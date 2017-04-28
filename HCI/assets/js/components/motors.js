// motor icon from here: http://preloaders.net/en/search/gear
function Motors (data){
	this.name = "Motors";
	this.id = "Motors_Group";
	this.data = data;
	this.drawMotor = drawMotor;
	this.updateMotor = updateMotor;
	
	var svg = 	d3.select("#profileimage")
	.append("g").attr("id",this.id);
}

Motors.prototype.initializeComponents = function(){
	groupId = this.id;
	$.each(this.data, function(GIndex,objectToDraw){
		drawMotor(groupId, objectToDraw.id,objectToDraw.x,objectToDraw.y, objectToDraw.width,objectToDraw.height);
	});
}

Motors.prototype.updateComponents = function(jsonData){
	$.each(this.data, function(GIndex,objectToUpdate){
		var motorDataType =  objectToUpdate.linkedData;
		var motorDataItem =  objectToUpdate.linkedField;

		var motorValue = 0;
		
		// check to see if the item is in the returned JSON or if we should check the DOM
		if (typeof (jsonData[motorDataType]) != "undefined"){
			motorValue = jsonData[motorDataType][motorDataItem];
		} else if (typeof(document.getElementById(motorDataItem)) != "undefined") {
			motorValue = document.getElementById(motorDataItem).value;
		}
				
		//check to see if the motor value in the jsonData overrides this but only when the bus is on
		if (typeof (jsonData["motors"]) != "undefined" && motorValue == 1){		
			motorValue = jsonData["motors"][objectToUpdate.id];		
		}
		updateMotor(objectToUpdate, motorValue);
	});
}

function drawMotor(groupId, id,x,y,w,h){
	var motorImage = "assets/images/motor.gif";	
	d3.select("#"+groupId) //select body in html
		.append("image")  // add image tag in svg element
		.attr('id',id) 
		.attr('xlink:href',motorImage) //set href property of image element..
		.attr("x",x) 
		.attr("y",y)
		.attr("width",w)
		.attr("height",h);	
}

function updateMotor(motorToUpdate, motorValue) {
	if (motorValue>0) { 
		$("#"+motorToUpdate.id).show();
	}else{
		$("#"+motorToUpdate.id).hide();
	}
}
