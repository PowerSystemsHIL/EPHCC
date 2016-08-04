% Copyright (c) 2016 Massachusetts Institute of Technology
% Permission is hereby granted, free of charge, to any person obtaining a copy of this 
% software and associated documentation files (the "Software"), to deal in the Software
% without restriction, including without limitation the rights to use, copy, modify, 
% merge, publish, distribute, sublicense, and/or sell copies of the Software, and to 
% permit persons to whom the Software is furnished to do so, subject to the following 
% conditions:
% 
% 
% The above copyright notice and this permission notice shall be included in 
% all copies or substantial portions of the Software.
% 
% THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
% INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
% PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
% HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION 
% OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
% SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
%
%
%%


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
