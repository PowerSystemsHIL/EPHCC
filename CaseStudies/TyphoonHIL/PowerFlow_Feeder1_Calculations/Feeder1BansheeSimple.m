function mpc = Feeder1BansheeSimple
% Power Flow calculation of Feeder 1 from Banshee model. Transmission lines
% are considered simple RL loads, WITHOUT shunt capacitances and mutual
% coupling. Impedance from core coupling and snubbers ARE NOT considered.
%Shunt resistors for measurement units ARE NOT considered. Shunt losses of
% the transformers ARE considered (resistive and inductive).

%% MATPOWER Case Format : Version 2
mpc.version = '2';

%%-----  Power Flow Data  -----%%
%% system MVA base
mpc.baseMVA = 3.75;

%% bus data
%	bus_i	type	Pd	Qd	Gs	Bs	area	Vm	Va	baseKV	zone	Vmax	Vmin
mpc.bus = [
	1	3	0	0	0.00	0.00	1	1	0	13.8	1	1.10	0.90;
	2	1	0	0	0.00	0.00	1	1	0	13.8	1	1.10	0.90;
	3	1	0	0	0.0114	0.00	1	1	0	13.8	1	1.10	0.90; %Pd is the resistive shunt loss of the trafo (x2)
	4	1	0	0	0.27	-0.1308	1	1	0	0.48	1	1.10	0.90; %Pd and Qd are the power of the shunt load
	5	1	0	0	1.08	-0.5231	1	1	0	0.48	1	1.10	0.90; %Pd and Qd are the power of the shunt load
	6	1	0	0	0.045	-0.0218	1	1	0	0.48	1	1.10	0.90; %Pd and Qd are the power of the shunt load
	7	1	0	0	0.0057	0.00	1	1	0	13.8	1	1.10	0.90; %Pd is the resistive shunt loss of the trafo
	8	1	0	0	0.045	-0.0218	1	1	0	13.8	1	1.10	0.90; %Pd and Qd are the power of the shunt load
	9	1	0	0	0.225	-0.109	1	1	0	0.208	1	1.10	0.90; %Pd and Qd are the power of the shunt load
	10	1	0	0	0.0057	0.00	1	1	0	13.8	1	1.10	0.90; %Pd is the resistive shunt loss of the trafo
	11	1	0	0	0.001	0.00	1	1	0	4.16	1	1.10	0.90; %Pd is the resistive shunt loss of the trafo (x2)
	12	1	0	0	1.35	-0.6538	1	1	0	0.48	1	1.10	0.90; %Pd and Qd are the power of the shunt load
	13	1	0	0	1.0341	-0.5008	1	1	0	0.48	1	1.10	0.90; %Pd and Qd are the power of the shunt load
	14	1	0	0	0.045	-0.0218	1	1	0	0.48	1	1.10	0.90; %Pd and Qd are the power of the shunt load
	15	1	0	0	0.04	0.00	1	1	0	13.8	1	1.10	0.90;
	16	2	0	0	0.04	0.00	1	1	0	13.8	1	1.10	0.90;
	17	1	0	0	0.0057	0.00	1	1	0	13.8	1	1.10	0.90; %Pd is the resistive shunt loss of the trafo
	18	1	0	0	0.00	0.00	1	1	0	0.48	1	1.10	0.90;
	19	1	0	0	0.045	-0.0218	1	1	0	0.48	1	1.10	0.90; %Pd and Qd are the power of the shunt load
];

%% generator data
%	bus	Pg	Qg	Qmax	Qmin	Vg	mBase	status	Pmax	Pmin	Pc1	Pc2	Qc1min	Qc1max	Qc2min	Qc2max	ramp_agc	ramp_10	ramp_30	ramp_q	apf
mpc.gen = [
    1   0   0   30  -30 1   100 1   100 0   0   0   0   0   0   0   0   0   0   0   0;
	16	1.5 0	2.0	-2.0	1	4	1	4	0	0	0	0	0	0	0	0	0	0	0	0;
];

%% branch data
%	fbus	tbus	r	x	b	rateA	rateB	rateC	ratio	angle	status	angmin	angmax
mpc.branch = [
	1	2	0.0013	9.9e-4	0.00	0	0	0	0	0	1	-360	360;
	2	3	0.0046	0.0036	0.00	0	0	0   0	0	1	-360	360;
	2	7	0.0142	0.0109	0.00	0	0	0	0	0	1	-360	360;
	2	15	0.0026	0.002	0.00	0	0	0	0	0	1	-360	360;
	3	4	0.01	0.049	-0.002	0	0	0	0	30	1	-360	360; %b is the inductive shunt loss of the trafo
	3	5	0.0099	0.0547	-0.002	0	0	0	0	30	1	-360	360; %b is the inductive shunt loss of the trafo
	5	6	2.1338	1.6359	0.00	0	0	0	0	0	1	-360	360;
	7	8	0.0077	0.0059	0.00	0	0	0	0	0	1	-360	360;
	7	9	0.01	0.049	-0.002	0	0	0	0	30	1	-360	360; %b is the inductive shunt loss of the trafo
	7	10	0.0039	0.003	0.00	0	0	0	0	0	1	-360	360;
	10	11	0.0042	0.0473	-0.002	0	0	0	0	30	1	-360	360; %b is the inductive shunt loss of the trafo
	11	12	0.0099	0.0566	-1.8362e-4	0	0	0	0	30	1	-360	360; %b is the inductive shunt loss of the trafo
	11	13	0.0099	0.0566	-1.8362e-4	0	0	0	0	30	1	-360	360; %b is the inductive shunt loss of the trafo
	11	14	0.0568	0.0436	0.00	0	0	0	0	0	1	-360	360;
	15	16	0.0067	0.005	0.00	0	0	0	0	0	1	-360	360;
	15	17	0.0077	0.0059	0.00	0	0	0	0	0	1	-360	360;
	17	18	0.0086	0.0569	-0.002	0	0	0	0	30	1	-360	360; %b is the inductive shunt loss of the trafo
	18	19	4.2675	3.2719	0.00	0	0	0	0	0	1	-360	360;
];

%%-----  OPF Data  -----%%
%% generator cost data
%	1	startup	shutdown	n	x1	y1	...	xn	yn
%	2	startup	shutdown	n	c(n-1)	...	c0
mpc.gencost = [
	1	0	0	1	0;
    1	0	0	1	0;
];
