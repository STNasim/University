#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
	
	int x,z; //Variables auxiliares
	z=x=0; //Se inician las variables en 0 para evitar contenido basura
	int C,G,A,T,Tm; //Variables para el cálculo
	int TATA; //Variable para contabilizar las cajas TATA
	C=G=A=T=TATA=Tm=0; //Se inician las variables en 0 para evitar contenido basura
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
		if (x==3){ //Si el numero es 3
			sec[b]='T'; //Se le asigna al valor b de la secuencia, la letra T
		}
		cout<<sec[b]; //Comando para ver la secuencia generada, por pantalla
	}
	
	
	cout<<endl<<"Ingrese la posicion de la secuencia para comenzar "; //Se pide ingresar el dato para comenzar"
	cin>>z; //Se lee la posición de la secuencia donde se debe empezar a calcular
	while (z<1 or z>4981){ //Si el usuario ingresa un valor invalido
		cout<<"Valor invalido, ingrese nuevamente el valor "; //se le notificara
		cin>>z; //y pedira que ingrese un nuevo valor hasta que este sea valido
	}
	
	for(int c=0;c<20;c++){ //Este proceso se repite 20 veces
		if (sec[z+c-1]=='C') //Si la base en la posición es 'C'
		C++; //Se le suma 1 a C
		if (sec[z+c-1]=='G') //Si la base en la posición es 'G'
		G++; //Se le suma 1 a G
		if (sec[z+c-1]=='A') //Si la base en la posición es 'A'
		A++; //Se le suma 1 a A
		if (sec[z+c-1]=='T') //Si la base en la posición es 'T'
		T++; //Se le suma 1 a T
	}

	Tm=((4*(G+C))+(2*(A+T))); //Cálculo de Melting Temperature
	
	cout<<"El resultado de la formula de Melting Temperature es: "<<Tm; //Mostrando resultado en pantalla
	
	for (int d=0;d<5000;d++){ //Ciclo para repetir las acciones hasta el ultimo valor de la secuencia
		if (sec[d]=='T' and sec[d+1]=='A' and sec[d+2]=='T' and sec[d+3]=='A'){ //Si se cumple que una continuación de bases es TATA
			d=d+3; //Se saltan hasta el final de la caja
			TATA++; //y se suma 1 al contador de cajas TATA
		}
	}
	cout<<endl<<endl<<"La cantidad de cajas TATA en la secuencia es de: "<<TATA<<endl;
	
	cout<<endl<<"La reversa complementaria de la secuencia es:"<<endl;
	for (int e=4999;e>-1;e--){ //Ciclo que comienza en el final de la secuencia, y termina en el inicio
		if (sec[e]=='C') //Si el caracter es 'C'
			cout<<'G'; //Se muestra una 'G' en pantalla
		if (sec[e]=='G') //Si el caracter es 'G'
			cout<<'C'; //Se muestra una 'C' en pantalla
		if (sec[e]=='A') //Si el caracter es 'A'
			cout<<'T'; //Se muestra una 'T' en pantalla
		if (sec[e]=='T') //Si el caracter es 'T'
			cout<<'A'; //Se muestra una 'A' en pantalla
	}

	return 0;
}
