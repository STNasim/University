#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
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
	int primes, n, chunk= 100, limite=10000000;
	double starttime,endtime;
	for (int k=0;k<3;k++) //k=distribucion; 0=static, 1=dinamic, 2=guided
	{
		if(k==0)printf("static\n");
		if(k==1)printf("\ndinamic\n");
		if(k==2)printf("\nguided\n");
		printf("N hilos;Chunk;Tiempo\n");
		int aux=0;
		for(int j=1;j<13;j+=aux)
		{
			chunk=100;
			omp_set_num_threads(j); //Cantidad de hilos: 1,2,4,8,16
			for(int i=0;i<4;i++)
			{
				chunk*=10;
				primes=0;
				if(k==0)
				{
				starttime=omp_get_wtime();
				#pragma omp parallel for schedule (static) default(shared) reduction(+:primes)
				for(int n=2;n<limite;n++) if (isprime(n)) primes++;
				endtime=omp_get_wtime();
				}
				if(k==1)
				{
				starttime=omp_get_wtime();
				#pragma omp parallel for schedule (dynamic,chunk) default(shared) reduction(+:primes)
				for(int n=2;n<limite;n++) if (isprime(n)) primes++;
				endtime=omp_get_wtime();
				}
				if(k==2)
				{
				starttime=omp_get_wtime();
				#pragma omp parallel for schedule (guided,chunk) default(shared) reduction(+:primes)
				for(int n=2;n<limite;n++) if (isprime(n)) primes++;
				endtime=omp_get_wtime();
				}
				printf("%d;%d;%f\n",j,chunk,endtime-starttime);
			}
			if(j==1)aux=1;
			if(j==2)aux=2;
			if(j==4)aux=4;
		}
	}
}
