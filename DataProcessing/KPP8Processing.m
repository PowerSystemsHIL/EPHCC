%%% This script processes data for KPP#8, maximum level of PV          %%%
% penetration.
                                                             %
%% Load data
load 'voltage.dat';
%
%% Initialize
delta_t=voltage(11,1)-voltage(10,1);
total_time=delta_t*length(voltage);
Vlimit(1:49)=0;
%% Find maximum voltage deviation interval at each relay
%
for m=1:48                                       % each bus
    column=m+1;
    for n=1:length(voltage)                      % each time
     if (abs(voltage(n,column)-1) < 0.5 && ...
             abs(voltage(n,column)-1) > .05)     %limit exceeded
         Vlimit(column)=Vlimit(column)+delta_t;  %increment limit
     end
    end
end
%% Find max duration
maxDuration=Vlimit(2);
for n=3:length(Vlimit)
    if (Vlimit(n) > maxDuration)
        maxDuration=Vlimit(n);
        maxIndex=n;
    end
end
%% Results
disp('Max voltage deviation in percent is...')
disp(maxDuration/total_time*100);
disp('')
disp('...at CB in column')
disp(maxIndex)

    

    
