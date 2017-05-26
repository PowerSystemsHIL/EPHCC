Name = 'Feeder1BansheeSimple';
% Name = 'Feeder1Banshee';
% Name = 'Feeder1BansheeNosnubbers';
% Name = 'Feeder1BansheeFULL';
clc
mpopt = mpoption('pf.fd.max_it',100,'pf.alg','FDXB');
runpf(Name,mpopt)