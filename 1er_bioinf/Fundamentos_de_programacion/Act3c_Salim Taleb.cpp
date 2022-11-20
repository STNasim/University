#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

struct isla{ //El struct servira para almacenar los datos de cada isla encontrada
	int pos; //Variable donde se guarda la posicion
	int tam; //Variable donde se guarda el tamaño
	float rel; //Variable donde se guarda la relacion de la isla con la cadena
};

void RelacionCG (char sec[],isla i[],int z); //Prototipo de la funcion RelacionCG

int main(int argc, char *argv[]) {
	string se,l; //Se declaran 2 string para extraer los datos
	ifstream op; //Se declara un archivo logico para abrir el archivo con los datos
	int n,y; //La variable n es auxiliar y la variable y almacenara la cantidad de islas CpG
	n=y=0;
	int z; //La variable z sera el tamaño total de la cadena
	op.open ("FragmentoCromo1.fasta");
		
	while (getline(op, l)) //Se copia la informacion del archivo fisico a un string
		se += l; //Se copia la informacion del string l al se y se desplaza 1 lugar
	
	char * sec = new char [se.length()+1]; //Se declara un cstring con un tamaño equivalente al string de la cadena mas uno espacio para el \0
	std::strcpy (sec, se.c_str()); //Se copia el contenido del string al cstring
	z=se.length()-1;
	
	for (int x=0;x<z;x++){ //Ciclo para repetir las acciones hasta el ultimo valor de la secuencia
		while (sec[x]=='C' or sec[x]=='G'){ //Este while describe que, si el valor analizado 
			x++;                            //de la secuencia es 'C' o 'G' se le suma 1 a la 
			n++;                            //variable n y se analiza la siguiente base
		}
		if (n>=4){ //Si la variable n es mayor o igual a 4, es decir, que hay 4 o más
			y++; //Se suma uno a la cantidad de islas CpG
		}
		n=0;
	}
	isla *res= new isla [y]; //Se declara un cstring con el tamaño de la cantidad total de islas CpG
	RelacionCG (sec,res,z); //Llamado de la funcion RelacionCG
		
	for (int t=0;t<y;t++){ //Se muetran los resultados
		cout<<"Isla: "<<t+1<<endl<<"Posicion: "<<res[t].pos<<endl<<"Tamaño: "<<res[t].tam<<endl<<"Relacion: "<<res[t].rel<<'%'<<endl<<endl;
	}
	delete [] res; //Se devuelve la memoria que se presto
	op.close(); //Se cierra el archivo
	return 0;
}

void RelacionCG (char sec[], isla res[],int z){ //implementacion de la funcion RelacionCG
	int m=0;
	int n=0;
	for (int x=0;x<z;x++){ //Ciclo para repetir las acciones hasta el ultimo valor de la secuencia
		while (sec[x]=='C' or sec[x]=='G'){ //Este while describe que, si el valor analizado 
			x++;                            //de la secuencia es 'C' o 'G' se le suma 1 a la 
			n++;                            //variable n y se analiza la siguiente base
		}
		if (n>=4){ //Si la variable n es mayor o igual a 4, es decir, que hay 4 o más C o G
			res[m].pos=x-n+1;//Se asigna la posicion que viene dada por el lugar donde esta la primer base, menos el largo, mas uno
			res[m].tam=n; //Se asigna el tamaño
			res[m].rel=((n/(float) z)*100); //Se asigna la relacion con respecto al tamaño de la cadena
			m++;
		}
		n=0; //Se reinicia la variable a 0
	}
}

