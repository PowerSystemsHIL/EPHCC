%%% Script to evaluate quantities for KPP#4 %%%
%
%
%% Initialize 
timePf_cum=0; 
timeKW_cum=0;
PFreqTotalTime=0;
ExportreqTotalTime=0;
%
%% Load data
load powerreal.dat;
load reactivepower.dat;
load misc_2.dat;
deltaT=(powerreal(11,1)-powerreal(10,1))/1000;
%
%% Loop through entire file
for n=1:length(powerreal);
    power(n)=powerreal(n,44)+powerreal(n,45)+powerreal(n,46);
    vars(n)=reactivepower(n,44)+reactivepower(n,45)+reactivepower(n,46);
    pf(n)=sign(vars(n))*abs(cos(power(n)/sqrt(power(n)^2+vars(n)^2)));
    if (misc_2(n,5)==1)                   % PF contract active?
        PFreqTotalTime=PFreqTotalTime+deltaT;
        if (pf(n)>misc_2(n,6)-.05 && pf(n)<misc_2(n,6)+.05) % PF in bounds?
            timePf_cum=timePf_cum+deltaT;
        end
    if (misc_2(n,7)==1)                    % KW export limit active?
        ExportreqTotalTime=ExportreqTotalTime+deltaT;
        if (power(n)>misc_2(n,8)-1e5 && power(n)<misc_2(n,8)+1e5) %in
            timeKW_cum=timeKW_cum+deltaT;                         %bounds?
        end
    end
    end
end
%% Calculate Percent Time 
percentTimeKW=timeKW_cum/ExportreqTotalTime*100;  % pct of time in bounds
percentTimePf=timePf_cum/PFreqTotalTime*100;  % pct of time in bounds
%
%% Display R esults
disp('Percent of time that exported power exceeds 100 KW of contract...')
disp(100-percentTimeKW);
disp('')
disp('Percent of time that PF exceeds .05 of contract...')
disp(100-percentTimePf);
