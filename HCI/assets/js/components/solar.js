function Solar (data){
	this.name = "Solar";
	this.id = "Solar_Group";
	this.data = data;
	this.drawSolar = drawSolar;
	//append g to group objects
	var svg = 	d3.select("#profileimage")
	.append("g").attr("id",this.id);
}

Solar.prototype.initializeComponents = function(){
	groupId = this.id;
	$.each(this.data, function(cIndex,objectToDraw){
		drawSolar(groupId,objectToDraw.id,objectToDraw.x,objectToDraw.y, objectToDraw.width,objectToDraw.height);
	});
}

Solar.prototype.updateComponents = function(jsonData){
	$.each(this.data, function(cIndex,objectToUpdate){
		var linkedRelay = objectToUpdate.linkedRelay;
		var relayValue = jsonData.realpower[linkedRelay];
		//var relayValue = jsonData.solar[pvToUpdate.id];
		relayValue = -1* relayValue; // multiply by negative 1 for now
		if (relayValue>20) { 
			$("#"+objectToUpdate.id).show();
		}else{
			$("#"+objectToUpdate.id).hide();
		}
	});
}


function drawSolar(groupId,id,x,y,w,h){
	var motorImage = "assets/images/solar.gif";	
	
	d3.select("#"+groupId) //select body in html
		.append("image")  // add image tag in svg element
		.attr('id',id) 
		.attr('xlink:href',motorImage) //set href property of image element..
		.attr("x",x) 
		.attr("y",y)
		.attr("width",w)
		.attr("height",h);	
}

