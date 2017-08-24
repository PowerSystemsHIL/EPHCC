function [ kpp6 ] = calc_kpp6( res, seqi, comm, prices, kpp4 )
%CALC_KPP1 Summary of this function goes here
%   Detailed explanation goes here

soc = res.battery_SoC * 100 / 10000;

t_under = zeros(comm.M,2);
not_island = (~kpp4.planned_island) & (~kpp4.unplanned_island);

lim = nan*ones(comm.M,1);
lim(not_island) = 40;
t_under( (soc<40) & repmat(not_island,1,2) ) = 1;
dot = -prices.P61;     % dot $/min
d_per_class = t_under.*dot.*seqi.opt.Ts/60;                         % $ values
d_cum_per_class = cumsum(d_per_class);
legend_per_class = {'ESS1' 'ESS2'};
d_cum_total = sum(d_cum_per_class,2);

clear( 'res', 'seqi', 'comm', 'prices', 'kpp4' );
kpp6=wsp2struct(who);


