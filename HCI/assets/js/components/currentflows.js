function CurrentFlows (data){
	this.name = "CurrentFlows";
	this.id = "CurrentFlows_Group";
	this.data = data;
	this.drawPolygon = drawPolygon;
	
	
	var svg = 	d3.select("#profileimage")
	.append("g").attr("id",this.id);
}

CurrentFlows.prototype.initializeComponents = function(){
	var groupId = this.id;

	// draw arrows
	$.each(this.data, function(cIndex,objectToDraw){
		drawPolygon(
			groupId,
			objectToDraw.id,
			objectToDraw.x,
			objectToDraw.y,
			objectToDraw.scale,
			objectToDraw.angle,
			"0,25,18,0,37,25,26,25,26,52,10,52,10,25", // default points for all arrows until transformed,
			'#f99503',	// stroke
			'#f1c40f',	// fill - probably want to controll this in css
			'hidden'
		);
	});
};


CurrentFlows.prototype.updateComponents = function(jsonData){
	$.each(this.data, function(cIndex,objectToUpdate){
		var relayId = objectToUpdate.linkedField;  // This is the relay field in the JSON data that we want
		var status = jsonData.realpower[relayId];  // Status of Relay for arrow
		var arrow = document.getElementById(objectToUpdate.id);

		// arrow angle. 
		angle = objectToUpdate.angle;
		if (status < 0) {
			angle=180+objectToUpdate.angle;
		}
		arrow.setAttribute(
			'transform',
			'scale(' + objectToUpdate.scale + ')' +
			'translate(' + objectToUpdate.x + ',' + objectToUpdate.y+') ' +
			'rotate(' + angle + ',19,26) '
		);
		
		// hide arrow if status is not above threshold
		if (status == 0 || Math.abs(status) < objectToUpdate.threshhold){
			arrow.setAttribute('visibility','hidden');
		}else {
			arrow.setAttribute('visibility','visible');			
		}		
	});
}

// right now used for drawing arrows
function drawPolygon(groupId, id, x, y, scale, angle, points, stroke, fill, visibility){
	var svg = document.getElementById(groupId);
	var polygon = document.createElementNS("http://www.w3.org/2000/svg", 'polygon');
		polygon.setAttribute('id',id);
		polygon.setAttribute('points',points);
		polygon.setAttribute('transform',
					'scale(' + scale + ')' +
					'translate(' + x + ',' + y + ') ' +
					'rotate(' + angle + ',19,26)'
				);
		polygon.setAttribute('stroke', stroke);
		polygon.setAttribute('fill', fill);
		polygon.setAttribute('visibility', visibility);
		
	svg.appendChild(polygon);
}