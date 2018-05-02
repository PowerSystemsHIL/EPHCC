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


%CBs = {'CB100', 'CB200', 'CB300'};
%CBs = {'CB101', 'CB102', 'CB103', 'CB104', 'CB105', 'CB106', 'CB107', 'CB108'};
%CBs = {'CB104', 'CB107'};
CBs = {'CB401', 'CB402', 'CB403', 'CB404', 'CB405', 'CB406'};

% Ties
%CBs = {'CB108', 'CB109', 'CB111', 'CB113', 'CB213', 'CB216', 'CB217', 'CB401'};
% Interruptable & priority loads
%CBs = {'CB104', 'CB107', 'CB114', 'CB206', 'CB208', 'CB204', 'CB219', 'CB218', 'CB212', 'CB307', 'CB308', 'CB309', 'CB402', 'CB403', 'CB405', 'CB406'};

%%
for ii=1:length(CBs)

%ii = 1;
fh = figure('name', CBs{ii});
annotation(fh, 'TextBox', 'string', CBs{ii}, 'position', [0.2 0.95 0.6 0.05]);
ax = [];

CBid = eval(['id.' CBs{ii}]);
ctrl = res.breaker_ctrl(:,CBid);
stat = res.breaker(:,CBid);
p = res.powerreal(:,CBid);
q = res.reactivepower(:,CBid);
v = res.voltage(:,CBid)/1000;
f = res.frequency(:,CBid)/6000;

ax= [ax subplot(5,1,1)]; 
    title('Relay status');
    dig = (double(dec2bin(ctrl,5))-48)';
    dig = dig(5:-1:1,:);
    dig(2,:) = 2*dig(2,:)+dig(1,:);
    dig(1,:) = [];
%     dig(1,:) = dig(1,:) < 0.5;
    dig_lab = {'CloseReq', 'GooseTrip', 'Reset', 'ProtSet'};
    
    Ndig = size(dig,1);
    dig_lab = dig_lab(Ndig:-1:1);
    base = (((Ndig-1):-1:0)'*ones(1,comm.M)*1.2);
    plot(comm.t_min, dig + base); grid on;
    set(gca,'YTick', [0:Ndig-1]*1.2);
    set(gca,'XTick', [0:5:100]);
    set(gca,'YTickLabel', dig_lab);


ax= [ax subplot(5,1,[2 3])]; 
    title('Relay status');
    dig = (double(dec2bin(stat,16))-48)';
    dig = dig(16:-1:1,:);
    dig_lab = {'Closed', 'R25 Sync', 'R27 UV', 'R50 OCi', 'R51 OC', 'R59 OV', ...
        'reset', 'T50', 'T51', 'T27', 'T59', 'R81 UF', 'R81 OF', 'R81RF', 'opmode', 'pmode'};
    
    Ndig = size(dig,1);
    dig_lab = dig_lab(Ndig:-1:1);
    base = (((Ndig-1):-1:0)'*ones(1,comm.M)*1.2);
    plot(comm.t_min, dig + base); grid on;
    set(gca,'YTick', [0:Ndig-1]*1.2);
    set(gca,'XTick', [0:5:100]);
    set(gca,'YTickLabel', dig_lab);
    
ax= [ax subplot(5,1,4)]; 
    plot(comm.t_min, [p q]); hold on; grid on;
    title('P / Q');

ax= [ax subplot(5,1,5)]; 
    plot(comm.t_min, [v f]); hold on; grid on;
    title('V / F');

xlabel('time [min]');
linkaxes(ax,'x');
end