function Chp (data){
	this.name = "CHP";
	this.id = "CHP_Group";
	this.data = data;
	this.drawCHP = drawCHP;
	this.updateCHP = updateCHP;
	
	//append g to group objects
	var svg = 	d3.select("#profileimage")
	.append("g").attr("id",this.id);
}

Chp.prototype.initializeComponents = function(){
	var groupId = this.id;

	$.each(this.data, function(cIndex,objectToDraw){
		drawCHP(groupId,objectToDraw,objectToDraw.x,objectToDraw.y, objectToDraw.width,objectToDraw.height);
	});
};

Chp.prototype.updateComponents = function(jsonData){
		//update chp	
	$.each(this.data, function(cIndex,objectToUpdate){		
		var chpStatus = jsonData.chp[objectToUpdate.id];  // chp in the json
		updateCHP(objectToUpdate, chpStatus);
	});
};

function CHPColor(num){
	if (num >= 0 && num < 33) {return "red"}
	if (num >= 30 && num < 66) {return "red"}
	if (num >= 66 && num <= 100) {return "red"}
} 


//need 1 label above and one below?
function drawCHP(groupId, objectToDraw, x,y, w, h){
	id = objectToDraw.id;
	// battery label that says what current charge percentage is
	
	// label width is about 50 so if total battery width is under 30, just start at 0
	var labelX =  x+ w/2-15;
	var labelY =  (y+ h + 20);
	if (w < 30) labelX= x;
	
	drawText(groupId,(id+"_boltLabel"), labelX, labelY, "%", "grey");
	drawText(groupId,(id+"_boltLabel"), labelX - 15, y-10, objectToDraw.label, "grey");

	var svg = d3.select("#"+groupId);	

	//battery rectangel outline
	svg.append("rect")
			.attr("width", w)
			.attr("height", h)
			.attr("x", x)
			.attr("y", y)
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
		.attr("x", x + 0 )
		.attr("y", y + (h - level))
		.attr("rx", 2)
		.attr("ry", 2)
		.attr("style","mix-blend-mode: screen;");

	// scales are normalized over their default size (you can get default size by getting the delta of max and min y and x in the points definitions below with a 5 pt buffer for aethetics
}

// instead of position, we pass in id and get possition
function updateCHP(chpToUpdate, chpNewValue){
	chpNewValue = 100*chpNewValue/chpToUpdate.max;
	if (typeof(chpNewValue) != "undefined") { 
		chpId = chpToUpdate.id;
		position = [chpToUpdate.x,chpToUpdate.y];

		height = chpToUpdate.height;
				
		var batteryheight = d3.scale.linear()
							.domain([0,100])    // accepted values
							.range([0, height]) // this controls the size of the fill.
							.clamp(true);
		
		// make sure value within acceptable bounds
		if (chpNewValue > 100 ) {
			console.warn( "CHP level above 100( " + chpNewValue + ") setting to 100");
			chpNewValue = 100;
		}
		if (chpNewValue < 0 ) {
			console.warn( "CHP level below 0( " + chpNewValue + ") setting to 0");
			chpNewValue = 0;
		}
		var round = chpNewValue.toFixed(0);
		var levelFill = batteryheight(chpNewValue);

		d3.select("#"+chpId+"_level")
		   .attr("fill", CHPColor(chpNewValue))
		   .attr("height", levelFill)
		   .attr("y", position[1] + (height - levelFill));


		d3.select("#"+chpId+"_boltLabel")
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
