%% Copyright 2018 Alliance for Sustainable Energy, LLC
%
% Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
% and associated documentation files (the "Software"), to deal in the Software without restriction, 
% including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
% and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, 
% subject to the following conditions:
%
% The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
%
% THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
% BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
% NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS, THE COPYRIGHT HOLDERS, THE UNITED STATES, 
% THE UNITED STATES DEPARTMENT OF ENERGY, OR ANY OF THEIR EMPLOYEES BE LIABLE FOR ANY CLAIM, 
% DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
% OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
%
% Author: Przemyslaw Koralewicz / NREL
% Date: 2017

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
CloudDelay = 20;

Irradiance.Rise = 20*60;            % FIX, Sunrise beginning time t=20min
Irradiance.RiseDuration = 40*60;    % FIX, Duration of ramp until full irradiance

Nc=Nc+1; Cloud(Nc) = struct('Start', 30*60, 'Depth', 0.9, 'Ramp', 10, 'Duration', 30);
Nc=Nc+1; Cloud(Nc) = struct('Start', 40*60, 'Depth', 0.6, 'Ramp', 15, 'Duration', 30);
Nc=Nc+1; Cloud(Nc) = struct('Start', 45*60, 'Depth', 0.9, 'Ramp', 10, 'Duration', 60);
Nc=Nc+1; Cloud(Nc) = struct('Start', 65*60, 'Depth', 0.9, 'Ramp', 10, 'Duration', 60);
Nc=Nc+1; Cloud(Nc) = struct('Start', 73*60, 'Depth', 0.5, 'Ramp', 5 , 'Duration', 30);
Nc=Nc+1; Cloud(Nc) = struct('Start', 80*60, 'Depth', 0.7, 'Ramp', 15, 'Duration', 30);
Nc=Nc+1; Cloud(Nc) = struct('Start', 95*60, 'Depth', 0.9, 'Ramp', 10, 'Duration', 60);

%% Motors
Next('Motor1'   , 9 , 1);
Next('Motor1'   , 15, 0);
Next('Motor1'   , 26, 1);
Next('Motor1'   , 37, 0);
Next('Motor1'   , 50, 1);
Next('Motor1'   , 55, 0);
Next('Motor1'   , 66, 1);
Next('Motor1'   , 72, 0);
Next('Motor1'   , 78, 1);
Next('Motor1'   , 92, 0);

Next('Motor2'   , 20, 1);
Next('Motor2'   , 25, 0);
Next('Motor2'   , 67, 1);
Next('Motor2'   , 73, 0);
Next('Motor2'   , 80, 1);
Next('Motor2'   , 91, 0);
Next('Motor2'   , 96, 1);

%% Sequence start - grid connected
Next('MGC_Enable', 2/60, 1);            % start of test sequence

Next('DMS.kWena', 2, 1);
Next('DMS.kWref', 2, 7000);         % DMS xport request
Next('DMS.PFena', 2, 1);
Next('DMS.PFref', 2, 1.0);         % unity power factor request
% Next('DMS.Dq'   , 3, 6);         % Droops will be set to it's values
% since init - evauation of responses will only be done during voltage/freq event 
Nv=Nv+1; Grid.Volt(Nv) = struct('Start', 3*60, 'Depth', 115000*0.02, 'Duration', 120);
Nf=Nf+1; Grid.Freq(Nf) = struct('Start', 7*60, 'Depth', 0.4, 'Duration', 60);
Nf=Nf+1; Grid.Freq(Nf) = struct('Start', 9*60, 'Depth', -0.6, 'Duration', 20);
% Next('DMS.Dp'   , 5, 3);
Next('DMS.kWena', 11, 0);
Next('DMS.kWref', 11, 0);           % DMS xport request
%Next('DMS.Dp'   , 10, 0);
%Next('DMS.Dq'   , 10, 0);
Next('DMS.PFena', 12, 0);           % unity power factor request




%% PLanned islanding - start island
Next('DMS.DisReq'      , 12, 1);
Next('Grid.OpenSSF1'   , 13, 1); 
Next('Grid.OpenSSF2'   , 13.2, 1); 
Next('Grid.OpenSSF3'   , 13.4, 1); 
Next('Grid.CutGrid'   , 13.6, 1); 


Next('Fault.Gen3', 16, 1);
Next('Fault.Gen3', 18, 0);
Next('Fault.Pv1', 22, 1);
Next('Fault.Pv1', 24, 0);
Next('Fault.Ess1', 28, 1);
Next('Fault.Ess1', 29.5, 0);


Next('Grid.CutGrid'    , 34,   0); 
Next('Grid.OpenSSF1'   , 34.2, 0); 
Next('Grid.OpenSSF2'   , 34.4, 0); 
Next('Grid.OpenSSF3'   , 34.6, 0); 
Next('DMS.DisReq'      , 35,   0);

%% End of planned islanding - start grid connected
Next('DMS.kWena', 38, 1);
Next('DMS.kWref', 38, 3000);         % DMS import request
Next('DMS.PFena', 38, 1);
Next('DMS.PFref', 38, 0.98);         
Next('DMS.kWref', 41, 2000);         % DMS import request
Next('DMS.kWref', 42, 1000);         % DMS import request
Next('DMS.Dp'   , 41, 2);

Next('DMS.kWena', 48, 0);
Next('DMS.kWref', 48, 0);           % DMS import request
%Next('DMS.Dp'   , 64, 0);
Next('DMS.PFena', 58, 0);

Next('Fault.Gen1', 49, 1);
Next('Fault.Gen1', 40, 0);
Next('Fault.Pv1', 42, 1);
Next('Fault.Pv1', 43, 0);




%% Unintentional islanding - start island
Next('Fault.Loc1'      , 60, 1);
Next('Fault.Loc1'      , 61, 0);
Next('DMS.DisReq'      , 60+(10/60),   1);
Next('Grid.OpenSSF1'   , 61, 1); 
Next('Grid.OpenSSF2'   , 61.2, 1); 
Next('Grid.OpenSSF3'   , 61.4, 1); 
Next('Grid.CutGrid'    , 61.6, 1);

Next('Fault.Pv2', 63, 1);
Next('Fault.Pv2', 64, 0);
Next('Fault.Gen1', 68, 1);
Next('Fault.Gen1', 70, 0);
Next('Fault.Ess2', 74, 1);
Next('Fault.Ess2', 75, 0);
Next('Fault.Gen2', 79, 1);
Next('Fault.Gen2', 80.5, 0);

%% End of unintentional islanding - start grid connected
Next('Grid.CutGrid'    , 82, 0);
Next('Grid.OpenSSF1'   , 82.2, 0); 
Next('Grid.OpenSSF2'   , 82.4, 0); 
Next('Grid.OpenSSF3'   , 82.6, 0); 
Next('DMS.DisReq'      , 82.7, 0);


Next('DMS.kWena', 90, 1);
Next('DMS.kWref', 90, 10000);         % DMS import request
Next('DMS.PFena', 88, 1);
Next('DMS.PFref', 88, 0.96);         
%Next('DMS.Dq'   , 3, 6);
Nv=Nv+1; Grid.Volt(Nv) = struct('Start', 95*60, 'Depth', -115000*0.03, 'Duration', 150);
Nf=Nf+1; Grid.Freq(Nf) = struct('Start', 92*60, 'Depth', 0.3, 'Duration', 20);
Nf=Nf+1; Grid.Freq(Nf) = struct('Start', 98*60, 'Depth', -0.4, 'Duration', 40);

Next('Fault.Pv2', 94, 1);
Next('Fault.Pv2', 95, 0);

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
