%% This function configures test sequence by configuring time instances and 
% parameters of events
function [out] = init_seq()

%% Generic config
Ts = 0.2;
End = 100*60;
N = End/Ts+1;


%% Initial conditions
% motors command: 0- stop, 1-run
Init('Motor1', 0, 0);
Init('Motor2', 0, 0);
% DER failure command: 0- ok, 1-failed
Init('Fault.Gen1', 0, 0);
Init('Fault.Gen2', 0, 0);
Init('Fault.Gen3', 0, 0);
Init('Fault.Ess1', 0, 0);
Init('Fault.Ess2', 0, 0);
Init('Fault.Pv1', 0, 0);
Init('Fault.Pv2', 0, 0);

% Fault injection
% bitfield, bit no: 0 - fault loc #1, 1- fault loc #2, etc...
Init('Fault.Loc1', 0, 0);
Init('Fault.Loc2', 0, 0);
Init('Fault.Loc3', 0, 0);
Init('Fault.Loc4', 0, 0);
Init('Fault.Loc5', 0, 0);
Init('Fault.Loc6', 0, 0);
% DMS
Init('DMS.DisReq', 0, 0);
Init('DMS.kWena', 0, 0);
Init('DMS.PFena', 0, 0);
Init('DMS.kWref', 0, 0);
Init('DMS.PFref', 0, 1.0);
Init('DMS.Dp', 0, 0);
Init('DMS.Dq', 0, 0);
%
% Grid cut
Init('Grid.CutGrid', 0, 0);
Init('Grid.OpenSSF1', 0, 0);
Init('Grid.OpenSSF2', 0, 0);
Init('Grid.OpenSSF3', 0, 0);
%Grid.Freq(n) - events
%Grid.Voltage(n) - events
Init('MGC_Enable', 0, 0);            % start of test sequence

Nc = 0; % Irradiance - Nc= cloud number
Nf = 0; % Frequency events counter
Nv = 0; % Voltage event counter
CloudDelay = 20;

%% Sequence start - grid connected
Next('MGC_Enable', 2/60, 1);            % start of test sequence

Next('DMS.kWena', 2, 1);
Next('DMS.kWref', 2, 5000);         % DMS xport request
Next('DMS.PFena', 2, 1);
Next('DMS.PFref', 2, 1.0);         % unity power factor request
Next('DMS.Dq'   , 3, 6);
Nv=Nv+1; Grid.Volt(Nv) = struct('Start', 3*60, 'Depth', -115000*0.03, 'Duration', 120);
Next('DMS.Dp'   , 5, 3);
Nf=Nf+1; Grid.Freq(Nf) = struct('Start', 7*60, 'Depth', -0.6, 'Duration', 60);
Nf=Nf+1; Grid.Freq(Nf) = struct('Start', 9*60, 'Depth', 0.4, 'Duration', 20);
Next('DMS.kWena', 10, 0);
Next('DMS.kWref', 10, 0);           % DMS xport request
Next('DMS.Dp'   , 10, 0);
Next('DMS.Dq'   , 10, 0);
Next('Motor1'   , 12, 1);
Next('Motor2'   , 15, 1);
Next('DMS.PFref', 23, 0.9);         % unity power factor request
Next('DMS.PFena', 25, 0);           % unity power factor request

Irradiance.Rise = 20*60;            % FIX, Sunrise beginning time t=20min
Irradiance.RiseDuration = 40*60;    % FIX, Duration of ramp until full irradiance

Next('Motor2'   , 24, 0);
Next('Fault.Ess1', 4, 1);
Next('Fault.Ess1', 6, 0);

Nc=Nc+1; Cloud(Nc) = struct('Start', 30*60, 'Depth', 0.8, 'Ramp', 10, 'Duration', 30);

%% PLanned islanding - start island
Next('DMS.DisReq'      , 32, 1);
Next('Grid.OpenSSF1'   , 33, 1); 
Next('Grid.OpenSSF2'   , 33.2, 1); 
Next('Grid.OpenSSF3'   , 33.4, 1); 
Next('Grid.CutGrid'   , 33.6, 1); 


Next('Fault.Gen3', 36, 1);
Next('Fault.Gen3', 38, 0);
Next('Fault.Pv1', 42, 1);
Next('Fault.Pv1', 44, 0);
Next('Fault.Loc2', 46, 1);
Next('Fault.Loc2', 46.5, 0);

Next('Motor1'   , 45, 1);
Next('Motor2'   , 47, 1);
Next('Motor1'   , 49, 0);

Nc=Nc+1; Cloud(Nc) = struct('Start', 50*60, 'Depth', 0.6, 'Ramp', 15, 'Duration', 30);
Next('Grid.CutGrid'    , 54,   0); 
Next('Grid.OpenSSF1'   , 54.2, 0); 
Next('Grid.OpenSSF2'   , 54.4, 0); 
Next('Grid.OpenSSF3'   , 54.6, 0); 
Next('DMS.DisReq'      , 55,   0);

%% End of planned islanding - start grid connected
Next('Motor1'   , 55, 1);
Next('DMS.kWena', 58, 1);
Next('DMS.kWref', 58, -500);         % DMS import request
Next('DMS.PFena', 58, 1);
Next('DMS.PFref', 58, 0.98);         
Next('DMS.kWref', 59, -1000);         % DMS import request
Next('DMS.kWref', 60, -1500);         % DMS import request
Next('Motor2'   , 61, 1);
Next('DMS.Dp'   , 61, 2);
Nf=Nf+1; Grid.Freq(Nf) = struct('Start', 62*60, 'Depth', 0.3, 'Duration', 20);
Nf=Nf+1; Grid.Freq(Nf) = struct('Start', 63*60, 'Depth', -0.4, 'Duration', 40);

Next('DMS.kWena', 64, 0);
Next('DMS.kWref', 64, 0);           % DMS import request
Next('DMS.Dp'   , 64, 0);
Next('DMS.PFena', 68, 0);

Next('Fault.Gen2', 59, 1);
Next('Fault.Gen2', 60, 0);
Next('Fault.Ess2', 62, 1);
Next('Fault.Ess2', 63, 0);
Next('Fault.Loc3', 67, 1);
Next('Fault.Loc3', 67.5, 0);

Nc=Nc+1; Cloud(Nc) = struct('Start', 60*60, 'Depth', 0.9, 'Ramp', 10, 'Duration', 300);
Nc=Nc+1; Cloud(Nc) = struct('Start', 81*60, 'Depth', 0.5, 'Ramp', 5 , 'Duration', 30);
Nc=Nc+1; Cloud(Nc) = struct('Start', 94*60, 'Depth', 0.3, 'Ramp', 15, 'Duration', 30);


%% Unintentional islanding - start island
Next('Fault.Loc1'      , 70, 1);
Next('Grid.OpenSSF1'   , 71, 1); 
Next('Grid.OpenSSF2'   , 71.2, 1); 
Next('Grid.OpenSSF3'   , 71.4, 1); 
Next('Grid.CutGrid'    , 71.6, 1);

Next('Fault.Gen1', 73, 1);
Next('Fault.Gen1', 75, 0);
Next('Motor1'   , 76, 0);
Next('Fault.Pv2', 80, 1);
Next('Fault.Pv2', 81, 0);
Next('Fault.Loc4', 86, 1);
Next('Fault.Loc4', 86.5, 0);

%% End of unintentional islanding - start grid connected
Next('Fault.Loc1'      , 72, 0);
Next('Grid.CutGrid'    , 92, 0);
Next('Grid.OpenSSF1'   , 92.2, 0); 
Next('Grid.OpenSSF2'   , 92.4, 0); 
Next('Grid.OpenSSF3'   , 92.6, 0); 

Next('Motor2'   , 95, 0);

Next('DMS.kWena', 95, 1);
Next('DMS.kWref', 95, 9000);         % DMS import request
Next('DMS.PFena', 93, 1);
Next('DMS.PFref', 93, 0.96);         
Next('DMS.Dq'   , 3, 6);
Nv=Nv+1; Grid.Volt(Nv) = struct('Start', 95*60, 'Depth', 115000*0.03, 'Duration', 150);

Next('Fault.Loc5', 98, 1);
Next('Fault.Loc5', 98.5, 0);

Next('MGC_Enable', 99+58/60, 0);
out=wsp2struct(who);
end

function Next(fieldname, timeMin, value)
    evalin('caller', [fieldname '.Time = [' fieldname '.Time ' num2str(timeMin*60)  '];']);
    evalin('caller', [fieldname '.Val  = [' fieldname '.Val  ' num2str(value) '];']);
end

function Init(fieldname, timeMin, value)
    evalin('caller', [fieldname '.Time = ' num2str(timeMin) ';']);
    evalin('caller', [fieldname '.Val  = ' num2str(value) ';']);
end
