function [ kpp5 ] = calc_kpp5( res, seqi, comm, prices, id)
%CALC_KPP5 Summary of this function goes here
%   Detailed explanation goes here

iB.B101 =  1; iB.B104 =  2; iB.B109 =  3; iB.B106 =  4; iB.B110 =  5; iB.B114 =  6;
iB.B201 =  7; iB.B206 =  8; iB.B208 =  9; iB.B209 = 10; iB.B212 = 11; iB.B214 = 12;
iB.B216 = 13; iB.B217 = 14; iB.B219 = 15; iB.B301 = 16; iB.B305 = 17; iB.B307 = 18;
iB.B308 = 19; iB.B309 = 20; iB.B401 = 21; iB.B402 = 22; iB.B403 = 23;

iPQ = [id.CB101 id.CB104 id.CB109 id.CB106 id.CB110 id.CB114 ...
       id.CB201 id.CB206 id.CB208 id.CB209 id.CB212 id.CB214 id.CB216 id.CB217 id.CB219 ...
       id.CB301 id.CB305 id.CB307 id.CB308 id.CB309 ...
       id.CB401 id.CB402 id.CB403];

 test = [ones(1,10) zeros(1,4) ones(1,4) zeros(1,6) ones(1,13)];
 test = [test; test(end:-1:1)]';
   
%  testd1 = [test(1) test(1:end-1)];
%  testd2 = [test(1) test(1) test(1:end-2)];
%  testd3 = [test(1) test(1) test(1) test(1:end-3)];
%  testd4 = [test(1) test(1) test(1) test(1) test(1:end-4)];
%  testd5 = [test(1) test(1) test(1) test(1) test(1) test(1) test(1:end-5)];
% td = test;
% for i=1:5
%  td = [td; [test(i+1:end) test(end)*ones(1,i)] ];
% end; 
% tsum = sum(td,1);
% ax(1) = subplot(3,1,1); plot(test, '*');
% ax(2) = subplot(3,1,2); plot(td', '*');
% ax(3) = subplot(3,1,3); plot(tsum, '*');
% linkaxes(ax, 'x')
%warning('Temporarily remove Feeder4 as it had wrong data linked in simulink so far');
%iPQ(end-2:end) = [];

volt = res.voltage(:,iPQ);
sampthres = 5;
thres = 750;
vbad = zeros(size(volt));
cnt = zeros(size(volt));
chN = size(volt,2);
len = size(volt,1);
vbad(volt<thres) = 1;
   
for i=1:len
   cnt(i+1,:) = cnt(i,:).*vbad(i,:) + vbad(i,:);
end
outage = cnt;
for i=len:-1:1
   outage(i,:) = ((cnt(i,:)>0 & outage(i+1,:)>0) | cnt(i,:)>sampthres);
end

% detect start of each outage event
outage_event = diff(outage)>0;
outage_event_cnt = cumsum(outage_event,1);
outage_event_all = sum(outage_event_cnt,2);

cnt(1,:) = [];
outage(1,:) = [];

%%
% unwind
qVolt_unwind = cumsum((diff([res.quality_Volt(:,1:chN);res.quality_Volt(end,1:chN)])<-45000)*2^16) + res.quality_Volt(:,1:chN);
qHz_unwind = cumsum((diff([res.quality_Hz(:,1:chN);res.quality_Hz(end,1:chN)])<-45000)*2^16) + res.quality_Hz(:,1:chN);
qVolt_unwind = 0.01 * qVolt_unwind; % scaling in sl
qHz_unwind = 0.01 * qHz_unwind; % scaling in sl
% voltage quality
dif = [zeros(1,chN); diff(qVolt_unwind)].*(~outage);
dif(dif<0) = 0;
qVolt_outage = cumsum(dif);
% freq quality
dif = [zeros(1,chN); diff(qHz_unwind)].*(~outage);
dif(dif<0) = 0;
qHz_outage = cumsum(dif);

%%
t_per_class = [sum(qVolt_outage,2) sum(qHz_outage,2)];
dot_per_class = [-prices.P51 -prices.P52];          % $/(sek*PU) , $/(sek*Hz)
dot = repmat(dot_per_class, comm.M,1);              %  
d_cum_per_class = t_per_class.*dot;                     % $ values
legend_per_class = {'N_{PQV}*P_{51}[$]' 'N_{PQF}*P_{52}[$]'};
d_cum_total = max(sum(d_cum_per_class,2), -prices.KPP5_CAP);

clear( 'res', 'seqi', 'comm', 'prices', 'id', 'kpp3' );
kpp5=wsp2struct(who);


