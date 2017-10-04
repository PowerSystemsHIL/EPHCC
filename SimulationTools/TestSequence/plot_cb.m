
CBs = {'CB100', 'CB200', 'CB300', 'CB402'};

%%
for ii=1:length(CBs)

%ii = 1;
fh = figure;
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
    dig(1,:) = [];
    dig(1,:) = dig(1,:) < 0.5;
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