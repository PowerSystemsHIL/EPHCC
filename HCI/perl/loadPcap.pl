#!/usr/bin/perl
#Copyright (c) 2016 Massachusetts Institute of Technology
#
#Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
#
#The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
#
#THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

use strict;
use warnings;

use Net::TcpDumpLog;
use Data::Dumper;
#use Data::Printer;
use IO::Handle;
use Time::HiRes qw(usleep time);

use JSON;

require 'common_functions.pl';

my $datadir = '../data/';

my $log = Net::TcpDumpLog->new(); 
$log->read("../sampleData/hil v2.pcap");

my @indexes = $log->indexes;

&dataDirCleanup($datadir);


# divide by 1000 for real/reactive power

foreach my $index (@indexes) {
	my ($length_orig,$length_incl,$drops,$secs,$msecs) = $log->header($index); 
	my $data = $log->data($index);
	
	
	my ($headers,$payload) = unpack('b336 a*',$data);

	my (@unpacked) = unpack('n s704 b8 b8 b8 b8 b8 b8 b8 b8 b8 b8 b8 b8 b8 b8 b8 b8 b8 b8 b8 b8 s4 n*',$payload);
	
	my $startbyte = $unpacked[0];
	my $timestamp =  time*1000;

	if ($startbyte != 44975) {
		print "$timestamp: $startbyte is WRONG STARTBYTE! Should be 44975\n";
	}else{
		&decodePacket($timestamp, $datadir, \@unpacked);
		#usleep (200000);
	}

}
