#!/usr/bin/perl
#Copyright (c) 2016 Massachusetts Institute of Technology
#
#Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
#
#The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
#
#THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


# TODO: Write out header + packet into one file for easier replay (maybe just print unpacked string to file?
sub dataDirCleanup(){
	my ($datadir, $createsubs) =@_;
#	print "Clearing old data\n";
#	`rm -rf $datadir`;

	print "Creating data dir\n";
	`mkdir $datadir`;
	
	if ($createsubs == 1) {
		my @dirnames = ("waveform");
		#my @dirnames = ("waveform","powerreal","reactivepower","voltage","frequency","breakerstatus","battery","pf","fuel");
		foreach my $dirname (@dirnames) {
			if (! -d "$datadir/$dirname"){
					print "Creating $dirname directory\n";
					`mkdir $datadir/$dirname`
			}
		}
	}
	# when you start the perl script it should delete the data in the data dirs.
	#flush
	$| = 1; 
}

sub decodePacket() {
	my ($timestamp, $datadir, $folderTimeStamp, $receivedpacket) = @_;
	
	#Every field is now a int16 (s) except for start byte
	my $unpackString = "i*"; # s is signed, S is unsigned (short - int16) (I - int32)
	my (@unpacked) = unpack($unpackString,$receivedpacket);
	
	# unpack Header into a hash 	
	my %headerInfoHash = {};
	(
		$headerInfoHash{startByte},	
		$headerInfoHash{profileId}, 
		$headerInfoHash{simtime}, 
		$headerInfoHash{numberOfWaveforms},
		$headerInfoHash{numberOfPointsInWaveform},
		$headerInfoHash{scaleOfWaveform},
		$headerInfoHash{relays}{number},
		$headerInfoHash{relays}{powerreal}{scale},
		$headerInfoHash{relays}{reactivepower}{scale},
		$headerInfoHash{relays}{voltage}{scale},
		$headerInfoHash{relays}{frequency}{scale},
		$headerInfoHash{devices}{battery}{number},
		$headerInfoHash{devices}{battery}{SoC}{scale},
		$headerInfoHash{devices}{battery}{VRMSLL}{scale},
		$headerInfoHash{devices}{battery}{Frequency}{scale},
		$headerInfoHash{devices}{battery}{kW}{scale},
		$headerInfoHash{devices}{battery}{kVAR}{scale},
		$headerInfoHash{devices}{dieselGenerator}{number},
		$headerInfoHash{devices}{dieselGenerator}{voltage}{scale},
		$headerInfoHash{devices}{dieselGenerator}{fuelConsumption}{scale},
		$headerInfoHash{devices}{ngchpGenerator}{number},
		$headerInfoHash{devices}{ngchpGenerator}{voltage}{scale},
		$headerInfoHash{devices}{ngchpGenerator}{tempActual}{scale},
		$headerInfoHash{devices}{ngchpGenerator}{heatRecovered}{scale},
		$headerInfoHash{devices}{ngchpGenerator}{fuelUsage}{scale},
		$headerInfoHash{devices}{ngchpGenerator}{ChpC02}{scale},
		$headerInfoHash{devices}{ngchpGenerator}{boilerHeat}{scale},
		$headerInfoHash{devices}{ngchpGenerator}{CHPHeatContribution}{scale},
		$headerInfoHash{devices}{ngchpGenerator}{boilerNM}{scale},
		$headerInfoHash{devices}{ngchpGenerator}{boilerLbm}{scale},
		$headerInfoHash{devices}{motor}{number},
		$headerInfoHash{devices}{solar}{number},
		$headerInfoHash{devices}{solar}{VRMSLL}{scale},
		$headerInfoHash{devices}{solar}{kW}{scale},
		$headerInfoHash{devices}{solar}{kVAR}{scale},
		$headerInfoHash{devices}{pf}{number},
		$headerInfoHash{devices}{pf}{scale},
		$headerInfoHash{numberOfMiscDataScales}	
	) = unpack($unpackString,$receivedpacket);
	
	
	#$headerInfoHash{numberOfWaveforms} = 3;

	
	#$headerInfoHash{numberOfWaveforms} =3;
	#$headerInfoHash{numberOfPointsInWaveform}=166;

	# -3 because it counts devices and scales as an extra key and first entry is at 0 not at 1
	my $head1 =  (scalar keys %headerInfoHash) - 1;
	my $head2 =  (scalar keys %{$headerInfoHash{devices}});
	my $head3 =  (scalar keys %{$headerInfoHash{relays}}) - 1; # -1 to not count {number}
	my $head4 =  (scalar keys %{$headerInfoHash{devices}{ngchpGenerator}}) - 1;
	my $head5 =  (scalar keys %{$headerInfoHash{devices}{dieselGenerator}}) - 1;
	#my $head6 =  (scalar keys %{$headerInfoHash{devices}{pf}}) - 1;
	my $head7 =  (scalar keys %{$headerInfoHash{devices}{battery}}) - 1;
	my $head8 =  (scalar keys %{$headerInfoHash{devices}{solar}}) - 1;

#	print $head1.",".$head2.",".$head3.",".$head4.",".$head5."\n";
	my $currPacketLocation = $head1 + $head2 + $head3 + $head4+ $head5 +$head7 + $head8;
	
	
	my %orderHash = ();
	
	# since arrays are looped in order, this is here to help loop later on
	$orderHash{relays} = ["powerreal", "reactivepower", "voltage", "frequency"];
	$orderHash{devices} = ["battery", "dieselGenerator", "ngchpGenerator", "motor", "solar", "pf"];
	$orderHash{dieselGenerator} = ["voltage", "fuelConsumption"];
	$orderHash{ngchpGenerator} = ["voltage", "tempActual", "heatRecovered", "fuelUsage", "ChpC02", "boilerHeat", "CHPHeatContribution", "boilerNM", "boilerLbm"];
	$orderHash{pf} = ["val","pf_impexp","pf_laglead"];
	$orderHash{battery} = ["SoC","VRMSLL","Frequency","kW","kVAR"];
	$orderHash{solar} = ["VRMSLL","kW","kVAR"];

	
	
################################### Sub Header
	#my $currPacketLocation = (scalar keys %headerInfoHash)+(scalar keys %{$headerInfoHash{devices}})+(scalar keys %{$headerInfoHash{scales}})-1 ;
	# extract the miscDataSubHeader information [number of elements, scale]
	
	my $subHeaderCounter =0;
	if ($headerInfoHash{numberOfMiscDataScales} == 0) {
		$headerInfoHash{numberOfMiscDataScales} =1;
	}
	for (my $i=0; $i < $headerInfoHash{numberOfMiscDataScales}; $i++){
#		print "Sub Header: $currPacketLocation\n";
		$headerInfoHash{"miscDataSubHeader"}{$i} = [$unpacked[$currPacketLocation],$unpacked[$currPacketLocation+1]];
		$currPacketLocation = $currPacketLocation+2;
		$subHeaderCounter += $headerInfoHash{"miscDataSubHeader"}{$i}[0];
	}

#print Dumper(\%headerInfoHash);

	# location in unpacked array of first non-header data
	my $nonHeaderLocation = $currPacketLocation;

################################### Data Dir creation



	# tell php what the latest id is
	&printToFile (">".$datadir."/latest.id",$headerInfoHash{profileId}.",$folderTimeStamp\n");

	#check if dir for ID exists
	$datadir = $datadir.$headerInfoHash{profileId};
	if (!-d $datadir) {
		print "**************Data dir for $headerInfoHash{profileId} does not exist\n";
		`mkdir $datadir`;
		print "********Datadir created\n";
	}

	$datadir = $datadir.'/'.$folderTimeStamp.'/';
	if (!-d $datadir) {
		print "**************Data dir $datadir does not exist for this time stamp.\n";
		&dataDirCleanup($datadir, 1);
	}


	# print out latest simtime
	&printToFile (">".$datadir."simtime.dat", $timestamp.",".$headerInfoHash{simtime}."\n");
################################### Waveform	
	# for each waveform, print a new file.
	for (my $waveform = 0; $waveform < $headerInfoHash{numberOfWaveforms}; $waveform++) {
		my $start = $nonHeaderLocation + ($headerInfoHash{numberOfPointsInWaveform})* ( $waveform );
		#my $start = $currPacketLocation;
		my $stop = $start + $headerInfoHash{numberOfPointsInWaveform} - 1;
		$currPacketLocation = $stop;
		my $waveformStringOutput; 	
		my @waveform = @unpacked[$start..$stop];
		# Loop instead of join to apply scale
		foreach my $waveformValue (@waveform) {
			my $wscale = $headerInfoHash{scaleOfWaveform};
			if ($wscale == 0) {$wscale =1;}
			my $scaledWaveformValue = $waveformValue/$wscale;
			if ($waveformStringOutput eq "") {
				$waveformStringOutput.=	$scaledWaveformValue;

			}else{
				$waveformStringOutput.=",".$scaledWaveformValue;
			}
		}
		&printToFile (">$datadir/waveform/waveform".$waveform .".dat",$waveformStringOutput."\n");
	}
	$currPacketLocation ++;
	
################################### Relay Specific
	# Relay devices. We need to first order them so that we loop through the correct order in the packet
	if ($headerInfoHash{relays}{number} == 0) {
		$headerInfoHash{relays}{number} = 1;
	}
	my $numberOfRelays = $headerInfoHash{relays}{number};
	
	foreach my $relayLabel ( @{$orderHash{relays}}) {
#		print $relayLabel." - ".$headerInfoHash{relays}{$relayLabel}{scale}."\n";
		$currPacketLocation = &printRealayDependantData($timestamp, $headerInfoHash{relays}{$relayLabel}{scale}, $currPacketLocation, $numberOfRelays, $relayLabel, $datadir, \@unpacked);
	}

################################### Breakers
	$currPacketLocation = &printRealayDependantData($timestamp, 1, $currPacketLocation, $numberOfRelays, "breaker", $datadir, \@unpacked);

 
	
###################################	 Devices
	# loop through each device
	foreach my $device (@{$orderHash{devices}}) {
		# In the header, 0 means 1 with no valid values
		if ($headerInfoHash{devices}{$device}{number} == 0) {
			$headerInfoHash{devices}{$device}{number} =1;
		}
		
		# check to see if there's a sub device for this item to loop through
		if (defined $orderHash{$device}){
			foreach my $subDevice (@{$orderHash{$device}}){
				my $subScale = $headerInfoHash{devices}{$device}{$subDevice}{scale};
				if (!defined ($subScale)) {
					$subScale = $headerInfoHash{devices}{$device}{scale};
				}
				$currPacketLocation = &printRealayDependantData($timestamp, $subScale,$currPacketLocation, $headerInfoHash{devices}{$device}{number}, $device."_".$subDevice,$datadir,\@unpacked);	
			}
				
		}else {
			my $scale = $headerInfoHash{devices}{$device}{scale};
			$currPacketLocation = &printRealayDependantData($timestamp, $scale,$currPacketLocation, $headerInfoHash{devices}{$device}{number}, $device,$datadir,\@unpacked);	
		}
	}

#################################### misc data here.
	# for the number of misc scales
	#	for the number of items in each misc scale
	for (my $i=0; $i<$headerInfoHash{numberOfMiscDataScales}; $i++) {
		my $numberOfMiscs = $headerInfoHash{"miscDataSubHeader"}{$i}[0];
		my $miscScale = $headerInfoHash{"miscDataSubHeader"}{$i}[1];
		if ($numberOfMiscs == 0) {
			$numberOfMiscs = 1;
		}
		if ($miscScale == 0 ) {
			$miscScale = 1;
		}
	#	print "Misc ".($i+1)." numberOfMisc: $numberOfMiscs miscScale: $miscScale currPacketLocation: $currPacketLocation\n";
		$currPacketLocation = &printRealayDependantData($timestamp, $miscScale,$currPacketLocation, $numberOfMiscs, "misc_".($i+1),$datadir,\@unpacked);

	
	}
	
	##### End of packet stuff
	my $stopbyte = $unpacked[$currPacketLocation];
	$currPacketLocation++;
	my $checksum = $unpacked[$currPacketLocation];
	
	if ($stopbyte != 21845 ){
		print "!!!!----->Stop byte mismatch. Expecting 21845. Received: $stopbyte\n";
	}
}

# returns next location in packet
sub printRealayDependantData() {
	my ($timestamp, $scale, $currPacketLocation, $numberOfRelays, $label, $datadir, $unpackedArrayRef) =@_;
	my $newStop = $currPacketLocation + $numberOfRelays - 1;
	# we itterrate newstop in the return so that we can have the correct handling of only 1 relay
#	print "$label Start: location: $currPacketLocation, scale: $scale numberOfValues: $numberOfRelays, $newStop\n";
	my @sliceArray = @{$unpackedArrayRef}[$currPacketLocation..$newStop];
	my $fileToWrite = ">>$datadir".'/'.$label.".dat";
	my $sliceOutputString = "";
	$sliceOutputString = $timestamp;
	foreach my $oneSlice (@sliceArray) {
		if ($label eq "breaker"){ # hack for breakers b/c wrong data is being sent
			if ($oneSlice == 3 or $oneSlice == 1) {
				$oneSlice = 1;
			}else {
				$oneSlice = 0;
			}
		}

		if ($scale == 0) {$scale=1;}
		$sliceOutputString.=",".($oneSlice/$scale);
	}
#	print "\n";
#	print "\t$sliceOutputString\n";
	&printToFile ($fileToWrite,$sliceOutputString."\n");

	return ($newStop+1);
}



sub openUnicastListenSocket(){
    my ($port) = @_;
	my $MySocket = new IO::Socket::INET->new (LocalPort=>$port, Proto=>'udp', ReuseAddr=>1) || die "Failed to open unicast socket for listening. Error: $!\n";
	return $MySocket;

}	
sub printToFile () {
	my ($filename,$data) = @_;
#	print $filename, $data;
	open( OUTPUT , $filename )  || die("Could not writeoutfile with name:$filename $!.");
	OUTPUT->flush();
	print OUTPUT $data;
	close (OUTPUT);
}

sub dec2bin {
    my $str = unpack("B32", pack("N", shift));
    $str =~ s/^0+(?=\d)//;   # otherwise you'll get leading zeros
    return $str;
}
sub bin2dec {
    return unpack("N", pack("B32", substr("0" x 32 . shift, -32)));
}
1;
