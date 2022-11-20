#ifndef UTILES_GRAFOS_H
#define UTILES_GRAFOS_H

#include <fstream>
#include <string>
//#include <cstdlib>

#include "grafo.h"

using namespace std;

void escribirOpciones(ostream &pOut) {
    pOut << " layout=neato; " << endl; // "dot", "neato", "fdp", "twopi", "circo"
    pOut << " overlap=false; " << endl;
    pOut << " splines=true; " << endl;

    // colores de nodos y arcos por defecto
    pOut << "node [color = black];" << endl;
    pOut << "edge [color = blue];" << endl;
}

void escribirOpcionesPonderados(ostream &pOut) {
    pOut << " layout=circo; " << endl; // "dot", "neato", "fdp", "twopi", "circo"
    pOut << " overlap=false; " << endl;
    pOut << " splines=false; " << endl; // curved
    //archivo << "splines = ortho;" << endl;
    //archivo << "overlap = scale;" << endl; // opción adicional para ver pesos

    // colores de nodos y arcos por defecto
    pOut << "node [color = black];" << endl;
    pOut << "edge [color = blue];" << endl;
}

void generarImagenYMostrar(string pScript, string pNomImagen) {
    string comando;
    comando += "dot -Tpng " + pScript + " -o " + pNomImagen; // producir la imagen:
    comando += "& \"" + pNomImagen + "\"";                  // mostrar la imagen
    system( comando.c_str() );
}

template<class T>
void imprimirYMostrarImagenGrafo(string dir, string nombre_sin_extension,
                                 BaseGrafo<T>& pGrafo)   // dir de la forma: "../<NombreProyecto>/";
{
    if( NO_DIRIGIDO == pGrafo.getTipoGrafo() ) {
        string nom = nombre_sin_extension; // sin extensión
        string script = dir + nom + ".txt";
        string imagen = dir + nom + ".png";

        vector<T> nodos = pGrafo.getNodos();
        vector<pair<T,T>> arcos = pGrafo.getArcos();

        ofstream archivo( script.c_str() );
        archivo << "graph G {" << endl;
        escribirOpciones( archivo );

        // se colocan nodos
        for( auto& nodo : nodos )
            archivo << nodo << ";" << endl;

        // se colocan arcos
        for( auto& arco : arcos )
            archivo << arco.first << " -- " << arco.second << endl;

        archivo << "}" << endl;

        archivo.close();

        generarImagenYMostrar(script, imagen);
    }

    if( DIRIGIDO == pGrafo.getTipoGrafo() ) {
        string nom = nombre_sin_extension; // sin extensión
        string script = dir + nom + ".txt";
        string imagen = dir + nom + ".png";

        vector<T> nodos = pGrafo.getNodos();
        vector<pair<T,T>> arcos = pGrafo.getArcos();

        ofstream archivo( script.c_str() );

        archivo << "digraph G {" << endl;
        escribirOpciones( archivo );

        // se colocan nodos
        for( auto& nodo : nodos )
            archivo << nodo << ";" << endl;

        // se colocan arcos
        for( auto& arco : arcos )
            archivo << arco.first << " -> " << arco.second << endl;

        archivo << "}" << endl;

        archivo.close();

        generarImagenYMostrar(script, imagen);
    }
}

template<class T>
void imprimirYMostrarRecorridosDFSyBFS(string dir, string nombre_sin_extension,
                                       BaseGrafo<T>& pGrafo, vector<T> &recorrido)   // dir de la forma: "../<NombreProyecto>/";
{
    string nom = nombre_sin_extension; // sin extensión
    string script = dir + nom + ".txt";
    string imagen = dir + nom + ".png";

    vector<T> nodos = pGrafo.getNodos();
    vector<pair<T,T>> arcos = pGrafo.getArcos();

    ofstream archivo( script.c_str() );

    if( DIRIGIDO == pGrafo.getTipoGrafo() ) {
        archivo << "digraph G {" << endl;
        escribirOpciones( archivo );

        // se colocan nodos
        for( auto& nodo : nodos ) {
            auto it = find(recorrido.begin(), recorrido.end(), nodo );
            if( it == recorrido.end() )
                archivo << nodo << endl;
            else
                archivo << nodo
                        << "[xlabel = \"" << it - recorrido.begin() + 1
                        << "\", color = red];" << endl;
        }

        // se colocan arcos
        for( auto& arco : arcos ) {
            if( find(recorrido.begin(), recorrido.end(), arco.first ) == recorrido.end() )
                archivo << arco.first << " -> " << arco.second << endl;
            else
                archivo << arco.first << " -> " << arco.second
                        << "[color = \"red:blue\"];" << endl;
        }
    }

    if( NO_DIRIGIDO == pGrafo.getTipoGrafo() ) {
        archivo << "graph G {" << endl;
        escribirOpciones( archivo );

        // se colocan nodos
        for( auto& nodo : nodos ) {
            auto it = find(recorrido.begin(), recorrido.end(), nodo );
            if( it == recorrido.end() )
                archivo << nodo << endl;
            else
                archivo << nodo
                        << "[xlabel = \"" << it - recorrido.begin() + 1
                        << "\", color = red];" << endl;
        }

        // se colocan arcos
        for( auto& arco : arcos ) {
            if( find(recorrido.begin(), recorrido.end(), arco.first ) == recorrido.end() )
                archivo << arco.first << " -- " << arco.second << endl;
            else
                archivo << arco.first << " -- " << arco.second
                        << "[color = \"red:blue\"];" << endl;
        }
    }

    archivo << "}" << endl;

    archivo.close();

    generarImagenYMostrar(script, imagen);
}

template<class T>
void imprimirYMostrarImagenGrafoPonderado(string dir, string nombre_sin_extension,
                                          BaseGrafo<T>& pGrafo)   // dir de la forma: "../<NombreProyecto>/";
{
    if( NO_DIRIGIDO == pGrafo.getTipoGrafo() ) {
        string nom = nombre_sin_extension; // sin extensión
        string script = dir + nom + ".txt";
        string imagen = dir + nom + ".png";

        vector<T> nodos = pGrafo.getNodos();
        vector<pair<T,T>> arcos = pGrafo.getArcos();

        ofstream archivo( script.c_str() );

        archivo << "graph G {" << endl;
        escribirOpcionesPonderados( archivo );

        // se colocan nodos
        for( auto& nodo : nodos )
            archivo << nodo << ";" << endl;

        // se colocan arcos
        for( auto& arco : arcos )
            archivo << arco.first << " -- " << arco.second
                    << "[label = \"" << pGrafo.getPesoArco( arco.first, arco.second ) << "\"]"<< endl;

        archivo << "}" << endl;

        archivo.close();

        generarImagenYMostrar(script, imagen);
    }

    if( DIRIGIDO == pGrafo.getTipoGrafo() ) {
        string nom = nombre_sin_extension; // sin extensión
        string script = dir + nom + ".txt";
        string imagen = dir + nom + ".png";

        vector<T> nodos = pGrafo.getNodos();
        vector<pair<T,T>> arcos = pGrafo.getArcos();

        ofstream archivo( script.c_str() );

        archivo << "digraph G {" << endl;
        escribirOpcionesPonderados( archivo );

        // se colocan nodos
        for( auto& nodo : nodos )
            archivo << nodo << ";" << endl;

        // se colocan arcos
        for( auto& arco : arcos )
            archivo << arco.first << " -> " << arco.second
                    << "[label = \"" << pGrafo.getPesoArco( arco.first, arco.second ) << "\"]"<< endl;

        archivo << "}" << endl;

        archivo.close();

        generarImagenYMostrar(script, imagen);
    }
}

#endif // UTILES_GRAFOS_H
