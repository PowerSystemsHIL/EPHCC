
#Copyright (c) 2016 Massachusetts Institute of Technology
#
#Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
#
#The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
#
#THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

use strict;
use warnings;

use Data::Dumper;
#use Data::Printer;
use IO::Socket;

use Time::HiRes qw(usleep);

use JSON;

my $datadir = '../data/';
my $folder = '02-16-2017-22-01-49';
my $profileid = 2;
my $simtimestart = 0;

my $numberOfWaveforms = 3;
my $numberOfPointsInWaveform = 1;

	
my $unicastOutSocket = &openUnicastSendSocket("127.0.0.1","7200","127.0.0.1");


		
	my %orderHash = ();
	
	$orderHash{relays} = [ "powerreal", "reactivepower", "voltage", "frequency","breaker"];
	$orderHash{devices} = ["battery", "dieselGenerator", "ngchpGenerator", "motor", "solar", "pf"];
	$orderHash{dieselGenerator} = ["voltage", "fuelConsumption"];
	$orderHash{ngchpGenerator} = ["voltage", "tempActual", "heatRecovered", "fuelUsage", "ChpC02", "boilerHeat", "CHPHeatContribution", "boilerNM", "boilerLbm"];
	$orderHash{pf} = ["val","pf_impexp","pf_laglead"];
	$orderHash{battery} = ["SoC","VRMSLL","Frequency","kW","kVAR"];
	$orderHash{solar} = ["VRMSLL","kW","kVAR"];

		
		# 1) generate header
		# 2) open all files and while relay file has data loop
		# 3) In loop increment ALL other files
my @header = ();
$header[0] = 44975;						#$headerInfoHash{startByte},	
$header[1] = $profileid;				#$headerInfoHash{profileId}, 
$header[2] = $simtimestart;				#$headerInfoHash{simtime}, 
$header[3] = $numberOfWaveforms;		#$headerInfoHash{numberOfWaveforms},
$header[4] = $numberOfPointsInWaveform;	#$headerInfoHash{numberOfPointsInWaveform},
$header[5] = 1;        #$headerInfoHash{scaleOfWaveform},
$header[6] = 48;        #$headerInfoHash{relays}{number},
$header[7] = 1000;       #$headerInfoHash{relays}{powerreal}{scale},
$header[8] = 1000;        #$headerInfoHash{relays}{reactivepower}{scale},
$header[9] = 1000;        #$headerInfoHash{relays}{voltage}{scale},
$header[10] = 1000;       #$headerInfoHash{relays}{frequency}{scale},
$header[11] = 1;       #$headerInfoHash{devices}{battery}{number},
$header[12] = 1000;       #$headerInfoHash{devices}{battery}{SoC}{scale},
$header[13] = 1000;       #$headerInfoHash{devices}{battery}{VRMSLL}{scale},
$header[14] = 1000;       #$headerInfoHash{devices}{battery}{Frequency}{scale},
$header[15] = 1000;       #$headerInfoHash{devices}{battery}{kW}{scale},
$header[16] = 1000;       #$headerInfoHash{devices}{battery}{kVAR}{scale},
$header[17] = 1;     #$headerInfoHash{devices}{dieselGenerator}{number},
$header[18] = 1000;       #$headerInfoHash{devices}{dieselGenerator}{voltage}{scale},
$header[19] = 1000;       #$headerInfoHash{devices}{dieselGenerator}{fuelConsumption}{scale},
$header[20] =  1;        #$headerInfoHash{devices}{ngchpGenerator}{number},
$header[21] =  1000;        #$headerInfoHash{devices}{ngchpGenerator}{voltage}{scale},
$header[22] =  1000;        #$headerInfoHash{devices}{ngchpGenerator}{tempActual}{scale},
$header[23] =  1000;        #$headerInfoHash{devices}{ngchpGenerator}{heatRecovered}{scale},
$header[24] =  1000;        #$headerInfoHash{devices}{ngchpGenerator}{fuelUsage}{scale},
$header[25] =  1000;        #$headerInfoHash{devices}{ngchpGenerator}{ChpC02}{scale},
$header[26] =  1000;        #$headerInfoHash{devices}{ngchpGenerator}{boilerHeat}{scale},
$header[27] =  1000;        #$headerInfoHash{devices}{ngchpGenerator}{CHPHeatContribution}{scale},
$header[28] =  1000;        #$headerInfoHash{devices}{ngchpGenerator}{boilerNM}{scale},
$header[29] =  1000;        #$headerInfoHash{devices}{ngchpGenerator}{boilerLbm}{scale},
$header[30] =  2;        #$headerInfoHash{devices}{motor}{number},
$header[31] =  1;        #$headerInfoHash{devices}{solar}{number},
$header[32] =  1000;        #$headerInfoHash{devices}{solar}{VRMSLL}{scale},
$header[33] =  1000;        #$headerInfoHash{devices}{solar}{kW}{scale},
$header[34] =  1000;        #$headerInfoHash{devices}{solar}{kVAR}{scale},
$header[35] =  3;        #$headerInfoHash{devices}{pf}{number},
$header[36] =  1000;        #$headerInfoHash{devices}{pf}{scale},
$header[37] =  3;        #$headerInfoHash{numberOfMiscDataScales}	
$header[38] = 36;
$header[39] = 1000;
$header[40] = 11;
$header[41] = 1000;
$header[42] = 9;
$header[43] = 1000;


my @filehandles = ();

 

foreach my $relayLabel ( @{$orderHash{relays}}) {
	my $filename = $datadir.$profileid.'/'.$folder.'/'.$relayLabel.".dat";
	print "opening $filename\n";
	local *FILEHANDLE;	
	open( FILEHANDLE , $filename )  || die("Could not openfile $!.");
    push(@filehandles, *FILEHANDLE);



}
foreach my $device (@{$orderHash{devices}}) {
# check to see if there's a sub device for this item to loop through
		if (defined $orderHash{$device}){
			foreach my $subDevice (@{$orderHash{$device}}){
					my $filename = $datadir.$profileid.'/'.$folder.'/'.$device."_".$subDevice.".dat";
					print "opening $filename\n";
					local *FILEHANDLE;	
					open( FILEHANDLE , $filename )  || die("Could not openfile $!.");
					push(@filehandles, *FILEHANDLE);
			}
				
		}else {
			my $filename = $datadir.$profileid.'/'.$folder.'/'.$device.".dat";
			print "opening $filename\n";
			local *FILEHANDLE;	
			open( FILEHANDLE , $filename )  || die("Could not openfile $!.");
			push(@filehandles, *FILEHANDLE);
		}
}

#misc
for (my $i=1; $i<=$header[37]; $i++) {
	my $filename = $datadir.$profileid.'/'.$folder.'/misc_'.$i.".dat";
	print "opening $filename\n";
	local *FILEHANDLE;	
	open( FILEHANDLE , $filename )  || die("Could not openfile $!.");
    push(@filehandles, *FILEHANDLE);
}

while (1){
	$header[2] = $simtimestart++;				#itterate simtime

	my @packet = @header;
	push(@packet,0); #waveform1
	push(@packet,0); #waveform2
	push(@packet,0); #waveform3
	my $iter = 0;
	foreach my $filehandle (@filehandles) {
		my $lineFromFile = <$filehandle> || die ("finished input file");
		chomp ($lineFromFile);
		$lineFromFile = substr $lineFromFile, 14;
		my @splitArray = split(/,/,$lineFromFile);
	#	print "$lineFromFile\n";
#	print Dumper (\@splitArray);
		if ($iter != 4) {
		map { $_ *= 1000 } @splitArray;
		}
		
#	print Dumper (\@splitArray);

		$iter++;
		push (@packet,@splitArray);
	}
	push(@packet,21845); #stop byte

	my $packstring = "i*"; # s is signed, S is unsigned (short - int16) (I - int32)
	my $payload = pack($packstring,@packet);
	
	$unicastOutSocket->send($payload) || die ("Can't send over unicast: $payload Error: $!\n");
	print "Sent packet.\n";
	usleep(200000);
}



sub openUnicastSendSocket(){
	my ($destip, $port, $myip) = @_;
	my $MyUnicastSendSocket = new IO::Socket::INET->new(PeerPort=>$port,Proto=>'udp',PeerAddr=>$destip,ReuseAddr=>1,LocalAddr=>$myip) || die "Error opening over unicast send socket: $!\n";
	$MyUnicastSendSocket->autoflush(1);
	return $MyUnicastSendSocket;
} 
sub printToFile () {
	my ($fiename,$data) = @_;
	open( OUTPUT , $fiename )  || die("Could not writeoutfile $!.");
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
