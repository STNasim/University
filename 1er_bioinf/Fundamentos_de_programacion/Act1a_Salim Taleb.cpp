#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
	
	int x; //Variable auxiliar
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

	return 0;
}
