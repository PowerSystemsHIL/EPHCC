% This script reads in the excel sheet that holds the test plan and converts
% it into the appropriate format to be used by the simulink model.
% Author: Matthew Backes
% Date: 8/16/2016

[num, txt, raw] = xlsread('TestProcedure_detailed','v1'); %v1 is the sheet name in the excel file

%% Column number variables - in case sheet gets reformatted
% the third row of the excel sheet is where to search for the column names

time_colnum = find(strcmp('time',txt(3,:)));
POI_colnum = find(strcmp('POI',txt(3,:)));
Diesel_colnum = find(strcmp('diesel_breaker',txt(3,:)));
SolarIrr_colnum = find(strcmp('pv_breaker',txt(3,:)));
CHP_colnum = find(strcmp('CHP_breaker',txt(3,:))); 
load_colnum = find(strcmp('load_gain',txt(3,:)));
motor_colnum = find(strcmp('motor',txt(3,:)));
fault_colnum = find(strcmp('fault',txt(3,:)));
dsoCommand_colnum = find(strcmp('dsoCommand',txt(3,:)));
dsoImportExportValue_colnum = find(strcmp('dsoImportExportValue',txt(3,:)));
dsoPFValue_colnum = find(strcmp('dsoPFValue',txt(3,:)));
dsoVarValue_colnum = find(strcmp('dsoVarValue',txt(3,:)));
dsoDRValue_colnum = find(strcmp('dsoDRValue',txt(3,:)));
dsoCommandStartTime_colnum = find(strcmp('dsoCommandStartTime',txt(3,:)));
dsoCommandDuration_colnum = find(strcmp('dsoCommandDuration',txt(3,:)));

%% Create individual vectors for each command 
size_labels = length(txt)-length(num); %num starts at column where first number appears
vec_length = length(num);
time_vec = num(:,time_colnum);
POI_vec = raw(size_labels+1:length(raw),POI_colnum);
diesel_vec = txt(size_labels+1:length(txt),Diesel_colnum); %txt and raw vectors start from row 1,so we need to offset 
solarIrr_vec = num(:,SolarIrr_colnum);
CHP_vec = txt(size_labels+1:length(txt),CHP_colnum);
load_vec = num(:,load_colnum);
motor_vec = txt(size_labels+1:length(txt),motor_colnum);
fault_vec = num(:,fault_colnum);
dsoCommand_vec = txt(size_labels+1:length(txt),dsoCommand_colnum);
dsoImportExportValue_vec = num(:,dsoImportExportValue_colnum);
dsoPFValue_vec = num(:,dsoPFValue_colnum);
dsoVarValue_vec = num(:,dsoVarValue_colnum);
dsoDRValue_vec = num(:,dsoDRValue_colnum);
dsoCommandStartTime_vec = num(:,dsoCommandStartTime_colnum);
dsoCommandDuration_vec = num(:,dsoCommandDuration_colnum);

%% This section puts the time format from excel into total minutes
[y, mo, d, h, mi, s] = datevec(datestr(time_vec,13));  %13 is table number for Standard Matlab date format HH:MM:SS 
time_vec = h*3600+mi*60+s;  %in seconds

for i = 1:vec_length
    if isnan(dsoCommandStartTime_vec(i)) == 1
        dsoCommandStartTime_vec(i) = 0;
    else 
        dsoCommandStartTime_vec(i) = dsoCommandStartTime_vec(i);
    end
    if isnan(dsoCommandDuration_vec(i)) == 1
        dsoCommandDuration_vec(i) = 0;
    else
        dsoCommandDuration_vec(i) = dsoCommandDuration_vec(i);
    end
end

[yStart, moStart, dStart, hStart, miStart, sStart] = datevec(datestr(dsoCommandStartTime_vec,13));
dsoCommandStartTime_vec = hStart*3600+miStart*60+sStart;

[yDur, moDur, dDur, hDur, miDur, sDur] = datevec(datestr(dsoCommandDuration_vec,13));
dsoCommandDuration_vec = hDur*3600+miDur*60+sDur;


%% This section parses out the status of the three POI breakers
for i = 1:vec_length
    [POI_1(i), remain] = strtok(POI_vec(i),'-');
    [POI_2(i), remain] = strtok(remain,'-');
    POI_3(i) = strtok(remain,'-');
end
POI_1 = strtrim(POI_1); %remove any leading whitespace
POI_1 = deblank(POI_1); %remove any trailing whitespace
POI_2 = strtrim(POI_2);
POI_2 = deblank(POI_2);
POI_3 = strtrim(POI_3);
POI_3 = deblank(POI_3);

POI_1 = POI_1'; %turn row vector into column vector
POI_2 = POI_2';
POI_3 = POI_3';

%need to adjust this to have modbus commands
for i = 1:length(POI_1) %translate 'C' and 'O' into modbus command
    if strcmp(POI_1(i),'C') == 1
        %write modbus POI 1 breaker close signal
        POI_all(i,1) = 0;
    elseif strcmp(POI_1(i),'O') == 1
        %write modbus POI 1 breaker open signal
        POI_all(i,1) = 1;
    else
        print('Please check for a formatting error in row %d for POIs', i);
    end
    if strcmp(POI_2(i),'C') == 1
        %write modbus POI 2 breaker close signal
        POI_all(i,2) = 0;
    elseif strcmp(POI_2(i),'O') == 1
        %write modbus POI 2 breaker open signal
        POI_all(i,2) = 1;
    else
        print('Please check for a formatting error in row %d for POIs', i);
    end
    if strcmp(POI_3(i),'C') == 1
        %write modbus POI 3 breaker close signal
        POI_all(i,3) = 0;
    elseif strcmp(POI_3(i),'O') == 1
        %write modbus POI 3 breaker open signal
        POI_all(i,3) = 1;
    else
        print('Please check for a formatting error in row %d for POIs', i);
    end   
%     if i >= 2
%         change_CMD_POI(i) = strcmp(POI_1(i),POI_1(i-1));
%     end
end   

%% This section translates the diesel generator breaker command
diesel_vec = strtrim(diesel_vec);
diesel_vec = deblank(diesel_vec);

for i = 1:vec_length
    if strcmp('ON',diesel_vec(i))==1 
        diesel(i) = 0; %breaker close signal is 0
    elseif strcmp('OFF',diesel_vec(i))==1
        diesel(i) = 1; %breaker open signal is 1
    else
        disp(['formatting error in diesel column, row ', num2str(i)]);
    end
end
diesel = diesel';

%% This section converts the solar irradiance percentage into a gain
for i = 1:vec_length
    if strcmp(solarIrr_vec(i),'OFF') == 1
        solarIrr(i) = 1;
        solarBreaker(i) = 1;  %if NaN, that means solar PV breaker is open
    else
        solarIrr(i) = 0.01*solarIrr_vec(i);
        solarBreaker(i) = 0;
    end
end
solarIrr = solarIrr';
solarBreaker = solarBreaker';

%% This section translates the CHP generator breaker command
CHP_vec = strtrim(CHP_vec);
CHP_vec = deblank(CHP_vec);

for i = 1:vec_length
    if strcmp('ON',CHP_vec(i))==1 
        CHP(i) = 0; %breaker close signal is 0
    elseif strcmp('OFF',CHP_vec(i))==1
        CHP(i) = 1; %breaker open signal is 1
    else
        disp(['formatting error in CHP column, row ', num2str(i)]);
    end
end
CHP = CHP';

%% This section converts the current load percentage into a gain
load_gain = 0.01*load_vec;

%% This section translates the motor breaker commands 
motor_vec = strtrim(motor_vec);
motor_vec = deblank(motor_vec);

%separate into one
for i = 1:vec_length
    [motor1_vec(i), remain] = strtok(motor_vec(i),'-');
    motor2_vec(i) = strtok(remain,'-');
end
motor1_vec = deblank(motor1_vec');
motor2_vec = strtrim(motor2_vec');

for i = 1:vec_length
    if strcmp('ON',motor1_vec(i))==1 
        motor1(i) = 0; %breaker close signal is 0
    elseif strcmp('OFF',motor1_vec(i))==1
        motor1(i) = 1; %breaker open signal is 1
    else
        disp(['formatting error in motor1 column, row ', num2str(i)]);
    end
    
    if strcmp('ON',motor2_vec(i))==1 
        motor2(i) = 0; %breaker close signal is 0
    elseif strcmp('OFF',motor2_vec(i))==1
        motor2(i) = 1; %breaker open signal is 1
    else
        disp(['formatting error in motor2 column, row ', num2str(i)]);
    end
end
motor1 = motor1';
motor2 = motor2';
motor_all = [motor1 motor2];

%% This section converts the fault column entries into fault commands
fault_all(1:vec_length,1:8) = 0;
for i = 1:vec_length
    if isnan(fault_vec(i)) == 1
        fault_all(i,:) = 0;
    else 
        fault_num = int64(fault_vec(i));
        fault_all(i,fault_num) = 1;
    end
end
fault1 = fault_all(:,1);
fault2 = fault_all(:,2);
fault3 = fault_all(:,3);
fault4 = fault_all(:,4);
fault5 = fault_all(:,5);
fault6 = fault_all(:,6);
fault7 = fault_all(:,7);
fault8 = fault_all(:,8);

%% This section is for DSO Ancillary Services Requests
% This section will work with preparing separate arrays for the ancillary 
% services so that Modbus commands can be easily sent in the simulink model
% matlab function
dsoCommand_vec = lower(dsoCommand_vec); %the strfind function is case sensitive, need this for data cleaning

for i = 1:vec_length
    if isempty(cell2mat(strfind(dsoCommand_vec(i),'none'))) ~= 1  %strfind returns a cell, not array
        %modbus send register value for doing nothing (0)
        dsoReconnect(i) = 0;
        dsoDisconnect(i) = 0;
        dsoExport(i) = 0;
        dsoImport(i) = 0;
        dsoVAR(i) = 0;
        dsoDR(i) = 0;
        dsoPF(i) = 0;
    else
        if isempty(cell2mat(strfind(dsoCommand_vec(i),'reconnect'))) ~= 1  %to check if reconnect command was given at command i
            dsoReconnect(i) = 1;
        end
        if isempty(cell2mat(strfind(dsoCommand_vec(i),'disconnect'))) ~= 1
            dsoDisconnect(i) = 1;
        end
        if isempty(cell2mat(strfind(dsoCommand_vec(i),'export'))) ~= 1
            dsoExport(i) = 1; 
        end
        if isempty(cell2mat(strfind(dsoCommand_vec(i),'import'))) ~= 1
            dsoImport(i) = 1;
        end
        if isempty(cell2mat(strfind(dsoCommand_vec(i),'var'))) ~= 1
            dsoVAR(i) = 1;
        end
        if isempty(cell2mat(strfind(dsoCommand_vec(i),'demand response'))) ~= 1
            dsoDR(i) = 1;
        end
        if isempty(cell2mat(strfind(dsoCommand_vec(i),'power factor'))) ~= 1
            dsoPF(i) = 1;
        end
    end
end
dsoDisconnect = dsoDisconnect';
dsoReconnect = dsoReconnect';
dsoExport = dsoExport';
dsoImport = dsoImport';
dsoPF = dsoPF';
dsoVAR = dsoVAR';
dsoDR = dsoDR';
dso_all = [dsoDisconnect dsoReconnect dsoExport dsoImport dsoPF dsoVAR dsoDR ];

%% This section cleans up the DSO ancillary service requests column
for i = 1:vec_length
    if isnan(dsoDRValue_vec(i)) == 1
        dsoDRValue(i) = 0;
    else 
        dsoDRValue(i) = int64(dsoDRValue_vec(i));
    end
    
    if isnan(dsoPFValue_vec(i)) == 1
        dsoPFValue(i) = 0;
    else 
        dsoPFValue(i) = int64(dsoPFValue_vec(i));
    end
    if isnan(dsoVarValue_vec(i)) == 1
        dsoVarValue(i) = 0;
    else 
        dsoVarValue(i) = int64(dsoVarValue_vec(i));
    end
    if isnan(dsoImportExportValue_vec(i)) == 1
        dsoImportExportValue(i) = 0;
    else 
        dsoImportExportValue(i) = int64(dsoImportExportValue_vec(i));
    end
end
dsoImportExportValue = dsoImportExportValue';
dsoPFValue = dsoPFValue';
dsoVarValue = dsoVarValue';
dsoDRValue = dsoDRValue';
dsoValue_all = [dsoImportExportValue dsoPFValue dsoVarValue dsoDRValue];

%% This section combines the simulink signals into one matrix
CMD_signals = [time_vec POI_all diesel solarIrr solarBreaker CHP load_gain motor1 motor2 fault_all dso_all dsoValue_all dsoCommandStartTime_vec dsoCommandDuration_vec];
save('CMD_signals','CMD_signals');