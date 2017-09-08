function save_figs(fh, filename, savefig, savepng)
    for i=1:length(fh)
        print(fh(i), '-dpng' ,'-r300', [filename num2str(i)]); % ,['-r' num2str(saveDPI)]
    end;
end