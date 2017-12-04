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
