function [ seq_out ] = seq_interp( seq, t_new )
%SEQ_INTERPOLATE Summary of this function goes here
%   Interpolation of test sequence into results time
%   Additionally all data's are transposed - original tes seq is vertical
%   (1,N) while results are horizontal (Nx1)
%% interpolate tes sequence vectors to result time
seq_out.opt = seq.opt;

seq_out.t = t_new';

seq_out.motor1 = round(interp1(seq.t, seq.motor1, t_new));
seq_out.motor2 = round(interp1(seq.t, seq.motor2, t_new));
seq_out.dms_disreq = round(interp1(seq.t, seq.dms_disreq, t_new));
seq_out.dms_kWena = round(interp1(seq.t, seq.dms_kWena, t_new));
seq_out.dms_PFena = round(interp1(seq.t, seq.dms_PFena, t_new));
seq_out.dms_kWref = interp1(seq.t, seq.dms_kWref, t_new);
seq_out.dms_PFref = interp1(seq.t, seq.dms_PFref, t_new);
seq_out.dms_kWref_nan = interp1(seq.t, seq.dms_kWref_nan, t_new);
seq_out.dms_kWHzref_nan = interp1(seq.t, seq.dms_kWHzref_nan, t_new);
seq_out.dms_PFref_nan = interp1(seq.t, seq.dms_PFref_nan, t_new);
seq_out.dms_phiref_nan = interp1(seq.t, seq.dms_phiref_nan, t_new);
seq_out.dms_Dp = interp1(seq.t, seq.dms_Dp, t_new);
seq_out.dms_Dq = interp1(seq.t, seq.dms_Dq, t_new);

seq_out.grid_freq = interp1(seq.t, seq.grid_freq, t_new);
seq_out.grid_volt = interp1(seq.t, seq.grid_volt, t_new);

seq_out.price = interp1(seq.t, seq.price, t_new);

end

