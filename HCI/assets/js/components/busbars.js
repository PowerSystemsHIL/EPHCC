function Busbars (data){
	this.name = "Busbars";
	this.id = "Busbars_Group";
	this.data = data;
	this.drawRect = drawRect;
	
	var svg = 	d3.select("#profileimage")
	.append("g").attr("id",this.id);
}

Busbars.prototype.initializeComponents = function(){
	groupId = this.id;
	var relaybarclass="relaybar";
	var relaybusstyle = 'fill-opacity:1.0; stroke:#fff; stroke-width:1; ';	

	$.each(this.data, function(rIndex,objectToDraw){
		drawRect(
			groupId,
			objectToDraw.id,
			objectToDraw.x,
			objectToDraw.y,
			objectToDraw.height,
			objectToDraw.width,
			relaybusstyle,
			relaybarclass
		);
	});
};

// update relay bar aka bus color/status
Busbars.prototype.updateComponents = function(jsonData){
	// make sure relevant data exist
	if (typeof (jsonData.breaker) !== "undefined" && typeof(jsonData.voltage)!== "undefined" && typeof(jsonData.realpower)!== "undefined" ) {
		var voltages = jsonData.voltage;
		var realpowers = jsonData.realpower;
		var breakers = jsonData.breaker;
		$.each(this.data, function(rIndex,objectToUpdate){
			var rect = document.getElementById(objectToUpdate.id);
			var bstat=0;
			var voltage = 0;
			var vcondition = false;
			$.each(objectToUpdate.linkedRelays, function(index, linkedRelay) {
				// using real power here because if breaker is open but is not energized, the bus is not energized
				brkstat = Math.abs(realpowers[linkedRelay]); 
				voltage = Math.abs(voltages[linkedRelay]); 
				var breakerOpen = Math.abs(breakers[linkedRelay]); 
				if (voltage > .2 && breakerOpen ==1) {
					vcondition = true;
				}
				bstat += brkstat;
			});			
			if ((bstat/2 > 10 || vcondition)) {
				rect.value = 1;
				rect.setAttribute('stroke','#f00');
				rect.setAttribute('fill','#f00');
			}else {
				rect.setAttribute('stroke','#888');
				rect.setAttribute('fill','#888');
				rect.value = 0; // set value so we can trigger other items on this
			}	
		});
	}
};

function drawRect(groupId, id, x, y, height, width, style,objclass){
	var svg = document.getElementById(groupId);
	var rect = document.createElementNS("http://www.w3.org/2000/svg", 'rect');
		rect.setAttribute('id', id);
		rect.setAttribute('x', x);
		rect.setAttribute('y', y);
		rect.setAttribute('width', width);
		rect.setAttribute('height', height);
		rect.setAttribute('style', style);
		rect.setAttribute('class', objclass);		
	svg.appendChild(rect);
};