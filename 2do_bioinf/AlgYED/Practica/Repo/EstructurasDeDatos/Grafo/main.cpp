#include <QCoreApplication>

#include <iostream>

#include "grafo.h"
#include "digrafo.h"
#include "grafoponderado.h"
#include "digrafoponderado.h"

#include "utiles_grafos.h"

using namespace std;

void test_grafo_template(); // matricial
void test_digrafo_template(); // lista de adyacencias
void test_grafo_ponderado_template();
void test_digrafo_ponderado_template();
void test_digrafo_matriz_template();
void test_grafo_ListaAdyacencias_template();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //    test_grafo_template();
    //    test_grafo_ListaAdyacencias_template();
    //    test_digrafo_template();
          test_digrafo_matriz_template();
    //    test_grafo_ponderado_template();
    //    test_digrafo_ponderado_template();

    cout << "Fin de las pruebas..." << endl;

    return a.exec();
}

void test_grafo_template() { // matricial
    Grafo<int> g;   // no dirigido

    for(unsigned int i=1;i<10;i++)
    {
        g.agregarNodo(i);
        g.agregarArco(i,rand()%i);
    }
    cout << g << endl;
    g.agregarNodo(53);
    cout<< "Agregando nodo 53: "<<endl;
    cout << g << endl;
    g.agregarArco(53,2);
    cout<< "Agregando arco de 53 a 2: "<<endl;
    cout << g << endl;
    g.borrarArco(53,2);
    cout<< "Borrando arco de 53 a 2: "<<endl;
    cout << g << endl;
    g.borrarNodo(53);
    cout<< "Borrando nodo 53: "<<endl;
    cout << g << endl;
    cout<<"Vecinos del nodo 5: ";
    for(auto& val : g.getVecinos(5))
        cout<<val<<", ";
    cout<<endl;
    cout<<"Nodos con arcos que inciden en 5: ";
    for(auto& val : g.getNodosConArcosIncidentes(5))
        cout<<val<<", ";
    cout<<endl;
    cout<<"Orden del grafo: "<<g.getOrden()<<endl;
    cout<<"Grado del grafo: "<<g.getGrado()<<endl;
    cout<<"Numero de arcos del grafo: "<<g.getNumeroArcos();

    string dir = "../Grafo/";
    string nom = "grafo_1";
    imprimirYMostrarImagenGrafo(dir, nom, g); // dir de la forma: "../<NombreProyecto>/";
}

void test_digrafo_matriz_template() {
    Digrafo<int> g(MATRICIAL);

    for(unsigned int i=1;i<10;i++)
    {
        g.agregarNodo(i);
        g.agregarArco(i,rand()%i);
    }
    cout << g << endl;
    g.agregarNodo(53);
    cout<< "Agregando nodo 53: "<<endl;
    cout << g << endl;
    g.agregarArco(53,2);
    cout<< "Agregando arco de 53 a 2: "<<endl;
    cout << g << endl;
    g.borrarArco(53,2);
    cout<< "Borrando arco de 53 a 2: "<<endl;
    cout << g << endl;
    g.borrarNodo(53);
    cout<< "Borrando nodo 53: "<<endl;
    cout << g << endl;
    cout<<"Vecinos del nodo 5: ";
    for(auto& val : g.getVecinos(5))
        cout<<val<<", ";
    cout<<endl;
    cout<<"Nodos con arcos que inciden en 5: ";
    for(auto& val : g.getNodosConArcosIncidentes(5))
        cout<<val<<", ";
    cout<<endl;
    cout<<"Orden del grafo: "<<g.getOrden()<<endl;
    cout<<"Grado del grafo: "<<g.getGrado()<<endl;
    cout<<"Numero de arcos del grafo: "<<g.getNumeroArcos();

    string dir = "../Grafo/";
    string nom = "grafo_1";
    imprimirYMostrarImagenGrafo(dir, nom, g); // dir de la forma: "../<NombreProyecto>/";
}

void test_grafo_ListaAdyacencias_template() {
    Grafo<int> g(LISTA_ADYACENCIAS);

    for(unsigned int i=1;i<10;i++)
    {
        g.agregarNodo(i);
        g.agregarArco(i,rand()%i);
    }
    cout << g << endl;
    g.agregarNodo(53);
    cout<< "Agregando nodo 53: "<<endl;
    cout << g << endl;
    g.agregarArco(53,2);
    cout<< "Agregando arco de 53 a 2: "<<endl;
    cout << g << endl;
    g.borrarArco(53,2);
    cout<< "Borrando arco de 53 a 2: "<<endl;
    cout << g << endl;
    g.borrarNodo(53);
    cout<< "Borrando nodo 53: "<<endl;
    cout << g << endl;
    cout<<"Vecinos del nodo 5: ";
    for(auto& val : g.getVecinos(5))
        cout<<val<<", ";
    cout<<endl;
    cout<<"Nodos con arcos que inciden en 5: ";
    for(auto& val : g.getNodosConArcosIncidentes(5))
        cout<<val<<", ";
    cout<<endl;
    cout<<"Orden del grafo: "<<g.getOrden()<<endl;
    cout<<"Grado del grafo: "<<g.getGrado()<<endl;
    cout<<"Numero de arcos del grafo: "<<g.getNumeroArcos();

    string dir = "../Grafo/";
    string nom = "grafo_1";
    imprimirYMostrarImagenGrafo(dir, nom, g); // dir de la forma: "../<NombreProyecto>/";
}

void test_digrafo_template() {
    Digrafo<int> g;
    string dir = "../Grafo/img/";

    g.agregarNodo(10);
    g.agregarNodo(5);
    g.agregarNodo(12);
    g.agregarNodo(8);
    g.agregarNodo(9);

    g.agregarArco(10, 5);
    g.agregarArco(10, 12);
    g.agregarArco(5, 12);
    g.agregarArco(5, 8);
    g.agregarArco(8, 9);

    g.agregarArco(12, 12); // bucle

    g.agregarNodo(6); // nodo aislado

    cout << g << endl;

    cout << "Orden de g: " << g.getOrden() << endl << endl;
    cout << "Cantidad de arcos de g: " << g.getCantArcos() << endl << endl;

    imprimirYMostrarImagenGrafo(dir, "digrafo_1", g);

    cout << endl << endl
         << "Se borran nodos y arcos..." << endl << endl;

    // g.borrarArco(5, 8);
    g.borrarArco(12, 12);

    cout << g << endl;

    imprimirYMostrarImagenGrafo(dir, "digrafo_2", g);

    // g.borrarNodo(10);
    g.borrarNodo(12);

    cout << g << endl;

    cout << "Orden de g: " << g.getOrden() << endl << endl;
    cout << "Cantidad de arcos de g: " << g.getCantArcos() << endl << endl;

    imprimirYMostrarImagenGrafo(dir, "digrafo_3", g);

    g.limpiar(); // borra todos los nodos.

    g.agregarNodo(0);
    g.agregarNodo(1);
    g.agregarNodo(2);
    g.agregarNodo(3);
    g.agregarNodo(4);
    g.agregarNodo(5);
    g.agregarNodo(6);
    g.agregarNodo(7);
    g.agregarArco(0, 2);
    g.agregarArco(1, 2);
    g.agregarArco(1, 3);
    g.agregarArco(1, 5);
    g.agregarArco(1, 6);
    g.agregarArco(2, 4);
    g.agregarArco(2, 5);
    g.agregarArco(2, 6);
    g.agregarArco(3, 7);
    g.agregarArco(4, 6);
    g.agregarArco(5, 6);

    cout << g << endl;
    cout << "Orden de g: " << g.getOrden() << endl << endl;
    cout << "Grado de g: " << g.getGrado() << endl << endl;
    cout << "Grado Entrada y Salida de nodo 0: "
         << g.getGradoEntradaNodo(0) << "(entrada), "
         << g.getGradoSalidaNodo(0) << "(salida)" << endl << endl;
    cout << "Grado Entrada y Salida de nodo 1: "
         << g.getGradoEntradaNodo(1) << "(entrada), "
         << g.getGradoSalidaNodo(1) << "(salida)" << endl << endl;
    cout << "Grado Entrada y Salida de nodo 3: "
         << g.getGradoEntradaNodo(3) << "(entrada), "
         << g.getGradoSalidaNodo(3) << "(salida)" << endl << endl;
    cout << "Cantidad de arcos de g: " << g.getCantArcos() << endl << endl;

    imprimirYMostrarImagenGrafo(dir, "digrafo_4", g);

    // -------- vecinos 1 --------
    int nodo = 1;
    vector<int> vecinos = g.getVecinos( nodo );
    cout << "Vecinos del nodo " << nodo << ": \n\t";
    copy(vecinos.begin(), vecinos.end(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;
    // ----------------------------
    // -------- vecinos 2 --------
    nodo = 2;
    vecinos = g.getVecinos( nodo );
    cout << "Vecinos del nodo " << nodo << ": \n\t";
    copy(vecinos.begin(), vecinos.end(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;
    //    // ----------------------------

    //        // -------- arcos incidentes a un nodo 1 --------
    //        nodo = 1;
    //        vector<pair<int,int>> arcosIncidentes = g.getArcosIncidentes( nodo );
    //        cout << "Arcos incidentes del nodo " << nodo << ": \n\t";
    //        for( auto arco : arcosIncidentes )
    //            cout << arco << ", " << ends;
    //        cout << endl << endl;
    //        // ----------------------------------------------
    //        // -------- arcos incidentes a un nodo 2 --------
    //        nodo = 2;
    //        arcosIncidentes = g.getArcosIncidentes( nodo );
    //        cout << "Arcos incidentes del nodo " << nodo << ": \n\t";
    //        for( auto arco : arcosIncidentes )
    //            cout << arco << ", " << ends;
    //        cout << endl << endl;
    //        // ----------------------------------------------
}

void cargar_grafo_ponderado_template(GrafoPonderado<int> &pG) {
    GrafoPonderado<int> &g = pG;

    g.agregarNodo(1);
    g.agregarNodo(2);
    g.agregarNodo(3);
    g.agregarNodo(4);
    g.agregarNodo(5);

    g.agregarArco(1, 2, 10);
    g.agregarArco(1, 4, 5);
    g.agregarArco(2, 3, 1);
    g.agregarArco(2, 4, 2);
    g.agregarArco(3, 5, 4);
    g.agregarArco(4, 3, 9);
    g.agregarArco(4, 5, 2);
    g.agregarArco(5, 1, 7);

    cout << g << endl;
    cout << "Orden de g: " << g.getOrden() << endl << endl;
    cout << "Grado de g: " << g.getGrado() << endl << endl;
    cout << "Cantidad de arcos de g: " << g.getCantArcos() << endl << endl;
}

void test_grafo_ponderado_template() {
    GrafoPonderado<int> g;
    cargar_grafo_ponderado_template(g);

    // test borrado de un arco
    g.agregarArco(2, 5, 99);
    g.borrarArco(5, 2); // arcos 1->5 y 5->1 son equivalentes en un grafo no dirigido.

    // test borrado de un nodo
    g.agregarNodo(99);
    g.agregarArco(1, 99, 99);
    g.agregarArco(99, 5, 99);
    g.borrarNodo(99);

    string dir = "../Grafo/img/";
    string nom = "grafo_ponderado";
    imprimirYMostrarImagenGrafoPonderado(dir, nom, g);
}

void cargar_digrafo_ponderado_template(DigrafoPonderado<int> &pG) {
    DigrafoPonderado<int> &g = pG;

    g.agregarNodo(1);
    g.agregarNodo(2);
    g.agregarNodo(3);
    g.agregarNodo(4);
    g.agregarNodo(5);

    g.agregarArco(1, 2, 10);
    g.agregarArco(1, 4, 5);
    g.agregarArco(2, 3);    // por defecto, peso 1.
    g.agregarArco(2, 4, 2);
    g.agregarArco(3, 5, 4);
    g.agregarArco(4, 2, 3);
    g.agregarArco(4, 3, 9);
    g.agregarArco(4, 5, 2);
    g.agregarArco(5, 1, 7);
    g.agregarArco(5, 3, 6);

    cout << g << endl;

    cout << "Orden de g: " << g.getOrden() << endl << endl;
    cout << "Grado de g: " << g.getGrado() << endl << endl;
    cout << "Cantidad de arcos de g: " << g.getCantArcos() << endl << endl;
}

void test_digrafo_ponderado_template() {
    DigrafoPonderado<int> g;
    cargar_digrafo_ponderado_template(g);

    // test borrado de un arco
    g.agregarArco(1, 5, 99);
    g.borrarArco(1, 5);

    // test borrado de un nodo
    g.agregarNodo(99);
    g.agregarArco(1, 99, 99);
    g.agregarArco(99, 5, 99);
    g.borrarNodo(99);

    string dir = "../Grafo/img/";
    string nom = "digrafo_ponderado";
    imprimirYMostrarImagenGrafoPonderado(dir, nom, g);
}


