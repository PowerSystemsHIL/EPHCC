function [ sequence ] = generate_all( opt )
%GENERATE_ALL Summary of this function goes here
%   Detailed explanation goes here

t = 0:opt.Ts:opt.End;

irradiance = gen_irradiance(opt);
irradiance = [  gen_clouds(opt, irradiance, 0); ... 
                gen_clouds(opt, irradiance, opt.CloudDelay)];
price = gen_price(opt);
cut_grid = gen_stairs(opt, 'Grid.CutGrid');
grid_open_ssf1 = gen_stairs(opt, 'Grid.OpenSSF1');
grid_open_ssf2 = gen_stairs(opt, 'Grid.OpenSSF2');
grid_open_ssf3 = gen_stairs(opt, 'Grid.OpenSSF3');
dms_disreq = gen_stairs(opt, 'DMS.DisReq');
dms_kWena  = gen_stairs(opt, 'DMS.kWena');
dms_PFena  = gen_stairs(opt, 'DMS.PFena');
dms_kWref  = gen_stairs(opt, 'DMS.kWref');
dms_PFref  = gen_stairs(opt, 'DMS.PFref');

nanv = nan*ones(1,opt.N);
kWref = nanv;
dms_kWref_nan = nanv;
dms_kWref_nan(dms_kWena==1) = dms_kWref(dms_kWena==1);
dms_PFref_nan = nanv;
dms_PFref_nan(dms_PFena==1) = dms_PFref(dms_PFena==1);
dms_phiref_nan = acos(dms_PFref_nan)/pi*180;

grid_freq = 60.000 * ones(1,opt.N);
grid_freq = gen_freq(opt, grid_freq);

%TODO: Freq and voltage stimuli
dms_Dp     = gen_stairs(opt, 'DMS.Dp');
dms_Dq     = gen_stairs(opt, 'DMS.Dq');
motor1     = gen_stairs(opt, 'Motor1');
motor2     = gen_stairs(opt, 'Motor2');

mgc_enable = gen_stairs(opt, 'MGC_Enable');
fault.loc1 = gen_stairs(opt, 'Fault.Loc1');
fault.loc2 = gen_stairs(opt, 'Fault.Loc2');
fault.loc3 = gen_stairs(opt, 'Fault.Loc3');
fault.loc4 = gen_stairs(opt, 'Fault.Loc4');
fault.loc5 = gen_stairs(opt, 'Fault.Loc5');
fault.loc6 = gen_stairs(opt, 'Fault.Loc6');
fault.gen1 = gen_stairs(opt, 'Fault.Gen1');
fault.gen2 = gen_stairs(opt, 'Fault.Gen2');
fault.gen3 = gen_stairs(opt, 'Fault.Gen3');
fault.ess1 = gen_stairs(opt, 'Fault.Ess1');
fault.ess2 = gen_stairs(opt, 'Fault.Ess2');
fault.pv1  = gen_stairs(opt, 'Fault.Pv1');
fault.pv2  = gen_stairs(opt, 'Fault.Pv2');

udpframe = int16(zeros(15,opt.N));
udpframe(1:2,:)   = reshape(typecast(uint32(t*1000), 'int16'),2,opt.N);
udpframe(10,:)    = uint16(mgc_enable)*2 + uint16(cut_grid);
% Hz udpframe(11,:)
% Volt udpframe(12,:)
udpframe(13,:)    = 1000*price;
udpframe(14:15,:) = 1000*irradiance;

sequence=wsp2struct(who);
end

