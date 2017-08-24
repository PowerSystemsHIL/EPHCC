function [ kpp4 ] = calc_kpp4( res, seqi, comm, prices, id, kpp3)
%CALC_KPP4 Summary of this function goes here
%   Detailed explanation goes here

%% Calculate limits
lim.kW_max = seqi.dms_kWref_nan + 0.05*10e3;
lim.kW_min = seqi.dms_kWref_nan - 0.05*10e3;
lim.kWHz_max =  seqi.dms_kWHzref_nan + 0.10*10e3;
lim.kWHz_min =  seqi.dms_kWHzref_nan - 0.10*10e3;;

dms_kVArref = sqrt(1-power(seqi.dms_PFref,2))./seqi.dms_PFref.*kpp3.pcc.p;        % Reactive power with PF control term
dms_kVArVoltref = dms_kVArref + (seqi.grid_volt-115000)/115000./(seqi.dms_Dq/100)*10e3;     % Reactive power with kVAR/Volt support

iVoltEvent = seqi.grid_volt ~= 115000;

nanv = nan*ones(comm.M,1);
dms_kVArref_nan = nanv;
dms_kVArref_nan(seqi.dms_PFena==1) = dms_kVArref(seqi.dms_PFena==1);
dms_kVArVoltref_nan = nanv;
dms_kVArVoltref_nan(iVoltEvent) = dms_kVArVoltref(iVoltEvent);

lim.kVAr_max = dms_kVArref_nan + 0.05*10e3;
lim.kVAr_min = dms_kVArref_nan - 0.05*10e3;
lim.kVArVolt_max =  dms_kVArVoltref_nan + 0.10*10e3;
lim.kVArVolt_min =  dms_kVArVoltref_nan - 0.10*10e3;

%% Planned islanding
t_for_islanding = 30; %[s]
it_island = t_for_islanding/seqi.opt.Ts;
% delay criteria for checking if islanded
planned_island = seqi.dms_disreq & [zeros(it_island, 1); seqi.dms_disreq(1:end-it_island)];
unplanned_island = (seqi.fault.loc1 | seqi.cut_grid) & ~planned_island;
% determine when grid is islanded = CB100 & CB200 & CB300 opened
islanded = (res.breaker(:,id.CB100) | res.breaker(:,id.CB200) | res.breaker(:,id.CB200)) & 1;

planned_penalty = zeros(comm.M,1);
unplanned_penalty = zeros(comm.M,1);
planned_penalty(~islanded & planned_island) = 1;
unplanned_penalty(~islanded & unplanned_island) = 1;

%% Calculate within limits
kW_good = zeros(comm.M,1);
kWHz_good = zeros(comm.M,1);
kVAr_good = zeros(comm.M,1);
kVArVolt_good = zeros(comm.M,1);

kW_good((kpp3.pcc.p<lim.kW_max)&(kpp3.pcc.p>lim.kW_min)) = 1;
kWHz_good((kpp3.pcc.p<lim.kWHz_max)&(kpp3.pcc.p>lim.kWHz_min))  = 1;
kVAr_good((kpp3.pcc.q<lim.kVAr_max)&(kpp3.pcc.q>lim.kVAr_min))  = 1;
kVArVolt_good((kpp3.pcc.q<lim.kVArVolt_max)&(kpp3.pcc.q>lim.kVArVolt_min)) = 1;

t_per_class = [kW_good kWHz_good kVAr_good kVArVolt_good planned_penalty unplanned_penalty];               % t - time
dot_per_class = [prices.P41 prices.P44 prices.P46 prices.P43 -prices.P45 -prices.P47];          % dot $/min
dot = repmat(dot_per_class, comm.M,1); 
d_per_class = t_per_class.*dot.*seqi.opt.Ts/60;                         % $ values
d_cum_per_class = cumsum(d_per_class);
legend_per_class = {'T_{TD/M}', 'T_{FkW}', 'T_{PF}', 'T_{VV}', 'T_{DR}', 'T_{UD}'};
d_cum_total = sum(d_cum_per_class,2);

clear( 'res', 'seqi', 'comm', 'prices', 'id', 'kpp3' );
kpp4=wsp2struct(who);


