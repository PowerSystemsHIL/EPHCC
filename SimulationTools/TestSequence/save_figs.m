%% Copyright 2018 Alliance for Sustainable Energy, LLC
%
% Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
% and associated documentation files (the "Software"), to deal in the Software without restriction, 
% including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
% and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, 
% subject to the following conditions:
%
% The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
%
% THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
% BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
% NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS, THE COPYRIGHT HOLDERS, THE UNITED STATES, 
% THE UNITED STATES DEPARTMENT OF ENERGY, OR ANY OF THEIR EMPLOYEES BE LIABLE FOR ANY CLAIM, 
% DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
% OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
%
% Author: Przemyslaw Koralewicz / NREL
% Date: 2017

function save_figs(fh, filename, savefig, savepng)
    for i=1:length(fh)
        plotsizeinch = [12 15];
        saveDPI = 300;
        set(fh(i),'PaperUnits','inches');
        set(fh(i),'PaperSize', plotsizeinch);
        set(fh(i),'PaperUnits','normalized');
        %set(gcf,'PaperPosition',[0.1,0.1,0.9,0.9]);
        set(fh(i),'PaperPositionMode','auto')
        set(fh(i),'PaperPosition',[0,0,1,1]);
        set(fh(i),'Position',[0 0 plotsizeinch]*saveDPI);
        print(fh(i), '-dpng' ,['-r' num2str(saveDPI)], [filename num2str(i)]); % ,['-r' num2str(saveDPI)]
    end;
end