figure;

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
figure
ax= [ax subplot(3,1,1)]; 
    plot(comm.t_min, kpp7.curPU(:, kpp7.IsGen));  grid on;
    set(gca,'XTick', [0:5:100]);
    legend(kpp7.LegendGen,  'location', 'NorthWest');
    title('Generators current [pu]');
    
ax= [ax subplot(3,1,2)]; 
    plot(comm.t_min, kpp7.curPU(:, kpp7.IsLine));  grid on;
    set(gca,'XTick', [0:5:100]);
    legend(kpp7.LegendLine,  'location', 'NorthWest');
    title('Generators current [pu]');

ax= [ax subplot(3,1,3)]; 
    plot(comm.t_min, kpp7.curPU(:, kpp7.IsTrafo));  grid on;
    set(gca,'XTick', [0:5:100]);
    legend(kpp7.LegendTrafo,  'location', 'NorthWest');
    title('Generators current [pu]');
    
xlabel('time [min]');
linkaxes(ax,'x');