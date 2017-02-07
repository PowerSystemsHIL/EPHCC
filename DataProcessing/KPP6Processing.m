%%% This script processes data for KPP#6, Amount of PV Production      %%%

% This script fnds the amount of PV production (Actual KWh produced      %
% divided by maximum possible KWh based on irradiance.                   %

%
%% Demand
%Irradiance=misc?(:,?);             %Irradiance in KW (1KW/m^2 times area)
%AvailablePVKW=0.15*Irradiance;     %Assume 15% PV efficiency
%
%% TotalMilliseconds, TotalHours, deltaTSecs- Time parameters
%time=misc?(:,1);
TotalMilliseconds=time(length(time))-time(1);
TotalHours=TotalMilliseconds/1000/3600;
deltaTSecs=(time(11)-time(10))/1000;
%
%%  Uncurtailed Maximum KWh from PV
PVMaxKWh=sum(Irradiance)*deltaTSecs/3600;
%
%% Total PV KWh Produced
%PVProducedKWh=sum(misc?(:,?))*deltaTSecs/3600;
%
%% Amount of PV Production
PercentPVProduction=PvProducedKWh/PVMaxKWh;
disp ('Amount of PV Production, Percent');
disp(PercentPVProduction);