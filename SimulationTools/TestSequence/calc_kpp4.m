function [ kpp4 ] = calc_kpp4( res, seqi, comm, prices, id, kpp3)
%CALC_KPP4 Summary of this function goes here
%   Detailed explanation goes here


lim.kW_max = seqi.dms_kWref_nan + 0.02*10e3;
lim.kW_min = seqi.dms_kWref_nan - 0.02*10e3;
lim.kWHz_max =  seqi.dms_kWHzref_nan + 0.05*10e3;
lim.kWHz_min =  seqi.dms_kWHzref_nan - 0.05*10e3;;



clear( 'res', 'seqi', 'comm', 'prices', 'id', 'kpp3' );
kpp4=wsp2struct(who);


