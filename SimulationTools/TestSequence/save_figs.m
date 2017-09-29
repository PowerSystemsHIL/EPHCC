function save_figs(fh, filename, savefig, savepng)
    for i=1:length(fh)
        plotsizeinch = [12 15];
        saveDPI = 300;
        set(fh(i),'PaperUnits','inches');
        set(fh(i),'PaperSize', plotsizeinch);
        set(fh(i),'PaperUnits','normalized');
        %set(gcf,'PaperPosition',[0.1,0.1,0.9,0.9]);
        set(fh(i),'PaperPositionMode','auto')
        set(fh(i),'PaperPosition',[0,0,1,1]);
        set(fh(i),'Position',[0 0 plotsizeinch]*saveDPI);
        print(fh(i), '-dpng' ,['-r' num2str(saveDPI)], [filename num2str(i)]); % ,['-r' num2str(saveDPI)]
    end;
end