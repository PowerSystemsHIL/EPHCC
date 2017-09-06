% Generate test sequence vector before running - sequence stored in seq.mat
seq_generate;
% Run UDP stream to opal and store received data. Results stored in res.mata
TX_RCV_UDP_Stream;
% Results of tests can be plotted
plot_kpp_all;
