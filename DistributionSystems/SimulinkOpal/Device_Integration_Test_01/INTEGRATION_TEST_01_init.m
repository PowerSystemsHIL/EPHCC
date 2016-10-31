% Copyright (c) 2016 Massachusetts Institute of Technology
% Permission is hereby granted, free of charge, to any person obtaining a copy of this 
% software and associated documentation files (the "Software"), to deal in the Software
% without restriction, including without limitation the rights to use, copy, modify, 
% merge, publish, distribute, sublicense, and/or sell copies of the Software, and to 
% permit persons to whom the Software is furnished to do so, subject to the following 
% conditions:
% 
% 
% The above copyright notice and this permission notice shall be included in 
% all copies or substantial portions of the Software.
% 
% THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
% INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
% PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
% HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION 
% OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
% SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
%
%
%%
clear;

components_path_init;

%% model configuration parameters
Ts = 100E-6; % integration time
SIM_HIL = 1; % control mode for NG_CHP [1: Woodward, 0: manual/simulation]

%% read relay settings
% reads-in all relay settings for the system and initializes vectors to
% hold these settings that will be called from the software relays
relay_settings_init;


%% cable parameters
% to be used for the PI sections
cable_impedance_init;

%% circuit breaker delays
% breaker mechanical open/close delay in seconds
% different delays may be applied to each breaker, however,
% for convenience it is assumed all breaker have the same delay 
cb_mech_delay = 5/60;

