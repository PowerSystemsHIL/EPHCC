figure;

ax = [];
ax= [ax subplot(2,1,1)]; 
    plot(seqi.t, [kpp8.d_cum_per_class]); hold on;
    plot(seqi.t, [kpp8.d_cum_total], 'LineWidth', 2);
                                   

linkaxes(ax,'x');