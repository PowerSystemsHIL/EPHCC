figure;
plotid = kpp5.iB.B101;

ax = [];
ax= [ax subplot(4,1,1)]; plot(seqi.t, res.quality_Hz(:,plotid)); 
                         
ax= [ax subplot(4,1,2)]; plot(seqi.t, res.frequency(:,kpp5.iPQ(plotid)));
ax= [ax subplot(4,1,3)]; plot(seqi.t, res.quality_Volt(:,plotid)); 
ax= [ax subplot(4,1,4)]; plot(seqi.t, res.voltage(:,kpp5.iPQ(plotid)));                        

linkaxes(ax,'x');