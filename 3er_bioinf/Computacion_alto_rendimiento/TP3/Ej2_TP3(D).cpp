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

int main(int argc, char **argv) {

	MPI_Init(&argc,&argv);
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	int N=10000000;//Contando el 0
	MPI_Status status;
	int stat[2]; // checked,primes
	double starttime,comsynctime,worktime;
	int chunk=1000; 

	for(int i=0;i<5;i++)
	{
		if(i==1 or i==2 or i==3) chunk*=10;
		if(i==4) chunk*=2;
		comsynctime=worktime=0;
		
		if (rank==0) 
		{
			int first=2, checked=2, down=0, primes=0;
			while (down!=size-1) 
			{
				starttime=MPI_Wtime();
				MPI_Recv(&stat,2,MPI_INT,MPI_ANY_SOURCE,MPI_ANY_TAG, MPI_COMM_WORLD,&status);
				comsynctime+=MPI_Wtime()-starttime;
				starttime=MPI_Wtime();
				int source = status.MPI_SOURCE;
				if (stat[0]) 
				{
					checked += stat[0]; 
					primes += stat[1];
				}
				MPI_Send(&first,1,MPI_INT,source,0,MPI_COMM_WORLD);
				if (first<N) first += chunk;
					else down++;
				worktime+=MPI_Wtime()-starttime;
			}
		} 
		else 
		{
			int start;
			stat[0]=0; stat[1]=0;
			starttime=MPI_Wtime();
			MPI_Send(stat,2,MPI_INT,0,0,MPI_COMM_WORLD);
			while(true) 
			{
				MPI_Recv(&start,1,MPI_INT,0,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
				comsynctime+=MPI_Wtime()-starttime;
				starttime=MPI_Wtime();
				if (start>=N) break;
				int last = start + chunk;
				if (last>N) last=N;
				stat[0] = last-start ; stat[1] = 0;
				for (int n=start; n<last; n++)
					if (isprime(n)) stat[1]++;
				worktime+=MPI_Wtime()-starttime;
				starttime=MPI_Wtime();
				MPI_Send(stat,2,MPI_INT,0,0,MPI_COMM_WORLD);
			}
		}
		MPI_Barrier(MPI_COMM_WORLD);
		if(rank==0) printf("Chunk:%d\nRank;Comsynctime;Worktime\n",chunk);
		MPI_Barrier(MPI_COMM_WORLD);
		printf("%d;%f;%f\n",rank,comsynctime,worktime);
	}
	MPI_Finalize();
}