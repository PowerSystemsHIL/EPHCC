res_bak = res;
temp = eval(['res.' filenames{1}]);
res.t = temp(:,1);
for k=1:length(filenames),
   res_bak = res;
   temp = eval(['res.' filenames{k}]);
   N=size(temp,2);
   eval(['res.' filenames{k} '= temp(:, 2:N);']);
end;
