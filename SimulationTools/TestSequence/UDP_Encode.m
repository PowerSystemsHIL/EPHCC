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
