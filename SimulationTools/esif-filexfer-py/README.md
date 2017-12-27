# ESIF API File Transfer Utilities - Python

These are utility scripts for transfering files to and from the File Repository in ESIF API. If you want a example Python scripts for interacting with ESIF API, see the [esif-api-examples](https://github.nrel.gov/viz/esif-api-examples/tree/master/python) project dir.

## Setup

These utilities run under Python 2.7. The only dependency is the requests package. Run `pip install -r requirements.txt` to install.

## Authentication

All Python examples use basic authentication. The `auth.py` helper provides a convenience wrapper to get username and password via command line options, auth.json config file, or user input. For example:

User input:
```shell
python esif-upload.py
username: meash
password:
```

Command line:
```shell
python esif-upload.py -u meash
password:
```

```shell
python esif-upload.py -u meash -p ********
```

If you don't wish to enter credentials each time, you can copy the file `auth_template.json` to `auth.json`, then edit it to add your username and password.

## Upload

Run `esif-upload.py` to upload a directory's files to ESIF API.

Add `--help` parameter to see all parameters.

First, provide the path and list of file extensions you would like to upload. 

* `--path` to provide the relative or absolute path, else current directory is used.
* `--ext` to provide a comma-delimited list of extensions to upload, else all files are (e.g. "jpg,pdf,csv").
* `--excludes` to provide comma-delimited list of subdirectory names to exclude, if using `--recurse` param.
* `--includes` to provide comma-delimited list of subdirectory names to include, if using `--recurse` param.

Then, you should use one of the following options:
    
* `--dataset` to provide Dataset ID to upload all files into.  If `--recurse` option used, it will tag nested files with all subdirectory names.
* `--create` to create a new dataset to upload all files into. Project ID must be provided via `--project` param. If `--recurse` option used, it will tag nested files with all subdirectory names. Provide a list of `--dataset-tags` to add tags to the newly created dataset.
* `--subdirs` to put files into a dataset for each subdirectory, based on the full path of the subdirectory, creating a new dataset if one does not already exist. Project ID must be provided via `--project` param. This turns on `--recurse` param.  Provide a list of `--dataset-tags` to add tags to the newly created datasets.
 
Additional params:

* `--recurse` to scan files in all subdirectories in the provided path, else only scans the root dir.
* `--all` to upload all files, else it will scan for files that are not yet in the repository (using filename for comparisons).
* `--test` to only do a test run, listing the files that would be uploaded. 
* `--project` to provide Project ID, if using `--create` or `--subdirs` params.
* `--tags` to provide comma-delimited list of additional tags for each file uploaded.
* `--dataset-tags` to provide comma-delimited list of tags for each dataset created (if using --create or --subdirs options).


## Download

Run `esif-download.py` to download all files from a given project or dataset into a directory.

Add `--help` parameter to see all parameters.

Provide the following options:

* `--dest` to provide the relative or absolute path to put files into, else current directory is used.

Then, you should use one of the following options:
    
* `--project` to provide Project ID to download all files within.
* `--dataset` to provide Dataset ID to download all files within.

Additional params:

* `--test` to only do a test run, listing the files that would be downloaded. 
* `--recreate` to provide put downloaded files into the subdirectory structure they were in when uploaded via upload tool. 
* `--tags` to provide comma-delimited list of tags to filter the file list by. All tags must be present to be included.
* `--filter` to provide keyword to filter the file list by. 
