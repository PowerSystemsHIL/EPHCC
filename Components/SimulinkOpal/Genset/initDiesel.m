function GP = initDiesel(GenSel)

switch GenSel
    case 1
        GP.Pn = 4000000;
        GP.Vn = 13800;
        GP.fn = 60;
        GP.Stator = [0.008979 0.05 2.35 1.72];
        GP.Field = [0.00206 0.511];
        GP.Dampers = [0.2826 3.738 0.02545 0.2392];
        GP.Inertia = [0.3468 0.009238 2];
        GP.Initial = [ -99  0  0  0  0  0  0  0  0 ];
        GP.Ex.Tr = 20e-4;
        GP.Ex.Regulator = [ 200 2e-3 ];
        GP.Ex.Exciter = [ 1 0.001 ];
        GP.Ex.Damping = [0.02 1 ];
        GP.Gov.Kp = 2;
    case 2
        GP.Pn = 80000;
        GP.Vn = 480;
        GP.fn = 60;
        GP.Stator = [0.02599 0.07 2.25 0.99];
        GP.Field = [0.016 0.2092];
        GP.Dampers = [0.2047 0.6524 0.04286 0.06387];
        GP.Inertia = [0.1268 0.02132 2];
        GP.Initial = [ -99  0  0  0  0  0  0  0  0 ];
        GP.Ex.Tr = 2e-3;
        GP.Ex.Regulator = [ 100 20e-3 ];
        GP.Ex.Exciter = [ 1 0.02 ];
        GP.Ex.Damping = [0.03 1 ];
        GP.Gov.Kp = 1;
end
