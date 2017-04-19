function Batteries (data){
	this.name = "Batteries";
	this.id = "Batteries_Group";
	this.data = data;
	this.drawBattery = drawBattery;
	this.updateBattery = updateBattery;
	this.drawText = drawText;
	//append g to group objects
	//append g to group objects
	var svg = 	d3.select("#profileimage")
	.append("g").attr("id",this.id);
}

Batteries.prototype.initializeComponents = function(){
	groupId = this.id;
	$.each(this.data, function(cIndex,objectToDraw){
		drawBattery(groupId,objectToDraw.id,[objectToDraw.x,objectToDraw.y], objectToDraw.width, objectToDraw.height);
	});
};

Batteries.prototype.updateComponents = function(jsonData){
	$.each(this.data, function(cIndex,objectToUpdate){
		var linkedRelay = objectToUpdate.linkedRelay;
		var relayValue = jsonData.realpower[linkedRelay];	// this tells us if it's charging
		var batteryStatus = jsonData.batteries[objectToUpdate.id];  // this gives percentage
		updateBattery(objectToUpdate, batteryStatus, relayValue); //Might need to add sign to determine if positive or negative value shows chargin
	});
}
	
function batterycolor(num){
	if (num >= 0 && num < 33) {return "red"}
	if (num >= 30 && num < 66) {return "orange"}
	if (num >= 66 && num <= 100) {return "green"}
} 

function boltDisplay(id,relay){
    relay =-1*relay;
	var fill;
	if (relay>0) {
		fill = "yellow";
	}else if (relay == 0) {
		fill = "grey";
	}else {
		fill = "none";
	}
	
//	fill = "none";
	d3.select("#"+id+"_bolt").style("fill", fill);

}

function drawBattery(groupId, id, position, w, h){
	// battery label that says what current charge percentage is
	
	// label width is about 50 so if total battery width is under 30, just start at 0
	var labelX =  position[0]+ w/2-15;
	var labelY =  (position[1]+ h + 20);
	if (w < 30) labelX= position[0];
	
	drawText(groupId,(id+"_boltLabel"), labelX, labelY, "%", "grey");

	var svg = d3.select("#"+groupId);
	
	// battery tip
	svg.append("rect")
			.attr("width", w/4.5)
			.attr("height", h/13.33)
			.attr("x", position[0] + w/2 - w/9 )
			.attr("y", position[1] - h/13.33)
			.attr("rx", 3)
			.attr("ry", 3)
			.style("fill", "white");
	
	//battery rectangel outline
	svg.append("rect")
			.attr("width", w)
			.attr("height", h)
			.attr("x", position[0])
			.attr("y", position[1])
			.attr("rx", 3)
			.attr("ry", 3)
			.style("fill", "none")
			.style("stroke", "white")
			.attr("id", id);

	//rectangle level, fill white 
	var level = h/3;
	svg.append("rect")
		.attr("id", id+"_level")
		.attr("width", w)
		.attr("height", level)
		.attr("x", position[0] + 0 )
		.attr("y", position[1] + (h - level))
		.attr("rx", 2)
		.attr("ry", 2)
		.attr("style","mix-blend-mode: screen;");

	// lightening bolt to indicate if battery is charging

	
	// scales are normalized over their default size (you can get default size by getting the delta of max and min y and x in the points definitions below with a 5 pt buffer for aethetics
	var scaleX = w/105;
	var scaleY = h/140;
	var boltX =  position[0];
	var boltY =  position[1];
	
	
	svg.append("polyline")
		.attr("id",id+"_bolt")
		.attr("transform","translate("+boltX+","+boltY+") scale("+scaleX+","+scaleY+")")
		.style("stroke","yellow")
		.style("fill", "yellow")
		.style("stroke-width", "1px")
		.attr("points","5,87 87,5 57,64 100,63 29,135 51,82 5,88"); 

}
// instead of position, we pass in id and get possition
function updateBattery(batteryToUpdate, batteryLevel, relayValue){
	if (batteryLevel != undefined) { 
		batteryId = batteryToUpdate.id;
		position = [batteryToUpdate.x,batteryToUpdate.y];

		height = batteryToUpdate.height;
		
		// update lightening bolt visibility based on relay status
		boltDisplay(batteryId,relayValue);
		
		var batteryheight = d3.scale.linear()
							.domain([0,100])    // accepted values
							.range([0, height]) // this controls the size of the fill.
							.clamp(true);
		
		// make sure value within acceptable bounds
		if (batteryLevel > 100 ) {
			console.warn( "Battery level above 100( " + batteryLevel + ") setting to 100");
			batteryLevel = 100;
		}
		if (batteryLevel < 0 ) {
			console.warn( "Battery level below 0( " + batteryLevel + ") setting to 0");
			batteryLevel = 0;
		}
		var round = batteryLevel.toFixed(2);
		var levelFill = batteryheight(batteryLevel);

		d3.select("#"+batteryId+"_level")
		   .attr("fill", batterycolor(batteryLevel))
		   .attr("height", levelFill)
		   .attr("y", position[1] + (height - levelFill));


		d3.select("#"+batteryId+"_boltLabel")
		.text(round + "%")
	}
}

function drawText(groupId, id, x, y, message, color) {
	//console.log(groupId, id, x, y, message, color);
	var svg = document.getElementById(groupId);
	var text = document.createElementNS("http://www.w3.org/2000/svg", 'text');
		text.setAttribute('id', id);
		text.setAttribute('x', x);
		text.setAttribute('y', y);
		text.setAttribute('fill', color);
		text.textContent = message;	
	svg.appendChild(text);
}