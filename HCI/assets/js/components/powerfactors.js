function PowerFactors (data){
	// first load the the css
	$('head').append($('<link rel="stylesheet" type="text/css" />').attr('href','assets/css/components/powerfactors.css'));
	
	this.name = "PowerFactors";
	this.id = "PowerFactors_Group";
	this.data = data;
	this.instantiateGauge = instantiateGauge;
	this.updateGauge = updateGauge;
	this.powerFactorDefaultSettings = {
		//Location of gauge
		x: 10,
		y: 10,
		//Length and Width of gauge
		width: 10,
		height: 440,
		margin: 20,
		//Center value
		center: 1,
		//Left and Right Bounds
		left: .5,
		right: .5,
		//Intervals for major and minor tick marks
		majorInterval: .25, //majorTicks
		minorInterval: .05,
		//Labels
		position: 'below' //options are 'above' or 'below'
	}
	
	var svg = 	d3.select("#profileimage")
	.append("g").attr("id",this.id);

}

//TODO: //Default Settings need to be handled better. 
PowerFactors.prototype.initializeComponents = function(){
	var groupId = this.id;

	var powerFactorDefaultSettings = this.powerFactorDefaultSettings;
	$.each(this.data, function(pfIndex,objectToDraw){
		pfSettings = powerFactorDefaultSettings;
		pfSettings.x = objectToDraw.x;
		pfSettings.y = objectToDraw.y;
		pfSettings.height = objectToDraw.height;
		pfSettings.width = objectToDraw.width;	
		instantiateGauge(pfSettings, groupId, objectToDraw.id);
	});
};

PowerFactors.prototype.updateComponents = function(jsonData){
	var powerFactorDefaultSettings = this.powerFactorDefaultSettings;

	$.each(this.data, function(pfIndex,objectToUpdate){
		var powerfactorData = jsonData.pf;  // PF data
		var breakerData = jsonData.breaker;  // relay data
		var pfRelayList = objectToUpdate.linkedRelays;
		powerFactorDefaultSettings.x = objectToUpdate.x;
		powerFactorDefaultSettings.y = objectToUpdate.y;
		powerFactorDefaultSettings.height = objectToUpdate.height;
		powerFactorDefaultSettings.width = objectToUpdate.width;
		updateGauge(powerfactorData, objectToUpdate.id, powerFactorDefaultSettings, pfRelayList, breakerData);
	});
};


//TODO: Add option to customize colors
 function instantiateGauge(s, parentDiv, id){

	// at the moment this is used to scale tickmarks. Might not need it. 
	// still haven't fully traced through all of the code
	//http://jaketrent.com/post/use-d3-rangebands/
	var tickscale = d3.scale.linear()
		.domain([0, 1]) //visual space
		.range([0, s.width]); //data space (scaling data to visual space)


	//use existing container
	var svg = d3.select("#"+parentDiv).append("g").attr("id",id);

      //Widest green background bar
	svg.append("rect")
		.attr("x", s.x-s.margin)
		.attr("y", s.y - s.margin)
		.attr("width", s.width+s.margin*2)
		.attr("height", s.height + s.margin*2)
		.attr("class", "bckbar");

		//Middle yellow background bar
	svg.append("rect")
		.attr("x", s.x + s.width/5)
		.attr("y", s.y - s.margin)
		.attr("width", 3*s.width/5)
		.attr("height", s.height + s.margin*2)
		.attr("class", "mbckbar");

		//Center red background bar
	svg.append("rect")
		.attr("x", s.x + 3*s.width/8)
		.attr("y", s.y - s.margin)
		.attr("width", s.width/4)
		.attr("height", s.height + s.margin*2)
		.attr("class", "cbckbar");

      //Draw horizontal line positioned in middle (height/2) running from margin to margin
	svg.append("line")
		.attr("x1", s.x) 
		.attr("y1", s.y+s.height/2+s.margin/2)
		.attr("x2", s.x + s.width)
		.attr("y2", s.y+s.height/2+s.margin/2)
		.attr("class", "midline");


      //Minor Ticks
	  //Get length of one side. divide by interval and times 2 to get the spacing correct on the tick marks
	  // Height of minor ticks from 1/4th height to 3/4th height
	svg.selectAll("minor")
		.data(new Array(Math.trunc(2*(Math.abs(s.center-s.right))/s.minorInterval)))
		.enter()
		.append("line")
		.attr("x1", function(d,i){return s.x + tickscale(i*s.minorInterval);}) 
		.attr("y1", s.y + s.height/3+s.margin/2)
		.attr("x2", function(d,i){return s.x + tickscale(i*s.minorInterval);})
		.attr("y2", s.y + 2*s.height/3 + s.margin/2)
		.attr("class", "minor");

    //Major Ticks
	svg.selectAll("major")
		.data(new Array(Math.trunc(2*(Math.abs(s.center-s.right))/s.majorInterval)+1))
		.enter()
		.append("line")
		.attr("x1", function(d,i){return s.x + tickscale(i*s.majorInterval);}) 
		.attr("y1", s.y + s.height/7+s.margin/2)
		.attr("x2", function(d,i){return s.x + tickscale(i*s.majorInterval);})
		.attr("y2", s.y + 6*s.height/7 + s.margin/2)
		//.attr("width",s.x/s.majorInterval)
		.attr("class", "major")

        //Labels
		//TOOD: Make font size relative to 1/5th height
		//TOOD: Draw labels over tick marks
	svg.selectAll("label")
		.data(new Array(Math.trunc(2*(Math.abs(s.center-s.right))/s.majorInterval)+1))
		.enter()
		.append("text")
		.attr("x", function(d,i){return s.x + tickscale(i*s.majorInterval)-18;}) //minus font size here
		.attr("y", function(d,i){
			if (s.position==='above'){
				return s.y + 1*s.height/3-1;
			} else {
				return s.y + s.height + s.margin-2;
			};
		})
		.text(
			function(d,i){
				//check if it divides evenly later 
				var middle =  Math.trunc(Math.abs(s.center-s.right)/s.majorInterval);
				if (i<middle) { //left
					return (s.left+i*Math.abs(s.center - s.left)/middle).toFixed(2);
				}else if (i == middle) {
					return s.center.toFixed(2);
				}else{ // itterate in reverse order
					return (s.center - (i-middle)*Math.abs(s.center - s.right)/middle).toFixed(2);
				}		
			})
		.attr("class", "text"); 
		
	//LEAD label
	svg.append("text")
		.attr("x", s.x - 18) //minus font size here?
		.attr("y", function(d){
			if (s.position==='above'){ // this inverse of the number line
				return s.y + s.height + s.margin-2;

			} else {
				return s.y + 1*s.height/3-1;

			}
		})
		.attr("id","circLead_"+id)		
		.attr("class", "text")
		.text("LEAD");
	//LAG Label
	svg.append("text")
		.attr("x", s.x +s.width - 18) //minus font size here?
		.attr("y", function(d){
			if (s.position==='above'){ // this inverse of the number line
				return s.y + s.height + s.margin-2;
			} else {
				return s.y + 1*s.height/3-1;
			}
		})		
		.attr("class", "text")
		.attr("id","circLag_"+id)		
		.text("LAG");

		
      //Pin(Circle)
	svg.selectAll("circ" + parentDiv)
		.data([{val:1, dir:'left'}]) //by default set value to middle 
		.enter()
		.append("circle")
		.attr("cx", s.x+s.width/2)
		.attr("cy", s.y+s.height/2+s.margin/2)
		.attr("r", s.height/4)
		.attr("id", "circ_"+id)
		.attr("class", "circ");

	//PF Value	
	svg.append("text")
		.attr("x", s.x + s.width + s.margin)
		.attr("y", s.y+s.height)
		.attr("id","pfval_"+id)
		.attr("class", "pfvalue")
		.text("1.00"); 
		
	//Lead/Lag/Island/Imp/Exp
	svg.append("text")
		.attr("x", s.x - 180)
		.attr("y", s.y+s.height)
		.attr("id","pfreading_"+id)
		.attr("class", "pfvalue")
		.text("ISLAND"); 
}

//s = settings
function updateGauge(pfdata, pfid, s, pfRelayList, breakerStatus){
	if (typeof (pfdata) !== "undefined" && typeof(pfdata.values) !== "undefined" && typeof(pfdata.leadlag) !=="undefined" && typeof(pfdata.impexp) !== "undefined" && typeof(pfdata.values[pfid]) !== "undefined") {
		//console.log(pfdata.values[pfid]);
		var meterValue = pfdata.values[pfid];
		var leadLag = pfdata.leadlag[pfid];
		var impExp = pfdata.impexp[pfid];
		var selectCircle = d3.select("#circ_"+pfid)

		//if Island no lag/lead, set vale to x.xxx, text to island
		var bstat=0;

		for (brkcnt=0; brkcnt < pfRelayList.length; brkcnt++) {
			brktocheck = pfRelayList[brkcnt];
			brkstat = Math.abs(breakerStatus[brktocheck]); 
			bstat += brkstat;			
		}
		if (bstat == 0 ) {
			$("#circ_"+pfid).hide();
			$("#circLead_"+pfid).css("fill","white");
			$("#circLag_"+pfid).css("fill","white");
			d3.select("#pfval_"+pfid).text("X.XXX");
			d3.select("#pfreading_"+pfid).text("ISLAND");		
		} else {
		
			//change meter
			d3.select("#pfval_"+pfid).text(pfdata.values[pfid].toFixed(3));
			

			if (impExp == 0 ) {
				d3.select("#pfreading_"+pfid).text("EXPORT");
				$("#circ_"+pfid).show();
			}else{
				d3.select("#pfreading_"+pfid).text("IMPORT");
				$("#circ_"+pfid).show();
			}
			
			
			var tickscale = d3.scale.linear()
				 .domain([s.left, s.center])
				 .range([0, s.width]);
			
			selectCircle	
			.transition()
			.duration(150)
			selectCircle
			.attr("cx", function(d,i){
				var cx = 1;
				if (pfdata.values[pfid] >= s.center ){
					cx = s.x+s.width/2;
				}
				// we change the color of lead/lag label based on which it is
				// make sure the dot doesn't go out of bounds (peg it to the edge if it does)
				// scale the addition to the x correctly
				if (leadLag == .001) { ///1 is lag to the right
					$("#circLag_"+pfid).css("fill","yellow");
					$("#circLead_"+pfid).css("fill","white");
					if (meterValue < s.right) {
						cx = s.x + s.width - tickscale(s.right)/2;
					}else if ( meterValue < s.center){
						cx = s.x + s.width - tickscale(meterValue)/2;
					}
					
				}else{  //lead to the left
					$("#circLag_"+pfid).css("fill","white");
					$("#circLead_"+pfid).css("fill","yellow");
					if (meterValue < s.left) {
						cx = s.x + tickscale(s.left)/2;
					}else if (meterValue < s.center) {
						cx = s.x + tickscale(meterValue)/2;
					}
				}
				
				return cx;
			});
		}
	}	
}
