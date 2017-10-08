figure('name', 'kpp4');

ax = [];
ax= [ax subplot(3,1,1)]; plot(comm.t_min, [ kpp3.pcc.p ], 'r', 'LineWidth', 2); hold on; grid on;
    plot(comm.t_min, [ kpp4.lim.kW_max kpp4.lim.kW_min kpp4.lim.kWHz_max kpp4.lim.kWHz_min], '--');
    all = [ kpp3.pcc.p      kpp4.lim.kWHz_max kpp4.lim.kWHz_min ];
    ymin = (min(min(all))); ymax = (max(max(all)));
    ymin = (floor(ymin/200))*200;
    ymax = (ceil(ymax/200))*200;
    ylim([ymin ymax]);
    set(gca,'XTick', [0:5:100]);
    title('Active power at POI [kW]');
ax= [ax subplot(3,1,2)]; plot(comm.t_min, [kpp3.pcc.q], 'r', 'LineWidth', 2); hold on;grid on;
    plot(comm.t_min, [kpp4.lim.kVAr_max     kpp4.lim.kVAr_min kpp4.lim.kVArVolt_max kpp4.lim.kVArVolt_min], '--' );
    set(gca,'XTick', [0:5:100]);
    title('Reactive power at POI [kVAr]');
ax= [ax subplot(3,1,3)]; 
    plot(comm.t_min, [kpp4.d_cum_per_class]); hold on;grid on;
    plot(comm.t_min, [kpp4.d_cum_total], 'LineWidth', 2);
    set(gca,'XTick', [0:5:100]);
    title('KPP4 summary values [$]');
    legend(kpp4.legend_per_class);
                                   

xlabel('time [min]');
linkaxes(ax,'x');