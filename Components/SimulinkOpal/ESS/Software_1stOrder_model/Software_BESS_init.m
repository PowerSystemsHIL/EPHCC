Ts = 100e-6; % simulation time step
Tc = Ts; %*5; % controller time step 
%Tc = Ts*5; % controller time step 
f = 60; % nominal grid freq
% s = tf('s');

% Battery parameters
batt_kWh = 1000;
batt_esr = 0.1;
Vdc_nom = 1000;

% Voltage Source Impedance
Pgrid = 3e6; % changed from 1MW to 3 MW - R.S[2017-01-26] 
Vgrid = 480/sqrt(3);
Igrid = Pgrid/Vgrid/3;
GridPct = 0.01; % 1% is reasonable for a large 1MW generator but should be higher ~5% for 10s of kw machine 
Zgrid = Vgrid*GridPct/(Pgrid/Vgrid/3); 
Rgrid = Zgrid/2;
Lgrid = (Zgrid/2)/(2*pi*f);
H = 2;
tau_mech = 0.3; % time constant on prime mover
% sys_mech = ss(1/(tau_mech*s+1));
dPer = 0.05; % droop percent
PUIMax = 1.2; % max current output

loadCmds = [0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0;  % time
            0   1   0   0   0   0   0   0   0   0   0  ;  % additional R
            0   0   0   1   0   0   0   0   0   0   0  ;  % L
            0   0   0   0   0   1   0   0   0   0   0  ;  % C
            ];
        
paramPLLControlP = 180; 
paramPLLControlI = 3200;
paramPLLControlD = 1;
% paramPLLControlP = 180; % default settings
% paramPLLControlI = 3200;
% paramPLLControlD = 5;
paramPLLControlSatFreq = 10; % Hz delta from nominal 60
paramPLLDVoltsTol = 0.85;
paramPLLQVoltsTol = 0.15;
paramPLLQFEDebounceTime = 0.007;
paramPLLQREDebounceTime = 0.1;
sampdT = Tc;
dT = Ts;
PLLFreqChangeRateMax = 12; %100
PLLFreqCutOff = 25; %200
%PLLFreqChangeRateMax = 100;
%PLLFreqCutOff = 200;
Lvir = Lgrid*100;
Rpvir = (Vgrid^2)/(0.001*Pgrid/3);
Resrvir = Rgrid;

%% Resistive droop for low voltage microgrids

% paramDroopVolts2Real = 100;
% paramDroopVolts2Reac = 0;
% paramDroopFreq2Real = 0;
% paramDroopFreq2Reac = 100;
% 
% %% Inductive droop for higher voltage microgrids
% 
paramDroopVolts2Real = 0*(1/dPer); % 10
paramDroopVolts2Reac = 1*(1/dPer);
paramDroopFreq2Real = 1*(1/dPer);
paramDroopFreq2Reac = 0*(1/dPer); %10

filt = firstOrderDig(50e-3, Tc, 'low');

%% Cross coupling in droop for mixed microgrids

% paramDroopVolts2Real = 0.5*(1/dPer); % 10
% paramDroopVolts2Reac = 0*(1/dPer);
% paramDroopFreq2Real = 0*(1/dPer);
% paramDroopFreq2Reac = 0.5*(1/dPer); %10
% 
% filt = firstOrderDig(50e-3, Tc, 'low');

%[mag_num, mag_den] = firstOrderDig(500e-6, Tc, 'low');

% %% Cross coupling in droop for mixed microgrids
% 
% paramDroopVolts2Real = 1;
% paramDroopVolts2Reac = 100;
% paramDroopFreq2Real = 100;
% paramDroopFreq2Reac = 1;
% 
% [mag_num, mag_den] = firstOrderDig(50e-3, Tc, 'low');

%% Current source inverter - voltage source based

% Inverter filter parameters
Sn_ess = 250e3;   %[VA]
fn_ess = 60;    %[Hz]
Us_ess = 480;        %[V]; nap. RMS p-p stojana
Rs_ess_base = Us_ess^2/Sn_ess;        %[ohm]
Ls_ess_base = Rs_ess_base/2/pi/fn_ess;     

Rs_ess_PU = 5.4e-3;     %[PU]
Ls_ess_PU = 10.2e-2;     %[PU]

Rs_ess = Rs_ess_PU*Rs_ess_base;     %[ohm]; rezystancja stojana
Ls_ess = Ls_ess_PU*Ls_ess_base;     %[H]; indukcyjnosc stojana
