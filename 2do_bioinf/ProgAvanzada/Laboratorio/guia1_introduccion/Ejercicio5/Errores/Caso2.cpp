#include <iostream>
using namespace std;
void Mayor(int a, int b) //La funcion es void por lo que no devolvera el dato
{
int m = a;
if(b > a) m = b;
return m;
}

int main()
{
int mayor;
//No se inicializaron las variables a y b
cout << "Ingrese dos números:" << endl;
cin >> a >> b;

mayor = Mayor(a, b);

cout << "El mayor es " << mayor << endl;
return 0;
}
