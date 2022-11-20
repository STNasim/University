#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
	
	int x,n; //Variables auxiliares
	n=0; //Se inicia la variable en 0 para evitar contenido basura
	int C,G,A,T; //Variables con las cantidades de bases
	int ICpG; //Variables con la cantidad de Islas CpG
	int PI,TI; //Variables que representan la posición y el tamaño de la mayor Isla CpG
	C=G=A=T=ICpG=PI=TI=0; //Se inician todas las variables en 0 para evitar contenido basura
	float ProC,ProG; //Variables para calcular proporciones
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
	
	
	for (int c=0;c<5000;c++){ //Ciclo para repetir las acciones para los 5000 valores de la secuencia
		if (sec[c]=='C') //Si el caracter es C 
			C++; //Se le suma 1 al valor total de Citosina
		if (sec[c]=='G') //Si el caracter es G
			G++; //Se le suma 1 al valor total de Guanina
		if (sec[c]=='A') //Si el caracter es A
			A++; //Se le suma 1 al valor total de Adenina
		if (sec[c]=='T') //Si el caracter es T
			T++; //Se le suma 1 al valor total de Timina
	}
	
	
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
	
	
	cout<<endl<<"La cantidad de Citosina es: "<<C; //Muestra la cantidad de Citosina por pantalla
	cout<<endl<<"La cantidad de Guanina es: "<<G; //Muestra la cantidad de Guanina por pantalla
	cout<<endl<<"La cantidad de Adenina es: "<<A; //Muestra la cantidad de Adenina por pantalla
	cout<<endl<<"La cantidad de Timina es: "<<T; //Muestra la cantidad de Timina por pantalla
	
	ProC=(float(C*100)/float(C+G+A+T)); //Cálculo de la proporción de Citosina
	cout<<endl<<"La proporcion de Citosina es: "<<ProC<<"%"; //Muestra la proporción de Citosina por pantalla
	ProG=(float(G*100)/float(C+G+A+T)); //Cálculo de la proporción de Guanina
	cout<<endl<<"La proporcion de Guanina es: "<<ProG<<"%"; //Muestra la proporción de Guanina por pantalla
	
	cout<<endl<<"La cantidad de Islas CpG es: "<<ICpG; //Muestra la cantidad de Islas CpG por pantalla
	cout<<endl<<"El tamanio de la mayor Isla CpG es: "<<TI; //Muestra el tamaño de la mayor Isla CpG por pantalla
	cout<<endl<<"La posicion de la mayor Isla CpG es: "<<PI; //Muestra la posición de la mayor Isla CpG por pantalla

 return 0;
}
