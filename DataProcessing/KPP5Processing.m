%%% Script to evaluate quantities for KPP#5 %%%
%
%
%% Initialize  
timeKW_cum=0;
%
%% Load data
load powerreal.dat;
load misc_2.dat;                                        %DMS commands
deltaT=(powerreal(11,1)-powerreal(10,1))/1000;
%
%% Loop through entire file
for n=1:length(powerreal);
    if(misc_2(n,3)==1)                      % if import limit is active...
    power(n)=powerreal(n,44)+powerreal(n,45)+powerreal(n,46);
        if (abs(power(n)-misc_2(n,4))<1e5)  % if grid is giving < 0.1 MW...
            timeKW_cum=timeKW_cum+deltaT;
        else
        end
    end
end
%% Calculate Percent Time Dispatched power is within 100 KW of contract
percentTimeKW=timeKW_cum/deltaT/length(powerreal)*100;
%% Display Result
disp('Percent of time that exported power is within 100 KW of contract...')
disp(percentTimeKW);