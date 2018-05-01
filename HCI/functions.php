<?
/*
Copyright (c) 2016 Massachusetts Institute of Technology

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

function profileToUse(){
	# based on last modified date in data, determine which profile to use
	$file = 'data/latest.id';
	$lines = `tail -n 1 -q $file`;
	$lines = rtrim($lines); 
	if ($lines == ""){
		$lines = "0,0";		
	}
	$profileLine = explode (",", $lines);
	$toReturn['id'] = $profileLine[0];
	$toReturn['foldername'] = $profileLine[1];
	return $toReturn;
}

function getDataDir(){
	$idArray = profileToUse();
	$dataDir = "data//".$idArray["id"]."//".$idArray["foldername"]."//";
	return $dataDir;

}
function getLatestRow($filename,$label) {
	$dataDir= getDataDir();
	$file = $dataDir.$filename;
	$lines = `tail -n 1 -q $file`;
	$lines = rtrim($lines); 
	$toReturn = Array ();
	//print "$label: $file: $lines<hr>";
	$dataSeriesArray = explode (",", $lines);
	foreach ($dataSeriesArray as $seriesNumber => $seriesValue) {
		if($seriesNumber  != 0){
			$toReturn[$label.($seriesNumber)] = $seriesValue;
		}else {
			$toReturn["timestamp"] = $seriesValue; # 0th value is always timestamp
		}
	}
	return $toReturn;
}

function getSimTime(){

	//$dmstime = getLatestRow("misc_2.dat","dmstime");
	$toReturn = getLatestRow("simtime.dat","simtime");
	$toReturn['steptime1'] = getLatestRow("misc_2.dat","misc")['misc1'];
	$toReturn['servertime']=time();
	return $toReturn;
}

function getCHP(){
	$toReturn['CHP1'] = getLatestRow("ngchpGenerator_CHPHeatContribution.dat","CHP")["CHP1"];
	$toReturn['CHP2'] = getLatestRow("ngchpGenerator_boilerHeat.dat","CHP")["CHP1"];
	return $toReturn;
}


function getMotors(){
	return getLatestRow("motor.dat","MOTOR");
}

function getRealpower(){
	return getLatestRow("powerreal.dat","R");
}

function getVoltage(){
	return getLatestRow("voltage.dat","R");
}

function getBreakers(){
	return getLatestRow("breaker.dat","R");
}

function getSolar(){
	return getLatestRow("solar_kVAR.dat","PV");
}

function getGridPower(){
	return getLatestRow("misc_3.dat","G");
}

function getPowerFactor(){
	$toReturn = Array ();
	$toReturn['values'] = getLatestRow("pf_val.dat","pf");
	$toReturn['leadlag'] = getLatestRow("pf_pf_laglead.dat","pf");
	$toReturn['impexp'] = getLatestRow("pf_pf_impexp.dat","pf");
	return $toReturn;
}

#pass in which values we want and filename in the future?
function getVVF(){
	$toReturn = Array ();
	
	$volts=getLatestRow("voltage.dat","");
	$freqs=getLatestRow("frequency.dat","");
	foreach ($volts as $voltindex => $voltvalue){
		if ($voltindex != "timestamp"){
			$dataPoint["x"] =$freqs[$voltindex];
			$dataPoint["y"] =$voltvalue;
			$toReturn[0][$voltindex-1] =$dataPoint;
		}
	}

//green
		$dataPoint["x"] =58.5;
		$dataPoint["y"] =.22;
		$toReturn[0][48] =$dataPoint;
		$dataPoint["x"] =60.5;
		$dataPoint["y"] =.22;
		$toReturn[1][48] =$dataPoint;
//orange same row as green
		$dataPoint["x"] =57;
		$dataPoint["y"] =.22;
		$toReturn[0][49] =$dataPoint;
		$dataPoint["x"] =58.5;
		$dataPoint["y"] =.22;
		$toReturn[1][49] =$dataPoint;

		$dataPoint["x"] =60.5;
		$dataPoint["y"] =.22;
		$toReturn[0][50] =$dataPoint;
		$dataPoint["x"] =62;
		$dataPoint["y"] =.22;
		$toReturn[1][50] =$dataPoint;
//orange row below green		
		$dataPoint["x"] =57;
		$dataPoint["y"] =.18;
		$toReturn[0][51] =$dataPoint;
		$dataPoint["x"] =62;
		$dataPoint["y"] =.18;
		$toReturn[1][51] =$dataPoint;




//red bottom row
		$dataPoint["x"] =57;
		$dataPoint["y"] =.2;
		$toReturn[0][52] =$dataPoint;
		$dataPoint["x"] =62;
		$dataPoint["y"] =.20;
		$toReturn[1][52] =$dataPoint;		

// grey, bottom row left
		$dataPoint["x"] =56;
		$dataPoint["y"] =.7;
		$toReturn[0][53] =$dataPoint;
		$dataPoint["x"] =57;
		$dataPoint["y"] =.7;
		$toReturn[1][53] =$dataPoint;
// grey, bottom row right
		$dataPoint["x"] =62;
		$dataPoint["y"] =.7;
		$toReturn[0][54] =$dataPoint;
		$dataPoint["x"] =63;
		$dataPoint["y"] =.7;
		$toReturn[1][54] =$dataPoint;

// orange top row
		$dataPoint["x"] =57;
		$dataPoint["y"] =.1;
		$toReturn[0][55] =$dataPoint;
		$dataPoint["x"] =62;
		$dataPoint["y"] =.1;
		$toReturn[1][55] =$dataPoint;



	return $toReturn;
}

// this is profile 3 (canary specific)
function getPQ_canary(){	
	$dataDir= getDataDir();
	$file = $dataDir.'powerreal.dat';
	$file2 = $dataDir.'reactivepower.dat';

	$lines = `tail -n 1 -q $file`;
	$lines2 = `tail -n 1 -q $file2`;

	$lines = rtrim($lines); 
	$lines2 = rtrim($lines2);

	$toReturn = Array();

	if ($lines != "" and $lines2 != "") {

		$realpower = explode (",", $lines);
		$reactivepower =  explode (",", $lines2);

		$dataPoint["x"] = $realpower[1];
		$dataPoint["y"] =$reactivepower[1];
		$toReturn[0][0] =$dataPoint;

		$dataPoint["x"] = -1*($realpower[2]);
		$dataPoint["y"] =-1*($reactivepower[2]);

		$toReturn[0][1] =$dataPoint;
		
		//PL
		$dataPoint["x"] = $realpower[3] + $realpower[4];
		$dataPoint["y"] =$reactivepower[3] + $reactivepower[4];

		$toReturn[0][2] =$dataPoint;
		
		//r2-PL
		$dataPoint["x"] =abs($realpower[2]) - $toReturn[0][2]['x'];
		$dataPoint["y"] =abs($reactivepower[2]) - $toReturn[0][2]['y'];

		$toReturn[0][3] =$dataPoint;
	}
	return $toReturn;
}
function getPQ(){	
	$dataDir= getDataDir();
	$file = $dataDir.'powerreal.dat';
	$file2 = $dataDir.'reactivepower.dat';

	$lines = `tail -n 1 -q $file`;
	$lines2 = `tail -n 1 -q $file2`;

	$realpowerlines = rtrim($lines); 
	$reactivepowerlins = rtrim($lines2);
	
	$realpowerArray = explode (",", $realpowerlines);
	$reactivepowerArray = explode (",", $reactivepowerlins);
	$toReturn = Array();

	if ($realpowerlines != "" and $reactivepowerlins != "") {
		foreach ($realpowerArray as $realpowerindex => $realpowerlinesvalue) {
			if ($realpowerindex == 20) { //TODO: DELETE THIS HACK FOR RENALDO FOR SYMPOSIUM
				$realpowerArray[$realpowerindex] =-1*$realpowerArray[$realpowerindex];	
			}
			$dataPoint["x"] =$realpowerArray[$realpowerindex];
			$dataPoint["y"] =$reactivepowerArray[$realpowerindex];
			$toReturn[0][$realpowerindex] =$dataPoint;
		}
	}
	return $toReturn;
}





########################## functions for graphs
function getFileData($fileDataParams) {
	$lines = "";	

	# this has a .00000001% chance of being wrong if service is restarted in the microsecond betweent he check and the tail
	# currently there's a bug for waveforms. Because we store waveforms in seperate files but only pass back meta data for one of the files, we always get waveform

	if ($fileDataParams['exists'] == 1 and ($fileDataParams['newfiletime'] > $fileDataParams['lastfiletime'] or $fileDataParams['newfilesize'] > $fileDataParams['lastfilesize']) or $fileDataParams['haddata'] == 1) {
//	if ($fileDataParams['exists'] == 1) {
		$endLine = $fileDataParams['offset'] + $fileDataParams['numberofpoints'];
		$cmd = "sed -n ".$fileDataParams['offset'].",".$endLine."p ".$fileDataParams['file'];
		#$cmd = "tail -n +".$fileDataParams['offset']." -q ".$fileDataParams['file'];

		$lines = `$cmd`;
		$lines = rtrim($lines);

	}
	return $lines;
}

function checkFileParameters($seriesParameters) {
	$file = $seriesParameters['file'];
	$lastFileSize = $seriesParameters['lastfilesize'];
	$lastFileTime = $seriesParameters['lastfiletime'];
	$offset = $seriesParameters['offset'];


	if (file_exists($file) ) {
		$newFileTime = filemtime($file);
		#$newFileSize = filesize ($file)*.0009765625;
		$newFileSize = filesize ($file);

		
		
		# service was restarted when new file is smaller than old
		# this may not be true for waveform file but offset is always 1 for that
		if ($lastFileSize > $newFileSize) {
			$offset = 1;
		}
		
		# can't always use filesize for this because some files aren't appending but overwriting
		# if the service was just reset, second post will start getting data since first post still has file size of a bigger file
		if ($newFileSize > $lastFileSize and $newFileTime > $lastFileTime) {
			if ($offset == 0) { 
					$linecount = `wc -l < $file`;
					$linecount = rtrim($linecount);
					$offset = $linecount + 1 - $seriesParameters['maxpointspergraph'];
			}				
			if ($offset<0) {
				$offset = 1;
			}
		}
		$seriesParameters['exists'] = 1;
		$seriesParameters['offset'] = $offset;
		$seriesParameters['newfilesize'] = $newFileSize;
		$seriesParameters['newfiletime'] = $newFileTime;
	}else {
		$seriesParameters['exists'] = 0;
		$seriesParameters['offset'] = 0;
	}
	
	
	return $seriesParameters;
}




function getGraphs($seriesParameters) {
	$lines ="";
	$seriesParameters = checkFileParameters($seriesParameters);
	$lines = getFileData($seriesParameters);
	
	$toReturnArray = Array ();
	if ($lines != "") {
		$lineArray = explode ("\n", $lines);
		$timestamp = 0;
		foreach ($lineArray as $linenumber => $line) {
			if ($line != "") {
				$seriesParameters['offset']++;
				$dataSeriesArray = explode (",", $line);		
				$timestamp = $dataSeriesArray[0];
				
				foreach ($dataSeriesArray as $seriesNumber => $seriesValue) {
					if ($seriesNumber != 0) { // 0 is timestamp
						$dataPoint["x"] = $timestamp;
					#	$dataPoint["x"] = $offset;
						$dataPoint["y"] = $seriesValue;
						$toReturnArray[$linenumber][$seriesNumber-1] = $dataPoint;
					}
				}	
			}
		}
		$toReturnArray['lastfilesize'] = $seriesParameters['newfilesize'];
		$toReturnArray['lastfiletime'] = $seriesParameters['newfiletime'];
	}else {
		$toReturnArray['lastfilesize'] = $seriesParameters['lastfilesize'];
		$toReturnArray['lastfiletime'] = $seriesParameters['lastfiletime'];
	}
	
	$toReturnArray['offset'] = $seriesParameters['offset'];
	
	return $toReturnArray ;

}

function getBatteries(){
	$dataDir= getDataDir();
	$file = $dataDir.'battery_SoC.dat';
	$lines = `tail -n 1 -q $file`;
	$lines = rtrim($lines);
	$batteryArray = explode (",", $lines);
	$toReturn = Array();
	$index = 1;
	if (isset ($batteryArray)){
		unset ($batteryArray[0]);
		foreach ($batteryArray as $battery ){
			$toReturn["BAT".$index] = $battery;
			$index++;
		}
	}
	return $toReturn;
}

# NOTE THIS IS THE ONLY SERIES WHERE WE ACTUALLY SCALE IN THE PHP
# need to combine some of the duplication here with getGraphs
function getTrendLines($seriesParameters) {
	$dataDir= getDataDir();

	$seriesParameters = checkFileParameters($seriesParameters);
	$lines = getFileData($seriesParameters);
	
	$seriesParameters2 = $seriesParameters;
	$seriesParameters2['file'] = $dataDir.'battery_SoC.dat';
	
	$seriesParameters3 = $seriesParameters;
	$seriesParameters3['file'] = $dataDir.'ngchpGenerator_CHPHeatContribution.dat';
	
	//$simTime = getLatestRow("simtime.dat","simtime")["simtime1"];
	//$batteryBreaker = getLatestRow("breaker.dat","B")["B14"];

	//$seriesParameters2 = checkFileParameters($seriesParameters2);
	$lines2 = getFileData($seriesParameters2);
	$lines3 = getFileData($seriesParameters3);

	
	$toReturnArray = Array ();
	$lineArray = explode ("\n", $lines);
	$lineArray2 = explode ("\n", $lines2);
	$lineArray3 = explode ("\n", $lines3);
	if ($lines != "") {
		foreach ($lineArray as $linenumber => $line) {
			// make sure the line has data and the battery file also has data for that line
			if ($line != "" and isset ($lineArray2[$linenumber]) and isset ($lineArray3[$linenumber])) {
				$seriesParameters['offset']++;
				$dataSeriesArray = explode (",", $line);
				$dataSeriesArray2 = explode (",", $lineArray2[$linenumber]);
				$dataSeriesArray3 = explode (",", $lineArray3[$linenumber]);
				
				$trendLines = Array ();
					
				$timestamp = $dataSeriesArray[0];
				
				
				if (!isset ($dataSeriesArray[43])) {  //751-3
					$dataSeriesArray[43] = 0;					
				}if (!isset ($dataSeriesArray[44])) { //751-2
					$dataSeriesArray[44] = 0;					
				}if (!isset ($dataSeriesArray[45])) { //751-1
					$dataSeriesArray[45] = 0;					
				}if (!isset ($dataSeriesArray[46])) { //F3_GCB (CHP)
					$dataSeriesArray[46] = 0;					
				}if (!isset ($dataSeriesArray[47])) { // F1_GCB (Diesel)
					$dataSeriesArray[47] = 0;					
				}if (!isset ($dataSeriesArray[48])) { // Battery
					$dataSeriesArray[48] = 0;					
				}if (!isset ($dataSeriesArray[20])) { //Solar
					$dataSeriesArray[20] = 0;					
				}

				$trendLines[0] = $dataSeriesArray[45]; //1
				$trendLines[1] = $dataSeriesArray[44]; //2
				$trendLines[2] = $dataSeriesArray[43]; //3
				$trendLines[3] = $dataSeriesArray[46]; //CHP
				$trendLines[4] = $dataSeriesArray[47]; //Diesel
				$trendLines[5] = -1*$dataSeriesArray[48]; // battery
				$trendLines[6] = -1*$dataSeriesArray[20]; //PV
				
				$dataPoint['x'] = $timestamp;
				
				$dataPoint['y'] =(1*$trendLines[0]);
				$toReturnArray[$linenumber][0] = $dataPoint;
				
				$dataPoint['y'] =(1*$trendLines[1]);
				$toReturnArray[$linenumber][1] = $dataPoint;
				
				$dataPoint['y'] =(1*$trendLines[2]);
				$toReturnArray[$linenumber][2] = $dataPoint;
			
				$dataPoint['y'] =(1*$trendLines[3]);
				$toReturnArray[$linenumber][3] = $dataPoint;

			
				$dataPoint['y'] = (1*$trendLines[4]);
				$toReturnArray[$linenumber][4] = $dataPoint;
				
				$dataPoint['y'] =(-1*$trendLines[5]);
				$toReturnArray[$linenumber][5] = $dataPoint;
				
				$dataPoint['y'] =(1*$trendLines[6]);
				$toReturnArray[$linenumber][6] = $dataPoint;
				

				# 
				# battery is from lineArray2
				# scaling here in the php
				# TODO: right only using first battery. If more than one, need to either return all or have a way to supply it
				$dataPoint['y'] = 1000*($dataSeriesArray2[1]);
				//$dataPoint['y'] = 1000*((-1/60)*$simTime + 75);
			//	echo($dataPoint['y']."\n");
				$toReturnArray[$linenumber][7] = $dataPoint;
				$dataPoint['y'] = 1000*($dataSeriesArray3[1]);

			//	echo($dataPoint['y']."\n");
				$toReturnArray[$linenumber][8] = $dataPoint;
		
			}else {
				
			}
			
			#echo $offset."<br>";
		}
		$toReturnArray['lastfilesize'] = $seriesParameters['newfilesize'];
		$toReturnArray['lastfiletime'] = $seriesParameters['newfiletime'];
	}else {
		$toReturnArray['lastfilesize'] = $seriesParameters['lastfilesize'];
		$toReturnArray['lastfiletime'] = $seriesParameters['lastfiletime'];
	}
	$toReturnArray['offset'] = $seriesParameters['offset'];
	
	return $toReturnArray ;
}

function getWaveform( $seriesParameters){
	$toReturnArray = Array(); 
	$dataDir= getDataDir();
	$waveformDir = $dataDir."waveform";
	# detect automatically based on files
	$waveformFiles = scandir ( $waveformDir);
	
	foreach ($waveformFiles as $file) {
		if ($file !== "." and $file !=="..") {
			preg_match (  '/(\d+).dat/', $file, $matches);
			$waveformNumber = $matches[1];
			$seriesParameters['file']  = $dataDir.'waveform/'.$file;
			$seriesParameters['seriesnumber']  = $waveformNumber;
			$seriesParameters = checkFileParameters($seriesParameters);
			
			//small hack since we store these in seperate files and we only care about 0's metric
			if ($waveformNumber != 0) {
				$seriesParameters['lastfilesize'] = 0;
				$seriesParameters['lastfiletime'] = 0;
			}
			if ($seriesParameters['exists'] == 1) {
				$toReturnArray = createWaveFormArray($seriesParameters, $toReturnArray);
				
				// we only do the following for 0 because we assume that 0 is always there while others may not be
				if ($waveformNumber == 0) {
					$toReturnArray['lastfilesize'] = $seriesParameters['newfilesize'];
					$toReturnArray['lastfiletime'] = $seriesParameters['newfiletime'];
				}
			}else {
				if ($waveformNumber == 0) {
					$toReturnArray['lastfilesize'] = $seriesParameters['lastfilesize'];
					$toReturnArray['lastfiletime'] = $seriesParameters['lastfiletime'];
				}
			}
		}
	}

		return $toReturnArray;
}

function createWaveFormArray ($seriesParameters, $toReturnArray) {

	$seriesParameters['haddata'] = 0; # we never need to catch up on waveform

	$lines = getFileData($seriesParameters, $toReturnArray);
	$seriesNumber = $seriesParameters['seriesnumber'];
	
	if ($lines != ""){
		$waveFormArray = explode (",", $lines);
		$waveformCount = count($waveFormArray);

		foreach ($waveFormArray as $pointNumber => $pointValue) {
			$waveformCount--;
			$dataPoint["x"] = $waveformCount/13;
			$dataPoint["y"] = $pointValue;
			$toReturnArray[$waveformCount][$seriesNumber] = $dataPoint;
		}
	}
	return $toReturnArray;
}
function unitCircle($seriesNmber, $multiplier, $points, $thirdSeries){
	$itterator = 360/$points;
	// do this in a for loop (for 0 to 360)
	$counter = 0;
	for ($x = 0; $x <= 360; $x = $x+$itterator) {
		$thirdSeries[$counter][$seriesNmber]["x"] = $multiplier*round(cos(deg2rad($x)),5);
		$thirdSeries[$counter][$seriesNmber]["y"] = $multiplier*round(sin(deg2rad($x)),5);
		$counter++;
	}
	return $thirdSeries;
}

function feederTwoCircle($seriesNmber, $multiplier, $points, $thirdSeries){
	$itterator = 360/($points-2);
	// do this in a for loop (for 0 to 360)
	$counter = 0;
	for ($x = 0; $x <= 90; $x = $x+$itterator) {
		$thirdSeries[$counter][$seriesNmber]["x"] = $multiplier*round(cos(deg2rad($x)),5);
		$thirdSeries[$counter][$seriesNmber]["y"] = $multiplier*round(sin(deg2rad($x)),5);
		$counter++;
	}
	
	for ($x = 180; $x<=270; $x = $x+$itterator) {
		$thirdSeries[$counter][$seriesNmber]["x"] = $multiplier*round(cos(deg2rad($x)),5);
		$thirdSeries[$counter][$seriesNmber]["y"] = $multiplier*round(sin(deg2rad($x)),5);
		$counter++;
	}
		$thirdSeries[$counter][$seriesNmber]["x"] = $multiplier*round(cos(deg2rad(360)),5);
		$thirdSeries[$counter][$seriesNmber]["y"] = $multiplier*round(sin(deg2rad(360)),5);
		$counter++;
	

	return $thirdSeries;

}



?>
