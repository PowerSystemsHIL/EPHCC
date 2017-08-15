function [ kpp4 ] = calc_kpp5( res, seqi, comm, prices, id)
%CALC_KPP4 Summary of this function goes here
%   Detailed explanation goes here

iB.B101 =  1; iB.B104 =  2; iB.B109 =  3; iB.B106 =  4; iB.B110 =  5; iB.B114 =  6;
iB.B201 =  7; iB.B206 =  8; iB.B208 =  9; iB.B209 = 10; iB.B212 = 11; iB.B214 = 12;
iB.B216 = 13; iB.B217 = 14; iB.B219 = 15; iB.B301 = 16; iB.B305 = 17; iB.B307 = 18;
iB.B308 = 19; iB.B309 = 20; iB.B401 = 21; iB.B402 = 22; iB.B403 = 23;

iPQ = [id.CB101 id.CB104 id.CB109 id.CB106 id.CB110 id.CB114 ...
       id.CB201 id.CB206 id.CB208 id.CB209 id.CB212 id.CB214 id.CB216 id.CB217 id.CB219 ...
       id.CB301 id.CB305 id.CB307 id.CB308 id.CB309 ...
       id.CB401 id.CB402 id.CB403];
   
   

clear( 'res', 'seqi', 'comm', 'prices', 'id', 'kpp3' );
kpp4=wsp2struct(who);


