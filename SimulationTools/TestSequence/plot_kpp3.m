figure;

ax = [];
ax= [ax subplot(3,1,1)]; 
    area(seqi.t, [kpp3.p_per_class]); hold on;
    plot(seqi.t, [ kpp3.lim.p_max  ], '--');
    plot(seqi.t, [ kpp3.lim.p_min  ], '--');
    ylim([min(min(min(kpp3.p_per_class)),-6000) max(max(max(kpp3.p_per_class)),11000)]);
ax= [ax subplot(3,1,2)]; 
    area(seqi.t, [kpp3.q_per_class]); hold on;
    plot(seqi.t, [ kpp3.lim.q_max  ], '--');
    plot(seqi.t, [ kpp3.lim.q_min  ], '--');
    ylim([min(min(min(kpp3.q_per_class)),-6000) max(max(max(kpp3.q_per_class)),11000)]);
ax= [ax subplot(3,1,3)]; 
    plot(seqi.t, [kpp3.d_cum_total], 'r', 'LineWidth', 2); 
    

linkaxes(ax,'x');