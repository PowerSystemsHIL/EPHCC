// System profile definitions for "MINI BANSHEE" profile
// Make this one big json data structure
// move loadinfo instantiation into where the rest is instantiated 
// don"t update fill/stroke/etc if it"s the same
var hilDataDefinitionLocal = {
	"name":"BANSHEE",
	"id":"2",
	"systemProfile": {
		
		"width":"calc(100% - 50px)",
		"height":"calc(100% - 200px)",
		"profileimage":"banshee.png",
		"svg" : {
			"boxWidth":"2550",
			"boxHeight":"1150"
		},	
		"firewall": {
			"show":"no",
			"width":"400px",
			"height":"600px",
			"layout":""
			
		},
	
		"components": {
			"testDescriptions":[
				{id:"testdescription1", x:"1500", y:"100", color:"grey", message: ["Time step: 100 uSec", "Site demand: 14 MVA at 0.9 p.f."]}			
			],
			
			"powerFactors":[
				{id:"pf1",margin:20,center:1,left:.5,right:.5,majorInterval:.25,minorInterval:.05,position:"below",x:1975,y:0,width:400,height:40,"linkedRelays":["R43"]},  //R301
				{id:"pf2",margin:20,center:1,left:.5,right:.5,majorInterval:.25,minorInterval:.05,position:"below",x:250,y:0,width:400,height:40,"linkedRelays":["R45"]},  //R101
				{id:"pf3",margin:20,center:1,left:.5,right:.5,majorInterval:.25,minorInterval:.05,position:"below",x:1100,y:0,width:400,height:40,"linkedRelays":["R44"]}  //R201

			],
			// current flow arrows 	
			// threshold is when to show them (angle should be 180 for down or 270 or 90)
			"currentFlows": [
				{"id":"A1","linkedField":"R1","x":"3925","y":"390","angle":180,"scale":.5,"threshhold":0}, //301
				{"id":"A2","linkedField":"R2","x":"4232","y":"390","angle":180,"scale":.5,"threshhold":0},     //302
				{"id":"A3","linkedField":"R3","x":"4490","y":"390","angle":180,"scale":.5,"threshhold":0},   //303
				{"id":"A4","linkedField":"R4","x":"4810","y":"390","angle":180,"scale":.5,"threshhold":0},    //304
				{"id":"A5","linkedField":"R5","x":"3648","y":"730","angle":180,"scale":.5,"threshhold":0},  	//305
				{"id":"A6","linkedField":"R6","x":"3894","y":"730","angle":180,"scale":.5,"threshhold":0},      //306
				{"id":"A7","linkedField":"R7","x":"4198","y":"1700","angle":180,"scale":.5,"threshhold":0}, //307
				{"id":"A8","linkedField":"R8","x":"3980","y":"1130","angle":180,"scale":.5,"threshhold":0}, //308
				{"id":"A9","linkedField":"R9","x":"4840","y":"1476","angle":180,"scale":.5,"threshhold":0}, //309
				{"id":"A10","linkedField":"R10","x":"2090","y":"380","angle":180,"scale":.5,"threshhold":0}, //201
				{"id":"A11","linkedField":"R11","x":"2420","y":"380","angle":180,"scale":.5,"threshhold":0}, //202
				{"id":"A12","linkedField":"R12","x":"2658","y":"380","angle":180,"scale":.5,"threshhold":0},  //203
				{"id":"A13","linkedField":"R13","x":"2068","y":"1430","angle":180,"scale":.5,"threshhold":0}, //204
				{"id":"A14","linkedField":"R14","x":"2010","y":"780","angle":0,"scale":.5,"threshhold":0}, //205
				{"id":"A15","linkedField":"R15","x":"1806","y":"1000","angle":180,"scale":.5,"threshhold":0},  //206
				{"id":"A16","linkedField":"R16","x":"2092","y":"1000","angle":180,"scale":.5,"threshhold":0},  //207
				{"id":"A17","linkedField":"R17","x":"1804","y":"1430","angle":180,"scale":.5,"threshhold":0}, //208
				{"id":"A18","linkedField":"R18","x":"2392","y":"1000","angle":180,"scale":.5,"threshhold":0}, //209
				{"id":"A19","linkedField":"R19","x":"2520","y":"1000","angle":180,"scale":.5,"threshhold":0}, //210
				{"id":"A20","linkedField":"R20","x":"2546","y":"760","angle":0,"scale":.5,"threshhold":20},   //211 solar
				{"id":"A21","linkedField":"R21","x":"2644","y":"1670","angle":180,"scale":.5,"threshhold":0},     //212
				{"id":"A22","linkedField":"R22","x":"3070","y":"1770","angle":270,"scale":.5,"threshhold":0},   //213 //should this be negative or positive for left?
				{"id":"A23","linkedField":"R23","x":"2826","y":"740","angle":180,"scale":.5,"threshhold":0},     //214
				{"id":"A24","linkedField":"R24","x":"3176","y":"740","angle":180,"scale":.5,"threshhold":0},  //215
				{"id":"A25","linkedField":"R25","x":"3234","y":"1100","angle":180,"scale":.5,"threshhold":0},      //216
				{"id":"A26","linkedField":"R26","x":"2894","y":"1150","angle":180,"scale":.5,"threshhold":0}, //217
				{"id":"A27","linkedField":"R27","x":"3138","y":"1090","angle":180,"scale":.5,"threshhold":0}, //218
				{"id":"A28","linkedField":"R28","x":"2392","y":"1710","angle":180,"scale":.5,"threshhold":0}, //219
				
				{"id":"A29","linkedField":"R29","x":"925","y":"380","angle":180,"scale":.5,"threshhold":0}, //R101
				{"id":"A30","linkedField":"R30","x":"1040","y":"380","angle":180,"scale":.5,"threshhold":0}, //R102
				{"id":"A31","linkedField":"R31","x":"1140","y":"380","angle":180,"scale":.5,"threshhold":0},  //R103
				{"id":"A32","linkedField":"R32","x":"194","y":"635","angle":180,"scale":.5,"threshhold":0}, //R104
				{"id":"A33","linkedField":"R33","x":"450","y":"635","angle":180,"scale":.5,"threshhold":0},  //R105
				{"id":"A34","linkedField":"R34","x":"684","y":"740","angle":180,"scale":.5,"threshhold":0},  //R106
				{"id":"A35","linkedField":"R35","x":"796","y":"740","angle":180,"scale":.5,"threshhold":0},  //R107
				{"id":"A36","linkedField":"R36","x":"1042","y":"740","angle":180,"scale":.5,"threshhold":0}, //R108
				{"id":"A37","linkedField":"R37","x":"210","y":"1262","angle":180,"scale":.5,"threshhold":0}, //R109
				{"id":"A38","linkedField":"R38","x":"734","y":"1280","angle":180,"scale":.5,"threshhold":0},	//R110
				{"id":"A39","linkedField":"R39","x":"355","y":"1440","angle":180,"scale":.5,"threshhold":0}, //R111
				{"id":"A40","linkedField":"R40","x":"1193","y":"1128","angle":180,"scale":.5,"threshhold":0}, //R112
				{"id":"A41","linkedField":"R41","x":"1193","y":"1550","angle":180,"scale":.5,"threshhold":0},  //R113
				{"id":"A42","linkedField":"R42","x":"734","y":"1564","angle":180,"scale":.5,"threshhold":0},  //R114
				{"id":"A43","linkedField":"R43","x":"4152","y":"160","angle":180,"scale":.5,"threshhold":0}, //SEL751-3
				{"id":"A44","linkedField":"R44","x":"2526","y":"160","angle":180,"scale":.5,"threshhold":0},  //SEL751-2
				{"id":"A45","linkedField":"R45","x":"1040","y":"160","angle":180,"scale":.5,"threshhold":0}, //SEL751-1
				{"id":"A46","linkedField":"R46","x":"1370","y":"650","angle":0,"scale":.5,"threshhold":0}, //F3_GCB
				{"id":"A47","linkedField":"R47","x":"4648","y":"870","angle":0,"scale":.5,"threshhold":0}, //F1_GCB
			],
			// relays boxes
			"relays":[ 
				{"id":"R1","x":"1965","y":"238","size":"15"},  //R301
				{"id":"R2","x":"2117","y":"234","size":"15"},  //R302
				{"id":"R3","x":"2246","y":"236","size":"15"},  //R303
				{"id":"R4","x":"2406","y":"239","size":"15"},  //R304
				{"id":"R5","x":"1826","y":"400","size":"15"},  //R305
				{"id":"R6","x":"1949","y":"399","size":"15"},  //R306
				{"id":"R7","x":"2101","y":"898","size":"15"},  //R307
				{"id":"R8","x":"1993","y":"593","size":"15"},  //R308
				{"id":"R9","x":"2422","y":"769","size":"15"},  //R309
				{"id":"R10","x":"1047","y":"228","size":"15"}, //R201
				{"id":"R11","x":"1213","y":"230","size":"15"}, //R202
				{"id":"R12","x":"1330","y":"227","size":"15"}, //R203
				{"id":"R13","x":"1036","y":"750","size":"15"}, //R204
				{"id":"R14","x":"1006","y":"423","size":"15"}, //R205
				{"id":"R15","x":"905","y":"537","size":"15"},  //R206
				{"id":"R16","x":"1049","y":"532","size":"15"}, //R207
				{"id":"R17","x":"904","y":"752","size":"15"},  //R208
				{"id":"R18","x":"1198","y":"552","size":"15"}, //R209
				{"id":"R19","x":"1262","y":"551","size":"15"}, //R210
				{"id":"R20","x":"1276","y":"420","size":"15"}, //R211
				{"id":"R21","x":"1325","y":"861","size":"15"}, //R212
				{"id":"R22","x":"1486","y":"892","size":"15"}, //R213
				{"id":"R23","x":"1415","y":"400","size":"15"}, //R214
				{"id":"R24","x":"1590","y":"399","size":"15"}, //R215
				{"id":"R25","x":"1619","y":"613","size":"15"}, //R216
				{"id":"R26","x":"1447","y":"613","size":"15"}, //R217
				{"id":"R27","x":"1571","y":"572","size":"15"}, //R218		
				{"id":"R28","x":"1198","y":"885","size":"15"}, //R219			
				{"id":"R29","x":"465","y":"227","size":"15"}, //R101
				{"id":"R30","x":"522","y":"228","size":"15"}, //R102
				{"id":"R31","x":"572","y":"228","size":"15"}, //R103			
				{"id":"R32","x":"99","y":"352","size":"15"},  //R104
				{"id":"R33","x":"226","y":"350","size":"15"}, //R105
				{"id":"R34","x":"344","y":"404","size":"15"}, //R106
				{"id":"R35","x":"399","y":"405","size":"15"}, //R107
				{"id":"R36","x":"523","y":"405","size":"15"}, //R108
				{"id":"R37","x":"151","y":"551","size":"15"}, //R109
				{"id":"R38","x":"370","y":"669","size":"15"}, //R110
				{"id":"R39","x":"229","y":"663","size":"15"}, //R111
				{"id":"R40","x":"599","y":"629","size":"15"}, //R112
				{"id":"R41","x":"599","y":"727","size":"15"}, //R113
				{"id":"R42","x":"370","y":"813","size":"15"}, //R114
				
				{"id":"R43","x":"2078","y":"121","size":"15"}, //SEL751-3
				{"id":"R44","x":"1265","y":"121","size":"15"}, //SEL751-2
				{"id":"R45","x":"521","y":"120","size":"15"}, //SEL751-1
				{"id":"R46","x":"2327","y":"479","size":"15"}, //F3_GCB			
				{"id":"R47","x":"687","y":"356","size":"15"} //F1_GCB

			],
			
			// these are the bars above the relay (breakers). Otherwise known as bus
			// rlist attribute is the list of all relays associated with this breaker		
			"busbars": [
				{"id":"B1","x":459,"y":173,"width":137,"height":11,"linkedRelays":["R29","R30","R45"]}, //B101
				{"id":"B2","x":87,"y":299,"width":170,"height":11,"linkedRelays":["R29","R33"]}, //B102
				{"id":"B3","x":652,"y":306,"width":60,"height":11,"linkedRelays":["R31","R47"]}, //B103
				{"id":"B4","x":324,"y":352,"width":220,"height":11,"linkedRelays":["R30","R34","R36"]},	//B105
				{"id":"B5","x":201,"y":463,"width":56,"height":11,"linkedRelays":["R33","R37"]}, //B104
				{"id":"B6","x":261,"y":621,"width":220,"height":11,"linkedRelays":["R34","R39","R38"]}, //B106
				{"id":"B7","x":308,"y":768,"width":83,"height":11,"linkedRelays":["R38"]}, //B107
				{"id":"B8","x":1037,"y":173,"width":315,"height":11,"linkedRelays":["R44", "R10","R11","R12"]}, //B201
				{"id":"B9","x":943,"y":349,"width":83,"height":11,"linkedRelays":["R14","R48"]}, //B202
				{"id":"B10","x":1409,"y":352,"width":215,"height":11,"linkedRelays":["R12","R23","R24"]}, //B208
				{"id":"B11","x":865,"y":474,"width":218,"height":11,"linkedRelays":["R36","R10","R16","R14"]}, //B204
				{"id":"B12","x":1196,"y":474,"width":98,"height":11,"linkedRelays":["R11","R18","R19","R20"]}, //B203
				{"id":"B13","x":1393,"y":552,"width":74,"height":11,"linkedRelays":["R23","R26"]}, //B209
				{"id":"B14","x":1563,"y":531,"width":74,"height":11,"linkedRelays":["R24","R25"]}, //B210
				{"id":"B15","x":843,"y":697,"width":222,"height":11,"linkedRelays":["R39","R16"]}, //B205
				{"id":"B16","x":1192,"y":836,"width":62,"height":11,"linkedRelays":["R18","R37"]}, //B206
				{"id":"B17","x":1317,"y":819,"width":80,"height":11,"linkedRelays":["R22","R19"]}, //B207
				{"id":"B18","x":1949,"y":178,"width":481,"height":11,"linkedRelays":["R43","R1","R2","R3","R4"]}, //B301
				{"id":"B19","x":1807,"y":348,"width":166,"height":11,"linkedRelays":["R1","R5","R6"]},//B302
				{"id":"B20","x":2213,"y":420,"width":135,"height":11,"linkedRelays":["R3","R46"]}, //B306
				{"id":"B21","x":1803,"y":549,"width":63,"height":11,"linkedRelays":["R5","R25"]}, //B303
				{"id":"B22","x":1925,"y":548,"width":85,"height":11,"linkedRelays":["R6","R8","R26"]}, //B304
				{"id":"B23","x":2343,"y":723,"width":150,"height":11,"linkedRelays":["R4","R41"]},//B307
				{"id":"B24","x":2053,"y":833,"width":90,"height":11,"linkedRelays":["R2","R22"]} //B305
			],
			

			// This is the loads (Priority, Critical, Interruptible)
			"loadInfos": [
				{"id": "L1", "linkedElement":"R32", "x":82, "y":472, "width":45,"height":40, "type": "I" }, //I1
				{"id": "L2", "linkedElement":"B5", "x":223, "y":498, "width":55,"height":40, "type": "C" }, //C1 - BUS104 - B5
				{"id": "L3", "linkedElement":"R35", "x":390, "y":490, "width":45,"height":40, "type": "I" }, //I2
				{"id": "L4", "linkedElement":"R42", "x":363, "y":854, "width":50,"height":40, "type": "P" }, //P1
				{"id": "L5", "linkedElement":"B9", "x":928, "y":412, "width":45,"height":40, "type": "C" }, //C3 - BUS202 - B9
				{"id": "L6", "linkedElement":"R17", "x":894, "y":888, "width":45,"height":40, "type": "I" }, //I4
				{"id": "L7", "linkedElement":"R13", "x":1030, "y":888, "width":45,"height":40, "type": "P" }, //P3
				{"id": "L8", "linkedElement":"R28", "x":1183, "y":933, "width":45,"height":50, "type": "P" }, //P2
				{"id": "L9", "linkedElement":"R21", "x":1310, "y":904, "width":45,"height":54, "type": "I" }, //I5
				{"id": "L10", "linkedElement":"B13", "x":1380, "y":608, "width":38,"height":48, "type": "C" }, //C4 - BUS209 - B13
				{"id": "L11", "linkedElement":"R27", "x":1563, "y":610, "width":30,"height":50, "type": "P" },  //P5 
				{"id": "L12", "linkedElement":"B21", "x":1838, "y":605, "width":47,"height":40, "type": "C" },   //C5 - BUS303 - B21
				{"id": "L13", "linkedElement":"R8", "x":1982, "y":638, "width":33,"height":48, "type": "I" }, //I6
				{"id": "L14", "linkedElement":"B20", "x":2237, "y":534, "width":35,"height":50, "type": "C" }, //C6 - BUS306 -B20
				{"id": "L15", "linkedElement":"R7", "x":2090, "y":958, "width":38,"height":48, "type": "P" }, //P4
				{"id": "L16", "linkedElement":"R15", "x":898, "y":628, "width":38,"height":40, "type": "P" }, //I3
				{"id": "L17", "linkedElement":"R9", "x":2410, "y":819, "width":38,"height":48, "type": "P" },  //P6
				{"id": "L18", "linkedElement":"B6", "x":438, "y":750, "width":40,"height":43, "type": "C" }  //C2 - BUS106 - B6
			],
				
			// these are the boxes we print values for any given relay in
			
			"infoBoxes":[
				{"units":"kW","linkedData":"realpower","linkedField":"R1","id":"RINFO1","x":"1845","y":"252","color":"gray","message":"No data"},  //R301
				{"units":"kW","linkedData":"realpower","linkedField":"R2","id":"RINFO2","x":"2010","y":"249","color":"gray","message":"No data"},  //R302
				{"units":"kW","linkedData":"realpower","linkedField":"R3","id":"RINFO3","x":"2265","y":"250","color":"gray","message":"No data"},  //R303
				{"units":"kW","linkedData":"realpower","linkedField":"R4","id":"RINFO4","x":"2428","y":"251","color":"gray","message":"No data"},  //R304
				{"units":"kW","linkedData":"realpower","linkedField":"R5","id":"RINFO5","x":"1845","y":"415","color":"gray","message":"No data"},  //R305
				{"units":"kW","linkedData":"realpower","linkedField":"R6","id":"RINFO6","x":"1973","y":"414","color":"gray","message":"No data"},  //R306
				{"units":"kW","linkedData":"realpower","linkedField":"R7","id":"RINFO7","x":"2126","y":"913","color":"gray","message":"No data"},  //R307
				{"units":"kW","linkedData":"realpower","linkedField":"R8","id":"RINFO8","x":"2018","y":"608","color":"gray","message":"No data"},  //R308
				{"units":"kW","linkedData":"realpower","linkedField":"R9","id":"RINFO9","x":"2290","y":"784","color":"gray","message":"No data"},  //R309
				{"units":"kW","linkedData":"realpower","linkedField":"R10","id":"RINFO10","x":"937","y":"242","color":"gray","message":"No data"}, //R201
				{"units":"kW","linkedData":"realpower","linkedField":"R11","id":"RINFO11","x":"1103","y":"245","color":"gray","message":"No data"}, //R202
				{"units":"kW","linkedData":"realpower","linkedField":"R12","id":"RINFO12","x":"1355","y":"242","color":"gray","message":"No data"}, //R203
				{"units":"kW","linkedData":"realpower","linkedField":"R13","id":"RINFO13","x":"1061","y":"765","color":"gray","message":"No data"}, //R204
				{"units":"kW","linkedData":"realpower","linkedField":"R14","id":"RINFO14","x":"1055","y":"438","color":"gray","message":"No data"}, //R205
				{"units":"kW","linkedData":"realpower","linkedField":"R15","id":"RINFO15","x":"930","y":"552","color":"gray","message":"No data"},  //R206
				{"units":"kW","linkedData":"realpower","linkedField":"R16","id":"RINFO16","x":"1074","y":"538","color":"gray","message":"No data"}, //R207
				{"units":"kW","linkedData":"realpower","linkedField":"R17","id":"RINFO17","x":"929","y":"767","color":"gray","message":"No data"},  //R208
				{"units":"kW","linkedData":"realpower","linkedField":"R18","id":"RINFO18","x":"1095","y":"572","color":"gray","message":"No data"}, //R209
				{"units":"kW","linkedData":"realpower","linkedField":"R19","id":"RINFO19","x":"1284","y":"576","color":"gray","message":"No data"}, //R210
				{"units":"kW","linkedData":"realpower","linkedField":"R20","id":"RINFO20","x":"1301","y":"435","color":"gray","message":"No data"}, //R211
				{"units":"kW","linkedData":"realpower","linkedField":"R21","id":"RINFO21","x":"1348","y":"876","color":"gray","message":"No data"}, //R212
				{"units":"kW","linkedData":"realpower","linkedField":"R22","id":"RINFO22","x":"1461","y":"942","color":"gray","message":"No data"}, //R213
				{"units":"kW","linkedData":"realpower","linkedField":"R23","id":"RINFO23","x":"1440","y":"415","color":"gray","message":"No data"}, //R214
				{"units":"kW","linkedData":"realpower","linkedField":"R24","id":"RINFO24","x":"1615","y":"414","color":"gray","message":"No data"}, //R215
				{"units":"kW","linkedData":"realpower","linkedField":"R25","id":"RINFO25","x":"1670","y":"628","color":"gray","message":"No data"}, //R216
				{"units":"kW","linkedData":"realpower","linkedField":"R26","id":"RINFO26","x":"1470","y":"643","color":"gray","message":"No data"}, //R217
				{"units":"kW","linkedData":"realpower","linkedField":"R27","id":"RINFO27","x":"1464","y":"587","color":"gray","message":"No data"}, //R218
				{"units":"kW","linkedData":"realpower","linkedField":"R28","id":"RINFO28","x":"1091","y":"900","color":"gray","message":"No data"}, //R219
				{"units":"kW","linkedData":"realpower","linkedField":"R29","id":"RINFO29","x":"355","y":"242","color":"gray","message":"No data"}, //R101
				{"units":"kW","linkedData":"realpower","linkedField":"R30","id":"RINFO30","x":"447","y":"310","color":"gray","message":"No data"}, //R102
				{"units":"kW","linkedData":"realpower","linkedField":"R31","id":"RINFO31","x":"597","y":"243","color":"gray","message":"No data"}, //R103
				{"units":"kW","linkedData":"realpower","linkedField":"R32","id":"RINFO32","x":"18","y":"387","color":"gray","message":"No data"},  //R104
				{"units":"kW","linkedData":"realpower","linkedField":"R33","id":"RINFO33","x":"147","y":"387","color":"gray","message":"No data"}, //R105
				{"units":"kW","linkedData":"realpower","linkedField":"R34","id":"RINFO34","x":"264","y":"440","color":"gray","message":"No data"}, //R106
				{"units":"kW","linkedData":"realpower","linkedField":"R35","id":"RINFO35","x":"416","y":"430","color":"gray","message":"No data"}, //R107
				{"units":"kW","linkedData":"realpower","linkedField":"R36","id":"RINFO36","x":"540","y":"440","color":"gray","message":"No data"}, //R108
				{"units":"kW","linkedData":"realpower","linkedField":"R37","id":"RINFO37","x":"122","y":"600","color":"gray","message":"No data"}, //R109
				{"units":"kW","linkedData":"realpower","linkedField":"R38","id":"RINFO38","x":"390","y":"684","color":"gray","message":"No data"}, //R110
				{"units":"kW","linkedData":"realpower","linkedField":"R39","id":"RINFO39","x":"199","y":"710","color":"gray","message":"No data"}, //R111
				{"units":"kW","linkedData":"realpower","linkedField":"R40","id":"RINFO40","x":"624","y":"644","color":"gray","message":"No data"}, //R112
				{"units":"kW","linkedData":"realpower","linkedField":"R41","id":"RINFO41","x":"648","y":"742","color":"gray","message":"No data"}, //R113
				{"units":"kW","linkedData":"realpower","linkedField":"R42","id":"RINFO42","x":"413","y":"828","color":"gray","message":"No data"}, //R114
				{"units":"kW","linkedData":"realpower","linkedField":"R43","id":"RINFO43","x":"2103","y":"125","color":"gray","message":"No data"}, //SEL751-3
				{"units":"kW","linkedData":"realpower","linkedField":"R44","id":"RINFO44","x":"1290","y":"125","color":"gray","message":"No data"}, //SEL751-2
				{"units":"kW","linkedData":"realpower","linkedField":"R45","id":"RINFO45","x":"546","y":"125","color":"gray","message":"No data"}, //SEL751-1
				{"units":"kW","linkedData":"realpower","linkedField":"R46","id":"RINFO46","x":"2420","y":"495","color":"gray","message":"No data"}, //F3_GCB
				{"units":"kW","linkedData":"realpower","linkedField":"R47","id":"RINFO47","x":"602","y":"371","color":"gray","message":"No data"}, //F1_GCB
				{"units":"kW","linkedData":"realpower","linkedField":"R48","id":"RINFO48","x":"1065","y":"311","color":"gray","message":"No data"}, //battery
				// Voltage Info
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R1","id":"RINF1O1","x":"1845","y":"265","color":"gray","message":"No data"},  //R301
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R2","id":"RINF1O2","x":"2010","y":"265","color":"gray","message":"No data"},  //R302
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R3","id":"RINF1O3","x":"2265","y":"265","color":"gray","message":"No data"},  //R303
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R4","id":"RINF1O4","x":"2428","y":"266","color":"gray","message":"No data"},  //R304
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R5","id":"RINF1O5","x":"1845","y":"430","color":"gray","message":"No data"},  //R305
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R6","id":"RINF1O6","x":"1973","y":"430","color":"gray","message":"No data"},  //R306
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R7","id":"RINF1O7","x":"2126","y":"928","color":"gray","message":"No data"},  //R307
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R8","id":"RINF1O8","x":"2018","y":"623","color":"gray","message":"No data"},  //R308
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R9","id":"RINF1O9","x":"2290","y":"800","color":"gray","message":"No data"},  //R309
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R10","id":"RINFO110","x":"937","y":"255","color":"gray","message":"No data"}, //R201
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R11","id":"RINFO111","x":"1103","y":"260","color":"gray","message":"No data"}, //R202
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R12","id":"RINFO112","x":"1355","y":"257","color":"gray","message":"No data"}, //R203
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R13","id":"RINFO113","x":"1061","y":"780","color":"gray","message":"No data"}, //R204
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R14","id":"RINFO114","x":"1055","y":"452","color":"gray","message":"No data"}, //R205
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R15","id":"RINFO115","x":"930","y":"565","color":"gray","message":"No data"},  //R206
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R16","id":"RINFO116","x":"1074","y":"553","color":"gray","message":"No data"}, //R207
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R17","id":"RINFO117","x":"929","y":"782","color":"gray","message":"No data"},  //R208
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R18","id":"RINFO118","x":"1095","y":"587","color":"gray","message":"No data"}, //R209
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R19","id":"RINFO119","x":"1284","y":"590","color":"gray","message":"No data"}, //R210
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R20","id":"RINFO120","x":"1301","y":"450","color":"gray","message":"No data"}, //R211
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R21","id":"RINFO121","x":"1348","y":"890","color":"gray","message":"No data"}, //R212
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R22","id":"RINFO122","x":"1461","y":"957","color":"gray","message":"No data"}, //R213
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R23","id":"RINFO123","x":"1440","y":"430","color":"gray","message":"No data"}, //R214
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R24","id":"RINFO124","x":"1615","y":"429","color":"gray","message":"No data"}, //R215
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R25","id":"RINFO125","x":"1670","y":"642","color":"gray","message":"No data"}, //R216
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R26","id":"RINFO126","x":"1470","y":"658","color":"gray","message":"No data"}, //R217
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R27","id":"RINFO127","x":"1464","y":"602","color":"gray","message":"No data"}, //R218
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R28","id":"RINFO128","x":"1091","y":"915","color":"gray","message":"No data"}, //R219
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R29","id":"RINFO129","x":"355","y":"257","color":"gray","message":"No data"}, //R101
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R30","id":"RINFO130","x":"447","y":"325","color":"gray","message":"No data"}, //R102
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R31","id":"RINFO131","x":"597","y":"258","color":"gray","message":"No data"}, //R103
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R32","id":"RINFO132","x":"18","y":"402","color":"gray","message":"No data"},  //R104
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R33","id":"RINFO133","x":"147","y":"402","color":"gray","message":"No data"}, //R105
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R34","id":"RINFO134","x":"264","y":"455","color":"gray","message":"No data"}, //R106
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R35","id":"RINFO135","x":"416","y":"445","color":"gray","message":"No data"}, //R107
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R36","id":"RINFO136","x":"540","y":"455","color":"gray","message":"No data"}, //R108
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R37","id":"RINFO137","x":"122","y":"615","color":"gray","message":"No data"}, //R109
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R38","id":"RINFO138","x":"390","y":"699","color":"gray","message":"No data"}, //R110
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R39","id":"RINFO139","x":"199","y":"725","color":"gray","message":"No data"}, //R111
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R40","id":"RINFO140","x":"624","y":"659","color":"gray","message":"No data"}, //R112
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R41","id":"RINFO141","x":"648","y":"757","color":"gray","message":"No data"}, //R113
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R42","id":"RINFO142","x":"413","y":"842","color":"gray","message":"No data"}, //R114
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R43","id":"RINFO143","x":"2103","y":"140","color":"gray","message":"No data"}, //SEL751-3
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R44","id":"RINFO144","x":"1290","y":"140","color":"gray","message":"No data"}, //SEL751-2
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R45","id":"RINFO145","x":"546","y":"140","color":"gray","message":"No data"}, //SEL751-1
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R46","id":"RINFO146","x":"2420","y":"510","color":"gray","message":"No data"}, //F3_GCB
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R47","id":"RINFO147","x":"602","y":"385","color":"gray","message":"No data"}, //F1_GCB
				{"rangeColors":[{"low":-99999999999,"high":.8,"color":"orange"},{"low":.8,"high":1.1,"color":"lightgreen"},{"low":1.1,"high":99999999999,"color":"orange"}],"units":"Vpu","linkedData":"voltage","linkedField":"R48","id":"RINFO148","x":"1065","y":"325","color":"gray","message":"No data"} //battery

			],
			
			"batteries" : [
				{ "id":"BAT1","x":1025,"y":283,"width":18,"height":40,"linkedRelay":"R48"}
			],
			"solar" : [
				{ "id":"PV1","x":1300,"y":283,"width":75,"height":75,"linkedRelay":"R20"}
			],
			
			"motors" : [
				{ "id":"MOTOR1","x":2462,"y":778,"width":40,"height":40,"linkedData":"bus","linkedField":"B23"},
				{ "id":"MOTOR2","x":306,"y":846,"width":36,"height":36,"linkedData":"bus","linkedField":"B7"}
			],
			
			"generators" : [
				{ "id":"GEN1","x":625,"y":405,"width":50,"height":50,"linkedRelay":"R47"},
				{ "id":"GEN2","x":2350,"y":530,"width":50,"height":50,"linkedRelay":"R46"},
			],
			"cybers" : [
				{ "id": "CYBER1","x":188,"y":431,"width":36,"height":36, "classToBind":"relay"}
			],
			"gridPowers" : [
				{ "id": "G1","x":420,"y":90,"width":15,"height":15,"miscField":"G6" },
				{ "id": "G2","x":1160,"y":80,"width":15,"height":15,"miscField":"G6" },
				{ "id": "G3","x":1970,"y":88,"width":15,"height":15,"miscField":"G6" }
			],
			"chp" : [
				{ "id": "CHP1","label":"CHP","x":2350,"y":650,"width":18,"height":40, "max":5,"linkedField":6 },
				{ "id": "CHP2","label":"Boiler","x":2300,"y":650,"width":18,"height":40,"max":20,"linkedField":2 }

			]
		}
	},
	//need 3 pq graphs. 1 sand chart to take up the left part of the screen
	//F1, F2, F3 (Feeders)
	//
	"graphDefinitions" : {
	////////////////////////////Feeder 3
		"pq-43-46-a" : { // hack to show the hitstory and the latest
			"height" : "calc(50% - 85px)",
			"width" : "24.5%",
			"position" : "fixed",
			"top" : "calc(50%)",
			"left" : "0%",
			"title" : "Feeder 3",
			"titleFontColor" : "white",
			"backgroundColor": "transparent",
			"chartType" : "scatter",
			"markerSize" : 12,
			"markerType" : "circle",
			"markerBorderColor": "white",
			"markerBorderThickness": "white",
			"xValueType" : "number",
			"xValueFormatString" : "0.####",
			"yValueFormatString" : "0.####",
			"axisX" : {
				"title": "MW",
				"maximum": 6,
				"minimum": -6,
				//"interval": .3,
				"titleFontColor": "white",
				"labelFontColor": "white",
				 "stripLines": [ 
                                        {      
                                                "value":0,
                                                "label" : "",
                                                "color": "lightblue",
                                                "labelFontSize": 30,
                                                "labelBackgroundColor": "black"
                                        }
                                ]
	
			},
			"axisY" : {
				"title": "MVAR",
				"maximum": 6,
				"minimum": -6,
				"titleFontColor": "white",
				"includeZero": false,
				 "stripLines": [ 
	                               {      
                                                "value":0,
                                                "label" : "",
                                                "color": "lightblue",
                                                "labelFontSize": 30,
                                                "labelBackgroundColor": "black"
                                        }
		                                ]


			
			},
			"axisY2" : "",
			"customChartDefinition" :  { 
				"0": {
					"color": "blue",
					 "showInLegend": true,
				},"1": {
					"color": "crimson",
					 "showInLegend": true,
				},"2": {
					"color": "crimson",
					 "showInLegend": false,
				},
				"3": {
					 "color": "blue",
					 "showInLegend": false
				}
			},
			"maxPoints" : 1,
			"timeWindow" : "", // not relevant because xValueType is not time
			"legendPrefix" : "PQ",
			"customLegends": {
				"0" : "Utility-3",
				"1" : "CHP",
				"2" : "Utility-3_Curve",
				"3" : "CHP_Curve",
				
			},
			"defaultVisible": {
				"CHP": "1",
				"Utility-3": "1",
				"Utility-3_Curve": "0",
				"CHP_Curve": "0"
			},
			"scale" : 1000,
			"xScale" : 1000
		},
		"pq-43-46-b" : {
			"height" : "calc(50% - 85px)",
			"width" : "24.5%",
			"position" : "fixed",
			"top" : "calc(50%)",
			"left" : "0%",
			"title" : "Feeder 3",
			"titleFontColor" : "white",
			"backgroundColor": "transparent",
			"chartType" : "line",
			"markerSize" : 10,
			"lineThickness": 4,
			"markerType" : "none",
			"xValueType" : "number",
			"xValueFormatString" : "0.####",
			"yValueFormatString" : "0.####",
			"legend": {
				"horizontalAlign": "center",
				"fontSize": 14,
				"fontWeight": "bold",
				"fontFamily": "calibri",
				"fontColor": "black",
				"cursor":"pointer",
			},
			"axisX" : {
				"title": "MW",
				"maximum": 6,
				"minimum": -6,
			//	"interval": .3,
				"titleFontColor": "white",
				"labelFontColor": "white",
				 "stripLines": [ 
                                        {      
                                                "value":0,
                                                "label" : "",
                                                "color": "lightlightblue",
                                                "labelFontSize": 30,
                                                "labelBackgroundColor": "black"
                                        }
                                ]
	
			},
			"axisY" : {
				"title": "MVAR",
				"maximum": 6,
				"minimum": -6,
				"titleFontColor": "white",
				"includeZero": false,
				 "stripLines": [ 
	                               {      
                                                "value":0,
                                                "label" : "",
                                                "color": "lightlightblue",
                                                "labelFontSize": 30,
                                                "labelBackgroundColor": "black"
                                        }
		                                ]


			
			},
			"axisY2" : "",
			"customChartDefinition" :  { 
				"0": {
					"color": "blue",
					 "showInLegend": true,
				},"1": {
					"color": "crimson",
					 "showInLegend": true,
				},"2": {
					"color": "crimson",
					 "showInLegend": false,
				},
				"3": {
					 "color": "blue",
					 "showInLegend": false
				}
			},
			"maxPoints" : 150,
			"timeWindow" : "", // not relevant because xValueType is not time
			"legendPrefix" : "PQ",
			"customLegends": {
				"0" : "Utility-3",
				"1" : "CHP",
				"2" : "Utility-3_Curve",
				"3" : "CHP_Curve",
				
			},
			"defaultVisible": {
				"CHP": "1",
				"Utility-3": "1",
				"Utility-3_Curve": "1",
				"CHP_Curve": "1"
			},
			"scale" : 1000,
			"xScale" : 1000
		},
		
//////////////////FEEDER 2

		"pq-44-20-48-a" : { // hack to show the hitstory and the latest
			"height" : "calc(50% - 85px)",
			"width" : "24.5%",
			"position" : "fixed",
			"top" : "70px",
			"left" : "25%",
			"title" : "Feeder 2",
			"titleFontColor" : "white",
			"backgroundColor": "transparent",
			"chartType" : "scatter",
			"markerSize" : 12,
			"markerType" : "circle",
			"markerBorderColor": "white",
			"markerBorderThickness": "white",
			"xValueType" : "number",
			"xValueFormatString" : "0.####",
			"yValueFormatString" : "0.####",
			"axisX" : {
				"title": "MW",
				"maximum": 10,
				"minimum": -10,
				"titleFontColor": "white",
				"labelFontColor": "white",
				 "stripLines": [ 
                                        {      
                                                "value":0,
                                                "label" : "",
                                                "color": "lightblue",
                                                "labelFontSize": 30,
                                                "labelBackgroundColor": "black"
                                        }
                                ]
	
			},
			"axisY" : {
				"title": "MVAR",
				"maximum": 10,
				"minimum": -10,
				"titleFontColor": "white",
				"includeZero": false,
				 "stripLines": [ 
	                               {      
                                                "value":0,
                                                "label" : "",
                                                "color": "lightblue",
                                                "labelFontSize": 30,
                                                "labelBackgroundColor": "black"
                                        }
		                                ]


			
			},
			"axisY2" : "",
			"customChartDefinition" :  { 
				"0": {
					"color": "cornflowerblue",
					 "showInLegend": true,
				},"1": {
					"color": "yellow",
					 "showInLegend": true,
				},"2": {
					"color": "green",
					 "showInLegend": true,
				},
				"3": {
					"color": "green",
					 "showInLegend": false,
				},
				"4": {
					 "color": "cornflowerblue",
					 "showInLegend": false
				}
			},
			"maxPoints" : 1,
			"timeWindow" : "", // not relevant because xValueType is not time
			"legendPrefix" : "PQ",
			"customLegends": { //PV, ESS
				"0" : "Utility-2",
				"1" : "PV",
				"2" : "ESS",
				"3" : "Utility-2_Curve",
				"4" : "PV_ESS_Curve"
				
			},
			"defaultVisible": {
				"PV": "1",
				"ESS": "1",
				"Utility-2": "1",
				"Utility-2_Curve": "0",
				"PV_ESS_Curve": "0"
			},
			"scale" : 1000,
			"xScale" : 1000
		},
		"pq-44-20-48-b" : {
			"height" : "calc(50% - 85px)",
			"width" : "24.5%",
			"position" : "fixed",
			"top" : "70px",
			"left" : "25%",
			"title" : "Feeder 2",
			"titleFontColor" : "white",
			"backgroundColor": "transparent",
			"chartType" : "line",
			"lineThickness": 4,
			"markerSize" : 10,
			"markerType" : "none",
			"xValueType" : "number",
			"xValueFormatString" : "0.####",
			"yValueFormatString" : "0.####",
			"legend": {
				"horizontalAlign": "center",
				"fontSize": 14,
				"fontWeight": "bold",
				"fontFamily": "calibri",
				"fontColor": "black",
				"cursor":"pointer",
			},
			"axisX" : {
				"title": "MW",
				"maximum": 10,
				"minimum": -10,
				//"interval": .3,
				"titleFontColor": "white",
				"labelFontColor": "white",
				 "stripLines": [ 
                                        {      
                                                "value":0,
                                                "label" : "",
                                                "color": "lightblue",
                                                "labelFontSize": 30,
                                                "labelBackgroundColor": "black"
                                        }
                                ]
	
			},
			"axisY" : {
				"title": "MVAR",
				"maximum": 10,
				"minimum": -10,
				"titleFontColor": "white",
				"includeZero": false,
				 "stripLines": [ 
	                               {      
                                                "value":0,
                                                "label" : "",
                                                "color": "lightblue",
                                                "labelFontSize": 30,
                                                "labelBackgroundColor": "black"
                                        }
		                                ]


			
			},
			"axisY2" : "",
			"customChartDefinition" :  { 
				"0": {
					"color": "cornflowerblue",
					 "showInLegend": true,
				},"1": {
					"color": "yellow",
					 "showInLegend": true,
				},"2": {
					"color": "green",
					 "showInLegend": true,
				},
				"3": {
					"color": "green",
					 "showInLegend": false,
				},
				"4": {
					 "color": "cornflowerblue",
					 "showInLegend": false
				}
			},
			"maxPoints" : 150,
			"timeWindow" : "", // not relevant because xValueType is not time
			"legendPrefix" : "PQ",
			"customLegends": { //PV, ESS
				"0" : "Utility-2",
				"1" : "PV",
				"2" : "ESS",
				"3" : "Utility-2_Curve",
				"4" : "PV_ESS_Curve"
				
			},
			"defaultVisible": {
				"PV": "1",
				"ESS": "1",
				"Utility-2": "1",
				"Utility-2_Curve": "1",
				"PV_ESS_Curve": "1"
			},
			"scale" : 1000,
			"xScale" : 1000
		},
/////////////////////////////////////////////////////////// Feeder 1
		"pq-45-47-a" : { // hack to show the hitstory and the latest
			"height" : "calc(50% - 85px)",
			"width" : "24.5%",
			"position" : "fixed",
			"top" : "70px",
			"left" : "0px",
			"title" : "Feeder 1",
			"titleFontColor" : "white",
			"backgroundColor": "transparent",
			"chartType" : "scatter",
			"markerSize" : 12,
			"markerType" : "circle",
			"markerBorderColor": "white",
			"markerBorderThickness": "white",
			"xValueType" : "number",
			"xValueFormatString" : "0.####",
			"yValueFormatString" : "0.####",
			"axisX" : {
				"title": "MW",
				"maximum": 6,
				"minimum": -6,
				//"interval": .3,
				"titleFontColor": "white",
				"labelFontColor": "white",
				 "stripLines": [ 
                                        {      
                                                "value":0,
                                                "label" : "",
                                                "color": "lightblue",
                                                "labelFontSize": 30,
                                                "labelBackgroundColor": "black"
                                        }
                                ]
	
			},
			"axisY" : {
				"title": "MVAR",
				"maximum": 6,
				"minimum": -6,
				"titleFontColor": "white",
				"includeZero": false,
				 "stripLines": [ 
	                               {      
                                                "value":0,
                                                "label" : "",
                                                "color": "lightblue",
                                                "labelFontSize": 30,
                                                "labelBackgroundColor": "black"
                                        }
		                                ]


			
			},
			"axisY2" : "",
			"customChartDefinition" :  { 
				"0": {
					"color": "cyan",
					 "showInLegend": true,
				},"1": {
					"color": "firebrick",
					 "showInLegend": true,
				},"2": {
					"color": "firebrick",
					 "showInLegend": false,
				},
				"3": {
					 "color": "cyan",
					 "showInLegend": false
				}
			},
			"maxPoints" : 1,
			"timeWindow" : "", // not relevant because xValueType is not time
			"legendPrefix" : "PQ",
			"customLegends": {
				"0" : "Utility-1",
				"1" : "Diesel",
				"2" : "Utility-1_Curve",
				"3" : "Diesel_Curve"
				
			},
			"defaultVisible": {
				"Diesel": "1",
				"Utility-1": "1",
				"Utility-1_Curve":"0",
				"Diesel_Curve":"0"
			},
			"scale" : 1000,
			"xScale" : 1000
		},
		"pq-45-47-b" : {
			"height" : "calc(50% - 85px)",
			"width" : "24.5%",
			"position" : "fixed",
			"top" : "70px",
			"left" : "0px",
			"title" : "Feeder 1",
			"titleFontColor" : "white",
			"backgroundColor": "transparent",
			"chartType" : "line",
			"markerSize" : 10,
			"markerType" : "none",
			"xValueType" : "number",
			"lineThickness": 4,
			"xValueFormatString" : "0.####",
			"yValueFormatString" : "0.####",
			"legend": {
				"horizontalAlign": "center",
				"fontSize": 14,
				"fontWeight": "bold",
				"fontFamily": "calibri",
				"fontColor": "black",
				"cursor":"pointer"
			},
			"axisX" : {
				"title": "MW",
				"maximum": 6,
				"minimum": -6,
				"titleFontColor": "white",
				"labelFontColor": "white",
				 "stripLines": [ 
                                        {      
                                                "value":0,
                                                "label" : "",
                                                "color": "lightblue",
                                                "labelFontSize": 30,
                                                "labelBackgroundColor": "black"
                                        }
                                ]
	
			},
			"axisY" : {
				"title": "MVAR",
				"maximum": 6,
				"minimum": -6,
				"titleFontColor": "white",
				"includeZero": false,
				 "stripLines": [ 
	                               {      
                                                "value":0,
                                                "label" : "",
                                                "color": "lightblue",
                                                "labelFontSize": 30,
                                                "labelBackgroundColor": "black"
                                        }
		                        ]


			
			},
			"axisY2" : "",
			"customChartDefinition" :  { 
				"0": {
					"color": "cyan",
					 "showInLegend": true,
				},"1": {
					"color": "firebrick",
					 "showInLegend": true,
				},"2": {
					"color": "firebrick",
					 "showInLegend": false,
				},
				"3": {
					 "color": "cyan",
					 "showInLegend": false
				}
			},
			"maxPoints" : 150,
			"timeWindow" : "", // not relevant because xValueType is not time
			"legendPrefix" : "PQ",
			"customLegends": {
				"0" : "Utility-1",
				"1" : "Diesel",
				"2" : "Utility-1_Curve",
				"3" : "Diesel_Curve"
				
			},
			"defaultVisible": {
				"Diesel": "1",
				"Utility-1": "1",
				"Utility-1_Curve":"1",
				"Diesel_Curve":"1"
			},
			"scale" : 1000,
			"xScale" : 1000
		},
		
///////////////////////////VVF

		"vvf-a" : {
			//"backgroundimage":"assets/images/background.png",
			"height" : "calc(50% - 85px)",
			"width" : "24.5%",
			"position" : "fixed",
			"top" : "calc(50%)",
			"left" : "25%",
			"title" : "P1547",
			"titleFontColor" : "white",
			"backgroundColor": "transparent",
			"chartType" : "scatter",
			"markerSize" : 12,
			"markerType" : "circle",
			"markerBorderColor": "white",
			"markerBorderThickness": 2,
			"xValueType" : "number",
			"xValueFormatString" : "0.####",
			"yValueFormatString" : "0.####",
			"legend": {
				"horizontalAlign": "center",
				"fontSize": 14,
				"fontWeight": "bold",
				"fontFamily": "calibri",
				"fontColor": "white",
				"cursor":"pointer"
			},
			"axisX" : {
				"title": "Frequency",
				"maximum": 63,
				"minimum": 56,
				"interval": 1,
				"titleFontColor": "white",
				"labelFontColor": "white",
				 "stripLines":[ 
				
                    ]
	
			},
			"axisY" : {
				"title": "Voltage",
				"maximum": 1.2,
				"minimum": .5,
				"interval": .1,
				"titleFontColor": "white",
				"gridThickness":0,
				"includeZero": false,
				 "stripLines": [

						
					
		            ]
			
			},

			"axisY2" :[{
				"title": "", //green row
				"maximum": .32,
				"minimum": -.38,
				"interval":10,
				"suffix": "",  
				"titleFontColor": "white",
				"includeZero": false,
				"labelFontSize":1,
				"labelMaxWidth":0,
				"margin":0,
				"gridThickness":0,
				"tickThickness":0,
				"titleFontSize":0,
			
			},{
				"title": "", //orange row
				"maximum": .5,
				"minimum": -.2,
				"interval":1,
				"suffix": "",  
				"titleFontColor": "white",
				"includeZero": false,
				"labelFontSize":1,
				"labelMaxWidth":0,
				"gridThickness":0,
				"tickThickness":0,
				"lineThickness":0,

				"margin":0,
				"titleFontSize":0
			},{
				"title": "", //red row
				"maximum": .7,
				"minimum": 0,				

				"interval":1,
				"tickThickness":0,
				"lineThickness":0,

				"suffix": "",  
				"titleFontColor": "white",
				"includeZero": true,
				"labelFontSize":1,
				"labelMaxWidth":0,
				"margin":0,
				"gridThickness":0,
				"titleFontSize":0
			},
			{
				"title": "", //top orange row
				"maximum": .1,
				"minimum": -.6,
				"interval":1,
				"margin":0,
				"suffix": "",  
				"titleFontColor": "white",
				"includeZero": true,
				"labelFontSize":1,
				"labelMaxWidth":0,
				"gridThickness":0,				
				"tickThickness":0,
				"lineThickness":0,

				"titleFontSize":0
			}

			],
			"customChartDefinition" :  { 
				"0": {
					 "showInLegend": false,
				},
				"1": {
					 "showInLegend": false,
				},
				"2": {
					 "showInLegend": false,
				},
				"3": {
					 "showInLegend": false
				},
				"4": {
					 "showInLegend": false
				},
				"5": {
					 "showInLegend": false
				},
				"6": {
					 "showInLegend": false
				},
				"7": {
					 "showInLegend": false
				},
				"8": {
					 "showInLegend": false
				},
				"9": {
					 "showInLegend": false
				},
				"10": {
					 "showInLegend": false
				},
				"11": {
					 "showInLegend": false
				},
				"12": {
					 "showInLegend": false
				},
				"13": {
					 "showInLegend": false
				},
				"14": {
					 "showInLegend": false
				},
				"15": {
					 "showInLegend": false
				},
				"16": {
					 "showInLegend": false
				},
				"17": {
					 "showInLegend": false
				},
				"18": {
					 "showInLegend": false
				},
				"19": {
					"showInLegend": true,
					"color":"yellow"
				},
				"20": {
					 "showInLegend": false
				},
				"21": {
					 "showInLegend": false
				},
				"22": {
					 "showInLegend": false
				},
				"23": {
					 "showInLegend": false
				},
				"24": {
					 "showInLegend": false
				},
				"25": {
					 "showInLegend": false
				},
				"26": {
					 "showInLegend": false
				},
				"27": {
					 "showInLegend": false
				},
				"28": {
					 "showInLegend": false
				},
				"29": {
					 "showInLegend": false
				},
				"30": {
					 "showInLegend": false
				},
				"31": {
					 "showInLegend": false
				},
				"32": {
					 "showInLegend": false
				},
				"33": {
					 "showInLegend": false
				},
				"34": {
					 "showInLegend": false
				},
				"35": {
					 "showInLegend": false
				},
				"36": {
					 "showInLegend": false
				},
				"37": {
					 "showInLegend": false
				},
				"38": {
					 "showInLegend": false
				},
				"39": {
					 "showInLegend": false
				},
				"40": {
					 "showInLegend": false
				},
				"41": {
					 "showInLegend": false
				},
				"42": {
					 "showInLegend": true,
					"color":"blue"
				},"43": {
					 "showInLegend": true,
					"color":"cornflowerblue"
				},"44": {
					 "showInLegend": true,
					"color":"cyan"
				},"45": {
					 "showInLegend": true,
					"color":"crimson"
				},
				"46": {
					 "showInLegend": true,
					"color":"firebrick"
				},
				"47": {
					 "showInLegend": true,
					"color":"green"
				},
				"48":{
					"showInLegend": false,
					"chartType": "scatter",
					"axisYIndex" : 0,
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"color":"green",
					"markerSize":0,

				},"49":{
					"showInLegend": false,
					"chartType": "scatter",
					"axisYIndex" : 0,
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"color":"orange",
					"markerSize":0,


				},"50":{
					"showInLegend": false,
					"chartType": "scatter",
					"axisYIndex" : 0,
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"lineThickness":0,
					"markerSize":0,
					"color":"orange",
					"markerSize":0,

				},"51":{
					"showInLegend": false,
					"chartType": "scatter",
					"axisYIndex" : "1",
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"markerSize":0,
					"color":"orange",
					"markerSize":0,

				},"52":{
					"showInLegend": false,
					"chartType": "scatter",
					"axisYIndex" : 2,
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"color":"red",
					"markerSize":0,

				},"53":{
					"showInLegend": false,
					"chartType": "scatter",
					"axisYIndex" : 2,
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"color":"grey",
					"markerSize":0,

				},"54":{
					"showInLegend": false,
					"chartType": "scatter",
					"axisYIndex" : 2,
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"color":"grey",
					"markerSize":0,

				},"55":{
					"showInLegend": false,
					"chartType": "scatter",
					"axisYIndex" : 3,
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"color":"orange",
					"markerSize":0,

				}
			},
			"maxPoints" : 1,
			"timeWindow" : "", // not relevant because xValueType is not time
			"legendPrefix" : "R",
			"customLegends": {
				"0" : "R301",
				"1" : "R302",
				"2" : "R303",
				"3" : "R304",
				"4" : "R305",
				"5" : "R306",
				"6" : "R307",
				"7" : "R308",
				"8" : "R309",
				"9" : "R201",
				"10" : "R202",
				"11" : "R203",
				"12" : "R204",
				"13" : "R205",
				"14" : "R206",
				"15" : "R207",
				"16" : "R208",
				"17" : "R209",
				"18" : "R210",
				"20" : "R212",
				"21" : "R213",
				"22" : "R214",
				"23" : "R215",
				"24" : "R216",
				"25" : "R217",
				"26" : "R218",
				"27" : "R219",
				"28" : "R101",
				"29" : "R102",
				"30" : "R103",
				"31" : "R104",
				"32" : "R105",
				"33" : "R106",
				"34" : "R107",
				"35" : "R108",
				"36" : "R109",
				"37" : "R110",
				"38" : "R111",
				"39" : "R112",
				"40" : "R113",
				"41" : "R114",
				"44" : "Utility-1",
				"43" : "Utility-2",
				"42" : "Utility-3",
				"46" : "CHP",
				"45" : "Diesel",
				"47" : "ESS",
				"19" : "PV"
			},
			"defaultVisible": {
				"Utility-1": "1",	
				"Utility-2": "1",	
				"Utility-3": "1",
				"Diesel": "1",
				"PV": "1",
				"CHP": "1",
				"R49": "0",
				"R50": "0",
				"R51": "0",
				"R52": "0",
				"R53": "0",
				"R54": "0",
				"R55": "0",
				"R56": "0",
			},
			"scale" : 1,
			"xScale" : 1
		},










		"vvf-b" : {
			//"backgroundimage":"assets/images/background.png",
			"height" : "calc(50% - 85px)",
			"width" : "24.5%",
			"position" : "fixed",
			"top" : "calc(50%)",
			"left" : "25%",
			"title" : "P1547",
			"titleFontColor" : "white",
			"backgroundColor": "transparent",
			"chartType" : "line",
			"markerSize" : 10,
			"markerType" : "circle",
			//"markerBorderColor": "white",
			"markerBorderThickness": 4,
			"xValueType" : "number",
			"xValueFormatString" : "0.####",
			"yValueFormatString" : "0.####",
			"legend": {
				"horizontalAlign": "center",
				"fontSize": 14,
				"fontWeight": "",
				"fontFamily": "calibri",
				"fontColor": "black",
				"cursor":"pointer"
			},
			"axisX" : {
				"title": "Frequency",
				"maximum": 63,
				"minimum": 56,
				"interval": 1,
				"titleFontColor": "white",
				"labelFontColor": "white",
				 "stripLines":[ 
				
                    ]
	
			},
			"axisY" : {
				"title": "Voltage",
				"maximum": 1.2,
				"minimum": .5,
				"interval": .1,
				"titleFontColor": "white",
				"gridThickness":0,
				"includeZero": false,
				 "stripLines": [

						
					
		            ]
			
			},

			"axisY2" :[{
				"title": "", //green row
				"maximum": .32,
				"minimum": -.38,
				"interval":10,
				"suffix": "",  
				"titleFontColor": "white",
				"includeZero": false,
				"labelFontSize":1,
				"labelMaxWidth":0,
				"margin":0,
				"gridThickness":0,
				"tickThickness":0,
				"titleFontSize":0,
			
			},{
				"title": "", //orange row
				"maximum": .5,
				"minimum": -.2,
				"interval":1,
				"suffix": "",  
				"titleFontColor": "white",
				"includeZero": false,
				"labelFontSize":1,
				"labelMaxWidth":0,
				"gridThickness":0,
				"tickThickness":0,
				"lineThickness":0,

				"margin":0,
				"titleFontSize":0
			},{
				"title": "", //red row
				"maximum": .7,
				"minimum": 0,				

				"interval":1,
				"tickThickness":0,
				"lineThickness":0,

				"suffix": "",  
				"titleFontColor": "white",
				"includeZero": true,
				"labelFontSize":1,
				"labelMaxWidth":0,
				"margin":0,
				"gridThickness":0,
				"titleFontSize":0
			},
			{
				"title": "", //top orange row
				"maximum": .1,
				"minimum": -.6,
				"interval":1,
				"margin":0,
				"suffix": "",  
				"titleFontColor": "white",
				"includeZero": true,
				"labelFontSize":1,
				"labelMaxWidth":0,
				"gridThickness":0,				
				"tickThickness":0,
				"lineThickness":0,

				"titleFontSize":0
			}

			],
			"customChartDefinition" :  { 
				"0": {
					 "showInLegend": false,
				},
				"1": {
					 "showInLegend": false,
				},
				"2": {
					 "showInLegend": false,
				},
				"3": {
					 "showInLegend": false
				},
				"4": {
					 "showInLegend": false
				},
				"5": {
					 "showInLegend": false
				},
				"6": {
					 "showInLegend": false
				},
				"7": {
					 "showInLegend": false
				},
				"8": {
					 "showInLegend": false
				},
				"9": {
					 "showInLegend": false
				},
				"10": {
					 "showInLegend": false
				},
				"11": {
					 "showInLegend": false
				},
				"12": {
					 "showInLegend": false
				},
				"13": {
					 "showInLegend": false
				},
				"14": {
					 "showInLegend": false
				},
				"15": {
					 "showInLegend": false
				},
				"16": {
					 "showInLegend": false
				},
				"17": {
					 "showInLegend": false
				},
				"18": {
					 "showInLegend": false
				},
				"19": {
					"showInLegend": true,
					"fillOpacity":1,
					"color":"yellow"
				},
				"20": {
					 "showInLegend": false
				},
				"21": {
					 "showInLegend": false
				},
				"22": {
					 "showInLegend": false
				},
				"23": {
					 "showInLegend": false
				},
				"24": {
					 "showInLegend": false
				},
				"25": {
					 "showInLegend": false
				},
				"26": {
					 "showInLegend": false
				},
				"27": {
					 "showInLegend": false
				},
				"28": {
					 "showInLegend": false
				},
				"29": {
					 "showInLegend": false
				},
				"30": {
					 "showInLegend": false
				},
				"31": {
					 "showInLegend": false
				},
				"32": {
					 "showInLegend": false
				},
				"33": {
					 "showInLegend": false
				},
				"34": {
					 "showInLegend": false
				},
				"35": {
					 "showInLegend": false
				},
				"36": {
					 "showInLegend": false
				},
				"37": {
					 "showInLegend": false
				},
				"38": {
					 "showInLegend": false
				},
				"39": {
					 "showInLegend": false
				},
				"40": {
					 "showInLegend": false
				},
				"41": {
					 "showInLegend": false
				},
				"42": {
					 "showInLegend": true,
					  "fillOpacity":1,
					"color":"blue"
				},
				"43": {
					 "showInLegend": true,
					  "fillOpacity":1,
					"color":"cornflowerblue"
				},
				"44": {
					 "showInLegend": true,
					  "fillOpacity":1,
					"color":"cyan"
				},
				"45": {
					 "showInLegend": true,
					  "fillOpacity":1,
					"color":"crimson"
				},
				"46": {
					 "showInLegend": true,
					  "fillOpacity":1,
					"color":"firebrick"
				},
				"47": {
					 "showInLegend": true,
					  "fillOpacity":1,
					"color":"green"
				},
				"48":{
					"showInLegend": false,
					"chartType": "scatter",
					"axisYIndex" : 0,
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"color":"green",
					"markerSize":0,

				},"49":{
					"showInLegend": false,
					"chartType": "scatter",
					"axisYIndex" : 0,
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"color":"orange",
					"markerSize":0,


				},"50":{
					"showInLegend": false,
					"chartType": "scatter",
					"axisYIndex" : 0,
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"lineThickness":0,
					"markerSize":0,
					"color":"orange",
					"markerSize":0,

				},"51":{
					"showInLegend": false,
					"chartType": "scatter",
					"axisYIndex" : "1",
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"markerSize":0,
					"color":"orange",
					"markerSize":0,

				},"52":{
					"showInLegend": false,
					"chartType": "scatter",
					"axisYIndex" : 2,
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"color":"red",
					"markerSize":0,

				},"53":{
					"showInLegend": false,
					"chartType": "scatter",
					"axisYIndex" : 2,
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"color":"grey",
					"markerSize":0,

				},"54":{
					"showInLegend": false,
					"chartType": "scatter",
					"axisYIndex" : 2,
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"color":"grey",
					"markerSize":0,

				},"55":{
					"showInLegend": false,
					"chartType": "scatter",
					"axisYIndex" : 3,
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"color":"orange",
					"markerSize":0,

				}
			},
			"maxPoints" : 150,
			"timeWindow" : "", // not relevant because xValueType is not time
			"legendPrefix" : "R",
			"customLegends": {
				"0" : "R301",
				"1" : "R302",
				"2" : "R303",
				"3" : "R304",
				"4" : "R305",
				"5" : "R306",
				"6" : "R307",
				"7" : "R308",
				"8" : "R309",
				"9" : "R201",
				"10" : "R202",
				"11" : "R203",
				"12" : "R204",
				"13" : "R205",
				"14" : "R206",
				"15" : "R207",
				"16" : "R208",
				"17" : "R209",
				"18" : "R210",
				"20" : "R212",
				"21" : "R213",
				"22" : "R214",
				"23" : "R215",
				"24" : "R216",
				"25" : "R217",
				"26" : "R218",
				"27" : "R219",
				"28" : "R101",
				"29" : "R102",
				"30" : "R103",
				"31" : "R104",
				"32" : "R105",
				"33" : "R106",
				"34" : "R107",
				"35" : "R108",
				"36" : "R109",
				"37" : "R110",
				"38" : "R111",
				"39" : "R112",
				"40" : "R113",
				"41" : "R114",
				"44" : "Utility-1",
				"43" : "Utility-2",
				"42" : "Utility-3",
				"46" : "CHP",
				"45" : "Diesel",
				"47" : "ESS",
				"19" : "PV"
				
				
				
			},
			"defaultVisible": {
				"Utility-1": "1",	
				"Utility-2": "1",	
				"Utility-3": "1",
				"Diesel": "1",
				"PV": "1",
				"CHP": "1",
				"R49": "0",
				"R50": "0",
				"R51": "0",
				"R52": "0",
				"R53": "0",
				"R54": "0",
				"R55": "0",
				"R56": "0",
			},
			"scale" : 1,
			"xScale" : 1
		},








"vvf-c" : {
			//"backgroundimage":"assets/images/background.png",
			"height" : "calc(50% - 85px)",
			"width" : "24.5%",
			"position" : "fixed",
			"top" : "calc(50%)",
			"left" : "25%",
			"title" : "P1547",
			"titleFontColor" : "white",
			"backgroundColor": "transparent",
			"chartType" : "scatter",
			"markerSize" : 10,
			"markerType" : "circle",
			//"markerBorderColor": "white",
			"markerBorderThickness": 4,
			"xValueType" : "number",
			"xValueFormatString" : "0.####",
			"yValueFormatString" : "0.####",
			"legend": {
				"horizontalAlign": "center",
				"fontSize": 14,
				"fontWeight": "bold",
				"fontFamily": "calibri",
				"fontColor": "white",
				"cursor":"pointer"
			},
			"axisX" : {
				"title": "Frequency",
				"maximum": 63,
				"minimum": 56,
				"interval": 1,
				"titleFontColor": "white",
				"labelFontColor": "white",
				 "stripLines":[ 
						{      
                                "value":60,
                                "label" : "",
                                "color": "black",
                                "labelFontSize": 30,
                                "labelBackgroundColor": "black",
								"thickness":5,
								"showOnTop":true
                        }
                    ]
	
			},
			"axisY" : {
				"title": "Voltage",
				"maximum": 1.2,
				"minimum": .5,
				"interval": .1,
				"titleFontColor": "white",
				"gridThickness":0,
				"includeZero": false,
				 "stripLines": [

						
						{      
                                "value":1,
                                "label" : "",
                                "color": "black",
                                "labelFontSize": 30,
                                "labelBackgroundColor": "black",
								"thickness":5,
								"showOnTop":true
                        }
		            ]
			
			},

			"axisY2" :[{
				"title": "", //green row
				"maximum": .32,
				"minimum": -.38,
				"interval":10,
				"suffix": "",  
				"titleFontColor": "white",
				"includeZero": false,
				"labelFontSize":1,
				"labelMaxWidth":0,
				"margin":0,
				"gridThickness":0,
				"tickThickness":0,
				"titleFontSize":0,
			
			},{
				"title": "", //orange row
				"maximum": .5,
				"minimum": -.2,
				"interval":1,
				"suffix": "",  
				"titleFontColor": "white",
				"includeZero": false,
				"labelFontSize":1,
				"labelMaxWidth":0,
				"gridThickness":0,
				"tickThickness":0,
				"lineThickness":0,

				"margin":0,
				"titleFontSize":0
			},{
				"title": "", //red row
				"maximum": .7,
				"minimum": 0,				

				"interval":1,
				"tickThickness":0,
				"lineThickness":0,

				"suffix": "",  
				"titleFontColor": "white",
				"includeZero": true,
				"labelFontSize":1,
				"labelMaxWidth":0,
				"margin":0,
				"gridThickness":0,
				"titleFontSize":0
			},
			{
				"title": "", //top orange row
				"maximum": .1,
				"minimum": -.6,
				"interval":1,
				"margin":0,
				"suffix": "",  
				"titleFontColor": "white",
				"includeZero": true,
				"labelFontSize":1,
				"labelMaxWidth":0,
				"gridThickness":0,				
				"tickThickness":0,
				"lineThickness":0,

				"titleFontSize":0
			}

			],
			"customChartDefinition" :  { 
				"0": {
					 "showInLegend": false,
				},
				"1": {
					 "showInLegend": false,
				},
				"2": {
					 "showInLegend": false,
				},
				"3": {
					 "showInLegend": false
				},
				"4": {
					 "showInLegend": false
				},
				"5": {
					 "showInLegend": false
				},
				"6": {
					 "showInLegend": false
				},
				"7": {
					 "showInLegend": false
				},
				"8": {
					 "showInLegend": false
				},
				"9": {
					 "showInLegend": false
				},
				"10": {
					 "showInLegend": false
				},
				"11": {
					 "showInLegend": false
				},
				"12": {
					 "showInLegend": false
				},
				"13": {
					 "showInLegend": false
				},
				"14": {
					 "showInLegend": false
				},
				"15": {
					 "showInLegend": false
				},
				"16": {
					 "showInLegend": false
				},
				"17": {
					 "showInLegend": false
				},
				"18": {
					 "showInLegend": false
				},
				"19": {
					 "showInLegend": true
				},
				"20": {
					 "showInLegend": false
				},
				"21": {
					 "showInLegend": false
				},
				"22": {
					 "showInLegend": false
				},
				"23": {
					 "showInLegend": false
				},
				"24": {
					 "showInLegend": false
				},
				"25": {
					 "showInLegend": false
				},
				"26": {
					 "showInLegend": false
				},
				"27": {
					 "showInLegend": false
				},
				"28": {
					 "showInLegend": false
				},
				"29": {
					 "showInLegend": false
				},
				"30": {
					 "showInLegend": false
				},
				"31": {
					 "showInLegend": false
				},
				"32": {
					 "showInLegend": false
				},
				"33": {
					 "showInLegend": false
				},
				"34": {
					 "showInLegend": false
				},
				"35": {
					 "showInLegend": false
				},
				"36": {
					 "showInLegend": false
				},
				"37": {
					 "showInLegend": false
				},
				"38": {
					 "showInLegend": false
				},
				"39": {
					 "showInLegend": false
				},
				"40": {
					 "showInLegend": false
				},
				"41": {
					 "showInLegend": false
				},
				"45": {
					 "showInLegend": true
				},
				"46": {
					 "showInLegend": true
				},
				"47": {
					 "showInLegend": true
				},
				"48":{
					"showInLegend": false,
					"chartType": "stepArea",
					"axisYIndex" : 0,
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"color":"lawngreen",
					"markerSize":0,
					"fillOpacity":1


				},"49":{
					"showInLegend": false,
					"chartType": "stepArea",
					"axisYIndex" : 0,
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"color":"lightgrey",
					"markerSize":0,
					"fillOpacity":1


				},"50":{
					"showInLegend": false,
					"chartType": "stepArea",
					"axisYIndex" : 0,
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"lineThickness":0,
					"markerSize":0,
					"color":"lightgrey",
					"markerSize":0,
					"fillOpacity":1

				},"51":{
					"showInLegend": false,
					"chartType": "stepArea",
					"axisYIndex" : "1",
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"markerSize":0,
					"color":"lightgrey",
					"markerSize":0,
					"fillOpacity":1

				},"52":{
					"showInLegend": false,
					"chartType": "stepArea",
					"axisYIndex" : 2,
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"color":"darkgray", 
					"markerSize":0,
					"fillOpacity":.8

				},"53":{
					"showInLegend": false,
					"chartType": "stepArea",
					"axisYIndex" : 2,
					"axisYType" : "secondary", //gray
					"titleFontSize": 0,
					"color":"dimgray",
					"markerSize":0,
					"fillOpacity":1

				},"54":{
					"showInLegend": false,
					"chartType": "stepArea",
					"axisYIndex" : 2,
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"color":"dimgray", //gray
					"markerSize":0,
					"fillOpacity":1

				},"55":{
					"showInLegend": false,
					"chartType": "stepArea",
					"axisYIndex" : 3,
					"axisYType" : "secondary",
					"titleFontSize": 0,
					"color":"lightgrey", //orange
					"markerSize":0,
					"fillOpacity":1

				}
			},
			"maxPoints" : 2,
			"timeWindow" : "", // not relevant because xValueType is not time
			"legendPrefix" : "R",
			"customLegends": {
				"0" : "R301",
				"1" : "R302",
				"2" : "R303",
				"3" : "R304",
				"4" : "R305",
				"5" : "R306",
				"6" : "R307",
				"7" : "R308",
				"8" : "R309",
				"9" : "R201",
				"10" : "R202",
				"11" : "R203",
				"12" : "R204",
				"13" : "R205",
				"14" : "R206",
				"15" : "R207",
				"16" : "R208",
				"17" : "R209",
				"18" : "R210",
				"20" : "R212",
				"21" : "R213",
				"22" : "R214",
				"23" : "R215",
				"24" : "R216",
				"25" : "R217",
				"26" : "R218",
				"27" : "R219",
				"28" : "R101",
				"29" : "R102",
				"30" : "R103",
				"31" : "R104",
				"32" : "R105",
				"33" : "R106",
				"34" : "R107",
				"35" : "R108",
				"36" : "R109",
				"37" : "R110",
				"38" : "R111",
				"39" : "R112",
				"40" : "R113",
				"41" : "R114",
				"44" : "Utility-1",
				"43" : "Utility-2",
				"42" : "Utility-3",
				"46" : "CHP",
				"45" : "Diesel",
				"47" : "ESS",
				"19" : "PV"
			},
			"defaultVisible": {
				"Utility-1": "0",	
				"Utility-2": "0",	
				"Utility-3": "0",
				"Diesel": "0",
				"PV": "0",
				"CHP": "0",
				"R49": "1",
				"R50": "1",
				"R51": "1",
				"R52": "1",
				"R53": "1",
				"R54": "1",
				"R55": "1",
				"R56": "1",
			},
			"scale" : 1,
			"xScale" : 1
		},
////////////////VOLTAGE CUMULATIVE
		"voltagecumulative" : {
			"height" : "calc(100% - 170px)",
			"width" : "49%",
			"position" : "fixed",
			"top" : "70px",
			"left" : "50%",
			"title" : "Energy Sources",
			"titleFontColor" : "white",
			"backgroundColor": "black",
			"chartType" : "stackedArea",
		//	"markerType": "none",
			"xValueType" : "dateTime",
			"yValueFormatString" : "0.####",
			"axisX" : {
				"title": "5 Minutes",
				"titleFontColor": "white",
				"labelFontColor": "white",
				"labelFontSize":5,
				"titleFontSize":30
			},
			"axisY" : {
				"title": "MW",
				"maximum": 15,
				"minimum": 0,
				"interval": 3,
				"titleFontColor": "white",
				"includeZero": false,
				"stripLines": ""
			},
			"axisY2" : [{
				"title": "Battery SoC",
				"maximum": 100,
				"minimum": 0,
				"suffix": "%",  
				"titleFontColor": "white",
				"includeZero": true,
				"labelFontSize":20,
				"titleFontSize":15
			
			},{
				"title": "CHP MBtu/hr",
				"maximum": 10,
				"minimum": 0,
				"suffix": "",  
				"titleFontColor": "white",
				"includeZero": true,
				"labelFontSize":20,
				"titleFontSize":15
			}],
			"customChartDefinition" : {  // works same way as custom Legend. overrides chart type for some series (used for secondary axis)
				"0":{
					"color":"cyan"
				},"1":{
					"color":"cornflowerblue"
				},"2":{
					"color":"blue"
				},"3":{
					"color":"firebrick"
				},"4":{
					"color":"crimson"
				},"5":{
					"color":"green"
				},"6":{
					"color":"yellow"
				},

				"7": {
					"chartType": "line",
					"axisYIndex" : 0,
					"axisYType" : "secondary",
					"titleFontSize": 10,
					"color":"lawngreen"
				},
				"8": {
					"chartType": "line",
					"axisYType" : "secondary",
					"axisYIndex" : 1,
					"color":"red"
				}
			
			},
			"maxPoints" : 1500,
			"timeWindow" : 300, // seconds
			"legendPrefix" : "R",
			"customLegends": {
				"0" : "Utility-1",
				"1" : "Utility-2",
				"2" : "Utility-3",
				"3" : "CHP",
				"4" : "Diesel",
				"5" : "ESS",
				"6" : "PV",
				"7" : "Battery SoC",
				"8" : "CHP Thermal"
			},
			"defaultVisible": {
				"Utility-1" : 1,
				"Utility-2" : 1,
				"Utility-3" : 1,
				"Battery" : 1,
				"CHP" : 1,
				"ESS" : 1,
				"PV" : 1,
				"Diesel" : 1,
				"CHP Thermal" : 1,
				"Battery SoC" : 1			
			},
			"scale" : 1000
		}



	}


}
