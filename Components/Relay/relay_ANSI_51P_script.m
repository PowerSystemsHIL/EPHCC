% CREATED BY: REYNALDO SALCEDO
% LAST CHANGE BY : REYNALDO SALCEDO
% GROUP: 73
% DATE MODIFIED  : 05/17/2016
%

function [trip51] = relay_ANSI_51P_script(Ts, Irms, TOC_pickup, curveType, timeDial)
%#codegen

% current is expected as seem at teh secondary of the CT

persistent n51
if isempty(n51)
    n51=0;
end

% assuming tap = 1, this could be adjusted as an input
CT_tap = 1;
% Ipu = pickup * CT_secondary * tap
Ipu = TOC_pickup * 5 * CT_tap;
% Trip time calculation
M = Irms./Ipu; % multiples of pickup
y = relay_TCC( timeDial, M , curveType);
% selecting the smallest trip time
t51 = min(y(1:3));
% reset the timer if the Irms is less than the pickup current
if t51 < 0
    t51 = 0;
end

% check signal threshold
bool_51 = sum(Irms > Ipu) > 0;
% resetting count at signal within threshold
n51 = n51 .* bool_51;
% increase count by Ts at signal out of threshold
n51 = n51 + bool_51 .* Ts;
% check trip signal
trip51 = n51 > t51;
