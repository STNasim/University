#include <iostream>
using namespace std;

float Cuadrado(float val)
{
return val*val;
}

int main()
{
int c;   //Variable sin usar
float v = 2.4;
float v2 = Cuadrado(); //No se enviaron los parametros a la funcion
cout << v << " al cuadrado es " << v2 << endl;
return 0;
}
