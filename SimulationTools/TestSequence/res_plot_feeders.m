fh = figure();
annotation(fh, 'TextBox', 'string', 'Feeder 1', 'position', [0.2 0.95 0.6 0.05]);
ax= subplot(3,4,1); plot(res.t, res.powerreal(:,[1:14]));
ax= [ax subplot(3,4,5)]; plot(res.t, res.powerreal(:,[50]));
ax= [ax subplot(3,4,9)]; plot(res.t, res.powerreal(:,[53]));

ax= [ax subplot(3,4,2)]; plot(res.t, res.reactivepower(:,[1:14]));
ax= [ax subplot(3,4,6)]; plot(res.t, res.reactivepower(:,[50]));
ax= [ax subplot(3,4,10)]; plot(res.t, res.reactivepower(:,[53]));

ax= [ax subplot(3,4,3)]; plot(res.t, res.voltage(:,[2:15]));
ax= [ax subplot(3,4,7)]; plot(res.t, res.voltage(:,[50]));
ax= [ax subplot(3,4,11)]; plot(res.t, res.voltage(:,[53]));

ax= [ax subplot(3,4,4)]; plot(res.t, res.breaker(:,[2:15]));
ax= [ax subplot(3,4,8)]; plot(res.t, res.breaker(:,[50]));
ax= [ax subplot(3,4,12)]; plot(res.t, res.breaker(:,[53]));

linkaxes(ax,'x');

%% Feeder 2
fh = figure();
annotation(fh, 'TextBox', 'string', 'Feeder 2', 'position', [0.2 0.95 0.6 0.05]);
ax= subplot(4,4,1); plot(res.t, res.powerreal(:,[15:33]));
ax= [ax subplot(4,4,5)]; plot(res.t, res.powerreal(:,[51]));
ax= [ax subplot(4,4,9)]; plot(res.t, res.powerreal(:,[54]));
ax= [ax subplot(4,4,13)]; plot(res.t, res.powerreal(:,[55]));

ax= [ax subplot(4,4,2)]; plot(res.t, res.reactivepower(:,[15:33]));
ax= [ax subplot(4,4,6)]; plot(res.t, res.reactivepower(:,[51]));
ax= [ax subplot(4,4,10)]; plot(res.t, res.reactivepower(:,[54]));
ax= [ax subplot(4,4,14)]; plot(res.t, res.reactivepower(:,[55]));

ax= [ax subplot(4,4,3)]; plot(res.t, res.voltage(:,[15:33]));
ax= [ax subplot(4,4,7)]; plot(res.t, res.voltage(:,[51]));
ax= [ax subplot(4,4,11)]; plot(res.t, res.voltage(:,[54]));
ax= [ax subplot(4,4,15)]; plot(res.t, res.voltage(:,[55]));

ax= [ax subplot(4,4,4)]; plot(res.t, res.breaker(:,[15:33]));
ax= [ax subplot(4,4,8)]; plot(res.t, res.breaker(:,[51]));
ax= [ax subplot(4,4,12)]; plot(res.t, [res.breaker(:,[54]) res.battery_SoC(:,1)./10000]);
ax= [ax subplot(4,4,16)]; plot(res.t, res.breaker(:,[55]));

linkaxes(ax,'x');

%% Feeder 3
fh = figure();
annotation(fh, 'TextBox', 'string', 'Feeder 3', 'position', [0.2 0.95 0.6 0.05]);
ax= subplot(3,4,1); plot(res.t, res.powerreal(:,[34:43]));
ax= [ax subplot(3,4,5)]; plot(res.t, res.powerreal(:,[52]));
ax= [ax subplot(3,4,9)]; plot(res.t, res.powerreal(:,[56]));

ax= [ax subplot(3,4,2)]; plot(res.t, res.reactivepower(:,[34:43]));
ax= [ax subplot(3,4,6)]; plot(res.t, res.reactivepower(:,[52]));
ax= [ax subplot(3,4,10)]; plot(res.t, res.reactivepower(:,[56]));

ax= [ax subplot(3,4,3)]; plot(res.t, res.voltage(:,[34:43]));
ax= [ax subplot(3,4,7)]; plot(res.t, res.voltage(:,[52]));
ax= [ax subplot(3,4,11)]; plot(res.t, res.voltage(:,[56]));

ax= [ax subplot(3,4,4)]; plot(res.t, res.breaker(:,[2:15]));
ax= [ax subplot(3,4,8)]; plot(res.t, res.breaker(:,[52]));
ax= [ax subplot(3,4,12)]; plot(res.t, res.breaker(:,[56]));

linkaxes(ax,'x');

%% Feeder 4
fh = figure();
annotation(fh, 'TextBox', 'string', 'Feeder 2', 'position', [0.2 0.95 0.6 0.05]);
ax=     subplot(5,4,1) ; plot(res.t, res.powerreal(:,[45:49]));
ax= [ax subplot(5,4,5)]; plot(res.t, res.powerreal(:,[44]));
ax= [ax subplot(5,4,9)]; plot(res.t, res.powerreal(:,[57]));
ax= [ax subplot(5,4,13)]; plot(res.t, res.powerreal(:,[58]));
ax= [ax subplot(5,4,17)]; plot(res.t, res.powerreal(:,[59]));

ax= [ax subplot(5,4,2)]; plot(res.t, res.reactivepower(:,[45:49]));
ax= [ax subplot(5,4,6)]; plot(res.t, res.reactivepower(:,[44]));
ax= [ax subplot(5,4,10)]; plot(res.t, res.reactivepower(:,[57]));
ax= [ax subplot(5,4,14)]; plot(res.t, res.reactivepower(:,[58]));
ax= [ax subplot(5,4,18)]; plot(res.t, res.reactivepower(:,[59]));

ax= [ax subplot(5,4,3)]; plot(res.t, res.voltage(:,[45:49]));
ax= [ax subplot(5,4,7)]; plot(res.t, res.voltage(:,[44]));
ax= [ax subplot(5,4,11)]; plot(res.t, res.voltage(:,[57]));
ax= [ax subplot(5,4,15)]; plot(res.t, res.voltage(:,[58]));
ax= [ax subplot(5,4,19)]; plot(res.t, res.voltage(:,[59]));

ax= [ax subplot(5,4,4)]; plot(res.t, res.breaker(:,[45:49]));
ax= [ax subplot(5,4,8)]; plot(res.t, res.breaker(:,[44]));
ax= [ax subplot(5,4,12)]; plot(res.t, res.breaker(:,[57]));
ax= [ax subplot(5,4,16)]; plot(res.t, [res.breaker(:,[58]) res.battery_SoC(:,2)./10000]);
ax= [ax subplot(5,4,20)]; plot(res.t, res.breaker(:,[59]));

linkaxes(ax,'x');