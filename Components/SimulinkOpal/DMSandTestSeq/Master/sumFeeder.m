function out = sumFeeder(f)
out.kw = 0;
out.kvar = 0;
out.kw_avg = 0;
out.kvar_avg = 0;
for i=1:length(f)
    out.kw = f(i).kw + out.kw;
    out.kvar = f(i).kvar + out.kvar;
    out.kw_avg = f(i).kw_avg + out.kw_avg;
    out.kvar_avg = f(i).kvar_avg + out.kvar_avg;
end
out.time = f.time;
out.name = 'Total';