opdaq_path = 'RemoteCHIL_SS_F4_RELAY_HOUSING\OpREDHAWKtarget\A_FILE_RECORDED_';
opdaq_path = 'UrbanCHIL_SS_COMMUNICATION\OpREDHAWKtarget\A_FILE_RECORDED_';
%opdaq_path = 'A_FILE_RECORDED_';

dat_all = [];
tsim_all = [];
next_tsim = 0;
for i=1:100
    
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
            dat_all = [dat_all uint16(dat(2:end,:))];
            tsim_all = [tsim_all t_sim];
            disp([num2str(i-1) ': ' num2str(t_sim([1:5 end-4:end]))]);
        end;
    end
end

tsim_all = uint32(tsim_all - tsim_all(1));

save('opdaq_proc', 'dat_all', 'tsim_all');

%% Convert raw data into result file
BANSHEEUDP = BANSHEE_Frame();
dat_all(25,:) = 23;
for i=1:length(tsim_all)
            u8data = typecast(swapbytes(dat_all(:,i)),'uint8')';
            [datastruct header] = UDP_decode(BANSHEEUDP, u8data);
            timestamp = tsim_all(i);
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
           
end
%% Data type conversions
%int16 -> uint16
breaker(breaker<0) = breaker(breaker<0) + 2^16;

%% Store data to .dat files
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