#include <stdio.h>
#include <mpi.h>

template<class T>
void mybcastSec(T *buff, long tam,MPI_Datatype tipo, int fuente, MPI_Comm com)
{	
	MPI_Status status;
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	//Se realiza un envio desde la fuente a cada nodo que no sea la fuente
	for (int i=0;i<size;i++)
		if(i!=fuente)
			{
				if(rank==fuente)MPI_Send(buff,tam,tipo,i,i,com);
				if(rank==i)MPI_Recv(buff,tam,tipo,fuente,i,com,&status);
			}
}

template<class T>
void mybcastTree(T *buff, long tam,MPI_Datatype tipo, int fuente, MPI_Comm com)
{	
	MPI_Status status;
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	int n1=0, n2=size;
	//Por simplicidad, si el nodo 0 no es la fuente se envia primero a él los datos
	if (fuente!=0)
	{
		if(rank==0) MPI_Recv(buff,tam,tipo,fuente,0,com,&status);
		if(rank==fuente) MPI_Send(buff,tam,tipo,0,0,com);
	}
	//Se realiza un envio en forma de arbol a los nodos desde el 0
	while ((n2-n1)!=1) 
	{
		int middle = (n1+n2)/2;
		if (rank==n1) MPI_Send(buff,tam,tipo,middle,middle,com);
		else if (rank==middle) MPI_Recv(buff,tam,tipo,n1,middle,com,&status);
		if (rank<middle) n2 = middle;
		else n1=middle;
	}
}

int main(int argc, char **argv) {

	int rank, size;
	double starttime, endtime;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	
	double *buff= new double[20000000];
	
	MPI_Barrier(MPI_COMM_WORLD);
	starttime=MPI_Wtime();
	mybcastSec(buff, 20000000, MPI_DOUBLE, 2, MPI_COMM_WORLD);
	MPI_Barrier(MPI_COMM_WORLD);
	endtime=MPI_Wtime();
	if(rank==0)printf("El tiempo para mybcastSec() fue de: %f\n",endtime-starttime);

	
	MPI_Barrier(MPI_COMM_WORLD);
	starttime=MPI_Wtime();
	mybcastTree(buff, 20000000, MPI_DOUBLE, 2, MPI_COMM_WORLD);
	MPI_Barrier(MPI_COMM_WORLD);
	endtime=MPI_Wtime();
	if(rank==0)printf("El tiempo para mybcastTree() fue de: %f\n",endtime-starttime);


	MPI_Barrier(MPI_COMM_WORLD);
	starttime=MPI_Wtime();
	MPI_Bcast(buff, 20000000, MPI_DOUBLE, 2, MPI_COMM_WORLD);
	MPI_Barrier(MPI_COMM_WORLD);
	endtime=MPI_Wtime();
	if(rank==0)printf("El tiempo para MPI_Bcast() fue de: %f\n",endtime-starttime);
	
	MPI_Finalize();
}