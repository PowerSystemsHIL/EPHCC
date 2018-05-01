function InfoBoxes (data){
	this.name = "InfoBoxes";
	this.id = "InfoBoxes_Group";

	this.data = data;
	this.drawText = drawText;
	this.singleStatColor = singleStatColor;
	
	var svg = 	d3.select("#profileimage")
	.append("g").attr("id",this.id);
}

InfoBoxes.prototype.initializeComponents = function(){
	var groupId = this.id;

	$.each(this.data, function(cIndex,objectToDraw){
		drawText(
			groupId,
			objectToDraw.id, 
			objectToDraw.x, 
			objectToDraw.y, 
			objectToDraw.message, 
			objectToDraw.color
		);	
	});
};

InfoBoxes.prototype.updateComponents = function(jsonData){
	$.each(this.data, function(cIndex,objectToUpdate){
		var infoBoxDataType = objectToUpdate.linkedData;
		var infoBoxDataItem = objectToUpdate.linkedField;
		var infoBoxUnits = objectToUpdate.units;
		var textColor = objectToUpdate.color;

		var status = jsonData[infoBoxDataType][infoBoxDataItem];
		var boxText = "";
		
		if (typeof (status) == "undefined") {
			boxText = "No data";
		} else {
			boxText = (status).toString() + " " + (infoBoxUnits).toString();

			if (typeof(objectToUpdate.rangeColors) != "undefined") {
				textColor = singleStatColor(objectToUpdate.rangeColors,status);
			}
		}
		var text = document.getElementById(objectToUpdate.id);
//		text.setAttribute('fill', 'green');
		text.textContent = boxText;
		text.setAttribute("fill",textColor);
	});
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
function singleStatColor(colorRanges, value) {
	var toReturn = "grey";
	$.each(colorRanges, function(cIndex, cData) {
		if (value <= cData.high && value>=cData.low) {
			toReturn =cData.color;
			return cData.color;
		}
	});
	return toReturn;
}