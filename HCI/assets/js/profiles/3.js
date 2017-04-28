// System profile definitions for "MINI BANSHEE" profile
// Make this one big json data structure
// move loadinfo instantiation into where the rest is instantiated 
// don"t update fill/stroke/etc if it"s the same
var hilDataDefinitionLocal = {
	"name":"CANARY",
	"id":"3",
	"loadKeys": {
		"x": 250,
		"y": 130
	},
	"systemProfile": {
		"width":"calc(100% - 600px)",
		"height":"calc(100% - 200px)",
		"profileimage":"canary.png",
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
			{"id":"R1","x":"229","y":"306","size":"41"},  // R1 139
			{"id":"R2","x":"502","y":"55","size":"41"},  // R2
			{"id":"R3","x":"502","y":"307","size":"41"},  // R3
			{"id":"R4","x":"502","y":"548","size":"41"}  // R4

		],
		
		// current flow arrows 	
		"currentFlows": [
			{"id":"A1","x":"325","y":"302","angle":90,"scale":1,"threshhold":0},   // R1
			{"id":"A2","x":"650","y":"50","angle":90,"scale":1,"threshhold":0},     // R2
			{"id":"A3","x":"650","y":"300","angle":90,"scale":1,"threshhold":0},   // R3
			{"id":"A4","x":"650","y":"542","angle":90,"scale":1,"threshhold":0}     // R4
		],
		
		// these are the bars above the relay (breakers)
		// rlist attribute is the list of all relays associated with this breaker		
		"relayBars": [
			{"id":"B1","x":426,"y":2,"width":10,"height":635,"rlist":[1,2,3,4]}         // B?
		],
	
		// This is the loads (Priority, Critical, Interruptible)
		"loadInfo": [
			{"id": "L3", "linkedElement":"R3", "x":935,"width":95,"height":30, "y":385, "type": "I" },
			{"id": "L4", "linkedElement":"R4","x":940,"width":95,"height":30, "y":630, "type": "C" }
		],
			
		// these are the boxes we print values for any given relay in
		"infoBoxes":[
			{ "units":"kW","linkedData":"realpower","linkedField":"R1","id":"RINFO1","message":"No data","x":225,"y":275, "color":"grey"},
			{ "units":"kW","linkedData":"realpower","linkedField":"R2","id":"RINFO2","message":"No data","x":495,"y":25, "color":"grey"},
			{ "units":"kW","linkedData":"realpower","linkedField":"R3","id":"RINFO3","message":"No data","x":495,"y":275, "color":"grey"},
			{ "units":"kW","linkedData":"realpower","linkedField":"R4","id":"RINFO4","message":"No data","x":495,"y":515, "color":"grey"},

			{ "rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R1","id":"RINF1O1","message":"No data","x":225,"y":295, "color":"grey"},
			{ "rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R2","id":"RINF1O2","message":"No data","x":495,"y":45, "color":"grey"},
			{ "rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R3","id":"RINF1O3","message":"No data","x":495,"y":295, "color":"grey"},
			{ "rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R4","id":"RINF1O4","message":"No data","x":495,"y":535, "color":"grey"}
		],
		
		"batteries" : [
		],
		
		"motors" : [
			{ "id":"MOTOR1","x":1088,"y":706,"width":58,"height":58,"linkedData":"breaker","linkedField":"R4"}
		],
		
		"generators" : [
		//	{ "id":"GEN1","x":26,"y":432,"width":36,"height":36,"relay":7},
		],
		
		"cyber" : [
			{ "id": "CYBER1","x":188,"y":431,"width":36,"height":36 }
		]
	},
	
	"graphDefinitions" : {
	
		"pq2" : { // hack to show the hitstory and the latest
			"height" : "calc(100% - 170px)",
			"width" : "59%",
			"position" : "fixed",
			"top" : "70px",
			"left" : "0px",
			"title" : "P vs Q",
			"titleFontColor" : "white",
			"backgroundColor": "transparent",
			"chartType" : "scatter",
			"markerSize" : 22,
			"markerType" : "circle",
			"markerBorderColor": "white",
			"markerBorderThickness": "white",
			"xValueType" : "number",
			"xValueFormatString" : "0.####",
			"yValueFormatString" : "0.####",
			"axisX" : {
				"title": "P",
				"maximum": 1.25,
				"minimum": -1.25,
				"interval": .3,
				"titleFontColor": "white",
				"labelFontColor": "white",
				 "stripLines": [ 
                                        {      
                                                "value":0,
                                                "label" : "",
                                                "color": "blue",
                                                "labelFontSize": 30,
                                                "labelBackgroundColor": "black"
                                        }
                                ]
	
			},
			"axisY" : {
				"title": "Q",
				"maximum": 1.2,
				"minimum": -1.2,
				"titleFontColor": "white",
				"includeZero": false,
				 "stripLines": [ 
	                               {      
                                                "value":0,
                                                "label" : "",
                                                "color": "blue",
                                                "labelFontSize": 30,
                                                "labelBackgroundColor": "black"
                                        }
		                                ]


			
			},
			"axisY2" : "",
			"maxPoints" : 1,
			"timeWindow" : "", // not relevant because xValueType is not time
			"legendPrefix" : "PQ",
			"customLegends": {
				"0" : "Grid",
				"2" : "Total_Load",
				"1" : "NG_CHP",
				"3" : "dPdQ",
				
			},
			"defaultVisible": {
				"Grid": "1",
				"Total_Load": "1",
				"NG_CHP": "1",			
				"dPdQ": "1"			
			},
			"scale" : 4000,
			"xScale" : 4000
		},
		"pq" : {
			"height" : "calc(100% - 170px)",
			"width" : "59%",
			"position" : "fixed",
			"top" : "70px",
			"left" : "0px",
			"title" : "P vs Q",
			"titleFontColor" : "white",
			"backgroundColor": "transparent",
			"chartType" : "scatter",
			"markerSize" : 20,
			"xValueType" : "number",
			"xValueFormatString" : "0.####",
			"yValueFormatString" : "0.####",
			"legend": {
				"horizontalAlign": "center",
				"fontSize": 14,
				"fontWeight": "bold",
				"fontFamily": "calibri",
				"fontColor": "white",
				"cursor":"pointer",
			},
			"axisX" : {
				"title": "P",
				"maximum": 1.25,
				"minimum": -1.25,
				"interval": .3,
				"titleFontColor": "white",
				"labelFontColor": "white",
				 "stripLines": [ 
                                        {      
                                                "value":0,
                                                "label" : "",
                                                "color": "blue",
                                                "labelFontSize": 30,
                                                "labelBackgroundColor": "black"
                                        }
                                ]
	
			},
			"axisY" : {
				"title": "Q",
				"maximum": 1.2,
				"minimum": -1.2,
				"titleFontColor": "white",
				"includeZero": false,
				 "stripLines": [ 
	                               {      
                                                "value":0,
                                                "label" : "",
                                                "color": "blue",
                                                "labelFontSize": 30,
                                                "labelBackgroundColor": "black"
                                        }
		                                ]


			
			},
			"axisY2" : "",
			"maxPoints" : 400,
			"timeWindow" : "", // not relevant because xValueType is not time
			"legendPrefix" : "PQ",
			"customLegends": {
				"0" : "Grid",
				"2" : "Total_Load",
				"1" : "NG_CHP",
				"3" : "dPdQ",
				
			},
			"defaultVisible": {
				"Grid": "1",
				"Total_Load": "1",
				"NG_CHP": "1",			
				"dPdQ": "1"			
			},
			"scale" : 4000,
			"xScale" : 4000
		},
		"waveform" : {
			"height" : "calc(50% - 100px)",
			"width" : "39%",
			"position" : "fixed",
			"top" : "50%",
			"left" : "60%",
			"title" : "Time Domain",
			"titleFontColor" : "white",
			"backgroundColor": "black",
			"chartType" : "line",
			"xValueType" : "number",
			"xValueFormatString" : "0.####",
			"yValueFormatString" : "0.####",
			"axisX" : {
				"title": "Time (ms)",
				"titleFontColor": "white",
				"labelFontColor": "white"	
			},
			"axisY" : {
				"title": "Per Unit",
				"maximum": 1,
				"minimum": -1,
				"titleFontColor": "white",
				"includeZero": false,
				"stripLines": ""
			
			},
			"axisY2" : "",
			"maxPoints" : 166,
			"timeWindow" : "", // not relevant because xValueType is not time
			"legendPrefix" : "Waveform",
			"customLegends": {
				"0" : "W1",
				"1" : "W2",
				"2" : "W3"	
			},
			"defaultVisible": {
				"W1": "1",
				"W2": "1",
				"W3": "1"				
			},
			"scale" : 1		
		},
		
		"voltage" : {
			"height" : "calc(50% - 70px)",
			"width" : "39%",
			"position" : "fixed",
			"top" : "70px",
			"left" : "60%",
			"title" : "Voltage",
			"titleFontColor" : "white",
			"backgroundColor": "black",
			"chartType" : "line",
			"xValueType" : "dateTime",
			"xValueFormatString" : "hh:mm:ss.fff",
			"yValueFormatString" : "0.####",
			"axisX" : {
				"title": "Last 300 seconds",
				"titleFontColor": "white",
				"labelFontColor": "black"	
			},
			"axisY" : {
				"title": "Per Unit",
				"maximum": 1.15,
				"minimum": 0.85,
				"titleFontColor": "white",
				"includeZero": false,
				"stripLines": [ 
					{      
						"startValue": 1.05,
						"endValue": 1.056,
						"color": "red",
						"lineDashType": "dash"
					},
					{
						"startValue": 0.95,
						"endValue": 0.956,
						"lineDashType": "dash",
						"color": "red"
					}
				]
			},
			"axisY2" : "",
			"maxPoints" : 4500,
			"timeWindow" : 300, // seconds
			"legendPrefix" : "R",
			"customLegends": {
				"0" : "Grid"	
			},
			"defaultVisible": {
				"Grid" : 1		
			},
			"scale" : 1
		},
		/*
		"voltagecumulative" : {
			"height" : "500px",
			"width" : "600px",
			"position" : "fixed",
			"top" : "510px",
			"left" : "1280px",
			"title" : "Energy Sources",
			"titleFontColor" : "white",
			"backgroundColor": "black",
			"chartType" : "stackedArea",
			"xValueType" : "dateTime",
			"xValueFormatString" : "hh:mm:ss.fff",
			"yValueFormatString" : "0.####",
			"axisX" : {
				"title": "15 Minutes",
				"titleFontColor": "white",
				"labelFontColor": "black"	
			},
			"axisY" : {
				"title": "MW",
				"maximum": 10,
				"minimum": 0,
				"titleFontColor": "white",
				"includeZero": false,
				"stripLines": ""
			},
			"axisY2" : {
				"title": "Battery SoC",
				"maximum": 100,
				"minimum": 0,
				"suffix": "%",  
				"titleFontColor": "white",
				"includeZero": true
			
			},
			"customChartDefinition" : {  // works same way as custom Legend. overrides chart type for some series (used for secondary axis)
				"5": {
					"chartType": "line",
					"axisYType" : "secondary"
				}
			
			},
			"maxPoints" : 13500,
			"timeWindow" : 900, // seconds
			"legendPrefix" : "R",
			"customLegends": {
				"0" : "PV",
				"1" : "Gen 1",
				"2" : "Gen 2",
				"3" : "Battery",
				"4" : "Grid",
				"5" : "Battery SoC"		
			},
			"defaultVisible": {
				"PV" : 1,
				"Gen 1" : 1,
				"Gen 2" : 1,
				"Battery" : 1,
				"Grid" : 1,
				"Battery SoC" : 1			
			},
			"scale" : 1
		}
		*/
	}

}
