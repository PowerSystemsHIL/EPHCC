opt = init_seq();


seq = generate_all(opt);


subplot(4,1,1); plot(seq.t, [seq.irradiance; seq.price]);

dig     = [seq.fault.loc1; seq.cut_grid; seq.dms_disreq; seq.mgc_enable];
dig_lab = {'fault.loc1' 'G.Cut'            'DMS.DR'        'MGC.En'      };

Ndig = size(dig,1);
dig_lab = dig_lab(Ndig:-1:1);
base = (((Ndig-1):-1:0)'*ones(1,opt.N)*1.2);
subplot(4,1,[3 4]); plot(seq.t, dig + base);
set(gca,'YTick', [0:Ndig]*1.2);
set(gca,'YTickLabel', dig_lab);

save seq.mat seq;