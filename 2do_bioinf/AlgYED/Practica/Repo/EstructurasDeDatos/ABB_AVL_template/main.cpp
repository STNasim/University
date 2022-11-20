#include <QCoreApplication>

#include <iostream>
#include <string>
#include <ctime>
#include <random>
// ##############################################################
// ##############################################################
//    El bloque para la clase "Punto" podría estar en un archivo "punto.h" para ordenar el código.
//    Lo central es que la definición de la función "std::to_string()" se encuentre
//    ANTES de incluir el archivo "abb_avl_template.h" (que es donde se utiliza).
class Punto{
public:
    float x, y;
    float mod() { return x*x+y*y; } //para acortar código
    //bool operator<(Punto pP) { return (x*x+y*y) < (pP.x*pP.x+pP.y*pP.y); }
};
// Se codificaron sobrecargas globales para evitar inconvenientes con "const".
bool operator<(Punto pA, Punto pB) { return pA.mod() < pB.mod(); }
bool operator>(Punto pA, Punto pB) { return pA.mod() > pB.mod(); }
// ##############################################################
// ##############################################################

// ##############################################################
// El siguiente bloque resuelve el "problema" de utilizar el std::to_string(...)
// con un tipo de dato creado por el programador. Notar que el código de la función
// se escribe DENTRO del espacio de nombre STD. Eso es todo :)
// ##############################################################
namespace std {
string to_string(Punto c){
    string cad;
    cad += "( " + to_string(c.x) + ", " + to_string(c.y) + " )";
    return cad;
}
}
// ##############################################################
// ##############################################################

#include "abb_avl_template.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try {
        using namespace abb_avl_template;

        ABB_AVL<int> abb;

        abb.agregar(15);
        abb.agregar(10);
        abb.agregar(6);
        abb.agregar(30);
        abb.agregar(20);
        abb.agregar(50);

        // Imprimir el árbol
        cout << endl << endl;
        cout << abb;
        cout << endl << endl;
        cout << "Cantidad de elementos: " << abb.size() << endl;
        cout << endl << endl;

        cout << "Altura del abb: " << abb.getAltura() << endl;

        // Borrado, caso por caso
        cout << "Borrado de elementos... Primero agregamos algunos nodos" << endl;

        abb.agregar(90);
        abb.agregar(100);
        abb.agregar(2);
        abb.agregar(7);
        abb.agregar(18);
        abb.agregar(13);
        abb.agregar(9);

        cout << "ABB:" << endl << abb << endl << endl;

        cout << "Se borra un nodo hoja: 100" << endl;
        abb.borrar(100);
        cout << "ABB:" << endl << abb << endl << endl;

        cout << "Se borra un nodo hoja: 2" << endl;
        abb.borrar(2);
        cout << "ABB:" << endl << abb << endl << endl;

        cout << "Se borra un nodo con un descendiente derecho: 50" << endl;
        abb.borrar(50);
        cout << "ABB:" << endl << abb << endl << endl;

        cout << "Se borra un nodo con un descendiente izquierdo: 20" << endl;
        abb.borrar(20);
        cout << "ABB:" << endl << abb << endl << endl;

        cout << "Borrado de elementos con DOS descendientes... primero agregamos otros nodos:" << endl;
        abb.agregar(22);
        abb.agregar(26);
        abb.agregar(16);
        abb.agregar(20);
        abb.agregar(60);
        abb.agregar(75);
        abb.agregar(45);

        cout << "ABB:" << endl << abb << endl << endl;

        cout << "Se borra un nodo con dos descendientes: 30" << endl;
        abb.borrar(30);
        cout << "ABB:" << endl << abb << endl << endl;
        cout << "Se borra un nodo con dos descendientes: 15" << endl;
        abb.borrar(15);
        cout << "ABB:" << endl << abb << endl << endl;

        cout<<(abb.buscar(15)? "El 15 se encuentra en el ABB":"El 15 NO se encuentra en el ABB")<<endl;

        cout<<(abb.buscar(90)? "El 90 se encuentra en el ABB":"El 90 NO se encuentra en el ABB")<<endl;

        cout<<"Recorrido Pos Orden: ";abb.recorrerPosOrden(cout);
        cout<<endl;

        cout<<"Recorrido Pre Orden: ";abb.recorrerPreOden(cout);
        cout<<endl;

        cout<<"Numero de hojas en el ABB: "<<abb.contarHojas()<<endl;

        cout<<"Numero de nodos intermedios en el ABB: "<<abb.contarNodosIntermedios()<<endl;

        abb.podarAlt();
        cout<<"Arbol tras podar: "<<endl<<abb<<endl;
        cout<<"Arbol 1: "<<endl<<abb<<endl;

        cout<<(abb.lleno()?"El arbol1 es lleno":"El arbol1 no es lleno")<<endl;
        ABB_AVL<int> abb2;
        abb2.agregar(10);
        abb2.agregar(5);
        abb2.agregar(12);
        abb2.agregar(11);
        abb2.agregar(13);
        cout<<"Arbol 2: "<<endl<<abb2<<endl;
        cout<<(abb2.lleno()?"El arbol2 es lleno":"El arbol2 no es lleno")<<endl<<endl;

        cout<<(abb2.completo()?"El arbol2 es completo":"El arbol2 no es completo")<<endl;
        ABB_AVL<int> abb3;
        abb3.agregar(10);
        abb3.agregar(5);
        abb3.agregar(12);
        abb3.agregar(3);
        cout<<"Arbol 3: "<<endl<<abb3<<endl;
        cout<<(abb3.completo()?"El arbol3 es completo":"El arbol3 no es completo")<<endl<<endl;

        cout<<(abb3.perfecto()?"El arbol3 es perfecto":"El arbol3 no es perfecto")<<endl;
        cout<<"Agregando 1 y 6 al arbol2"<<endl;
        abb2.agregar(1);
        abb2.agregar(6);
        cout<<abb2<<endl;
        cout<<(abb2.perfecto()?"El arbol2 es perfecto":"El arbol2 es perfecto")<<endl;

        cout<<"Arbol: "<<endl<<abb<<endl;
        int dato=0;
        unsigned int altura=0;

        abb.hojaMenosProfunda(dato,altura);
        cout<<"La hoja menos profunda tiene altura: "<<altura<<" y el dato es: "<<dato<<endl;

        abb.hojaMasProfunda(dato,altura);
        cout<<"La hoja mas profunda tiene altura: "<<altura<<" y el dato es: "<<dato<<endl;

        cout<<"La diferencia de altura es: "<<abb.diferenciaAltura()<<endl;

        cout<<"El promedio de altura es: "<<abb.promedioAltura()<<endl;

    }
    catch (string mje) {
        cout << "Error: " << mje << endl;
    }
    catch (...) {
        cout << "Error indeterminado..." << endl;
    }

    cout << "Fin de la prueba..." << endl;

    return a.exec();
}
