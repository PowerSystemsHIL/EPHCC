figure;

ax = [];
ax= [ax subplot(3,1,1)]; plot(seqi.t, [ kpp3.pcc.p ], 'LineWidth', 2); hold on
                         plot(seqi.t, [ kpp4.lim.kWHz_max ], '--');
                         plot(seqi.t, [ kpp4.lim.kWHz_min ], '--');
                         all = [ kpp3.pcc.p      kpp4.lim.kWHz_max kpp4.lim.kWHz_min ];
                         ymin = (min(min(all))); ymax = (max(max(all)));
                         ymin = (floor(ymin/200))*200;
                         ymax = (ceil(ymax/200))*200;
                         ylim([ymin ymax]);
                         legend({'P_{POI}' 'Q_{POI}'});
ax= [ax subplot(3,1,2)]; plot(seqi.t, [seqi.dms_phiref_nan+5 ...
                             seqi.dms_phiref_nan-5 ...
                             ... %seqi.dms_kWref_nan+(0.02+1./seqi.dms_Dp)*10e3; ...
                             ... %seqi.dms_kWref_nan-(0.02+1./seqi.dms_Dp)*10e3; ...
                             kpp3.pcc.ang]);
ax= [ax subplot(3,1,3)]; 
    area(seqi.t, [kpp3.p_per_class]); hold on;
    plot(seqi.t, [ kpp3.lim.p_max  kpp3.lim.q_max], '--');
    plot(seqi.t, [ kpp3.lim.p_min  kpp3.lim.q_min], '--');
    ylim([min(min(min(all)),-6000) max(max(max(all)),11000)]);
                                   

linkaxes(ax,'x');