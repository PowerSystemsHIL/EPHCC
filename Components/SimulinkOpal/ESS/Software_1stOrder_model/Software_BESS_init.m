Ts = 100e-6; % simulation time step
Tc = Ts; %*5; % controller time step 
f = 60; % nominal grid freq
s = tf('s');

% Voltage Source Impedance
Pgrid = 3e6; % changed from 1MW to 3 MW - R.S[2017-01-26] 
Vgrid = 480/sqrt(3);
Igrid = Pgrid/Vgrid/3;
Zgrid = Vgrid*0.01/(Pgrid/Vgrid/3); % 1% is reasonable for a large 1MW generator but should be higher ~5% for 10s of kw machine 
Rgrid = Zgrid/2;
Lgrid = (Zgrid/2)/(2*pi*f);
H = 2;
tau_mech = 0.3; % time constant on prime mover
sys_mech = ss(1/(tau_mech*s+1));

loadCmds = [0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0;  % time
            0   1   0   0   0   0   0   0   0   0   0  ;  % additional R
            0   0   0   1   0   0   0   0   0   0   0  ;  % L
            0   0   0   0   0   1   0   0   0   0   0  ;  % C
            ];
        
paramPLLControlP = 18; 
paramPLLControlI = 320;
paramPLLControlD = 1;
% paramPLLControlP = 180; % default settings
% paramPLLControlI = 3200;
% paramPLLControlD = 5;
paramPLLControlSatFreq = 10; % Hz delta from nominal 60
paramPLLDVoltsTol = 0.85;
paramPLLQVoltsTol = 0.15;
paramPLLQFEDebounceTime = 0.010;
sampdT = Tc;
dT = Ts;
PLLFreqChangeRateMax = 10; %100
PLLFreqCutOff = 10; %200
%PLLFreqChangeRateMax = 100;
%PLLFreqCutOff = 200;

%% Resistive droop for low voltage microgrids

% paramDroopVolts2Real = 100;
% paramDroopVolts2Reac = 0;
% paramDroopFreq2Real = 0;
% paramDroopFreq2Reac = 100;
% 
% %% Inductive droop for higher voltage microgrids
% 
% paramDroopVolts2Real = 0;
% paramDroopVolts2Reac = 100;
% paramDroopFreq2Real = 100;
% paramDroopFreq2Reac = 0;

%% Cross coupling in droop for mixed microgrids

paramDroopVolts2Real = 0.5*(1/0.05); % 10
paramDroopVolts2Reac = 0*(1/0.05);
paramDroopFreq2Real = 0*(1/0.05);
paramDroopFreq2Reac = 0.5*(1/0.05); %10

filt = firstOrderDig(50e-3, Tc, 'low');

%[mag_num, mag_den] = firstOrderDig(500e-6, Tc, 'low');

% %% Cross coupling in droop for mixed microgrids
% 
% paramDroopVolts2Real = 1;
% paramDroopVolts2Reac = 100;
% paramDroopFreq2Real = 100;
% paramDroopFreq2Reac = 1;
% 
% [mag_num, mag_den] = firstOrderDig(50e-3, Tc, 'low');