
/*
Copyright (c) 2016 Massachusetts Institute of Technology

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

// Version 1.0-
// Helper script to make defining multiple canvasjs graphs on one page easier 

// some variables needed for page
var updateInterval = 200;
var dpsGlobal = [];
var charts = [];
	
function instantiateGraphs(graphDefinitions){
	
		// add some variables that we pass back to the server 
		$.each(graphDefinitions, function (serieslabel,seriesData) {
				graphDefinitions[serieslabel].offset = 0;
				graphDefinitions[serieslabel].lastfiletime = 0;
				graphDefinitions[serieslabel].lastfilesize = 0;
				graphDefinitions[serieslabel].haddata = 1; // haddata is used to catch up
			}
		);		
		// First load: get last 150 (30*5) data points
		// Include line number of the last datapoint
		// Subsequent ajax requests return all lines since last data point using  -n +K
		// USE visible for show 
		
		getDataAndUpdate(graphDefinitions);
	
}

function getDataAndUpdate() {
	// auto generate the query parameters so when we add new graph to graphDefinitions, we don't have to remember to add it here
	var queryData = {};
	queryData["query"] = "getgraphdata";
	$.each(graphDefinitions , function ( serieslabel )  {
		queryData[serieslabel + "_offset"]= graphDefinitions[serieslabel].offset;
		queryData[serieslabel + "_lastfiletime"]= graphDefinitions[serieslabel].lastfiletime;
		queryData[serieslabel + "_lastfilesize"]= graphDefinitions[serieslabel].lastfilesize; // this one is probably not needed
		queryData[serieslabel + "_maxpoints"]= graphDefinitions[serieslabel].maxPoints;
		queryData[serieslabel + "_haddata"]= graphDefinitions[serieslabel].haddata;
	});
	
	$.ajax({
		//beforeSend: {},
		type: 'POST',
		url: "ajax_controller.php",
		data: queryData,
		success: function(data){
			//console.log(data);
			var freshData = false;
			$.each(data, function (serieslabel,seriesData) {
				// only try to display series we've defined in settings
				if (typeof (graphDefinitions[serieslabel]) !== "undefined" ) {
					if ( data[serieslabel] != undefined && data[serieslabel][0] != undefined ) {


						// if not instantiated, instantiate the graph
						if (typeof charts[serieslabel] == 'undefined') { 
							console.log("Instantiating graph : " + serieslabel);
							var backgroundImage ='';
							if (typeof (graphDefinitions[serieslabel].backgroundimage) != "undefined"){
								backgroundImage = graphDefinitions[serieslabel].backgroundimage;
							}
							$('#grapharea').prepend('<div id="'+serieslabel+'" style="height: '+graphDefinitions[serieslabel].height+'; width: '+graphDefinitions[serieslabel].width+'; position: '+graphDefinitions[serieslabel].position+'; top: '+graphDefinitions[serieslabel].top+'; left: '+graphDefinitions[serieslabel].left+'; background-image: url(\''+backgroundImage+'\'); border-style:solid" ></div>');
							createGraph(serieslabel, seriesData);
						} 
						
						// add points to chart (and return true if points were added)
						freshData = updateChart(serieslabel, seriesData);
						
						// hack because waveform always returns data
						if (serieslabel=="waveform" || serieslabel =="powerfactor"){
							freshData = false;
						}
						
						graphDefinitions[serieslabel].haddata = 1; 

					}else {
						graphDefinitions[serieslabel].haddata = 0; 

					}
					// update with new offset value
					//console.log(serieslabel + " old " + graphDefinitions[serieslabel].offset +" new "+ data[serieslabel].offset + " delta " + ( data[serieslabel].offset - graphDefinitions[serieslabel].offset))
					
					graphDefinitions[serieslabel].offset = data[serieslabel].offset;
					graphDefinitions[serieslabel].lastfiletime = data[serieslabel].lastfiletime;
					graphDefinitions[serieslabel].lastfilesize = data[serieslabel].lastfilesize;
				}else if (serieslabel === "profileid"){
					if (data.profileid.id != profileId){
						//location.reload();
						console.log("Would have reloaded: ",data.profileid.id, profileId);
					}					
				}
				
				
			});
			updateTimerBar(data['simtime'],data['profileid']);
		},
		dataType: "json",
		complete: function (data){	
			setTimeout(function(){getDataAndUpdate()}, updateInterval);			
		}
	});


}

function formatedTimeString (time) {
	
	var hours = time.getHours();
	var minutes = time.getMinutes();
	var seconds = time.getSeconds();
	
	if (hours < 10) {
		hours = "0"+hours;
	}
	if (minutes < 10) {
		minutes = "0"+minutes;
	}
	if (seconds < 10) {
		seconds = "0"+seconds;
	}
	return (hours + ":" + minutes + ":" + seconds);
	
}

function toDateTime(secs){
	var t = new Date(1970,0,1);
	t.setSeconds(secs);
	return t;
}

function createGraph(element, dataSeries)  {
	dataDefinitions = graphDefinitions[element];

	var numberOfSeries = Object.keys(dataSeries[0]).length;
	var dps = [];
	chartdata = [];
	for (i = 0; i<numberOfSeries; i++) {
		dps[i]=[];
		// this handles the case when we refresh the page by remembering our previous legend selection
		// unselects the series and hides them from legend
		var visible = true;
		var toolTipContent = undefined;
		var legendName = dataDefinitions.legendPrefix + (i+1);
		var axisYType = "primary";
		var axisYIndex = 0;
		var lineThickness = 0;
		if (typeof(dataDefinitions.lineThickness) !=="undefiend"){
			lineThickness = dataDefinitions.lineThickness;
		}
		var chartType = dataDefinitions.chartType;
		var markerBorderColor = dataDefinitions.markerBorderColor;
		var markerBorderThickness = dataDefinitions.markerBorderThickness;
		var markerSize = dataDefinitions.markerSize;
		var color = "";
		var fillOpacity = .7;
		var showInLegend = true;
		// set overrides for default Y axis type and chart type values based on the data definitions
		if ( dataDefinitions.customChartDefinition != 'undefined' && typeof dataDefinitions.customChartDefinition[i] != 'undefined' && typeof dataDefinitions.customChartDefinition[i].axisYType != 'undefined'  ) {
			axisYType = dataDefinitions.customChartDefinition[i].axisYType;
		}
		if ( dataDefinitions.customChartDefinition != 'undefined' && typeof dataDefinitions.customChartDefinition[i] != 'undefined' && typeof dataDefinitions.customChartDefinition[i].fillOpacity != 'undefined'  ) {
			fillOpacity = dataDefinitions.customChartDefinition[i].fillOpacity;
		}
		if (typeof dataDefinitions.customChartDefinition != 'undefined' && typeof dataDefinitions.customChartDefinition[i] != 'undefined' && typeof dataDefinitions.customChartDefinition[i].axisYIndex != 'undefined'  ) {
			axisYIndex = dataDefinitions.customChartDefinition[i].axisYIndex;
		}
		if (typeof dataDefinitions.customChartDefinition != 'undefined' && typeof dataDefinitions.customChartDefinition[i] != 'undefined' && typeof dataDefinitions.customChartDefinition[i].chartType != 'undefined'  ) {
			chartType = dataDefinitions.customChartDefinition[i].chartType;

		}

		// set overrides for legend values
		if ( typeof dataDefinitions.customLegends != 'undefined' && typeof dataDefinitions.customLegends[i] != 'undefined' ) {
			legendName = dataDefinitions.customLegends[i];
		}
		if ( typeof dataDefinitions.customChartDefinition != 'undefined' && typeof dataDefinitions.customChartDefinition[i] != 'undefined' && typeof dataDefinitions.customChartDefinition[i].markerBorderThickness != 'undefined' ) {
			markerBorderThickness = dataDefinitions.customChartDefinition[i].markerBorderThickness;
		}
		if ( typeof dataDefinitions.customChartDefinition != 'undefined' && typeof dataDefinitions.customChartDefinition[i] != 'undefined' && typeof dataDefinitions.customChartDefinition[i].markerBorderColor != 'undefined' ) {
			markerBorderColor = dataDefinitions.customChartDefinition[i].markerBorderColor;
		}
		if ( typeof dataDefinitions.customChartDefinition != 'undefined' && typeof dataDefinitions.customChartDefinition[i] != 'undefined' && typeof dataDefinitions.customChartDefinition[i].color != 'undefined' ) {
			color = dataDefinitions.customChartDefinition[i].color;
		}
		if ( typeof dataDefinitions.customChartDefinition != 'undefined' && typeof dataDefinitions.customChartDefinition[i] != 'undefined' && typeof dataDefinitions.customChartDefinition[i].showInLegend != 'undefined' ) {
			showInLegend = dataDefinitions.customChartDefinition[i].showInLegend;
		}
		if ( typeof dataDefinitions.customChartDefinition != 'undefined' && typeof dataDefinitions.customChartDefinition[i] != 'undefined' && typeof dataDefinitions.customChartDefinition[i].markerSize != 'undefined' ) {
			markerSize = dataDefinitions.customChartDefinition[i].markerSize;
		}

		if ( typeof dataDefinitions.customChartDefinition != 'undefined' && typeof dataDefinitions.customChartDefinition[i] != 'undefined' && typeof dataDefinitions.customChartDefinition[i].lineThickness != 'undefined' ) {
			lineThickness = dataDefinitions.customChartDefinition[i].lineThickness;
		}
		// checks to see if we should hide the series based on previous interaction with page that gets stored in the cookie
		// or based on the config
		// If in the config to show or not disabled by click in previous interaction, show
		// If not in the config to show and not enabled by previous interaction don't show
		// When clicking on an item to hide it on the page you are setting the hide cookie to true. When clicking to show, you are setting hide cookie to false
		// If not cookie exists, do default action from settings
		
		var cookieToCheck = element+"."+legendName;


		if ((typeof dataDefinitions.defaultVisible[legendName] == "undefined" || dataDefinitions.defaultVisible[legendName] == 0)&& Cookies.get(cookieToCheck) != "false") {
			visible = false;
			toolTipContent = null;
		}
		
        if (Cookies.get(cookieToCheck) != undefined && Cookies.get(cookieToCheck) != "false"){
        	visible = false;
         	toolTipContent = null;
        }

		// TODO: Need to validate here to make sure all the settings are defined correctly in the settings file
		if (typeof dataDefinitions.markerType == "undefined"){
			dataDefinitions.markerType  = "circle";
		}
		if (typeof dataDefinitions.markerBorderColor == "undefined"){
			dataDefinitions.markerBorderColor  = "transparent";
		}
		chartdata[i] = {	
			type: chartType,
			//xValueType: "number",
			markerSize: markerSize,
			xValueType: dataDefinitions.xValueType,
			xValueFormatString: dataDefinitions.xValueFormatString,
			yValueFormatString: dataDefinitions.yValueFormatString,
			showInLegend: showInLegend,
			//showInLegend: dataDefinitions.data[i].showInLegend,
	
			name: legendName,
			//legendMarkerType: "none",
			markerType: dataDefinitions.markerType,
			markerBorderColor: markerBorderColor,
			markerBorderThickness: markerBorderThickness,
			lineThickness: lineThickness,

		//	markerBorderColor: "white",
		//	markerBorderThickness: 4,

			markerBorderWidth: "10px",
			dataPoints: dps[i],
			visible: visible,
			toolTipContent: toolTipContent,
			axisYType: axisYType,
			fillOpacity: fillOpacity,
			axisYIndex: axisYIndex
		}
		if (color !=  "") { // if the color attribute is not there, it uses auto
			chartdata[i].color = color;
		}
	}	
	
	// move alot of these into data definitions above
	
	if (typeof dataDefinitions.legend == "undefined"){
			dataDefinitions.legend = 
			{
				//verticalAlign: "botom",
				horizontalAlign: "center",
				fontSize: 14,
				fontWeight: "bold",
				fontFamily: "calibri",
				fontColor: "white",
				cursor:"pointer"
				
			}
	}
	
	// hide/unhide on legend click of data series
	dataDefinitions.legend.itemclick =
			function(e) { 
				if (typeof(e.dataSeries.visible) === "undefined" || e.dataSeries.visible) {
					hideDataSeries(e.chart._containerId, e);
				}
				else {
					showDataSeries(e.chart._containerId, e);
				}
				charts[e.chart._containerId].render();
			};
	
	
	
	var chart = new CanvasJS.Chart(element,{
		title: {
			text: dataDefinitions.title,
			fontColor: dataDefinitions.titleFontColor

		},
		toolTip: {
			//content:"x: {x}, y: {y}", // can we check for if visible here?
			shared: true,
		},
		axisX: dataDefinitions.axisX,
		axisY: dataDefinitions.axisY, 
		axisY2: dataDefinitions.axisY2,
		axisX2: dataDefinitions.axisX2,
		backgroundColor: dataDefinitions.backgroundColor,
		data: chartdata,
		exportEnabled: false,
		zoomEnabled: false,
		legend: dataDefinitions.legend
	});
	
	// this should be reencoded into dataDefinitions.
	charts[element] = chart;
	dpsGlobal[element] = dps;
}

// Functions to hide/unhide data series when we click on the series in a legend of a given graph
function hideDataSeries(element, e) {
	e.dataSeries.visible = false;
	e.dataSeries.toolTipContent = null; //delete from tool tip
	// add cookie so next refresh it could be hidden
	Cookies.set(element+"."+e.dataSeries.name, true);
}
function showDataSeries(element, e) {
	e.dataSeries.visible = true;
	e.dataSeries.toolTipContent = undefined;
	// remove from cookie so we can show it later
	//	Cookies.remove(element+"."+e.dataSeries.name); 
	Cookies.set(element+"."+e.dataSeries.name, false);
}


// Add new data points to a given chart (dataSeries continues the new data points)
function updateChart(element, dataSeries) {
	if (dataSeries != undefined && dataSeries[0] != undefined) {
	
		var numberOfPoints = Object.keys(dataSeries).length; // number of points returned in this query
		var numberOfSeries = Object.keys(dataSeries[0]).length; // number of series returned in this query
		var yScale  = graphDefinitions[element].scale;
		var xScale = 1;
		if (graphDefinitions[element].xScale!=undefined){
			xScale = graphDefinitions[element].xScale;
		}	
		var maxDataPoints  = graphDefinitions[element].maxPoints; // max number of points to draw before deleting old ones from the graph
		
		
		for (datarow = 0; datarow<numberOfPoints; datarow++){
			for (dseries = 0; dseries<numberOfSeries; dseries++) {
				if (dataSeries[datarow]!= undefined && dataSeries[datarow][dseries] != undefined) {
					// scale the data if it needs scaling
					dataSeries[datarow][dseries].y = dataSeries[datarow][dseries].y / yScale;									      
					dataSeries[datarow][dseries].x = dataSeries[datarow][dseries].x / xScale; 	
					// push the data into the appropriate data series
					dpsGlobal[element][dseries].push(dataSeries[datarow][dseries]);
					
					// Override maxPoints if there's a maxPoints set in custom data
					var maxDataPointsLocal = maxDataPoints;
					if (graphDefinitions[element].customChartDefinition != undefined && graphDefinitions[element].customChartDefinition[dseries] != undefined && graphDefinitions[element].customChartDefinition[dseries].maxPoints != undefined){
						maxDataPointsLocal = graphDefinitions[element].customChartDefinition[dseries].maxPoints;
					}
					if (dpsGlobal[element][dseries].length > maxDataPointsLocal) {
						dpsGlobal[element][dseries].shift();
					}
				}
			}
		}
		
		
		
		// if it's a timeseries graph fix the viewport to the correct range
		if (graphDefinitions[element].xValueType == "dateTime") {
			viewPortMax = charts[element].options.data[0].dataPoints[ charts[element].options.data[0].dataPoints.length - 1].x;
			viewPortMin = viewPortMax - (graphDefinitions[element].timeWindow*1000);
			charts[element].options.axisX.viewportMaximum = viewPortMax;
			charts[element].options.axisX.viewportMinimum = viewPortMin;
		//	console.log("Setting viewport. Min:" + viewPortMin + " Timewindow:" + (graphDefinitions[element].timeWindow*1000) + " Max:" + viewPortMax);
		}
		charts[element].render();
		return true;
	}
	return false;

}   
