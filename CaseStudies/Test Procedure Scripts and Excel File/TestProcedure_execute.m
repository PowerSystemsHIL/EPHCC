function [y,n1] = TestProcedure_execute(u,CMD_signals,n)
% Author: Matthew Backes, MIT Lincoln Laboratory
% Date: 8/16/2016
% This function takes in the test sequence signals from a .mat file which
% is generated with the ____.m script. It then updates the parameters
% within the simulink model according to the time stamp of the test
% sequence command signals.
% CMD column 1 = time
% CMD column 2 = POI feeder 1 SEL relay
% CMD column 3 = POI feeder 2 SEL relay
% CMD column 4 = POI feeder 3 SEL relay
% CMD column 5 = diesel breaker
% CMD column 6 = solar irradiance gain
% CMD column 7 = solar breaker
% CMD column 8 = CHP breaker
% CMD column 9 = load gain
% CMD column 10 = motor 1 breaker
% CMD column 11 = motor 2 breaker
% CMD column 12 = fault location 1
% CMD column 13 = fault location 2
% CMD column 14 = fault location 3
% CMD column 15 = fault location 4
% CMD column 16 = fault location 5
% CMD column 17 = fault location 6
% CMD column 18 = fault location 7
% CMD column 19 = fault location 8
%
% NEXT SECTION IS 13 DSO OUTPUT COMMANDS
%
% CMD column 20 = dso Disconnect command
% CMD column 21 = dso Reconnect command
% CMD column 22 = dso Export command
% CMD column 23 = dso Import command
% CMD column 24 = dso power factor command
% CMD column 25 = dso VAR support command
% CMD column 26 = dso Demand Response command
% CMD column 27 = dso Import/export value
% CMD column 28 = dso power factor value
% CMD column 29 = dso VAR value
% CMD column 30 = dso DR value
% CMD column 31 = dso Command start time
% CMD column 32 = dso command duration

y = u;

coder.extrinsic('set_param') %declare set_param as an extrinsic function
coder.extrinsic('num2str') %declare num2str as an extrinsic function
coder.extrinsic('tcpip')

time = CMD_signals(:,1); 
%time_lastCMD = time(length(time)); %do i need this anymore?
numCMDs = length(time);
DMS_ipaddr = '192.168.10.40';
POI_F1_ipaddr = '192.168.10.41';
POI_F2_ipaddr = '192.168.10.42';
POI_F3_ipaddr = '192.168.10.43';
port = 512;

handles.tcp=tcpip(DMS_ipaddr, port,'Timeout',1);    %Create the tcpip object
set(handles.tcp, 'InputBufferSize', 512);       %assign the buffer
handles.tcp.ByteOrder='bigEndian';              %specify the order in which bytes are transmitted

handles.connected=0;                            %default is not connected
% try 
    if ~strcmp(handles.tcp.Status,'open')       %if not open then 
        fopen(handles.tcp);                     %open a connection
        handles.connected = 1;                  %connected
    end


if n > numCMDs   %do nothing if we have exhausted all commands
    n1 = n;
else
    if u > time(n) % when the simulation time is greater than the command signal time, execute set_param
        n1 = n+1; % increment to next command to execute
        
        %parameters to set within simulink model
        set_param('testScript_model/TestCommands','diesel_breaker',num2str(CMD_signals(n,5)),'pv_breaker',num2str(CMD_signals(n,7)),'CHP_breaker',num2str(CMD_signals(n,8)),'load_gain',num2str(CMD_signals(n,9)),'motor1_breaker',num2str(CMD_signals(n,10)),'motor2_breaker',num2str(CMD_signals(n,11)),'fault1',num2str(CMD_signals(n,12)),'fault2',num2str(CMD_signals(n,13)),'fault3',num2str(CMD_signals(n,14)),'fault4',num2str(CMD_signals(n,15)),'fault5',num2str(CMD_signals(n,16)),'fault6',num2str(CMD_signals(n,17)),'fault7',num2str(CMD_signals(n,18)),'fault8',num2str(CMD_signals(n,19)));
        
        %modbus commands
%         if CMD_signals(n,2) == 1    %if 1, then POI_1 should be open -> issue Modbus command
%             ctrl_device_DMS_modbus(POI_F1_ipaddr,502,[20,0,6,1,6,hex2dec('2000'),2]);
%         else
%             ctrl_device_DMS_modbus(POI_F1_ipaddr,502,[20,0,6,1,6,hex2dec('2001'),1]);
%         end
%         if CMD_signals(n,3) == 1
%             ctrl_device_DMS_modbus(POI_F2_ipaddr,502,[20,0, 6, 1, 6, 2000, 2]);
%         else
%             ctrl_device_DMS_modbus(POI_F2_ipaddr,502,[20,0,6,1,6,2001,1]);
%         end
%         if CMD_signals(n,4) == 1
%             ctrl_device_DMS_modbus(POI_F3_ipaddr,502,[20,0,6,1,6,2000,2]);
%         else
%             ctrl_device_DMS_modbus(POI_F3_ipaddr,502,[20,0,6,1,6,2001,1]);
%         end
%         
%         if dsoDisconnect(n) == 1 
%             ctrl_device_DMS_modbus(DMS_ipaddr,502,[10, 0, 6, 1, 6, 0000, 1]); %do i need to reset this?
%         end
%         if dsoReconnect(n) == 1 
%             ctrl_device_DMS_modbus(DMS_ipaddr,502,[10, 0, 6, 1, 6, 0001, 1]);
%         end
%         if dsoExport(n) == 1
%             ctrl_device_DMS_modbus(DMS_ipaddr,502,[10, 0, 6, 1, 6, 0002, 1]);
%             ctrl_device_DMS_modbus(DMS_ipaddr,502,[10, 0, 6, 1, 6, 0007, CMD_Signals(n,27)]);
%         end
%         if dsoImport(n) == 1
%             ctrl_device_DMS_modbus(DMS_ipaddr,502,[10, 0, 6, 1, 6, 0003, 1]);
%             ctrl_device_DMS_modbus(DMS_ipaddr,502,[10, 0, 6, 1, 6, 0007, CMD_Signals(n,27)]);
%         end
%         if dsoPF(n) == 1 
%             ctrl_device_DMS_modbus(DMS_ipaddr,502,[10, 0, 6, 1, 6, 0004, 1]);
%             ctrl_device_DMS_modbus(DMS_ipaddr,502,[10, 0, 6, 1, 6, 0008, CMD_Signals(n,28)]);
%         end
%         if dsoVAR(n) == 1
%             ctrl_device_DMS_modbus(DMS_ipaddr,502,[10, 0, 6, 1, 6, 0005, 1]);
%             ctrl_device_DMS_modbus(DMS_ipaddr,502,[10, 0, 6, 1, 6, 0009, CMD_Signals(n,29)]);
%         end
%         if dsoDR(n) == 1
%             ctrl_device_DMS_modbus(DMS_ipaddr,502,[10, 0, 6, 1, 6, 0006, 1]);
%             ctrl_device_DMS_modbus(DMS_ipaddr,502,[10, 0, 6, 1, 6, 0010, CMD_Signals(n,30)]);
%         end
%         
%         ctrl_device_DMS_modbus(DMS_ipaddr,502,[10, 0, 6, 1, 6, 0011, u]);
%         ctrl_device_DMS_modbus(DMS_ipaddr,502,[10, 0, 6, 1, 6, 0012, CMD_Signals(n,31)]);
%         ctrl_device_DMS_modbus(DMS_ipaddr,502,[10, 0, 6, 1, 6, 0013, CMD_Signals(n,32)]);
        
     else  % wait until the simulation time has eclisped the next command time
        n1 = n; 
    end
end