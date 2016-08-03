% CREATED BY: REYNALDO SALCEDO
% LAST CHANGE BY : REYNALDO SALCEDO
% GROUP: 73
% DATE MODIFIED  : 04/13/2016
%

function [r] = relay_ANSI_50512759_script(Ts, Iinst, Irms, Vrms, IOC, TOC, VRMSLL)
%#codegen

persistent n50 n51 n27 n59
if isempty(n51)
    n50=0;
    n51=0;
    n59=0;
    n27=0;
end

% additional time delay in seconds
additional_time_delay = 0.05; % 3 cycles
% undervoltage/overvoltage settings at +-15% of nominal voltage
TUV = VRMSLL * 0.85 * sqrt(1/3);
TOV = VRMSLL * 1.15 * sqrt(1/3);
u = [Irms./TOC ; Vrms./TUV ; Vrms./TOV ];

% Trip time calculation
% order of inputs
% u(1:3)->51 , u(4:6)->27 , u(7:9)->59
y = relay_TCC( 1, u , 1); % moderate inverse

y(4:6) = -1 .* y(4:6);
y = (y>0).*y ./ double((y>0));
% finalizing times
t50 = 0.25/60; % 1/4 of a cycle for inst. overcurrent
t51 = min(y(1:3));
t27 = min(y(4:6)) + additional_time_delay;
t59 = min(y(7:9)) + additional_time_delay;

% chck signal thshld
bool_50 = sum(Iinst>IOC)>0;
bool_51 = sum(Irms>TOC)>0;
bool_27 = sum(Vrms<TUV)>0;
bool_59 = sum(Vrms>TOV)>0;
% resetting cnt at signal w/in thshld
n50 = n50 .* bool_50;
n51 = n51 .* bool_51;
n27 = n27 .* bool_27;
n59 = n59 .* bool_59;
% increase cnt by Ts at signal out of thshold
n50 = n50 + bool_50 .* Ts;
n51 = n51 + bool_51 .* Ts;
n27 = n27 + bool_27 .* Ts;
n59 = n59 + bool_59 .* Ts;
% check trip signal
r.trip50 = n50 > t50;
r.trip51 = n51 > t51;
r.trip27 = n27 > t27;
r.trip59 = n59 > t59;
