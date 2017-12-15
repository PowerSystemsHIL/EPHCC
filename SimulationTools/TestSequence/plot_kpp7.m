ax = [];
figure('name', 'kpp7_a');

ax= [ax subplot(3,1,1)]; 
    area(comm.t_min, [cumsum(kpp7.gen1_start) cumsum(kpp7.gen2_start) cumsum(kpp7.gen3_start)]);  grid on;
    set(gca,'XTick', [0:5:100]);
    legend({'Gen1', 'Gen2', 'Gen3'},  'location', 'NorthWest');
    title('Generators reconnections count [unit]');
    
ax= [ax subplot(3,1,2)]; 
    plot(comm.t_min, cumsum(kpp7.cb_switches));  grid on;
    set(gca,'XTick', [0:5:100]);
    title('CB switches count [unit]');

ax= [ax subplot(3,1,3)]; 
    plot(comm.t_min, [kpp7.soc kpp7.bat_cycle]);  grid on;
    set(gca,'XTick', [0:5:100]);
    legend({'SoC1', 'SoC2', 'Cycle1', 'Cycle2'},  'location', 'NorthWest');
    title('SoC of batteries and battery cycles [unit]');

xlabel('time [min]');
linkaxes(ax,'x');
%%
figure('name', 'kpp7_b');
ax= [ax subplot(4,1,1)]; 
    plot(comm.t_min, kpp7.curPU(:, kpp7.IsGen));  grid on;
    set(gca,'XTick', [0:5:100]);
    legend(kpp7.LegendGen,  'location', 'NorthWest');
    title('Generators current [pu]');
    
ax= [ax subplot(4,1,2)]; 
    plot(comm.t_min, kpp7.curPU(:, kpp7.IsLine));  grid on;
    set(gca,'XTick', [0:5:100]);
    %legend(kpp7.LegendLine,  'location', 'NorthWest');
    title('Lines current [pu]');

ax= [ax subplot(4,1,3)]; 
    plot(comm.t_min, kpp7.curPU(:, kpp7.IsTrafo));  grid on;
    set(gca,'XTick', [0:5:100]);
    %legend(kpp7.LegendTrafo,  'location', 'NorthWest');
    title('Transformers current [pu]');

ax= [ax subplot(4,1,4)]; 
    plot(comm.t_min, kpp7.d_cum_per_class(:,[5 6 7])); 
    hold on;
    plot(comm.t_min, kpp7.d_cum_total, 'r', 'LineWidth', 2);
    title('KPP7 summary values [$]');
    legend(kpp7.legend_per_class{[5 6 7]}, 'location', 'SouthWest');
    linkaxes(ax,'x');
%% Frequency
figure('name', 'kpp7'); 
ax= [ax subplot(1,1,1)]; 
plot(comm.t_min, kpp7.d_cum_per_class);
hold on;
plot(comm.t_min, kpp7.d_cum_total, 'r', 'LineWidth', 2);
title('KPP7 summary values [$]');
legend(kpp7.legend_per_class, 'location', 'SouthWest');
linkaxes(ax,'x');