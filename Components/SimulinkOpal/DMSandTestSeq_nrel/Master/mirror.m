function dataOut = mirror(x)
% outputs a set of data that is x concatenated with a mirrored version of
% itself so that x(end) = dataOut(length(x)+1) and the length is doubled
[m,n] = size(x);
if m >= n 
    dataOut = [x; x(m:-1:1,:)];  % make more rows
else
    dataOut = [x, x(:,n:-1:1)];  % make more cols
end