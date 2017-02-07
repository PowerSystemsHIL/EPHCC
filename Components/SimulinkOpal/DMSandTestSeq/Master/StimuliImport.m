% Test inputs for HIL Stimuli
tStop = 1800; % seconds before the data is mirrored back
%feederLoads; % bring in load data and plot it

%%
load('irradiance.mat'); % TODO: note this doesn't change too fast and needs to be stronger in the second half
solar = irradiance;
export = 1e3*pulse(0,          5.5*60,      1.5*60,        tStop) + 4e3*pulse(0,          7.5*60,      1.5*60,        tStop);
% export = [zeros(1,60) linspace(1e3,3e3,4*60) 3e3*ones(1,6.5*60-5*60) zeros(1,tStop-6.5*60)]; % export request
import = 8e3*pulse(0, 17.5*60, 1*60, tStop);
% TODO: shift loads or export to get a reasonable power_needed profile
PFReq = 1-0.5*pulse(0, 6.5*60, 2.5*60, tStop);
island = pulse(0, 9*60, 8*60, tStop); % DMS request
autosynch= pulse(0, 5*60, 4*60, tStop)+ pulse(0, 17*60, 3*60, tStop); % DMS request
microgridcontrollerstart= pulse(0, 3*60, 27*60, tStop); % DMS request
blackstart= pulse(0, 3*60, 27*60, tStop); % DMS request

%               startState, faultTime,  duration,   tStop
faults = [pulse(0,          20*60+132,  2,        tStop); % BUS204
          zeros(1,tStop); %pulse(0,          20*60+132*2,2*60,        tStop); % BUS103
          pulse(0,          14*60,      2,        tStop); % BUS106
          zeros(1,tStop); %pulse(0,          25*60,      120,        tStop); % BUS301
          pulse(0,          26*60,      2,        tStop); % BUS208
          pulse(0,          20*60,      8.5*60,      tStop) + pulse(0, 2*60, 3*60, tStop); % cut grid power
          pulse(0,          10*60,      1*60,      tStop) + pulse(0, 18*60, 1*60, tStop); % motor1
          pulse(0,          12*60,      1*60,      tStop) + pulse(0, 4*60, 1.5*60, tStop); % motor2
          ];
%power_needed = power_req(solar*0.95*-5 + f1_tot.kw + f2_tot.kw + f3_tot.kw, export, import,island | faults(6,:)); % this can be met by shedding load or sending generator commands
%faults = mirror(faults);

timeMin = linspace(0,tStop/60,tStop);

%% Plotting only seems to work in 2016
if plotEnabled
    figure;
    s(1) = subplot(4,1,1);
    plot(timeMin, solar, 'LineWidth',2);
    ylabel('W/m^3');
    s(2) = subplot(4,1,2);
    plot(timeMin, export, 'LineWidth',2); hold on;
    plot(timeMin, import, 'LineWidth',2); 
    ylabel('kW');
    yyaxis right; plot(timeMin, PFReq, 'LineWidth',2);
    ylim([-1.2 1.2])
    ylabel('PF');
    legend('Export Req','Import Lim','PF Request');
    s(3) = subplot(4,1,3);
    plot(timeMin, island, 'LineWidth',2); hold on;
    plot(timeMin, autosynch*0.9, 'LineWidth',2);
    plot(timeMin, microgridcontrollerstart*0.93, 'LineWidth',2);
    plot(timeMin, blackstart*0.97, 'LineWidth',2);
    s(3).YTickLabel = {'False', '', '', '', '', 'True'};
    legend('POI Disconnect Request', 'Request to Sync with POI', 'MGC Start', 'BS Enabled');
    s(4) = subplot(4,1,4);
    p = plot(timeMin, faults','LineWidth',2);
    s(4).YTickLabel = {'False', '', '', '', '', 'True'};
    set(p(7),'LineStyle','--');
    set(p(8),'LineStyle','--');
    legend('BUS204 Fault', 'BUS103 Fault', 'BUS106 Fault', 'BUS301 Fault', 'BUS208 Fault', 'Cut Grid Power','motor1','motor2'); 
    linkaxes(s,'x');
    for i = 1:4
        s(i).XTick = 1:30;
        grid(s(i),'minor')
    end

    %xlim([0 1800]);

    title(s(1), 'Solar Irradiance');
    title(s(2), 'Power Export/Import');
    title(s(3), 'Control Signals');
    title(s(4), 'Stimuli Occurances');

    figure; plot(timeMin, power_needed); title('kW power from gen or load shed');
    hold on
    line([0 30],[10.5e3 10.5e3],'Color','r','LineStyle','--')
end
