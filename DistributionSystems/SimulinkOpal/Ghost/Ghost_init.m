%% Copyright 2018 Alliance for Sustainable Energy, LLC
%
% Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
% and associated documentation files (the "Software"), to deal in the Software without restriction, 
% including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
% and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, 
% subject to the following conditions:
%
% The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
%
% THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
% BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
% NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS, THE COPYRIGHT HOLDERS, THE UNITED STATES, 
% THE UNITED STATES DEPARTMENT OF ENERGY, OR ANY OF THEIR EMPLOYEES BE LIABLE FOR ANY CLAIM, 
% DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
% OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
%

%% model configuration parameters
Ts = 100E-6; % integration time
Ts_EPC = 100E-6; % integration time for BESS and PV 
SIM_HIL = 1; % Selects Opal-RT(1) or Simulink(0)

%% read relay settings
% reads-in all relay settings for the system and initializes vectors to
% hold these settings that will be called from the software relays
relay_settings_init;

%% cable parameters
% to be used for the PI sections
cable_impedance_init;

%% adds the component folders to the path
% eventually, Opal-RT may need to include flexibility to use subfolders in a development
% components_path_init;
% Components should be permanently added to matlab library by opening project in \SimulationTools\SimulinkOpal\HIL.prj
% and then saving paths

%% add DER modbus interface configuration files path
addpath('der_configuration_files');

%% circuit breaker delays
% breaker mechanical open/close delay in seconds
% different delays may be applied to each breaker, however,
% for convenience it is assumed all breaker have the same delay
cb_mech_delay = 5/60;

%% Precalculate governor's TF's - lack of control system toolbox on one of machine
% st=50e-6;
% if length(st)>1
%     st=SampleTime(1);
% end
% method=('zoh');
% Wc = 1;
% Numerator=[0.025 1];
% Denominator=[0.0009 1];
% if(st>0)
%     [T4numd,T4dend] = sldiscutil('disctransferfcn',{st,method,Wc,Numerator,Denominator});
% end	
% 
% 
% Numerator=[1];
% Denominator=[0.00574 1];
% if(st>0)
%     [T3numd,T3dend] = sldiscutil('disctransferfcn',{st,method,Wc,Numerator,Denominator});
% end
T4numd =[ 27.7778  -27.7237 ];
T4dend = [ 1.0000   -0.9460 ];
T3numd = [ 0    0.0087 ];
T3dend = [ 1.0000   -0.9913 ];

%% PHIL interface
PHIL.P_ratio = 20;
PHIL.V_ratio = 4160/480;
PHIL.I_ratio = PHIL.P_ratio/PHIL.V_ratio;

%% Test stimuli generator
% see. Stimuli.xlsx for better view and changes. After doce in excel just
% copy and paste here
Stim.Ts = 4;

Stim.Gen1.s	= [	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.5	0.5	1	1	1	1	0.3	0.3	0.3	0.3	0.3	0.3	0.3	0.3	0.3	0.3	0.3	0.3	];
Stim.Gen1.Run	= [	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	1	1	1	1	1	1	1	1	1	1	1	0	];
Stim.Gen1.Ena	= [	0	0	0	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	1	1	0	];
Stim.Gen2.s	= [	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.5	0.5	1	1	1	1	0.3	0.3	0.3	0.3	0.3	0.3	0.3	0.3	0.3	0.3	0.3	0.3	];
Stim.Gen2.Run	= [	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	1	1	1	1	1	1	1	1	1	1	1	0	];
Stim.Gen2.Ena	= [	0	0	0	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	1	1	0	];
Stim.Gen3.s	= [	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.5	0.5	1	1	1	1	0.3	0.3	0.3	0.3	0.3	0.3	0.3	0.3	0.3	0.3	0.3	0.3	];
Stim.Gen3.Run	= [	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	1	1	1	1	1	1	1	1	1	1	1	0	];
Stim.Gen3.Ena	= [	0	0	0	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	1	1	0	];
Stim.CB.CB100	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB200	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB300	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB101	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB102	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB103	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB104	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB105	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB106	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB107	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB108	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB109	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB110	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB111	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB112	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB113	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB114	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB201	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB202	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB203	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB204	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB205	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB206	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB207	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB208	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB209	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB210	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB211	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB212	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB213	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB214	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB215	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB216	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB217	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB218	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB219	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB301	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB302	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB303	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB304	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB305	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB306	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB307	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB308	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB309	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB310	= [	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	];
Stim.CB.CB401	= [	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	2	2	2	2	];
Stim.CB.CB402	= [	2	2	2	2	2	1	1	2	2	2	2	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	2	2	2	];
Stim.CB.CB403	= [	2	2	2	2	2	2	1	2	2	2	2	2	1	1	2	2	2	2	1	1	2	2	1	1	1	1	1	1	2	2	2	2	2	2	2	2	];
Stim.CB.CB404	= [	2	2	2	1	1	1	1	2	2	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
Stim.CB.CB405	= [	2	2	2	2	2	1	1	2	2	2	2	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	2	2	2	];
Stim.CB.CB406	= [	2	2	2	2	2	2	1	2	2	2	2	2	2	1	2	2	2	2	1	1	2	2	2	1	1	1	1	1	2	2	2	2	2	2	2	2	];
Stim.ESS1.Ena	= [	0	1	1	1	1	1	1	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	1	1	0	0	1	1	1	0	0	];
Stim.ESS1.p	= [	0	0	0	0	0	0	0	0	0	0	0	0	0	0	-0.08	-0.1	-0.1	-0.1	0	0.2	-0.2	-1	-1	0.2	0.2	-1	-1	-1	-1	0.16	0.16	0.1	0.2	0	0	0	];
Stim.ESS1.q	= [	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0.05	0	0	0	0	-0.2	-0.2	-0.2	-0.2	0	0	0	0	0	0	0	0	0.05	0.1	0	0	0	];
Stim.ESS1.v	= [	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
Stim.ESS1.f	= [	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
Stim.ESS1.VFmode	= [	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	];
Stim.ESS2.Ena	= [	0	1	1	1	1	1	1	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	1	1	0	0	1	1	1	0	0	];
Stim.ESS2.p	= [	0	0	0	0	0	0	0	0	0	0	0	0	0	0	-0.08	-0.1	-0.1	-0.1	0	0.2	-0.2	-1	-1	0.2	0.2	-1	-1	-1	-1	0.16	0.16	0.1	0.2	0	0	0	];
Stim.ESS2.q	= [	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0.05	0	0	0	0	-0.2	-0.2	-0.2	-0.2	0	0	0	0	0	0	0	0	0.05	0.1	0	0	0	];
Stim.ESS2.v	= [	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
Stim.ESS2.f	= [	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
Stim.ESS2.VFmode	= [	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	];
Stim.PV1.Ena	= [	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
Stim.PV1.Irradiance	= [	0	0.05	0.3	0.7	1	0.5	0.7	0.7	0.3	0.1	0	0	0	0	0.3	0.4	0.1	0.1	0.1	0.2	0.3	0.4	1	0.4	0.3	0.1	0	0	0.3	0.6	0.1	0.2	0.1	0	0	0	];
Stim.PV2.Ena	= [	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
Stim.PV2.Irradiance	= [	0	0.05	0.3	0.7	1	0.5	0.7	0.7	0.3	0.1	0	0	0	0	0.3	0.4	0.1	0.1	0.1	0.2	0.3	0.4	1	0.4	0.3	0.1	0	0	0.3	0.6	0.1	0.2	0.1	0	0	0	];

Stim.N = length(Stim.Gen3.s);
Stim.Trep = Stim.N*Stim.Ts;
Stim.Dec = Stim.Trep/Ts/5000;


%% Disactivate links that needs to be opened to allow proper model separation 
if exist('OpenLinks', 'var')  % only run when in opal - keep link resolved when editing outside
    if (strncmp(gcb, 'Ghost_f4', length('Ghost_f4')))
        LinkPath = 'Ghost_f4/SS_Feeder4';
        if (length(find_system(LinkPath, 'SearchDepth', 0)) == 1)
            if strcmp(get_param(LinkPath, 'LinkStatus'), 'inactive') == 0
                disp(['###openning link: ' LinkPath]);
                set_param(LinkPath, 'LinkStatus', 'inactive');
            else
                disp(['###link already open: ' LinkPath]);
            end;
        end;
    elseif (strncmp(gcb, 'Ghost', length('Ghost')))
        LinkPath = { ... 
            'Ghost/SS_COMMUNICATION' ...
            'Ghost/SS_F1_RELAY_HOUSING' ... 
            'Ghost/SS_F2_RELAY_HOUSING' ...
            'Ghost/SS_F3_RELAY_HOUSING' ...
            'Ghost/SS_F4_RELAY_HOUSING' ...
            'Ghost/SS_Feeder1' ...
            'Ghost/SS_Feeder2' ...
            'Ghost/SS_Feeder3' ...
            'Ghost/SS_Feeder4' ...
            'Ghost/SM_UtilityService'};
        for ii = 1:length(LinkPath)
            if (length(find_system(LinkPath{ii}, 'SearchDepth', 0)) == 1)
                if strcmp(get_param(LinkPath{ii}, 'LinkStatus'), 'inactive') == 0
                    disp(['###openning link: ' LinkPath{ii}]);
                    set_param(LinkPath{ii}, 'LinkStatus', 'inactive');
                else
                    disp(['###link already open: ' LinkPath{ii}]);
                end;
            end;
        end;
    elseif (strncmp(gcb, 'Ghost_f34', length('Ghost_f34')))
        LinkPath = { ... 
            'Ghost_f34/SS_COMMUNICATION' ...
            'Ghost_f34/SS_F3_RELAY_HOUSING' ...
            'Ghost_f34/SS_Feeder3' ...
            'Ghost_f34/SS_Feeder4' ...
            'Ghost_f34/SM_UtilityService'};
        for ii = 1:length(LinkPath)
            if (length(find_system(LinkPath{ii}, 'SearchDepth', 0)) == 1)
                if strcmp(get_param(LinkPath{ii}, 'LinkStatus'), 'inactive') == 0
                    disp(['###openning link: ' LinkPath{ii}]);
                    set_param(LinkPath{ii}, 'LinkStatus', 'inactive');
                else
                    disp(['###link already open: ' LinkPath{ii}]);
                end;
            end;
        end;
    else
        disp(['###skipping openning links for model ' gcb]);
    end;
else
    disp('###skipping openning links - not an Rtlab environment');
end;