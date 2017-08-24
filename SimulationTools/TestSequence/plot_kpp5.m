figure;
plotid = kpp5.iB.B201;

ax = [];
ax= [ax subplot(4,1,1)]; plot(comm.t_min, res.quality_Hz(:,plotid)); 
                         
ax= [ax subplot(4,1,2)]; plot(comm.t_min, res.frequency(:,kpp5.iPQ(plotid)));
ax= [ax subplot(4,1,3)]; plot(comm.t_min, res.quality_Volt(:,plotid)); 
ax= [ax subplot(4,1,4)]; plot(comm.t_min, res.voltage(:,kpp5.iPQ(plotid)));                        

linkaxes(ax,'x');