#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void Islas(char sec[],int &ICpG, int &PI, int &TI); //Prototipo de la funcion Islas

int main(int argc, char *argv[]) {
	
	int ICpG=0; //Variables con la cantidad de Islas CpG
	int PI=0;//Variables que representan la posición y
	int TI=0;//el tamaño de la mayor Isla CpG
	string se; //Variable string donde se ingresara la cadena por primera vez
	
	cout<<"Ingrese la secuencia"<<endl;
	cin>>se; //Se lee la secuencia por teclado
	
	char * sec = new char [se.length()+1]; //Se declara un cstring con un tamaño equivalente al string de la cadena
	std::strcpy (sec, se.c_str()); //Se copia el contenido del string al cstring
	
	Islas(sec,ICpG,PI,TI); //Llamado de la funcion Islas
	cout<<endl<<"La cantidad de Islas CpG es: "<<ICpG; //Muestra la cantidad de Islas CpG por pantalla
	cout<<endl<<"El tamanio de la mayor Isla CpG es: "<<TI; //Muestra el tamaño de la mayor Isla CpG por pantalla
	cout<<endl<<"La posicion de la mayor Isla CpG es: "<<PI; //Muestra la posición de la mayor Isla CpG por pantalla
	delete [] sec;  //Se devuelve la memoria pedida previamente

	return 0;
}

void Islas(char sec[],int &ICpG, int &PI, int &TI){ //Implementacion de la funcion Islas
	int n=0; //Variable auxiliar
	for (int d=0;d<5000;d++){ //Ciclo para repetir las acciones hasta el ultimo valor de la secuencia
		while (sec[d]=='C' or sec[d]=='G'){ //Este while describe que, si el valor analizado 
			d++;                            //de la secuencia es 'C' o 'G' se le suma 1 a la 
			n++;                            //variable n y se analiza la siguiente base
		}
		if (n>=4){ //Si la variable n es mayor o igual a 4, es decir, que hay 4 o más
			ICpG++; //'C' o 'G' se suma 1 al contador de las Islas CpG
			if (n>TI){ //Si el tamaño de la ultima Isla detectada es mayor en tamaño a la previamente
				TI=n;  //guardada, se sobrescribe TI con el tamaño de esta nueva isla
				PI=d-n; //Ademas, se indica la posicion de esta nueva isla de mayor tamaño
			}
		}		
		n=0; //Se reinicia la variable n a 0 en caso de que haya 'C' o 'G' seguidas pero que no formen una Isla CpG
		//y para que al terminar de contar una Isla CpG comience nuevamente en 0
	}
}
