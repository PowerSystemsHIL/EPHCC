<<<<<<< HEAD
%% Feeder 1
f1(1) = loadLoad('..\..\C1.mat', tStop);
f1(2) = loadLoad('..\..\P1.mat', tStop);
f1(3) = loadLoad('..\..\I1.mat', tStop);
f1(4) = loadLoad('..\..\C2.mat', tStop);
f1(5) = loadLoad('..\..\I2.mat', tStop);
=======
dataDir = '..\..\..\..\CaseStudies\SimulinkOpal\BANSHEE_DEBUG_v16\'

%% Feeder 1
f1(1) = loadLoad([dataDir 'C1.mat'], tStop);
f1(2) = loadLoad([dataDir 'P1.mat'], tStop);
f1(3) = loadLoad([dataDir 'I1.mat'], tStop);
f1(4) = loadLoad([dataDir 'C2.mat'], tStop);
f1(5) = loadLoad([dataDir 'I2.mat'], tStop);
>>>>>>> 3b7aefb8b79b42b61d07606e133a5b93dc8459c2
f1_tot = sumFeeder(f1);
%plotLoad(f1, f1_tot, 'Feeder 1');


%% Feeder 2
<<<<<<< HEAD
f2(1) = loadLoad('..\..\C3.mat', tStop);
f2(2) = loadLoad('..\..\I3.mat', tStop);
f2(3) = loadLoad('..\..\I4.mat', tStop);
f2(4) = loadLoad('..\..\P3.mat', tStop);
f2(5) = loadLoad('..\..\P2.mat', tStop);
f2(6) = loadLoad('..\..\I5.mat', tStop);
f2(7) = loadLoad('..\..\C4.mat', tStop);
f2(8) = loadLoad('..\..\P5.mat', tStop);
=======
f2(1) = loadLoad([dataDir 'C3.mat'], tStop);
f2(2) = loadLoad([dataDir 'I3.mat'], tStop);
f2(3) = loadLoad([dataDir 'I4.mat'], tStop);
f2(4) = loadLoad([dataDir 'P3.mat'], tStop);
f2(5) = loadLoad([dataDir 'P2.mat'], tStop);
f2(6) = loadLoad([dataDir 'I5.mat'], tStop);
f2(7) = loadLoad([dataDir 'C4.mat'], tStop);
f2(8) = loadLoad([dataDir 'P5.mat'], tStop);
>>>>>>> 3b7aefb8b79b42b61d07606e133a5b93dc8459c2
f2_tot = sumFeeder(f2);
%plotLoad(f2, f2_tot, 'Feeder 2');

%% Feeder 3
<<<<<<< HEAD
f3(1) = loadLoad('..\..\C5.mat', tStop);
f3(2) = loadLoad('..\..\I6.mat', tStop);
f3(3) = loadLoad('..\..\P4.mat', tStop);
f3(4) = loadLoad('..\..\C6.mat', tStop);
f3(5) = loadLoad('..\..\P6.mat', tStop);
=======
f3(1) = loadLoad([dataDir 'C5.mat'], tStop);
f3(2) = loadLoad([dataDir 'I6.mat'], tStop);
f3(3) = loadLoad([dataDir 'P4.mat'], tStop);
f3(4) = loadLoad([dataDir 'C6.mat'], tStop);
f3(5) = loadLoad([dataDir 'P6.mat'], tStop);
>>>>>>> 3b7aefb8b79b42b61d07606e133a5b93dc8459c2
f3_tot = sumFeeder(f3);
%plotLoad(f3, f3_tot, 'Feeder 3');