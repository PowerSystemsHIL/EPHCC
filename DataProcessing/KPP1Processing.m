%%% This script processes data for KPP#6, Amount of PV Production      %%%

% This script fnds outage percentages (KW and sec) for C, P, I loads on  %
% feeders F1F2 and F3 as well as total demands and aggregate outage      %
% summaries                                                              %
%
%
%% Demands
I1Demand=300;
I2Demand=250;
I3Demand=300;
I4Demand=600;
I5Demand=400;
I6Demand=600;
P1Demand=1000;
P2Demand=1000;
P3Demand=1000;
P4Demand=600;
P5Demand=700;
P6Demand=1000;
C1Demand=1200;
C2Demand=1500;
C3Demand=1000;
C4Demand=1000;
C5Demand=1000;
C6Demand=800;
%
%% TotalDemaand
F1TotalDemand=I1Demand+I2Demand+P1Demand+C1Demand+C2Demand;
F2TotalDemand=I3Demand+I4Demand+I5Demand+P2Demand+P3Demand+C3Demand+...
    C4Demand;
F3TotalDemand=I6Demand+P4Demand+C5Demand+C6Demand;
%
%% TotalMilliseconds, TotalHours, deltaTSecs- Time parameters
TotalMilliseconds=time(length(time))-time(1);
TotalHours=TotalMilliseconds/1000/3600;
deltaTSecs=(time(11)-time(10))/1000;
%
%% Aggregate load served (%) and outage duration (secs) for each load
loads=[I1' I2' I3' I4' I5' I6' P1' P2' P3' P4' P5' P6' C1' C2' C3' C4'...
    C5' C6'];
I1Served=sum(I1)*deltaTSecs/3600;               %KWh served
I1TimeServed=I1Served/(I1Demand*TotalHours);    %Percent of time served
I2Served=sum(I2)*deltaTSecs/3600;
I2TimeServed=I2Served/(I2Demand*TotalHours);
I3Served=sum(I3)*deltaTSecs/3600;
I3TimeServed=I3Served/(I3Demand*TotalHours);
I4Served=sum(I4)*deltaTSecs/3600;
I4TimeServed=I4Served/(I4Demand*TotalHours);
I5Served=sum(I5)*deltaTSecs/3600;
I5TimeServed=I5Served/(I5Demand*TotalHours);
I6Served=sum(I6)*deltaTSecs/3600;
I6TimeServed=I6Served/(I6Demand*TotalHours);
P1Served=sum(P1)*deltaTSecs/3600;
P1TimeServed=P1Served/(P1Demand*TotalHours);
P2Served=sum(P2)*deltaTSecs/3600;
P2TimeServed=P2Served/(P2Demand*TotalHours);
P3Served=sum(P3)*deltaTSecs/3600;
P3TimeServed=P3Served/(P3Demand*TotalHours);
P4Served=sum(P4)*deltaTSecs/3600;
P4TimeServed=P4Served/(P4Demand*TotalHours);
P5Served=sum(P5)*deltaTSecs/3600;
P5TimeServed=P5Served/(P5Demand*TotalHours);
P6Served=sum(P6)*deltaTSecs/3600;
P6TimeServed=P6Served/(P6Demand*TotalHours);
C1Served=sum(C1)*deltaTSecs/3600;
C1TimeServed=C1Served/(C1Demand*TotalHours);
C2Served=sum(C2)*deltaTSecs/3600;
C2TimeServed=C2Served/(C2Demand*TotalHours);
C3Served=sum(C3)*deltaTSecs/3600;
C3TimeServed=C3Served/(C3Demand*TotalHours);
C4Served=sum(C4)*deltaTSecs/3600;
C4TimeServed=C4Served/(C4Demand*TotalHours);
C5Served=sum(C5)*deltaTSecs/3600;
C5TimeServed=C5Served/(C5Demand*TotalHours);
C6Served=sum(C6)*deltaTSecs/3600;
C6TimeServed=C6Served/(C6Demand*TotalHours);
%
% Quantities for summary chart (See notebook p. 438 for item #'s)
%% 1.)
F1TotalEnergyDemand=F1TotalDemand*TotalHours;
F2TotalEnergyDemand=F2TotalDemand*TotalHours;
F3TotalEnergyDemand=F3TotalDemand*TotalHours;
%2.)
F1CLoadOutage=(C1Served+C2Served)/((C1Demand+C2Demand)*...
    TotalHours);                              % % F1 Critical Load Served
F1CTimeOutage=(C1TimeServed+C2TimeServed)/2;  % % F1 Critical Time Served
F2CLoadOutage=(C3Served+C4Served)/((C3Demand+C4Demand)*...
    TotalHours);                              % % F2 Critical Load Served
F2CTimeOutage=(C3TimeServed+C4TimeServed)/2;  % % F2 Critical Time Served
F3CloadOutage=(C5Served+C6Served)/((C5Demand+C6Demand)*...
    TotalHours);                              % % F3 Critical Load Served
F3CTimeOutage=(C5TimeServed+C6TimeServed)/2;  % % F3 Critical Time Served
%% 3.)
F1PLoadOutage=(P1Served)/((P1Demand)*...
    TotalHours);                              % % F1 Priority Load Served
F1PTimeOutage=(P1TimeServed);                 % % F1 Priority Time Served
F2PLoadOutage=(P2Served+P3Served)/((P2Demand+P3Demand)*...
    TotalHours);                              % % F2 Priority Load Served
F2PTimeOutage=(P2TimeServed+P3TimeServed)/2;  % % F2 Priority Time Served
F3PloadOutage=(P6Served)/((P6Demand)*...
    TotalHours);                              % % F3 Priority Load Served
F3PTimeOutage=(P6TimeServed);                 % % F3 Priority Time Served
%% 4.)
F1ILoadOutage=(I1Served+I2Served)/((I1Demand+I2Demand)*...
    TotalHours);                              % % F1 Interrupt Load Served
F1ITimeOutage=(I1TimeServed+I2TimeServed)/2;  % % F1 Interrupt Time Served
F2ILoadOutage=(I3Served+I4Served+I5Served)/((I3Demand+I4Demand+I5Demand)*...
    TotalHours);                              % % F2 Interrupt Load Served
F2ITimeOutage=(I3TimeServed+I4TimeServed+I5TimeServed)/3;
                                              % % F2 Interrupt Time Served
F3IloadOutage=(I6Served)/((I6Demand)*...
    TotalHours);                              % % F3 Interrupt Load Served
F3PTimeOutage=(I6TimeServed);                 % % F3 Interrupt Time Served
%% 5.)
TotalCriticalLoadOutage=(C1Served+C2Served+C3Served+C4Served...
    +C5Served+C6Served)/((C1Demand+C2Demand+C3Demand+C4Demand+...
    C5Demand+C6Demand)*TotalHours);
TotalCriticalTimeOutage=(C1TimeServed+C2TimeServed+C3TimeServed+...
    C4TimeServed+C5TimeServed+C6TimeServed)/6;
%% 6.)
TotalPriorityLoadOutage=(P1Served+P2Served+P3Served+P4Served...
    +P5Served+P6Served)/((P1Demand+P2Demand+P3Demand+P4Demand+...
    P5Demand+P6Demand)*TotalHours);
TotalPriorityTimeOutage=(P1TimeServed+P2TimeServed+P3TimeServed+...
    P4TimeServed+P5TimeServed+P6TimeServed)/6;
%% 7.)
TotalInterruptLoadOutage=(I1Served+I2Served+I3Served+I4Served...
    +I5Served+I6Served)/((I1Demand+I2Demand+I3Demand+I4Demand+...
    I5Demand+I6Demand)*TotalHours);
TotalInterruptTimeOutage=(I1TimeServed+I2TimeServed+I3TimeServed+...
    I4TimeServed+I5TimeServed+I6TimeServed)/6;
%% 8.)
TotalF1LoadOutage=(C1Served+C2Served+P1Served+I1Served+I2Served)/(...
    (C1Demand+C2Demand+P1Demand+I1Demand+I2Demand)*TotalHours);
TotalF1TimeOutage=(C1TimeServed+C2TimeServed+P1TimeServed+I1TimeServed+...
    I2TimeServed)/5;
TotalF2LoadOutage=(C3Served+C4Served+P2Served+P3Served+I3Served+I4Served...
    +I5Served)/((C3Demand+C4Demand+P2Demand+P3Demand+I3Demand+I4Demand...
    +I5Demand)*TotalHours);
TotalF2TimeOutage=(C3TimeServed+C4TimeServed+P2TimeServed+P3TimeServed...
    +I3TimeServed+I4TimeServed+I5TimeServed)/7;
TotalF3LoadOutage=(C5Served+C6Served+P6Served+I6Served)/((C5Demand+...
    C6Demand+P6Demand+I6Demand)*TotalHours);
TotalF3TimeOutage=(C5TimeServed+C6TimeServed+P6TimeServed+I6TimeServed)/4;
%% 9.)
TotalLoadOutage=(C1Served+C2Served+P1Served+I1Served+I2Served+...
    C3Served+C4Served+P2Served+P3Served+I3Served+I4Served+I5Served...
    +C5Served+C6Served+P6Served+I6Served)/((C1Demand+C2Demand+P1Demand+...
    I1Demand+I2Demand+C3Demand+C4Demand+P2Demand+P3Demand+I3Demand+...
    I4Demand+I5Demand+C5Demand+C6Demand+P6Demand+I6Demand)*TotalHours);
TotalTimeOutage=(C1TimeServed+C2TimeServed+P1TimeServed+I1TimeServed+...
    I2TimeServed+C3TimeServed+C4TimeServed+P2TimeServed+P3TimeServed+...
    I3TimeServed+I4TimeServed+I5TimeServed+C5TimeServed+C6TimeServed+...
    P6TimeServed+I6TimeServed)/16;
%% 10.)
disp('Percent Critical KWh Outage = '); disp( 100*(1-TotalCriticalLoadOutage));
disp('Percent Priority KWh Outage = '); disp( 100*(1-TotalPriorityLoadOutage));
disp('Percent Interruptible KWh Outage = '); disp( 100*(1-TotalInterruptLoadOutage));
%
disp('Percent Critical Time Outage = '); disp( 100*(1-TotalCriticalTimeOutage));
disp('Percent Priority Time Outage = '); disp( 100*(1-TotalPriorityTimeOutage));
disp('Percent Interruptible Time Outage = '); disp( 100*(1-TotalInterruptTimeOutage));