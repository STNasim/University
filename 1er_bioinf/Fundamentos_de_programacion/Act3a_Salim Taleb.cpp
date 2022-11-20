#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;

void contar(char sec[],int &A, int &C, int &G, int &T, int x); //Prototipo de la funcion contar
void prop(int &A, int &C, int &G, int &T, float &ProC, float &ProG); //Prototipo de la funcion prop
void Islas(char sec[],int &ICpG, int &PI, int &TI, int x); //Prototipo de la funcion Islas
int FMT(int &A, int &C, int &G, int &T); //Prototipo de la funcion FMT
int cajas(char sec[], int x); //Prototipo de la funcion cajas
void comp (char sec[], char secc[], int x); //Prototipo de la funcion comp

int main(int argc, char *argv[]) {
	int x,z; //Variable auxiliar
	int A,C,G,T; //Variables con las cantidades de bases
	C=G=A=T=0; //Se inician todas las variables en 0 para evitar contenido basura
	int A1,C1,G1,T1; //Variables para el calculo
	C1=G1=A1=T1=0; //Se inician todas las variables en 0 para evitar contenido basura
	float ProC,ProG; //Variables para calcular proporciones
	int ICpG=0; //Variables con la cantidad de Islas CpG
	int PI=0;//Variables que representan la posición y
	int TI=0;//el tamaño de la mayor Isla CpG
	int Tm; //Variable para el calculo de la formula de Tm
	int TATA=0; //Variable para las cajas TATA
	string se, l;
	ifstream secuen;
	secuen.open("FragmentoCromo1.txt"); //Se asigna el archivo fisico al archivo logico
	
	while (getline(secuen, l)) //Se copia la informacion del archivo fisico a un string
		se += l; //Se copia la informacion del string l al se y se desplaza 1 lugar
	
	char * sec = new char [se.length()+1]; //Se declara un cstring con un tamaño equivalente al string de la cadena mas uno espacio para el \0
	std::strcpy (sec, se.c_str()); //Se copia el contenido del string al cstring
	
	x=se.length()-1; //Se asigna a la variable x el valor del largo de la cadena -1 para futuros calculos
	contar(sec, A, C, G, T, x); //Llamado de la funcion contar
	cout<<endl<<"La cantidad de Citosina es: "<<C; //Muestra la cantidad de Citosina por pantalla
	cout<<endl<<"La cantidad de Guanina es: "<<G; //Muestra la cantidad de Guanina por pantalla
	cout<<endl<<"La cantidad de Adenina es: "<<A; //Muestra la cantidad de Adenina por pantalla
	cout<<endl<<"La cantidad de Timina es: "<<T; //Muestra la cantidad de Timina por pantalla
	
	prop(A,C,G,T,ProC,ProG); //Llamado de la funcion prop
	cout<<endl<<"La proporcion de Citosina es: "<<ProC<<"%"; //Muestra la proporción de Citosina por pantalla
	cout<<endl<<"La proporcion de Guanina es: "<<ProG<<"%"; //Muestra la proporción de Guanina por pantalla
	
	Islas(sec,ICpG,PI,TI,x); //Llamado de la funcion Islas
	cout<<endl<<"La cantidad de Islas CpG es: "<<ICpG; //Muestra la cantidad de Islas CpG por pantalla
	cout<<endl<<"El tamanio de la mayor Isla CpG es: "<<TI; //Muestra el tamaño de la mayor Isla CpG por pantalla
	cout<<endl<<"La posicion de la mayor Isla CpG es: "<<PI; //Muestra la posición de la mayor Isla CpG por pantalla
	
	cout<<endl<<"Ingrese la posicion de la secuencia para comenzar "; //Se pide ingresar el dato para comenzar"
	cin>>z; //Se lee la posición de la secuencia donde se debe empezar a calcular
	
	for(int c=0;c<20;c++){ //Este proceso se repite 20 veces
		if (sec[z+c-1]=='C') //Si la base en la posición es 'C'
			C1++; //Se le suma 1 a C
		if (sec[z+c-1]=='G') //Si la base en la posición es 'G'
			G1++; //Se le suma 1 a G
		if (sec[z+c-1]=='A') //Si la base en la posición es 'A'
			A1++; //Se le suma 1 a A
		if (sec[z+c-1]=='T') //Si la base en la posición es 'T'
			T1++; //Se le suma 1 a T
	}
	
	Tm=FMT(A1,C1,G1,T1); //Llamado de la funcion FMT
	cout<<"El resultado de la formula de Melting Temperature es: "<<Tm; //Mostrando resultado en pantalla
	
	TATA=cajas(sec,x); //Llamado de la funcion cajas
	cout<<endl<<endl<<"La cantidad de cajas TATA en la secuencia es de: "<<TATA<<endl; //Mostrando resultado en pantalla
	
	char * secc = new char [se.length()+1]; //Se declara un cstring con un tamaño equivalente al string de la cadena extraida mas un espacio para el \0
	comp(sec,secc,x); //Llamado de la funcion comp
	
	cout<<endl<<"La reversa complementaria de la secuencia es:"<<endl<<secc; //Mostrando resultado en pantalla
	delete [] sec; //Se devuelve la memoria prestada
	delete [] secc; //Se devuelve la memoria prestada
	secuen.close(); //Se cierra el archivo
	return 0;
}
void contar(char sec[],int &A, int &C, int &G, int &T,int x){ //Implementacion de la funcion contar
	for (int c=0;c<x;c++){ //Ciclo para repetir las acciones para los 5000 valores de la secuencia
		if (sec[c]=='C') //Si el caracter es C 
			C++; //Se le suma 1 al valor total de Citosina
		if (sec[c]=='G') //Si el caracter es G
			G++; //Se le suma 1 al valor total de Guanina
		if (sec[c]=='A') //Si el caracter es A
			A++; //Se le suma 1 al valor total de Adenina
		if (sec[c]=='T') //Si el caracter es T
			T++; //Se le suma 1 al valor total de Timina
	}
}
	
void prop(int &A, int &C, int &G, int &T, float &ProC, float &ProG){ //Implementacion de la funcion prop
	ProC=(float(C*100)/float(C+G+A+T)); //Cálculo de la proporción de Citosina
	ProG=(float(G*100)/float(C+G+A+T)); //Cálculo de la proporción de Guanina
}
		
void Islas(char sec[],int &ICpG, int &PI, int &TI, int x){ //Implementacion de la funcion Islas
	int n=0; //Variable auxiliar
	for (int d=0;d<x;d++){ //Ciclo para repetir las acciones hasta el ultimo valor de la secuencia
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
		n=0; //Se reinicia la variable n a 0 en caso de que haya 'C' o 'G' seguidas pero que no formen una 
		//Isla CpG y para que al terminar de contar o no una Isla CpG comience nuevamente en 0
		}
}
int FMT(int &A, int &C, int &G, int &T){ //Implementacion de la funcion FMT
	int Tm;
	Tm=((4*(G+C))+(2*(A+T))); //Cálculo de Melting Temperature
	return Tm; //Devuelve el resultado de la formula
}
int cajas(char sec[],int x){ //Implementacion de la funcion cajas
	int TATA=0; //Variable para las cajas TATA
		for (int d=0;d<x;d++){ //Ciclo para repetir las acciones hasta el ultimo valor de la secuencia
			if (sec[d]=='T' and sec[d+1]=='A' and sec[d+2]=='T' and sec[d+3]=='A'){ //Si se cumple que una continuación de bases es TATA
			d=d+3; //Se saltan hasta el final de la caja
				TATA++; //y se suma 1 al contador de cajas TATA
			}
		}
		return TATA; //Devuelve la cantidad de cajas TATA
}
void comp(char sec[], char secc[], int x){ //Implementacion de la funcion comp
	int p=0;
	for (int e=x;e>-1;e--){ //Ciclo que comienza en el final de la secuencia, y termina en el inicio
		if (sec[e]=='C'){ //Si el caracter es 'C'
			secc[p]='G'; //Le coloca un caracter 'G' a la secuencia complementaria
		}
		if (sec[e]=='G'){ //Si el caracter es 'G'
			secc[p]='C'; //Le coloca un caracter 'C' a la secuencia complementaria
		}
		if (sec[e]=='A'){ //Si el caracter es 'A'
			secc[p]='T'; //Le coloca un caracter 'T' a la secuencia complementaria
		}
		if (sec[e]=='T'){ //Si el caracter es 'T'
			secc[p]='A'; //Le coloca un caracter 'A' a la secuencia complementaria
		}
		if (sec[e]=='N'){ //Si el caracter es 'N'
			secc[p]='N'; //Le coloca un caracter 'N' a la secuencia complementaria
		}
		p++; //Avanza a al siguiente posicion
	}	
}
						
