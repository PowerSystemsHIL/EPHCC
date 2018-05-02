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

%%
figure('name', 'kpp1');
ax = [];
ax= [ax subplot(3,1,1)]; area(comm.t_min, kpp1.P_good_per_class, 'LineStyle', 'none'); grid on;
set(gca,'XTick', [0:5:100]);
title('kW served by load class');
legend({'M','I','P','C'});
ax= [ax subplot(3,1,2)]; area(comm.t_min, -kpp1.P_outage_per_class, 'LineStyle', 'none'); grid on;
set(gca,'XTick', [0:5:100]);
title('kW outage by load class');
% subplot(4,1,3); area(comm.t_min, kpp1.E_good_per_class, 'LineStyle', 'none'); hold on;
%                 area(comm.t_min, -kpp1.EO_per_class, 'LineStyle', 'none');
% subplot(4,1,4); area(comm.t_min, [kpp1.EP_per_class], 'LineStyle', 'none'); hold on;
%                 area(comm.t_min, -kpp1.EOP_per_class, 'LineStyle', 'none');
%                 plot(comm.t_min, zeros(M,1), 'b', 'LineWidth', 2);
%                 plot(comm.t_min, kpp1.Price_total, 'r', 'LineWidth', 2);
ax= [ax subplot(3,1,3)];
    plot(comm.t_min, [kpp1.d_cum_per_class(:,[1:4 9])]); hold on; grid on;
    plot(comm.t_min, [kpp1.d_cum_per_class(:,5:8)], '--');
    legend(kpp1.d_cum_per_class_legend);
    plot(comm.t_min, kpp1.d_cum_total, 'r', 'LineWidth', 3);
    title('KPP1 summary values [$]');
    set(gca,'XTick', [0:5:100]);

xlabel('time [min]');
linkaxes(ax,'x');   
