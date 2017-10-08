figure('name', 'kpp3');

ax = [];
ax= [ax subplot(3,1,1)]; 
    area(comm.t_min, [kpp3.p_per_class]); hold on; grid on;
    plot(comm.t_min, [ kpp3.lim.p_max  ], '--');
    plot(comm.t_min, [ kpp3.lim.p_min  ], '--');
    ylim([min(min(min(kpp3.p_per_class)),-6000) max(max(max(kpp3.p_per_class)),11000)]);
    set(gca,'XTick', [0:5:100]);
    title('Active power at POI [kW]');    
ax= [ax subplot(3,1,2)]; 
    area(comm.t_min, [kpp3.q_per_class]); hold on;  grid on;
    plot(comm.t_min, [ kpp3.lim.q_max  ], '--');
    plot(comm.t_min, [ kpp3.lim.q_min  ], '--');
    ylim([min(min(min(kpp3.q_per_class)),-6000) max(max(max(kpp3.q_per_class)),11000)]);
    set(gca,'XTick', [0:5:100]);
    title('Reactive power at POI [kVAr]');    
ax= [ax subplot(3,1,3)]; 
    plot(comm.t_min, [kpp3.d_cum_per_class]); hold on;  grid on;
    plot(comm.t_min, [kpp3.d_cum_total], 'LineWidth', 3);
    set(gca,'XTick', [0:5:100]);
    title('KPP3 summary values [$]');
    legend(kpp3.legend_per_class);

xlabel('time [min]');
linkaxes(ax,'x');