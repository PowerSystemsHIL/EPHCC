# command line args
import argparse
parser = argparse.ArgumentParser()
parser.add_argument('-u', '--username', required=False, help='Username for ESIF API.')
parser.add_argument('-p', '--password', required=False, help='Password for ESIF API.')
parser.add_argument('-r', '--recurse', dest='recurse', required=False, help='Recursive dir search will include files within all subdirectories of the specified path. Enabled when using --subdirs param.', action='store_true')
parser.add_argument('-a', '--all', dest='all_files', required=False, help='Upload all files found, else it only uploads non-existing files (based on filename). Enabled when using --create param. This has the potential to re-upload files that already exist in the repository, causing duplicates.', action='store_true')
parser.add_argument('-t', '--test', dest='test', required=False, help='Show files that would be uploaded, but do not perform upload.', action='store_true')
parser.add_argument('--path', required=False, help='Path to scan, else current dir.')
parser.add_argument('--ext', required=False, help='Comma-delimited list of file extensions to include, else all.')
group = parser.add_mutually_exclusive_group()
group.add_argument('--dataset', required=False, help='Dataset ID to upload into. Not valid with --subdirs or --create params.')
group.add_argument('-s','--subdirs', dest='subdirs', required=False, help='Put files into a dataset named for the subdirectory that contains it into the provided project ID, creating it if it doesn''t already exist. Enables --recurse, and requires project ID via --project param. Not valid with --dataset or --create params.', action='store_true')
group.add_argument('-c', '--create', dest='ds_create', required=False, help='Create new dataset in the provided project ID, to contain all files regardless if --recurse param is specified or not. It creates a single dataset and tags files with subdir names. Requires project ID via --project. Not valid with --dataset or --subdirs params.')
parser.add_argument('--project', required=False, help='Project ID to upload into, when creating dataset. Only valid with --create or --subdirs param.')
parser.add_argument('--tags', required=False, help='Comma-delimited list of tags to assign to uploaded files.')
parser.add_argument('--dataset-tags', dest='ds_tags', required=False, help='Comma-delimited list of tags to assign to created datasets. Only valid with --create or --subdirs params.')
parser.add_argument('--excludes', dest='excludes', required=False, help='Comma-delimited list of subdirectories to exclude from the recursive file scan. Only valid with ---recurse param.')
parser.add_argument('--includes', dest='includes', required=False, help='Comma-delimited list of subdirectories to include in the recursive file scan. Only valid with ---recurse param.')

args = parser.parse_args()

import requests
import json
import dirfiles
import bulktransfer

# default project/dataset manually assigned - lookup your own
project = args.project if args.project else None
dataset = args.dataset if args.dataset else None
files_path = args.path if args.path else '.'
files_ext = args.ext
test_only = args.test
ds_subdirs = args.subdirs
ds_create = args.ds_create
recurse = True if ds_subdirs else args.recurse
new_only = False if ds_create else not args.all_files  # flip all_files param into new_only
files_tags = args.tags.split(',') if args.tags else []
ds_tags = args.ds_tags.split(',') if args.ds_tags else []
excludes = args.excludes.split(',') if args.excludes else []
includes = args.includes.split(',') if args.includes else []

# check args
if (ds_create or ds_subdirs) and project is None:
    print 'You must provide a project ID to create datasets within'
    exit()
if not (ds_create or ds_subdirs) and dataset is None:
    print 'You must provide a dataset ID'
    exit()

base_url = 'https://api.hpc.nrel.gov/esif/api'

# get auth
username = args.username
password = args.password

try:
    with open('auth.json', 'r') as f:
        auth_file = json.load(f)
        username = auth_file['username']
        password = auth_file['password']
except:
    pass

if not username:
    username = raw_input('username: ')

if not password:
    import getpass
    password = getpass.getpass(prompt='password: ')

credentials = (username, password)

def getRelSubdir(file):
    subdir = dirfiles.extractFileRelativeDir(file, files_path)
    if subdir == '.':  # if root of path, use path name up a level
        subdir = dirfiles.extractParentDir(files_path)
    return subdir

def extractDatasetsFromFile(file):
    return [ds[u'name'] for ds in file['datasets']]

def scan():
    if recurse:
        filelist = dirfiles.getFilesInDirRecursive(files_path, files_ext, excludes, includes)
    else:
        filelist = dirfiles.getFilesInDir(files_path, files_ext)

    if ds_create or not new_only:
        return filelist

    print "Comparing files scanned to eliminate existing..."
    upload_list = []

    # if into single dataset, compare just that
    if not ds_subdirs:
        existing_files = set([f[u'filename'] for f in listFilesInDataset(dataset)])
        # upload if filename not present already
        upload_list = [f for f in filelist if dirfiles.extractFilename(f) not in existing_files]
    else:
        # iterate through files for subdirs datasets to be generated, and check for dupes against each
        datasets = set([getRelSubdir(f) for f in filelist])
        existing_files = listFilesInProject(project)
        existing_files_per = {}
        # per dataset about to be used, extract the project files w/in that dataset
        for ds in datasets:
            existing_files_per[ds] = [f[u'filename'] for f in existing_files if ds in extractDatasetsFromFile(f)]
        # only upload files not in dataset-to-be-used's files
        upload_list = [f for f in filelist if dirfiles.extractFilename(f) not in existing_files_per[getRelSubdir(f)]]

    removed = len(filelist)-len(upload_list)
    if (removed > 0):
        print "Removed " + str(removed) + ' existing files'
    return upload_list

def listFilesInDataset(ds=dataset):
    query = {
        'dataset': [ds],
        'limit': 0,
        'sort': 'filename',
        'active': True
    }
    endpoint = '/repo/files'
    url = '{}{}'.format(base_url, endpoint)

    response = requests.get(url, auth=credentials, params=query)
    return json.loads(response.text)

def listFilesInProject(prj=project):
    query = {
        'project': [prj],
        'limit': 0,
        'sort': 'filename',
        'active': True
    }
    endpoint = '/repo/files'
    url = '{}{}'.format(base_url, endpoint)

    response = requests.get(url, auth=credentials, params=query)
    return json.loads(response.text)

def listDatasetsInProject(prj=project):
    query = {
        'project': [prj],
        'limit': 0,
        'sort': 'created_on desc',
        'active': True
    }
    endpoint = '/repo/datasets'
    url = '{}{}'.format(base_url, endpoint)

    response = requests.get(url, auth=credentials, params=query)
    return json.loads(response.text)

def createDataset(ds_name, tags=[], prj=project):
    endpoint = '/repo/datasets'
    url = '{}{}'.format(base_url, endpoint)

    headers = {
        'content-type': 'application/json'
    }
    body = {
        'name': ds_name,
        'tags': tags + ds_tags,
        'projects': [prj]
    }

    response = requests.post(url, auth=credentials, headers=headers, data=json.dumps(body))
    ds = json.loads(response.text)
    ds['name'] = ds_name  # inject name into response for reuse
    return ds

def uploadFile(dataset, file, tags=[]):
    opts = {
        'datasets': [dataset],
        'tags': files_tags + tags,
        'orig_path': dirfiles.extractFileRelativeDir(file, files_path)
    }
    res = bulktransfer.uploadFile(file, opts, credentials)
    info = res[u'files'][0]
    print "   File " + dirfiles.extractFilename(info['name']) + ' uploaded (' + str(info['size']) + ' bytes)'
    return res


def testAuth():
    endpoint = '/auth/login'
    url = '{}{}'.format(base_url, endpoint)
    headers = {
        'content-type': 'application/json'
    }
    response = requests.post(url, auth=credentials, headers=headers)
    obj = json.loads(response.text)
    if 'error' in obj:
        print obj['error']['message']
        exit()

testAuth()  # test credentials before continuing with scan/upload
filelist = scan()

if not len(filelist):
    print "No files to upload"
    exit()
    
print "Uploading " + str(len(filelist)) + ' files...'

# if only test, print files and exit
if test_only:
    for file in filelist:
        final_tags = files_tags + dirfiles.extractFileNestedDirs(file, files_path)
        print file + ' ' + (str(final_tags) if len(final_tags) else "")
    exit()

# create new dataset, if specified
if ds_create and len(filelist):
    res = createDataset(ds_create)
    dataset = res['id']
    print "New dataset created: " + dataset

# upload all files to dataset
if dataset and not ds_subdirs:
   for file in filelist:
       # put relative subdirs in as tags
       tags = dirfiles.extractFileNestedDirs(file, files_path)
       res = uploadFile(dataset, file, tags)

elif ds_subdirs:
    datasets = listDatasetsInProject()
    for file in filelist:
        subdir = getRelSubdir(file)
        tags = dirfiles.extractFileNestedDirs(file, files_path)

        # lookup dataset in our cache, if not present, create a new one
        file_ds = next((ds for ds in datasets if ds["name"] == subdir), None)
        if file_ds is None:
            file_ds = createDataset(subdir)
            datasets.append(file_ds)

        res = uploadFile(file_ds['id'], file, tags)


