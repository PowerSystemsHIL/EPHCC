function [ vect ] = seq_gen_stairs( opt, fieldname )
%GEN_PWL Summary of this function goes here
%   Detailed explanation goes here
    str = eval(['opt.' fieldname]);
    
    % Check required fields
    required = {'Val', 'Time'};
    for rr = 1:length(required)
        if (~isfield(str, required{rr}))
            error (['''' required{rr} ''' field must exist in configuration struct: ' opt '.' fieldname]);
        end
    end
    M = length(str.Val);
    vect = ones(1,opt.N)*str.Val(1);
    for i=1:M
        nstep = 1 + str.Time(i)/opt.Ts;
        vect(nstep:opt.N) = str.Val(i);
    end
        
end

