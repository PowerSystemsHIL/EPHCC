<!DOCTYPE HTML>
<?
/*
Copyright (c) 2016 Massachusetts Institute of Technology

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

	//CanvasJS Version: v1.9.5.1 GA
	//jquery Version: 3.1
?>

<html>

<head>
	<script src="assets/js/jquery-3.1.0.min.js"></script>
	<script src="assets/js/jquery.canvasjs.min.js"></script>
	<script src="assets/js/js.cookie.js"></script>
	<link rel="shortcut icon" href="favicon.png"/>

		<!-- This needs to be conditional on which profile we are getting data for -->
	<script charset="utf-8" src="assets/js/CanvasJSLLHelper.js"></script>
	<script charset="utf-8" src="assets/js/common_functions.js"></script>


	<script type="text/javascript">
	
		var graphDefinitions;
		var profileId = 0;

		//get the right graph Definitions
		jQuery(document).ready(function() { 
			$.ajax({
				//beforeSend: {},
				type: 'POST',
				url: "ajax_controller.php",
				data: {query: "latestprofile"},
				success: function(data){
					$.getScript("assets/js/profiles/"+data.profileid.id+".js", function(){
					   console.log("Script loaded but not necessarily executed.");
						hilDataDefinition = JSON.parse(JSON.stringify(hilDataDefinitionLocal));
						graphDefinitions = hilDataDefinition.graphDefinitions;
						profileId = data.profileid.id;
						var profileName = hilDataDefinition.name;

						$('body').append(
							'<div id="header" width="100%">'+
							'<svg preserveAspectRatio="none" viewBox="0 0 1080 25" id="headersvg">'+
								'<text x="10" y="20" height="10" font-size="20" fill="white">'+profileName+' SYSTEM PROFILE</text>'+
								'<rect width="5" height="10" style="fill:orange;stroke-width:1;stroke:white" id="datafreshness" x="1030"/>'+
								'<text x="855" y="9" startOffset="100%" height="100%" font-family="" font-size="10" fill="white" id="foldername" >----</text>' +
								'<text x="985" y="9" startOffset="100%" height="100%" font-family="" font-size="10" fill="white" id="timer2" >00:00:00</text>' +
								'<text x="1040" y="9" startOffset="100%" height="100%" font-family="" font-size="10" fill="white" id="timer" >------</text>' +
								'<line y1="25" x1="0" y2="25" x2="100%" stroke-width="1" stroke="white"/>'+
							'</svg>'+
							'</div>'+
							'<div id="grapharea">'+
							'</div>'+
							'<div id="footer" style="width: 100%; position: fixed; bottom: 0px;">'+
								'<svg preserveAspectRatio="none" viewBox="0 0 1080 40" id="footersvg">'+
										'<image width="160" height="60"  xlink:href="assets/images/mitlogo.png"/>'+
								'</svg>'+
							'</div>'
						);
						//instantiateGraphs(graphDefinitions);
					});
				},
				dataType: "json",
				complete: function (data){	
					setTimeout(function(){instantiateGraphs(graphDefinitions)}, updateInterval);			
				}
			});
		});
		
 	</script>
</head>
<body style="background-color:black;">
		
</body>


</html>
