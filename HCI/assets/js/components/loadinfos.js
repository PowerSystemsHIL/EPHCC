function LoadInfos (data){
	this.name = "LoadInfos";
	this.id = "LoadInfos_Group";
	this.data = data;

//TODO: These need to be in the settings. Need to think how to fit into current paradigm
	this.x = 150;
	this.y = 130;
	this.drawLoadKey = drawLoadKey;
	this.loadKeys = [
		{'name': 'Critical Load', 'clicked':true, 'color':'navy', 'type':'C'},
		{'name': 'Priority load', 'clicked':true, 'color':'blue', 'type':'P'},
		{'name': 'Interruptible Load', 'clicked':true, 'color':'cornflowerblue', 'type':'I'}
	]; 
	
	//append g to group objects
	var loadBoxStyle = 'mix-blend-mode: screen';
	var svg = 	d3.select("#profileimage")
	.append("g").attr("id",this.id).attr("style",loadBoxStyle);

}

LoadInfos.prototype.initializeComponents = function(){	
	var svg = d3.select("#"+this.id);
	var rangeValues = [];
	var domainValues = [];
	$.each(this.loadKeys, function( index, element) {
		if (domainValues.indexOf(element.type) == -1){
			domainValues.push (element.type);
		}
		if (rangeValues.indexOf(element.color) == -1){
			rangeValues.push (element.color);
		}
	});
	
	var col = d3.scale.ordinal()
				.domain(domainValues)
				.range(rangeValues);
	
	
	var loadBoxStyle = 'fill-opacity:1; stroke:#fff; stroke-width:3; mix-blend-mode: screen';

	var loadBoxes =	 svg.selectAll("loadbox")
		.data(this.data)
		.enter()
		.append("rect")
			.attr("id", function(d){return d.id} )
			.attr("x", function(d){return d.x} )
			.attr("y", function(d){return d.y} )
			.attr("width", function(d){return d.width})
			.attr("height",function(d){return d.height})
			.attr("opacity", 1)
			.attr("fill", function(d){return col(d.type)})
			//.attr("class", "loadbox")
			.attr("class", function(d){return "load" + d.type})
			.attr("style",loadBoxStyle);
	drawLoadKey(this.id,col, this.x, this.y, this.loadKeys);						

};

LoadInfos.prototype.updateComponents = function(jsonData){
	$.each(this.data, function(GIndex,objectToUpdate){
		var linkedElementId = objectToUpdate.linkedElement;
		var linkedElement =  document.getElementById(linkedElementId); // could be Bus, could be Relay
		var status = -1;

		if (typeof(linkedElement) != "undefined" && linkedElement != null) {
			status = linkedElement.value;
		}
		var loadToUpdate = document.getElementById(objectToUpdate.id);
		objectToUpdate.value = status;
		if (status == 0) {
			loadToUpdate.style.stroke="gray"; // not energized
		}
		if (status == 1) {
			loadToUpdate.style.stroke="#f00"; // energized 
		}
	});
}


function drawLoadKey(groupId, col, x, y, loadKeys){
	
	var svg = d3.select("#"+groupId);	

	var keyboxes = 	svg.selectAll("keys")
			.data(loadKeys)
			.enter()
			.append("g")
			.attr("class", "keybox")
			.style("cursor","pointer");
	var loadBoxStyle = 'fill-opacity:1.0; stroke:#fff; stroke-width:1; mix-blend-mode: screen;';

	keyboxes.append("rect")
			.attr("x", x)
			.attr("y", function(d,i){return y + i*30})
			.attr("width", 25)
			.attr("height", 25)
			.attr("fill", function(d){return col((d.name)[0])})
			.attr("style",loadBoxStyle);

	keyboxes.append("text")
			.attr("x", x+30)
			.attr("y", function(d,i){return y+ 18 + i*30})
			.text(function(d){return d.name})
			.attr("fill", "white")
			.attr("opacity", .6);
						
	// this seems redundant to do in the loop since it only needs to be done once for the class
	keyboxes.on("click", function(d){
		//	console.log(d)
			var classname = ".load" + (d.name)[0]
		//	console.log(classname)
			var state = d.clicked 
			
			var sel = svg.selectAll(classname)
			
			//console.log(sel)  

			if (state) { 
				//if clicked already, then set state to false 
				//set opacity to 0 
				sel.attr("opacity", 0)
					.attr("stroke", "none")

				d.clicked = false
				}
			else {
				//set state to true
				//set opacity to .5
				sel.attr("opacity", .8)
			  		//.attr("mix-blend-mode", 'darken')
			  	d.clicked = true
			}
			
		})
		.attr("class", "keys");
}


function drawText(id, x, y, message, color) {
	var svg = document.getElementById('profileimage');
	var text = document.createElementNS("http://www.w3.org/2000/svg", 'text');
		text.setAttribute('id', id);
		text.setAttribute('x', x);
		text.setAttribute('y', y);
		text.setAttribute('fill', color);
		text.textContent = message;	
	svg.appendChild(text);
}