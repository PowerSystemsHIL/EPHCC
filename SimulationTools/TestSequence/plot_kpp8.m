figure;

ax = [];
ax= [ax subplot(1,1,1)]; 
    plot(comm.t_min, [kpp8.d_cum_per_class]); hold on; grid on;
    plot(comm.t_min, [kpp8.d_cum_total], 'LineWidth', 3);
    title('KPP8 - sum of KPP1..KPP7 [$]');
                                   
legend(kpp8.legend_per_class);
linkaxes(ax,'x');