function seq_print(seq)

isl1 = seq.opt.DMS.DisReq.Time(3) - seq.opt.DMS.DisReq.Time(2);
isl2 = seq.opt.DMS.DisReq.Time(5) - seq.opt.DMS.DisReq.Time(4);

disp(['1st islanding period: ' num2str(isl1/60) ' min']);
disp(['2nd islanding period: ' num2str(isl2/60) ' min']);
disp(['Tot islanding period: ' num2str((isl1+isl2)/60) ' min']);

kVAr = sum(~isnan(seq.dms_kVArref_nan)*0.2)/60;
kW = sum(~isnan(seq.dms_kWref_nan)*0.2)/60;
kWHz = sum(~isnan(seq.dms_kWHzref_nan)*0.2)/60;
kVArVolt = sum(~isnan(seq.dms_kVArVoltref_nan)*0.2)/60;

disp(['kW request period   : ' num2str(kW) ' min']);
disp(['kVAR request period : ' num2str(kVAr) ' min']);
disp(['kW/Hz period        : ' num2str(kWHz) ' min']);
disp(['kVar/V period       : ' num2str(kVArVolt) ' min']);


