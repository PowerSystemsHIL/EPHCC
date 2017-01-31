function plotLoad(f,f_sum,title_text)
  
figure; hold on;
for i=1:length(f); 
    plot(f(i).time, f(i).kw); 
    legText{i} = f(i).name;
end
ylabel('kW on Individual Loads');
ax = gca;
yyaxis right;
ax.YColor = [0 0 0]; %black
plot(f_sum.time, f_sum.kw, 'LineWidth',3,'Color','k');
legText{i+1} = f_sum.name;
ylabel('kW Load Total (Bold trace)');
legend(legText,'Location','eastoutside');
title([title_text ', Loading (kW)']);

figure; hold on;
for i=1:length(f); 
    plot(f(i).time, f(i).kvar); 
    legText{i} = f(i).name;
end
ylabel('kVar on Individual Loads');
ax = gca; 
yyaxis right;
ax.YColor = [0 0 0]; %black
plot(f_sum.time, f_sum.kvar, 'LineWidth',3,'Color','k');
legText{i+1} = f_sum.name;
ylabel('kVar Load Total (Bold trace)');
legend(legText,'Location','eastoutside');
title([title_text ', Loading (kVar)']);
