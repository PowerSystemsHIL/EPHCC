function [ kpp1 ] = calc_kpp1( res, seqi, comm, prices )
%CALC_KPP1 Summary of this function goes here
%   Detailed explanation goes here

iF1 = [1 2       9           17 18];
iF2 = [3 4 5     10 11 12    19 20];
iF3 = [6         13 14       21 22];
iF4 = [7 8       15 16       23 24 25];

iI = [1:8];
iP = [9:16];
iC = [17:25];
iM = [26:27];

P(:,[iF1 iF2 iF3])  = res.misc_1(:,[iF1 iF2 iF3]);
P(:,iF4)            = res.misc_1(:,[iF4])* 20;
P(:,iM)             = res.motor(:,[1 5]);

N = 50;
M = length(P(:,1));

%% Demands
Demand = [300   250     300     600     400     600     20*15   20*20 ...       % Interruptable
          1000  1000    1000    600     700     1000    20*10   20*10 ...       % Priority
          1200  1500    1000    1000    1000    800     20*25   20*20   20*3 ...% Critical
          200   200];                                                            % Motors
D = repmat(Demand, M, 1);
D(:,iM(1)) = D(:,iM(1)).*seqi.motor1;
D(:,iM(2)) = D(:,iM(2)).*seqi.motor2;

TotalDemand = sum(Demand);

%% Calculate power

P_good = zeros(M,N);
P_good(P>(D./2)) = P(P>(D./2));

P_outage = zeros(M,N);
P_outage(P<(D./2)) = D(P<(D./2));

P_good_per_class = zeros(M,4);
P_outage_per_class = zeros(M,4);
P_good_per_class(:,1) = sum(P_good(:,iM),2);
P_good_per_class(:,2) = sum(P_good(:,iI),2);
P_good_per_class(:,3) = sum(P_good(:,iP),2);
P_good_per_class(:,4) = sum(P_good(:,iC),2);
P_outage_per_class(:,1) = sum(P_outage(:,iM),2);
P_outage_per_class(:,2) = sum(P_outage(:,iI),2);
P_outage_per_class(:,3) = sum(P_outage(:,iP),2);
P_outage_per_class(:,4) = sum(P_outage(:,iC),2);

E = cumsum(P*seqi.opt.Ts/3600);
E_good_per_class = cumsum(P_good_per_class*seqi.opt.Ts/3600);
EO_per_class = cumsum(P_outage_per_class*seqi.opt.Ts/3600);

EP_per_class = E_good_per_class .* repmat([prices.P12 prices.P13 prices.P12 prices.P11],M,1);
EOP_per_class = EO_per_class .* repmat([prices.P16 0 prices.P16 prices.P15],M,1);

d_cum_total = sum([EP_per_class -EOP_per_class],2);

clear( 'res', 'seqi', 'comm', 'prices' );
kpp1=wsp2struct(who);


