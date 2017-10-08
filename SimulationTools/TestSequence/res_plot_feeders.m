fh = figure('name', 'feed1');
annotation(fh, 'TextBox', 'string', 'Feeder 1', 'position', [0.2 0.95 0.6 0.05]);
ax= subplot(3,4,1); plot(comm.t_min, res.powerreal(:,[1:14]));
ax= [ax subplot(3,4,5)]; plot(comm.t_min, res.powerreal(:,[50]));
ax= [ax subplot(3,4,9)]; plot(comm.t_min, res.powerreal(:,[53]));

ax= [ax subplot(3,4,2)]; plot(comm.t_min, res.reactivepower(:,[1:14]));
ax= [ax subplot(3,4,6)]; plot(comm.t_min, res.reactivepower(:,[50]));
ax= [ax subplot(3,4,10)]; plot(comm.t_min, res.reactivepower(:,[53]));

ax= [ax subplot(3,4,3)]; plot(comm.t_min, res.voltage(:,[2:15]));
ax= [ax subplot(3,4,7)]; plot(comm.t_min, res.voltage(:,[50]));
ax= [ax subplot(3,4,11)]; plot(comm.t_min, res.voltage(:,[53]));

ax= [ax subplot(3,4,4)]; plot(comm.t_min, repmat((0:(14-1))*1.1,comm.M,1) + bitand(res.breaker(:,[1:14]),1));
ax= [ax subplot(3,4,8)]; plot(comm.t_min,  bitand(res.breaker(:,[50]),1));
ax= [ax subplot(3,4,12)]; plot(comm.t_min, bitand(res.breaker(:,[53]),1));

linkaxes(ax,'x');

%% Feeder 2
fh = figure('name', 'feed2');
annotation(fh, 'TextBox', 'string', 'Feeder 2', 'position', [0.2 0.95 0.6 0.05]);
ax= subplot(4,4,1); plot(comm.t_min, res.powerreal(:,[15:33]));
ax= [ax subplot(4,4,5)]; plot(comm.t_min, res.powerreal(:,[51]));
ax= [ax subplot(4,4,9)]; plot(comm.t_min, res.powerreal(:,[54]));
ax= [ax subplot(4,4,13)]; plot(comm.t_min, res.powerreal(:,[55]));

ax= [ax subplot(4,4,2)]; plot(comm.t_min, res.reactivepower(:,[15:33]));
ax= [ax subplot(4,4,6)]; plot(comm.t_min, res.reactivepower(:,[51]));
ax= [ax subplot(4,4,10)]; plot(comm.t_min, res.reactivepower(:,[54]));
ax= [ax subplot(4,4,14)]; plot(comm.t_min, res.reactivepower(:,[55]));

ax= [ax subplot(4,4,3)]; plot(comm.t_min, res.voltage(:,[15:33]));
ax= [ax subplot(4,4,7)]; plot(comm.t_min, res.voltage(:,[51]));
ax= [ax subplot(4,4,11)]; plot(comm.t_min, res.voltage(:,[54]));
ax= [ax subplot(4,4,15)]; plot(comm.t_min, res.voltage(:,[55]));

ax= [ax subplot(4,4,4)]; plot(comm.t_min, repmat((0:(19-1))*1.1,comm.M,1) + bitand(res.breaker(:,[15:33]),1));
ax= [ax subplot(4,4,8)]; plot(comm.t_min, bitand(res.breaker(:,[51]),1));
ax= [ax subplot(4,4,12)]; plot(comm.t_min, [bitand(res.breaker(:,[54]),1) res.battery_SoC(:,1)./10000]);
ax= [ax subplot(4,4,16)]; plot(comm.t_min, bitand(res.breaker(:,[55]),1));

linkaxes(ax,'x');

%% Feeder 3
fh = figure('name', 'feed3');
annotation(fh, 'TextBox', 'string', 'Feeder 3', 'position', [0.2 0.95 0.6 0.05]);
ax= subplot(3,4,1); plot(comm.t_min, res.powerreal(:,[34:43]));
ax= [ax subplot(3,4,5)]; plot(comm.t_min, res.powerreal(:,[52]));
ax= [ax subplot(3,4,9)]; plot(comm.t_min, res.powerreal(:,[56]));

ax= [ax subplot(3,4,2)]; plot(comm.t_min, res.reactivepower(:,[34:43]));
ax= [ax subplot(3,4,6)]; plot(comm.t_min, res.reactivepower(:,[52]));
ax= [ax subplot(3,4,10)]; plot(comm.t_min, res.reactivepower(:,[56]));

ax= [ax subplot(3,4,3)]; plot(comm.t_min, res.voltage(:,[34:43]));
ax= [ax subplot(3,4,7)]; plot(comm.t_min, res.voltage(:,[52]));
ax= [ax subplot(3,4,11)]; plot(comm.t_min, res.voltage(:,[56]));

ax= [ax subplot(3,4,4)]; plot(comm.t_min, repmat((0:(10-1))*1.1,comm.M,1) + bitand(res.breaker(:,[34:43]),1));
ax= [ax subplot(3,4,8)]; plot(comm.t_min, bitand(res.breaker(:,[52]),1));
ax= [ax subplot(3,4,12)]; plot(comm.t_min, bitand(res.breaker(:,[56]),1));

linkaxes(ax,'x');

%% Feeder 4
fh = figure('name', 'feed4');
annotation(fh, 'TextBox', 'string', 'Feeder 4', 'position', [0.2 0.95 0.6 0.05]);
ax=     subplot(5,4,1) ; plot(comm.t_min, res.powerreal(:,[45:49]));
ax= [ax subplot(5,4,5)]; plot(comm.t_min, res.powerreal(:,[44]));
ax= [ax subplot(5,4,9)]; plot(comm.t_min, res.powerreal(:,[57]));
ax= [ax subplot(5,4,13)]; plot(comm.t_min, res.powerreal(:,[58]));
ax= [ax subplot(5,4,17)]; plot(comm.t_min, res.powerreal(:,[59]));

ax= [ax subplot(5,4,2)]; plot(comm.t_min, res.reactivepower(:,[45:49]));
ax= [ax subplot(5,4,6)]; plot(comm.t_min, res.reactivepower(:,[44]));
ax= [ax subplot(5,4,10)]; plot(comm.t_min, res.reactivepower(:,[57]));
ax= [ax subplot(5,4,14)]; plot(comm.t_min, res.reactivepower(:,[58]));
ax= [ax subplot(5,4,18)]; plot(comm.t_min, res.reactivepower(:,[59]));

ax= [ax subplot(5,4,3)]; plot(comm.t_min, res.voltage(:,[45:49]));
ax= [ax subplot(5,4,7)]; plot(comm.t_min, res.voltage(:,[44]));
ax= [ax subplot(5,4,11)]; plot(comm.t_min, res.voltage(:,[57]));
ax= [ax subplot(5,4,15)]; plot(comm.t_min, res.voltage(:,[58]));
ax= [ax subplot(5,4,19)]; plot(comm.t_min, res.voltage(:,[59]));

ax= [ax subplot(5,4,4)]; plot(comm.t_min, repmat((0:(5-1))*1.1,comm.M,1) + bitand(res.breaker(:,[45:49]),1));
ax= [ax subplot(5,4,8)]; plot(comm.t_min, bitand(res.breaker(:,[44]),1));
ax= [ax subplot(5,4,12)]; plot(comm.t_min, bitand(res.breaker(:,[57]),1));
ax= [ax subplot(5,4,16)]; plot(comm.t_min, [bitand(res.breaker(:,[58]),1) res.battery_SoC(:,2)./10000]);
ax= [ax subplot(5,4,20)]; plot(comm.t_min, bitand(res.breaker(:,[59]),1));

linkaxes(ax,'x');