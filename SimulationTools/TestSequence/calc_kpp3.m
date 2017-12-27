function [ kpp3 ] = calc_kpp3( res, seqi, comm, prices , id)
%CALC_KPP1 Summary of this function goes here
%   Detailed explanation goes here


pcc.p=res.powerreal(:,id.CB100) + res.powerreal(:,id.CB200) + res.powerreal(:,id.CB300);
pcc.e=cumsum(pcc.p*seqi.opt.Ts/3600);
pcc.q=res.reactivepower(:,id.CB100)+res.reactivepower(:,id.CB200)+res.reactivepower(:,id.CB300);
pcc.s= sqrt( pcc.p.^2 + pcc.q.^2 );

pcc.ang = zeros(comm.M,1);
use_tan = (pcc.s > 10 & abs(pcc.p) > abs(pcc.q));
use_ctg = (pcc.s > 10 & abs(pcc.p) < abs(pcc.q));
pcc.ang(use_tan) = atan(pcc.q(use_tan)./pcc.p(use_tan))/pi*180;
pcc.ang(use_tan & pcc.p<0) = pcc.ang(use_tan & pcc.p<0) + 180;
pcc.ang(use_ctg) = acot(pcc.p(use_ctg)./pcc.q(use_ctg))/pi*180;
pcc.ang(use_ctg & pcc.p<0) = pcc.ang(use_ctg & pcc.p<0) + 180;

pcc.pf= cos(pcc.ang);

lim.p_max = 12000 * ones(comm.M,1);
lim.p_min = -6000 * ones(comm.M,1);
lim.q_max =  5000 * ones(comm.M,1);
lim.q_min = -5000 * ones(comm.M,1);

%% Active power vs limits split
p_imp       = zeros(comm.M,1);
p_imp_over  = zeros(comm.M,1);
p_exp       = zeros(comm.M,1);
p_exp_over  = zeros(comm.M,1);

exp = pcc.p>0;
imp = pcc.p<0;
p_imp(exp & pcc.p>lim.p_max(1)) = lim.p_max(1);
p_imp(exp & pcc.p<lim.p_max(1)) = pcc.p(exp & pcc.p<lim.p_max(1));
p_imp_over(exp & pcc.p>lim.p_max(1)) = pcc.p(exp & pcc.p>lim.p_max(1)) - lim.p_max(1);

p_exp(imp & pcc.p<lim.p_min(1)) = lim.p_max(1);
p_exp(imp & pcc.p>lim.p_min(1)) = pcc.p(imp & pcc.p>lim.p_min(1));
p_exp_over(imp & pcc.p<lim.p_min(1)) = pcc.p(imp & pcc.p<lim.p_min(1)) + lim.p_min(1);

p_per_class = [ p_exp_over p_exp p_imp p_imp_over]; % [kW]

%% Reactive power vs limits split
q_imp       = zeros(comm.M,1);
q_imp_over  = zeros(comm.M,1);
q_exp       = zeros(comm.M,1);
q_exp_over  = zeros(comm.M,1);

exp = pcc.q>0;
imp = pcc.q<0;
q_imp(exp & pcc.q>lim.q_max(1)) = lim.q_max(1);
q_imp(exp & pcc.q<lim.q_max(1)) = pcc.q(exp & pcc.q<lim.q_max(1));
q_imp_over(exp & pcc.q>lim.q_max(1)) = pcc.q(exp & pcc.q>lim.q_max(1)) - lim.q_max(1);

q_exp(imp & pcc.q<lim.q_min(1)) = lim.q_max(1);
q_exp(imp & pcc.q>lim.q_min(1)) = pcc.q(imp & pcc.q>lim.q_min(1));
q_exp_over(imp & pcc.q<lim.q_min(1)) = pcc.q(imp & pcc.q<lim.q_min(1)) + lim.q_min(1);

q_per_class = [ q_exp_over q_exp q_imp q_imp_over]; % [kW]

pq_per_class = [p_per_class q_per_class(:,1)-q_per_class(:,4)];

doe_coefs_per_class = [ -prices.P32*[0.5 1 1 3] prices.P33 ]; % [$ / kWh]
doe = zeros(comm.M, 5);
doe(:,1:4) = repmat(doe_coefs_per_class(1:4), comm.M, 1) .* repmat(seqi.price, 1, 4);
doe(:,5)   = doe_coefs_per_class(5)*ones(comm.M, 1);

d_per_class = res.Speed * pq_per_class * seqi.opt.Ts / 3600 .* doe;
e_per_class = res.Speed * cumsum(pq_per_class * seqi.opt.Ts / 3600);
d_cum_per_class = cumsum(d_per_class);
doe_per_class = d_cum_per_class ./ e_per_class;
legend_per_class = {'E_{BO}' 'E_{B}' 'E_{E}' 'E_{EO}' 'E_{RP}'};

d_cum_total = sum(d_cum_per_class,2);

clear( 'res', 'seqi', 'comm', 'prices', 'id' );
kpp3=wsp2struct(who);


