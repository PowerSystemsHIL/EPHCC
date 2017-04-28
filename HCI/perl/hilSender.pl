
use strict;
use warnings;

use Net::TcpDumpLog;
use Data::Dumper;
#use Data::Printer;
use IO::Socket;

use Time::HiRes qw(usleep);

use JSON;

my $datadir = '../data/';


my $log = Net::TcpDumpLog->new(); 
$log->read("../sampleData/banshee.pcap");

my @indexes = $log->indexes;

	
my $unicastOutSocket = &openUnicastSendSocket("127.0.0.1","7200","127.0.0.1");


# when you start the perl script it should delete the data in the data dirs.



# divide by 1000 for real/reactive power

foreach my $index (@indexes) {
	my ($length_orig,$length_incl,$drops,$secs,$msecs) = $log->header($index); 
	my $data = $log->data($index);
	
	
	my ($headers,$payload) = unpack('b336 a*',$data);
	if (defined $payload and $payload ne '') {
	
		my ($startbyte) = unpack('n*',$payload);

		
		if ($startbyte == 44975) {
		
			$unicastOutSocket->send($payload) || die ("Can't send over unicast: $payload Error: $!\n");
		}else {
		
			print "Skipping startbyte: $startbyte\n";
		}
	}
		
	usleep (20000);
	

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
