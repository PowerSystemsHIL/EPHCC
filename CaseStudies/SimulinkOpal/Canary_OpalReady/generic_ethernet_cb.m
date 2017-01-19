%
%  OPAL-RT Technologies inc
%
%  Copyright (C) 2014. All rights reserved
%

function [varargout]=generic_ether_ctrl_cb(action,varargin);
% get current block
if(~strcmp(lower(action),'update'))
	blockName = gcb;
end

tcp_mode_ix  = 13;	
remote_ip_ix = 15;
	
protocol = get_param(gcb,'protocol');
tcp_mode = get_param(gcb,'tcp_mode');
		
switch (lower(action))
    case 'initfcn'
        gen_async_cb_with_ethernet(blockName,get_param(blockName,'Name'),get_param(blockName,'FunctionName'),'sfun_gen_async_ctrl.c');
        varargout{1}='';           
    
    case 'update'
        blockHandle = varargin{1};
		oldnamesIconParam=varargin{3};
        oldvalues=varargin{4};
        
        varargout{1}='';	
	
    case 'protocol'
	    protocol = get_param(gcb,'protocol');
		maskvisibilities = get_param(gcb, 'MaskVisibilities');		
        if (strcmp(protocol, 'UDP'))
		    maskvisibilities{remote_ip_ix} = 'on';
			maskvisibilities{tcp_mode_ix}  = 'off';
		else
			if (strcmp(tcp_mode, 'Client'))
				maskvisibilities{remote_ip_ix} = 'on';
			else
				maskvisibilities{remote_ip_ix} = 'off';
			end
			maskvisibilities{tcp_mode_ix}  = 'on';
		end
		set_param(gcb,'MaskVisibilities', maskvisibilities);
		set_param([gcb '/AsyncEthernetCtrl'],'protocol', protocol);
		
    case 'tcp_mode'
	    tcp_mode = get_param(gcb,'tcp_mode');
		maskvisibilities = get_param(gcb, 'MaskVisibilities');		
        if (strcmp(tcp_mode, 'Client'))
		    maskvisibilities{remote_ip_ix} = 'on';
		else
		    maskvisibilities{remote_ip_ix} = 'off';
		end
		
        if (strcmp(protocol, 'UDP'))
			maskvisibilities{tcp_mode_ix}  = 'off';
            maskvisibilities{remote_ip_ix} = 'on';
		else
		    maskvisibilities{tcp_mode_ix} = 'on';
		end
		
		set_param(gcb,'MaskVisibilities', maskvisibilities);
		set_param([gcb '/AsyncEthernetCtrl'],'tcp_mode', tcp_mode);	

	case 'swap_rx'
		val = get_param(gcb,'swap_rx');
		set_param([gcb '/AsyncEthernetCtrl'],'swap_rx', val);		

	case 'swap_tx'
		val = get_param(gcb,'swap_tx');
		set_param([gcb '/AsyncEthernetCtrl'],'swap_tx', val);			

		
    otherwise 
        disp(sprintf('unknown action value %s in generic_ethernet_cb',lower(action)));
        varargout{1}='';
end
