%% Copyright 2018 Alliance for Sustainable Energy, LLC
%
% Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
% and associated documentation files (the "Software"), to deal in the Software without restriction, 
% including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
% and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, 
% subject to the following conditions:
%
% The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
%
% THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
% BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
% NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS, THE COPYRIGHT HOLDERS, THE UNITED STATES, 
% THE UNITED STATES DEPARTMENT OF ENERGY, OR ANY OF THEIR EMPLOYEES BE LIABLE FOR ANY CLAIM, 
% DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
% OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
%
% Author: Przemyslaw Koralewicz / NREL
% Date: 2017

function [dataout header] = UDP_decode(FrameStruct, u8data)

i16data = swapbytes(typecast(u8data, 'int16'));
            
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
        eval(['dataout.' FrameStruct{i}.Name ' = double(i16data(ptr:ptr-1+' num2str(ItemSize) '));']);
        
        
    end
    
    ptr = ptr + ItemSize;

end