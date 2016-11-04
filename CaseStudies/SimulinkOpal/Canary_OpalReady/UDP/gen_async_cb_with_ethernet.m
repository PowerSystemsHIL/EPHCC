%
%  OPAL-RT Technologies inc
%
%  Copyright (C) 2014. All rights reserved
%

function gen_async_cb_with_ethernet(blockfullname, blockname, functionname, sourcefile, varargin);

if (evalin('base','exist(''opal_internal_generate'',''var'')') == 1)
    global RtlabInfo
	subsystemPathOnHost = evalin('base','subsystem_target_path');
    % get current subsystem & current block
    [sub, pos] = getrtlabinfo('getids');
    
    % get matlab release
    matlabRelease = ['R' OpGetMatlabVersionString];

    libName1 = '';
    libName2 = '';
    libName3 = '';
    filesToTransfer='';
    filesToTransferBeforeLoad='';	
    filesToTransferAfterComp='';	
    if strcmp(lower(RtlabInfo.Platform),'redhawk')
        libName2 = strcat('-lOpalAsyncApi', matlabRelease);
        libName3 = strcat('-lOpalAsyncApiCore'); 
        filesToTransfer = [getenv('RTLAB_ROOT') '/common/lib/redhawk/libOpalAsyncApiCore.a' '=binary'];   
        filesToTransfer = [filesToTransfer '|'  'AsyncEthernet.h' '=ascii'];
        filesToTransfer = [filesToTransfer '|'  'AsyncEthernet.c' '=ascii'];
        filesToTransfer = [filesToTransfer '|'  'AsyncEthernet.mk' '=ascii'];
		filesToTransferBeforeLoad = [subsystemPathOnHost '/' 'AsyncEthernet' '=binary'];
		filesToTransferAfterComp = ['AsyncEthernet' '=binary'];
    else
        RtlabInfo.Subsystem(sub).BlockInfo(pos).ErrorCode = 1001;
        RtlabInfo.Subsystem(sub).BlockInfo(pos).ErrorMsg = ['Block ' blockname ' is not supported on this target platform'];
    end
        
    % set block info
    RtlabInfo.Subsystem(sub).BlockInfo(pos).BlockFullName                 = blockfullname;
    RtlabInfo.Subsystem(sub).BlockInfo(pos).BlockName                     = blockname;
    RtlabInfo.Subsystem(sub).BlockInfo(pos).SFunctionName                 = functionname;
    RtlabInfo.Subsystem(sub).BlockInfo(pos).Product                       = 'RT-LAB';
    RtlabInfo.Subsystem(sub).BlockInfo(pos).INTERNAL_ADD_SOURCE_FILE      = '';                           % separated by space
    RtlabInfo.Subsystem(sub).BlockInfo(pos).INTERNAL_IGN_SOURCE_FILE      = sourcefile;    %              % separated by space
    RtlabInfo.Subsystem(sub).BlockInfo(pos).INTERNAL_LIBRARY1             = libName1;                     % separated by space                     
    RtlabInfo.Subsystem(sub).BlockInfo(pos).INTERNAL_LIBRARY2             = libName2;                     % separated by space
    RtlabInfo.Subsystem(sub).BlockInfo(pos).INTERNAL_LIBRARY3             = libName3;                     % separated by space
    RtlabInfo.Subsystem(sub).BlockInfo(pos).INTERNAL_INCLUDE_PATH         = '';                           % separated by space
    RtlabInfo.Subsystem(sub).BlockInfo(pos).INTERNAL_LIBRARY_PATH         = '';                           % separated by space
    RtlabInfo.Subsystem(sub).BlockInfo(pos).TargetPreCompileCmd           = '';                           % separated by ;
    RtlabInfo.Subsystem(sub).BlockInfo(pos).TargetPostCompileCmd          = '';                           % separated by ;   
    RtlabInfo.Subsystem(sub).BlockInfo(pos).FileTransferBeforeCompilation = filesToTransfer;              % separated by |     example ='file1.dat=ascii|file2.dat=binary'
    RtlabInfo.Subsystem(sub).BlockInfo(pos).FileTransferBeforeLoad        = filesToTransferBeforeLoad;    % separated by |     example ='file1.dat=ascii|file2.dat=binary'
    RtlabInfo.Subsystem(sub).BlockInfo(pos).FileTransferAfterCompilation  = filesToTransferAfterComp;     % separated by |     example ='file1.dat=ascii|file2.dat=binary'
    RtlabInfo.Subsystem(sub).BlockInfo(pos).FileTransferAfterReset        = '';                           % separated by |     example ='file1.dat=ascii|file2.dat=binary'
end
