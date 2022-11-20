#include "juegosaltocaballo.h"

JuegoSaltoCaballo::JuegoSaltoCaballo(QApplication *pPtrApp)
{
    graficador.setPtr_app(pPtrApp);
    srand((time(0)));
    nivel=1;
    nivelInicial=1;
    nivelSuperado=0;
    resultadoTestCorrecto=false;
    salir=false;
    tiempoUltimoJuego=0;
    filaInicial=0;
    columnaInicial=0;
    cantFilas=0;
    cantColumnas=0;
}

void JuegoSaltoCaballo::SeleccionarNivel(int valor)
{
    nivelInicial=valor;
    try {
        if(nivelInicial<1 or nivelInicial>8)
            throw "Nivel invalido";
    } catch (char const* error) {
        std::cout<<error<<". Cerrando aplicacion"<<std::endl;
        std::terminate();
    }
}

int JuegoSaltoCaballo::ObtenerNivelSuperado()
{
    return nivelSuperado;
}

float JuegoSaltoCaballo::ObtenerTiempoSuperado()
{
    return tiempoUltimoJuego;
}

void JuegoSaltoCaballo::IniciarJuego()
{
    Reiniciar();
    while(CargarDatosSegunNivel() and !salir)
    {
        graficador.limpiarDibujos();
        CargarNivel();
        ProcesarResultados();
    }
    std::cout<<"Fin del juego"<<std::endl;
}

void JuegoSaltoCaballo::Reiniciar()
{
    srand((time(0)));
    nivel=nivelInicial;
    salir=false;
    tiempoUltimoJuego=0;
    nivelSuperado=0;
}

void JuegoSaltoCaballo::SetPuntero(QApplication *pPtrApp)
{
    graficador.setPtr_app(pPtrApp);
}

bool JuegoSaltoCaballo::CargarDatosSegunNivel()
{
    //Setteo Tamaño
    bool todoOK=true;
    if(nivel>=1 and nivel<=3)
        cantFilas=cantColumnas=5;
    if(nivel==4)
        cantFilas=cantColumnas=6;
    if(nivel==5 or nivel==6)
        cantFilas=cantColumnas=7;
    if(nivel==7)
        cantFilas=cantColumnas=8;
    if(nivel==8)
        cantFilas=cantColumnas=9;

    //Setteo Posicion Inicial
    filaInicial=columnaInicial=0;
    if(nivel==1)
        filaInicial=columnaInicial=0;
    if(nivel==2)
        filaInicial=columnaInicial=2;
    if(nivel==3 or nivel==4)
    {
        filaInicial=rand()%cantFilas;
        columnaInicial=rand()%cantColumnas;
        while((nivel==3) and ((filaInicial+columnaInicial)%2==1))
        {
            filaInicial=rand()%cantFilas;
            columnaInicial=rand()%cantColumnas;
        }
    }
    if(nivel==5)
        filaInicial=columnaInicial=3;
    if(nivel>=6 and nivel<=8)
    {
        filaInicial=rand()%cantFilas;
        columnaInicial=rand()%cantColumnas;
    }
    if(nivel<1 or nivel>8)
        todoOK=false;

    return todoOK;
}

void JuegoSaltoCaballo::CargarNivel()
{
    dibujoTablero.SetDimensiones(cantFilas,cantColumnas);
    graficador.cargarDibujo( &dibujoTablero );
    solver.setImprimirSolucion(false); //Para testeo
    solver.setMostrarPosicionesIncorrectas(false);
    solver.setFinalizarPorTiempo(true);
    solver.setLimiteDeTiempo(2);
    sol = solver.generarUnaSolucionDesde(filaInicial, columnaInicial, cantFilas, cantColumnas);
    for(unsigned int i=0; i<sol.texto_posiciones.size(); ++i){
        graficador.cargarDibujo( &(sol.texto_posiciones[i]) );
    }
    graficador.cargarDibujo( &sol.caballo_inicial );
    graficador.cargarDibujo( &sol.caballo_final );

    if(!cronometro.EstaIniciado())
        cronometro.IniciarCronometro();
    else
        cronometro.ObtenerTiempoYReinicar();
    graficador.mostrar((cantColumnas-1)*80,(cantFilas-1)*80);
    cronometro.PararCronometro();
}

void JuegoSaltoCaballo::ProcesarResultados()
{
    if(graficador.getRespuestaUsuario()==-1)
        salir=true;
    if((graficador.getRespuestaUsuario()==1 and sol.correcta) or(graficador.getRespuestaUsuario()==0 and !sol.correcta))
        resultadoTestCorrecto=true;
    if((graficador.getRespuestaUsuario()==0 and sol.correcta) or(graficador.getRespuestaUsuario()==1 and !sol.correcta))
        resultadoTestCorrecto=false;
    if(graficador.getRespuestaUsuario()==1)
        std::cout<<"Eligio correcta";
    if(graficador.getRespuestaUsuario()==0)
        std::cout<<"Eligio incorrecta";

    if(!salir)
    {
        std::cout<<"Tiempo empleado en nivel "<<nivel<<": "<<cronometro.ObtenerTiempo()<<" segundos"<<std::endl;
        if(sol.correcta)
            std::cout<<" y la respuesta es correcta";
        else
            std::cout<<" y la respuesta es incorrecta";

        if(resultadoTestCorrecto)
        {
            std::cout<<". Su respuesta es correcta"<<std::endl;
            tiempoUltimoJuego=cronometro.ObtenerTiempo();
            nivelSuperado=nivel;
            if (nivel==8)
                salir=true;
            else
                nivel++;
        }
        else
            std::cout<<". Su respuesta es incorrecta"<<std::endl;
    }
    if(!sol.correcta and graficador.getRespuestaUsuario()!=-1)
    {
        solver.setMostrarPosicionesIncorrectas(true);
        sol = solver.getSol();
        graficador.limpiarDibujos();
        graficador.cargarDibujo( &dibujoTablero );
        for(unsigned int i=0; i<sol.texto_posiciones.size(); ++i){
            graficador.cargarDibujo( &(sol.texto_posiciones[i]) );
        }
        graficador.cargarDibujo( &sol.caballo_inicial );
        graficador.cargarDibujo( &sol.caballo_final );
        graficador.mostrar((cantColumnas-1)*80,(cantFilas-1)*80);
    }
}
