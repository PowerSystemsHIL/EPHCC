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

function [ out_freq ] = seq_gen_freq( opt, in_freq )
%CLOUD Summary of this function goes here
%   Detailed explanation goes here

% Check required fields
if ~isfield(opt.Grid, 'Freq')
    warning ('''Grid.Freq'' field must exist in configuration struct');
    out_freq = in_freq;
else

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
end