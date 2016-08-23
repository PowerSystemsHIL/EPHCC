% Copyright (c) 2016 Massachusetts Institute of Technology
% Permission is hereby granted, free of charge, to any person obtaining a copy of this 
% software and associated documentation files (the "Software"), to deal in the Software
% without restriction, including without limitation the rights to use, copy, modify, 
% merge, publish, distribute, sublicense, and/or sell copies of the Software, and to 
% permit persons to whom the Software is furnished to do so, subject to the following 
% conditions:
% 
% 
% The above copyright notice and this permission notice shall be included in 
% all copies or substantial portions of the Software.
% 
% THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
% INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
% PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
% HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION 
% OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
% SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
%
%
%%

function rs_create_opal_folder()

% the system name must match the folder in distribution system
system_name = 'Banshee_20160810';


% path to the system to be simulated in Opal-RT
system_path = 'E:\HIL_sandbox_internal_branch\DistributionSystems\SimulinkOpal\Banshee';


% DO NOT CHANGE
% path to the components folders
components_path = 'E:\HIL_sandbox_internal_branch\Components\SimulinkOpal\';
% destination of system-copy
new_folder_path = 'E:\HIL_sandbox_internal_branch\CaseStudies\SimulinkOpal\';
new_destination = [new_folder_path, system_name];
% create (attempt-to) new folder to copy system
try
    status_mkdir = mkdir(new_destination)
end
status_cpsystem = copyfile(system_path, new_destination)
% getting a list of the components folders
list_components = dir(components_path);
[row,~] = size(list_components);
% file to hold name of folders that need to be added to the paths in the
% BANSHEE_init.m file
fid = fopen([new_destination, '\components_path_init.m'],'w');
for k = 1:row
    % copy folder if there is not dots in the name
    if isempty(strfind(list_components(k).name,'.'))
        fprintf(fid, 'addpath(''%s'');\n', list_components(k).name);
    end
end
fclose(fid);
status_cpcomponet = copyfile(components_path, new_destination)
end

