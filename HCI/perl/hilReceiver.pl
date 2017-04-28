#!/usr/bin/perl

use strict;
use warnings;

use Data::Dumper;
#use Data::Printer;
use IO::Socket;
use IO::Handle;
use Time::HiRes qw(usleep gettimeofday);

use threads;
use threads::shared;
#use InfluxDB;
#use InfluxDB::LineProtocol qw(1.0.2 line2data);

require "common_functions.pl";

print "Starting HIL Listener.\n";

my $datadir = '../data/';
my $currDataDir : shared;
my $prevtimestamp : shared = 0;
my $folderTimeStamp : shared = 0;




if (!-d $datadir) {
	print "First time running. Creating datadir: $datadir \n";
	`mkdir $datadir`;
	print "Datadir created\n";
}





print "Starting zip monitor\n";
my $thr1 = threads->new(\&zipChecker,$datadir);

my $unicastListenSocket = &openUnicastListenSocket(7200);
my $receivedpacket;
print "Listening for data.\n";

#Copyright (c) 2016 Massachusetts Institute of Technology
#
#Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
#
#The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
#
#THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

# if we get updates faster than we can process them, this can fall behind. At 10 to 30 Hz it shouldn't really happen.
# If it starts to happen, we'd need to add a thread to decode and a thread to listen to decouple the operations
while (1) {
    $unicastListenSocket->recv($receivedpacket,9192);

	my ($startbyte) = unpack('i',$receivedpacket);
		
	my $timestamp =  int(1000* gettimeofday);

	
	# check to see if we need a new datadir
	# currently pegged at a 10 second gap
	if ($timestamp - $prevtimestamp > 10000) { 
			print "***********New Run Detected!***************Time Diff between packets: ".($timestamp - $prevtimestamp)."\n";
			my ($sec, $min, $hour, $mday, $mon, $year, $wday, $yday, $isdst) = localtime($timestamp/1000);
			$year +=1900;
			$mon +=1;
			if ($mon<10) {
				$mon = "0".$mon;
			}
			if ($mday<10) {
				$mday = "0".$mday;
			}
			if ($hour<10) {
				$hour = "0".$hour;
			}
			if ($min<10) {
				$min = "0".$min;
			}
			if ($sec<10) {
				$sec = "0".$sec;
			}
			{
				lock ($folderTimeStamp);
				$folderTimeStamp = "$mon-$mday-$year-$hour-$min-$sec";
			}
			
	} 
	{
		lock($prevtimestamp);
		$prevtimestamp = $timestamp;
	}
	print "$timestamp received packet \n";

	if ($startbyte != 44975) {
	print "$timestamp: $startbyte is WRONG STARTBYTE! Should be 44975\n";
	}else{
		&decodePacket($timestamp, $datadir, $folderTimeStamp, $receivedpacket);
	}
}

$thr1->join;

sub zipChecker(){
	my ($datadir) =@_;
	sleep(10);
	# get current dir
	# check for orphan dirs to zip


	# while 1 check if last known is > 10 and not zipped zip zip -r myarch.zip mydir/*
	
	while(1){
		my $timestamp =  int(1000* gettimeofday);
		my $localPrevTime = 0;
		{
			lock($prevtimestamp);
			$localPrevTime = $prevtimestamp;
		}
		
		my $localFolderTimeStamp = 0;
		{
			lock($folderTimeStamp);
			$localFolderTimeStamp = $folderTimeStamp;
		}
		
		my $fileToCheck = $datadir."/2/".$localFolderTimeStamp.'';
		my $fileToOutput = $datadir."/2/".$localFolderTimeStamp.".tar.gz";

		if ($timestamp - $localPrevTime > 10000 and $localFolderTimeStamp ne "0") {
			if (! -e "$fileToOutput"){
				print "Should be tarring $fileToCheck into $fileToOutput\n";
				`tar -cvf $fileToOutput $fileToCheck`;
				print "Finished tarring\n";

			}

		
		}
		sleep (1);
	}

	#
}
