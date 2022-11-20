#include <iostream>
using namespace std;

float GenerarAleatorio()
{
float aleatorio = rand()*1.0/(RAND_MAX - 1);
return aleatorio;
}

int main()
{
char * msj = GenerarAleatorio(); //Genero un puntero char para un valor float
cout << "El valor generado es " << msj << endl; //En este caso se mostrara la direccion del puntero y no el valor guardado
return 0;
}
