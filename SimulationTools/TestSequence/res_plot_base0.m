%% Load the data
clear all;
close all;
load 20170810_0800_res_base0.mat; 
%%
res_remove_time;

%%  Initialise supporting data
prices = init_prices;
id = init_ID;
comm = calc_common(res, seq);
seqi = seq_interp(seq, comm.t_sek);

%% Calc all KPP
kpp1 = calc_kpp1(res, seqi, comm, prices);
kpp3 = calc_kpp3(res, seqi, comm, prices, id);
kpp4 = calc_kpp4(res, seqi, comm, prices, id, kpp3);
kpp5 = calc_kpp5(res, seqi, comm, prices, id);





%% Plot KPP1
plot_kpp1;
plot_kpp3;

%% Plots
seq_plot(seq);

res_plot_feeders;

