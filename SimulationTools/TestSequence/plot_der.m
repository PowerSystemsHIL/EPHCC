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


DERs = {struct('name', 'gen1', 'mcb_id', id.CBGen1, 'bus_id', id.CB112, 'Vn', 13800, 'prec', 1) ...
    struct('name', 'ess1', 'mcb_id', id.CBEss1, 'bus_id', id.CB207, 'Vn', 4800, 'prec', 1) ...
    struct('name', 'pv1' , 'mcb_id', id.CBPv1,  'bus_id', id.CB209, 'Vn', 4800, 'prec', 1) ...
    struct('name', 'gen2', 'mcb_id', id.CBGen2, 'bus_id', id.CB303, 'Vn', 13800, 'prec', 1) ...
    struct('name', 'gen3', 'mcb_id', id.CBGen3, 'bus_id', id.CB402, 'Vn', 4800, 'prec', 10) ...
    struct('name', 'ess2', 'mcb_id', id.CBEss2, 'bus_id', id.CB402, 'Vn', 4800, 'prec', 10) ...
    struct('name', 'pv2' , 'mcb_id', id.CBPv2,  'bus_id', id.CB402, 'Vn', 4800, 'prec', 10) ...
    };

%%
for ii=1:7
fh = figure('name', DERs{ii}.name);
annotation(fh, 'TextBox', 'string', DERs{ii}.name, 'position', [0.2 0.95 0.6 0.05]);
ax = [];
res_ctrl = eval(['res.' DERs{ii}.name '_ctrl']);
ax= [ax subplot(6,2,1)]; 
    plot(comm.t_min, res_ctrl(:,[1 8])); hold on; grid on;
    title('Generator control word');

ax= [ax subplot(6,2,5)]; 
    plot(comm.t_min, res_ctrl(:,4)./DERs{ii}.Vn); hold on; grid on;
    title('V ref');
    
ax= [ax subplot(6,2,7)]; 
    plot(comm.t_min, [res.voltage(:,DERs{ii}.mcb_id) res.voltage(:,DERs{ii}.bus_id)]./repmat([1000 1000], comm.M,1)); hold on; grid on;
    title('V gen / V bus');

ax= [ax subplot(6,2,9)];
    plot(comm.t_min, res_ctrl(:,3)./DERs{ii}.prec); hold on; grid on;
    title('Q ref [kVAr]');

ax= [ax subplot(6,2,11)]; 
    plot(comm.t_min, res.reactivepower(:,DERs{ii}.mcb_id)); hold on; grid on;
    title('Q [kVAr]');

    
ax= [ax subplot(6,2,6)]; 
    plot(comm.t_min, [res_ctrl(:,5)]./repmat([100], comm.M,1)); hold on; grid on;
    title('F ref');

ax= [ax subplot(6,2,8)]; 
    plot(comm.t_min, [res.frequency(:,DERs{ii}.mcb_id) res.frequency(:,DERs{ii}.bus_id)]./100); hold on; grid on;
    title('F gen / F bus');

ax= [ax subplot(6,2,10)];
    plot(comm.t_min, res_ctrl(:,2)./DERs{ii}.prec); hold on; grid on;
    title('P ref [kW]');

ax= [ax subplot(6,2,12)];
    plot(comm.t_min, [res.powerreal(:,DERs{ii}.mcb_id)]); hold on; grid on;
    title('P [kW]');


ax= [ax subplot(6,2,3)]; 
    plot(comm.t_min, res_ctrl(:,6:7)./repmat([100 100], comm.M,1)); hold on; grid on;
    title('Droop [%]');


ax= [ax subplot(6,2,[2 4])]; grid on;
    title('Relay status');
    dig = (double(dec2bin(res.breaker(:,DERs{ii}.mcb_id),16))-48)';
    dig = dig(16:-1:1,:);
    dig_lab = {'Closed', 'R25 Sync', 'R27 UV', 'R50 OCi', 'R51 OC', 'R59 OV', ...
        'reset', 'T50', 'T51', 'T27', 'T59', 'R81 UF', 'R81 OF', 'R81RF', 'opmode', 'pmode'};
    
    Ndig = size(dig,1);
    dig_lab = dig_lab(Ndig:-1:1);
    base = (((Ndig-1):-1:0)'*ones(1,comm.M)*1.2);
    plot(comm.t_min, dig + base);
    xlabel('time [min]');
    set(gca,'YTick', [0:Ndig-1]*1.2);
    set(gca,'XTick', [0:5:100]);
    set(gca,'YTickLabel', dig_lab);

    


linkaxes(ax,'x');
end