f = 60; % Hz
sys_w = 2*pi*f; % rad/s
ft2mi = 1.0/5280.0; %mi/ft
[alphax,alphay] = pol2cart(-120*pi/180,1);
alpha = alphax+1j*alphay;

R1_cable11 = 0.2685;    % ohms/mi
X1_cable11 = 0.207;     % ohms/mi
R0_cable11 = 2.1408;     % ohms/mi
X0_cable11 = 1.582;     % ohms/mi
B_cable11 = 308.7587e-6;     % S/mi
L0_cable11 = X0_cable11/sys_w;    % H/mi
L1_cable11 = X1_cable11/sys_w;    % H/mi
C0_cable11 = B_cable11/sys_w;   % F/mi

R1_cable13 = 0.1206;    % ohms/mi
X1_cable13 = 0.1878;    % ohms/mi
R0_cable13 = 1.8354;    % ohms/mi
X0_cable13 = 1.2165;    % ohms/mi
B_cable13 = 384.0177e-6;    % S/mi
L0_cable13 = X0_cable13/sys_w;    % H/mi
L1_cable13 = X1_cable13/sys_w;    % H/mi
C0_cable13 = B_cable13/sys_w;    % F/mi

%    # Utility

l_U_L2 = 500.0*ft2mi;    % mi


%     # Feeder1

l_F1L1 = 1800.0*ft2mi;    % mi
l_F1L2 = 5500.0*ft2mi;    % mi
l_F1L3 = 1000.0*ft2mi;    % mi
l_F1L4 = 3000.0*ft2mi;    % mi
l_F1L5 = 3000.0*ft2mi;    % mi
l_F1L6 = 1500.0*ft2mi;    % mi
l_F1L7 = 2000.0*ft2mi;    % mi
l_F1L8 = 1000.0*ft2mi;    % mi
l_F1L9 = 2000.0*ft2mi;    % mi
l_F1DG = 2000.0*ft2mi;    % mi



A = [1,1,1; 1,alpha^2,alpha; 1,alpha,alpha^2];

Rabc11 = A*diag([R0_cable11;R1_cable11;R1_cable11])/A;
Xabc11 = A*diag([X0_cable11;X1_cable11;X1_cable11])/A;

Rabc13 = A*diag([R0_cable13;R1_cable13;R1_cable13])/A;
Xabc13 = A*diag([X0_cable13;X1_cable13;X1_cable13])/A;

Zabc11 = Rabc11+1j*Xabc11;
Zabc13 = Rabc13+1j*Xabc13;

Z11 = Zabc11(1,1)
Z13 = Zabc13(1,1)

Z1to2 = l_U_L2*Z13;
Z2to3 = l_F1L1*Z13;
Z2to7 = l_F1L2*Z13;
Z2to15 = l_F1L3*Z13;
Z15to17 = l_F1L4*Z13;
Z7to8 = l_F1L5*Z13;
Z7to10 = l_F1L6*Z13;
Z11to14 = l_F1L7*Z13;
Z5to6 = l_F1L8*Z13;
Z18to19 = l_F1L9*Z13;
Z15to16 = l_F1DG*Z11;

Zb1 = (13800^2)/3.75e6;
Zb2 = (480^2)/3.75e6;
Zb3 = (208^2)/3.75e6;
Zb4 = (4160^2)/3.75e6;

% ZlinesPU = zeros(19,19);

Z1to2PU = Z1to2/Zb1;
Z2to3PU = Z2to3/Zb1;
Z2to7PU = Z2to7/Zb1;
Z2to15PU = Z2to15/Zb1;
Z15to17PU = Z15to17/Zb1;
Z7to8PU = Z7to8/Zb1;
Z7to10PU = Z7to10/Zb1;
Z11to14PU = Z11to14/Zb4;
Z5to6PU = Z5to6/Zb2;
Z18to19PU = Z18to19/Zb2;
Z15to16PU = Z15to16/Zb1;

Sn_500kVA_1 = 500.0e3;    % VA
V1_500kVA_1 = 13800.0;    % V
V2_500kVA_1 = 480.0;    % V
Z_500kVA_1 = 5.0/100.0;    % pu
Z_ratio_500kVA_1 = 4.9;
Rm_500kVA_1 = 1e5/3;
Lm_500kVA_1 = 200/3;
R_500kVA_1 = Z_500kVA_1/sqrt(1.0+Z_ratio_500kVA_1^2.0);   % pu
X_500kVA_1 = Z_ratio_500kVA_1*R_500kVA_1;    % pu
G_500kVA_1 = 1/(Rm_500kVA_1/((V1_500kVA_1^2)/3.75e6));
B_500kVA_1 = 1/((sys_w*Lm_500kVA_1)/((V1_500kVA_1^2)/3.75e6));

Sn_500kVA_2       = 500.0e3;    % VA
V1_500kVA_2       = 13800.0;    % V
V2_500kVA_2       = 208.0;    % V
Z_500kVA_2        = 5.0/100.0;    % pu
Z_ratio_500kVA_2 = 4.9;
Rm_500kVA_2 = 1e5/3;
Lm_500kVA_2 = 200/3;
R_500kVA_2 = Z_500kVA_2/sqrt(1.0+Z_ratio_500kVA_2^2.0);    % pu
X_500kVA_2 = Z_ratio_500kVA_2*R_500kVA_2;    % pu
G_500kVA_2 = 1/(Rm_500kVA_2/((V1_500kVA_2^2)/3.75e6));
B_500kVA_2 = 1/((sys_w*Lm_500kVA_2)/((V1_500kVA_2^2)/3.75e6));

Sn_2MVA_1       = 2000.0e3;    % VA
V1_2MVA_1       = 4160.0;    % V
V2_2MVA_1       = 480.0;    % V
Z_2MVA_1        = 5.75/100.0;    % pu
Z_ratio_2MVA_1 = 5.7;
Rm_2MVA_1 = 1e5/3;
Lm_2MVA_1 = 200/3;
R_2MVA_1 = Z_2MVA_1/sqrt(1.0+Z_ratio_2MVA_1^2.0);    % pu
X_2MVA_1 = Z_ratio_2MVA_1*R_2MVA_1;    % pu
G_2MVA_1 = 1/(Rm_2MVA_1/((V1_2MVA_1^2)/3.75e6));
B_2MVA_1 = 1/((sys_w*Lm_2MVA_1)/((V1_2MVA_1^2)/3.75e6));

Sn_2500kVA_1       = 2500.0e3;    % VA
V1_2500kVA_1       = 13800.0;    % V
V2_2500kVA_1       = 480.0;    % V
Z_2500kVA_1        = 5.56/100.0;    % pu
Z_ratio_2500kVA_1 = 5.52;
Rm_2500kVA_1 = 1e5/3;
Lm_2500kVA_1 = 200/3;
R_2500kVA_1 = Z_2500kVA_1/sqrt(1.0+Z_ratio_2500kVA_1^2.0);    % pu
X_2500kVA_1 = Z_ratio_2500kVA_1*R_2500kVA_1;    % pu
G_2500kVA_1 = 1/(Rm_2500kVA_1/((V1_2500kVA_1^2)/3.75e6));
B_2500kVA_1 = 1/((sys_w*Lm_2500kVA_1)/((V1_2500kVA_1^2)/3.75e6));

Sn_2500kVA_2       = 2500.0e3;    % VA
V1_2500kVA_2       = 13800.0;    % V
V2_2500kVA_2       = 480.0;    % V
Z_2500kVA_2        = 5.75/100.0;    % pu
Z_ratio_2500kVA_2 = 6.6;
Rm_2500kVA_2 = 1e5/3;
Lm_2500kVA_2 = 200/3;
R_2500kVA_2 = Z_2500kVA_2/sqrt(1.0+Z_ratio_2500kVA_2^2.0);    %pu
X_2500kVA_2 = Z_ratio_2500kVA_2*R_2500kVA_2;    % pu
G_2500kVA_2 = 1/(Rm_2500kVA_2/((V1_2500kVA_2^2)/3.75e6));
B_2500kVA_2 = 1/((sys_w*Lm_2500kVA_2)/((V1_2500kVA_2^2)/3.75e6));

Sn_3750kVA       = 3750.0e3;    % VA
V1_3750kVA       = 13800.0;    % V
V2_3750kVA       = 4160.0;    % V
Z_3750kVA        = 4.75/100.0;    % pu
Z_ratio_3750kVA = 11.4;
Rm_3750kVA = 1e5/3; %division by 3 to change from delta to wye
Lm_3750kVA = 200/3;
R_3750kVA = Z_3750kVA/sqrt(1.0+Z_ratio_3750kVA^2.0);    % pu
X_3750kVA = Z_ratio_3750kVA*R_3750kVA;    % pu
G_3750kVA = 1/(Rm_3750kVA/((V1_3750kVA^2)/3.75e6));
B_3750kVA = 1/((sys_w*Lm_3750kVA)/((V1_3750kVA^2)/3.75e6));

Zt3to4PU = R_500kVA_1+1j*X_500kVA_1;
Zt7to9PU = R_500kVA_2+1j*X_500kVA_2;
Zt11to13PU = R_2MVA_1+1j*X_2MVA_1;
Zt11to12PU = R_2MVA_1+1j*X_2MVA_1;
Zt3to5PU = R_2500kVA_1+1j*X_2500kVA_1;
Zt17to18PU = R_2500kVA_2+1j*X_2500kVA_2;
Zt10to11PU = R_3750kVA+1j*X_3750kVA;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%% Create the branch impedance matrix %%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The first column is the Bus from which the branch starts
% The second column is the Bus where the branch arrives
% The third column is the resistance of the branch [pu]
% The fourth column is the reactance of the branch [pu]
% The fifth column is the branch conductance [pu]
% The sixth column is the branch admitance [pu]

Branch = zeros(18,6);
Branch(1,:) = [1,2,real(Z1to2PU),imag(Z1to2PU),0,0];
Branch(2,:) = [2,3,real(Z2to3PU),imag(Z2to3PU),0,0];
Branch(3,:) = [2,7,real(Z2to7PU),imag(Z2to7PU),0,0];
Branch(4,:) = [2,15,real(Z2to15PU),imag(Z2to15PU),0,0];
Branch(5,:) = [3,4,real(Zt3to4PU),imag(Zt3to4PU),G_500kVA_1,B_500kVA_1];
Branch(6,:) = [3,5,real(Zt3to5PU),imag(Zt3to5PU),G_2500kVA_1,B_2500kVA_1];
Branch(7,:) = [5,6,real(Z5to6PU),imag(Z5to6PU),0,0];
Branch(8,:) = [7,8,real(Z7to8PU),imag(Z7to8PU),0,0];
Branch(9,:) = [7,9,real(Zt7to9PU),imag(Zt7to9PU),G_500kVA_2,B_500kVA_2];
Branch(10,:) = [7,10,real(Z7to10PU),imag(Z7to10PU),0,0];
Branch(11,:) = [10,11,real(Zt10to11PU),imag(Zt10to11PU),G_3750kVA,B_3750kVA];
Branch(12,:) = [11,12,real(Zt11to12PU),imag(Zt11to12PU),G_2MVA_1,B_2MVA_1];
Branch(13,:) = [11,13,real(Zt11to13PU),imag(Zt11to13PU),G_2MVA_1,B_2MVA_1];
Branch(14,:) = [11,14,real(Z11to14PU),imag(Z11to14PU),0,0];
Branch(15,:) = [15,16,real(Z15to16PU),imag(Z15to16PU),0,0];
Branch(16,:) = [15,17,real(Z15to17PU),imag(Z15to17PU),0,0];
Branch(17,:) = [17,18,real(Zt17to18PU),imag(Zt17to18PU),G_2500kVA_2,B_2500kVA_2];
Branch(18,:) = [18,19,real(Z18to19PU),imag(Z18to19PU),0,0];

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%% Calculates Constant Impedance loads %%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% The column number one is the bus where the load is connected
% The column number two is the real power at that bus at rated voltage [MW]
% The column number three is the reactive power at that bus at rated
% voltage [MVAr]

Load = zeros(10,3);

Load(1,:) = [4,0.3*0.9,0.3*sin(acos(0.9))];
Load(2,:) = [5,1.2*0.9,1.2*sin(acos(0.9))];
Load(3,:) = [6,0.05*0.9,0.05*sin(acos(0.9))];
Load(4,:) = [8,0.05*0.9,0.05*sin(acos(0.9))];
Load(5,:) = [9,0.25*0.9,0.25*sin(acos(0.9))];
Load(6,:) = [12,1.5*0.9,1.5*sin(acos(0.9))];
Load(7,:) = [13,1.0*0.9,1.0*sin(acos(0.9))];
Load(8,:) = [13,0.149*0.9,0.149*sin(acos(0.9))];
Load(9,:) = [14,0.05*0.9,0.05*sin(acos(0.9))];
Load(10,:) = [19,0.05*0.9,0.05*sin(acos(0.9))];

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%% Calculates Trafo shunt resistance losses %%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Column 1 is the bus where the resistance losses happen
% Column 2 is the power loss in the resistors at nominal voltage [MW]

Trafo_sh_loss = zeros(5,2);

Trafo_sh_loss(1,:) = [3,2*5.7e3/1e6];
Trafo_sh_loss(2,:) = [7,5.7e3/1e6];
Trafo_sh_loss(3,:) = [10,5.7e3/1e6];
Trafo_sh_loss(4,:) = [11,2*519/1e6];
Trafo_sh_loss(5,:) = [17,5.7e3/1e6];


% Y = zeros(19,19);
% 
% for i=1:(size(Branch,1)+1)
%     x = find(Branch(:,1)==i);
%     for k=1:size(x,1)
%         Y(Branch(x(k),1),Branch(x(k),2)) = -Branch(x(k),3);
%         Y(Branch(x(k),2),Branch(x(k),1)) = -Branch(x(k),3);
%     end
%     Y(i,i) = -sum(Y(i,:));
% end
% 
% 
% rY = real(Y);
% iY = imag(Y);
