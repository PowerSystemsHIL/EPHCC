clear all;
clear all;

opdaq_path = '..\..\..\RemoteCHIL\models\RemoteCHIL\RemoteCHIL_SS_F4_RELAY_HOUSING\OpREDHAWKtarget\A_FILE_RECORDED_';
opdaq_path = '..\..\..\UrbanCHIL2\models\UrbanCHIL\UrbanCHIL_SS_COMMUNICATION\OpREDHAWKtarget\A_FILE_RECORDED_';
opdaq_path = '..\..\..\UrbanCHIL2\models\UrbanCHIL\A_FILE_RECORDED_';
opdaq_path = '..\..\..\UrbanCHIL\models\UrbanCHIL\A_FILE_RECORDED_';
opdaq_path = 'Run66\A_FILE_RECORDED_';

dat_all = [];
tsim_all = [];
next_tsim = 0;
for i=1:1000
    
    if mod(i-1,2)==0
        suffix = 'e_';
    else
        suffix = 'o_';
    end;
    suffix = [suffix num2str(i-1)];
    if exist([opdaq_path suffix '.mat'], 'file')
        dat_str = load([opdaq_path suffix]);
        dat = eval(['dat_str.recVar_' num2str(i-1)]);
        if(~isempty(dat))
            t_sim = dat(5,:)*2^16 + dat(4,:);
            remove_i = t_sim<next_tsim;
            dat(:,remove_i) = [];
            t_sim(remove_i) = [];
            next_tsim = t_sim(end)+1;
            dat_all = [dat_all int16(dat(2:end,:))];
            tsim_all = [tsim_all t_sim];
            disp([num2str(i-1) ': ' num2str(t_sim([1:5 end-4:end]))]);
        end;
    end
end

tsim_all = uint32(tsim_all - tsim_all(1));

save('opdaq_proc', 'dat_all', 'tsim_all');

% %% Convert raw data into result file
% BANSHEEUDP = BANSHEE_Frame();
% dat_all(25,:) = 23;
% % for i=1:length(tsim_all)
% %             u8data = typecast(swapbytes(dat_all(:,i)),'uint8')';
% %             [datastruct header] = UDP_decode(BANSHEEUDP, u8data);
% %             timestamp = tsim_all(i);
% %             filenames = fieldnames(datastruct);
% %             for jj=1:length(filenames)
% %                 newrow = [timestamp eval(['datastruct.' filenames{jj}])];
% %                 if exist(filenames{jj},'var')
% %                     eval([filenames{jj} '= [' filenames{jj} ';newrow];']);
% %                 else
% %                     eval([filenames{jj} '= newrow;']);
% %                 end
% %             end
% %             %disp(['RX-' num2str(timestamp) ':' num2str(timestamp-lasttimestamp) ':' num2str(datastruct.misc_2)]);
% %             %disp(num2str(newrow));
% %            
% % end
% 
% [res header] = UDP_decode_all(BANSHEEUDP, dat_all);
% 
% %% Data type conversions
% %int16 -> uint16
% res.breaker(res.breaker<0) = res.breaker(res.breaker<0) + 2^16;
% 
% %% Store data to .dat files
% save header.mat header;
% 
% %%
% res.t = double(tsim_all);
% save res.mat;