clc;

path = pwd; % 'C:\OPAL-RT\HIL_WORKSPACE\07222015_DEMO\models\MODEL_07172015';

ls = dir(path);
rows=length(ls);
for r = 1:rows  
    if ~isempty(strfind(ls(r).name, '.mat'))
        load(ls(r).name);
    end
end

% clear all; clc;
% a = load('irradiance.mat')
% irr_d = a.irr.Data;
% ln = 0:length(irr_d)-1;
% data = [ln; irr_d'];
% del a, ln, irr_d;
% save('irradiance_data.mat', '-v4')

