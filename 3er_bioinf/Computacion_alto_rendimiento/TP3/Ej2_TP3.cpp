#include <stdio.h>
#include <mpi.h>
#include <math.h>

int isprime(int n) 
{
	int m = int(sqrt(n));
	for (int j=2; j<=m; j++)
		if (!(n % j)) return 0;
	return 1;
}

int main(int argc, char **argv) 
{
	MPI_Init(&argc,&argv);
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	int n2, primesh, primes, chunk= 1000, n1,limite=10000000;
	double starttime,comsynctime,worktime;
	for(int i=0;i<5;i++)
	{
		if(i==1 or i==2 or i==3) chunk*=10;
		if(i==4) chunk*=2;
		comsynctime=worktime=0;
		primesh=0;
		n1 = rank*chunk;
		starttime=MPI_Wtime();
		while(1) 
		{
			n2 = n1 + chunk;
			if(n2>limite) n2=limite;
			for (int n=n1; n<n2; n++) 
				if (isprime(n)) primesh++;
			worktime+=MPI_Wtime()-starttime;
			starttime=MPI_Wtime();
			MPI_Reduce(&primesh,&primes,1,MPI_INT,MPI_SUM,3,MPI_COMM_WORLD);
			comsynctime+=MPI_Wtime()-starttime;
			starttime=MPI_Wtime();
			n1 += size*chunk;
			if (n1>=limite) break;
		}
		MPI_Barrier(MPI_COMM_WORLD);
		if(rank==0) printf("Chunk:%d\nRank;Comsynctime;Worktime\n",chunk);
		for (int j=0;j<size;j++)
		{
			if(rank==j) printf("%d;%f;%f\n",rank,comsynctime,worktime);
			MPI_Barrier(MPI_COMM_WORLD);
		}
	}
	
	MPI_Finalize();
}