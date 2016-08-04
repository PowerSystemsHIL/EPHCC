% Copyright (c) 2016 Massachusetts Institute of Technology
% Permission is hereby granted, free of charge, to any person obtaining a copy of this 
% software and associated documentation files (the "Software"), to deal in the Software
% without restriction, including without limitation the rights to use, copy, modify, 
% merge, publish, distribute, sublicense, and/or sell copies of the Software, and to 
% permit persons to whom the Software is furnished to do so, subject to the following 
% conditions:
% 
% 
% The above copyright notice and this permission notice shall be included in 
% all copies or substantial portions of the Software.
% 
% THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
% INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
% PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
% HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION 
% OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
% SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
%
%
%%


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
