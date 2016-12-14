function out = power_req(loads, exportReq, importLim)
% calculate output power required given loads, export, and import

tLen = length(loads);
out = zeros(1,tLen); % no req if either case below isn't needed
 
 for t=1:tLen
     if exportReq(t) > 0
         out(t) = loads(t) + exportReq(t);
     end
     if importLim(t) > 0
         if (loads(t) - importLim(t)) > 0
            out(t) = loads(t) - importLim(t);
         end
     end
 end
     
     