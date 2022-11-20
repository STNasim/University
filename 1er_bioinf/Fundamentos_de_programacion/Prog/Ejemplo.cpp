#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	long tabla [7][12]{0};
	int m,c;
	long x;
	ifstream apor;
	apor.open("APORTES.txt", ios::in);
	if(!apor.is_open()){
		cout<<"El archivo no se encontro";
		return -1;
	}

	while(!apor.eof()){
		apor>>x>>c>>m;
		c--;
		m--;
		tabla [c][m]=x+tabla [c][m];
	}
	for (int z=0;z<7;z++){
		cout<<endl;
		for (int k=0;k<12;k++){
			cout<<tabla[z][k]<<"  ";
		}
	}
	apor.close();
	return 0;
}

