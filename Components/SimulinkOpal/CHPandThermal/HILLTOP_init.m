% CREATED BY: REYNALDO SALCEDO
% LAST CHANGE BY : REYNALDO SALCEDO
% GROUP: 73
% DATE MODIFIED  : 04/20/2016
%

%% model configuration parameters
Ts = 100E-6; 


%% read relay settings
% reads-in all relay settings for the system and initializes vectors to
% hold these settings that will be called from the software relays
relay_settings_init;
cb_mech_delay=[3 3]./60;



