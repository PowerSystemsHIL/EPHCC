function [ out_volt ] = gen_volt( opt, in_volt )
%CLOUD Summary of this function goes here
%   Detailed explanation goes here

% Check required fields
if ~isfield(opt.Grid, 'Volt')
   error ('''Grid.Volt'' field must exist in configuration struct');
end

pat = 1-[1	0.9	0.8	0.7	0.6	0.5	0.4	0.3	0.2	0.1	0	0.1	0.2	0.3	0.4	0.5	0.6	0.7	0.8	0.9	1];
plen = length(pat);

out_volt = in_volt;
for i=1:length(opt.Grid.Volt)
    % Check required fields
    required = {'Start', 'Depth', 'Duration'};
    for rr = 1:length(required)
        if (~isfield(opt.Grid.Volt(i), required{rr}))
            error (['''' required{rr} ''' field must exist in configuration struct']);
        end
    end
    start = opt.Grid.Volt(i).Start;
    depth = opt.Grid.Volt(i).Depth;
    dur = opt.Grid.Volt(i).Duration;
    pat1 = interp1(0:dur/(plen-1):dur, pat, 0:opt.Ts:dur);
    pat1 = pat1*depth;
    dv =  [zeros(1,start/opt.Ts) ...
                pat1 ...
                zeros(1,(opt.End-dur-start)/opt.Ts)];
   
%     l = min(length(cloud_pat), length(out_irrad));
%     out_irrad(1:l) =  cloud_pat(1:l).*out_irrad(1:l);
    out_volt = out_volt + dv;
end

end