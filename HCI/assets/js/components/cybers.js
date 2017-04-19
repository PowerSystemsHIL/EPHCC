function Cybers (data){
	this.name = "Cybers";
	this.id = "Cybers_Group";
	this.data = data;
		
	var svg = 	d3.select("#profileimage")
	.append("g").attr("id",this.id);
}

Cybers.prototype.initializeComponents = function(){
	$.each(this.data, function(cIndex,objectToDraw){
		// make the relays clickable/cyber (should be in the cyber component)
		$("."+objectToDraw.classToBind).on("click", function(d){
			// open cyber form
			//this.id
			console.log("click!")		
		});
	});
}

Cybers.prototype.updateComponents = function(){
	/*
	relayValue = -1* relayValue;
	if (relayValue>20) { 
		$("#"+solarToUpdate.id).show();
	}else{
		$("#"+solarToUpdate.id).hide();
	}
	*/
};
