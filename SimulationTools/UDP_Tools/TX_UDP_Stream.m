clear all;

%BANSHEEUDP = BANSHEE_Frame();
BANSHEEUDP = PHIL_Frame();
LoadStoredData(BANSHEEUDP, pwd);

%%
udp=pnet('udpsocket',7101)
try

    for i=60:600
            datastr = SelectDataStruct(BANSHEEUDP,i);
            u8data = UDP_Encode(BANSHEEUDP, header, datastr);
            
            % write to
            pnet(udp,'write',u8data);
            pnet(udp,'writepacket','192.168.5.32',7201);
            disp([num2str(i) ':' num2str(datastr.breaker4(1:13))]);
            disp(['  :' num2str(datastr.powerreal4(1:13))]);
        
        pause(1);
    end
    disp('Succesful transmision of messages. Closing udp port');
    pnet(udp, 'close');
catch
  %always close port
   disp('Filed to transmit messages. Closing udp port');
   pnet(udp, 'close');
end;

