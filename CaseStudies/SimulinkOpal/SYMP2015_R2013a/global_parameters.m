f = 60; % nominal grid frequency
Ts = 80e-6;
PLL_time_step = Ts;
Droop_control_time_step = Ts;
Td_es_min = Ts;
MPPT_ts = Ts;
Tds = Ts; % discrete time step for simulation

% voltage controller
vdc_cont_d = c2d(tf([0.0040 0.1000], [4.2217e-04 0.0398 0]), MPPT_ts);

