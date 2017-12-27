function [ kpp2 ] = calc_kpp2( res, seqi, comm, prices, id )
%CALC_KPP1 Summary of this function goes here
%   Detailed explanation goes here

%% Fuel consumption
gen1_gal_h = res.dieselGenerator_fuelConsumption(:,1)/100*4;    % gal/h   x4 - correction to more fuel use more realistic
gen2_heat_rec = res.ngchpGenerator_heatRecovered/100;          % MBtu/h             
gen2_nm3_h = gen2_heat_rec/0.2/0.020267/1.76;                   % Nm^3/h             
if (isfield(res, 'PHIL') && (res.PHIL==1))
    gen3_p = res.powerreal(:,id.CBGen3)/80 + 0.2;
    gen3_p(gen3_p>1.6) = 1.6;
    gen3_gal_h = 1.6*4*(14.827*gen3_p.^4 -27.253*gen3_p.^3 +15.553*gen3_p.^2 + 7.9033*gen3_p + 2.5);
    gen3_gal_h(gen3_gal_h < 0) = 0;
else
    gen3_gal_h = res.dieselGenerator_fuelConsumption(:,2)/100/4*1.6*4;    % gal/h x4 - correction to more fuel use more realistic
end;
% unwind from i32 - didn't work due to too big dynamics of changes
% hi= gen2_nm3_h_raw > 2^13;
% lo= gen2_nm3_h_raw < -2^13;
% unwind_up = [0; hi(1:end-1)] & lo;
% unwind_dn = [0; lo(1:end-1)] & hi;
% unwind = cumsum(unwind_up - unwind_dn)*2^16;
% gen2_nm3_h = unwind + gen2_nm3_h_raw;

foh = [gen1_gal_h gen2_nm3_h gen3_gal_h gen2_heat_rec];
p =   [res.powerreal(:,id.CBGen1) res.powerreal(:,id.CBGen2) res.powerreal(:,id.CBGen3)*20];
e =   res.Speed * cumsum(p*seqi.opt.Ts/3600);
dof_coefs = -1*[prices.P21 prices.P22 prices.P21 -prices.P23];
dof       = repmat(dof_coefs, comm.M, 1);
d_fuel    = foh.*dof;

d_per_class = res.Speed * [d_fuel.*seqi.opt.Ts/3600];
d_cum_per_class = cumsum(d_per_class);
f_cum_per_class = d_cum_per_class ./ dof;
legend_per_class = {'Diesel1' 'NG2' 'Diesel3' 'Heat2'};
d_cum_total = sum(d_cum_per_class,2);


clear( 'res', 'seqi', 'comm', 'prices' );
kpp2=wsp2struct(who);


