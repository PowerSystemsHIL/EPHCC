function GP = initGensetCtrl(GenSel)

switch GenSel
    case 1
        GP.Pn = 4000000;
        GP.Vn = 13800;
        GP.fn = 60;
        GP.VCtrl.P = 0.2;
        GP.VCtrl.I = 1.5;
        GP.FCtrl.P = 0.025;
        GP.FCtrl.I = 1;
        GP.Prec = 1;
    case 2
        GP.Pn = 80000;
        GP.Vn = 480;
        GP.fn = 60;
        GP.VCtrl.P = 0.02;
        GP.VCtrl.I = 1.5;
        GP.FCtrl.P = 0.025;
        GP.FCtrl.I = 1;
        GP.Prec = 10;
    case 3
        GP.Pn = 3500000;
        GP.Vn = 13800;
        GP.fn = 60;
        GP.VCtrl.P = 0.2;
        GP.VCtrl.I = 1.5;
        GP.FCtrl.P = 0.025;
        GP.FCtrl.I = 1;
        GP.Prec = 1;
end

%% Nominal current ratings
GP.In = GP.Pn/(GP.Vn/sqrt(3))/3;

%% Droop lowpass filter
GP.filt = firstOrderDig(50e-3, 100e-6, 'low');
