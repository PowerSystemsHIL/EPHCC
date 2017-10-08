figure('name', 'kpp6');

ax = [];
ax= [ax subplot(2,1,1)]; plot(comm.t_min, [ kpp6.soc ], 'LineWidth', 2); hold on; grid on;
    plot(comm.t_min, [ kpp6.lim ], 'r--', 'LineWidth', 2);
    set(gca,'XTick', [0:5:100]);
    title('ESS state of charge [kW]');
    legend(kpp6.legend_per_class);
ax= [ax subplot(2,1,2)]; 
    area(comm.t_min, [kpp6.d_cum_per_class]); hold on;grid on;
    %plot(comm.t_min, [kpp6.d_cum_total], 'LineWidth', 2);
    set(gca,'XTick', [0:5:100]);
    title('KPP6 summary values [$]');
    legend(kpp6.legend_per_class);
                                   

xlabel('time [min]');
linkaxes(ax,'x');