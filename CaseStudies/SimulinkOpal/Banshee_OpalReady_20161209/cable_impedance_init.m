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
%%

%% loading cable data

% reading file
[cable_num, cable_txt] = xlsread('cable_impedance.xlsx');
cable_txt = cable_txt(2:end,1);

% impedances arranged by index and not by specific codes.
% Data Input Format 
% Index	Cable Type	Base kV	R1 (ohms/mi)	X1 (ohms/mi)	R0 (ohms/mi)
% X0 (ohms/mi)	G (uS/mi)	B (uS/mi)	Nomial Ampacity (A)

% convertion factor mile->km:
miToKm = 1/1.60934; % 1mi / 1.60934km

kV = cable_num(:,3);
R1 = cable_num(:,4) * miToKm;
L1 = cable_num(:,5) * miToKm / 377;
R0 = cable_num(:,6) * miToKm;
L0 = cable_num(:,7) * miToKm / 377;
C1 = 1 ./ ((1./ (cable_num(:,8) * 1E-6 * miToKm)) * 377);
C0 = C1;
ampacity = cable_num(:,9);
% formation implemented in the PI model
cable_spec = [R1, R0, L1, L0, C1, C0];


