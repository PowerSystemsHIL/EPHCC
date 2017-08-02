function [ sequence ] = generate_all( opt )
%GENERATE_ALL Summary of this function goes here
%   Detailed explanation goes here

t = 0:opt.Ts:opt.End;

irradiance = gen_irradiance(opt);
irradiance = gen_clouds(opt, irradiance);
price = gen_price(opt);
grid_breakers = gen_stairs(opt, 'Grid.Breakers');
dms_disreq = gen_stairs(opt, 'DMS.DisReq');
mgc_enable = gen_stairs(opt, 'MGC_Enable');

clear opt;
sequence=wsp2struct(who);
end

