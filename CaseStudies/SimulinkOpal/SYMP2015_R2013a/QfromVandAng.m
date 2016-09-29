function Q = QfromVandAng(V1,V2,angle,X)
% Calculate reactive power flow.
% V1 and V2 are source #1 and 2 RMS voltage.  
% angle is phase angle between them. (radians)
% X is impedance along that path.

Q = V1^2/(X)-(V1*V2/(X))*cos(angle);


end

