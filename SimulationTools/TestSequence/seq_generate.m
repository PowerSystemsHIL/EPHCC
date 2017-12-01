function seq = seq_generate(seq_no);

opt = eval(['seq_config_' num2str(seq_no) '();']);

seq = seq_generate_all(opt);
seq.seq_no = seq_no;

seq_plot(seq);

save seq.mat seq;