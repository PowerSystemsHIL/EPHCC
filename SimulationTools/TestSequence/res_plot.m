fh = figure();
annotation(fh, 'TextBox', 'string', 'Feeder 1', 'position', [0.2 0.95 0.6 0.05]);
ax= subplot(3,4,1); plot(res.simtime(:,1), res.powerreal(:,[2:15]));
ax= [ax subplot(3,4,5)]; plot(res.simtime(:,1), res.powerreal(:,[51]));
ax= [ax subplot(3,4,9)]; plot(res.simtime(:,1), res.powerreal(:,[54]));

ax= [ax subplot(3,4,2)]; plot(res.simtime(:,1), res.reactivepower(:,[2:15]));
ax= [ax subplot(3,4,6)]; plot(res.simtime(:,1), res.reactivepower(:,[51]));
ax= [ax subplot(3,4,10)]; plot(res.simtime(:,1), res.reactivepower(:,[54]));

ax= [ax subplot(3,4,3)]; plot(res.simtime(:,1), res.voltage(:,[2:15]));
ax= [ax subplot(3,4,7)]; plot(res.simtime(:,1), res.voltage(:,[51]));
ax= [ax subplot(3,4,11)]; plot(res.simtime(:,1), res.voltage(:,[54]));

ax= [ax subplot(3,4,4)]; plot(res.simtime(:,1), res.breaker(:,[2:15]));
ax= [ax subplot(3,4,8)]; plot(res.simtime(:,1), res.breaker(:,[51]));
ax= [ax subplot(3,4,12)]; plot(res.simtime(:,1), res.breaker(:,[54]));

linkaxes(ax,'x');

%% Feeder 2
fh = figure();
annotation(fh, 'TextBox', 'string', 'Feeder 2', 'position', [0.2 0.95 0.6 0.05]);
ax= subplot(4,4,1); plot(res.simtime(:,1), res.powerreal(:,[16:34]));
ax= [ax subplot(4,4,5)]; plot(res.simtime(:,1), res.powerreal(:,[52]));
ax= [ax subplot(4,4,9)]; plot(res.simtime(:,1), res.powerreal(:,[55]));
ax= [ax subplot(4,4,13)]; plot(res.simtime(:,1), res.powerreal(:,[56]));

ax= [ax subplot(4,4,2)]; plot(res.simtime(:,1), res.reactivepower(:,[16:34]));
ax= [ax subplot(4,4,6)]; plot(res.simtime(:,1), res.reactivepower(:,[52]));
ax= [ax subplot(4,4,10)]; plot(res.simtime(:,1), res.reactivepower(:,[55]));
ax= [ax subplot(4,4,14)]; plot(res.simtime(:,1), res.reactivepower(:,[56]));

ax= [ax subplot(4,4,3)]; plot(res.simtime(:,1), res.voltage(:,[16:34]));
ax= [ax subplot(4,4,7)]; plot(res.simtime(:,1), res.voltage(:,[52]));
ax= [ax subplot(4,4,11)]; plot(res.simtime(:,1), res.voltage(:,[55]));
ax= [ax subplot(4,4,15)]; plot(res.simtime(:,1), res.voltage(:,[56]));

ax= [ax subplot(4,4,4)]; plot(res.simtime(:,1), res.breaker(:,[16:34]));
ax= [ax subplot(4,4,8)]; plot(res.simtime(:,1), res.breaker(:,[52]));
ax= [ax subplot(4,4,12)]; plot(res.simtime(:,1), res.breaker(:,[55]));
ax= [ax subplot(4,4,16)]; plot(res.simtime(:,1), res.breaker(:,[56]));

linkaxes(ax,'x');

%% Feeder 3
fh = figure();
annotation(fh, 'TextBox', 'string', 'Feeder 3', 'position', [0.2 0.95 0.6 0.05]);
ax= subplot(3,4,1); plot(res.simtime(:,1), res.powerreal(:,[35:44]));
ax= [ax subplot(3,4,5)]; plot(res.simtime(:,1), res.powerreal(:,[53]));
ax= [ax subplot(3,4,9)]; plot(res.simtime(:,1), res.powerreal(:,[57]));

ax= [ax subplot(3,4,2)]; plot(res.simtime(:,1), res.reactivepower(:,[35:44]));
ax= [ax subplot(3,4,6)]; plot(res.simtime(:,1), res.reactivepower(:,[53]));
ax= [ax subplot(3,4,10)]; plot(res.simtime(:,1), res.reactivepower(:,[57]));

ax= [ax subplot(3,4,3)]; plot(res.simtime(:,1), res.voltage(:,[35:44]));
ax= [ax subplot(3,4,7)]; plot(res.simtime(:,1), res.voltage(:,[53]));
ax= [ax subplot(3,4,11)]; plot(res.simtime(:,1), res.voltage(:,[57]));

ax= [ax subplot(3,4,4)]; plot(res.simtime(:,1), res.breaker(:,[2:15]));
ax= [ax subplot(3,4,8)]; plot(res.simtime(:,1), res.breaker(:,[53]));
ax= [ax subplot(3,4,12)]; plot(res.simtime(:,1), res.breaker(:,[57]));

linkaxes(ax,'x');