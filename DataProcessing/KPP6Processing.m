%%% This script processes data for KPP#6, Amount of PV Production      %%%

% This script fnds the amount of PV production (Actual KWh produced      %
% divided by maximum possible KWh based on irradiance.                   %
%
%% Load data files
load misc_3.dat;            % column 8 is irradiance
load solar_kW.dat;          % column 2 is PV power, KW
%% Demand
Irradiance=misc_3(:,8);             %Irradiance in KW (1KW/m^2 times area)
AvailablePVKW=0.15*Irradiance;     %Assume 15% PV efficiency
%
%% TotalMilliseconds, TotalHours, deltaTSecs- Time parameters
time=misc_3(:,1);
TotalMilliseconds=time(length(time))-time(1);
TotalHours=TotalMilliseconds/1000/3600;
deltaTSecs=(time(11)-time(10))/1000;
%
%%  Uncurtailed Maximum KWh from PV
PVMaxKWh=sum(Irradiance)*deltaTSecs/3600;
%
%% Total PV KWh Produced
PVProducedKWh=sum(solar_kW(:,2))*deltaTSecs/3600;
%
%% Amount of PV Production
PercentPVProduction=PVProducedKWh/PVMaxKWh*100;
disp ('Amount of PV Production, Percent');
disp(PercentPVProduction);