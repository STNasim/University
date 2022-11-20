#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
using namespace std;

struct paciente{
	char apellido[20];
	char nombres [40];
	char tel[15];
	int DNI;
	char sexo;
	char OS[15];
};

int main(int argc, char *argv[]) {
	paciente x;
	fstream archi;
	
	archi.open("REGISTROS.dat", ios::in | ios::out | ios::binary | ios::ate);
	if (!archi.is_open()){
		cout<<"El archivo no se pudo abrir";
		return -1;
	}
	cout<<"Ingrese nombres ";
	fgets(x.nombres,40,stdin);
	cout<<"Ingrese apellido ";
	cin>>x.apellido;
	cout<<"Ingrese telefono";
	cin>>x.tel;
	cout<<"Ingrese DNI";
	cin>>x.DNI;
	cout<<"Ingrese sexo";
	cin>>x.sexo;
	cout<<"Ingrese OS";
	cin>>x.OS;
	
	archi.write((char*)&x,sizeof(x));
	
	archi.close();
	return 0;
}
