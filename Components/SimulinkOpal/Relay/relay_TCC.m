% CREATED BY: REYNALDO SALCEDO
% LAST CHANGE BY : REYNALDO SALCEDO
% GROUP: 73
% DATE MODIFIED  : 05/06/2016
%

function t = relay_TCC( TD, M , tcc_type)

% returns the operating time in seconds
% see: SEL751 manual, page 4.23 - table 4.17
% calc. pickup time as given in IEEE Std C37.112-1996
% TD: time dial
% B: minimum operating time for high currents
% A, P: define degree of inverseness of TCC
% M: multiples of pickup
% t = TD .* (B + (A ./ (M.^P - 1)));

if tcc_type == 1
    % moderately inverse
    t = op_time_US_TCC_eq(TD, M, 0.0104, 0.0226, 0.02);
elseif tcc_type == 2
    % inverse
    t = op_time_US_TCC_eq(TD, M, 5.95, 0.180, 2);
elseif tcc_type == 3
    % very inverse
    t = op_time_US_TCC_eq(TD, M, 3.88, 0.0963, 2);
else
    % extremely inverse
    t = op_time_US_TCC_eq(TD, M, 5.67, 0.0352, 2);
end

end


function t = op_time_US_TCC_eq(TD, M, A, B, P)
% returns the operating time in seconds
% see: SEL751 manual, page 4.23 - table 4.17
% calc. pickup time as given in IEEE Std C37.112-1996
% TD: time dial
% B: minimum operating time for high currents
% A, P: define degree of inverseness of TCC
% M: multiples of pickup
t = TD .* (B + (A ./ (M.^P - 1)));

end
