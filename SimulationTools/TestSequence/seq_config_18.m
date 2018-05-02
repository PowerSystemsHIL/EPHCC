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
CloudDelay = -10;

Irradiance.Rise = 20*60;            % FIX, Sunrise beginning time t=20min
Irradiance.RiseDuration = 40*60;    % FIX, Duration of ramp until full irradiance

Nc=Nc+1; Cloud(Nc) = struct('Start', 35*60, 'Depth', 0.9, 'Ramp', 20, 'Duration', 120);
Nc=Nc+1; Cloud(Nc) = struct('Start', 45*60, 'Depth', 0.9, 'Ramp', 10, 'Duration', 30);
Nc=Nc+1; Cloud(Nc) = struct('Start', 60*60, 'Depth', 0.6, 'Ramp', 15, 'Duration', 30);
Nc=Nc+1; Cloud(Nc) = struct('Start', 63*60, 'Depth', 0.7, 'Ramp', 15, 'Duration', 30);
Nc=Nc+1; Cloud(Nc) = struct('Start', 72*60, 'Depth', 0.5, 'Ramp', 15 , 'Duration', 60);
Nc=Nc+1; Cloud(Nc) = struct('Start', 81*60, 'Depth', 0.9, 'Ramp', 30, 'Duration', 240);
Nc=Nc+1; Cloud(Nc) = struct('Start', 92*60, 'Depth', 0.9, 'Ramp', 10, 'Duration', 60);

%% Motors
Next('Motor1'   , 12, 1);
Next('Motor1'   , 25, 0);
Next('Motor1'   , 28, 1);
Next('Motor1'   , 42, 0);
Next('Motor1'   , 49, 1);
Next('Motor1'   , 65, 0);
Next('Motor1'   , 69, 1);
Next('Motor1'   , 89, 0);


Next('Motor2'   , 4 , 1);
Next('Motor2'   , 25, 0);
Next('Motor2'   , 45, 1);
Next('Motor2'   , 62, 0);
Next('Motor2'   , 68, 1);
Next('Motor2'   , 73, 0);
Next('Motor2'   , 82, 1);

%% DER contingencies
Next('Fault.Ess1', 20, 1);
Next('Fault.Ess1', 21.5, 0);
Next('Fault.Gen1', 37, 1);
Next('Fault.Gen1', 39, 0);
Next('Fault.Ess1', 48, 1);
Next('Fault.Ess1', 49.5, 0);
Next('Fault.Pv1', 66, 1);
Next('Fault.Pv1', 68, 0);
Next('Fault.Gen2', 75, 1);
Next('Fault.Gen2', 76.5, 0);
Next('Fault.Pv1', 95, 1);
Next('Fault.Pv1', 97, 0);

%% Sequence start - grid connected
Next('MGC_Enable', 2/60, 1);            % start of test sequence

Next('DMS.kWena', 2, 1);
Next('DMS.kWref', 2, 10000);         % DMS xport request
Nf=Nf+1; Grid.Freq(Nf) = struct('Start', 5*60, 'Depth', 0.4, 'Duration', 60);
Next('DMS.PFena', 2, 1);
Next('DMS.PFref', 2, 1.0);         % unity power factor request
% Next('DMS.Dq'   , 3, 6);         % Droops will be set to it's values
% since init - evauation of responses will only be done during voltage/freq event 
% Next('DMS.Dp'   , 5, 3);
Next('DMS.kWena', 7, 0);
Next('DMS.kWref', 7, 0);           % DMS xport request
%Next('DMS.Dp'   , 10, 0);
%Next('DMS.Dq'   , 10, 0);
Next('DMS.PFena', 7, 0);           % unity power factor request




%% Unintentional islanding - start island
Next('Fault.Loc1'      , 10, 1);
Next('Fault.Loc1'      , 11, 0);
Next('DMS.DisReq'      , 10+(10/60),   1);
Next('Grid.OpenSSF1'   , 10, 1); 
Next('Grid.OpenSSF2'   , 10.2, 1); 
Next('Grid.OpenSSF3'   , 10.4, 1); 
Next('Grid.CutGrid'    , 10.6, 1);


Next('Grid.CutGrid'    , 22, 0);
Next('Grid.OpenSSF1'   , 22.2, 0); 
Next('Grid.OpenSSF2'   , 22.4, 0); 
Next('Grid.OpenSSF3'   , 22.6, 0); 
Next('DMS.DisReq'      , 22.7, 0);

%% End of unplanned islanding - start grid connected
Next('DMS.kWena', 33, 1);
Next('DMS.kWref', 33, 8000);         % DMS import request
Next('DMS.PFena', 28, 1);
Next('DMS.PFref', 28, 0.97);         
Nf=Nf+1; Grid.Freq(Nf) = struct('Start', 34*60, 'Depth', -0.6, 'Duration', 20);
Next('DMS.kWref', 35, 7000);         % DMS import request
Next('DMS.kWref', 37, 6000);         % DMS import request
Next('DMS.Dp'   , 39, 2);
Nf=Nf+1; Grid.Freq(Nf) = struct('Start', 39*60, 'Depth', 0.3, 'Duration', 20);

Next('DMS.kWena', 43, 0);
Next('DMS.kWref', 43, 0);           % DMS import request
%Next('DMS.Dp'   , 64, 0);
Nv=Nv+1; Grid.Volt(Nv) = struct('Start', 47*60, 'Depth', -115000*0.02, 'Duration', 120);
Next('DMS.PFena', 50, 0);


%% PLanned islanding - start island
Next('DMS.DisReq'      , 52, 1);
Next('Grid.OpenSSF1'   , 53, 1); 
Next('Grid.OpenSSF2'   , 53.2, 1); 
Next('Grid.OpenSSF3'   , 53.4, 1); 
Next('Grid.CutGrid'   , 53.6, 1); 

Next('Grid.CutGrid'    , 84,   0); 
Next('Grid.OpenSSF1'   , 84.2, 0); 
Next('Grid.OpenSSF2'   , 84.4, 0); 
Next('Grid.OpenSSF3'   , 84.6, 0); 
Next('DMS.DisReq'      , 85,   0);
%% End of planned islanding - start grid connected

Next('DMS.PFena', 87, 1);
Next('DMS.PFref', 87, 1);   
Next('DMS.PFref', 96, 0.98); 
Next('DMS.kWena', 96, 1);
Next('DMS.kWref', 96, 10000);         % DMS import request
%Next('DMS.Dq'   , 3, 6);
Nv=Nv+1; Grid.Volt(Nv) = struct('Start', 89*60, 'Depth', 115000*0.03, 'Duration', 150);
Nf=Nf+1; Grid.Freq(Nf) = struct('Start', 98*60, 'Depth', -0.4, 'Duration', 40);

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
