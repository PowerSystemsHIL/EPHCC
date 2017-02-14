% Initialization Script for Desktop Sim
addpath(genpath('../../../Components/SimulinkSpeedgoat'))
addpath('../../../CaseStudies/SimulinkSpeedgoat')

f = 60; % nominal grid frequency

% Sample Rates
Ts = 80e-6*2;
%Ts=1e-3;
PLL_time_step = Ts; Td_es_min = Ts; Tds = Ts;
Tau = 1e-4; % Breaking Algebraic loops

% Load Data Files
dataDir = '../../../CaseStudies/SimulinkSpeedgoat/LoadProfiles';
loadDirs = dir(dataDir);
rows = length(loadDirs);
for r = 1:rows  
    if ~isempty(strfind(loadDirs(r).name, '.mat'))
        
        fileName = loadDirs(r).name;
        load([dataDir '/' fileName]);
        
        dataName = strsplit(fileName,'.');
        dataName = dataName{1};
        
        %Pivot Data
        eval([dataName '=' dataName ''';']);
        
        % Convert first column to seconds (from minutes)
        eval([dataName '(:,1) = (' dataName '(:,1)-1)*1;']);
    end
end

% Clean up workspace
clearvars loadDirs rows r visible
