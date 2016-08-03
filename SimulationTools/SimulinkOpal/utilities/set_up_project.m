function set_up_project()
%set_up_project  Configure the environment for this project
%
%   Set up the environment for the current project. This function is set to
%   Run at Startup.

%   Copyright 2011-2012 The MathWorks, Inc.
v = ver('MATLAB');
if(~strcmp(v.Version,'8.1'))
    warning('This project must be run in Matlab 2013a.  Any changes committed will cause problems for others.');
end
a = computer('arch');
if(~strcmp(a,'win32'))
    warning('This project must be run in from 32-bit matlab for Opal support.');
end

% Use Simulink Project API to get the current project:
p = slproject.getCurrentProject;

projectRoot = p.RootFolder;
% Set the location of slprj to be the "work" folder of the current project:
myCacheFolder = fullfile(projectRoot, 'work');
if ~exist(myCacheFolder, 'dir')
    mkdir(myCacheFolder)
end
Simulink.fileGenControl('set', 'CacheFolder', myCacheFolder, ...
   'CodeGenFolder', myCacheFolder);

% Set the path for this project:
folders = project_paths();
for jj=1:numel(folders)
    addpath( fullfile(projectRoot, folders{jj}) );
end

