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

%try

    for i=1:20000
        len=pnet(udp,'readpacket');
        if len>0
            u8data=pnet(udp,'read',2000,'uint8');
            [datastruct header] = UDP_decode(BANSHEEUDP, u8data);
            disp(['Gen1_ctrl :' num2str(datastruct.gen1_ctrl) '|| Gen2_ctrl :' num2str(datastruct.gen2_ctrl) '|| Gen3_ctrl :' num2str(datastruct.gen3_ctrl) ]);
        end
        pause(0.001);
    end
    disp('Data capture complete. Closing port...');
    pnet(udp, 'close');
