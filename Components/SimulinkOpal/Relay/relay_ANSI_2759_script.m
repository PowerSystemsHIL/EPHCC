% CREATED BY: REYNALDO SALCEDO
% LAST CHANGE BY : REYNALDO SALCEDO
% GROUP: 73
% DATE MODIFIED  : 05/17/2016
%

function [r] = relay_ANSI_2759_script(Ts, Vrms, VRMSLL)
%#codegen

persistent n27 n59
if isempty(n59)
    n59=0;
    n27=0;
end

% additional time delay in seconds
% 0.0625: minimum time required by the TCC at u=0
additional_time_delay = 0.05 + 0.0625; % 3 cycles + 0.0625

% undervoltage/overvoltage settings at +-15% of nominal voltage
TUV = VRMSLL * 0.85 * sqrt(1/3);
TOV = VRMSLL * 1.15 * sqrt(1/3);
u = [Vrms./TUV ; Vrms./TOV ];

% Trip time calculation
% order of inputs
% u(1:3)->27 , u(4:6)->59
y = 0.1140 + (0.0515 ./ (u.^0.020 - 1)); % moderate inverse

y(1:3) = -1 .* y(1:3);
y = (y>0).*y ./ double((y>0));
% final time delays
t27 = min(y(1:3)) + additional_time_delay;
t59 = min(y(4:6)) + additional_time_delay;
% chck signal thshld
bool_27 = sum(Vrms < TUV) > 0;
bool_59 = sum(Vrms > TOV) > 0;
% resetting cnt at signal w/in thshld
n27 = n27 .* bool_27;
n59 = n59 .* bool_59;
% increase cnt by Ts at signal out of thshold
n27 = n27 + bool_27 .* Ts;
n59 = n59 + bool_59 .* Ts;
% check trip signal
r.trip27 = n27 > t27;
r.trip59 = n59 > t59;
