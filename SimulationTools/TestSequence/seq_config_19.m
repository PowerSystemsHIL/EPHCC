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
Init('DMS.Dp', 0, 3);
Init('DMS.Dq', 0, 6);
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

%% Solar
CloudDelay = -20;

Irradiance.Rise = 20*60;            % FIX, Sunrise beginning time t=20min
Irradiance.RiseDuration = 40*60;    % FIX, Duration of ramp until full irradiance

Nc=Nc+1; Cloud(Nc) = struct('Start', 31*60, 'Depth', 0.6, 'Ramp', 15, 'Duration', 30);
Nc=Nc+1; Cloud(Nc) = struct('Start', 34*60, 'Depth', 0.7, 'Ramp', 15, 'Duration', 30);
Nc=Nc+1; Cloud(Nc) = struct('Start', 37*60, 'Depth', 0.9, 'Ramp', 10, 'Duration', 60);
Nc=Nc+1; Cloud(Nc) = struct('Start', 49*60, 'Depth', 0.9, 'Ramp', 20, 'Duration', 120);
Nc=Nc+1; Cloud(Nc) = struct('Start', 71*60, 'Depth', 0.9, 'Ramp', 25, 'Duration', 240);
Nc=Nc+1; Cloud(Nc) = struct('Start', 78*60, 'Depth', 0.5, 'Ramp', 5 , 'Duration', 30);
Nc=Nc+1; Cloud(Nc) = struct('Start', 91.5*60, 'Depth', 0.9, 'Ramp', 10, 'Duration', 30);

%% Motors
Next('Motor1'   , 3 , 1);
Next('Motor1'   , 12, 0);
Next('Motor1'   , 20, 1);
Next('Motor1'   , 37, 0);
Next('Motor1'   , 50, 1);
Next('Motor1'   , 58, 0);
Next('Motor1'   , 69, 1);
Next('Motor1'   , 85, 0);


Next('Motor2'   , 20, 1);
Next('Motor2'   , 28, 0);
Next('Motor2'   , 46, 1);
Next('Motor2'   , 56, 0);
Next('Motor2'   , 59, 1);
Next('Motor2'   , 71, 0);
Next('Motor2'   , 76, 1);

%% DER contingencies
Next('Fault.Gen2', 9, 1);
Next('Fault.Gen2', 10.5, 0);
Next('Fault.Ess1', 14, 1);
Next('Fault.Ess1', 15.5, 0);
Next('Fault.Ess1', 41, 1);
Next('Fault.Ess1', 42.5, 0);
Next('Fault.Pv1', 45, 1);
Next('Fault.Pv1', 47, 0);
Next('Fault.Gen2', 74, 1);
Next('Fault.Gen2', 75.5, 0);
Next('Fault.Pv1', 90, 1);
Next('Fault.Pv1', 92, 0);
Next('Fault.Gen1', 95, 1);
Next('Fault.Gen1', 96.5, 0);

%% Sequence start - grid connected
Next('MGC_Enable', 2/60, 1);            % start of test sequence

Next('DMS.PFena', 1, 1);
Next('DMS.PFref', 1, 1);       
Next('DMS.kWena', 4, 1);
Next('DMS.kWref', 4, 11000);         % DMS xport request
Next('DMS.kWref', 6, 9000);         % DMS xport request
Next('DMS.kWref', 8, 7000);         % DMS xport request
% Next('DMS.Dq'   , 3, 6);         % Droops will be set to it's values
% since init - evauation of responses will only be done during voltage/freq event 
% Next('DMS.Dp'   , 5, 3);
Next('DMS.kWena', 15, 0);
Next('DMS.kWref', 15, 0);           % DMS xport request
Next('DMS.PFref', 15, 0.99);         % unity power factor request
%Next('DMS.Dp'   , 10, 0);
%Next('DMS.Dq'   , 10, 0);
Next('DMS.PFena', 22, 0);           % unity power factor request
Nv=Nv+1; Grid.Volt(Nv) = struct('Start', 19*60, 'Depth', 115000*0.02, 'Duration', 120);
Nf=Nf+1; Grid.Freq(Nf) = struct('Start', 9*60, 'Depth', 0.3, 'Duration', 20);
Nf=Nf+1; Grid.Freq(Nf) = struct('Start', 12*60, 'Depth', -0.4, 'Duration', 40);




%% PLanned islanding - start island
Next('DMS.DisReq'      , 23, 1);
Next('Grid.OpenSSF1'   , 24, 1); 
Next('Grid.OpenSSF2'   , 24.2, 1); 
Next('Grid.OpenSSF3'   , 24.4, 1); 
Next('Grid.CutGrid'   , 24.6, 1); 

Next('Grid.CutGrid'    , 54,   0); 
Next('Grid.OpenSSF1'   , 54.2, 0); 
Next('Grid.OpenSSF2'   , 54.4, 0); 
Next('Grid.OpenSSF3'   , 54.6, 0); 
Next('DMS.DisReq'      , 55,   0);

%% End of planned islanding - start grid connected


%% Unintentional islanding - start island
%Next('Fault.Loc1'      , 66, 1);
%Next('Fault.Loc1'      , 67, 0);
Next('DMS.DisReq'      , 66+(10/60),   1);
Next('Grid.OpenSSF1'   , 67, 1); 
Next('Grid.OpenSSF2'   , 67.2, 1); 
Next('Grid.OpenSSF3'   , 67.4, 1); 
Next('Grid.CutGrid'    , 67.6, 1);


Next('Grid.CutGrid'    , 79, 0);
Next('Grid.OpenSSF1'   , 79.2, 0); 
Next('Grid.OpenSSF2'   , 79.4, 0); 
Next('Grid.OpenSSF3'   , 79.6, 0); 
Next('DMS.DisReq'      , 79.7, 0);
%% End of unintentional islanding - start grid connected

Next('DMS.PFena', 81, 1);
Next('DMS.PFref', 81, 0.98);         
Next('DMS.kWena', 90, 1);
Next('DMS.kWref', 90, 11000);         % DMS import request
Next('DMS.kWena', 98, 0);
Next('DMS.kWref', 98, 0);             % DMS import request

Nf=Nf+1; Grid.Freq(Nf) = struct('Start', 91*60, 'Depth', 0.4, 'Duration', 60);
Nf=Nf+1; Grid.Freq(Nf) = struct('Start', 96*60, 'Depth', -0.6, 'Duration', 20);
Nv=Nv+1; Grid.Volt(Nv) = struct('Start', 84*60, 'Depth', -115000*0.03, 'Duration', 150);

%% End of sequence
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
