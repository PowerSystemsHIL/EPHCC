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


function [trip50] = relay_ANSI_50P_script(Ts, Iinst, IOC_pickup, IOC_timeDelay)
%#codegen

% current is expected as seem at the secondary of the CT

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
