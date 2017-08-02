%% This function configures test sequence by configuring time instances and 
% parameters of events
function [out] = init_seq()

%% Generic config
Ts = 1;
End = 100*60;
N = End/Ts+1;


%% Initial conditions
% motors command: 0- stop, 1-run
Motor{1}.Time   = 0; Motor{1}.Val    = 0;
Motor{2}.Time   = 0; Motor{2}.Val    = 0;
% DER failure command: 0- ok, 1-failed
GenFail{1}.Time = 0; GenFail{1}.Val  = 0;
GenFail{2}.Time = 0; GenFail{2}.Val  = 0;
GenFail{3}.Time = 0; GenFail{3}.Val  = 0;
EssFail{1}.Time = 0; EssFail{1}.Val  = 0;
EssFail{2}.Time = 0; EssFail{2}.Val  = 0;
PvFail{1}.Time  = 0; PvFail{1}.Val   = 0;
PvFail{2}.Time  = 0; PvFail{2}.Val   = 0;
% Fault injection
% bitfield, bit no: 0 - fault loc #1, 1- fault loc #2, etc...
Fault.BitFaultLoc1 = 1;
Fault.BitFaultLoc1 = 2;
Fault.BitFaultLoc1 = 3;
Fault.BitFaultLoc1 = 4;
Fault.BitFaultLoc1 = 5;
Fault.Time = 0; Fault.Val = 0;
% DMS
DMS.DisReq.Time = 0; DMS.DisReq.Val = 0;
%
%
%
% Grid cut
%   bitfield, bit no: 0 - cut grid, 1-SS feeder #1 open ... 3-SS feeder
Grid.Breakers.BitCutGrid = 1;
Grid.Breakers.BitOpenSSF1 = 2;
Grid.Breakers.BitOpenSSF2 = 4;
Grid.Breakers.BitOpenSSF3 = 8;
Grid.Breakers.Time = 0;  Grid.Breakers.Val = 0;
%Grid.Freq(n) - events
%Grid.Voltage(n) - events
% Irradiance - Nc= cloud number
Nc = 0; 

%% Sequence start
MGC_Enable.Time = [0 1 End-1];
MGC_Enable.Val  = [0 1 0];

Irradiance.Rise = 20*60;            % FIX, Sunrise beginning time t=20min
Irradiance.RiseDuration = 40*60;    % FIX, Duration of ramp until full irradiance

Nc=Nc+1; Cloud(Nc) = struct('Start', 30*60, 'Depth', 0.8, 'Ramp', 10, 'Duration', 30);

Next('DMS.DisReq'      , 32*60, 1);
Next('Grid.Breakers'   , 33*60, 1); 

Nc=Nc+1; Cloud(Nc) = struct('Start', 50*60, 'Depth', 0.6, 'Ramp', 15, 'Duration', 30);
Next('Grid.Breakers'   , 54*60, 0); 
Next('DMS.DisReq'      , 55*60, 0);
Nc=Nc+1; Cloud(Nc) = struct('Start', 60*60, 'Depth', 0.9, 'Ramp', 10, 'Duration', 300);
Nc=Nc+1; Cloud(Nc) = struct('Start', 81*60, 'Depth', 0.5, 'Ramp', 5 , 'Duration', 30);
Nc=Nc+1; Cloud(Nc) = struct('Start', 94*60, 'Depth', 0.3, 'Ramp', 15, 'Duration', 30);


out=wsp2struct(who);
end

function Next(fieldname, time, value)
    evalin('caller', [fieldname '.Time = [' fieldname '.Time ' num2str(time)  '];']);
    evalin('caller', [fieldname '.Val  = [' fieldname '.Val  ' num2str(value) '];']);
end
