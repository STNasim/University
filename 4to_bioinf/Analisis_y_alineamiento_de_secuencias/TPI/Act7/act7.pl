use Bio::SearchIO;
use strict;
use warnings;

my $searchio = Bio::SearchIO->new( -file   => "$ARGV[0]" );

while (my $result = $searchio->next_result) 
{
    print "Procesando Query: ",$result->query_name," ",$result->query_description,"\n";
    my $nombre_archi =$result->query_name;
    $nombre_archi =~ s/\//\-/g;
    open(ARCHI,'>', $nombre_archi); 
    print ARCHI "Hit Nro.\tDescripcion\t%identidad\tInicio Match\tFin Match\t%secuencia alineada\n";
    my $nro_hit=0; 
    while (my $hit = $result->next_hit) 
    {
        if($nro_hit>9) {last};
        my $hsp = $hit->hsp('best');
        $nro_hit+=1;
        print ARCHI $nro_hit,"\t";
        print ARCHI $hit->description(),"\t";
        print ARCHI $hsp->percent_identity(),"\t";
        print ARCHI $hsp->start('query'),"\t";
        print ARCHI $hsp->end('query'),"\t";
        print ARCHI $hsp->frac_conserved('query')*100;
        print ARCHI "\n";
    }
    close(ARCHI);
}