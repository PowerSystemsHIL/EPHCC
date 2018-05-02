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

function [ax] = seq_plot(seq);
ax = [];
opt = seq.opt;
figure('name', ['sequence' num2str(seq.seq_no)]);
ax= [ax subplot(6,1,1)]; plot(seq.t/60, [seq.irradiance; seq.price]);
    legend({'Irradiance PV1', 'Irradiance PV2', 'Grid energy price'});
    title(['Microgid controller procurement 2017 - sequence #' num2str(seq.seq_no)]);
    set(gca,'XTick', [0:5:100]);
    ylabel('[PU]'); grid on;
ax= [ax subplot(6,1,2)]; plot(seq.t/60, [seq.grid_freq./60.0; seq.grid_volt./115000]);
    legend({'Grid freq', 'Grid voltage'});
    set(gca,'XTick', [0:5:100]);
    ylabel('[PU]'); grid on;
    title('Grid parameters');
ax= [ax subplot(6,1,3)]; plot(seq.t/60, [seq.dms_kWref_nan+0.05*10e3; ...
                             seq.dms_kWref_nan-0.05*10e3; ...
                             seq.dms_kWHzref_nan+0.10*10e3; ...
                             seq.dms_kWHzref_nan-0.10*10e3; ...
                             ]); hold on; 
                         
    %legend({'DMS kW max' 'DMS kW min' 'DMS kW max(Hz/kW)' 'DMS kW max(Hz/kW)'});
    title('DMS active power reference');
    set(gca,'XTick', [0:5:100]);
    ylabel('[kW]'); grid on;
ax= [ax subplot(6,1,4)];
    plot(seq.t/60, [seq.dms_kVArref_nan+0.02*10e3; ...
                             seq.dms_kVArref_nan-0.02*10e3; ...
                             seq.dms_kVArVoltref_nan+0.05*10e3; ...
                             seq.dms_kVArVoltref_nan-0.05*10e3; ...
                             ]);
%     plot(seq.t/60, [seq.dms_phiref_nan+5; seq.dms_phiref_nan-5]); hold on;
%     plot(seq.t/60, [seq.dms_ang_kVArVoltref_nan+10; seq.dms_ang_kVArVoltref_nan-10]);
    title('DMS reactive power reference');
    set(gca,'XTick', [0:5:100]);
    ylabel('[kVAr]'); grid on;
                         
dig     = [seq.fault.loc1; seq.fault.loc2; seq.fault.loc3; seq.fault.loc4; seq.fault.loc5; seq.fault.loc6];
dig_lab = {'fault.loc1' 'fault.loc2' 'fault.loc3' 'fault.loc4' 'fault.loc5' 'fault.loc6' };
dig     = [dig; seq.fault.gen1; seq.fault.gen2; seq.fault.gen3; seq.fault.ess1; seq.fault.ess2; seq.fault.pv1; seq.fault.pv2];
dig_lab = [dig_lab 'fault.gen1' 'fault.gen2' 'fault.gen3' 'fault.ess1' 'fault.ess2' 'fault.pv1' 'fault.pv2' ];
dig     = [dig; seq.motor1; seq.motor2; seq.cut_grid; seq.dms_disreq; seq.mgc_enable];
dig_lab = [dig_lab 'Mot1' 'Mot2' 'G.Cut'            'DMS.DR'        'MGC.En'      ];

% Don't plot signals which are always zero
rem_plot = [];
for i=1:size(dig)
    if (sum(dig(i,:)) == 0)
        rem_plot = [rem_plot i];
    end;
end
dig(rem_plot,:) = [];
dig_lab(rem_plot) = [];

Ndig = size(dig,1);
dig_lab = dig_lab(Ndig:-1:1);
base = (((Ndig-1):-1:0)'*ones(1,opt.N)*1.2);
ax= [ax subplot(6,1,[5 6])]; plot(seq.t/60, dig + base);
xlabel('time [min]');
set(gca,'YTick', [0:Ndig-1]*1.2);
set(gca,'XTick', [0:5:100]);
set(gca,'YTickLabel', dig_lab);
linkaxes(ax,'x'); grid on;


%tightfig();