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

function [ kpp8 ] = calc_kpp8( kpp1, kpp2, kpp3, kpp4, kpp5, kpp6, kpp7)
%CALC_KPP8 Summary of this function goes here
%   Detailed explanation goes here
 
d_cum_per_class = [kpp1.d_cum_total kpp2.d_cum_total  kpp3.d_cum_total  ...
                   kpp4.d_cum_total kpp5.d_cum_total  kpp6.d_cum_total ...
                   kpp7.d_cum_total];
d_cum_total = sum(d_cum_per_class,2);

legend_per_class = {'KPP1' 'KPP2' 'KPP3' 'KPP4' 'KPP5' 'KPP6' 'KPP7' 'KPP8'};

clear( 'kpp1', 'kpp2', 'kpp3', 'kpp4', 'kpp5', 'kpp6', 'kpp7'  );
kpp8=wsp2struct(who);


