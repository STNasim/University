#include <QCoreApplication>

#include "abb_rn_template.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try {
        using namespace abb_rn_template;

        ABB_RN<int> abb;

        // Esta secuencia de valores se resuelve correctamente.
        vector<int> valores = {
            50, // Caso base, se inserta nodo raíz
            60, // Se inserta nodo a la derecha
            70, // Se inserta nodo a la derecha
            80, // Se inserta nodo a la derecha
            90, // Se inserta nodo a la derecha
            100, // Se inserta nodo a la derecha
            110, // Se inserta nodo a la derecha
            120, // Se inserta nodo a la derecha
            130, // Se inserta nodo a la derecha
            140,
            150,
        };

        //        cout << "**********************" << endl;
        //        cout << "Altura del arbol: " << abb.getAltura() << endl;
        //        cout << "Altura NEGRA del arbol: " << abb.getAlturaNegra() << endl;
        //        cout << "Se imprime el ABB en preorden:" << endl;
        //        abb.recorrerInOrden( cout );
        //        cout << endl << endl;

        for( unsigned int i = 0; i < valores.size(); ++i ) {
            //            cout << "**********************" << endl;
            cout << "Se agrega el "<< valores[i] <<": " << endl;
            abb.agregar( valores[i] );

            //            cout << "Altura del arbol: " << abb.getAltura() << endl;
            //            cout << "Altura NEGRA del arbol: " << abb.getAlturaNegra() << endl;
            //            cout << "Se imprime el ABB en preorden:" << endl;
            //            abb.recorrerInOrden( cout );
            //            cout << endl << endl;
        }

        cout << endl << endl << abb << endl << endl;

        cout<<"El numero de nodos negros es: "<<abb.getNodosNegros()<<endl;
        cout<<"El numero de nodos rojos es: "<<abb.getNodosRojos()<<endl;
        cout<<"El numero total de nodos es: "<<abb.getNodos()<<endl;

        ABB_RN<int> abb2;

        abb2.agregar(40);
        abb2.agregar(20);
        abb2.agregar(60);
        abb2.agregar(10);
        abb2.agregar(30);
        abb2.agregar(50);
        abb2.agregar(80);

        cout<<"abb2 con "<<abb2.getNodos()<<" elementos: "<<endl<<abb2<<endl;
        cout<<"La cantidad maxima de elementos hasta que no cambie la altura negra es: "
           <<abb2.nodosHastaCambiarAlturaNegra()<<endl;

        cout<<"abb con "<<abb.getNodos()<<" elementos: "<<endl<<abb<<endl;
        cout<<"La cantidad maxima de elementos hasta que no cambie la altura negra es: "
           <<abb.nodosHastaCambiarAlturaNegra()<<endl;
    }
    catch (string mje)  { cout << "Error: " << mje << endl; }
    catch (...)         { cout << "Error indeterminado..." << endl; }

    cout << "Fin de las prueba..." << endl;

    return a.exec();
}
