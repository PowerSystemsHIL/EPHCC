%% Copyright 2018 Alliance for Sustainable Energy, LLC
%
% Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
% and associated documentation files (the "Software"), to deal in the Software without restriction, 
% including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
% and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, 
% subject to the following conditions:
%
% The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
%
% THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
% BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
% NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS, THE COPYRIGHT HOLDERS, THE UNITED STATES, 
% THE UNITED STATES DEPARTMENT OF ENERGY, OR ANY OF THEIR EMPLOYEES BE LIABLE FOR ANY CLAIM, 
% DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
% OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
%
% Author: Przemyslaw Koralewicz / NREL
% Date: 2017

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
