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

figure('name', 'kpp4');

ax = [];
ax= [ax subplot(3,1,1)]; plot(comm.t_min, [ kpp3.pcc.p ], 'r', 'LineWidth', 2); hold on; grid on;
    plot(comm.t_min, [ kpp4.lim.kW_max kpp4.lim.kW_min kpp4.lim.kWHz_max kpp4.lim.kWHz_min], '--');
    all = [ kpp3.pcc.p      kpp4.lim.kWHz_max kpp4.lim.kWHz_min ];
    ymin = (min(min(all))); ymax = (max(max(all)));
    ymin = (floor(ymin/200))*200;
    ymax = (ceil(ymax/200))*200;
    ylim([ymin ymax]);
    set(gca,'XTick', [0:5:100]);
    title('Active power at POI [kW]');
ax= [ax subplot(3,1,2)]; plot(comm.t_min, [kpp3.pcc.q], 'r', 'LineWidth', 2); hold on;grid on;
    plot(comm.t_min, [kpp4.lim.kVAr_max     kpp4.lim.kVAr_min kpp4.lim.kVArVolt_max kpp4.lim.kVArVolt_min], '--' );
    set(gca,'XTick', [0:5:100]);
    title('Reactive power at POI [kVAr]');
ax= [ax subplot(3,1,3)]; 
    plot(comm.t_min, [kpp4.d_cum_per_class]); hold on;grid on;
    plot(comm.t_min, [kpp4.d_cum_total], 'LineWidth', 2);
    set(gca,'XTick', [0:5:100]);
    title('KPP4 summary values [$]');
    legend(kpp4.legend_per_class);
                                   

xlabel('time [min]');
linkaxes(ax,'x');