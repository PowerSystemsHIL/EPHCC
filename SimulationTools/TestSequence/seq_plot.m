function [ax] = seq_plot(seq);
ax = [];
opt = seq.opt;
figure;
ax= [ax subplot(6,1,1)]; plot(seq.t, [seq.irradiance; seq.price]);
ax= [ax subplot(6,1,2)]; plot(seq.t, [seq.dms_kWref_nan+0.02*10e3; ...
                             seq.dms_kWref_nan-0.02*10e3; ...
                             seq.dms_kWHzref_nan+0.05*10e3; ...
                             seq.dms_kWHzref_nan-0.05*10e3; ...
                             ]);
ax= [ax subplot(6,1,3)]; plot(seq.t, [seq.dms_phiref_nan+5; ...
                             seq.dms_phiref_nan-5; ...
                             %seq.dms_kWref_nan+(0.02+1./seq.dms_Dp)*10e3; ...
                             %seq.dms_kWref_nan-(0.02+1./seq.dms_Dp)*10e3; ...
                             ]);

ax= [ax subplot(6,1,4)]; plot(seq.t, [seq.grid_freq./60.0; seq.grid_volt./115000]);
                         
dig     = [seq.fault.loc1; seq.fault.loc2; seq.fault.loc3; seq.fault.loc4; seq.fault.loc5; seq.fault.loc6];
dig_lab = {'fault.loc1' 'fault.loc2' 'fault.loc3' 'fault.loc4' 'fault.loc5' 'fault.loc6' };
dig     = [dig; seq.fault.gen1; seq.fault.gen2; seq.fault.gen3; seq.fault.ess1; seq.fault.ess2; seq.fault.pv1; seq.fault.pv2];
dig_lab = [dig_lab 'fault.gen1' 'fault.gen2' 'fault.gen3' 'fault.ess1' 'fault.ess2' 'fault.pv1' 'fault.pv2' ];
dig     = [dig; seq.motor1; seq.motor2; seq.cut_grid; seq.dms_disreq; seq.mgc_enable];
dig_lab = [dig_lab 'Mot1' 'Mot2' 'G.Cut'            'DMS.DR'        'MGC.En'      ];

Ndig = size(dig,1);
dig_lab = dig_lab(Ndig:-1:1);
base = (((Ndig-1):-1:0)'*ones(1,opt.N)*1.2);
ax= [ax subplot(6,1,[5 6])]; plot(seq.t, dig + base);
set(gca,'YTick', [0:Ndig-1]*1.2);
set(gca,'YTickLabel', dig_lab);
linkaxes(ax,'x');
%tightfig();