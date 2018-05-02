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

function seq_print(seq)

isl1 = seq.opt.DMS.DisReq.Time(3) - seq.opt.DMS.DisReq.Time(2);
isl2 = seq.opt.DMS.DisReq.Time(5) - seq.opt.DMS.DisReq.Time(4);

disp(['1st islanding period: ' num2str(isl1/60) ' min']);
disp(['2nd islanding period: ' num2str(isl2/60) ' min']);
disp(['Tot islanding period: ' num2str((isl1+isl2)/60) ' min']);

kVAr = sum(~isnan(seq.dms_kVArref_nan)*0.2)/60;
kW = sum(~isnan(seq.dms_kWref_nan)*0.2)/60;
kWHz = sum(~isnan(seq.dms_kWHzref_nan)*0.2)/60;
kVArVolt = sum(~isnan(seq.dms_kVArVoltref_nan)*0.2)/60;

disp(['kW request period   : ' num2str(kW) ' min']);
disp(['kVAR request period : ' num2str(kVAr) ' min']);
disp(['kW/Hz period        : ' num2str(kWHz) ' min']);
disp(['kVar/V period       : ' num2str(kVArVolt) ' min']);


