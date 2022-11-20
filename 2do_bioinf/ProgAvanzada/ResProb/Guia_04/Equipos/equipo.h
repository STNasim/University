#ifndef EQUIPO_H
#define EQUIPO_H
#include <string>
using namespace std;

class Equipo {
public:
   Equipo();
   Equipo(string pNombre, int pNumeroSerie);
   void setNombre( string nuevoNombre );
   string getNombre();
   void setNumeroSerie( int nuevoNumero );
   int getNumeroSerie();
   virtual int getTipo();
   virtual ~Equipo();
private:
   string Nombre;
protected:
   int NumeroSerie;
};

#endif // EQUIPO_H
