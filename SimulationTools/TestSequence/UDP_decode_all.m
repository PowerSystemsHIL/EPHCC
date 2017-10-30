function [dataout header] = UDP_decode_all(FrameStruct, i16data_all)

header = [];
data = [];
ptr = 1;
for i=1:length(FrameStruct)
    %item size
    i16data = i16data_all(:,1);
    if ischar(FrameStruct{i}.Size)
        ItemSize = eval(['header.' FrameStruct{i}.Size]);
    else
        ItemSize = FrameStruct{i}.Size;
    end
    
    % header extraction
    if isfield(FrameStruct{i}, 'Header')
        eval(['header.' FrameStruct{i}.Header ' = i16data(ptr:ptr-1+' num2str(FrameStruct{i}.Size) ');']);
        if strcmp(FrameStruct{i}.Header,'Misc')
            for iii=1:header.Misc(1)
                misccfg = i16data(ptr+1:ptr+2);
                eval(['header.Misc_' num2str(iii) ' = misccfg;']);
                ptr = ptr+2;
            end
        end
    end
    

    
    % extract data that shall be stored in files and put them in a struct
    % with name of the file as fieldname
    if isfield(FrameStruct{i}, 'File')
        eval(['dataout.' FrameStruct{i}.Name ' = double(i16data_all(ptr:ptr-1+' num2str(ItemSize) ',:))'';']);
        
        
    end
    
    ptr = ptr + ItemSize;

end