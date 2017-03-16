function filt_d = firstOrderDig(tau, dt, type)
% create a digital first order low pass filter with tau time contant 
% and with dt sampling rate

if ~isempty(ver('control')) % Check for control system toolbox
    s = tf('s');
    if strcmp(type, 'low')
        filt = 1 / (tau*s + 1);
    elseif strcmp(type, 'high')
        filt = (tau*s) / (tau*s + 1);
    end
    filt_ss = ss(filt);    
    filt_d = c2d(filt_ss, dt);
else
    load filt_d;
end;
    
%[num, den] = tfdata(filt_d,'v');


% output can be verified with step(tf(num,den,sampdT))