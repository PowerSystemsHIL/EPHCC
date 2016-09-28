function P = PfromVandAng(V1,V2,angle,X)
% Calculate real power flow.
% V1 and V2 are source #1 and 2 RMS voltage.  
% angle is phase angle between them. (radians)
% X is impedance along that path.

P = ((V1*V2)/(X))*sin(angle);


end

