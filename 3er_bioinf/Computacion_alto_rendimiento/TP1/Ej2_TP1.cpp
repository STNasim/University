#include <stdio.h>
#include <mpi.h>
int main(int argc, char **argv) {

	int rank, size;
	double starttime, endtime, tiempo=0;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	double *buff= new double[20000000];
	MPI_Status status;

	for (int e=0;e<size;e++)
	{
		for(int r=e+1;r<size;r++)
		//Se recorre la matriz de nodos trinagular superior
		{
			for (int i=0;i<5;i++)
			//Se repiten los envios 5 veces y se promedian
			{
				MPI_Barrier( MPI_COMM_WORLD ) ;
				starttime = MPI_Wtime();
				if(rank==e)
					MPI_Send(buff,20000000,MPI_DOUBLE,r,5,MPI_COMM_WORLD);
				else if(rank==r)
					MPI_Recv(buff,20000000,MPI_DOUBLE,e,5,MPI_COMM_WORLD,&status);	
				MPI_Barrier( MPI_COMM_WORLD ) ;
				endtime = MPI_Wtime();
				tiempo+=endtime-starttime;
			}
			if (rank==r)printf("El tiempo de envio en la prueba desde %d a %d fue %f seg \n",e,r,tiempo/5);
			tiempo=0;
		}
	}
	MPI_Finalize();
}