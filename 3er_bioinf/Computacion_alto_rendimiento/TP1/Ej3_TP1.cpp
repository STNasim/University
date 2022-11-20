#include <stdio.h>
#include <mpi.h>
int main(int argc, char **argv) {

	int rank, size;
	double starttime, endtime, tiempo=0;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	int n=1;
	while(n*2<=size) 
	//Se relizara un envio a la particion siempre que exista suficientes nodos en la corrida
	{
		double *buff= new double[20000000];
		MPI_Status status;
		for (int i=0;i<5;i++)
		//Se repiten los envios 5 veces y se promedian
		{
			MPI_Barrier( MPI_COMM_WORLD ) ;
			starttime = MPI_Wtime();
			if(rank<n)
				MPI_Send(buff,20000000,MPI_DOUBLE,rank+n,5,MPI_COMM_WORLD);
			else if(rank<n*2)
				MPI_Recv(buff,20000000,MPI_DOUBLE,rank-n,5,MPI_COMM_WORLD,&status);
			MPI_Barrier( MPI_COMM_WORLD ) ;
			endtime = MPI_Wtime();
			tiempo+=endtime-starttime;		
		}
		if (rank==0)printf("El tiempo de envio en la prueba con %d procesadores en cada particion fue de %f seg \n",n,tiempo/5);
		n++;
		tiempo=0;
	}
	MPI_Finalize();
}