<?
/*
Copyright (c) 2016 Massachusetts Institute of Technology

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

include_once ("functions.php");

# these five lines merge post and get handling so we don't have to account for each seperately
$passedInVariables['query']='none';
if (isset($_POST['query'])){
	$passedInVariables = $_POST;
}
if (isset($_GET['query'])){
	$passedInVariables = $_GET;
}

switch($passedInVariables["query"]) {
	
	case "latestprofile":
		$toReturn;
		$toReturn["profileid"]=profileToUse();
		echo json_encode($toReturn,JSON_NUMERIC_CHECK);

	
	break;
	
	case "getfrequency":
		
		$numberOfPoints = 150;
		if(isset($passedInVariables['numberofpoints'])) {
			$numberOfPoints = $passedInVariables['numberofpoints'];
		}	
		$offset = 0;
		if(isset($passedInVariables['offset'])) {
			$offset = $passedInVariables['offset'];
		}	
		$toReturn = getFrequency($numberOfPoints,$offset);
		
		echo $toReturn;
		//echo json_encode($toReturn);	
	break;
	
	//	
	case "getgraphdata":
		$toReturn = Array();
		$idArray = profileToUse();
		$id = $idArray['id'];
		$foldername = $idArray['foldername'];
		$toReturn['profileid'] = $idArray;
		$seriesParameters['numberofpoints'] = 500; # at 5Hz this is 100 seconds
		$seriesParameters['maxpointspergraph'] = 13500; # in seconds
		$seriesParameters['lastfiletime'] = 1449259871;
		$seriesParameters['lastfilesize'] = 0;
		$seriesParameters['offset'] = 1;
		$seriesParameters['haddata'] = 1;


		if(isset($passedInVariables['numberofpoints'])) {
			$seriesParameters['numberOfPoints'] = $passedInVariables['numberofpoints'];
		}
		
		# this loop simplifies adding new graphs or modifying existing ones
		# TODO: Function for graphs should check if data exists, if not call the function for that file?
		# There are three types of graphs so far:
		# 1) x is time, y is value (streaming)
		# 2) x is time, y is value (not streaming like waveform...each but works like 1)
		# 3) x is value, y is value (single point and multiple points)
		
		$alreadySeen = Array ();
		foreach ($passedInVariables as $passedInVariable => $data) {
			if (preg_match ( "/(.*)_(.*)/" , $passedInVariable,  $matches )){
				$seriesLabel = $matches[1];
				if (!isset ($alreadySeen[$seriesLabel])) { // because the prefix can be used multiple times
					$alreadySeen[$seriesLabel] = 1;
				//	echo "$seriesLabel: <br>";
					
					// these all need else's for default values
					if(isset($passedInVariables[$seriesLabel.'_offset'])) {
						$seriesParameters['offset'] = $passedInVariables[$seriesLabel.'_offset'];
					}else {
						$seriesParameters['offset'] = 1;
					}
					
					// these all need else's for default values
					if(isset($passedInVariables[$seriesLabel.'_haddata'])) {
						$seriesParameters['haddata'] = $passedInVariables[$seriesLabel.'_haddata'];
					}else {
						$seriesParameters['haddata'] = 1;
					}
					
					if(isset($passedInVariables[$seriesLabel.'_lastfiletime'])) {
						$seriesParameters['lastfiletime'] = $passedInVariables[$seriesLabel.'_lastfiletime'];
					}else{
						$seriesParameters['lastfiletime'] = 1449259871;
					}
					
					
					if(isset($passedInVariables[$seriesLabel.'_lastfilesize'])) {
						$seriesParameters['lastfilesize'] = $passedInVariables[$seriesLabel.'_lastfilesize'];
					}else {
						$seriesParameters['lastfilesize'] = 0;
					}
					
					if(isset($passedInVariables[$seriesLabel.'_maxpoints'])) {
						$seriesParameters['maxpointspergraph'] = $passedInVariables[$seriesLabel.'_maxpoints'];
					}else {
						$seriesParameters['maxpointspergraph'] = 1500; # in seconds
					}
						

					$seriesParameters['file'] = 'data/'.$id.'/'.$foldername.'/'.$seriesLabel.'.dat';
										
					if ($seriesLabel == "voltagecumulative") {
						$seriesParameters['file'] = 'data/'.$id.'/'.$foldername.'/powerreal.dat';
						$toReturn[$seriesLabel] = getTrendLines($seriesParameters);

					}
					// the pq graph label tells us which breakers for that graph in this format pq-44-44-etc where the digits are the breakers 
					elseif(preg_match('/pq-/',$seriesLabel)){
						
						if(preg_match_all('/\d+/',$seriesLabel,$matches)){
							// first time through the loop we get all
							if (!isset($toReturn["pq"])) {
								$toReturn["pq"] = getPQ();
								$toReturn['pqmatches'] = $matches;
							}
							// for this series set the right breakers
							$thirdSeries = Array();
							$seriesIndex = 0;
							foreach ($matches[0] as $matchIndex => $match) {
							//	echo "Match: $matchIndex > ".$match."\n";
								$thirdSeries[0][$matchIndex]=$toReturn["pq"][0][$match];
								$thirdSeries[0][$matchIndex]["markerType"] = "circle";
								$seriesIndex = $matchIndex;
							}
							$seriesIndex++;
							foreach ($matches[0] as $matchIndex => $match) {

								if ($match == "43") {
									$thirdSeries[0][$seriesIndex]["x"]=0;
									$thirdSeries[1][$seriesIndex]["x"]=299;
									$thirdSeries[2][$seriesIndex]["x"]=597;
									$thirdSeries[3][$seriesIndex]["x"]=894;
									$thirdSeries[4][$seriesIndex]["x"]=1189;
									$thirdSeries[5][$seriesIndex]["x"]=1481;
									$thirdSeries[6][$seriesIndex]["x"]=1770;
									$thirdSeries[7][$seriesIndex]["x"]=2055;
									$thirdSeries[8][$seriesIndex]["x"]=2335;
									$thirdSeries[9][$seriesIndex]["x"]=2610;
									$thirdSeries[10][$seriesIndex]["x"]=2879;
									$thirdSeries[11][$seriesIndex]["x"]=3142;
									$thirdSeries[12][$seriesIndex]["x"]=3239;
									$thirdSeries[13][$seriesIndex]["x"]=3327;
									$thirdSeries[14][$seriesIndex]["x"]=3407;
									$thirdSeries[15][$seriesIndex]["x"]=3477;
									$thirdSeries[16][$seriesIndex]["x"]=3538;
									$thirdSeries[17][$seriesIndex]["x"]=3590;
									$thirdSeries[18][$seriesIndex]["x"]=3632;
									$thirdSeries[19][$seriesIndex]["x"]=3664;
									$thirdSeries[20][$seriesIndex]["x"]=3687;
									$thirdSeries[21][$seriesIndex]["x"]=3700;
									$thirdSeries[22][$seriesIndex]["x"]=3703;
									$thirdSeries[23][$seriesIndex]["x"]=3696;
									$thirdSeries[24][$seriesIndex]["x"]=3679;
									$thirdSeries[25][$seriesIndex]["x"]=3652;
									$thirdSeries[26][$seriesIndex]["x"]=3616;
									$thirdSeries[27][$seriesIndex]["x"]=3570;
									$thirdSeries[28][$seriesIndex]["x"]=3509;
									$thirdSeries[29][$seriesIndex]["x"]=3211;
									$thirdSeries[30][$seriesIndex]["x"]=2907;
									$thirdSeries[31][$seriesIndex]["x"]=2597;
									$thirdSeries[32][$seriesIndex]["x"]=2283;
									$thirdSeries[33][$seriesIndex]["x"]=1965;
									$thirdSeries[34][$seriesIndex]["x"]=1643;
									$thirdSeries[35][$seriesIndex]["x"]=1318;
									$thirdSeries[36][$seriesIndex]["x"]=990;
									$thirdSeries[37][$seriesIndex]["x"]=661;
									$thirdSeries[38][$seriesIndex]["x"]=331;
									$thirdSeries[39][$seriesIndex]["x"]=0;
									$thirdSeries[0][$seriesIndex]["y"]=2796;
									$thirdSeries[1][$seriesIndex]["y"]=2789;
									$thirdSeries[2][$seriesIndex]["y"]=2768;
									$thirdSeries[3][$seriesIndex]["y"]=2733;
									$thirdSeries[4][$seriesIndex]["y"]=2683;
									$thirdSeries[5][$seriesIndex]["y"]=2620;
									$thirdSeries[6][$seriesIndex]["y"]=2543;
									$thirdSeries[7][$seriesIndex]["y"]=2452;
									$thirdSeries[8][$seriesIndex]["y"]=2349;
									$thirdSeries[9][$seriesIndex]["y"]=2231;
									$thirdSeries[10][$seriesIndex]["y"]=2101;
									$thirdSeries[11][$seriesIndex]["y"]=1959;
									$thirdSeries[12][$seriesIndex]["y"]=1794;
									$thirdSeries[13][$seriesIndex]["y"]=1625;
									$thirdSeries[14][$seriesIndex]["y"]=1451;
									$thirdSeries[15][$seriesIndex]["y"]=1273;
									$thirdSeries[16][$seriesIndex]["y"]=1092;
									$thirdSeries[17][$seriesIndex]["y"]=908;
									$thirdSeries[18][$seriesIndex]["y"]=722;
									$thirdSeries[19][$seriesIndex]["y"]=533;
									$thirdSeries[20][$seriesIndex]["y"]=344;
									$thirdSeries[21][$seriesIndex]["y"]=153;
									$thirdSeries[22][$seriesIndex]["y"]=-38;
									$thirdSeries[23][$seriesIndex]["y"]=-229;
									$thirdSeries[24][$seriesIndex]["y"]=-420;
									$thirdSeries[25][$seriesIndex]["y"]=-609;
									$thirdSeries[26][$seriesIndex]["y"]=-796;
									$thirdSeries[27][$seriesIndex]["y"]=-982;
									$thirdSeries[28][$seriesIndex]["y"]=-1163;
									$thirdSeries[29][$seriesIndex]["y"]=-1306;
									$thirdSeries[30][$seriesIndex]["y"]=-1437;
									$thirdSeries[31][$seriesIndex]["y"]=-1554;
									$thirdSeries[32][$seriesIndex]["y"]=-1658;
									$thirdSeries[33][$seriesIndex]["y"]=-1749;
									$thirdSeries[34][$seriesIndex]["y"]=-1826;
									$thirdSeries[35][$seriesIndex]["y"]=-1889;
									$thirdSeries[36][$seriesIndex]["y"]=-1938;
									$thirdSeries[37][$seriesIndex]["y"]=-1973;
									$thirdSeries[38][$seriesIndex]["y"]=-1994;
									$thirdSeries[39][$seriesIndex]["y"]=-2001;
									$seriesIndex++;

									$thirdSeries = unitCircle($seriesIndex, 4000, 150, $thirdSeries);
								}
								if ($match == "44") { //Feeder 2
									
									#$thirdSeries = feederTwoCircle($seriesIndex, 2500, 150, $thirdSeries);
									$thirdSeries = unitCircle($seriesIndex, 2500, 150, $thirdSeries);

									$seriesIndex++;

									$thirdSeries = unitCircle($seriesIndex, 9000, 150, $thirdSeries);

								}
								if ($match == "45") {
									$thirdSeries[0][$seriesIndex]["x"]=0;
									$thirdSeries[1][$seriesIndex]["x"]=341;
									$thirdSeries[2][$seriesIndex]["x"]=680;
									$thirdSeries[3][$seriesIndex]["x"]=1019;
									$thirdSeries[4][$seriesIndex]["x"]=1355;
									$thirdSeries[5][$seriesIndex]["x"]=1688;
									$thirdSeries[6][$seriesIndex]["x"]=2017;
									$thirdSeries[7][$seriesIndex]["x"]=2342;
									$thirdSeries[8][$seriesIndex]["x"]=2661;
									$thirdSeries[9][$seriesIndex]["x"]=2975;
									$thirdSeries[10][$seriesIndex]["x"]=3282;
									$thirdSeries[11][$seriesIndex]["x"]=3581;
									$thirdSeries[12][$seriesIndex]["x"]=3692;
									$thirdSeries[13][$seriesIndex]["x"]=3792;
									$thirdSeries[14][$seriesIndex]["x"]=3883;
									$thirdSeries[15][$seriesIndex]["x"]=3963;
									$thirdSeries[16][$seriesIndex]["x"]=4033;
									$thirdSeries[17][$seriesIndex]["x"]=4091;
									$thirdSeries[18][$seriesIndex]["x"]=4139;
									$thirdSeries[19][$seriesIndex]["x"]=4176;
									$thirdSeries[20][$seriesIndex]["x"]=4202;
									$thirdSeries[21][$seriesIndex]["x"]=4217;
									$thirdSeries[22][$seriesIndex]["x"]=4220;
									$thirdSeries[23][$seriesIndex]["x"]=4212;
									$thirdSeries[24][$seriesIndex]["x"]=4193;
									$thirdSeries[25][$seriesIndex]["x"]=4163;
									$thirdSeries[26][$seriesIndex]["x"]=4122;
									$thirdSeries[27][$seriesIndex]["x"]=4069;
									$thirdSeries[28][$seriesIndex]["x"]=4000;
									$thirdSeries[29][$seriesIndex]["x"]=3660;
									$thirdSeries[30][$seriesIndex]["x"]=3313;
									$thirdSeries[31][$seriesIndex]["x"]=2960;
									$thirdSeries[32][$seriesIndex]["x"]=2602;
									$thirdSeries[33][$seriesIndex]["x"]=2239;
									$thirdSeries[34][$seriesIndex]["x"]=1872;
									$thirdSeries[35][$seriesIndex]["x"]=1502;
									$thirdSeries[36][$seriesIndex]["x"]=1129;
									$thirdSeries[37][$seriesIndex]["x"]=754;
									$thirdSeries[38][$seriesIndex]["x"]=377;
									$thirdSeries[39][$seriesIndex]["x"]=00;
									$thirdSeries[0][$seriesIndex]["y"]=3186;
									$thirdSeries[1][$seriesIndex]["y"]=3178;
									$thirdSeries[2][$seriesIndex]["y"]=3154;
									$thirdSeries[3][$seriesIndex]["y"]=3114;
									$thirdSeries[4][$seriesIndex]["y"]=3057;
									$thirdSeries[5][$seriesIndex]["y"]=2985;
									$thirdSeries[6][$seriesIndex]["y"]=2898;
									$thirdSeries[7][$seriesIndex]["y"]=2795;
									$thirdSeries[8][$seriesIndex]["y"]=2676;
									$thirdSeries[9][$seriesIndex]["y"]=2543;
									$thirdSeries[10][$seriesIndex]["y"]=2395;
									$thirdSeries[11][$seriesIndex]["y"]=2233;
									$thirdSeries[12][$seriesIndex]["y"]=2045;
									$thirdSeries[13][$seriesIndex]["y"]=1852;
									$thirdSeries[14][$seriesIndex]["y"]=1654;
									$thirdSeries[15][$seriesIndex]["y"]=1451;
									$thirdSeries[16][$seriesIndex]["y"]=1245;
									$thirdSeries[17][$seriesIndex]["y"]=1035;
									$thirdSeries[18][$seriesIndex]["y"]=822;
									$thirdSeries[19][$seriesIndex]["y"]=608;
									$thirdSeries[20][$seriesIndex]["y"]=392;
									$thirdSeries[21][$seriesIndex]["y"]=174;
									$thirdSeries[22][$seriesIndex]["y"]=-44;
									$thirdSeries[23][$seriesIndex]["y"]=-261;
									$thirdSeries[24][$seriesIndex]["y"]=-478;
									$thirdSeries[25][$seriesIndex]["y"]=-694;
									$thirdSeries[26][$seriesIndex]["y"]=-908;
									$thirdSeries[27][$seriesIndex]["y"]=-1119;
									$thirdSeries[28][$seriesIndex]["y"]=-1326;
									$thirdSeries[29][$seriesIndex]["y"]=-1489;
									$thirdSeries[30][$seriesIndex]["y"]=-1637;
									$thirdSeries[31][$seriesIndex]["y"]=-1770;
									$thirdSeries[32][$seriesIndex]["y"]=-1889;
									$thirdSeries[33][$seriesIndex]["y"]=-1992;
									$thirdSeries[34][$seriesIndex]["y"]=-2079;
									$thirdSeries[35][$seriesIndex]["y"]=-2151;
									$thirdSeries[36][$seriesIndex]["y"]=-2207;
									$thirdSeries[37][$seriesIndex]["y"]=-2247;
									$thirdSeries[38][$seriesIndex]["y"]=-2271;
									$thirdSeries[39][$seriesIndex]["y"]=-2279;
									$seriesIndex++;
					
									$thirdSeries = unitCircle($seriesIndex, 4500, 150, $thirdSeries);
									
								}
							}
								$toReturn[$seriesLabel] = $thirdSeries;	
						}
					}
					elseif(preg_match('/vvf/',$seriesLabel)){
						if (!isset($toReturn["vvq"])) {
							$toReturn["vvq"] = getVVF( $seriesParameters);
						}
						$toReturn[$seriesLabel] = $toReturn["vvq"];

						//may need to return marker type circle here

					}elseif ($seriesLabel == "waveform") {
						//$seriesParameters['numberofpoints'] = 1;
						$toReturn[$seriesLabel] = getWaveform( $seriesParameters);
					}else {
						$toReturn[$seriesLabel] = getGraphs($seriesParameters);
					}
				}
			}
		}
		$toReturn['simtime'] = getSimTime();

		echo json_encode($toReturn,JSON_NUMERIC_CHECK);
	break;	
	case "getbatteries":
		$toReturn['batteries'] = getBatteries();

		echo json_encode($toReturn,JSON_NUMERIC_CHECK);
	break;
	case "systemprofileview":
	
				
		// Breakers for system profile view

		//TODO: Sysprofile view pass in which of these to run
		$toReturn['breaker'] = getBreakers();
		$id = profileToUse();
		$toReturn['profileid'] = $id;
		$toReturn['simtime'] = getSimTime();
		$toReturn['realpower'] = getRealpower();
		$toReturn['voltage'] = getVoltage();
		$toReturn['batteries'] = getBatteries();
		$toReturn['motors']= getMotors();
		$toReturn['pf']= getPowerFactor();
		$toReturn['solar']= getSolar();
		$toReturn['gridpower']= getGridPower();
		$toReturn['chp']= getCHP();

		// Write the contents back to the file
//			file_put_contents("current.json", json_encode($toReturn,JSON_NUMERIC_CHECK));
		echo json_encode($toReturn,JSON_NUMERIC_CHECK);
	
	break;
	
	
	default:
		$toReturn['post_params']=$_POST;
		$toReturn['get_params']=$_GET;
		$toReturn['ERROR']="Query value of '".$passedInVariables['query']."' is unknown";
		echoData(json_encode($toReturn), "json");
}

function echoData($data, $returnType, $filename = "default") {
	if ($returnType == "png") {
		$toReturn = $data;
		header('Content-Type: image/png');
	}
	if ($returnType == "kml"){
		$toReturn = $data;
		header('Content-type: application/vnd.google-earth.kml+xml');
		header('Content-Disposition: attachment; filename="'.$filename.'.kml"');
	}
	if ($returnType == "json"){
		$toReturn = $data;
		header("Content-type: application/json");

	}
	if ($returnType == "file" and $filename != "default"){	
		$fh = fopen($filename, 'w') or die("can't open file");
		fwrite($fh, $data);
		fclose($fh);
		$newdata['filename']=getCurrHost().$filename;
		$toReturn = json_encode($newdata);
		header("Content-type: application/json");
	}
	if ($returnType == "debug"){
		$toReturn = $data;
	}
	
	echo $toReturn;
}
?>
