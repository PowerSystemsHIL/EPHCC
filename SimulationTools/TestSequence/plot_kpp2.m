figure;

ax = [];
ax= [ax subplot(3,1,1)]; 
    area(seqi.t, kpp2.foh(:,[1 3 ]));
ax= [ax subplot(3,1,2)]; 
    area(seqi.t, kpp2.cb_switches);
ax= [ax subplot(3,1,2)]; 
    area(seqi.t, cumsum(kpp2.cb_switches));
ax= [ax subplot(3,1,3)]; 
    plot(seqi.t, [kpp2.d_cum_per_class]); hold on;
    plot(seqi.t, [kpp2.d_cum_total], 'LineWidth', 2);
    

linkaxes(ax,'x');