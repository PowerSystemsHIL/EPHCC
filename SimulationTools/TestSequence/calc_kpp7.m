function [ kpp7 ] = calc_kpp7( res, seqi, comm, prices, id )
%CALC_KPP1 Summary of this function goes here
%   Detailed explanation goes here

p_pv = [res.powerreal(:,id.CBPv1) 20*res.powerreal(:,id.CBPv2)];
e_pv = cumsum(p_pv*seqi.opt.Ts/3600);
brk_closed = bitand(1,res.breaker);
brkN = size(brk_closed,2);
transitions = [diff(brk_closed); zeros(1,brkN)];
sw_open  = zeros(comm.M,brkN);
sw_close = zeros(comm.M,brkN);
sw_open(transitions<0) = 1;
sw_close(transitions>0) = 1;
cb_switches = sum(sw_open(:,id.CB101:id.CB300),2);
gen1_start = sw_close(:,id.CBGen1);
gen2_start = sw_close(:,id.CBGen2);
gen3_start = sw_close(:,id.CBGen3);
gen_start = gen1_start + gen2_start + gen3_start;

%Calculate battery cycling
soc = res.battery_SoC./10000;
bat_cycle = [[0 0] ; cumsum(abs(diff(soc))) ];


%% Calculate overcurrents
oc(1)=struct('Type','Gen','Vn',13.8,'In',167.347904112935,'CB','CB151','ID','Gen1');
oc(2)=struct('Type','Gen','Vn',13.8,'In',146.429416098818,'CB','CB351','ID','Gen2');
oc(3)=struct('Type','Gen','Vn',0.48,'In',96.2250448649376,'CB','CB451','ID','Gen3');
oc(4)=struct('Type','Line','Vn',13.8,'In',280,'CB','CB100','ID','C100');
oc(5)=struct('Type','Line','Vn',13.8,'In',280,'CB','CB200','ID','C200');
oc(6)=struct('Type','Line','Vn',13.8,'In',280,'CB','CB300','ID','C300');
oc(7)=struct('Type','Line','Vn',0.48,'In',560,'CB','CB109','ID','C108');
oc(8)=struct('Type','Line','Vn',13.8,'In',280,'CB','CB106','ID','C106');
oc(9)=struct('Type','Line','Vn',4.16,'In',560,'CB','CB111','ID','C107');
oc(10)=struct('Type','Line','Vn',13.8,'In',280,'CB','CB101','ID','C101');
oc(11)=struct('Type','Line','Vn',13.8,'In',280,'CB','CB102','ID','C102');
oc(12)=struct('Type','Line','Vn',13.8,'In',160,'CB','CB103','ID','C103');
oc(13)=struct('Type','Line','Vn',13.8,'In',280,'CB','CB112','ID','C104');
oc(14)=struct('Type','Line','Vn',0.48,'In',560,'CB','CB113','ID','C109');
oc(15)=struct('Type','Line','Vn',13.8,'In',160,'CB','CB201','ID','C201');
oc(16)=struct('Type','Line','Vn',13.8,'In',280,'CB','CB202','ID','C202');
oc(17)=struct('Type','Line','Vn',13.8,'In',280,'CB','CB203','ID','C203');
oc(18)=struct('Type','Line','Vn',0.48,'In',560,'CB','CB213','ID','C206');
oc(19)=struct('Type','Line','Vn',0.48,'In',560,'CB','CB216','ID','C204');
oc(20)=struct('Type','Line','Vn',0.48,'In',560,'CB','CB217','ID','C205');
oc(21)=struct('Type','Line','Vn',0.48,'In',560,'CB','CB213','ID','C206');
oc(22)=struct('Type','Line','Vn',13.8,'In',280,'CB','CB301','ID','C301');
oc(23)=struct('Type','Line','Vn',13.8,'In',320,'CB','CB302','ID','C304');
oc(24)=struct('Type','Line','Vn',13.8,'In',160,'CB','CB303','ID','C302');
oc(25)=struct('Type','Line','Vn',13.8,'In',280,'CB','CB304','ID','C303');
oc(26)=struct('Type','Line','Vn',13.8,'In',280,'CB','CB310','ID','C305');
oc(27)=struct('Type','Line','Vn',0.48,'In',280,'CB','CB401','ID','C401');
oc(28)=struct('Type','Line','Vn',0.48,'In',320,'CB','CB452','ID','C403');
oc(29)=struct('Type','Line','Vn',0.48,'In',130,'CB','CB453','ID','C404');
oc(30)=struct('Type','Trafo','Vn',13.8,'In',104.592440070584,'CB','CB105','ID','T102');
oc(31)=struct('Type','Trafo','Vn',13.8,'In',156.888660105877,'CB','CB106','ID','T102');
oc(32)=struct('Type','Trafo','Vn',4.16,'In',277.572244802705,'CB','CB110','ID','T104');
oc(33)=struct('Type','Trafo','Vn',13.8,'In',104.592440070584,'CB','CB112','ID','T107');
oc(34)=struct('Type','Trafo','Vn',13.8,'In',104.592440070584,'CB','CB205','ID','T201');
oc(35)=struct('Type','Trafo','Vn',13.8,'In',156.888660105877,'CB','CB207','ID','T203');
oc(36)=struct('Type','Trafo','Vn',13.8,'In',209.184880141169,'CB','CB211','ID','T207');
oc(37)=struct('Type','Trafo','Vn',13.8,'In',104.592440070584,'CB','CB209','ID','T206');
oc(38)=struct('Type','Trafo','Vn',13.8,'In',41.8369760282337,'CB','CB210','ID','T210');
oc(39)=struct('Type','Trafo','Vn',13.8,'In',83.6739520564675,'CB','CB214','ID','T208');
oc(40)=struct('Type','Trafo','Vn',13.8,'In',83.6739520564675,'CB','CB215','ID','T209');
oc(41)=struct('Type','Trafo','Vn',13.8,'In',83.6739520564675,'CB','CB305','ID','T301');
oc(42)=struct('Type','Trafo','Vn',13.8,'In',83.6739520564675,'CB','CB306','ID','T302');
oc(43)=struct('Type','Trafo','Vn',13.8,'In',41.8369760282337,'CB','CB302','ID','T303');
oc(44)=struct('Type','Trafo','Vn',13.8,'In',104.592440070584,'CB','CB304','ID','T305');
oc(45)=struct('Type','Trafo','Vn',13.8,'In',209.184880141169,'CB','CB310','ID','T306');
oc(46)=struct('Type','Line','Vn',13.8,'In',280,'CB','CB108','ID','C105');


LegendGen = {};
LegendLine = {};
LegendTrafo = {};

for i=1:length(oc)
   iCB(i) = eval(['id.' oc(i).CB]);     
   Vn(i) = oc(i).Vn;
   In(i) = oc(i).In;
   IsTrafo(i) = strcmp(oc(i).Type,'Trafo');
   IsGen(i) = strcmp(oc(i).Type,'Gen');
   IsLine(i) = strcmp(oc(i).Type,'Line');
   if IsTrafo(i)
       LegendTrafo(length(LegendTrafo)+1) = {oc(i).ID};
   end;
   if IsLine(i)
       LegendLine(length(LegendLine)+1) = {oc(i).ID};
   end;
   if IsGen(i)
       LegendGen(length(LegendGen)+1) = {oc(i).ID};
   end;
end

voltPU = res.voltage(:,iCB)./1000;
p = res.powerreal(:,iCB);
q = res.reactivepower(:,iCB);
s = sqrt(p.^2+q.^2);

voltPU(voltPU<0.01) = 0.01;
volt = voltPU.*repmat(Vn,comm.M,1);

cur = s/3./(volt/sqrt(3));
curPU = cur./repmat(In,comm.M,1);

dcurGen =  (curPU(:,IsGen) - 1);
dcurTrafo = (curPU(:,IsTrafo) - 1);
dcurLine = (curPU(:,IsLine) - 1);
dcurGen(dcurGen<0) = 0;
dcurTrafo(dcurTrafo<0) = 0;
dcurLine(dcurLine<0) = 0;

dGen =  dcurGen.^2;
dTrafo = dcurTrafo.^2;
dLine = dcurLine.^2;

d_cum_Gen   = res.Speed * cumsum(sum(dGen,2));
d_cum_Trafo = res.Speed * cumsum(sum(dTrafo,2));
d_cum_Line  = res.Speed * cumsum(sum(dLine,2));

%%
u_cum_per_class = [cumsum(gen_start) bat_cycle cumsum(cb_switches) d_cum_Gen d_cum_Trafo d_cum_Line];
dot_per_class = [-prices.P71 -prices.P73 -prices.P73 -prices.P74 -prices.P75 -prices.P76 -prices.P77];          % $/(sek*PU) , $/(sek*Hz)
dot = repmat(dot_per_class, comm.M,1);              %  
d_cum_per_class = u_cum_per_class .* dot;
legend_per_class = {'Gen starts', 'ESS1 cycles', 'ESS2cycles', 'CB switch', 'Gen OC', 'Trafo OC', 'Line OC'};
d_cum_total_uncapped = sum(d_cum_per_class,2);
d_cum_total = max(d_cum_total_uncapped, -prices.KPP7_CAP);

clear( 'res', 'seqi', 'comm', 'prices' );
kpp7=wsp2struct(who);


