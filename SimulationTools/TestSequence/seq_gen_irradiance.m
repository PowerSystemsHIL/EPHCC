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

function [ out_irrad ] = seq_gen_irradiance( opt )
%IRRADIANCE Summary of this function goes here
%   Detailed explanation goes here
% Check required fields
if (~isfield(opt, 'Irradiance'))
   error (['''Irradiance'' field must exist in configuration struct']);
end

if (isfield(opt.Irradiance, 'Fixed'))
    out_irrad  = opt.Irradiance.Fixed * ones(1,opt.N);
else
    % PV profile
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

end