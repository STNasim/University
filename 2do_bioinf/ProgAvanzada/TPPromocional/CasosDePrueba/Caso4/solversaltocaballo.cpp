#include "solversaltocaballo.h"

#include <sstream>

//using namespace std;

SolverSaltoCaballo::SolverSaltoCaballo()
{
    volcarSolucionEnConsola=false;
    resaltarPosicionesIncorrectas = false;

    cantFil=8;
    cantCol=8;
    dfila[0] = -1; dcol[0] = -2;
    dfila[1] = -2; dcol[1] = -1;
    dfila[2] = -1; dcol[2] = 2;
    dfila[3] = -2; dcol[3] = 1;
    dfila[4] = 1; dcol[4] = -2;
    dfila[5] = 2; dcol[5] = -1;
    dfila[6] = 1; dcol[6] = 2;
    dfila[7] = 2; dcol[7] = 1;

    // Variables auxiliares de algoritmo recursivo
    salir = false;
    tablero = nullptr;

    finalizar_por_tiempo = true;
    tiempo_limite = 5; // En segundos

    colorCabInicial.resize(3);
    colorCabFinal.resize(3);
    setColorCaballoInicial();
    setColorCaballoFinal();
    c_inicial = clock();
    sol_retornada = false;
}

void SolverSaltoCaballo::setFinalizarPorTiempo(bool pBandera)
{
    finalizar_por_tiempo = pBandera;
}

void SolverSaltoCaballo::setImprimirSolucion(bool pBandera)
{
    volcarSolucionEnConsola = pBandera;
}

void SolverSaltoCaballo::setMostrarPosicionesIncorrectas(bool pBandera)
{
    resaltarPosicionesIncorrectas = pBandera;
    for(unsigned int i=0; i<sol.posiciones_correctas.size(); ++i)
        if(!sol.posiciones_correctas[i])
            sol.texto_posiciones[i].setColor(0,0,1);
        else
            sol.texto_posiciones[i].setColor(1,0,0);
}

void SolverSaltoCaballo::setLimiteDeTiempo(unsigned int segundos)
{
    tiempo_limite = segundos;
}

void SolverSaltoCaballo::setColorCaballoInicial(float pR, float pG, float pB)
{
    colorCabInicial[0]=pR;
    colorCabInicial[1]=pG;
    colorCabInicial[2]=pB;
}

void SolverSaltoCaballo::setColorCaballoFinal(float pR, float pG, float pB)
{
    colorCabFinal[0]=pR;
    colorCabFinal[1]=pG;
    colorCabFinal[2]=pB;
}

Solucion SolverSaltoCaballo::generarUnaSolucionDesde(int pF, int pC, int pCantFil, int pCantCol)
{
    cantFil = pCantFil;
    cantCol = pCantCol;

    sol = Solucion(0,0); // Solución inválida por defecto

    //Posicion inicial del caballo
    if(pF>=0&&pF<pCantFil && pC>=0&&pC<pCantCol){
        sol = Solucion(pF, pC);
        sol.caballo_inicial.setColor(colorCabInicial[0], colorCabInicial[1], colorCabInicial[2]);

        // Se limpia solución anterior
        sol.texto_posiciones.clear();
        sol.tablero.clear();

        int cantCasillas = pCantFil * pCantCol;

        // Se inicializa tablero en arreglo estático para mayor velocidad
        if(tablero != nullptr) delete [] tablero;
        tablero = new int[ cantCasillas ];
        for (int i=0; i<cantCasillas; ++i) tablero[i]=0;

        tablero[pF*pCantCol+pC]=1;
        c_inicial = clock();
        sol_retornada = false;
        salta(pF,pC,1); // encuentra 1 solución al azar que queda en tablero[]
        salir = false; // Para poder buscar otra solución
    }
    else{
        sol.caballo_inicial.setColor(colorCabInicial[0], colorCabInicial[1], colorCabInicial[2]);

        // Se limpia solución anterior
        sol.texto_posiciones.clear();
        sol.tablero.clear();

        int cantCasillas = pCantFil * pCantCol;

        // Se inicializa tablero en arreglo estático para mayor velocidad
        if(tablero != nullptr) delete [] tablero;
        tablero = new int[ cantCasillas ];
        for (int i=0; i<cantCasillas; ++i) tablero[i]=0;

        tablero[0*pCantCol+0]=1;
        salir = false; // Para poder buscar otra solución
    }
    return sol;
}

SolverSaltoCaballo::~SolverSaltoCaballo()
{
    delete [] tablero;
}

Solucion SolverSaltoCaballo::getSol() const
{
    return sol;
}

void SolverSaltoCaballo::salta(int finic, int cinic, int nsalto)
{
    static int intento = 0; ++intento;
    if( finalizar_por_tiempo && !salir ){
        if( unsigned((clock()-c_inicial)/CLOCKS_PER_SEC) >= tiempo_limite )
            salir = true;
    }
    if(intento%100000000==0 && volcarSolucionEnConsola && !salir ){
        std::cout << "Intento: " << intento
             << " - Tiempo: " << (clock()-c_inicial)/CLOCKS_PER_SEC
             << " segundos" <<std::endl;
    }
    if ((nsalto==(cantFil*cantCol) && !salir) || (finalizar_por_tiempo && salir && !sol_retornada)){
        sol.correcta = nsalto==(cantFil*cantCol); // Se indica si la solución es correcta
        if(volcarSolucionEnConsola){
            std::cout << "Intento: " << intento
                 << " - Tiempo: " << (clock()-c_inicial)/CLOCKS_PER_SEC
                 << " segundos" <<std::endl;
            imprimirSolucion();
        }
        copy(tablero,tablero+cantFil*cantCol,back_inserter(sol.tablero));
        sol_retornada = true;
        salir = true;
        unsigned cantCasilleros = unsigned(cantFil*cantCol);
        std::vector<unsigned> pos_ceros;
        sol.posiciones_correctas = std::vector<bool>(sol.tablero.size(),true);
        if(!sol.correcta){ // Si no es correcta, se completan ceros con los números restantes
            unsigned max = unsigned(*max_element(sol.tablero.begin(), sol.tablero.begin()+cantCasilleros));
            //std::cout << "max: " << max << std::endl;
            pos_ceros.resize(unsigned(cantCasilleros-max));
            //std::cout << "cantCasilleros-max: " << cantCasilleros-max << std::endl;
            std::vector<int>::iterator it = sol.tablero.begin();
            for(unsigned i=0; i<pos_ceros.size(); ++i){
                it = find(it, sol.tablero.end(), 0);
                pos_ceros[i] = unsigned(it - sol.tablero.begin());
                //std::cout << "pos_ceros["<<i<<"]: " << pos_ceros[i] << std::endl;
                ++it; // Buscar próximo cero
            }
            random_shuffle(pos_ceros.begin(),pos_ceros.end());
            for(unsigned i=0;i<pos_ceros.size();++i){
                sol.tablero[pos_ceros[i]] = int(i + max + 1);
                sol.posiciones_correctas[pos_ceros[i]] = false; // guardar saltos incorrectos
            }
        }
        int f,c,pos;
        unsigned upos;
        std::vector<unsigned>::iterator it;
        for(f=0; f<cantFil; ++f){
            for(c=0; c<cantCol; ++c){
                pos = f*cantCol+c;
                upos = unsigned(pos);
                it = std::find(pos_ceros.begin(), pos_ceros.end(), pos);
                if(resaltarPosicionesIncorrectas){
                    if(it != pos_ceros.end())
                        sol.texto_posiciones.push_back(Texto(std::to_string(sol.tablero[upos]),c,f,0,0,1));
                    else
                        sol.texto_posiciones.push_back(Texto(std::to_string(sol.tablero[upos]),c,f));
                }else{
                    sol.texto_posiciones.push_back(Texto(std::to_string(sol.tablero[upos]),c,f));
                }
                if(unsigned(sol.tablero[upos]) == cantCasilleros){
                    sol.caballo_final.setPosicion(c,f);
                }
            }
        }
        sol.caballo_final.setColor(colorCabFinal[0], colorCabFinal[1], colorCabFinal[2]);
    }
    else if( !salir ){
        int nuevax, nuevay;
        int indexSuffle[8] = {0,1,2,3,4,5,6,7}; // mapeo
        if(intento<=5)
            std::random_shuffle(indexSuffle, indexSuffle+8); // suffle de mapeo
        for (int i=0;(i<8) ;i++){
            nuevax=cinic+dcol[indexSuffle[i]];
            nuevay=finic+dfila[indexSuffle[i]];
            if ((nuevax>=0) && (nuevay>=0)
                    && (nuevax<cantCol) && (nuevay<cantFil)
                    &&(tablero[nuevay*cantCol+nuevax]==0)){
                nsalto=nsalto+1;
                tablero[nuevay*cantCol+nuevax]=nsalto;
                salta(nuevay,nuevax,nsalto);
                nsalto=nsalto-1;
                tablero[nuevay*cantCol+nuevax]=0;
            }
        }
    }
}

void SolverSaltoCaballo::imprimirSolucion()
{
    std::ostringstream out;
    out << "SOLUCION \'"
        << (sol.correcta?"CORRECTA":"INCORRECTA")
        <<"\' PARA EL PROBLEMA DE SALTO DEL CABALLO: " << std::endl;
    int f,c;
    for (f=cantFil-1; f>=0; --f){
        for (c=0; c<cantCol; ++c)
            out << std::setw(4) << tablero[f*cantCol+c];
        out << std::endl;
    }
    std::cout << out.str();
}
