%% Copyright 2018 Alliance for Sustainable Energy, LLC
%
% Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
% and associated documentation files (the "Software"), to deal in the Software without restriction, 
% including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
% and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, 
% subject to the following conditions:
%
% The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
%
% THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
% BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
% NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS, THE COPYRIGHT HOLDERS, THE UNITED STATES, 
% THE UNITED STATES DEPARTMENT OF ENERGY, OR ANY OF THEIR EMPLOYEES BE LIABLE FOR ANY CLAIM, 
% DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
% OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
%
% Author: Przemyslaw Koralewicz / NREL
% Date: 2017

figure('name', 'kpp2');

ax = [];
ax= [ax subplot(2,1,1)]; 
    area(comm.t_min, [kpp2.d_fuel(:,[1 3]) kpp2.d_fuel(:,2)+kpp2.d_fuel(:,4)]);  grid on;
    set(gca,'XTick', [0:5:100]);
    legend({'Diesel1' 'Diesel3' 'CHP2'});
    title('Fuel costs per hour [$/h]');    
ax= [ax subplot(2,1,2)]; 
    plot(comm.t_min, [kpp2.d_cum_per_class]); hold on;  grid on;
    plot(comm.t_min, [kpp2.d_cum_total], 'LineWidth', 3);
    set(gca,'XTick', [0:5:100]);
    title('KPP2 summary values [$]');
    legend(kpp2.legend_per_class);
    
xlabel('time [min]');
linkaxes(ax,'x');