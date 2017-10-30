clear all;

BANSHEEUDP = BANSHEE_Frame();


T0 = now;
udp=pnet('udpsocket',7200)
len=pnet(udp,'readpacket');
while(len>0)
    u8data=pnet(udp,'read',2000,'uint8');
    len=pnet(udp,'readpacket');
    disp('.');
end

%try8

    for i=1:20000
        len=pnet(udp,'readpacket');
        if len>0
            u8data=pnet(udp,'read',2000,'uint8');
            [datastruct header] = UDP_decode(BANSHEEUDP, u8data);
            disp(['Ess1_ctrl :' num2str(datastruct.ess1_ctrl) '|| Ess2_ctrl :' num2str(datastruct.ess2_ctrl) '|| PV1_ctrl :' num2str(datastruct.pv1_ctrl) '|| PV2_ctrl :' num2str(datastruct.pv2_ctrl) ]);
        end
        pause(0.001);
    end
    disp('Data capture complete. Closing port...');
    pnet(udp, 'close');
