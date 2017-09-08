figure;

generation = [kpp3.pcc.e(end,:) kpp2.e(end,:)  kpp7.e_pv(end,:)];
subplot(1,2,1); pie(generation);
legend({'Grid' 'Gen1','NGCHP2','Gen3','PV1','PV2'});
title(['Total energy consumed = ' num2str(round(sum(generation))) ' kWh']);
loads = kpp1.E_good_per_class(end,:);
subplot(1,2,2); pie(loads);
legend({'M', 'I', 'P', 'C'});
title(['Consumption by loads = ' num2str(round(sum(loads))) ' kWh']);
                                   

