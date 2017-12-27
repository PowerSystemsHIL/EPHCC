import requests
import json
from os import path

# special direct url for file uploads or downloads
url = 'https://app-prod.hpc.nrel.gov:8099/api'
upload_url = '{}{}'.format(url, '/repo/files/upload')
download_url = '{}{}'.format(url, '/repo/files/download')

def runUpload(files, opts, credentials):
    upload_response = requests.post(upload_url, auth=credentials, params=opts, files=files)
    return json.loads(upload_response.text)

def runDownload(files, credentials):
    opts = {
        'files': files if isinstance(files, list) else [files]
    }
    response = requests.post(download_url, auth=credentials, params=opts)
    return response

def downloadFiles(files, credentials):
    response = runDownload(files, credentials)
    return response

def uploadFiles(filelist, opts, credentials):
    # build files dict (json) of all files provided
    files = {}
    for file in filelist:
        filename = path.basename(file)
        files[filename] = open(file, 'rb')

    # opts should contain datasets:[], tags:[], etc
    return runUpload(files, opts, credentials)

def uploadFile(file, opts, credentials):
    # build files dict (json)
    filename = path.basename(file)
    files = {}
    files[filename] = open(file, 'rb')

    # opts should contain datasets:[], tags:[], etc
    return runUpload(files, opts, credentials)

if __name__ == "__main__":
    # test when not called via 'import'
    from auth import credentials

    print 'Uploading files...'
    filelist = ['/Users/meash/Downloads/users1.csv','/Users/meash/Downloads/users2.csv']
    opts = {
        'datasets': ['0c9ed288-2a12-4b0a-929e-c0c0db1c33fe'],
        'tags': ['test']
    }
    res = uploadFiles(filelist, opts, credentials)

    for file in res['files']:
        print 'UPLOADED ' + file['name'] + ' (' + str(file['size']) + ' bytes)'
