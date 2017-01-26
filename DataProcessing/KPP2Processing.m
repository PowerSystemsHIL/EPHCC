%%%  Script to generate KPP#2 emissions plots  %%%
%
load powerreal.dat;
time=powerreal(:,1);
DieselKW=abs(powerreal(:,48));
DieselCO2lbmcum=cumsum(DieselKW)*1425*(time(11)-time(10))/1e6/3600;
clear powerreal*;
%
load ngchpGenerator_ChpC02.dat;
CHPCO2lbmperhour= ngchpGenerator_ChpC02(:,2);
CHPCO2lbmcum=cumsum(CHPCO2lbmperhour)*(time(11)-time(10))/1000/3600;
clear ngch*;
%
load ngchpGenerator_boilerLbm.dat;
BoilerCO2lbmperhour=ngchpGenerator_boilerLbm(:,2);
BoilerCO2lbmcum=cumsum(BoilerCO2lbmperhour)*(time(11)-time(10))/1000/3600;
clear ngch*;
%
clf;
time=linspace(0,.2*length(time),length(time))/3600;
plot(time,BoilerCO2lbmcum);
hold on;
plot(time,CHPCO2lbmcum,'r');
plot(time,DieselCO2lbmcum,'g');
xlabel('Hours');
ylabel('lbm');
title('GHG Emission (CO2)');
legend ('Boiler', 'CHP', 'Diesel')
%
clear

