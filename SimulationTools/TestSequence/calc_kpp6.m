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

function [ kpp6 ] = calc_kpp6( res, seqi, comm, prices, kpp4 )
%CALC_KPP1 Summary of this function goes here
%   Detailed explanation goes here

soc = res.battery_SoC * 100 / 10000;

t_under = zeros(comm.M,2);
not_island = (~kpp4.planned_island) & (~kpp4.unplanned_island);

lim = nan*ones(comm.M,1);
lim(not_island) = 40;
t_under( (soc<40) & repmat(not_island,1,2) ) = 1;
dot = -prices.P61;     % dot $/min
d_per_class = res.Speed * t_under.*dot.*seqi.opt.Ts/60;                         % $ values
d_cum_per_class = cumsum(d_per_class);
t_cum_under = d_cum_per_class ./ dot;
legend_per_class = {'ESS1' 'ESS2'};
d_cum_total = sum(d_cum_per_class,2);


clear( 'res', 'seqi', 'comm', 'prices', 'kpp4' );
kpp6=wsp2struct(who);


