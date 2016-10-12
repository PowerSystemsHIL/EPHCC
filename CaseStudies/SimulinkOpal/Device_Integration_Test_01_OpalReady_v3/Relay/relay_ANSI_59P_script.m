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
%%


function [trip59] = relay_ANSI_59P_script(Ts, Vrms, VRMSLN, OV_pickup, UVOV_tripDelay)
%#codegen

% using a very simple model for the voltage protection. future work
% includes the revision of this function

persistent n59
if isempty(n59)
    n59=0;
end

% using 1.1 pu as default in case of inputs under 1.0 pu for overvoltage
if OV_pickup < 1 || OV_pickup==0
    OV_pickup = 1.10;
end

% trip delay + 1/4 of a cycle
t59 = 0.25/60 + UVOV_tripDelay;
% ratio of measurement to nominal voltage
ratio = Vrms ./ VRMSLN;
% check signal threshold
bool_59 = sum(ratio >= OV_pickup) > 0;
% resetting count at signal within threshold
n59 = n59 .* bool_59;
% increase count by Ts at signal out of threshold
n59 = n59 + bool_59 .* Ts;
% check trip signal
trip59 = n59 > t59;
