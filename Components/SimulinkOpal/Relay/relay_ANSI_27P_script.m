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


function [trip27] = relay_ANSI_27P_script(Ts, Vrms, VRMSLN, UV_pickup, UVOV_tripDelay)
%#codegen

% using a very simple model for the voltage protection. future work
% includes the revision of this function

persistent n27
if isempty(n27)
    n27=0;
end

% using 0.9 pu as default in case of inputs over 1.0 pu for undervoltage
if UV_pickup > 1 || UV_pickup==0
    UV_pickup = 0.90;
end

% trip delay + 1/4 of a cycle
t27 = 0.25/60 + UVOV_tripDelay;
% ratio of measurement to nominal voltage
ratio = Vrms ./ VRMSLN;
% check signal threshold
bool_27 = sum(ratio <= UV_pickup) > 0;
% resetting count at signal within threshold
n27 = n27 .* bool_27;
% increase count by Ts at signal out of threshold
n27 = n27 + bool_27 .* Ts;
% check trip signal 
trip27 = (n27 > t27);
