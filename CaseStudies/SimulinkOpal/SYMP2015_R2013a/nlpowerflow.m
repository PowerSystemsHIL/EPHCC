function [cleq, ceq] = nlpowerflow(x,impedance,grid)

% x(1) voltage, x(2) angle

cleq = [];
ceq = QfromVandAng(grid,x(1),x(2),impedance);
