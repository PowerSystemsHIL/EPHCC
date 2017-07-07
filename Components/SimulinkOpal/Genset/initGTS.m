
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
TestSystemGenPath  = 'NREL_Diesel_Genset_Test_System/SM_Master/Diesel_Generator/GenSet';
TestSystemCtrlPath = 'NREL_Diesel_Genset_Test_System/SM_Master/Diesel_Generator/SimGenCtrl';
switch GenSelect
    case '80kW'
        set_param(TestSystemGenPath,  'GenSel', '80kVA diesel generator');
        set_param(TestSystemCtrlPath, 'GenSel', '80kVA diesel generator');
        GenPN = 100e3;
        GenVN = 480;
    case '80kVA'
        set_param(TestSystemGenPath,  'GenSel', '80kVA diesel generator');
        set_param(TestSystemCtrlPath, 'GenSel', '80kVA diesel generator');
        GenPN = 100e3;
        GenVN = 480;
    case '4MW'
        set_param(TestSystemGenPath,  'GenSel', '4MVA diesel generator');
        set_param(TestSystemCtrlPath, 'GenSel', '4MVA diesel generator');
        GenPN = 4e6;
        GenVN = 13800;
    case '4MVA'
        set_param(TestSystemGenPath,  'GenSel', '4MVA diesel generator');
        set_param(TestSystemCtrlPath, 'GenSel', '4MVA diesel generator');
        GenPN = 4e6;
        GenVN = 13800;
    case '3.5MVA NG'
        set_param(TestSystemGenPath,  'GenSel', '3.5MVA natural gas generator');
        set_param(TestSystemCtrlPath, 'GenSel', '3.5MVA natural gas generator');
        GenPN = 3.5e6;
        GenVN = 13800;
end;
