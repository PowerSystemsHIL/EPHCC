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

load seq.mat; % load information about test sequence

udp=pnet('udpsocket',7200)
len=pnet(udp,'readpacket');
while(len>0)
    u8data=pnet(udp,'read',2000,'uint8');
    len=pnet(udp,'readpacket');
    disp('.');
end

TxDecimate = 10;      %Tx Send evey TxDecimate frame only
TxSequenceSpeed = TxDecimate; %Tx sequence speed multipier
nextTXd = 1;         %Indice of starting TX frame
T0 = now - seq.t(nextTXd)/60/60/24/TxSequenceSpeed;   % Set test sequence time reference;
timestamp = 0;
lastTxd = seq.opt.N;
%try
tic;
    while nextTXd<=lastTxd  %Loop until TXd frame no (<-) is sent
        timeMs = round((now-T0)*24*60*60*1000)*TxSequenceSpeed;
        if (seq.t(nextTXd) <= timeMs/1000)
            i16data = seq.udpframe(:,nextTXd);
            u8data = typecast(swapbytes(i16data), 'uint8');            
            % write to socket
            pnet(udp,'write',u8data);
            pnet(udp,'writepacket','10.79.111.63',7200);
            nextTXd = nextTXd + TxDecimate;
            %disp(['TX-' num2str(timeMs) ':' num2str(seq.price(nextTXd))]);
            disp(['T' num2str(nextTXd)]); 
        end;
        len=pnet(udp,'readpacket');
        if len>0
            u8data=pnet(udp,'read',2000,'uint8');
            [datastruct header] = UDP_decode(BANSHEEUDP, u8data);
            lasttimestamp = timestamp;
            timestamp = round((now-T0)*24*60*60*1000);
            filenames = fieldnames(datastruct);
            for jj=1:length(filenames)
                newrow = [timestamp eval(['datastruct.' filenames{jj}])];
                if exist(filenames{jj},'var')
                    eval([filenames{jj} '= [' filenames{jj} ';newrow];']);
                else
                    eval([filenames{jj} '= newrow;']);
                end
            end
            %disp(['RX-' num2str(timestamp) ':' num2str(timestamp-lasttimestamp) ':' num2str(datastruct.misc_2)]);
            %disp(num2str(newrow));
            disp('R');
        end
        pause(0.001);
    end
    toc;
    disp('Data capture complete. Closing port...');
    pnet(udp, 'close');
%catch
   %always close port
   %disp('Error during data capture. Closing port...');
   % pnet(udp, 'close');
%end;
%% Data type conversions
%int16 -> uint16
breaker(breaker<0) = breaker(breaker<0) + 2^16;

%% Store data to .dat files
for jj=1:length(filenames)
    if exist(filenames{jj},'var')
        dlmwrite([filenames{jj} '.dat'],eval(filenames{jj}),'newline','pc');
    end;
end
save header.mat header;

%%
temp = eval(filenames{1});
res.t = temp(:,1);
for k=1:length(filenames),
            temp = eval(filenames{k});
            N=size(temp,2);
            eval(['res.' filenames{k} '= temp(:,2:N);']);
        end;
        
save res.mat;