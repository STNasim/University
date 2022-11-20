#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv) {
	int fil,col,tam,sum;
	double starttime,endtime;
	int* matriz;

	for (int z=0;z<2;z++) //z=acceso; 0=por fil, 1=por col
	{
		if(z==0) printf("Acceso por fila\nN hilos;Bytes de matriz;Tiempo\n");
		else printf("\nAcceso por columna\nN hilos;Bytes de matriz;Tiempo\n");
		for (int p=0;p<4;p++)
		{
			if(p==0) fil=col=2; //16B
			if(p==1) fil=col=16; //1kB
			if(p==2) fil=col=512; //1mB
			if(p==3) fil=col=16384; //1gB
			tam=fil*col;
			matriz= new int [tam];
			for (int l = 0; l < tam; l++) matriz[l]=1;
			int aux=0;
			for (int k=1;k<13;k+=aux)
			{
				sum=0;
				omp_set_num_threads(k); //Cantidad de hilos: 1,2,4,8,16
				int i,j;
				if(z==0)
				{
					starttime=omp_get_wtime();
					#pragma omp parallel for default(shared) private(j) reduction(+:sum)
					for (j = 0; j < tam; j++)
						sum+=matriz[j];
					endtime=omp_get_wtime();
				}
				else
				{
					starttime=omp_get_wtime();
					#pragma omp parallel for default(shared) private(i,j) reduction(+:sum)
					for (j = 0; j < fil; j++)
						for( i=0; i< col;i++)
							sum+=matriz[j*col+i];
					endtime=omp_get_wtime();
				}
				printf("%d;%d;%f\n",k,tam*4,endtime-starttime);
				if(k==1)aux=1;
				if(k==2)aux=2;
				if(k==4)aux=4;
			}
			if(matriz) delete matriz;
		}
	}
}
