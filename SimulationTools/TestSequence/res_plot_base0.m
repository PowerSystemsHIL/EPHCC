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
