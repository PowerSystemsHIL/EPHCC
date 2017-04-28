// System profile definitions for "MINI BANSHEE" profile
// Make this one big json data structure
// move loadinfo instantiation into where the rest is instantiated 
// don"t update fill/stroke/etc if it"s the same
var hilDataDefinitionLocal = {
	"name":"DEMO",
	"id":"3",
	"loadKeys": {
		"x": 250,
		"y": 130
	},
	"systemProfile": {
		"width":"calc(100% - 600px)",
		"height":"calc(100% - 200px)",
		"profileimage":"demo.png",
		"svg" : {
			"boxWidth":"1200",
			"boxHeight":"820"
		},		
		"firewall": {
			"show":"yes",
			"width":"600px",
			"height":"100%",
			"layout":"right: 0px; top: 100px;"

		},
		"powerfactor":{
			"show":"no",
			"with":"10",
			"height":"10"
		},
		"testDescription": {
			"x": "1500",
			"y": "100",
			"color": "grey",
			"message": [
				"Time Step: 80uSec", 
			    "Min Demand: 4.2 MW",
				"Max Demand: 12 MW"
			]
		},
		// relays boxes
		"relays":[ 
			

		],
		
		// current flow arrows 	
		"currentFlows": [
			
		],
		
		// these are the bars above the relay (breakers)
		// rlist attribute is the list of all relays associated with this breaker		
		"relayBars": [
			
		],
	
		// This is the loads (Priority, Critical, Interruptible)
		"loadInfo": [
			
		],
			
		// these are the boxes we print values for any given relay in
		"infoBoxes":[
			
		],
		
		"batteries" : [
		],
		
		"motors" : [
		],
		
		"generators" : [
		//	{ "id":"GEN1","x":26,"y":432,"width":36,"height":36,"relay":7},
		],
		
		"cyber" : [
		]
	},
	
	"graphDefinitions" : {
	
	}

}
