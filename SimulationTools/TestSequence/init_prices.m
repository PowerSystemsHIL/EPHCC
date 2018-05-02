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
% Author: Przemyslaw Koralewicz / NREL
% Date: 2017

function [ prices ] = init_prices(  )
%CALC_KPP1 Summary of this function goes here
%   Detailed explanation goes here

KPP1max = 7477.5;

%% KPP1
P11 = 1.00/3;
P12 = 0.90/3;
P13 = 0.85/3;

P15 = 4.50/3;
P16 = 2.25/3;
P17 = 1.00/3;

%% KPP2
P21 = 3.10;
P22 = 0.87;
P23 = 24.50;

%% KPP3
P31 = 0.35/4;
P32 = 1.00/4;
P33 = 0.50/4;

%% KPP4
P41 = 7.87;
P43 = 49.85;
P44 = 96.69;
P45 = 6.50;
P46 = 3.73;
P47 = 8.80;

%% KPP5
P51 = 4.88;
P52 = 0.49;
KPP5_CAP = KPP1max * 0.05;

%% KPP6
P61 = 1.87;

%% KPP7
P71 = 10.00;
P72 = 10.00;
P73 = 10.00;
P74 = 0.40;
P75 = 0.50; % Generators overcurrents
P76 = 0.05; % Trafos overcurrents
P77 = 0.005; % Line overcurrent
KPP7_CAP = KPP1max * 0.15;


prices=wsp2struct(who);