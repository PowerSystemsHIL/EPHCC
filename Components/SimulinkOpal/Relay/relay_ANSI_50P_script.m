% CREATED BY: REYNALDO SALCEDO
% LAST CHANGE BY : REYNALDO SALCEDO
% GROUP: 73
% DATE MODIFIED  : 05/17/2016
%

function [trip50] = relay_ANSI_50P_script(Ts, Iinst, IOC_pickup, IOC_timeDelay)
%#codegen

% current is expected as seem at teh secondary of the CT

persistent n50
if isempty(n50)
    n50=0;
end

% trip delay + 1/4 of a cycle
t50 = 0.25/60 + IOC_timeDelay;
% assuming tap = 1, this could be adjusted as an input
CT_tap = 1;
% Ipu = pickup * CT_secondary * tap
% multiply by sqrt(2) for peak current
Ipu = IOC_pickup * 5 * CT_tap * sqrt(2);
% check signal threshold
bool_50 = sum(Iinst > Ipu) > 0;
% resetting count at signal within threshold
n50 = n50 .* bool_50;
% increase count by Ts at signal out of threshold
n50 = n50 + bool_50 .* Ts;
% check trip signal
trip50 = n50 > t50;
