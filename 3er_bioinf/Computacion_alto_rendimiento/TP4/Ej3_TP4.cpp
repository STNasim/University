#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char **argv) 
{
	double starttime,endtime;
	int filA,colA,colB;
	printf("Tam de A;Hilos;Tiempo\n");
	int aux=0;
	for (int hilos=1;hilos<13;hilos+=aux)
	{
		omp_set_num_threads(hilos); //Cantidad de hilos: 1,2,4,8,16
		for(int p=0;p<5;++p)//VER P
		{
			if(p==0) filA=colA=colB=2; //16B c/matriz
			if(p==1) filA=colA=colB=16; //1kB c/matriz
			if(p==2) filA=colA=colB=50; //~10kB c/matriz
			if(p==3) filA=colA=colB=160; //100kB c/matriz
			if(p==4) filA=colA=colB=512; //1mB c/matriz
			if(p==5) filA=colA=colB=1619; //~10mB c/matriz
			if(p==6) filA=colA=colB=5120; //100mB c/matriz
			if(p==7) filA=colA=colB=16384; //1gB c/matriz
			int *a= new int[filA*colA];
			int *b= new int[colA*colB];
			int *c= new int[filA*colB];

			int i,j,k;
			starttime=omp_get_wtime();
			#pragma omp parallel for default(shared) private(i,j)
			for (k=0; k<colB; k++)
				for (i=0; i<filA; ++i)
				{
					c[i*colB+k] = 0.0;
					for (j=0; j<colA; j++) c[i*colB+k] = c[i*colB+k] + a[i*colA+j] * b[j*colB+k];
				}
			endtime=omp_get_wtime();
			if(a) delete a;
			if(b) delete b;
			if(c) delete c;
			printf("%d;%d;%f\n",filA*colA*4,hilos,endtime-starttime);
		}
	if(hilos==1)aux=1;
	if(hilos==2)aux=2;
	if(hilos==4)aux=4;
		
	}
}
