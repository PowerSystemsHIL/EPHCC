figure;

ax = [];
ax= [ax subplot(3,1,1)]; plot(seqi.t, [ kpp3.pcc.p ], 'r', 'LineWidth', 1); hold on
                         plot(seqi.t, [ kpp4.lim.kW_max kpp4.lim.kW_min kpp4.lim.kWHz_max kpp4.lim.kWHz_min], '--');
                         all = [ kpp3.pcc.p      kpp4.lim.kWHz_max kpp4.lim.kWHz_min ];
                         ymin = (min(min(all))); ymax = (max(max(all)));
                         ymin = (floor(ymin/200))*200;
                         ymax = (ceil(ymax/200))*200;
                         ylim([ymin ymax]);
ax= [ax subplot(3,1,2)]; plot(seqi.t, [kpp3.pcc.q], 'r', 'LineWidth', 1); hold on;
    plot(seqi.t, [kpp4.lim.kVAr_max     kpp4.lim.kVAr_min kpp4.lim.kVArVolt_max kpp4.lim.kVArVolt_min], '--' );
ax= [ax subplot(3,1,3)]; 
    plot(seqi.t, [kpp4.d_cum_per_class]); hold on;
    plot(seqi.t, [kpp4.d_cum_total], 'LineWidth', 2);
                                   

linkaxes(ax,'x');