/*
Copyright (c) 2016 Massachusetts Institute of Technology

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

function updateTimerBar(data,iddata){
	// make sure there's data
	if (typeof(data.timestamp) !== "undefined" && data.timstamp != "") {
		//update freshness timer
		oldtimer = parseInt($('#timer').html());
		newtimer = parseInt(data['simtime1']);
		servertime = parseInt(data['servertime']);
		datatime = parseInt(data['timestamp'])/1000;
		$('#foldername').html(iddata.foldername);

		// 5 second hysteresis before we declare stale data 
	

		if (servertime < datatime + 5) {
			//console.log("updating time");
			$('#datafreshness').css("fill","green");
			$('#timer').html(newtimer);
			var timerdate = new Date(null);
			timerdate.setSeconds(newtimer); 					
			$('#timer2').html(timerdate.toISOString().substr(11, 8));
			var pad = "";
			if (data.steptime1%60<=9){pad="0"}
			$('#timer3').html(Math.trunc(data.steptime1/60)+":"+pad+(data.steptime1%60).toFixed(0) );
		} else{
			// calculate time since last update but only put it in the pretty time box
			$('#datafreshness').css("fill","orange"); 
	
			var d = new Date();
			var currTime = d.getTime();
			var timDiff = (currTime - data['timestamp'])/1000;
			var timerdate = new Date(null);
			timerdate.setSeconds(timDiff); 	
			$('#timer2').html( timerdate.toISOString().substr(11, 8));
		//	$('#timer3').html(timerdate.toISOString().substr(14,2)+" mins");
			$('#timer3').html( "Not running");

			// handel initial case
			if (!$.isNumeric(oldtimer)){
				$('#timer').html(newtimer);
			}
		}
	}
}
