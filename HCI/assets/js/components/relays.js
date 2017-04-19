function Relays (data){
	this.name = "Relays";
	this.id = "Relays_Group";
	this.data = data;
	this.drawRect = drawRect;
	
	var svg = 	d3.select("#profileimage")
	.append("g").attr("id",this.id);
}

Relays.prototype.initializeComponents = function(){
	groupId = this.id;
	
	// Default styling of breaker box
	var relaystyle = 'fill-opacity:1.0; stroke:#fff; stroke-width:1; ';	
	var relayclass="relay";
	// draw each of the relays
	$.each(this.data, function(rIndex,objectToDraw){
		drawRect(
			groupId,
			objectToDraw.id,
			objectToDraw.x,
			objectToDraw.y,
			objectToDraw.size,
			objectToDraw.size,
			relaystyle,
			relayclass
		);
	});
};


Relays.prototype.updateComponents = function(jsonData){
	if (typeof (jsonData.breaker) !== "undefined" ) { // make sure breaker data exists
		$.each(this.data, function(rIndex,objectToUpdate){
			if (typeof(jsonData.breaker[objectToUpdate.id]) !== "undefined"){ // make sure this data item exists
				var status = jsonData.breaker[objectToUpdate.id];  // Status for relay
				var relayToUpdate = document.getElementById(objectToUpdate.id);
				relayToUpdate.value = status;
				if (status == 0) {
					relayToUpdate.style.fill="#0f0"; // not energized
				}
				if (status == 1) {
					relayToUpdate.style.fill="#f00"; // energized
				}
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
