function [ kpp7 ] = calc_kpp7( res, seqi, comm, prices, id )
%CALC_KPP1 Summary of this function goes here
%   Detailed explanation goes here

p_pv = [res.powerreal(:,id.CBPv1) 20*res.powerreal(:,id.CBPv2)];
e_pv = cumsum(p_pv*seqi.opt.Ts/3600);

d_cum_total = zeros(comm.M,1);

clear( 'res', 'seqi', 'comm', 'prices' );
kpp7=wsp2struct(who);


