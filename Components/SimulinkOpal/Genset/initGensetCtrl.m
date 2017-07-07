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
    case 2
        GP.Pn = 80000;
        GP.Vn = 480;
        GP.fn = 60;
        GP.VCtrl.P = 0.02;
        GP.VCtrl.I = 1.5;
        GP.FCtrl.P = 0.025;
        GP.FCtrl.I = 1;
end
