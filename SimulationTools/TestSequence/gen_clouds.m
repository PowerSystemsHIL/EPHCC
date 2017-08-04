function [ out_irrad ] = gen_clouds( opt, in_irrad, delay )
%CLOUD Summary of this function goes here
%   Detailed explanation goes here

% Check required fields
if ~isfield(opt, 'Cloud')
   error ('''Cloud'' field must exist in configuration struct');
end

out_irrad = in_irrad;
for i=1:length(opt.Cloud)
    % Check required fields
    required = {'Start', 'Depth', 'Ramp', 'Duration'};
    for rr = 1:length(required)
        if (~isfield(opt.Cloud(i), required{rr}))
            error (['''' required{rr} ''' field must exist in configuration struct']);
        end
    end
        
    start = opt.Cloud(i).Start + delay;
    depth = opt.Cloud(i).Depth;
    slope = depth/opt.Cloud(i).Ramp*opt.Ts;
    cloud_pat = [ones(1,start/opt.Ts) ...
                1:-slope:(1-depth) ...
                (1-depth)*ones(1,opt.Cloud(i).Duration/opt.Ts) ...
                (1-depth):slope:1 ...
                ones(1,(opt.End-2*opt.Cloud(i).Ramp-opt.Cloud(i).Duration-start)/opt.Ts)];
   
    l = min(length(cloud_pat), length(out_irrad));
    out_irrad(1:l) =  cloud_pat(1:l).*out_irrad(1:l);
end

end