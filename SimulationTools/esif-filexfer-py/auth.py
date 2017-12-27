import argparse
import json

# get username/password from command line
#    or from auth.json file
#    or from user input
parser = argparse.ArgumentParser()
parser.add_argument('-u', '--username', required=False)
parser.add_argument('-p', '--password', required=False)
args = parser.parse_args();

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

credentials = (username, password);
