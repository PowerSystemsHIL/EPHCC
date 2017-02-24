function dataOut = stepFunc(startState, time, endTime)
% generate a step which starts at startState and at time jumps to
% ~startState and goes until endTime

dataOut = [startState.*ones(1,time) ~startState.*ones(1, endTime-time)];