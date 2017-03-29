function LoadStoredData( FrameStruct, Path )
%LOADSTOREDDATA Summary of this function goes here
%   Detailed explanation goes here
    store_path = pwd;    
    try
        cd(Path)
        for i=1:length(FrameStruct)
           if isfield(FrameStruct{i}, 'File')
              filename = FrameStruct{i}.File;
              evalin('base', ['load ' filename]); 
           end
        end
        evalin('base', 'load header;');
    catch
        cd(store_path);
        error('Error during loading of files');
    end
    disp(['Sucessful loading of data from: ' Path]);
    cd(store_path);
end

