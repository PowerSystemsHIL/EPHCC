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

close all;

%% Process for PHIL or CHIL run
res.PHIL = 1; % Comment out if CHIL shall be used
res.Speed = 1;

%%  Initialise supporting data
prices = init_prices;
id = init_ID;
comm = calc_common(res, seq, TxSequenceSpeed);
seqi = seq_interp(seq, comm.t_sek);

%% Calc all KPP
kpp1 = calc_kpp1(res, seqi, comm, prices);
kpp2 = calc_kpp2(res, seqi, comm, prices, id);
kpp3 = calc_kpp3(res, seqi, comm, prices, id);
kpp4 = calc_kpp4(res, seqi, comm, prices, id, kpp3);
kpp5 = calc_kpp5(res, seqi, comm, prices, id);
kpp6 = calc_kpp6(res, seqi, comm, prices, kpp4);
kpp7 = calc_kpp7(res, seqi, comm, prices, id);
kpp8 = calc_kpp8(kpp1, kpp2, kpp3, kpp4, kpp5, kpp6, kpp7);

%% Plot all KPP's
plot_kpp1;
plot_kpp2;
plot_kpp3;
plot_kpp4;
plot_kpp5;
plot_kpp6;
plot_kpp7;
plot_kpp8;

