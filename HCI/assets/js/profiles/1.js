// System profile definitions for "SHERIFF" profile
// Make this one big json data structure
// move loadinfo instantiation into where the rest is instantiated 
// don"t update fill/stroke/etc if it"s the same
var hilDataDefinitionLocal = {
	"name":"SHERIFF",
	"id":"1",
	"loadKeys": {
		"x": 1010,
		"y": 30
	},
	"systemProfile": {
		"width":"calc(100% - 600px)",
		"height":"calc(100% - 200px)",
		"profileimage":"sheriff.png",
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
			"width":"10",
			"height":"10"
		},
		"testDescription": {
			"x": "10",
			"y": "50",
			"color": "grey",
			"message": [
				"Time Step: 80uSec", 
			    "Min Demand: 4.2 MW",
				"Max Demand: 12 MW"
			]
		},
		// relays boxes
		"relays":[ 
			{"id":"R1","x":"488","y":"54","size":"12"},  // R1 139
			{"id":"R2","x":"626","y":"161","size":"12"},  // R2
			{"id":"R3","x":"488","y":"154","size":"12"},  // R3
			{"id":"R4","x":"352","y":"161","size":"12"},  // R4
			{"id":"R5","x":"1092","y":"351","size":"12"}, // R5
			{"id":"R6","x":"874","y":"266","size":"12"},  // R6
			{"id":"R7","x":"37","y":"395","size":"12"},   // R7
			{"id":"R8","x":"1034","y":"351","size":"12"}, // R8
			{"id":"R9","x":"743","y":"416","size":"12"},  // R9
			{"id":"R10","x":"862","y":"425","size":"12"},  // R10
			{"id":"R11","x":"569","y":"259","size":"12"},  // R11
			{"id":"R12","x":"412","y":"272","size":"12"},  // R12
			{"id":"R13","x":"664","y":"596","size":"12"},  // R13
			{"id":"R14","x":"566","y":"523","size":"12"},  // R14
			{"id":"R15","x":"474","y":"523","size":"12"},  // R15
			{"id":"R16","x":"361","y":"523","size":"12"},  // R16
			{"id":"R17","x":"177","y":"523","size":"12"},  // R17
			{"id":"R18","x":"200","y":"390","size":"12"},  // R18
			{"id":"R19","x":"1026","y":"539","size":"12"} // R19
		],
		
		// current flow arrows 	
		"currentFlows": [
			{"id":"A1","x":"969","y":"160","angle":180,"scale":.5,"threshhold":0},   // R1
			{"id":"A2","x":"790","y":"158","angle":90,"scale":1,"threshhold":0},     // R2
			{"id":"A3","x":"598","y":"220","angle":180,"scale":.8,"threshhold":0},   // R3
			{"id":"A4","x":"235","y":"160","angle":270,"scale":1,"threshhold":0},     // R4
			{"id":"A5","x":"2175","y":"750","angle":180,"scale":.5,"threshhold":0},  // R5 
			{"id":"A6","x":"860","y":"295","angle":180,"scale":1,"threshhold":0},      // R6
			{"id":"A7","x":"159","y":"1638","angle":180,"scale":.25,"threshhold":100},   // R7
			{"id":"A8","x":"4143","y":"1455","angle":180,"scale":.25,"threshhold":300},  // R8
			{"id":"A9","x":"1855","y":"1085","angle":180,"scale":.4,"threshhold":0}, // R9 
			{"id":"A10","x":"2150","y":"1120","angle":180,"scale":.4,"threshhold":0}, // R10 
			{"id":"A11","x":"1130","y":"600","angle":180,"scale":.5,"threshhold":0},  // R11 
			{"id":"A12","x":"816","y":"600","angle":180,"scale":.5,"threshhold":0},   // R12 
			{"id":"A13","x":"1322","y":"1350","angle":180,"scale":.5,"threshhold":30}, // R13 
			{"id":"A14","x":"1124","y":"1090","angle":180,"scale":.5,"threshhold":0}, // R14
			{"id":"A15","x":"939","y":"1100","angle":180,"scale":.5,"threshhold":0},  // R15
			{"id":"A16","x":"714","y":"1100","angle":180,"scale":.5,"threshhold":0},  // R16
			{"id":"A17","x":"348","y":"1100","angle":180,"scale":.5,"threshhold":30},  // R17
			{"id":"A18","x":"805","y":"1630","angle":180,"scale":.25,"threshhold":200},   // R18
			{"id":"A19","x":"4109","y":"2218","angle":180,"scale":.25,"threshhold":200}  // R19
		],
		
		// these are the bars above the relay (breakers)
		// rlist attribute is the list of all relays associated with this breaker		
		"relayBars": [
			{"id":"B1","x":474,"y":15,"width":40,"height":7,"rlist":[1]},         // B?
			{"id":"B2","x":322,"y":115,"width":345,"height":9,"rlist":[1,4,3,2]},  // Ba
			{"id":"B3","x":19,"y":360,"width":211,"height":7,"rlist":[4,7,18]},    // Bb
			{"id":"B4","x":386,"y":230,"width":216,"height":7,"rlist":[3,11,12]},  // Bc
			{"id":"B5","x":254,"y":445,"width":327,"height":7,"rlist":[17,16,12,15,14]},   // Bd
			{"id":"B6","x":539,"y":580,"width":160,"height":8,"rlist":[13,14]},    // Be
			{"id":"B7","x":451,"y":495,"width":159,"height":8,"rlist":[14,15,12]}, // Bf
			{"id":"B8","x":154,"y":495,"width":243,"height":8,"rlist":[17,16,12]}, // Bg
			{"id":"B9","x":822,"y":230,"width":333,"height":7,"rlist":[2,6,5,8]},  // Bh
			{"id":"B10","x":1013,"y":300,"width":105,"height":7,"rlist":[2,5,8]},   // Bi
			{"id":"B11","x":844,"y":395,"width":117,"height":8,"rlist":[6,9,19]}   // Bj
		],
	
		// This is the loads (Priority, Critical, Interruptible)
		"loadInfo": [
			{"id": "L1", "linkedElement":"R4", "x":104, "y":423,"width":55,"height":30, "type": "C" },
			{"id": "L3", "linkedElement":"R12","x":248, "y":727,"width":55,"height":30, "type": "P" },
			{"id": "L4", "linkedElement":"R11","x":546, "y":405,"width":55,"height":30, "type": "P" },
			{"id": "L14", "linkedElement":"R16", "x":339, "y":727,"width":55,"height":30, "type": "I" },
			{"id": "L13", "linkedElement":"R15", "x":453, "y":727,"width":55,"height":30, "type": "I" },
			{"id": "L15", "linkedElement":"R14","x":543, "y":727,"width":55,"height":30, "type": "P" },
			{"id": "L9", "linkedElement":"R9","x":722, "y":541,"width":55,"height":30, "type": "I" },
			{"id": "L10", "linkedElement":"R10","x":840, "y":561,"width":55,"height":30, "type": "I" },
			{"id": "L11", "linkedElement":"R6","x":910, "y":561,"width":55,"height":30, "type": "C" },
			{"id": "L22", "linkedElement":"R5","x":1070, "y":488,"width":55,"height":30, "type": "P" },
		],
			
		// these are the boxes we print values for any given relay in
		"infoBoxes":[
			{ "units":"kW","linkedData":"realpower","linkedField":"R1","id":"RINFO1","message":"No data","x":528,"y":66, "color":"grey"},
			{ "units":"kW","linkedData":"realpower","linkedField":"R2","id":"RINFO7","message":"No data","x":74,"y":407, "color":"grey"},
			{ "units":"kW","linkedData":"realpower","linkedField":"R3","id":"RINFO8","message":"No data","x":950,"y":362, "color":"grey"},
			{ "units":"kW","linkedData":"realpower","linkedField":"R4","id":"RINFO13","message":"No data","x":685,"y":608, "color":"grey"},
			{ "units":"kW","linkedData":"realpower","linkedField":"R5","id":"RINFO17","message":"No data","x":197,"y":535, "color":"grey"}	
		],
		
		"batteries" : [
			{ "id":"BAT1","x":700,"y":725,"width":18,"height":40,"relay":13}
		],
		
		"motors" : [
			{ "id":"MOTOR1","x":188,"y":431,"width":36,"height":36,"linkedData":"breaker","linkedField":"R18"},
			{ "id":"MOTOR2","x":1014,"y":574,"width":36,"height":36,"linkedData":"breaker","linkedField":"R19"}
		],
		
		"generators" : [
			{ "id":"GEN1","x":26,"y":432,"width":36,"height":36,"relay":7},
			{ "id":"GEN2","x":1022,"y":387,"width":36,"height":36,"relay":8}
		],
		
		"cyber" : [
			{ "id": "CYBER1","x":188,"y":431,"width":36,"height":36 }
		]
	},
	
	"graphDefinitions" : {
		"frequency" : {
			"height" : "calc(49% - 70px)",
			"width" : "33%",
			"position" : "fixed",
			"top" : "70px",
			"left" : "",
			"title" : "Frequency",
			"titleFontColor" : "white",
			"backgroundColor": "black",
			"chartType" : "line",
			"xValueType" : "dateTime",	
			"xValueFormatString" : "hh:mm:ss.fff",
			"yValueFormatString" : "0.####",
			"axisX" : {
				"title": "Last 30 seconds",
				"titleFontColor": "white",
				"labelFontColor": "black"	
			},
			"axisY" : {
				"title": "Hz",
				"maximum": 61,
				"minimum": 59,
				"titleFontColor": "white",
				"includeZero": false,
				"stripLines":  [	
					{      
							"startValue": 59.28,
							"endValue": 59.3,
							"color": "red",
							"lineDashType": "dash"
					},
					{
							"startValue": 60.52,
							"endValue": 60.5,
							"lineDashType": "dash",
							"color": "red"

					}
				]			
			},
			"axisY2" : "",
			"maxPoints" : 450,
			"timeWindow" : 30, // seconds
			"legendPrefix" : "R",
			"customLegends": {
				"0" : "Grid",
				"6" : "Gen 1",
				"7" : "Gen 2",
				"16" : "PV",
				"12" : "Battery",
				"17" : "Motor 1",
				"18" : "Motor 2"		
			},
			"defaultVisible": {
				"Grid" : 1,
				"Gen 1" : 1,
				"Gen 2" : 1,
				"PV" : 1,
				"Battery" : 1,
				"Motor 1" : 1,
				"Motor 2" : 1			
			},
			"scale" : 468.1142857
		},
		
		"reactivepower" : {
			"height" : "calc(49% - 100px)",
			"width" : "33%",
			"position" : "fixed",
			"top" : "50%",
			"left" : "33.33%",
			"title" : "Reactive Power",
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
				"title": "MVAR",
				"maximum": 5,
				"minimum": -3,
				"titleFontColor": "white",
				"includeZero": false,
				"stripLines": [	
					{      
						"value":0,
						"label" : "0",
						"color": "grey",
						"labelFontSize": 30,
						"labelBackgroundColor": "black"
					}
				]
			},
			"axisY2" : "",
			"maxPoints" : 4500,
			"timeWindow" : 300, // seconds
			"legendPrefix" : "R",
			"customLegends": {
				"0" : "Grid",
				"6" : "Gen 1",
				"7" : "Gen 2",
				"16" : "PV",
				"12" : "Battery",
				"17" : "Motor 1",
				"18" : "Motor 2"		
			},
			"defaultVisible": {
				"Grid" : 1,
				"Gen 1" : 1,
				"Gen 2" : 1,
				"PV" : 1,
				"Battery" : 1,
				"Motor 1" : 1,
				"Motor 2" : 1			
			},
			"scale" : 1000			
		},
		
		"powerreal" : {
			"height" : "calc(49% - 70px)",
			"width" : "33%",
			"position" : "fixed",
			"top" : "70px",
			"left" : "33.33%",
			"title" : "Real Power",
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
				"title": "MW",
				"maximum": 9,
				"minimum": -5,
				"titleFontColor": "white",
				"includeZero": false,
				"stripLines": [	
					{      
						"value":0,
						"label" : "0",
						"color": "grey",
						"labelFontSize": 30,
						"labelBackgroundColor": "black"
					}
				]			
			},
			"axisY2" : "",
			"maxPoints" : 4500,
			"timeWindow" : 300, // seconds
			"legendPrefix" : "R",
			"customLegends": {
				"0" : "Grid",
				"6" : "Gen 1",
				"7" : "Gen 2",
				"16" : "PV",
				"12" : "Battery",
				"17" : "Motor 1",
				"18" : "Motor 2"		
			},
			"defaultVisible": {
				"Grid" : 1,
				"Gen 1" : 1,
				"Gen 2" : 1,
				"PV" : 1,
				"Battery" : 1,
				"Motor 1" : 1,
				"Motor 2" : 1			
			},
			"scale" : 1000,
			"y1Suffix" : ""
		},
		
		"waveform" : {
			"height" : "calc(49% - 100px)",
			"width" : "33%",
			"position" : "fixed",
			"top" : "50%",
			"left" : "0px",
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
			"maxPoints" : 208,
			"timeWindow" : "", // not relevant because xValueType is not time
			"legendPrefix" : "Waveform",
			"customLegends": {
				"0" : "Gen 4MW Voltage",
				"1" : "Gen 1MW Voltage",
				"2" : "Batt current"	
			},
			"defaultVisible": {
				"Gen 4MW Voltage": "1",
				"Gen 1MW Voltage": "1",
				"Batt current": "1"				
			},
			"scale" : 26214.4		
		},
		
		"voltage" : {
			"height" : "calc(49% - 70px)",
			"width" : "33%",
			"position" : "fixed",
			"top" : "70px",
			"left" : "66.66%",
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
				"0" : "Grid",
				"6" : "Gen 1",
				"7" : "Gen 2",
				"16" : "PV",
				"12" : "Battery",
				"17" : "Motor 1",
				"18" : "Motor 2"		
			},
			"defaultVisible": {
				"Grid" : 1,
				"Gen 1" : 1,
				"Gen 2" : 1,
				"PV" : 1,
				"Battery" : 1,
				"Motor 1" : 1,
				"Motor 2" : 1			
			},
			"scale" : 26214.4
		},
		
		"voltagecumulative" : {
			"height" : "calc(49% - 100px)",
			"width" : "33%",
			"position" : "fixed",
			"top" : "50%",
			"left" : "66.66%",
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
			"scale" : 1000
		}
	}

}
