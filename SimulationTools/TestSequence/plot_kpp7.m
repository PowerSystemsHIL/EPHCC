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

ax = [];
figure('name', 'kpp7_a');

ax= [ax subplot(3,1,1)]; 
    area(comm.t_min, [cumsum(kpp7.gen1_start) cumsum(kpp7.gen2_start) cumsum(kpp7.gen3_start)]);  grid on;
    set(gca,'XTick', [0:5:100]);
    legend({'Gen1', 'Gen2', 'Gen3'},  'location', 'NorthWest');
    title('Generators reconnections count [unit]');
    
ax= [ax subplot(3,1,2)]; 
    plot(comm.t_min, cumsum(kpp7.cb_switches));  grid on;
    set(gca,'XTick', [0:5:100]);
    title('CB switches count [unit]');

ax= [ax subplot(3,1,3)]; 
    plot(comm.t_min, [kpp7.soc kpp7.bat_cycle]);  grid on;
    set(gca,'XTick', [0:5:100]);
    legend({'SoC1', 'SoC2', 'Cycle1', 'Cycle2'},  'location', 'NorthWest');
    title('SoC of batteries and battery cycles [unit]');

xlabel('time [min]');
linkaxes(ax,'x');
%%
figure('name', 'kpp7_b');
ax= [ax subplot(4,1,1)]; 
    plot(comm.t_min, kpp7.curPU(:, kpp7.IsGen));  grid on;
    set(gca,'XTick', [0:5:100]);
    legend(kpp7.LegendGen,  'location', 'NorthWest');
    title('Generators current [pu]');
    
ax= [ax subplot(4,1,2)]; 
    plot(comm.t_min, kpp7.curPU(:, kpp7.IsLine));  grid on;
    set(gca,'XTick', [0:5:100]);
    %legend(kpp7.LegendLine,  'location', 'NorthWest');
    title('Lines current [pu]');

ax= [ax subplot(4,1,3)]; 
    plot(comm.t_min, kpp7.curPU(:, kpp7.IsTrafo));  grid on;
    set(gca,'XTick', [0:5:100]);
    %legend(kpp7.LegendTrafo,  'location', 'NorthWest');
    title('Transformers current [pu]');

ax= [ax subplot(4,1,4)]; 
    plot(comm.t_min, kpp7.d_cum_per_class(:,[5 6 7])); 
    hold on;
    plot(comm.t_min, kpp7.d_cum_total, 'r', 'LineWidth', 2);
    title('KPP7 summary values [$]');
    legend(kpp7.legend_per_class{[5 6 7]}, 'location', 'SouthWest');
    linkaxes(ax,'x');
%% Frequency
figure('name', 'kpp7'); 
ax= [ax subplot(1,1,1)]; 
plot(comm.t_min, kpp7.d_cum_per_class);
hold on;
plot(comm.t_min, kpp7.d_cum_total, 'r', 'LineWidth', 2);
title('KPP7 summary values [$]');
legend(kpp7.legend_per_class, 'location', 'SouthWest');
linkaxes(ax,'x');