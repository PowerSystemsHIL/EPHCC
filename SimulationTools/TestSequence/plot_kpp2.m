figure;

ax = [];
ax= [ax subplot(2,1,1)]; 
    area(comm.t_min, [kpp2.d_fuel(:,[1 3]) kpp2.d_fuel(:,2)+kpp2.d_fuel(:,4)]);  grid on;
    set(gca,'XTick', [0:5:100]);
    legend({'Diesel1' 'Diesel3' 'CHP2'});
    title('Fuel costs per hour [$/h]');    
ax= [ax subplot(2,1,2)]; 
    plot(comm.t_min, [kpp2.d_cum_per_class]); hold on;  grid on;
    plot(comm.t_min, [kpp2.d_cum_total], 'LineWidth', 3);
    set(gca,'XTick', [0:5:100]);
    title('KPP2 summary values [$]');
    legend(kpp2.legend_per_class);
    
xlabel('time [min]');
linkaxes(ax,'x');