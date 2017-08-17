
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

%% read relay settings
% reads-in all relay settings for the system and initializes vectors to
% hold these settings that will be called from the software relays
mypath = pwd;
cd '..\..\..\DistributionSystems\SimulinkOpal\Banshee';
relay_settings_init;
cd(mypath);

%% circuit breaker delays
% breaker mechanical open/close delay in seconds
% different delays may be applied to each breaker, however,
% for convenience it is assumed all breaker have the same delay
cb_mech_delay = 5/60;

%% Initialise test system depending on generator model to be tested
TestSystemGenPath  = 'NREL_Diesel_Genset_Test_System/SM_Master/Diesel_Generator/GenSet';
TestSystemCtrlPath = 'NREL_Diesel_Genset_Test_System/SM_Master/Diesel_Generator/SimGenCtrl';
GCBPath = 'NREL_Diesel_Genset_Test_System/SM_Master/Diesel_Generator/Generic_Relay';
MCBPath = 'NREL_Diesel_Genset_Test_System/SM_Master/Generic_Relay';

switch GenSelect
    case '80kW'
        set_param(TestSystemGenPath,  'GenSel', '80kVA diesel generator');
        set_param(TestSystemCtrlPath, 'GenSel', '80kVA diesel generator');
        set_param(GCBPath, 'relay_settings', '[DER_REL(CBID.GEN3,:)]');
        set_param(MCBPath, 'relay_settings', '[F4(1,:)]');
        GenPN = 100e3;
        GenVN = 480;
        GenMult = 10;
    case '4MW'
        set_param(TestSystemGenPath,  'GenSel', '4MVA diesel generator');
        set_param(TestSystemCtrlPath, 'GenSel', '4MVA diesel generator');
        set_param(GCBPath, 'relay_settings', '[DER_REL(CBID.GEN1,:)]');
        set_param(MCBPath, 'relay_settings', '[F1(1,:)]');
        GenPN = 4e6;
        GenVN = 13800;
        GenMult = 1;
    case '3.5MW'
        set_param(TestSystemGenPath,  'GenSel', '3.5MVA natural gas generator');
        set_param(TestSystemCtrlPath, 'GenSel', '3.5MVA natural gas generator');
        set_param(GCBPath, 'relay_settings', '[DER_REL(CBID.GEN2,:)]');
        set_param(MCBPath, 'relay_settings', '[F3(1,:)]');
        GenPN = 3.5e6;
        GenVN = 13800;
        GenMult = 1;
end;

%% Test stimuli generator
% see. Stimuli.xlsx for better view and changes
Stim.Ts = 1;

% Test of multiple features / connect / disconnect etc
Stim.Gen.s	= [	0.1	0.1	0.1	0.1	0.1	0.1	0.1	0.5	0.5	0.5	1	1	1	1	1	1	1	1	1	1	1	0.1	0.1	0.1	1	1	1	1	1	1	1	1	1	1	1	1	0.5	0.5	0.1	0.1	0.1	];
Stim.Gen.Run	= [	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
Stim.Gen.Ena	= [	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
Stim.MCB	= [	2	1	1	1	1	1	1	1	1	1	1	1	1	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	2	1	1	1	1	1	1	1	1	1	1	];
Stim.Load1	= [	2	2	2	2	1	1	1	1	1	1	1	1	1	1	1	2	2	2	2	2	2	2	2	2	2	2	2	2	1	1	1	1	1	1	1	1	1	1	1	1	1	];
Stim.Load2	= [	2	2	2	1	1	1	1	1	1	1	1	1	1	1	1	1	1	2	2	2	2	2	2	2	2	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
Stim.Load3	= [	2	2	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];

% Fuel usage test
% Stim.Gen.s	= [	0	0	0	0	0	0	0.05	0.1	0.15	0.2	0.25	0.3	0.35	0.4	0.45	0.5	0.55	0.6	0.65	0.7	0.75	0.8	0.85	0.9	0.95	1	1.05	1.1	1.1	1.1	1.1	1.1	1.1	1.1	1.1	1.1	1.1	1.1	1.1	1.1	1.1	];
% Stim.Gen.Run	= [	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
% Stim.Gen.Ena	= [	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
% Stim.MCB	= [	2	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
% Stim.Load1	= [	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
% Stim.Load2	= [	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];
% Stim.Load3	= [	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	];


Stim.N = length(Stim.Gen.s);
Stim.Trep = Stim.N*Stim.Ts;
Stim.Dec = Stim.Trep/Ts/5000;