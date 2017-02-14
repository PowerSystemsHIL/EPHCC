% Copyright (c) 2015 Massachusetts Institute of Technology
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



function [power, rms_inv_volts, ang_deg] = CalcVandAngforMaxQPower(gridRMS, Vdc, L)
Vgrid_max = gridRMS *sqrt(2);
w=2*pi*60;
x0 = [120 1]; % why is this the best guess?
lb = [-(sqrt(2)/2)*Vdc -2*pi];  % limits on max line to neutral voltage
ub = [(sqrt(2)/2)*Vdc 2*pi];

%% Start with the default options
options = optimset;
%% Modify options setting
options = optimset(options,'Display', 'off');
options = optimset(options,'Algorithm', 'interior-point');
[x,fval,exitflag,output,lambda,grad,hessian] = ...
fmincon(@(x)-QfromVandAng(Vgrid_max,x(1),x(2),w*L),x0,[],[],[],[],lb,ub,@(x)nlQpowerflow(x,w*L,Vgrid_max),options);
power = QfromVandAng(Vgrid_max,x(1),x(2),w*L)/2; % divide by two takes us to average power on a single phase instead of peak
rms_inv_volts = x(1)/sqrt(2);
ang_deg = rad2deg(x(2));
% fprintf('Inverter Voltage %g RMS, Angle %g deg.\n', rms_inv_volts, ang_deg);
% fprintf('Single phase power %g watts and %g amps rms.\n', power, power/gridRMS);
