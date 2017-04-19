function Generators (data){
	this.name = "Generators";
	this.id = "Generators_Group";
	
	this.data = data;
	this.drawGenerator = drawGenerator;
	this.getGeneratorImage = getGeneratorImage;
	this.updateGenerator = updateGenerator;
	
	//append g to group objects
	var svg = 	d3.select("#profileimage")
	.append("g").attr("id",this.id);
	
}
Generators.prototype.initializeComponents = function(){
	var groupId = this.id;

	$.each(this.data, function(GIndex,objectToDraw){
		drawGenerator(groupId,objectToDraw.id,objectToDraw.x,objectToDraw.y, objectToDraw.width,objectToDraw.height);
	});
}

Generators.prototype.updateComponents = function(jsonData){
	$.each(this.data, function(GIndex,objectToUpdate){
		var linkedRelay = objectToUpdate.linkedRelay;
		var relayValue = jsonData.realpower[linkedRelay];
		updateGenerator(objectToUpdate, relayValue);
	});
}

function getGeneratorImage(relay) {
	if (relay==0) { 
		return "assets/images/offlight.png"; // lightbulb icons from wikimedia
	} 
	return "assets/images/animatedlight2.gif";
}

function drawGenerator(groupId,id,x,y,w,h){
	var generatorImage = getGeneratorImage(0);	
	d3.select("#"+groupId) //select body in html
		.append("image")  // add image tag in svg element
		.attr('id',id) 
		.attr('xlink:href',generatorImage) //set href property of image element..
		.attr("x",x) 
		.attr("y",y)
		.attr("width",w)
		.attr("height",h);	
}

function updateGenerator(generatorToUpdate, relayValue) {
	var imageToUse = getGeneratorImage(relayValue);
	if (relayValue>=0) {
		$("#"+generatorToUpdate.id).attr('href',imageToUse);
	}else{
		$("#"+generatorToUpdate.id).attr('href',imageToUse);
	}
}
