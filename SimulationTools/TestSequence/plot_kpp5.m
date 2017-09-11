figure; % Voltage

ax = [];
ax= [ax subplot(3,1,1)]; plot(comm.t_min, res.voltage(:,kpp5.iPQ)); 
title('Bus voltages [PU]');                         
ax= [ax subplot(3,1,2)]; area(comm.t_min, kpp5.outage_event_cnt);
title('Count of bus voltage outages');
%ax= [ax subplot(3,1,3)]; plot(comm.t_min, kpp5.qVolt_outage); 
ax= [ax subplot(3,1,3)]; area(comm.t_min, kpp5.d_cum_per_class);
hold on;
plot(comm.t_min, ones(1,comm.M)*(-prices.KPP5_CAP), 'r--');
plot(comm.t_min, kpp5.d_cum_total, 'r', 'LineWidth', 2);
title('KPP5 summary values [$]');
legend(kpp5.legend_per_class, 'location', 'SouthWest');
linkaxes(ax,'x');

%% Frequency
figure; 
ax = [];
ax= [ax subplot(3,1,1)]; plot(comm.t_min, res.frequency(:,kpp5.iPQ)); 
title('Bus frequencies [Hz]');                         
ax= [ax subplot(3,1,2)]; plot(comm.t_min, cumsum(kpp5.qHz_outage,2)); 
title('Frequency violations integrators [1/sek/Hz]');
ax= [ax subplot(3,1,3)]; area(comm.t_min, kpp5.d_cum_per_class);
hold on;
plot(comm.t_min, ones(1,comm.M)*(-prices.KPP5_CAP), 'r--');
plot(comm.t_min, kpp5.d_cum_total, 'r', 'LineWidth', 2);
title('KPP5 summary values [$]');
legend(kpp5.legend_per_class, 'location', 'SouthWest');
linkaxes(ax,'x');