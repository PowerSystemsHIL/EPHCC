%%% Script to evaluate quantities for KPP#3 %%%
%
%
%% Initialize 
Boiler_NMcum=0; 
NG_NMcum=0;
Diesel_GALcum=0;
time_cum=0;
%
%% Load data
load ngchpGenerator_boilerNM.dat;
load ngchpGenerator_fuelUsage.dat;
load powerreal.dat;
load breaker.dat;
deltaT=(ngchpGenerator_boilerNM(11,1)-ngchpGenerator_boilerNM(10,1))/1000;
%
%% Loop through entire file
for n=1:length(ngchpGenerator_boilerNM)
    if (breaker(n,44) | breaker(n,45) | breaker(n,46))==0   % islanded
        Boiler_NMcum=Boiler_NMcum+ngchpGenerator_boilerNM(n,2);
        NG_NMcum=NG_NMcum+ngchpGenerator_fuelUsage(n,2);
        Diesel_GALcum=Diesel_GALcum+abs(powerreal(n,48));   %KW from diesel
        time_cum=time_cum+deltaT;
    else 
    end
end
%
%% Usage per minute calculation during outage: 
%  Note:  Diesel gives 15.5 KWh per gallon
NG_UsagePerMin=NG_NMcum*(deltaT/3600)/(time_cum/60);          %average Nm^3/min
Boiler_UsagePerMin=Boiler_NMcum*(deltaT/3600)/(time_cum/60);  %average Nm^3/min
Diesel_UsagePerMin=Diesel_GALcum*(deltaT/3600)/(time_cum/60)/15.5;...
                                                              %average gal/min
%% Display
disp('Diesel gpm = '); disp(Diesel_UsagePerMin)
disp('CHP NG usage Nm^3 per min = '); disp(NG_UsagePerMin)
disp('Boiler NG usage Nm^3 per min = '); disp(Boiler_UsagePerMin)