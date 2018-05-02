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



%% read relay settings
% This file reads-in all the relay settings for the system
% The settings are arrange in increasing order
% reads relay settings from an excel file

addpath('relay_settings', 'relays_configuration_files', 'relay_iec61850');

F0 = xlsread('F0_relay_banshee.xlsx');
F1 = xlsread('F1_relay_banshee.xlsx');
F2 = xlsread('F2_relay_banshee.xlsx');
F3 = xlsread('F3_relay_banshee.xlsx');
F4 = xlsread('F4_relay_nrel.xlsx');

DER_REL = xlsread('DER_relay.xlsx');
% Define CB id's and their aliases
CBID.CB151     = 1;
CBID.GEN1      = 1;
CBID.CB251     = 2;
CBID.ESS1      = 2;
CBID.CB252     = 3;
CBID.PV1       = 3;
CBID.CB351     = 4;
CBID.GEN2      = 4;
CBID.CB451     = 5;
CBID.GEN3      = 5;
CBID.CB452     = 6;
CBID.ESS2      = 6;
CBID.CB453     = 7;
CBID.PV2       = 7;


