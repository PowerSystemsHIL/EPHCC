function outStruct = loadLoad(filename, desiredLength)

S = load(filename);
name = fieldnames(S);
data = getfield(S, name{1});
outStruct.time = 1:desiredLength;
kw = resample(data(2,:), desiredLength, length(data(2,:)));
kvar = resample(data(3,:), desiredLength, length(data(3,:)));
kw_avg = mean(kw);
kvar_avg = mean(kvar);
outStruct.kw = kw;
outStruct.kvar = kvar;
outStruct.kw_avg = kw_avg;
outStruct.kvar_avg = kvar_avg;
outStruct.name = name{1};
