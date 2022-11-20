#include <stdio.h>
#include <mpi.h>
int main(int argc, char **argv) {
	int rank, size;
	double starttime, endtime, tiempo;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	for (int n = 1; n <50000000; n+=500000) //Cantidad de doubles de 8 bytes a enviar
	{
			double *buff= new double[n];
			tiempo=0;
			for (int j=0;j<5;j++) //Se envian 5 veces y se promedia el tiempo
			{
				MPI_Barrier( MPI_COMM_WORLD ) ;
				starttime = MPI_Wtime();
				if(rank==0)		
					MPI_Send(buff,n,MPI_DOUBLE,1,5,MPI_COMM_WORLD);
				if(rank==1)
				{
					MPI_Status status;
					MPI_Recv(buff,n,MPI_DOUBLE,MPI_ANY_SOURCE,5,MPI_COMM_WORLD,&status);
				}
				MPI_Barrier( MPI_COMM_WORLD ) ;
				endtime = MPI_Wtime();
				tiempo+=endtime-starttime;	
			}
			if(rank==0)printf("%d,%f;\n",n*8,tiempo/5);
			delete buff;
	}
	MPI_Finalize();
}