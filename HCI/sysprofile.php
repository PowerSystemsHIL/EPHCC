<!DOCTYPE HTML>

<?
/*
Copyright (c) 2016 Massachusetts Institute of Technology

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

//TODO: Think about adding a global state? Two "threads". One to update the global var, one to update graphics?
//TODO: in profile definitions put all of the components in their own location. Then loop on them to see if there's a components file for them.
// If it exists, "register" it with the a global array. Loop on that array to trigger instantiation, update functions.
// console.out if coponent doesn't exist
?>

<html>

<head>
	<script src="assets/js/jquery.min.js"></script>
	<script src="assets/js/jquery.canvasjs.min.js"></script>
	<script src="assets/js/js.cookie.js"></script>
	<script charset="utf-8" src="assets/js/d3.js"></script>
	<script charset="utf-8" src="assets/js/common_functions.js"></script>

	<link rel="shortcut icon" href="favicon.png"/>
	
	
	<title>System Profile View</title>
	<script type="text/javascript">

	
	var componentsLoaded = {};
	// how fast the page refreshes
	var updateInterval = 250;
	//var gauge;
	var profileId = 0;
	var hilDataDefinition;
	
	jQuery(document).ready(function() { 		
		$('body').on('click', function (e){
		//	var offset = $(this).offset();
		//	alert("x:" + (e.pageX - offset.left - 9) +"y:"+ (e.pageY - offset.top - 80));
		});
	
		// instantiate page and shapes
		$.ajax({
			//beforeSend: {},
			type: 'POST',
			url: "ajax_controller.php",
			data: {query: "latestprofile"},
			success: function(data){
				$.getScript("assets/js/profiles/"+data.profileid.id+".js", function(){
				   console.log("Script loaded but not necessarily executed.");
					hilDataDefinition = JSON.parse(JSON.stringify(hilDataDefinitionLocal));
					profileId = data.profileid.id;
					
					layoutPage();
					
					console.log(profileId);
					loadComponents();
				});
			},
			dataType: "json",
			complete: function (data){	
				setTimeout(function(){getDataAndUpdate()}, updateInterval);			
			}
		});
	});

	function getDataAndUpdate() {
		var offset = "";
		$.ajax({
			//beforeSend: {},
			type: 'POST',
			url: "ajax_controller.php",
			data: {query: "systemprofileview"},
			success: function(data){				
				// reload page if there is a profileid mismatch
				if (data["profileid"]['id'] != profileId){
					console.log("id mismatch, reload")
					location.reload();
				}
				updateTimerBar(data['simtime'],data['profileid']);
				// updates all data on the page
				//this check will soon be unneccesary as each component should check to make sure data it needs exists
				if (data.breaker!=undefined) { 
					updateStatus(data);
				}
			},
			dataType: "json",
			complete: function (data){	
				setTimeout(function(){getDataAndUpdate()}, updateInterval);			
			}
		});
	}
	//--------------------------------------------
function toDateTime(secs){
	var t = new Date(1970,0,1);
	t.setSeconds(secs);
	return t;
}

//TODO: Should we register what data items we need so that API auto gets it?
function loadComponents(){
	components = hilDataDefinition.systemProfile.components;
	//loop through each component, load library
	$.each(components, function(componentName, componentData) {
		$.getScript("assets/js/components/"+componentName.toLowerCase()+".js")
			.done(function( script, textStatus ) {
				console.log( "Loaded library for "+componentName);
				//Initialize the componenet
				componentName = componentName[0].toUpperCase() + componentName.substring(1)
				var tempCompObject = stringToFunction(componentName);
				var compInstance = new tempCompObject(componentData);
				
			//	console.log("Initializing "+componentName);
				if (typeof (compInstance.initializeComponents) === "function"){
					compInstance.initializeComponents();
					componentsLoaded[componentName] = compInstance;
				}else{
					throw new Error('Function "initializeComponenets" not defined for ' + componentName);
				}
				//console.log("Finished initializing "+componentName);
			 })		
			.fail(function( jqxhr, settings, exception ) {
				throw new Error( "Failed to load "+componentName+" "+exception);
				componentsLoaded[componentName] = 0;
			})
	});
}

//Should we attempt to reload component if it wasn't loaded initially?
//Should each object also have an array of their elements?
function updateStatus(jsonData){
	$.each(componentsLoaded, function (cIndex, component){
		//console.log("Updating: " + cIndex);
		if (typeof (component.updateComponents) === "function"){
			//TODO: Go through each componenet and validate that relevant data exists AND that there's a change in the data from the old data AND combine some of the update functions that don't need to in a sep function 
			component.updateComponents(jsonData);
		}else{
			throw new Error('Function "updateComponents" not defined for ' + cIndex);
		}
		//console.log("Finshed Updating: " + cIndex);
		
	});
	
	
}

//Aux functions from: http://stackoverflow.com/questions/1366127/instantiate-a-javascript-object-using-a-string-to-define-the-class-name
var stringToFunction = function(str) {
	var arr = str.split(".");
	
	var fn = (window || this);
	for (var i = 0, len = arr.length; i < len; i++) {
		fn = fn[arr[i]];
	}
	
	if (typeof fn !== "function") {
		throw new Error("function not found");
	}
	
	return  fn;
};

function layoutPage(){
		//system profile and header
	var profileName = hilDataDefinition.name;
	var profileImageName = "assets/images/profiles/"+hilDataDefinition["systemProfile"]["profileimage"];
		$('body').append(
			'<div id="header" width="100%">'+
			'<svg preserveAspectRatio="none" viewBox="0 0 1080 25" id="headersvg">'+
				'<text x="10" y="20" height="10" font-size="20" fill="white">'+profileName+' SYSTEM PROFILE</text>'+
				'<rect width="5" height="10" style="fill:orange;stroke-width:1;stroke:white" id="datafreshness" x="1030"/>'+
				'<text x="855" y="9" startOffset="100%" height="100%" font-family="" font-size="10" fill="white" id="foldername" >-----</text>' +
				'<text x="985" y="9" startOffset="100%" height="100%" font-family="" font-size="10" fill="white" id="timer2" >00:00:00</text>' +
				'<text x="1040" y="9" startOffset="100%" height="100%" font-family="" font-size="10" fill="white" id="timer" >------</text>' +
				'<line y1="25" x1="0" y2="25" x2="100%" stroke-width="1" stroke="white"/>'+
			'</svg>'+
			'</div>'+
			'<div id="profilediv" style="position: fixed; width:'+hilDataDefinition["systemProfile"]["width"]+'; height:'+hilDataDefinition["systemProfile"]["height"]+';">' +
				//svg needs to have width/height at 100% to properly work with the resize/viewBox/aspectRatio stuff
				'<svg preserveAspectRatio="none" viewBox="0 0 '+hilDataDefinitionLocal["systemProfile"]["svg"]["boxWidth"]+' '+hilDataDefinitionLocal["systemProfile"]["svg"]["boxHeight"]+'" width="100%" height="100%" id="profileimage">' +

					'<image width="'+hilDataDefinitionLocal["systemProfile"]["svg"]["boxWidth"]+'" height="'+hilDataDefinitionLocal["systemProfile"]["svg"]["boxHeight"]+'" xlink:href="'+profileImageName+'" />'+
				'</svg>'+
				
				
			'</div>'+
			'<div id="footer" style="width: 100%; position: fixed; bottom: 0px;">'+
			'<svg preserveAspectRatio="none" viewBox="0 0 1080 60" id="footersvg">'+
					'<image width="160" height="60"  xlink:href="assets/images/doelogo.png"/>'+
					'<text x="890" y="30" startOffset="100%" height="100%" font-family="" font-size="30" fill="white" id="timer3" >00</text>' +
			'</svg>'+
			'</div>'
		
		);
		
		// firewall view
		if (hilDataDefinitionLocal["systemProfile"]["firewall"]["show"] == "yes") {
			$('body').append('<iframe frameBorder="0" id="firewallgraph" src="https://192.168.10.1/hil_graph.php?if=wan&sort=&filter=all&hostipformat=" style="height: '+hilDataDefinitionLocal["systemProfile"]["firewall"]["height"]+'; width: '+hilDataDefinitionLocal["systemProfile"]["firewall"]["width"]+'; position: fixed; '+hilDataDefinitionLocal["systemProfile"]["firewall"]["layout"]+' scrolling="no"/>');
		}
		
		// logos
		//$('body').append('</image>');
}


	
 	</script>
</head>
<body style="background-color:black;  overflow:hidden;">
	

	

	
	

</body>


</html>
