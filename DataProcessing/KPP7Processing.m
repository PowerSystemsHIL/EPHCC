%%% This script processes data for KPP#7, O&M Costs                    %%%
%%% DUE TO THE LIMITED DURATION OF THE HIL SIMULATION, THESE RESULTS   %%%
%%% HAVE LIMITED ACCURACY.                                             %%%
%
%% Diesel Emissions
load powerreal.dat;
load battery_kW.dat;
time=powerreal(:,1);
DieselKW=abs(powerreal(:,48));
DieselCO2lbmcum=sum(DieselKW)/1000*1425*(time(11)-time(10))/1000/3600;
%
%% TotalMilliseconds, TotalHours, deltaTSecs- Time parameters
time=powerreal(:,1);
TotalMilliseconds=time(length(time))-time(1);
TotalHours=TotalMilliseconds/1000/3600;
deltaTSecs=(time(11)-time(10))/1000;
clear powerreal*;
%
%% CHP Emissions
load ngchpGenerator_ChpC02.dat;
CHPCO2lbmperhour= ngchpGenerator_ChpC02(:,2);
CHPCO2lbmcum=sum(CHPCO2lbmperhour)*(time(11)-time(10))/1000/3600;
clear ngch*;
%% Battery Cycles
BattNamePlate=1000;                             %1000 KWh
BattCycles=sum(abs(battery_kW(:,2)))*deltaTSecs/3600/BattNamePlate/2;
%% Display Results
disp ('Total Emissions in lbs CO2 for DERs is...')
disp(CHPCO2lbmcum+DieselCO2lbmcum);
disp('');
disp('Battery cycles is...')
disp(BattCycles)


