#ifndef ABB_H
#define ABB_H

#include <iostream>
#include <string>

using namespace std;

template<class Q>
class Nodo_ABB{
public:
    Q dato; // dato almacenado en el nodo
    Nodo_ABB *izq, *der; // izq: datos menores, der: datos mayores
    Nodo_ABB(const Q& pDato, Nodo_ABB* pptr_izq = nullptr, Nodo_ABB* pptr_der = nullptr){
        dato = pDato; izq = pptr_izq; der = pptr_der;
    }
    string to_string() { return std::to_string(dato); } // std:: es necesario.
};

template<class T, class Nodo = Nodo_ABB<T>>
class ABB
{
public:
    ABB();
    ~ABB();

    // operaciones para mutar
    void agregar(T pDato);
    void borrar(const T& pDato);

    // operaciones para obtener información
    unsigned int getAltura();
    unsigned int size();
    T getRaiz();
    T getMayor();
    T getMenor();
    unsigned int contarHojas();
    unsigned int contarNodosIntermedios();
    unsigned int getNodos();

    // operaciones para recorrer
    void recorrerPreOden(ostream& out);
    void recorrerInOrden(ostream& out);
    void recorrerPosOrden(ostream& out);
    void recorrerNivel(unsigned int pNivel, ostream& pOut, int pAncho = 4, string pStr_null = "");

    // operaciones adicionales
    void volcarEnFlujo(ostream& pOut);
    void setSepParaVolcarEnFlujo(string pStr_null);
    bool buscar(T pDato);
    bool completarDato(T &pdato);
    void podar();
    void podarAlt();
    bool lleno();
    bool completo();
    unsigned int getAlturaA(T pDato);
    bool perfecto();
    void hojaMenosProfunda(T &dato,unsigned int &altura);
    void hojaMasProfunda(T &dato,unsigned int &altura);
    unsigned int diferenciaAltura();
    float promedioAltura();

protected:
    Nodo* raiz;
    unsigned int N;
    unsigned int getAltura_recursivo( Nodo* pRaiz );

private:
    // métodos privados
    void agregar_recursivo( Nodo*& pptr, const T& pValor );
    // void agregar_recursivo( Nodo*& pptr, T pValor ); <--- menos eficiente.
    Nodo* borrar_recursivo(Nodo *pRaiz, const T& pDato );

    void recorrerPreOrden_recursivo(Nodo *pptr, ostream &pOut);
    void recorrerInOrden_recursivo( Nodo* pptr, ostream& pOut );
    void recorrerPosOrden_recursivo(Nodo *pptr, ostream &pOut);

    void destruir_recursivamente(Nodo*& pptr );


    Nodo* getNodoMayor( Nodo* pRaiz );
    Nodo* getNodoMenor( Nodo* pRaiz );

    void recorrerNivel_recursivo(Nodo* pRaiz, unsigned int pNivel,
                                 ostream& pOut, unsigned int pAncho = 4,
                                 string pSep = "");
    void imprimirCentrado( ostream& pOut, int pAncho, string pCad );
    void contarHojasRecursivo(Nodo *pRaiz,unsigned int &contador);
    void contarNodosIntermediosRecursivo(Nodo *pRaiz,unsigned int &contador);
    void podarRecursivo(Nodo* pRaiz);
    void podarRecursivoAlt(Nodo * pRaiz);
    void llenoRecursivo(Nodo *pRaiz,bool &lleno);
    void completoRecursivo(Nodo *pRaiz,bool &retorno,unsigned int &AlturaAnteriorHoja);
    void hojaMenosProfundaRecursiva(Nodo *pRaiz,T &dato,unsigned int &altura);
    void hojaMasProfundaRecursiva(Nodo *pRaiz,T &dato,unsigned int &altura);
    void promedioAlturaRecursivo(Nodo *pRaiz,float &hojas,float &acumulador);

    string str_nil; // caracter indicador de nodo nulo o vacío.

};

// sobrecarga global de operador binario
template<class T>
ostream& operator<<(ostream& pOut, ABB<T>& pAbb) {
    pAbb.volcarEnFlujo( pOut );
    return pOut;
}

template<class T, class Nodo>
void ABB<T, Nodo>::volcarEnFlujo(ostream &pOut)
{
    unsigned int i,
            altura = getAltura(),
            ancho = N>0 ? (getNodoMayor(raiz)->to_string().length() + 1): 2;

    for( unsigned int j=1; j<altura; ++j ) ancho *= 2;

    recorrerNivel( 0, pOut, ancho, str_nil ); pOut << endl;

    for( i=1; i<=altura; ++i ){
        recorrerNivel( i, pOut, ancho, str_nil );
        pOut << endl;
        ancho /= 2;
    }
}

template<class T, class Nodo>
void ABB<T, Nodo>::setSepParaVolcarEnFlujo(string pStr_null)
{
    str_nil = pStr_null;
}

//
template<class T, class Nodo>
ABB<T, Nodo>::ABB() {
    raiz = nullptr;
    N = 0;

    str_nil = "*";
}

template<class T, class Nodo>
ABB<T, Nodo>::~ABB()
{
    destruir_recursivamente( raiz );
}

template<class T, class Nodo>
void ABB<T, Nodo>::agregar(T pDato)
{
    // recursivamente
    agregar_recursivo( raiz, pDato ); // inicialmente la raíz es nula

    // iterativamente
}

template<class T, class Nodo>
void ABB<T, Nodo>::borrar(const T &pDato)
{
    raiz = borrar_recursivo( raiz, pDato );
}

template<class T, class Nodo>
void ABB<T,Nodo>::recorrerPreOden(ostream &out)
{
    recorrerPreOrden_recursivo(raiz,out);
}

template<class T, class Nodo>
void ABB<T, Nodo>::recorrerPreOrden_recursivo(Nodo *pptr, ostream &pOut)
{
    if( pptr != nullptr ) {
        pOut << pptr->dato << "; ";
        recorrerPreOrden_recursivo( pptr->izq, pOut );
        recorrerPreOrden_recursivo( pptr->der, pOut );
    }
}

template<class T, class Nodo>
void ABB<T, Nodo>::recorrerInOrden(ostream &out)
{
    // recursivamente
    recorrerInOrden_recursivo( raiz, out );

    // iterativamente
}

template<class T, class Nodo>
void ABB<T, Nodo>::recorrerPosOrden_recursivo(Nodo *pptr, ostream &pOut)
{
    if( pptr != nullptr ) {
        recorrerPosOrden_recursivo( pptr->izq, pOut );
        recorrerPosOrden_recursivo( pptr->der, pOut );
        pOut << pptr->dato << "; ";
    }
}
template<class T, class Nodo>
void ABB<T,Nodo>::recorrerPosOrden(ostream &out)
{
    recorrerPosOrden_recursivo(raiz,out);
}

template<class T, class Nodo>
void ABB<T, Nodo>::recorrerNivel(unsigned int pNivel, ostream &pOut, int pAncho, string pStr_null)
{
    recorrerNivel_recursivo( raiz, pNivel, pOut, pAncho, pStr_null );
}

template<class T, class Nodo>
unsigned int ABB<T, Nodo>::getAltura()
{
    return getAltura_recursivo( raiz );
}

template<class T, class Nodo>
unsigned int ABB<T, Nodo>::size()
{
    return N;
}

template<class T, class Nodo>
T ABB<T, Nodo>::getRaiz()
{
    T resp = 0;
    if( raiz )  resp = raiz->dato;
    else        throw string("El ABB no tiene nodos");
    return resp;
}

template<class T, class Nodo>
T ABB<T, Nodo>::getMayor()
{
    T res = 0;
    Nodo* ptr = getNodoMayor( raiz );
    if( ptr ) res = ptr->dato;
    else      throw string("No hay nodo mayor porque no existen nodos en el ABB.");
    return res;
}

template<class T, class Nodo>
T ABB<T, Nodo>::getMenor()
{
    T res = 0;
    Nodo* ptr = getNodoMenor( raiz );
    if( ptr ) res = ptr->dato;
    else      throw string("No hay nodo menor porque no existen nodos en el ABB.");
    return res;
}

template<class T, class Nodo>
unsigned int ABB<T,Nodo>::contarHojas()
{
    unsigned int contador=0;
    if(raiz)
    {
        contarHojasRecursivo(raiz,contador);
//        if(!raiz->izq && !raiz->der)
//            contador++;
//        else
//        {
//            if(raiz->izq)
//                contarHojasRecursivo(raiz->izq,contador);
//            if(raiz->der)
//                contarHojasRecursivo(raiz->der,contador);
//        }
    }
    return contador;
}

template<class T, class Nodo>
unsigned int ABB<T, Nodo>::contarNodosIntermedios()
{
    unsigned int contador=0;
    if(raiz)
    {
        if(raiz->izq)
            contarNodosIntermediosRecursivo(raiz->izq,contador);
        if(raiz->der)
            contarNodosIntermediosRecursivo(raiz->der,contador);
    }
    return contador;
}

template<class T, class Nodo>
unsigned int ABB<T,Nodo>::getNodos()
{
    return N;
}

template<class T, class Nodo>
void ABB<T, Nodo>::agregar_recursivo(Nodo*& pptr, const T &pValor)
{
    if( pptr == nullptr ) { // árbol vacío a partir de pptr
        pptr = new Nodo( pValor );
        ++N;
    }
    else { // árbol NO vacío a partir de pptr
        if( pValor > pptr->dato )
            agregar_recursivo( pptr->der, pValor );
        else // <
            if( pValor < pptr->dato )
                agregar_recursivo( pptr->izq, pValor );
    }
}

template<class T, class Nodo>
Nodo* ABB<T, Nodo>::borrar_recursivo(Nodo* pRaiz, const T &pDato)
{
    Nodo* nueva_raiz = nullptr;

    if( pRaiz ){
        if( pDato == pRaiz->dato ) { // encontrado... hay que eliminar el nodo
            Nodo *izq, *der;
            izq = pRaiz->izq;
            der = pRaiz->der;
            if( !izq and !der ) { // no hay descendientes
                delete pRaiz;
                --N;
            }
            if( !izq and der ) { // hay un descendiente
                nueva_raiz = der;
                delete pRaiz;
                --N;
            }
            if( izq and !der ) { // hay un descendiente
                nueva_raiz = izq;
                delete pRaiz;
                --N;
            }
            if( der and izq ) { // hay dos descendientes
                // se elige el mayor de los menores
                izq = getNodoMayor( izq ); // while ( izq->der ) izq = izq->der;
                pRaiz->dato = izq->dato;
                pRaiz->izq = borrar_recursivo( pRaiz->izq, izq->dato );
                nueva_raiz = pRaiz;
            }
        }
        else {
            if( pDato < pRaiz->dato )
                pRaiz->izq = borrar_recursivo( pRaiz->izq, pDato );
            else
                pRaiz->der = borrar_recursivo( pRaiz->der, pDato ); // caso >
            nueva_raiz = pRaiz;
        }
    }
    return nueva_raiz;
}

template<class T, class Nodo>
void ABB<T, Nodo>::recorrerInOrden_recursivo(Nodo *pptr, ostream &pOut)
{
    if( pptr != nullptr ) {
        recorrerInOrden_recursivo( pptr->izq, pOut );
        pOut << pptr->to_string() << "; "; // pOut << pptr->dato << "; ";
        recorrerInOrden_recursivo( pptr->der, pOut );
    }
}

template<class T, class Nodo>
void ABB<T, Nodo>::destruir_recursivamente(Nodo *&pptr)
{
    if( pptr != nullptr ) {
        destruir_recursivamente( pptr->izq );
        destruir_recursivamente( pptr->der );
        //cout << "Borrado: " << pptr->dato << endl; // <--- para ver recorrido posorden en borrado del ABB.
        delete pptr;
        pptr = nullptr;
    }
}

template<class T, class Nodo>
unsigned int ABB<T, Nodo>::getAltura_recursivo(Nodo *pRaiz)
{
    unsigned int h = 0;
    if( pRaiz ) {
        unsigned int h_der, h_izq;
        h_izq = getAltura_recursivo( pRaiz->izq );
        h_der = getAltura_recursivo( pRaiz->der );
        h = 1 + (h_izq > h_der ? h_izq : h_der);
    }
    return h;
}

template<class T, class Nodo>
Nodo *ABB<T, Nodo>::getNodoMayor(Nodo *pRaiz)
{
    Nodo* ptr = pRaiz;
    if( ptr ) while ( ptr->der ) ptr = ptr->der;
    return ptr;
}

template<class T, class Nodo>
Nodo *ABB<T, Nodo>::getNodoMenor(Nodo *pRaiz)
{
    Nodo* ptr = pRaiz;
    if( ptr ) while ( ptr->izq ) ptr = ptr->izq;
    return ptr;
}

template<class T, class Nodo>
void ABB<T, Nodo>::recorrerNivel_recursivo(Nodo *pRaiz, unsigned int pNivel, ostream &pOut,
                                           unsigned int pAncho, string pStr_null)
{
    pOut.width( pAncho );

    if( pNivel == 0 )
        imprimirCentrado( pOut, pAncho, "R" );
    else {
        if( pRaiz ) {
            if( pNivel == 1 )
                imprimirCentrado( pOut, pAncho, pRaiz->to_string() ); // to_string(pRaiz->dato) );
            else { // nivel > 1
                recorrerNivel_recursivo( pRaiz->izq, pNivel-1, pOut, pAncho, pStr_null );
                recorrerNivel_recursivo( pRaiz->der, pNivel-1, pOut, pAncho, pStr_null );
            }
        }
        else { // pRaiz == 0, pNivel > 0
            string nil = pStr_null;
            string space;
            space.resize(pAncho, ' ');
            space.replace((space.length()-nil.size())/2, nil.size(), nil );
            unsigned int rep = 1;
            for( unsigned int o=0; o<pNivel-1; ++o ) rep *= 2;
            for( unsigned int j=0; j<rep; ++j)
                imprimirCentrado(pOut, pAncho, space);
        }
    }
}

template<class T, class Nodo>
void ABB<T, Nodo>::imprimirCentrado(ostream &pOut, int pAncho, string pCad)
{
    string space, cad;
    typedef unsigned long long int LL;
    space.resize( ( static_cast<LL>(pAncho) - pCad.length() ) / 2, ' ' );
    cad = pCad + space;
    pOut << cad;
}

template<class T, class Nodo>
bool ABB<T, Nodo>::buscar(T pDato)
{
    bool encontrado=false;
    Nodo *aux=raiz;
    while(aux && !encontrado)
    {
        if(aux->dato==pDato)
            encontrado=true;
        else
            if(aux->dato>pDato)
                aux=aux->izq;
            else
                aux=aux->der;
    }
    return encontrado;
}

template<class T, class Nodo>
bool ABB<T,Nodo>::completarDato(T &pDato)
{
    bool encontrado=false;
    Nodo *aux=raiz;
    while(aux && !encontrado)
    {
        if(aux->dato==pDato)
        {
            encontrado=true;
            pDato=aux->dato;
        }
        else
            if(aux->dato>pDato)
                aux=aux->izq;
            else
                aux=aux->der;
    }
    return encontrado;
}

template<class T, class Nodo>
void ABB<T,Nodo>::podar()
{
    destruir_recursivamente(raiz);
    raiz=nullptr;
    N=0;
}

template<class T, class Nodo>
void ABB<T,Nodo>::podarAlt()
{
    if(raiz)
    {
        if(raiz->izq)
        {
            if(!raiz->izq->izq && !raiz->izq->der)
            {
                delete raiz->izq;
                raiz->izq=nullptr;
            }
            else
                podarRecursivoAlt(raiz->izq);
        }
        if(raiz->der)
        {
            if(!raiz->der->izq && !raiz->der->der)
            {
                delete raiz->der;
                raiz->der=nullptr;
            }
            else
                podarRecursivoAlt(raiz->der);
        }
    }
}

template<class T, class Nodo>
bool ABB<T,Nodo>::lleno()
{
    if(raiz)
    {
        bool lleno=true;
        llenoRecursivo(raiz->izq,lleno);
        llenoRecursivo(raiz->der,lleno);
        return lleno;
    }
    else
        throw "No se puede terminar si un arbol vacio es lleno";
}

template<class T, class Nodo>
bool ABB<T,Nodo>::completo()
{
    if(raiz)
    {
        bool retorno=true;
        unsigned int AlturaPrimerHoja=1;
        Nodo *aux=raiz;
        while(aux->izq || aux->der)
        {
            if(aux->izq)
                aux=aux->izq;
            else
                aux=aux->der;
            AlturaPrimerHoja++;
        }
        if(AlturaPrimerHoja<getAltura())
            retorno=false;
        else
        {
            if(raiz->izq)
                completoRecursivo(raiz->izq,retorno,AlturaPrimerHoja);
            if(raiz->der && retorno)
                completoRecursivo(raiz->der,retorno,AlturaPrimerHoja);
        }
        return retorno;
    }
    else
        throw "No se puede determinar si un arbol vacio es completo";
}

template<class T, class Nodo>
unsigned int ABB<T,Nodo>::getAlturaA(T pDato)
{
    Nodo *aux=raiz;
    unsigned altura=1;
    while(aux->dato!=pDato)
    {
        if(pDato>aux->dato)
            aux=aux->der;
        else
            aux=aux->izq;
        altura++;
    }
    return altura;
}

template<class T, class Nodo>
bool ABB<T,Nodo>::perfecto()
{
    if(raiz)
    {
        unsigned int numero=2;
        bool retorno=true;
        for(unsigned int i=1;i<getAltura();i++)
        {
            numero*=2;
        }
        if(numero==N-1)
            retorno=true;
        else
            retorno=false;
        return retorno;
    }
    else throw "No se puede determinar si un arbol vacio es perfecto";
}

template<class T, class Nodo>
void ABB<T,Nodo>::hojaMenosProfunda(T &dato, unsigned int &altura)
{
    if(raiz)
    {
        Nodo *aux=raiz;
        while(aux->izq || aux->der)
        {
            if(aux->izq)
                aux=aux->izq;
            else
                aux=aux->der;
        }
        dato=aux->dato;
        altura=getAlturaA(aux->dato);
        hojaMenosProfundaRecursiva(raiz,dato,altura);
    }
    else throw "El arbol esta vacio";
}

template<class T, class Nodo>
void ABB<T,Nodo>::hojaMasProfunda(T &dato, unsigned int &altura)
{
    if(raiz)
    {
        Nodo *aux=raiz;
        while(aux->izq || aux->der)
        {
            if(aux->izq)
                aux=aux->izq;
            else
                aux=aux->der;
        }
        dato=aux->dato;
        altura=getAlturaA(aux->dato);
        hojaMasProfundaRecursiva(raiz,dato,altura);
    }
    else throw "El arbol esta vacio";
}

template<class T, class Nodo>
unsigned int ABB<T,Nodo>::diferenciaAltura()
{
    if(raiz)
    {
    unsigned int retorno=getAltura();
    unsigned int alturaMenos=0; T dato;
    hojaMenosProfunda(dato,alturaMenos);
    return retorno-alturaMenos;
    }
    else throw "Arbol vacio";
}

template<class T, class Nodo>
float ABB<T,Nodo>::promedioAltura()
{
    if(raiz)
    {
    float hojas=0, acumulador=0;
    promedioAlturaRecursivo(raiz,hojas,acumulador);
    return acumulador/hojas;
    }
    else throw "Arbol vacio";
}
template<class T, class Nodo>
void ABB<T,Nodo>::contarHojasRecursivo(Nodo *pRaiz, unsigned int &contador)
{
    if(!pRaiz->izq && !pRaiz->der)
        contador++;
    else
    {
        if(pRaiz->izq)
            contarHojasRecursivo(pRaiz->izq,contador);
        if(pRaiz->der)
            contarHojasRecursivo(pRaiz->der,contador);
    }
}

template<class T, class Nodo>
void ABB<T,Nodo>::contarNodosIntermediosRecursivo(Nodo *pRaiz, unsigned int &contador)
{
    if(pRaiz->izq || pRaiz->der)
        contador++;
    if(pRaiz->izq)
        contarNodosIntermediosRecursivo(pRaiz->izq,contador);
    if(pRaiz->der)
        contarNodosIntermediosRecursivo(pRaiz->der,contador);
}

template<class T, class Nodo>
void ABB<T,Nodo>::podarRecursivo(Nodo *pRaiz)
{
    if(!pRaiz->izq && !pRaiz->der)
    {
        delete pRaiz;
        --N;
    }
    else
    {
        if(pRaiz->izq)
            podarRecursivo(pRaiz->izq);
        if(pRaiz->der)
            podarRecursivo(pRaiz->der);
    }
}

template<class T, class Nodo>
void ABB<T,Nodo>::podarRecursivoAlt(Nodo *pRaiz)
{
    if(pRaiz->izq)
    {
        if(!pRaiz->izq->izq && !pRaiz->izq->der)
        {
            delete pRaiz->izq;
            pRaiz->izq=nullptr;
        }
        else
            podarRecursivoAlt(pRaiz->izq);
    }
    if(pRaiz->der)
    {
        if(!pRaiz->der->izq && !pRaiz->der->der)
        {
            delete pRaiz->der;
            pRaiz->der=nullptr;
        }
        else
            podarRecursivoAlt(pRaiz->der);
    }
}

template<class T, class Nodo>
void ABB<T, Nodo>::llenoRecursivo(Nodo *pRaiz, bool &lleno)
{
    if(lleno)
    {
        if(!((pRaiz->izq && pRaiz->der) || (!pRaiz->izq && !pRaiz->der)))
            lleno=false;
        if(pRaiz->izq && pRaiz->der)
        {
            llenoRecursivo(pRaiz->izq,lleno);
            llenoRecursivo(pRaiz->der,lleno);
        }
    }
}

template<class T, class Nodo>
void ABB<T,Nodo>::completoRecursivo(Nodo *pRaiz, bool &retorno, unsigned int &AlturaAnteriorHoja)
{
    if(!pRaiz->izq && !pRaiz->der)
    {
        unsigned int alturaNodo=getAlturaA(pRaiz->dato);
        if(alturaNodo+1<getAltura() && alturaNodo+1<AlturaAnteriorHoja)
            retorno=false;
    }
    else
    {
        if(pRaiz->izq)
            completoRecursivo(pRaiz->izq,retorno,AlturaAnteriorHoja);
        if(pRaiz->der)
            completoRecursivo(pRaiz->der,retorno,AlturaAnteriorHoja);
    }
}

template<class T, class Nodo>
void ABB<T,Nodo>::hojaMenosProfundaRecursiva(Nodo *pRaiz, T &dato, unsigned int &altura)
{
    if(!pRaiz->izq && !pRaiz->der)
    {
        unsigned alturaNodo=getAlturaA(pRaiz->dato);
        if(alturaNodo<altura)
        {
            altura=alturaNodo;
            dato=pRaiz->dato;
        }
    }
    else
    {
        if(pRaiz->izq)
            hojaMenosProfundaRecursiva(pRaiz->izq,dato,altura);
        if(pRaiz->der)
            hojaMenosProfundaRecursiva(pRaiz->der,dato,altura);
    }
}

template<class T, class Nodo>
void ABB<T,Nodo>::hojaMasProfundaRecursiva(Nodo *pRaiz, T &dato, unsigned int &altura)
{
    if(!pRaiz->izq && !pRaiz->der)
    {
        unsigned alturaNodo=getAlturaA(pRaiz->dato);
        if(alturaNodo>altura)
        {
            altura=alturaNodo;
            dato=pRaiz->dato;
        }
    }
    else
    {
        if(pRaiz->izq)
            hojaMasProfundaRecursiva(pRaiz->izq,dato,altura);
        if(pRaiz->der)
            hojaMasProfundaRecursiva(pRaiz->der,dato,altura);
    }
}

template<class T, class Nodo>
void ABB<T,Nodo>::promedioAlturaRecursivo(Nodo *pRaiz, float &hojas, float &acumulador)
{
    if(!pRaiz->izq && !pRaiz->der)
    {
        acumulador+=getAlturaA(pRaiz->dato);
        hojas++;
    }
    else
    {
        if(pRaiz->izq)
            promedioAlturaRecursivo(pRaiz->izq,hojas,acumulador);
        if(pRaiz->der)
            promedioAlturaRecursivo(pRaiz->der,hojas,acumulador);
    }
}

#endif // ABB_H
