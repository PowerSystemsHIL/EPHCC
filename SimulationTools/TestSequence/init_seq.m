%% This function configures test sequence by configuring time instances and 
% parameters of events
function [out] = init_seq()

%% Generic config
Ts = 1;
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
Init('DMS.PFref', 0, 0);
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
% Irradiance - Nc= cloud number
Nc = 0;
CloudDelay = 20;

%% Sequence start
MGC_Enable.Time = [0 1 End-1];
MGC_Enable.Val  = [0 1 0];

Irradiance.Rise = 20*60;            % FIX, Sunrise beginning time t=20min
Irradiance.RiseDuration = 40*60;    % FIX, Duration of ramp until full irradiance

Nc=Nc+1; Cloud(Nc) = struct('Start', 30*60, 'Depth', 0.8, 'Ramp', 10, 'Duration', 30);

Next('DMS.DisReq'      , 32, 1);
Next('Grid.CutGrid'   , 33, 1); 

Nc=Nc+1; Cloud(Nc) = struct('Start', 50*60, 'Depth', 0.6, 'Ramp', 15, 'Duration', 30);
Next('Grid.CutGrid'   , 54, 0); 
Next('DMS.DisReq'      , 55, 0);
Nc=Nc+1; Cloud(Nc) = struct('Start', 60*60, 'Depth', 0.9, 'Ramp', 10, 'Duration', 300);
Nc=Nc+1; Cloud(Nc) = struct('Start', 81*60, 'Depth', 0.5, 'Ramp', 5 , 'Duration', 30);
Nc=Nc+1; Cloud(Nc) = struct('Start', 94*60, 'Depth', 0.3, 'Ramp', 15, 'Duration', 30);


% Unintentional islanding
Next('Fault.Loc1'      , 70, 1);
Next('Grid.CutGrid'    , 71, 1);
Next('Fault.Loc1'      , 72, 0);
Next('Grid.CutGrid'    , 92, 0);

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
