function [ out ] = seq_gen_price( opt )
%GEN_PRICE Summary of this function goes here
%   Detailed explanation goes here
%IRRADIANCE Summary of this function goes here
%   Detailed explanation goes here


dur = opt.End;
start = 0;
pat1 = 0.01*[70	85	95	100	100	95	85	75	65	58	50	45	40	37	35	35	35	35	35	35	35];
t1 = [0:dur/(length(pat1)-1):dur];

t  = [0:opt.Ts:opt.End];
out = interp1(t1, pat1, t);

end