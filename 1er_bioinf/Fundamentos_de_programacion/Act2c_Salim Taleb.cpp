#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int gen (char sec[]);

int main(int argc, char *argv[]) {
	
	int x;
	int G; //Variable donde se guardara la cantidad posible de genes
	char sec[5000]; //Arreglo donde se guardara la cadena
	srand(time(0)); //Comando para que se genere una secuencia distinta cada ejecución
	
	for (int b=0;b<5000;b++){ //Ciclo para repetir las acciones para los 5000 valores de la secuencia
		x=rand()%4; //Se genera un numero aleatorio y se queda con el resto de la divisiòn por 4 (número desde 0 a 3)
		if (x==0) //Si el numero es 0 
			sec[b]='C'; //Se le asigna al valor b de la secuencia, la letra C
		if (x==1) //Si el numero es 1
			sec[b]='G'; //Se le asigna al valor b de la secuencia, la letra G
		if (x==2) //Si el numero es 2
			sec[b]='A'; //Se le asigna al valor b de la secuencia, la letra A
		if (x==3) //Si el numero es 3
			sec[b]='T'; //Se le asigna al valor b de la secuencia, la letra T
		cout<<sec[b]; //Comando para ver la secuencia generada, por pantalla
	}

	G=gen (sec);
	cout<<endl<<"La cantidad posible de genes es de "<<G;
	return 0;
}
	int gen (char sec[]){
		int G=0;
		int n=0;
		for (int d=0;d<5000;d++){
			while (sec[d]=='C' or sec[d]=='G'){ //Este while describe que, si el valor analizado 
				d++;                            //de la secuencia es 'C' o 'G' se le suma 1 a la 
				n++;                            //variable n y se analiza la siguiente base
			}
			if (n>=4){ //Si la variable n es mayor o igual a 4 quiere decir que existe una isla CPG
				for (int y=d+70;y<=d+90;y++){ //Se analiza la secuencia a una distancia entre 70 y 90
					if (sec[y]=='T' and sec[y+1]=='A' and sec[y+2]=='T' and sec[y+3]=='A'){ //Si se encuentra una caja TATA
					G++; //Se suma 1 a la variable de los posibles genes
					y=d+91; //Se sale del "for" aumentando la variable por encima de la condicion del "for"
					}
				}
			n=0;
			}
			if (sec[d]=='T' and sec[d+1]=='A' and sec[d+2]=='T' and sec[d+3]=='A'){ //Si se encuentra una caja TATA
					for (int z=d+70;z<=d+90;z++){ //Se analiza la secuencia a una distancia entre 70 y 90
						while (sec[z]=='C' or sec[z]=='G'){ //Este while describe que, si el valor analizado 
						z++;                            //de la secuencia es 'C' o 'G' se le suma 1 a la 
						n++;                            //variable n y se analiza la siguiente base
						}
						if (n>=4){ //Si la variable n es mayor o igual a 4 quiere decir que existe una isla CPG
						G++; //Se suma 1 a la variable de los posibles genes
						z=d+91; //Se sale del "for" aumentando la variable por encima de la condicion del "for"
						}
						n=0;
					}	
			}
		}
	return G;
	}
