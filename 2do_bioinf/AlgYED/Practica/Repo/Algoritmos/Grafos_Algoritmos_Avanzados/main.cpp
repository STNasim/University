#include <QCoreApplication>
#include <iostream>
#include "../../EstructurasDeDatos/Grafo/utiles_grafos.h"
#include "Grafos_Algoritmos_Avanzados.h"


using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    try
    {

        GrafoPonderado<int> g;

        //TEST DIJKSTRA
            for(unsigned int i=1;i<8;i++)
                g.agregarNodo(i);

            g.agregarArco(1,3,5);
            g.agregarArco(1,4,6);
            g.agregarArco(1,2,5);
            g.agregarArco(3,2,6);
            g.agregarArco(3,5,6);
            g.agregarArco(3,4,10);
            g.agregarArco(3,7,3);
            g.agregarArco(4,7,1);
            g.agregarArco(4,5,5);
            g.agregarArco(4,6,14);
            g.agregarArco(4,6,13);
            g.agregarArco(5,6,9);
            g.agregarArco(5,2,12);
            g.agregarArco(6,2,11);

            string dir = "../Grafos_Algoritmos_Avanzados/img/";
            string nom = "grafo_Dijkstra";
            imprimirYMostrarImagenGrafoPonderado(dir, nom, g);

            vector<pair<int,float>> resultado=Dijkstra(g,7);

            for(auto par : resultado)
                cout<<"Distancia a "<<par.first<<" es "<<par.second<<endl;


        //TEST KRUSKAL
//        for(unsigned int i=1;i<13;i++)
//            g.agregarNodo(i);

//        g.agregarArco(1,2,1);
//        g.agregarArco(1,4,1);
//        g.agregarArco(2,3,1);
//        g.agregarArco(3,7,1);
//        g.agregarArco(4,7,1);
//        g.agregarArco(8,10,1);
//        g.agregarArco(9,11,1);
//        g.agregarArco(9,12,1);
//        g.agregarArco(1,3,2);
//        g.agregarArco(3,5,2);
//        g.agregarArco(11,12,2);
//        g.agregarArco(2,5,3);
//        g.agregarArco(3,4,4);
//        g.agregarArco(10,11,4);
//        g.agregarArco(8,9,5);
//        g.agregarArco(5,6,6);
//        g.agregarArco(6,7,6);

//        string dir = "../Grafos_Algoritmos_Avanzados/img/";
//        string nom = "grafo_preKruskal";
//        imprimirYMostrarImagenGrafoPonderado(dir, nom, g);

//        GrafoPonderado<int> gKruskal=Kruskal(g);
//        nom = "grafo_posKruskal";
//        imprimirYMostrarImagenGrafoPonderado(dir, nom, gKruskal);

    }
    catch (string mje)
    {
        cout << "Error: " << mje << endl;
    }
    catch (...)
    {
        cout << "Error indeterminado..." << endl;
    }
    cout << "Fin de la prueba..." << endl;

    return a.exec();
}
