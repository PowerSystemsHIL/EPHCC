function dataOut = pulse(startState, t1, duration, endTime)
% generate a pulse which starts at startState and at t1 jumps to
% ~startState, after duration jumps back to startState, and goes until endTime

dataOut = [startState.*ones(1,t1) ~startState.*ones(1, duration) startState.*ones(1, endTime-duration-t1)];