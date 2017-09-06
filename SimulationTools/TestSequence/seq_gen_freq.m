function [ out_freq ] = seq_gen_freq( opt, in_freq )
%CLOUD Summary of this function goes here
%   Detailed explanation goes here

% Check required fields
if ~isfield(opt.Grid, 'Freq')
   error ('''Grid.Freq'' field must exist in configuration struct');
end

pat = 1-[1	0.5	0.2	0.05	0	0.03	0.1	0.17	0.25	0.3	0.35	0.4	0.45	0.5	0.55	0.6	0.65	0.7	0.75	0.8	0.85	0.9	0.95	1];
plen = length(pat);

out_freq = in_freq;
for i=1:length(opt.Grid.Freq)
    % Check required fields
    required = {'Start', 'Depth', 'Duration'};
    for rr = 1:length(required)
        if (~isfield(opt.Grid.Freq(i), required{rr}))
            error (['''' required{rr} ''' field must exist in configuration struct']);
        end
    end
    start = opt.Grid.Freq(i).Start;
    depth = opt.Grid.Freq(i).Depth;
    dur = opt.Grid.Freq(i).Duration;
    pat1 = interp1(0:dur/(plen-1):dur, pat, 0:opt.Ts:dur);
    pat1 = pat1*depth;
    df =  [zeros(1,start/opt.Ts) ...
                pat1 ...
                zeros(1,(opt.End-dur-start)/opt.Ts)];
   
%     l = min(length(cloud_pat), length(out_irrad));
%     out_irrad(1:l) =  cloud_pat(1:l).*out_irrad(1:l);
    out_freq = out_freq + df;
end

end