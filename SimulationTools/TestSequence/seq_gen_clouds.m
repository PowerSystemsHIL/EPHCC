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

function [ out_irrad ] = seq_gen_clouds( opt, in_irrad, delay )
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