function data = SelectDataStruct(FrameStruct, index)

for i=1:length(FrameStruct)
    if isfield(FrameStruct{i}, 'File')
        %item size

        %newdatastr = [num2str(FrameStruct{i}.Scale) '*' FrameStruct{i}.Name '(' num2str(index) ',2:' num2str(FrameStruct{i}.Size+1) ')'];
        newvalstr = [FrameStruct{i}.Name '(' num2str(index) ',2:end);'];
        newval = evalin('base', newvalstr);
        eval(['data.' FrameStruct{i}.Name '=newval;']);
    end
end
