function [P, Q] = PQfromVandAng(V1,V2,angle,X)
% Calculate real and reactive power flow.
% V1 and V2 are source #1 and 2 RMS voltage.  
% angle is phase angle between them.
% X is impedance along that path.

P = ((V1*V2)/(X))*sin(angle);
Q = V1^2/(X)-(V1*V2/(X))*cos(angle);

end

