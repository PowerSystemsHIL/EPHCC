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
kpp8 = calc_kpp8(kpp1, kpp2, kpp3, kpp4, kpp5, kpp6);

%% Plot all KPP's
plot_kpp1;
plot_kpp2;
plot_kpp3;
plot_kpp4;
plot_kpp5;
plot_kpp6;
plot_kpp7;
plot_kpp8;

