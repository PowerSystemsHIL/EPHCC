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

%BANSHEEUDP = BANSHEE_Frame();
BANSHEEUDP = PHIL_Frame();
LoadStoredData(BANSHEEUDP, pwd);

%%
udp=pnet('udpsocket',7101)
try

    for i=40:600
            datastr = SelectDataStruct(BANSHEEUDP,i);
            u8data = UDP_Encode(BANSHEEUDP, header, datastr);
            
            % write to
            pnet(udp,'write',u8data);
            pnet(udp,'writepacket','10.79.112.33',7201);
            disp([num2str(i) ':' num2str(datastr.breaker4(1:13))]);
            disp(['  :' num2str(datastr.powerreal4(1:13))]);
            disp(['  :' num2str(datastr.voltage4(1:13))]);
                
        pause(1);
    end
    disp('Succesful transmision of messages. Closing udp port');
    pnet(udp, 'close');
catch
  %always close port
   disp('Filed to transmit messages. Closing udp port');
   pnet(udp, 'close');
end;

