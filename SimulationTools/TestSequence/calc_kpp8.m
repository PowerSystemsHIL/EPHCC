function [ kpp8 ] = calc_kpp8( kpp1, kpp2, kpp3, kpp4, kpp5, kpp6)
%CALC_KPP4 Summary of this function goes here
%   Detailed explanation goes here
 
d_cum_per_class = [kpp1.d_cum_total kpp2.d_cum_total  kpp3.d_cum_total  ...
                   kpp4.d_cum_total kpp5.d_cum_total  kpp6.d_cum_total ];
d_cum_total = sum(d_cum_per_class,2);

legend_per_class = {'KPP1' 'KPP2' 'KPP3' 'KPP4' 'KPP5' 'KPP6' 'KPP8'};

clear( 'kpp1', 'kpp2', 'kpp3', 'kpp4', 'kpp5', 'kpp6'  );
kpp8=wsp2struct(who);


