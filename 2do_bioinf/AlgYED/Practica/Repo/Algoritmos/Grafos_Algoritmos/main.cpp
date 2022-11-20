#include <QCoreApplication>

#include <iostream>

#include "../../EstructurasDeDatos/Grafo/utiles_grafos.h"

#include "grafos_algoritmos.h"

using namespace std;

void cargar_grafo(Grafo<int> &pG);

void test_grafo_recorrido_DFS();
void test_digrafo_recorrido_DFS();
void test_grafo_recorrido_BFS();
void test_digrafo_recorrido_BFS();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // ************* Recorridos DFS y BFS *************
    //test_grafo_recorrido_DFS();
    //test_digrafo_recorrido_DFS();

    //test_grafo_recorrido_BFS();
    test_digrafo_recorrido_BFS();
    // ************************************************

    cout << "Fin de la prueba..." << endl;

    return a.exec();
}

void cargar_grafo(Grafo<int> &pG) {
    Grafo<int> &g = pG;

    g.agregarNodo(0);
    g.agregarNodo(1);
    g.agregarNodo(2);
    g.agregarNodo(3);
    g.agregarNodo(4);
    g.agregarNodo(5);
    g.agregarNodo(6);
    g.agregarNodo(7);
    g.agregarNodo(8);
    g.agregarNodo(10); // nodo aislado
    g.agregarNodo(9);

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
    g.agregarArco(4, 8);
    g.agregarArco(4, 9);
    g.agregarArco(6, 0);

    cout << g << endl;
    cout << "Orden de g: " << g.getOrden() << endl << endl;
    cout << "Grado de g: " << g.getGrado() << endl << endl;
    cout << "Cantidad de arcos de g: " << g.getCantArcos() << endl << endl;
}

void cargar_digrafo(Digrafo<int> &pG) {
    Digrafo<int> &g = pG;

    for(unsigned int i=1;i<12;i++)
        g.agregarNodo(i);

    g.agregarArco(1, 4);
    g.agregarArco(1, 7);
    g.agregarArco(2, 1);
    g.agregarArco(3, 1);
    g.agregarArco(3, 2);
    g.agregarArco(3, 5);
    g.agregarArco(5, 6);
    g.agregarArco(5, 2);
    g.agregarArco(5, 8);
    g.agregarArco(6, 3);
    g.agregarArco(6, 9);
    g.agregarArco(7, 4);
    g.agregarArco(7, 6);
    g.agregarArco(7, 10);
    g.agregarArco(8, 9);
    g.agregarArco(8, 11);
    g.agregarArco(9, 5);
    g.agregarArco(10, 9);
    g.agregarArco(11, 10);

    cout << g << endl;
    cout << "Orden de g: " << g.getOrden() << endl << endl;
    cout << "Grado de g: " << g.getGrado() << endl << endl;
    cout << "Cantidad de arcos de g: " << g.getCantArcos() << endl << endl;
}

void test_grafo_recorrido_DFS() {
    // se carga un grafo
    Grafo<int> g;   // no dirigido

    cargar_grafo(g);

    string dir = "../Grafos_Algoritmos/img/";
    string nom = "grafo_1";
    imprimirYMostrarImagenGrafo(dir, nom, g);

    // -------- recorrido en profundidad 1 --------
    int inicial = 0;
    vector<int> recorrido = recorrerEnProfundidad( g, inicial );
    cout << "Recorrido en profundidad desde " << inicial << ": \n\t";
    copy(recorrido.begin(), recorrido.end(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;
    imprimirYMostrarRecorridosDFSyBFS(dir, nom + "_inicial_" + to_string(inicial), g, recorrido);
    // ------------------------------------------

    // -------- recorrido en profundidad 2 --------
    inicial = 7;
    recorrido = recorrerEnProfundidad( g, inicial );
    cout << "Recorrido en profundidad desde " << inicial << ": \n\t";
    copy(recorrido.begin(), recorrido.end(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;
    imprimirYMostrarRecorridosDFSyBFS(dir, nom + "_inicial_" + to_string(inicial), g, recorrido);
    // ------------------------------------------
}

void test_digrafo_recorrido_DFS() {
    // se carga un grafo
    Digrafo<int> g;   // no dirigido

    cargar_digrafo(g);

    string dir = "../Grafos_Algoritmos/img/";
    string nom = "digrafo_1";
    imprimirYMostrarImagenGrafo(dir, nom, g);

    // -------- recorrido en profundidad 1 --------
    int inicial = 4;
    vector<int> recorrido = recorrerEnProfundidad( g, inicial );
    cout << "Recorrido en profundidad desde " << inicial << ": \n\t";
    copy(recorrido.begin(), recorrido.end(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;
    imprimirYMostrarRecorridosDFSyBFS(dir, nom + "_inicial_" + to_string(inicial), g, recorrido);
    // --------------------------------------------
    // -------- recorrido en profundidad 2 --------
    inicial = 10;
    recorrido = recorrerEnProfundidad( g, inicial );
    cout << "Recorrido en profundidad desde " << inicial << ": \n\t";
    copy(recorrido.begin(), recorrido.end(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;
    imprimirYMostrarRecorridosDFSyBFS(dir, nom + "_inicial_" + to_string(inicial), g, recorrido);
    // ------------------------------------------
}

void test_grafo_recorrido_BFS() {
    // se carga un grafo
    Grafo<int> g;   // no dirigido

    cargar_grafo(g);

    string dir = "../Grafos_Algoritmos/img/";
    string nom = "grafo_1";
    imprimirYMostrarImagenGrafo(dir, nom, g);

    // -------- recorrido en anchura 1 --------
    int inicial = 10;
    vector<int> recorrido = recorrerEnAnchura( g, inicial );
    cout << "Recorrido en anchura desde " << inicial << ": \n\t";
    copy(recorrido.begin(), recorrido.end(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;
    imprimirYMostrarRecorridosDFSyBFS(dir, nom + "_inicial_" + to_string(inicial), g, recorrido);
    // ------------------------------------------

    // -------- recorrido en profundidad 2 --------
    inicial = 7;
    recorrido = recorrerEnAnchura( g, inicial );
    cout << "Recorrido en anchura desde " << inicial << ": \n\t";
    copy(recorrido.begin(), recorrido.end(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;
    imprimirYMostrarRecorridosDFSyBFS(dir, nom + "_inicial_" + to_string(inicial), g, recorrido);
    // ------------------------------------------
}

void test_digrafo_recorrido_BFS() {
    // se carga un grafo
    Digrafo<int> g;   // no dirigido

    cargar_digrafo(g);

    string dir = "../Grafos_Algoritmos/img/";
    string nom = "digrafo_1";
    imprimirYMostrarImagenGrafo(dir, nom, g);

    // -------- recorrido en anchura 1 --------
    int inicial = 4;
    vector<int> recorrido = recorrerEnAnchura( g, inicial );
    cout << "Recorrido en anchura desde " << inicial << ": \n\t";
    copy(recorrido.begin(), recorrido.end(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;
    imprimirYMostrarRecorridosDFSyBFS(dir, nom + "_inicial_" + to_string(inicial), g, recorrido);
    // --------------------------------------------
    // -------- recorrido en anchura 2 --------
    inicial = 9;
    recorrido = recorrerEnAnchura( g, inicial );
    cout << "Recorrido en anchura desde " << inicial << ": \n\t";
    copy(recorrido.begin(), recorrido.end(), ostream_iterator<int>(cout, " "));
    cout << endl << endl;
    imprimirYMostrarRecorridosDFSyBFS(dir, nom + "_inicial_" + to_string(inicial), g, recorrido);
    // ------------------------------------------
}

