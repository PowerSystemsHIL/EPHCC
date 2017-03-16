% Copyright (c) 2015 Massachusetts Institute of Technology
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




%% Initialization file for Battery Energy Storage and Inverter block.  Called in mask workspace.
% Inputs:
%   max_power, batt_kWh, VacRMS, Vdc_nom, droop_gain?
% Outputs:
%   IacRMS, Vdc_max, Iac_max, L, C, Roff, Id_at_max, Iq_at_max
%   I_kp, I_ki, PLL_Ki, PLL_Kp, PLL_lock_window, PLL_freq_range, batt_esr 

%% Check some things and choose IGBT ratings
if Vdc_nom < VacRMS*sqrt(2)*sqrt(3)
    error('VacRMS too high for nominal battery voltage.');
end
IacRMS = max_power/VacRMS/3;

IGBT_voltages = [600 1200 1700 3300 4500 6500];
IGBT_currents = [100 300 600 1200 2400];
possible_voltages = find(Vdc_nom*1.4 < IGBT_voltages);
possible_currents = find(IacRMS*1.5 < IGBT_currents);
Vdc_max = IGBT_voltages(possible_voltages(1)) % take lowest voltage ratting
Iac_max = IGBT_currents(possible_currents(1)) % rated current of unit

fs = 10e3;  % switching frequency, could be made configurable upstream?

% assume 20% inductor ripple (peak to  nom) @ 50% duty
L = Vdc_nom/(IacRMS*0.2/(2/fs))  % boost inductor
% capacitors are sized by heating due to RMS current, 18uF/Iac
C = IacRMS*18e-6;  % DC capacitance
Roff = 1e7; % IGBT off resistance, larger for more correct sim, smaller makes it faster!
%Roff = 1e3;

batt_esr = (max_power*0.01)/(max_power/Vdc_nom)^2;  % 1% of full power loss assumption

[max_pow, rms_inv_volts, ang_deg] = CalcVandAngforMaxPower(VacRMS, Vdc_nom, L);
[Vd_at_max, Vq_at_max] = pol2cart(deg2rad(ang_deg), rms_inv_volts*sqrt(2))
Id_at_max = 3*max_pow*(2/3)/Vd_at_max % assuming PF of 1

[max_Qpow, rms_inv_Qvolts, Qang_deg] = CalcVandAngforMaxQPower(VacRMS, Vdc_nom, L);
[Vd_at_Qmax, Vq_at_Qmax] = pol2cart(deg2rad(Qang_deg), rms_inv_Qvolts*sqrt(2))
Iq_at_max = 3*max_pow*(2/3)/Vq_at_max %

%% Current controller

I_kp = 0.05;
I_ki = 0.03;

%% Pll stuff
PLL_Ki = 0.001*30;
PLL_Kp =.001*30;
PLL_lock_window = 0.05; % % of Vq tolerated for lock status
PLL_freq_range = 0.1; % lock freq range is f*(1+/-range)
% PLL_PI_comp = PLL_Kp + PLL_Ki*(1/s);