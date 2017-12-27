import os
from glob import glob
#import re

if os.name == 'nt':
    import win32api, win32con

def isHiddenDir(dir, root):
    if os.name== 'nt':
        attribute = win32api.GetFileAttributes(dir)
        return attribute & (win32con.FILE_ATTRIBUTE_HIDDEN | win32con.FILE_ATTRIBUTE_SYSTEM)
    else:  # posix
        reldirs = extractNestedDirs(dir, root)
        # if any rel dir paths start with ., it's hidden
        for f in reldirs:
            if f.startswith('.') and not f == '.':
                return True  # a nested subdir in relative path is hidden
        return False

def isValidFile(file, exts):
    return os.path.isfile(file) and not os.path.basename(file).startswith('.') and (exts is None or os.path.basename(file).endswith(exts))

def isDirIncluded(subdir, dir, excludes, includes):
    if excludes is None:
        excludes = []
    if includes is None:
        includes = []
    if (len(includes) == 0 and len(excludes) == 0) or subdir == dir:
        return True  # quick quit if no params
    subdirs = set(extractNestedDirs(subdir, dir))
    exdirs = set(excludes)
    indirs = set(includes)

    # if included and not excluded
    result = (len(indirs)==0 or len(subdirs.intersection(indirs))>0)\
           and (len(exdirs)==0 or len(subdirs.intersection(exdirs))==0)

    return result

def fixDir(dir):
    # make compat with Mac ~ and change rel to abs path
    dir = os.path.expanduser(dir)
    return os.path.abspath(dir)

def fixExt(exts):
    if exts is None:
        return exts; # include all
    if type(exts) == str:
        exts = exts.split(',')
    return tuple(exts)

def getFilesInDir(dir, exts=None, recurse=None):
    if recurse:
        return getFilesInDirRecursive(dir, exts)
    dir = fixDir(dir)
    exts = fixExt(exts)
    return [os.path.join(dir, f) for f in os.listdir(dir) if isValidFile(os.path.join(dir, f), exts)]

def getFilesInDirRecursive(dir, exts=None, excludes=['.git','.idea','node_modules'], includes=[]):
    dir = fixDir(dir)
    exts = fixExt(exts)

    if excludes is None:
        excludes = []
    if includes is None:
        includes = []

    return [f for x in os.walk(dir) if not isHiddenDir(x[0], dir) and isDirIncluded(x[0], dir, excludes, includes) for f in glob(os.path.join(x[0], '*')) if isValidFile(f, exts)]

def extractRelative(sub, dir):
    dir = fixDir(dir)
    return os.path.relpath(sub, dir)

def extractNestedDirs(sub, dir):
    reldir = extractRelative(sub, dir)
    if reldir != '.':
        return reldir.split(os.path.sep)
    else:
        return []

def extractFileDir(file):
    return os.path.dirname(file)

def extractFilename(file):
    return os.path.basename(file)

def extractParentDir(file):
    return os.path.basename(os.path.dirname(file))

def extractFileRelativeDir(file, dir):
    return extractRelative(os.path.dirname(file), dir)

def extractFileNestedDirs(file, dir):
    reldir = extractFileRelativeDir(file, dir)
    if reldir != '.':
        return reldir.split(os.path.sep)
    else:
        return []

if __name__ == "__main__":
    # test when not called via 'import'
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument('--path', required=False, help='Path to scan, else current dir')
    parser.add_argument('--ext', required=False, help='File extensions to include, else all')
    parser.add_argument('--excludes', required=False, help='List of subdirectories to exclude, if recurse used')
    parser.add_argument('--includes', required=False, help='List of subdirectories to include, if recurse used')
    parser.add_argument('-r', '--recurse', dest='recurse', required=False, help='Recursive dir search.', action='store_true')
    args = parser.parse_args()

    DIR=args.path
    EXT=args.ext
    excludes = args.excludes.split(',') if args.excludes is not None else []
    includes = args.includes.split(',') if args.includes is not None else []

    if not DIR:
        DIR='.'

    DIR = fixDir(DIR)

    if not args.recurse:
        # specified dir only example
        print 'Scanning ' + DIR + '...'
        filelist = getFilesInDir(DIR, EXT)
        for file in filelist:
            print file
    else:
        # recursive example
        filelist = getFilesInDirRecursive(DIR, EXT, excludes, includes)
        for file in filelist:
            tags = extractFileNestedDirs(file, DIR)
            relfile = extractRelative(file, DIR)
            #relpath = extractFileRelativeDir(file, DIR)
            if len(tags):
                print '  ' + relfile + '  ... subdirs: ' + str(tags)
            else:
                print '  ' + relfile
