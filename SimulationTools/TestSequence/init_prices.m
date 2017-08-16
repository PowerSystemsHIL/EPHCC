function [ prices ] = init_prices(  )
%CALC_KPP1 Summary of this function goes here
%   Detailed explanation goes here

%% KPP1
P11 = 1.00;
P12 = 0.90;
P13 = 0.85;

P15 = 4.50;
P16 = 2.25;
P17 = 1.00;

%% KPP2
P21 = 74.55;
P22 = 4.18;
P23 = 10.00;
P24 = 10.00;
P25 = 10.00;
P26 = 1.00;
P28 = 147.00;

%% KPP3
P31 = 0.35;
P32 = 1.00;
P33 = 0.50;

%% KPP4
P41 = 23.60;
P43 = 290.00;
P44 = 149.50;
P45 = 19.50;
P46 = 11.21;
P47 = 26.40;


prices=wsp2struct(who);