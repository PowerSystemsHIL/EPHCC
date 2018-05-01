function GridPowers (data){
	this.name = "GridPowers";
	this.id = "GridPowers_Group";
	this.data = data;
	

	//create the g element for this item set
	var svg = 	d3.select("#profileimage")
	.append("g").attr("id",this.id);
}
GridPowers.prototype.initializeComponents = function(){
	var groupId = this.id;

	$.each(this.data, function(GIndex,objectToDraw){
		var svg = 	d3.select("#"+groupId)
		.append("g").attr("id","GridG_"+this.id);

		// Little box to draw rectangle
		svg.append("rect")
			.attr("id",objectToDraw.id)
			.attr("x", objectToDraw.x)
			.attr("y", objectToDraw.y)
			.attr("width", objectToDraw.width)
			.attr("height", objectToDraw.height)
		.style("fill", "white");		
	});
}

GridPowers.prototype.updateComponents = function(jsonData){
	$.each(this.data, function(GIndex,objectToUpdate){
		var linkedField = objectToUpdate.miscField;
		var gridValue = jsonData.gridpower[linkedField];
		if (gridValue == 0) { 
			$("#"+objectToUpdate.id).css("fill", "yellow");
		}else{
			$("#"+objectToUpdate.id).css("fill", "grey");
		}
	});
}