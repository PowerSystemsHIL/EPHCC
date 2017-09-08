function [ kpp7 ] = calc_kpp7( res, seqi, comm, prices, id )
%CALC_KPP1 Summary of this function goes here
%   Detailed explanation goes here

p_pv = [res.powerreal(:,id.CBPv1) 20*res.powerreal(:,id.CBPv2)];
e_pv = cumsum(p_pv*seqi.opt.Ts/3600);
brk_closed = bitand(1,res.breaker);
brkN = size(brk_closed,2);
transitions = [diff(brk_closed); zeros(1,brkN)];
sw_open  = zeros(comm.M,brkN);
sw_close = zeros(comm.M,brkN);
sw_open(transitions<0) = 1;
sw_close(transitions>0) = 1;
cb_switches = sum(sw_open(:,id.CB101:id.CB300),2);
gen1_start = sw_close(:,id.CBGen1);
gen2_start = sw_close(:,id.CBGen2);
gen3_start = sw_close(:,id.CBGen3);

%Calculate battery cycling
soc = res.battery_SoC./10000;
bat_cycle = [[0 0] ; cumsum(abs(diff(soc))) ];

d_per_class = [cb_switches*prices.P74];
d_cum_per_class = cumsum(d_per_class);
legend_per_class = {'CB switch'};
d_cum_total = sum(d_cum_per_class,2);

clear( 'res', 'seqi', 'comm', 'prices' );
kpp7=wsp2struct(who);


