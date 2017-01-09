%% Feeder 1
f1(1) = loadLoad('..\..\C1.mat', tStop);
f1(2) = loadLoad('..\..\P1.mat', tStop);
f1(3) = loadLoad('..\..\I1.mat', tStop);
f1(4) = loadLoad('..\..\C2.mat', tStop);
f1(5) = loadLoad('..\..\I2.mat', tStop);
f1_tot = sumFeeder(f1);
%plotLoad(f1, f1_tot, 'Feeder 1');


%% Feeder 2
f2(1) = loadLoad('..\..\C3.mat', tStop);
f2(2) = loadLoad('..\..\I3.mat', tStop);
f2(3) = loadLoad('..\..\I4.mat', tStop);
f2(4) = loadLoad('..\..\P3.mat', tStop);
f2(5) = loadLoad('..\..\P2.mat', tStop);
f2(6) = loadLoad('..\..\I5.mat', tStop);
f2(7) = loadLoad('..\..\C4.mat', tStop);
f2(8) = loadLoad('..\..\P5.mat', tStop);
f2_tot = sumFeeder(f2);
%plotLoad(f2, f2_tot, 'Feeder 2');

%% Feeder 3
f3(1) = loadLoad('..\..\C5.mat', tStop);
f3(2) = loadLoad('..\..\I6.mat', tStop);
f3(3) = loadLoad('..\..\P4.mat', tStop);
f3(4) = loadLoad('..\..\C6.mat', tStop);
f3(5) = loadLoad('..\..\P6.mat', tStop);
f3_tot = sumFeeder(f3);
%plotLoad(f3, f3_tot, 'Feeder 3');