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

%load('opdaq_proc');

%% Convert raw data into result file
BANSHEEUDP = BANSHEE_Frame();
dat_all(25,:) = 23;

%% Select data
res_last_N = size(dat_all,2);
startMin = 0;
lastMin = 100;
startN = max(startMin*60/2e-3,1);
lastN = min(res_last_N, lastMin*60/2e-3);
dec = 10;
sel = startN:dec:lastN;


[res header] = UDP_decode_all(BANSHEEUDP, dat_all(:,sel));

%% Data type conversions
%int16 -> uint16
res.breaker(res.breaker<0) = res.breaker(res.breaker<0) + 2^16;

%% Store data to .dat files
%save header.mat header;

%%
res.t = double(tsim_all(sel));
%save res.mat;

%%  Initialise supporting data
prices = init_prices;
id = init_ID;
seq = seq_generate(91);
TxSequenceSpeed = 1;
comm = calc_common(res, seq, TxSequenceSpeed);
seqi = seq_interp(seq, comm.t_sek);

%%
res_plot_feeders_f
