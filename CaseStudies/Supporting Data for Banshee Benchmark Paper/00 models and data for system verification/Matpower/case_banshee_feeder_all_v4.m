function mpc = case_banshee_feeder_all_v4
% Ideal Power flow data for all 3 banshee feeders
% 1. Coupling snubbers are removed (both series and shunts)
% 2. Intertie lines are open (disconnected)
% 4. Measurement snubbers are ignored
% 5. Rotating machines (induction motors and synchronous generators) are turned off and disconnected
% 6. Inverters are turned off and disconnected
% 7. Positive sequence impedances of the lines are used (equal mutuals)
% 8. Loads are represented as admittances (because passive)
% 9. Transformer shunt admittances (Rm,Lm) are considered

%
%   MATPOWER
%   $Id: case4gs.m 1559 2010-03-10 18:08:32Z ray $

%% MATPOWER Case Format : Version 2
mpc.version = '2';

%%-----  Power Flow Data  -----%%
%% system MVA base
Sbase = 20e6;
wbase = 60.0*2.0*pi;
Vbase_HV = 13.8e3;
Vbase_MV = 4160;
Vbase_LV1 = 480;
Vbase_LV2 = 208;

Vbase_kHV = Vbase_HV/1000;
Vbase_kMV = Vbase_MV/1000;
Vbase_kLV1 = Vbase_LV1/1000;
Vbase_kLV2 = Vbase_LV2/1000;

Ibase_HV = Sbase/(sqrt(3)*Vbase_HV);
Ibase_MV = Sbase/(sqrt(3)*Vbase_MV);
Ibase_LV1 = Sbase/(sqrt(3)*Vbase_LV1);
Ibase_LV2 = Sbase/(sqrt(3)*Vbase_LV2);

Zbase_HV = Vbase_HV^2/Sbase;
Zbase_MV = Vbase_MV^2/Sbase;
Zbase_LV1 = Vbase_LV1^2/Sbase;
Zbase_LV2 = Vbase_LV2^2/Sbase;


mpc.baseMVA = Sbase/1e6;



%% transformer shunt admittances (magnetizing branches)

%feeder 1
%=========
s_tx_f1_1 = 480^2/conj((1/1e5 + 1/(1i*200*wbase))^-1 * (480/13800)^2);
Gs_tx_f1_1 = real(s_tx_f1_1)*1e-6;
Bs_tx_f1_1 = -imag(s_tx_f1_1)*1e-6;

s_tx_f1_2 = 480^2/conj((1/1e5 + 1/(1i*200*wbase))^-1 * (480/13800)^2);
Gs_tx_f1_2 = real(s_tx_f1_2)*1e-6;
Bs_tx_f1_2 = -imag(s_tx_f1_2)*1e-6;

s_tx_f1_3 = 4160^2/conj((1/1e5 + 1/(1i*200*wbase))^-1 * (4160/13800)^2);
Gs_tx_f1_3 = real(s_tx_f1_3)*1e-6;
Bs_tx_f1_3 = -imag(s_tx_f1_3)*1e-6;

s_tx_f1_4 = 208^2/conj((1/1e5 + 1/(1i*200*wbase))^-1 * (208/13800)^2);
Gs_tx_f1_4 = real(s_tx_f1_4)*1e-6;
Bs_tx_f1_4 = -imag(s_tx_f1_4)*1e-6;

s_tx_f1_5 = 480^2/conj((1/1e5 + 1/(1i*200*wbase))^-1 * (480/4160)^2);
Gs_tx_f1_5 = real(s_tx_f1_5)*1e-6;
Bs_tx_f1_5 = -imag(s_tx_f1_5)*1e-6;

s_tx_f1_6 = 480^2/conj((1/1e5 + 1/(1i*200*wbase))^-1 * (4160/13800)^2);
Gs_tx_f1_6 = real(s_tx_f1_6)*1e-6;
Bs_tx_f1_6 = -imag(s_tx_f1_6)*1e-6;

s_tx_f1_7 = 480^2/conj((1/1e5 + 1/(1i*200*wbase))^-1 * (480/13800)^2);
Gs_tx_f1_7 = real(s_tx_f1_7)*1e-6;
Bs_tx_f1_7 = -imag(s_tx_f1_7)*1e-6;

%feeder 2
%=========
s_tx_f2_1 = 208^2/conj((1/1e5 + 1/(1i*200*wbase))^-1 * (208/13800)^2);
Gs_tx_f2_1 = real(s_tx_f2_1)*1e-6;
Bs_tx_f2_1 = -imag(s_tx_f2_1)*1e-6;

s_tx_f2_2 = 4160^2/conj((1/1e5 + 1/(1i*200*wbase))^-1 * (4160/13800)^2);
Gs_tx_f2_2 = real(s_tx_f2_2)*1e-6;
Bs_tx_f2_2 = -imag(s_tx_f2_2)*1e-6;

s_tx_f2_3 = 480^2/conj((1/1e5 + 1/(1i*200*wbase))^-1 * (480/4160)^2);
Gs_tx_f2_3 = real(s_tx_f2_3)*1e-6;
Bs_tx_f2_3 = -imag(s_tx_f2_3)*1e-6;

s_tx_f2_4 = 480^2/conj((1/1e5 + 1/(1i*200*wbase))^-1 * (480/4160)^2);
Gs_tx_f2_4 = real(s_tx_f2_4)*1e-6;
Bs_tx_f2_4 = -imag(s_tx_f2_4)*1e-6;

s_tx_f2_6 = 480^2/conj((1/1e5 + 1/(1i*200*wbase))^-1 * (480/13800)^2);
Gs_tx_f2_6 = real(s_tx_f2_6)*1e-6;
Bs_tx_f2_6 = -imag(s_tx_f2_6)*1e-6;

s_tx_f2_7 = 480^2/conj((1/1e5 + 1/(1i*200*wbase))^-1 * (480/13800)^2);
Gs_tx_f2_7 = real(s_tx_f2_7)*1e-6;
Bs_tx_f2_7 = -imag(s_tx_f2_7)*1e-6;

s_tx_f2_8 = 480^2/conj((1/1e5 + 1/(1i*200*wbase))^-1 * (480/13800)^2);
Gs_tx_f2_8 = real(s_tx_f2_8)*1e-6;
Bs_tx_f2_8 = -imag(s_tx_f2_8)*1e-6;

s_tx_f2_9 = 480^2/conj((1/1e5 + 1/(1i*200*wbase))^-1 * (480/13800)^2);
Gs_tx_f2_9 = real(s_tx_f2_9)*1e-6;
Bs_tx_f2_9 = -imag(s_tx_f2_9)*1e-6;

s_tx_f2_10 = 480^2/conj((1/1e5 + 1/(1i*200*wbase))^-1 * (480/13800)^2);
Gs_tx_f2_10 = real(s_tx_f2_10)*1e-6;
Bs_tx_f2_10 = -imag(s_tx_f2_10)*1e-6;

%feeder 3
%=========
s_tx_f3_1 = 480^2/conj((1/1e5 + 1/(1i*200*wbase))^-1 * (480/13800)^2);
Gs_tx_f3_1 = real(s_tx_f3_1)*1e-6;
Bs_tx_f3_1 = -imag(s_tx_f3_1)*1e-6;

s_tx_f3_2 = 480^2/conj((1/1e5 + 1/(1i*200*wbase))^-1 * (480/13800)^2);
Gs_tx_f3_2 = real(s_tx_f3_2)*1e-6;
Bs_tx_f3_2 = -imag(s_tx_f3_2)*1e-6;

s_tx_f3_3 = 480^2/conj((1/1e5 + 1/(1i*200*wbase))^-1 * (480/13800)^2);
Gs_tx_f3_3 = real(s_tx_f3_3)*1e-6;
Bs_tx_f3_3 = -imag(s_tx_f3_3)*1e-6;

s_tx_f3_4 = 480^2/conj((1/1e5 + 1/(1i*200*wbase))^-1 * (480/13800)^2);
Gs_tx_f3_4 = real(s_tx_f3_4)*1e-6;
Bs_tx_f3_4 = -imag(s_tx_f3_4)*1e-6;

s_tx_f3_5 = 480^2/conj((1/1e5 + 1/(1i*200*wbase))^-1 * (480/13800)^2);
Gs_tx_f3_5 = real(s_tx_f3_5)*1e-6;
Bs_tx_f3_5 = -imag(s_tx_f3_5)*1e-6;

%% bus data
%1 = PQ, 2 = PV, 3 = slack
%Gs = conductance
%Bs = susceptance
%Pd and Qd in MW and MVAr respectively (positive Pd is load; positive Qd is
%normal (or lagging) reactive load)



%	bus_i	type	Pd                      Qd                      Gs          Bs              area	Vm      Va      baseKV          zone    Vmax	Vmin
mpc.bus = [
%feeder1 starts here    
	1       3       0                       0                       0           0               1       1       0       Vbase_kHV       1       1.1     0.9;
	2       1       0                       0                       0       	0               1       1       0       Vbase_kHV       1       1.1     0.9;
	3       1       0                       0                       0           0               1       1       0       Vbase_kHV       1       1.1     0.9;
	4       1       0                       0           0.27+Gs_tx_f1_1     -0.131+Bs_tx_f1_1   1       1       0       Vbase_kLV1      1       1.1     0.9;
    5       1       0                       0           1.08+Gs_tx_f1_2     -0.523+Bs_tx_f1_2   1       1       0       Vbase_kLV1      1       1.1     0.9;
    6       1       0                       0                       0           0               1       1       0       Vbase_kHV       1       1.1     0.9; %
    7       1       0                       0                       0           0               1       1       0       Vbase_kHV       1       1.1     0.9;
    8       1       0                       0               0+Gs_tx_f1_3       0+Bs_tx_f1_3     1       1       0       Vbase_kMV       1       1.1     0.9;
    9       1       0                       0           0.9+Gs_tx_f1_5  -0.316+Bs_tx_f1_5        1       1       0       Vbase_kLV1      1       1.1     0.9; %This is induction machine bus. Need to update power demand with value from simulation
    10      1       0                       0             1.35+Gs_tx_f1_6   -0.474+Bs_tx_f1_6   1       1       0       Vbase_kLV1      1       1.1     0.9;
    11      1       0                       0                         0               0         1       1       0       Vbase_kHV       1       1.1     0.9; %
    12      1       0                       0             0+Gs_tx_f1_7      0+Bs_tx_f1_7        1       1       0       Vbase_kLV1      1       1.1     0.9;
    13      1       0                       0                       0           0               1       1       0       Vbase_kHV       1       1.1     0.9; %This is Diesel genset bus. no power injected.
    14      1       0                   	0            0.225+Gs_tx_f1_4  -0.11+Bs_tx_f1_4     1       1       0       Vbase_kLV2      1       1.1     0.9;  
    15      1       0                       0                       0           0               1       1       0       Vbase_kHV       1       1.1     0.9;  

%feeder2 starts here
	20       1       0                       0                      0           0               1       1       0       Vbase_kHV       1       1.1     0.9;
	30       1       0                       0                      0           0               1       1       0       Vbase_kHV       1       1.1     0.9;
	40       1       0                       0                   0.9        -0.436              1       1       0       Vbase_kLV1      1       1.1     0.9;
    50       1       0                       0              0+Gs_tx_f2_2    0+Bs_tx_f2_2        1       1       0       Vbase_kMV       1       1.1     0.9;
    60       1       0                       0             0.54+Gs_tx_f2_3  -0.2620+Bs_tx_f2_3  1       1       0       Vbase_kLV1      1       1.1     0.9; %This load has an error because upstream transformer ratio is wrong. Actual voltage specified is .144kV whereas it should be .48kV
    70       1       0                       0            0.9+Gs_tx_f2_4    -0.44+Bs_tx_f2_4    1       1       0       Vbase_kLV1      1       1.1     0.9;
    80       1       0                       0                     0            0               1       1       0       Vbase_kHV       1       1.1     0.9;
    90       1       0                       0             0.9+Gs_tx_f2_6   -0.44+Bs_tx_f2_6    1       1       0       Vbase_kLV1      1       1.1     0.9;
    100      1       0                       0             0.36+Gs_tx_f2_7  -0.17+Bs_tx_f2_7    1       1       0       Vbase_kLV1      1       1.1     0.9;
    110      1       0                       0              Gs_tx_f2_8          Bs_tx_f2_8      1       1       0       Vbase_kLV1      1       1.1     0.9; % PV inverter bus
    120      1       0                       0                      0           0               1       1       0       Vbase_kHV       1       1.1     0.9;
    130      1       0                       0          0.63+Gs_tx_f2_10   -0.27+Bs_tx_f2_10    1       1       0       Vbase_kLV1      1       1.1     0.9;
    140      1       0.0                     0          0.27+Gs_tx_f2_1   -0.131+Bs_tx_f2_1     1       1       0       Vbase_kLV2      1       1.1     0.9;  
    150      1       0                       0            0.9+Gs_tx_f2_9  -0.4359+Bs_tx_f2_9    1       1       0       Vbase_kLV1      1       1.1     0.9;  

%feeder3 starts here
	200       1       0                       0                    0            0               1       1       0       Vbase_kHV       1       1.1     0.9;
	300       1       0                       0                    0            0               1       1       0       Vbase_kHV       1       1.1     0.9;
	400       1       0.                      0.          0.9+Gs_tx_f3_1    -0.436+Bs_tx_f3_1   1       1       0       Vbase_kLV1      1       1.1     0.9;
    500       1       0.                      0.           0.54+Gs_tx_f3_2  -0.262+Bs_tx_f3_2   1       1       0       Vbase_kLV1      1       1.1     0.9;
    600       1       0                       0                       0       0                 1       1       0       Vbase_kHV       1       1.1     0.9; 
    700       1       0                       0          0.54+Gs_tx_f3_3    -0.262+Bs_tx_f3_3   1       1       0       Vbase_kLV1      1       1.1     0.9;
    800       1       0                       0                       0       0                 1       1       0       Vbase_kHV       1       1.1     0.9;
    900       1       0                       0         0.72+Gs_tx_f3_4   -0.3487+Bs_tx_f3_4    1       1       0       Vbase_kLV1      1       1.1     0.9;
    1000      1       0                       0                       0       0                 1       1       0       Vbase_kHV       1       1.1     0.9;
    1100      1       0                       0                       0    	  0                 1       1       0       Vbase_kHV       1       1.1     0.9; 
    1200      1       0                       0            0.9+Gs_tx_f3_5  -0.436+Bs_tx_f3_5    1       1       0       Vbase_kLV1      1       1.1     0.9;% Induction machine connected to this bus. need to replace power with measured value
];



%% generator data
%	bus	Pg	Qg      Qmax	Qmin	Vg      mBase	status	Pmax	Pmin	Pc1	Pc2	Qc1min	Qc1max	Qc2min	Qc2max	ramp_agc	ramp_10	ramp_30	ramp_q	apf
mpc.gen = [
	1	100	-100	100     -100	1       20       1     100       0       0	0	0       0       0       0       0           0       0       0       0;
];


% mpc.gen = [
% 	1	0	0	-1000	1000	1	100	1	0	0	0	0	0	0	0	0	0	0	0	0	0;
% ];

%% branch data
ft2mi = 1.0/5280;
R13 = 0.1206; %ohms/mile (positive sequence, equal mutuals)
X13 = 498.15497e-6*wbase; %ohms/mile (positive sequence, equal mutuals)
R11 = 0.2685; %(positive seq, equal mutuals)
X11 = 549.08455e-6*wbase; %(positive seq, equal mutuals)

%Feeder one
%**********************************
%SI units
r_f1_line_SI = R13*500*ft2mi;
X_f1_line_SI = X13*500*ft2mi;

r_f1_line1_SI = R13*1800*ft2mi;
X_f1_line1_SI = X13*1800*ft2mi;

r_f1_line2_SI = R13*5500*ft2mi;
X_f1_line2_SI = X13*5500*ft2mi;

r_f1_line3_SI = R13*1000*ft2mi; %removed series snubber from line
X_f1_line3_SI = X13*1000*ft2mi;

r_f1_line6_SI = R13*1500*ft2mi;
X_f1_line6_SI = X13*1500*ft2mi;

r_f1_line4_SI = R13*3000*ft2mi;
X_f1_line4_SI = X13*3000*ft2mi;

r_f1_lineDIESEL_SI = R11*2000*ft2mi;
X_f1_lineDIESEL_SI = X11*2000*ft2mi;

%pu
%===
r_f1_line = r_f1_line_SI/Zbase_HV;%in pu
X_f1_line = X_f1_line_SI/Zbase_HV;

r_f1_line1 = r_f1_line1_SI/Zbase_HV;
X_f1_line1 = X_f1_line1_SI/Zbase_HV;

r_f1_line2 = r_f1_line2_SI/Zbase_HV;
X_f1_line2 = X_f1_line2_SI/Zbase_HV;

r_f1_line3 = r_f1_line3_SI/Zbase_HV;
X_f1_line3 = X_f1_line3_SI/Zbase_HV;

r_f1_line4 = r_f1_line4_SI/Zbase_HV;
X_f1_line4 = X_f1_line4_SI/Zbase_HV;

r_f1_line6 = r_f1_line6_SI/Zbase_HV;
X_f1_line6 = X_f1_line6_SI/Zbase_HV;

r_f1_lineDIESEL = r_f1_lineDIESEL_SI/Zbase_HV;
X_f1_lineDIESEL = X_f1_lineDIESEL_SI/Zbase_HV;

%Xformer Feeder1_transfo1
%===========================
xformerF1_1_Vprim = 13.8e3;
xformerF1_1_Vsec = 480;
xformerF1_1_Rprim = 5.712058;
xformerF1_1_Lprim = 37.1217e-3;
xformerF1_1_Rsec = 2.304e-3;
xformerF1_1_Lsec = 1.497e-5;
r_xformerF1_1 = (xformerF1_1_Rprim + xformerF1_1_Rsec*(xformerF1_1_Vprim/xformerF1_1_Vsec)^2)/Zbase_HV; %referring to primary (HV-side)
x_xformerF1_1 = (xformerF1_1_Lprim + xformerF1_1_Lsec*(xformerF1_1_Vprim/xformerF1_1_Vsec)^2)*wbase/Zbase_HV; %same

%Xformer Feeder1_transfo2
%===========================
xformerF1_2_Vprim = 13.8e3;
xformerF1_2_Vsec = 480;
xformerF1_2_Rprim = 1.132486;    
xformerF1_2_Lprim = 8.2911e-3;
xformerF1_2_Rsec = 456.7054e-6;
xformerF1_2_Lsec = 3.34359828521e-06;

r_xformerF1_2 = (xformerF1_2_Rprim + xformerF1_2_Rsec*(xformerF1_2_Vprim/xformerF1_2_Vsec)^2)/Zbase_HV; %referring to primary (HV-side)
x_xformerF1_2 = (xformerF1_2_Lprim + xformerF1_2_Lsec*(xformerF1_2_Vprim/xformerF1_2_Vsec)^2)*wbase/Zbase_HV; %same


%Xformer Feeder1_transfo3
%========================
xformerF1_3_Vprim = 13.8e3;
xformerF1_3_Vsec = 4160;
xformerF1_3_Rprim = 0.316185857381;
xformerF1_3_Lprim = 4.781e-3;
xformerF1_3_Rsec = 9.5774e-3;
xformerF1_3_Lsec = 144.8083e-6;

r_xformerF1_3 = (xformerF1_3_Rprim + xformerF1_3_Rsec*(xformerF1_3_Vprim/xformerF1_3_Vsec)^2)/Zbase_HV;
x_xformerF1_3 = (xformerF1_3_Lprim + xformerF1_3_Lsec*(xformerF1_3_Vprim/xformerF1_3_Vsec)^2)*wbase/Zbase_HV;

%Xformer Feeder1_transfo4
%========================
xformerF1_4_Vprim = 13.8e3;
xformerF1_4_Vsec = 208;
xformerF1_4_Rprim = 5.71205770268;
xformerF1_4_Lprim = 0.0371216739265;
xformerF1_4_Rsec = 0.00043255349795;
xformerF1_4_Lsec = 2.81109028347e-06;

r_xformerF1_4 = (xformerF1_4_Rprim + xformerF1_4_Rsec*(xformerF1_4_Vprim/xformerF1_4_Vsec)^2)/Zbase_HV; 
x_xformerF1_4 = (xformerF1_4_Lprim + xformerF1_4_Lsec*(xformerF1_4_Vprim/xformerF1_4_Vsec)^2)*wbase/Zbase_HV;



%Xformer Feeder1_transfo5
%=========================
xformerF1_5_Vprim = 4160;
xformerF1_5_Vsec = 480;
xformerF1_5_Rprim = 0.128960941635;% ohms
xformerF1_5_Lprim = 0.000974926638035;% H
xformerF1_5_Rsec = 0.000572311871163;% ohms
xformerF1_5_Lsec = 4.32659750607e-06;% H
r_xformerF1_5 = (xformerF1_5_Rprim + xformerF1_5_Rsec*(xformerF1_5_Vprim/xformerF1_5_Vsec)^2)/Zbase_MV; %use MV-side
x_xformerF1_5 = (xformerF1_5_Lprim + xformerF1_5_Lsec*(xformerF1_5_Vprim/xformerF1_5_Vsec)^2)*wbase/Zbase_MV;

%Xformer Feeder1_transfo6
%=======================
xformerF1_6_Vprim = 4160; %V
xformerF1_6_Vsec = 480;%V
xformerF1_6_Rprim = 0.128960941635; %ohms
xformerF1_6_Rsec = 0.000572311871163; % ohms
xformerF1_6_Lprim = 0.000974926638035; % H
xformerF1_6_Lsec = 4.32659750607e-06;% H
r_xformerF1_6 = (xformerF1_6_Rprim + xformerF1_6_Rsec*(xformerF1_6_Vprim/xformerF1_6_Vsec)^2)/Zbase_MV;
x_xformerF1_6 = (xformerF1_6_Lprim + xformerF1_6_Lsec*(xformerF1_6_Vprim/xformerF1_6_Vsec)^2)*wbase/Zbase_MV;

%Xformer Feeder1_transfo7
%===========================
xformerF1_7_Vprim = 13.8e3; %V
xformerF1_7_Vsec = 480; %V
xformerF1_7_Rprim = 0.98424830781;%ohms
xformerF1_7_Rsec = 0.000396924333332;% ohms
xformerF1_7_Lprim = 0.00861563908798;% H
xformerF1_7_Lsec = 3.47448583258e-06;% H
r_xformerF1_7 = (xformerF1_7_Rprim + xformerF1_7_Rsec*(xformerF1_7_Vprim/xformerF1_7_Vsec)^2)/Zbase_HV;
x_xformerF1_7 = (xformerF1_7_Lprim + xformerF1_7_Lsec*(xformerF1_7_Vprim/xformerF1_7_Vsec)^2)*wbase/Zbase_HV;

%end feeder 1
%************************************


%feeder 2
%********************************************
LF2 = 500*ft2mi;
LF2L1 = 5500*ft2mi;
LF2L2 = 2000*ft2mi;
LF2L3 = 3000*ft2mi;

%SI units
r_f2_line_SI = R13*LF2;
X_f2_line_SI = X13*LF2;

r_f2_line1_SI = R11*LF2L1;
X_f2_line1_SI = X11*LF2L1;

r_f2_line2_SI = R13*LF2L2;
X_f2_line2_SI = X13*LF2L2;

r_f2_line3_SI = R13*LF2L3;
X_f2_line3_SI = X13*LF2L3;


r_f2_line = r_f2_line_SI/Zbase_HV;%in pu
X_f2_line = X_f2_line_SI/Zbase_HV;

r_f2_line1 = r_f2_line1_SI/Zbase_HV;
X_f2_line1 = X_f2_line1_SI/Zbase_HV;

r_f2_line2 = r_f2_line2_SI/Zbase_HV;
X_f2_line2 = X_f2_line2_SI/Zbase_HV;

r_f2_line3 = r_f2_line3_SI/Zbase_HV;
X_f2_line3 = X_f2_line3_SI/Zbase_HV;

%Xformer Feeder2_transfo1
%===========================
xformerF2_1_Vprim = 13.8e3;
xformerF2_1_Vsec = 208;
xformerF2_1_Rprim = 5.712058;
xformerF2_1_Lprim = 37.1217e-3;
xformerF2_1_Rsec = 432.55e-6;
xformerF2_1_Lsec = 2.8111e-6;
r_xformerF2_1 = (xformerF2_1_Rprim + xformerF2_1_Rsec*(xformerF2_1_Vprim/xformerF2_1_Vsec)^2)/Zbase_HV; %referring to primary (HV-side)
x_xformerF2_1 = (xformerF2_1_Lprim + xformerF2_1_Lsec*(xformerF2_1_Vprim/xformerF2_1_Vsec)^2)*wbase/Zbase_HV; %same

%Xformer 201
%=============
xformer201_Vprim = 13.8e3;
xformer201_Vsec = 480;
xformer201_Rprim = 0.55942;
xformer201_Lprim = 3.76e-3;
xformer201_Rsec = 676.8e-6;
xformer201_Lsec = 4.5477e-6;

r_xformer201 = (xformer201_Rprim + xformer201_Rsec*(xformer201_Vprim/xformer201_Vsec)^2)/Zbase_HV; %referring to primary (HV-side)
x_xformer201 = (xformer201_Lprim + xformer201_Lsec*(xformer201_Vprim/xformer201_Vsec)^2)*wbase/Zbase_HV; %same


%Xformer Feeder2_transfo2
%========================
xformerF2_2_Vprim = 13.8e3;
xformerF2_2_Vsec = 4160;
xformerF2_2_Rprim = 316.1859e-3;
xformerF2_2_Lprim = 4.781e-3;
xformerF2_2_Rsec = 9.5774e-3;
xformerF2_2_Lsec = 144.8083e-6;

r_xformerF2_2 = (xformerF2_2_Rprim + xformerF2_2_Rsec*(xformerF2_2_Vprim/xformerF2_2_Vsec)^2)/Zbase_HV;
x_xformerF2_2 = (xformerF2_2_Lprim + xformerF2_2_Lsec*(xformerF2_2_Vprim/xformerF2_2_Vsec)^2)*wbase/Zbase_HV;

%Xformer Feeder2_transfo3 (issue here, original set of xformer impedances are too high. They were chosen for 13.8kV/480V ratio, whereas the actual circuit needs a 4160V/480V conversion)
% (so we end up using parameters for Sn_1500kVA transformer instead)
%=========================================================
% xformerF2_3_Vprim = 13.8e3;
% xformerF2_3_Vsec = 480;
% xformerF2_3_Rprim = 2.8462;
% xformerF2_3_Lprim = 20.724e-3;
% xformerF2_3_Rsec = 1.1478e-3;
% xformerF2_3_Lsec = 8.3575e-6;

xformerF2_3_Vprim = 4160;
xformerF2_3_Vsec = 480;
xformerF2_3_Rprim = 193.6597e-3;% ohms
xformerF2_3_Lprim = 1.2945e-3;% H
xformerF2_3_Rsec = 859.4368e-6;% ohms
xformerF2_3_Lsec = 5.7449e-6;% H

r_xformerF2_3 = (xformerF2_3_Rprim + xformerF2_3_Rsec*(xformerF2_3_Vprim/xformerF2_3_Vsec)^2)/Zbase_MV; %use MV-side
x_xformerF2_3 = (xformerF2_3_Lprim + xformerF2_3_Lsec*(xformerF2_3_Vprim/xformerF2_3_Vsec)^2)*wbase/Zbase_MV;



%Xformer Feeder2_transfo4
%=========================
xformerF2_4_Vprim = 4160;
xformerF2_4_Vsec = 480;
xformerF2_4_Rprim = 193.6597e-3;% ohms
xformerF2_4_Lprim = 1.2945e-3;% H
xformerF2_4_Rsec = 859.4368e-6;% ohms
xformerF2_4_Lsec = 5.7449e-6;% H
r_xformerF2_4 = (xformerF2_4_Rprim + xformerF2_4_Rsec*(xformerF2_4_Vprim/xformerF2_4_Vsec)^2)/Zbase_MV; %use MV-side
x_xformerF2_4 = (xformerF2_4_Lprim + xformerF2_4_Lsec*(xformerF2_4_Vprim/xformerF2_4_Vsec)^2)*wbase/Zbase_MV;

%Xformer Feeer2_transfo6
%=======================
xformerF2_6_Vprim = 13.8e3; %V
xformerF2_6_Vsec = 480;%V
xformerF2_6_Rprim = 1.1325; %ohms
xformerF2_6_Rsec = 456.7054e-6; % ohms
xformerF2_6_Lprim = 8.2911e-3; % H
xformerF2_6_Lsec = 3.3436e-6;% H
r_xformerF2_6 = (xformerF2_6_Rprim + xformerF2_6_Rsec*(xformerF2_6_Vprim/xformerF2_6_Vsec)^2)/Zbase_HV;
x_xformerF2_6 = (xformerF2_6_Lprim + xformerF2_6_Lsec*(xformerF2_6_Vprim/xformerF2_6_Vsec)^2)*wbase/Zbase_HV;

%Xformer Feeder2_transfo7
%===========================
xformerF2_7_Vprim = 13.8e3; %V
xformerF2_7_Vsec = 480; %V
xformerF2_7_Rprim = 2.8462;%ohms
xformerF2_7_Rsec = 1.1478e-3;% ohms
xformerF2_7_Lprim = 20.7241e-3;% H
xformerF2_7_Lsec = 8.3575e-6;% H
r_xformerF2_7 = (xformerF2_7_Rprim + xformerF2_7_Rsec*(xformerF2_7_Vprim/xformerF2_7_Vsec)^2)/Zbase_HV;
x_xformerF2_7 = (xformerF2_7_Lprim + xformerF2_7_Lsec*(xformerF2_7_Vprim/xformerF2_7_Vsec)^2)*wbase/Zbase_HV;


%Xformer Feeder2_transfo8
%========================
xformerF2_8_Vprim = 13.8e3; %V
xformerF2_8_Vsec = 480;
xformerF2_8_Rprim = 0.5594;% ohms
xformerF2_8_Rsec = 676.8e-6;% ohms
xformerF2_8_Lprim = 0.00376;% H
xformerF2_8_Lsec = 4.5477e-6;% H
r_xformerF2_8 = (xformerF2_8_Rprim + xformerF2_8_Rsec*(xformerF2_8_Vprim/xformerF2_8_Vsec)^2)/Zbase_HV;
x_xformerF2_8 = (xformerF2_8_Lprim + xformerF2_8_Lsec*(xformerF2_8_Vprim/xformerF2_8_Vsec)^2)*wbase/Zbase_HV;

%Xformer Feeder2_transfo9
%========================
xformerF2_9_Vprim = 13.8e3;
xformerF2_9_Vsec = 480;
xformerF2_9_Rprim = 1.41915;% ohms
xformerF2_9_Rsec = 572.312e-6;% ohms
xformerF2_9_Lprim = 10.7286e-3;% H
xformerF2_9_Lsec = 4.3266e-6;% H
r_xformerF2_9 = (xformerF2_9_Rprim + xformerF2_9_Rsec*(xformerF2_9_Vprim/xformerF2_9_Vsec)^2)/Zbase_HV;
x_xformerF2_9 = (xformerF2_9_Lprim + xformerF2_9_Lsec*(xformerF2_9_Vprim/xformerF2_9_Vsec)^2)*wbase/Zbase_HV;

%Xformer Feeder2_transfo10
%==========================
xformerF2_10_Vprim = 13.8e3; %kV
xformerF2_10_Vsec = 480; %V
xformerF2_10_Rprim = 1.41915; %ohms
xformerF2_10_Rsec = 572.312e-6; %ohms
xformerF2_10_Lprim = 10.7286e-3;%H
xformerF2_10_Lsec = 4.3266e-6; %H
r_xformerF2_10 = (xformerF2_10_Rprim + xformerF2_10_Rsec*(xformerF2_10_Vprim/xformerF2_10_Vsec)^2)/Zbase_HV;
x_xformerF2_10 = (xformerF2_10_Lprim + xformerF2_10_Lsec*(xformerF2_10_Vprim/xformerF2_10_Vsec)^2)*wbase/Zbase_HV;

%end feeder 2
%***************************************************

%feeder 3 data
%***************************************************
%SI units
r_f3_line_SI = R13*500*ft2mi; %removed the series snubber
X_f3_line_SI = X13*500*ft2mi; %removed series snubber

r_f3_line1_SI = R13*2500*ft2mi;
X_f3_line1_SI = X13*2500*ft2mi;

r_f3_line4_SI = R11*1500*ft2mi;
X_f3_line4_SI = X11*1500*ft2mi;

r_f3_line2_SI = R11*2000*ft2mi;
X_f3_line2_SI = X11*2000*ft2mi;

r_f3_lineNG_SI = R11*2000*ft2mi;
X_f3_lineNG_SI = X11*2000*ft2mi;

r_f3_line3_SI = R13*2000*ft2mi;
X_f3_line3_SI = X13*2000*ft2mi;



r_f3_line = r_f3_line_SI/Zbase_HV;%in pu
X_f3_line = X_f3_line_SI/Zbase_HV;

r_f3_line1 = r_f3_line1_SI/Zbase_HV;
X_f3_line1 = X_f3_line1_SI/Zbase_HV;

r_f3_line2 = r_f3_line2_SI/Zbase_HV;
X_f3_line2 = X_f3_line2_SI/Zbase_HV;

r_f3_line3 = r_f3_line3_SI/Zbase_HV;
X_f3_line3 = X_f3_line3_SI/Zbase_HV;

r_f3_line4 = r_f3_line4_SI/Zbase_HV;
X_f3_line4 = X_f3_line4_SI/Zbase_HV;

r_f3_lineNG = r_f3_lineNG_SI/Zbase_HV;
X_f3_lineNG = X_f3_lineNG_SI/Zbase_HV;


%Xformer Feeder3_transfo1
%===========================
xformerF3_1_Vprim = 13.8e3;
xformerF3_1_Vsec = 480;
xformerF3_1_Rprim = 1.41915;
xformerF3_1_Lprim =  10.7286e-3; 
xformerF3_1_Rsec = 572.312e-6;
xformerF3_1_Lsec = 4.3266e-6;
r_xformerF3_1 = (xformerF3_1_Rprim + xformerF3_1_Rsec*(xformerF3_1_Vprim/xformerF3_1_Vsec)^2)/Zbase_HV; %referring to primary (HV-side)
x_xformerF3_1 = (xformerF3_1_Lprim + xformerF3_1_Lsec*(xformerF3_1_Vprim/xformerF3_1_Vsec)^2)*wbase/Zbase_HV; %same


%Xformer Feeder2_transfo2
%========================
xformerF3_2_Vprim = 13.8e3;
xformerF3_2_Vsec = 480;
xformerF3_2_Rprim = 1.41915;
xformerF3_2_Lprim = 10.7286e-3; 
xformerF3_2_Rsec = 572.312e-6;
xformerF3_2_Lsec = 4.3266e-6;

r_xformerF3_2 = (xformerF3_2_Rprim + xformerF3_2_Rsec*(xformerF3_2_Vprim/xformerF3_2_Vsec)^2)/Zbase_HV;
x_xformerF3_2 = (xformerF3_2_Lprim + xformerF3_2_Lsec*(xformerF3_2_Vprim/xformerF3_2_Vsec)^2)*wbase/Zbase_HV;

%Xformer Feeder2_transfo3
%========================
xformerF3_3_Vprim = 13.8e3; %V
xformerF3_3_Vsec = 480; %V
xformerF3_3_Rprim = 2.8462;%ohms
xformerF3_3_Rsec = 1.1478e-3;% ohms
xformerF3_3_Lprim = 20.7241e-3;% H
xformerF3_3_Lsec = 8.3575e-6;% H


r_xformerF3_3 = (xformerF3_3_Rprim + xformerF3_3_Rsec*(xformerF3_3_Vprim/xformerF3_3_Vsec)^2)/Zbase_HV; %
x_xformerF3_3 = (xformerF3_3_Lprim + xformerF3_3_Lsec*(xformerF3_3_Vprim/xformerF3_3_Vsec)^2)*wbase/Zbase_HV;


%Xformer Feeder2_transfo4
%=========================
xformerF3_4_Vprim = 13.8e3;
xformerF3_4_Vsec = 480;
xformerF3_4_Rprim = 2.8462;% ohms
xformerF3_4_Lprim = 20.7241e-3;% H
xformerF3_4_Rsec = 1.1478e-3;% ohms
xformerF3_4_Lsec = 8.3575e-6;% H
r_xformerF3_4 = (xformerF3_4_Rprim + xformerF3_4_Rsec*(xformerF3_4_Vprim/xformerF3_4_Vsec)^2)/Zbase_HV; %
x_xformerF3_4 = (xformerF3_4_Lprim + xformerF3_4_Lsec*(xformerF3_4_Vprim/xformerF3_4_Vsec)^2)*wbase/Zbase_HV;

%Xformer Feeer2_transfo5
%=======================
xformerF3_5_Vprim = 13.8e3; %V
xformerF3_5_Vsec = 480;%V
xformerF3_5_Rprim = 0.98425; %ohms
xformerF3_5_Rsec = 396.92433e-6; % ohms
xformerF3_5_Lprim = 8.6156e-3; % H
xformerF3_5_Lsec = 3.74486e-6;% H
r_xformerF3_5 = (xformerF3_5_Rprim + xformerF3_5_Rsec*(xformerF3_5_Vprim/xformerF3_5_Vsec)^2)/Zbase_HV;
x_xformerF3_5 = (xformerF3_5_Lprim + xformerF3_5_Lsec*(xformerF3_5_Vprim/xformerF3_5_Vsec)^2)*wbase/Zbase_HV;
%end feeder 3
%***************************************************

%	fbus	tbus	r               x               b           rateA       rateB       rateC       ratio       angle       status      angmin      angmax
mpc.branch = [
	1       2       r_f1_line       X_f1_line       0           250         250         250         0           0           1           -360        360;
	2       3       r_f1_line1      X_f1_line1      0           250         250         250         0           0           1           -360        360;
	2       6       r_f1_line2      X_f1_line2      0           250         250         250         0           0           1           -360        360;
	2       11      r_f1_line3      X_f1_line3      0           250         250         250         0           0           1           -360        360;
    3       4       r_xformerF1_1   x_xformerF1_1   0           250         250         250         0           0           1           -360        360;
    3       5       r_xformerF1_2   x_xformerF1_2   0           250         250         250         0           0           1           -360        360;
    6       7       r_f1_line6      X_f1_line6      0           250         250         250         0           0           1           -360        360;
    6       14      r_xformerF1_4   x_xformerF1_4   0           250         250         250         0           0           1           -360        360;
    7       8       r_xformerF1_3   x_xformerF1_3   0           250         250         250         0           0           1           -360        360;
    8       9       r_xformerF1_5   x_xformerF1_5   0           250         250         250         0           0           1           -360        360;
    8       10      r_xformerF1_6   x_xformerF1_6   0           250         250         250         0           0           1           -360        360;
    11      15      r_f1_line4      X_f1_line4      0           250         250         250         0           0           1           -360        360;
    15      12      r_xformerF1_7   x_xformerF1_7   0           250         250         250         0           0           1           -360        360;
    11      13      r_f1_lineDIESEL X_f1_lineDIESEL   0           250         250         250         0           0           1         -360        360;

%feeder 2
%	fbus	tbus	r               x               b           rateA       rateB       rateC       ratio       angle       status      angmin      angmax
	1       20       r_f2_line       X_f2_line       0           250         250         250         0           0           1           -360        360;
	20      30       r_f2_line1      X_f2_line1      0           250         250         250         0           0           1           -360        360;
	20      80       r_f2_line2      X_f2_line2      0           250         250         250         0           0           1           -360        360;
	20      120      r_f2_line3      X_f2_line3      0           250         250         250         0           0           1           -360        360;
    30      140      r_xformerF2_1   x_xformerF2_1   0           250         250         250         0           0           1           -360        360;
    30      40       r_xformer201    x_xformer201    0           250         250         250         0           0           1           -360        360;
    30      50       r_xformerF2_2   x_xformerF2_2   0           250         250         250         0           0           1           -360        360;
    50      60       r_xformerF2_3   x_xformerF2_3   0           250         250         250         0           0           1           -360        360;
    50      70       r_xformerF2_4   x_xformerF2_4   0           250         250         250         0           0           1           -360        360;
    80      90       r_xformerF2_6   x_xformerF2_6   0           250         250         250         0           0           1           -360        360;
    80      100      r_xformerF2_7   x_xformerF2_7   0           250         250         250         0           0           1           -360        360;
    80      110      r_xformerF2_8   x_xformerF2_8   0           250         250         250         0           0           1           -360        360;
    120     150      r_xformerF2_9   x_xformerF2_9   0           250         250         250         0           0           1           -360        360;
    120     130      r_xformerF2_10  x_xformerF2_10  0           250         250         250         0           0           1           -360        360;    

%feeder 3
	1       200       r_f3_line       X_f3_line       0           250         250         250         0           0           1           -360        360;
	200     300       r_f3_line1      X_f3_line1      0           250         250         250         0           0           1           -360        360;
	200     600       r_f3_line4      X_f3_line4      0           250         250         250         0           0           1           -360        360;
	200     800       r_f3_line2      X_f3_line2      0           250         250         250         0           0           1           -360        360;
    200     1100      r_f3_line3      X_f3_line3      0           250         250         250         0           0           1           -360        360;
    300     400       r_xformerF3_1   x_xformerF3_1   0           250         250         250         0           0           1           -360        360;
    300     500       r_xformerF3_2   x_xformerF3_2   0           250         250         250         0           0           1           -360        360;
    600     700       r_xformerF3_3   x_xformerF3_3   0           250         250         250         0           0           1           -360        360;
    800     900       r_xformerF3_4   x_xformerF3_4   0           250         250         250         0           0           1           -360        360;
    800     1000      r_f3_lineNG     X_f3_lineNG     0           250         250         250         0           0           1           -360        360;    
    1100    1200      r_xformerF3_5   x_xformerF3_5   0           250         250         250         0           0           1           -360        360;
];