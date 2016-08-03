% CREATED BY: REYNALDO SALCEDO
% LAST CHANGE BY : REYNALDO SALCEDO
% GROUP: 73
% DATE MODIFIED  : 04/13/2016
%

function rs_relay_OpalCfg_function( file_name, index )
% This function creates all the xls files indicating the register
% configuration for the relays of each feeders. The ip address changes
% dynamically based on the input value k. The file name will end with the
% file_name: string
% index: interger
%

ip_address = ['192.168.10.', num2str(index)];

A = {'Modbus device configuration';
    '';
    'Block name';
    'Device name';
    'Device type';
    'Protocol';
    'IP address';
    'Port';
    'Slave ID';
    'Verbose';
    'Addresses of coil inputs';
    'Addresses of coil outputs';
    'Addresses of discrete inputs';
    'Addresses of holding register inputs';
    'Addresses of holding register outputs';
    'Addresses of input registers';
    'Polling frequency (ms)';};

B = {'';
    '';
    'Modbus_device';
    'modbus_slv';
    'Slave';
    'TCP';
    ip_address;
    '502';
    '17';
    '0';
    '0';
    '0';
    '0';
    '0';
    '2000-2001';
    '0-1-2-3-4-5-6-7-8-9-10-11-12-13-14-15-16-17-18-19-20-21-22-23-24';
    '100';};

AB = [A B];
xlswrite(file_name, AB);

end

