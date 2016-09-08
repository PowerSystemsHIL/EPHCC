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

function UnitTest_Breaker_Plots()

file_name = 'CB_SeriesLoad';
cb_plots(file_name, 0);
file_name = 'CB_ParallelLoad';
cb_plots(file_name, 0);
file_name = 'CB_DynamicLoad';
cb_plots(file_name, 0);

end

%% defining function
function cb_plots(file_name, save_fig)
% INPUTS:
% file_name: file name without the .mat extension
% save_fig: boolean indicating whether or not save the plots

% loading data
% Array "data" holds the simulation results
load([file_name, '.mat']);
t = data(1, :);
logic_trip = data(2, :);
cb_status = data(3, :);
iabc = [data(4, :); data(5, :); data(6, :)];
vabc_bus = [data(7, :); data(8, :); data(9, :)];
vabc_line = [data(10, :); data(11, :); data(12, :)];

figure;

ax1 = subplot(4,1,1);
plot(t, logic_trip,...
    t, cb_status, 'linewidth', 2);
ylim([-0.5, 1.5]);
legend('Trip Signal', 'CB Status'); grid on;
title(file_name,'Interpreter','none');

ax2 = subplot(4,1,2);
plot(t, iabc, 'linewidth', 2)
legend('Ia', 'Ib', 'Ic'); grid on;

ax3 = subplot(4,1,3);
plot(t, vabc_bus, 'linewidth', 2)
legend('Va', 'Vb', 'Vc'); grid on;

ax4 = subplot(4,1,4);
plot(t, vabc_line, 'linewidth', 2)
legend('Va', 'Vb', 'Vc'); grid on;

xlabel('Time [s]');
linkaxes([ax1,ax2,ax3,ax4],'x')
set([ax1,ax2,ax3,ax4], 'fontsize', 12)
if save_fig ~= 0
    % saving figure
    saveas(gcf, file_name);
end
end