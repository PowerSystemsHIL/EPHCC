function TestDescriptions (data){
	this.name = "TestDescriptions";
	this.id = "TestDescriptions_Group";
	this.data = data;
	this.drawText = drawText;
	
	var svg = 	d3.select("#profileimage")
	.append("g").attr("id",this.id);
}

TestDescriptions.prototype.initializeComponents = function(){
	var groupId = this.id;

	$.each(this.data, function(rIndex,objectToDraw){
			// System profile simulation description
		var profileDescription = objectToDraw.message;
		var messageX = parseInt(objectToDraw.x);
		var messageY = parseInt(objectToDraw.y);
		var messageColor = objectToDraw.color;
		for (num=0; num<profileDescription.length; num++) {
			drawText(groupId,("testDescription"+num), messageX,  (messageY+20*num), profileDescription[num], messageColor);		
		}
	});
};


TestDescriptions.prototype.updateComponents = function(){
	
	
};


function drawText(groupId,id, x, y, message, color) {
	var svg = document.getElementById(groupId);
	var text = document.createElementNS("http://www.w3.org/2000/svg", 'text');
		text.setAttribute('id', id);
		text.setAttribute('x', x);
		text.setAttribute('y', y);
		text.setAttribute('fill', color);
		text.textContent = message;	
	svg.appendChild(text);
}