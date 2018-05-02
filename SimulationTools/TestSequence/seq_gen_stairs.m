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

