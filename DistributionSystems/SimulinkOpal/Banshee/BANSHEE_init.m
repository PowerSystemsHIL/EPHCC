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
components_path_init;


%% circuit breaker delays
% breaker mechanical open/close delay in seconds
% different delays may be applied to each breaker, however,
% for convenience it is assumed all breaker have the same delay
cb_mech_delay = 5/60;

%% Initialization file for software BESS
Software_BESS_init;

%% Temp

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

%% Initialise test system depending on generator model to be tested

switch NREL_Mode
    case 3
        GenPN = 80e3;
        GenVN = 480;
    case 2
        GenPN = 4e6;
        GenVN = 13800;
    case 1
        GenPN = 4e6;
        GenVN = 13800;    
end;

%% Test stimuli generator
% see. Stimuli.xlsx for better view and changes
Stim.Ts = 3;

Stim.Gen3.s	= [	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.5	0.5	1	1	1	1	0.3	0.3	0.3	0.3	0.3	0.3	0.3	0.3	0.3	0.3	0.3	0.3	];
Stim.Gen3.Ena	= [	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	1	1	1	1	1	1	1	1	1	1	1	0	];
Stim.Gen3.GCBo	= [	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	0	0	0	0	0	0	0	1	1	1	1	1	0	0	0	0	0	0	0	0	1	];
Stim.Gen3.Mode	= [	3	3	3	3	3	3	3	3	3	3	3	3	3	3	3	3	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	3	3	3	3	];
Stim.CB.CB401	= [	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	2	2	2	2	];
Stim.CB.CB402	= [	2	2	1	1	1	1	1	2	2	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	2	2	2	];
Stim.CB.CB405	= [	2	2	1	1	1	1	1	2	2	2	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
Stim.CB.CB406	= [	2	2	2	1	1	1	1	2	2	1	1	1	1	1	2	2	2	2	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
Stim.CB.CB407	= [	2	2	2	2	2	1	1	2	2	2	2	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	2	2	2	];
Stim.CB.CB408	= [	2	2	2	2	2	2	1	2	2	2	2	2	1	1	2	2	2	2	1	1	2	2	1	1	1	1	1	1	2	2	2	2	2	2	2	2	];
Stim.CB.CB409	= [	2	2	2	1	1	1	1	2	2	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
Stim.CB.CB410	= [	2	2	2	2	1	1	1	2	2	2	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
Stim.CB.CB411	= [	2	2	2	2	2	1	1	2	2	2	2	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	2	2	2	];
Stim.CB.CB412	= [	2	2	2	2	2	2	1	2	2	2	2	2	1	1	2	2	2	2	1	1	2	2	2	1	1	1	1	1	2	2	2	2	2	2	2	2	];
Stim.ESS2.Ena	= [	0	1	1	1	1	1	1	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	1	1	0	0	1	1	1	0	0	];
Stim.ESS2.p	= [	0	0	0	0	0	0	0	0	0	0	0	0	0.16	0.08	-0.08	-0.1	-0.16	-0.2	1	1	-1	-1	-1	0.2	0.2	-1	-1	-1	-1	0.16	0.16	0.1	0.2	0	0	0	];
Stim.ESS2.q	= [	0	0	0	0	0	0	0	0	0	0	0	0	0.1	0.1	0.05	0	0	0.2	-0.2	-0.2	-0.2	-0.2	-0.2	0	0	0	0	0	0	0	0	0.05	0.1	0	0	0	];
Stim.ESS2.v	= [	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
Stim.ESS2.f	= [	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
Stim.ESS2.MCB	= [	0	0	0	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
Stim.PV.Ena	= [	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
Stim.PV.p	= [	0	0.05	0.3	0.7	1	0.5	0.7	0.7	0.3	0.1	0.2	0.3	0.1	0.1	0.3	0.4	0.7	0.8	0.9	1	1	1	0.7	0.4	0.3	0.1	0	0	0.3	0.6	0.1	0.2	0.1	0	0	0	];

Stim.N = length(Stim.Gen3.s);
Stim.Trep = Stim.N*Stim.Ts;
Stim.Dec = Stim.Trep/Ts/5000;