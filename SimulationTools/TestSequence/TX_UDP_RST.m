%clear all;

BANSHEEUDP = BANSHEE_Frame();

load seq.mat; % load information about test sequence

udp=pnet('udpsocket',7200)

i16data = seq.udpframe(:,1);
u8data = typecast(swapbytes(i16data), 'uint8');            

% write to socket
pnet(udp,'write',u8data);
pnet(udp,'writepacket','10.79.111.63',7200);
pnet(udp, 'close');
