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

%% Load the data
%clear all;
close all;
%load 20170810_0800_res_base0.mat; res_remove_time;  
    % Conservative case - all I and most P are closed to serve C
    % fully autonomous control - only SoC commands from operator
%load 20170811_1539_res.mat;        % Manual control - crashed after Gen1 outage
%load 20170815_0400_res.mat;         % Manual control - crashed after Gen1 outage
%load 20170824_1650_res.mat;         % Simple controller - didn't crash
%load 20170829_0800_res.mat;         % Simple controller - didn't crash
%load 20170918_1500_res.mat;

%% Plot test results
% Results shall be stored to C:\Results\ directory as these are used to
% generate the report
zoom = [0 100];
plot_kpp_all;
save_figs([1:10], 'C:\Results\kpp', 1,1);

%%
close all;
res_plot_feeders;
save_figs([1:4], 'C:\Results\feeder', 1,1);

%%
close all;
plot_der;
save_figs([1:7], 'C:\Results\der', 1,1);
