function [dataout header] = UDP_decode(FrameStruct, u8data)

u32data = typecast(u8data, 'uint32');
            
header = [];
data = [];
ptr = 1;
for i=1:length(FrameStruct)
    %item size
    if ischar(FrameStruct{i}.Size)
        ItemSize = eval(['header.' FrameStruct{i}.Size]);
    else
        ItemSize = FrameStruct{i}.Size;
    end
    
    % header extraction
    if isfield(FrameStruct{i}, 'Header')
        eval(['header.' FrameStruct{i}.Header ' = u32data(ptr:ptr-1+' num2str(FrameStruct{i}.Size) ');']);
        if strcmp(FrameStruct{i}.Header,'Misc')
            for i=1:header.Misc(1)
                misccfg = u32data(ptr+1:ptr+2);
                eval(['header.Misc_' num2str(i) ' = misccfg;']);
                ptr = ptr+2;
            end
        end
    end
    

    
    % extract data that shall be stored in files and put them in a struct
    % with name of the file as fieldname
    if isfield(FrameStruct{i}, 'File')
        eval(['dataout.' FrameStruct{i}.Name ' = u32data(ptr:ptr-1+' num2str(ItemSize) ');']);
        
        
    end
    
    ptr = ptr + ItemSize;

end