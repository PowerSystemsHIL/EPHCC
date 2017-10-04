clear all;
close all;
clear all;
% Generate test sequence vector before running - sequence stored in seq.mat
seq_generate;
% Run UDP stream to opal and store received data. Results stored in res.mata
TX_RCV_UDP_Stream;
%% Plot test results
% Results shall be stored to C:\Results\ directory as these are used to
% generate the report
% zoom = [10 20]
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