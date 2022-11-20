#include <stdio.h>
#include <mpi.h>

template<class T>
void mygatherv(T *sbuff, long nsend,MPI_Datatype tipo, T *rbuff, int *nrecv, int *despl,MPI_Datatype tipo2, int recep, MPI_Comm com)
{
	MPI_Status status;
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	if(rank==recep)
	{
		for(int i=0;i<size;i++)
			if(i!=recep) 
				MPI_Recv(&rbuff[despl[i]],nrecv[i],tipo2,i,i,com,&status);
			else
				for(int j=0;j<nsend;j++) rbuff[despl[i]+j]=sbuff[j];
	}
	else
		MPI_Send(sbuff,nsend,tipo,recep,rank,com);
}

int main(int argc, char **argv) {

	int rank, size;
	double res, prom, starttime, endtime;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	int tam=5003;
	int part=tam/size;
	int extra=tam-part*size;

	//Establece los tamaños de cada set de datos
	double middle=(size/2.0)-0.5;
	int n=part;
	if (rank<middle) n-=part/2;
	if (rank>middle) n+=part/2;
	if (rank==size-1) n+=extra;
	double *sbuff= new double[n];

	int *nrecv=NULL;
	int *despl=NULL;
	double *rbuff=NULL;

	//Seteo de parametros de tamaños en el "master"
	if(rank==2)
	{
		rbuff= new double[tam];
		nrecv= new int[size];
		despl= new int[size];

		for (int j=0; j<size; j++)
		{
			if (j<middle) nrecv[j]=part-part/2;
			if (j==middle) nrecv[j]=part;
			if (j>middle) nrecv[j]=part+part/2;
		}

		nrecv[size-1]+=extra;
		despl[0]=0;
 		for (int j=1; j<size; j++)despl[j] = despl[j-1] + nrecv[j-1];
	}

	//Setear datos en el "master"
	if (rank==2)
		for (int j=0; j<tam; j++)rbuff[j] = j;
	
	//Envío de los datos a procesar a cada procesador
	MPI_Scatterv(rbuff,nrecv,despl,MPI_DOUBLE,sbuff,n,MPI_DOUBLE,2,MPI_COMM_WORLD);

	//Operacion sobre los datos
	for (int j=0; j<n; j++)
		sbuff[j]*=rank;

	//MPI_Gatherv(sbuff,n,MPI_DOUBLE,rbuff,nrecv,despl,MPI_DOUBLE,2,MPI_COMM_WORLD);
	mygatherv(sbuff,n,MPI_DOUBLE,rbuff,nrecv,despl,MPI_DOUBLE,2,MPI_COMM_WORLD);
	if(rank==2)for(int i=0;i<tam;i++) printf("rbuff[%d]=%f\n",i,rbuff[i]);

	if(rbuff) delete rbuff;
	if(nrecv) delete nrecv;
	if(sbuff) delete sbuff;
	if(despl) delete despl;
	MPI_Finalize();
}