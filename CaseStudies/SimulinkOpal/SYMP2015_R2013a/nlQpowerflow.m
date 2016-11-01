function [cleq, ceq] = nlQpowerflow(x,impedance,grid)

% x(1) voltage, x(2) angle

cleq = [];
ceq = PfromVandAng(grid,x(1),x(2),impedance);
