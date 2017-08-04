function [ output_args ] = wsp2struct( input_args )
%WSP2STRUCT Summary of this function goes here
%   Detailed explanation goes here
    if length(input_args)==0;
        output_args='clear';
    else
        for k=1:length(input_args),
            TempVar=evalin('caller',input_args{k});
            eval(['output_args.' input_args{k} '=TempVar;']);
        end;
    end;
end

