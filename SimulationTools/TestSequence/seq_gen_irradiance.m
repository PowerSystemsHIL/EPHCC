function [ out_irrad ] = seq_gen_irradiance( opt )
%IRRADIANCE Summary of this function goes here
%   Detailed explanation goes here

% Check required fields
if (~isfield(opt, 'Irradiance'))
   error (['''Irradiance'' field must exist in configuration struct']);
end
required = {'Rise', 'RiseDuration'};
    for rr = 1:length(required)
        if (~isfield(opt.Irradiance, required{rr}))
            error (['''' required{rr} ''' field must exist in configuration struct']);
        end
    end    
    
dur = opt.Irradiance.RiseDuration;
start = opt.Irradiance.Rise;
pat1 = [0 0.05 0.25 0.50 0.70 0.85 0.90 0.93 0.95 0.98 1.00];
t1 = [0:dur/(length(pat1)-1):dur];
t  = [0:opt.Ts:dur];
pat = interp1(t1, pat1, t);

out_irrad = [zeros(1,start/opt.Ts), pat, ones(1,(opt.End-start-dur)/opt.Ts)];
end

