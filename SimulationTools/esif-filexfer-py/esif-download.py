# command line args
import argparse
parser = argparse.ArgumentParser()
parser.add_argument('-u', '--username', required=False, help='Username for ESIF API.')
parser.add_argument('-p', '--password', required=False, help='Password for ESIF API.')
parser.add_argument('-t', '--test', dest='test', required=False, help='Show files that would be downloaded, but do not perform download.', action='store_true')
parser.add_argument('-r', '--recreate', dest='recreate', required=False, help='Put downloaded files into the original subdirectory structure they were in when uploaded via upload tool.', action='store_true')
parser.add_argument('--dest', required=False, help='Path to download into, else current dir')
group = parser.add_mutually_exclusive_group()
group.add_argument('--dataset', required=False, help='Dataset ID to download from.')
group.add_argument('--project', required=False, help='Project ID to download from.')
parser.add_argument('--tags', required=False, help='Comma-delimited list of tags to filter file list by. All tags must be present for file to be included.')
parser.add_argument('--filter', required=False, help='Keyword to filter file list by.')

args = parser.parse_args()

import requests
import json
import bulktransfer
import os

# default project/dataset manually assigned - lookup your own
project = args.project if args.project else None
dataset = args.dataset if args.dataset else None
files_path = args.dest if args.dest else '.'
recreate = args.recreate

# check args
if project is None and dataset is None:
    print 'You must provide either a project or dataset ID to download files from.'
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

def extractFilename(response):
    import re
    import urllib2
    filename = re.findall("filename=['\"](.+)['\"]", response.headers['content-disposition'])[0]
    filename = filename.split('";')[0] # in case of extra filename* in header
    filename = urllib2.unquote(filename)
    return filename

def listFilesInDataset(ds, tags, filter):
    query = {
        'dataset': [ds],
        'limit': 0,
        'sort': 'created_on desc',
        'active': True
    }
    if tags is not None:
        query['tag'] = tags.split(',')
    if filter is not None:
        query['keyword'] = filter
        
    endpoint = '/repo/files'
    url = '{}{}'.format(base_url, endpoint)

    response = requests.get(url, auth=credentials, params=query)
    return json.loads(response.text)

def listFilesInProject(prj, tags, filter):
    query = {
        'project': [prj],
        'limit': 0,
        'sort': 'created_on desc',
        'active': True
    }
    if tags is not None:
        query['tag'] = tags.split(',')
    if filter is not None:
        query['keyword'] = filter

    endpoint = '/repo/files'
    url = '{}{}'.format(base_url, endpoint)

    response = requests.get(url, auth=credentials, params=query)
    return json.loads(response.text)

def downloadFile(file, dest):
    opts = {
        'file': [file]
    }
    res = bulktransfer.downloadFile(file, opts, credentials)
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

testAuth()  # test credentials before continuing with download
filelist = listFilesInDataset(dataset, args.tags, args.filter) if project is None else listFilesInProject(project, args.tags, args.filter)

print "Downloading " + str(len(filelist)) + ' files:'

for file in filelist:
    file_id = file['id']
    filename = file['filename']

    if args.test:
        if recreate:
            orig_path = file['metadata']['orig_path']
            final_path = os.path.join(orig_path, filename)
            print "  " + final_path
        else:
            print "  " + filename
    else:
        print "Receiving: " + filename + " ..."
        response = bulktransfer.downloadFiles(file_id, credentials)

        if (response.status_code == 200):
            final_filename = extractFilename(response)

            if recreate:
                orig_path = file['metadata']['orig_path']
                final_path = os.path.join(files_path, orig_path, final_filename)
                final_dir = os.path.dirname(final_path)
                # assure final path exists
                if not os.path.exists(final_dir):
                    import errno
                    try:
                        os.makedirs(final_dir)
                    except OSError:
                        if not os.path.isdir(final_dir):
                            raise

            else:
                final_path = os.path.join(files_path, final_filename)

            with open(final_path, 'wb') as f:
                f.write(response.content)
            print "... file written to " + final_path
        else:
            err = json.loads(response.content)['error']
            print "... ERROR " + err['message'] + " : " + err['description']
