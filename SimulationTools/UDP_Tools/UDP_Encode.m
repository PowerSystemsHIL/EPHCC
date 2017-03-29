function [u8data] = UDP_encode(FrameStruct, header, datastruct)

        
i32data = [];
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
        i32data = [i32data int32(eval(['header.' FrameStruct{i}.Header]))];
        if strcmp(FrameStruct{i}.Header,'Misc')
            for i=1:header.Misc(1)
                i32data = [i32data eval(['header.Misc_' num2str(i)])];
                ptr = ptr+2;
            end
        end
    elseif isfield(FrameStruct{i}, 'File')
        i32data = [i32data eval(['datastruct.' FrameStruct{i}.Name])];
    else
        i32data = [i32data zeros(1,ItemSize)];
    end
    
    ptr = ptr + ItemSize;

end

u8data = typecast(i32data, 'uint8');
