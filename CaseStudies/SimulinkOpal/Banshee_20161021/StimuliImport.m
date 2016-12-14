% Test inputs for HIL Stimuli
tStop = 1800; % seconds before the data is mirrored back
feederLoads; % bring in load data and plot it

%%
load('irradiance.mat'); % TODO: note this doesn't change too fast and needs to be stronger in the second half
solar = irradiance;
export = 1e3*pulse(0,          60,      120,        tStop) + 4e3*pulse(0,          4*60,      120,        tStop);
% export = [zeros(1,60) linspace(1e3,3e3,4*60) 3e3*ones(1,6.5*60-5*60) zeros(1,tStop-6.5*60)]; % export request
import = 8e3*pulse(0, 13*60, 120, tStop);
power_needed = power_req(solar*0.95*-5 + f1_tot.kw + f2_tot.kw + f3_tot.kw, export, import); % this can be met by shedding load or sending generator commands
% TODO: shift loads or export to get a reasonable power_needed profile
vars = 500*pulse(0, 30, 29.5*60, tStop);
island = pulse(0, 7*60, 6*60, tStop) + pulse(0, 15*60, 13*60, tStop); 

%               startState, faultTime,  duration,   tStop
faults = [pulse(0,          17*60,      120,        tStop); % POI 3 disconnect
          pulse(0,          17*60+132,  120,        tStop); % BUS103
          pulse(0,          17*60+132*2,120,        tStop); % BUS201
          pulse(0,          17*60+132*3,120,        tStop); % BUS208
          pulse(0,          17*60+132*4,120,        tStop); % BUS302
          ];
%faults = mirror(faults);


figure;
s(1) = subplot(4,1,1);
plot(solar);
s(2) = subplot(4,1,2);
plot(export); hold on;
plot(-import); 
plot(vars);
legend('Export Req','Import Lim','Export Vars');
s(3) = subplot(4,1,3);
plot(island);
s(4) = subplot(4,1,4);
plot(faults');
legend('POI3 disconnect', 'BUS103', 'BUS201', 'BUS208', 'BUS302'); 
linkaxes(s,'x');
xlim([0 1800]);

title(s(1), 'Solar Irradiance (W/m^3)');
title(s(2), 'Power Export/Import');
title(s(3), 'POI Disconnected');
title(s(4), 'Fault Occurances');

figure; plot(power_needed); title('kW power from gen or load shed');
