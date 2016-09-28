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
