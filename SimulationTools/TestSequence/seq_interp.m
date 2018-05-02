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

function [ seq_out ] = seq_interp( seq, t_new )
%SEQ_INTERPOLATE Summary of this function goes here
%   Interpolation of test sequence into results time
%   Additionally all data's are transposed - original tes seq is vertical
%   (1,N) while results are horizontal (Nx1)
%% interpolate test sequence vectors to result time
seq_out.opt = seq.opt;

seq_out.t = t_new';

seq_out.fault.loc1 = round(interp1(seq.t, seq.fault.loc1, t_new)); seq_out.fault.loc1(isnan(seq_out.fault.loc1)) = 0;
seq_out.cut_grid = round(interp1(seq.t, seq.cut_grid, t_new)); seq_out.cut_grid(isnan(seq_out.cut_grid)) = 0;


seq_out.motor1 = round(interp1(seq.t, seq.motor1, t_new));
seq_out.motor2 = round(interp1(seq.t, seq.motor2, t_new));
seq_out.dms_disreq = round(interp1(seq.t, seq.dms_disreq, t_new)); seq_out.dms_disreq(isnan(seq_out.dms_disreq)) = 0;
seq_out.dms_kWena = round(interp1(seq.t, seq.dms_kWena, t_new));
seq_out.dms_PFena = round(interp1(seq.t, seq.dms_PFena, t_new));
seq_out.dms_kWref = interp1(seq.t, seq.dms_kWref, t_new);
seq_out.dms_PFref = interp1(seq.t, seq.dms_PFref, t_new);
seq_out.dms_kWref_nan = interp1(seq.t, seq.dms_kWref_nan, t_new);
seq_out.dms_kWHzref_nan = interp1(seq.t, seq.dms_kWHzref_nan, t_new);
seq_out.dms_kVArVoltref_nan = interp1(seq.t, seq.dms_kVArVoltref_nan, t_new);
seq_out.dms_kVArref_nan = interp1(seq.t, seq.dms_kVArref_nan, t_new);
seq_out.dms_PFref_nan = interp1(seq.t, seq.dms_PFref_nan, t_new);
seq_out.dms_phiref_nan = interp1(seq.t, seq.dms_phiref_nan, t_new);
seq_out.dms_Dp = interp1(seq.t, seq.dms_Dp, t_new);
seq_out.dms_Dq = interp1(seq.t, seq.dms_Dq, t_new);

seq_out.grid_freq = interp1(seq.t, seq.grid_freq, t_new);
seq_out.grid_volt = interp1(seq.t, seq.grid_volt, t_new);

seq_out.price = interp1(seq.t, seq.price, t_new);

end

