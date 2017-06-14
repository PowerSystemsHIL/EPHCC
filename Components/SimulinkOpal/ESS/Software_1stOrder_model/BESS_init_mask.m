%% Required input parameters
%CFG.Sn = 250e3;   %[VA]
%CFG.fn = 60;    %[Hz]
%CFG.Vn = 480;        %[V]
%CFG.r_I_max; - ratio of Imax/In
function [BP] = BESS_init_mask(CFG)

%% Nominal current ratings
BP.In = CFG.Sn/(CFG.Vn/sqrt(3))/3;
BP.Imax = BP.In*CFG.r_I_max;


%% Current source inverter - voltage source based
% Inverter filter parameters
BP.R_base = CFG.Vn^2/CFG.Sn;        %[ohm]
BP.L_base = BP.R_base/2/pi/CFG.fn;     

BP.R_PU = 5.4e-3;     %[PU]
BP.L_PU = 10.2e-2;     %[PU]

%series indctor resistatnce and impedance
BP.R = BP.R_PU*BP.R_base;     %[ohm];
BP.L = BP.L_PU*BP.L_base;     %[H];

%disp([ 'R: ' num2str(BP.R) '/' num2str(BP.R_base)]);
%disp([ 'L: ' num2str(BP.L) '/' num2str(BP.L_base)]);

BP.I_slewrate = 1;

%% Droop lowpass filter
BP.filt = firstOrderDig(50e-3, CFG.Tc, 'low');


