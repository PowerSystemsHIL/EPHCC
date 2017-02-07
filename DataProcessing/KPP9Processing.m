%%%  Script to generate KPP#9 emissions plots  %%%
%%%  See ICD, same metric as KPP#2             %%%
%%
load powerreal.dat;
time=powerreal(:,1);
DieselKW=abs(powerreal(:,48));
DieselCO2lbmcum=cumsum(DieselKW)/1000*1425*(time(11)-time(10))/1000/3600;
UtilityKW=powerreal(:,44)+powerreal(:,45)+powerreal(:,46);
UtilityCO2lbmcum=cumsum(UtilityKW)/1000*457*(time(11)-time(10))/1000/3600;
clear powerreal*;
%%
load ngchpGenerator_ChpC02.dat;
CHPCO2lbmperhour= ngchpGenerator_ChpC02(:,2);
CHPCO2lbmcum=cumsum(CHPCO2lbmperhour)*(time(11)-time(10))/1000/3600;
clear ngch*;
%%
load ngchpGenerator_boilerLbm.dat;
BoilerCO2lbmperhour=ngchpGenerator_boilerLbm(:,2);
BoilerCO2lbmcum=cumsum(BoilerCO2lbmperhour)*(time(11)-time(10))/1000/3600;
clear ngch*;
%%
load ngchpGenerator_CHPHeatContribution.dat;
CHPHeatContribution=ngchpGenerator_CHPHeatContribution(:,2);  %MBtu per hr
%%
load breaker.dat;
for n=1:length(time)
    if (breaker(n,44) | breaker(n,45) | breaker(n,46))==0;   % islanded
        islanded(n)=1; 
    else islanded(n)=0;
    end
end
%
%%
clf;
time=linspace(0,.2*length(time),length(time))/3600;
subplot(311);
plot(time,BoilerCO2lbmcum);
hold on;
plot(time,CHPCO2lbmcum,'r');
plot(time,DieselCO2lbmcum,'g');
plot(time,UtilityCO2lbmcum,'c');
ylabel('lbm');
title('GHG Emission (CO2)');
legend ('Boiler', 'CHP', 'Diesel', 'PG&E')
subplot(312);
plot(time,CHPHeatContribution)
ylabel('MBtu/hr');
title ('Heat Contributed by CHP');
legend ('CHP heat, MBtu/hr')
subplot(313)
plot(time, islanded);
legend ('Islanded (1) or Grid-tied (0)')
xlabel('Hours');
ylabel ('Grid-tied status')
title('Islanded or Grid-Tied')
axis([0 max(time) 0 2]);

%%
clear 

