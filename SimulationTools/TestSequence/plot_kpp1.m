%%
figure;
subplot(3,1,1); area(comm.t_min, kpp1.P_good_per_class, 'LineStyle', 'none'); grid on;
set(gca,'XTick', [0:5:100]);
title('kW served by load class');
legend({'M','I','P','C'});
subplot(3,1,2); area(comm.t_min, -kpp1.P_outage_per_class, 'LineStyle', 'none'); grid on;
set(gca,'XTick', [0:5:100]);
title('kW outage by load class');
% subplot(4,1,3); area(comm.t_min, kpp1.E_good_per_class, 'LineStyle', 'none'); hold on;
%                 area(comm.t_min, -kpp1.EO_per_class, 'LineStyle', 'none');
% subplot(4,1,4); area(comm.t_min, [kpp1.EP_per_class], 'LineStyle', 'none'); hold on;
%                 area(comm.t_min, -kpp1.EOP_per_class, 'LineStyle', 'none');
%                 plot(comm.t_min, zeros(M,1), 'b', 'LineWidth', 2);
%                 plot(comm.t_min, kpp1.Price_total, 'r', 'LineWidth', 2);
subplot(3,1,3); 
    plot(comm.t_min, [kpp1.d_cum_per_class(:,1:4)]); hold on; grid on;
    plot(comm.t_min, [kpp1.d_cum_per_class(:,5:8)], '--');
    legend(kpp1.d_cum_per_class_legend);
    plot(comm.t_min, kpp1.d_cum_total, 'r', 'LineWidth', 3);
    title('KPP1 summary values [$]');
    set(gca,'XTick', [0:5:100]);

xlabel('time [min]');
    
