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

figure('name', 'kpp5 Voltage'); % Voltage

ax = [];
ax= [ax subplot(3,1,1)]; plot(comm.t_min, res.voltage(:,kpp5.iPQ)); 
title('Bus voltages [PU]');                         
ax= [ax subplot(3,1,2)]; area(comm.t_min, kpp5.outage_event_cnt);
title('Count of bus voltage outages');
%ax= [ax subplot(3,1,3)]; plot(comm.t_min, kpp5.qVolt_outage); 
ax= [ax subplot(3,1,3)]; area(comm.t_min, kpp5.d_cum_per_class);
hold on;
plot(comm.t_min, ones(1,comm.M)*(-prices.KPP5_CAP), 'r--');
plot(comm.t_min, kpp5.d_cum_total, 'r', 'LineWidth', 2);
title('KPP5 summary values [$]');
legend(kpp5.legend_per_class, 'location', 'SouthWest');
linkaxes(ax,'x');

%% Frequency
figure('name', 'kpp5 Freq'); 
ax = [];
ax= [ax subplot(3,1,1)]; plot(comm.t_min, res.frequency(:,kpp5.iPQ)); 
title('Bus frequencies [Hz]');                         
ax= [ax subplot(3,1,2)]; plot(comm.t_min, cumsum(kpp5.qHz_outage,2)); 
title('Frequency violations integrators [1/sek/Hz]');
ax= [ax subplot(3,1,3)]; area(comm.t_min, kpp5.d_cum_per_class);
hold on;
plot(comm.t_min, ones(1,comm.M)*(-prices.KPP5_CAP), 'r--');
plot(comm.t_min, kpp5.d_cum_total, 'r', 'LineWidth', 2);
title('KPP5 summary values [$]');
legend(kpp5.legend_per_class, 'location', 'SouthWest');
linkaxes(ax,'x');