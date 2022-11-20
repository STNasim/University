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

void Cajas (char sec[],int pc [], int z); //Prototipo de la funcion Cajas
void RelacionCG (char sec[],isla i[],int z); //Prototipo de la funcion RelacionCG

int main(int argc, char *argv[]) {
	string se,l; //Se declaran 2 string para extraer los datos
	ifstream op; //Se declara un archivo logico para abrir el archivo con los datos
	ofstream I,III,IV; //Archivos de escritura
	int n,y,TATA; //La variable n es auxiliar, la variable "y" almacenara la cantidad de islas CpG y TATA las cajas TATA
	n=y=TATA=0;
	int z; //La variable z sera el tamaño total de la cadena
	int C,A,T,G; //Variables para contar los nucleotidos
	C=A=T=G=0;
	float ProC,ProG; //Variables para guardar las proporciones
	ProC=ProG=0;
	op.open ("FragmentoCromo1.fasta"); //Se abre el archivo fisico donde estan los datos
		
	while (getline(op, l)) //Se copia la informacion del archivo fisico a un string
		se += l; //Se copia la informacion del string l al se y se desplaza 1 lugar
	
	char * sec = new char [se.length()+1]; //Se declara un cstring con un tamaño equivalente al string de la cadena mas uno espacio para el \0
	std::strcpy (sec, se.c_str()); //Se copia el contenido del string al cstring
	z=se.length()-1; //Se le asigna el valor del tamaño de la cadena menos uno para futuros calculos
	
	for (int d=0;d<z;d++){ //Ciclo para repetir las acciones hasta el ultimo valor de la secuencia
		if (sec[d]=='T' and sec[d+1]=='A' and sec[d+2]=='T' and sec[d+3]=='A'){ //Si se cumple que una continuación de bases es TATA
			d=d+3; //Se saltan hasta el final de la caja
			TATA++; //y se suma 1 al contador de cajas TATA
		}
	}
	int *pc= new int[TATA]; //Se crea el arrreglo dinamico en base al largo de la secuencia
	Cajas(sec,pc,z); //Llamado de la funcion cajas
	
	I.open("Actividad I.txt"); //Se abre el archivo fisico
	for(int h=0;h<TATA;h++){
		I<<"Posicion de la caja "<<h+1<<" es: "<<pc[h]<<endl; //Se guardan los resultados en el archivo
	}
	
	for (int x=0;x<z;x++){ //Ciclo para repetir las acciones hasta el ultimo valor de la secuencia
		while (sec[x]=='C' or sec[x]=='G'){ //Este while describe que, si el valor analizado 
			x++;                            //de la secuencia es 'C' o 'G' se le suma 1 a la 
			n++;                            //variable n y se analiza la siguiente base
		}
		if (n>=4){ //Si la variable n es mayor o igual a 4, es decir, que hay 4 o más C o G
			y++; //Se suma uno a la cantidad de islas CpG
		}
		n=0;
	}
	isla *res= new isla [y]; //Se declara un cstring con el tamaño de la cantidad total de islas CpG
	RelacionCG (sec,res,z); //Llamado de la funcion RelacionCG
	
	III.open("Actividad III.txt"); //Se crea el archivo fisico
	III<<"Posicion		"<<"Tamanio			"<<"Relacion"<<endl;
	for(int g=0;g<y;g++){									//Se guardan los datos en el formato requerido
		III<<res[g].pos<<"			"<<res[g].tam<<"			"<<res[g].rel<<endl;
	}
	
	for (int u=0;u<z;u++){ //Se calculan la cantidad total de cada base
		if (sec[u]=='C')
			C++;
		if (sec[u]=='A')
			A++;
		if (sec[u]=='T')
			T++;
		if (sec[u]=='G')
			G++;
	}
	ProC=(C/(float)z)*100; //Calculos de proporcion
	ProG=(G/(float)z)*100;
	
	IV.open("Actividad IV.txt"); //Se crea el archivo fisico
	IV<<"La cantidad de nucleotidos es: "<<endl<<"G: "<<G<<endl<<"A: "<<A<<endl<<"T: "<<T<<endl; //Se escribe sobre el archivo
	IV<<"La proporcion de nucleotidos es: "<<endl<<"C: "<<ProC<<'%'<<endl<<"G: "<<ProG<<'%';
	
	delete [] res; //Se devuelve la memoria que se presto
	delete [] pc; //Se devuelve la memoria que se presto
	op.close (); //Se cierra el archivo de datos
	I.close (); //Se cierra el archivo I
	III.close (); //Se cierra el archivo II
	IV.close (); //Se cierra el archivo IV
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

void Cajas (char sec[],int pc [], int z){  //Implementacion de la funcion Cajas
	int e=0;
	for (int f=0;f<z;f++){ //Ciclo para repetir las acciones hasta el ultimo valor de la secuencia
		if (sec[f]=='T' and sec[f+1]=='A' and sec[f+2]=='T' and sec[f+3]=='A'){ //Si se cumple que una continuación de bases es TATA
			pc[e]=f; //Se guarda la posicion de la caja en el arreglo pc
			f=f+3; //Se saltan hasta el final de la caja
			e++; //Se pasa a la posicion siguiente
		}
	}
}
