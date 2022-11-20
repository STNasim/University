#include <stdio.h>
#include <mpi.h>
#include <fstream>
int main(int argc, char **argv) 
{
	int rank, size;
	double starttime, endtime;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	if(size>1)
	{
		int l=0;
		int n=0;
		int extra=0;
		int cantA=0;
		char*lectura;
		MPI_Status status;
		if(rank==0)
		{
			std::fstream archi;
			archi.open("homo_sapiens_chromosome_1.fasta", std::fstream::in);
			archi.seekg(0,archi.end);
			l= archi.tellg();
			archi.seekg(0,archi.beg);
			archi.ignore(10000,'\n'); //Se ignora la cabecera
			l-=archi.tellg(); //Se resta la cabecera
			lectura= new char[l];
			archi.read(lectura,l);
			n=l/size;
			int extra= l-n*size;
			//Se envia a cada nodo el tamaño del arreglo que van a recibir
			//y tambien el tamaño extra que recibira el ultimo
			for (int i=1;i<size;i++)
				MPI_Send(&n,1,MPI_INT,i,i,MPI_COMM_WORLD);
			MPI_Send(&extra,1,MPI_INT,size-1,20,MPI_COMM_WORLD);
		}
		else
			MPI_Recv(&n,1,MPI_INT,0,rank,MPI_COMM_WORLD,&status);
		if(rank==size-1)
		{
			MPI_Recv(&extra,1,MPI_INT,0,20,MPI_COMM_WORLD,&status);
			n+=extra;
		}

		if(rank==0)
		{
			//Se envian los datos a cada nodo
			for (int i = 1; i < size; i++)
				if(i==size-1)
					MPI_Send(lectura+n*i,n+extra,MPI_CHAR,i,i,MPI_COMM_WORLD);
				else
					MPI_Send(lectura+n*i,n,MPI_CHAR,i,i,MPI_COMM_WORLD);
			//Se cuentan las A
			for (int i = 0; i < n; i++)
				if(lectura[i]=='A')
					cantA+=1;
			
			int aux=0;
			for (int i = 1; i < size; i++)
			{
				MPI_Recv(&aux,1,MPI_INT,i,i,MPI_COMM_WORLD,&status);
				cantA+=aux;
			}
			
			printf("Cantidad de A:%d\n",cantA);

			double porA=double(cantA/double(l));
			printf("Procentaje de A:%f\n",porA);
	
		}
		else
			{
				lectura= new char[n];
				MPI_Recv(lectura,n,MPI_CHAR,0,rank,MPI_COMM_WORLD,&status);
				//Se cuentan las A
				for (int i = 0; i < n; i++)
					if(lectura[i]=='A')
						cantA+=1;
				MPI_Send(&cantA,1,MPI_INT,0,rank,MPI_COMM_WORLD);
			}
	}
	MPI_Finalize();
}