#include <stdio.h>
#include <mpi.h>
#include <random>
#define sqr(x)	((x)*(x))

double comp_pi(int points)
{
	double x_coord,
    y_coord, 
    pi,       
    r; 
  	int inside,n;
  	inside = 0;
  	for (n = 1; n <= points; n++)  
  	{
  		x_coord  = (double)random()/(double)RAND_MAX;
    	y_coord = (double)random()/(double)RAND_MAX;
    	if ((sqr(x_coord) + sqr(y_coord)) <= 1.0)inside++;
  	}
  	pi = 4.0 *(double)inside/(double)points;
  	return(pi);
} 

int main(int argc, char **argv) {

	int rank, size;
	double res, prom, starttime, endtime;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	srand(rank);
	for (int i=10000;i<50000002;i=i*2)
	//Se aumenta en cada iteracion la cantidad de puntos a calcular por nodo
	{
		MPI_Barrier(MPI_COMM_WORLD);
		starttime=MPI_Wtime();
		double res=comp_pi(i);
		MPI_Reduce(&res,&prom,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
		MPI_Barrier(MPI_COMM_WORLD);
		endtime=MPI_Wtime();
		if (rank==0)
		{
			prom/=size;
			printf("%d,%f,%f;\n",i,endtime-starttime,prom);
		}
	}
	MPI_Finalize();
}