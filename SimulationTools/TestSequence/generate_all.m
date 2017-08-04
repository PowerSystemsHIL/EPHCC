function [ sequence ] = generate_all( opt )
%GENERATE_ALL Summary of this function goes here
%   Detailed explanation goes here

t = 0:opt.Ts:opt.End;

irradiance = gen_irradiance(opt);
irradiance = [  gen_clouds(opt, irradiance, 0); ... 
                gen_clouds(opt, irradiance, opt.CloudDelay)];
price = gen_price(opt);
cut_grid = gen_stairs(opt, 'Grid.CutGrid');
dms_disreq = gen_stairs(opt, 'DMS.DisReq');
mgc_enable = gen_stairs(opt, 'MGC_Enable');
fault.loc1 = gen_stairs(opt, 'Fault.Loc1');
fault.loc2 = gen_stairs(opt, 'Fault.Loc2');


udpframe = int16(zeros(15,opt.N));
udpframe(1:2,:)   = reshape(typecast(uint32(t*1000), 'int16'),2,opt.N);
udpframe(10,:)    = uint16(mgc_enable)*2 + uint16(cut_grid);
% Hz udpframe(11,:)
% Volt udpframe(12,:)
udpframe(13,:)    = 1000*price;
udpframe(14:15,:) = 1000*irradiance;

sequence=wsp2struct(who);
end

