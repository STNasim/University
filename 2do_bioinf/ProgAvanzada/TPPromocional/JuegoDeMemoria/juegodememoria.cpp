#include "juegodememoria.h"

JuegoDeMemoria::JuegoDeMemoria(QApplication *pptrApp)
{
    srand(time(0));
    ptrApp = pptrApp;
    margen = 0.1;
    nivel = 1;
    nivelInicial=1;
    filas=0;
    columnas=0;
    rojo=0.5f;
    verde=0.6f;
    azul=0.5f;
    mostrarAlIniciar=false;
    tiempoMostrar=3000;
    miliSegundosAlFallar=1000;
    nivelSuperado=0;
    tiempoNivelSuperado=0;
    cartasSeleccionadas[0] = nullptr;
    cartasSeleccionadas[1] = nullptr;

    connect(&temporizador, SIGNAL(timeout()), this, SLOT(voltearCartas()));
    connect(&temporizadorMostrar, SIGNAL(timeout()), this, SLOT(EsconderCartas()));
}

JuegoDeMemoria::~JuegoDeMemoria()
{
    for (unsigned int i=0; i<mazoDeCartas.size(); ++i)
        if(mazoDeCartas[i] != nullptr)
            delete mazoDeCartas[i];
}

void JuegoDeMemoria::IniciarJuego()
{
    Reiniciar();
    seleccionaMazo();
    repartirCartas();
    ptrApp->exec();
}

void JuegoDeMemoria::seleccionaMazo()
{
    mazoDeCartas.clear();
    if(nivel<=3 or nivel==5 or nivel>=7)
    {
        mazoDeCartas.push_back(new Carta(2, FIG_TRIANGULO, {1.0,0.0,0.0}));
        mazoDeCartas.push_back(new Carta(2, FIG_TRIANGULO, {1.0,0.0,0.0}));
    }
    if(nivel>=1)
    {
        mazoDeCartas.push_back(new Carta(1, FIG_CUADRADO, {1.0,0.0,0.0}));
        mazoDeCartas.push_back(new Carta(1, FIG_CUADRADO, {1.0,0.0,0.0}));

    }
    if(nivel>=2)
    {
        mazoDeCartas.push_back(new Carta(3, FIG_TRIANGULO, {0.0,0.0,1.0}));
        mazoDeCartas.push_back(new Carta(3, FIG_TRIANGULO, {0.0,0.0,1.0}));
    }
    if (nivel>=3)
    {
        mazoDeCartas.push_back(new Carta(4, FIG_ESPIRAL, {0.0,0.0,1.0}));
        mazoDeCartas.push_back(new Carta(4, FIG_ESPIRAL, {0.0,0.0,1.0}));
    }
    if(nivel>=4)
    {
        mazoDeCartas.push_back(new Carta(5, FIG_ESTRELLA, {0.0,1.0,0.0}));
        mazoDeCartas.push_back(new Carta(5, FIG_ESTRELLA, {0.0,1.0,0.0}));
    }
    if(nivel==6 or nivel==8)
    {
        mazoDeCartas.push_back(new Carta(6, FIG_CIRCULO, {0.0,1.0,0.0}));
        mazoDeCartas.push_back(new Carta(6, FIG_CIRCULO, {0.0,1.0,0.0}));
    }
    if(nivel>=7)
    {
        mazoDeCartas.push_back(new Carta(7, FIG_ESPIRAL, {0.0,1.0,0.0}));
        mazoDeCartas.push_back(new Carta(7, FIG_ESPIRAL, {0.0,1.0,0.0}));
        mazoDeCartas.push_back(new Carta(8, FIG_ESTRELLA, {1.0,0.0,0.0}));
        mazoDeCartas.push_back(new Carta(8, FIG_ESTRELLA, {1.0,0.0,0.0}));
    }
}

void JuegoDeMemoria::repartirCartas()
{
    if(nivel<=7)
        filas=2;
    if(nivel==1)
        columnas=2;
    if(nivel==2)
        columnas=3;
    if(nivel==3 or nivel==4)
        columnas=4;
    if(nivel==5 or nivel==6)
        columnas=5;
    if(nivel==7)
        columnas=7;
    if(nivel==8)
    {
        filas=4;
        columnas=4;
    }
    if(nivel!=0)
    {
        mesaConCartas.repartirCartas(filas,columnas,mazoDeCartas,mostrarAlIniciar);
        if(nivel==1 or nivel==8)
            resize(500,500);
        else if(nivel!=8)
            resize(400+(100*nivel),300);
        if(mostrarAlIniciar)
            temporizadorMostrar.start(tiempoMostrar);
        show();
    }
}

void JuegoDeMemoria::initializeGL()
{
    glClearColor(rojo,verde,azul,0.0f);
}

void JuegoDeMemoria::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Se define espacio de graficación
    anchoMesaConCartas = mesaConCartas.getCantColumnas() + (mesaConCartas.getCantColumnas() - 1) * 0.1 + 2 * margen;
    altoMesaConCartas = mesaConCartas.getCantFilas() + (mesaConCartas.getCantFilas() -1) * 0.1 + 2 * margen;
    glOrtho(0, anchoMesaConCartas, 0, altoMesaConCartas, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void JuegoDeMemoria::paintGL()
{
    glClearColor(rojo,verde,azul,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();{
        glTranslated(margen,margen,0);
        mesaConCartas.dibujar();
    }glPopMatrix();
}

void JuegoDeMemoria::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && cartasSeleccionadas[1] == nullptr
            && !mesaConCartas.TodasLasCartasEmparejadas())
    {
        cronometro.IniciarCronometro();
        double posX = event->x() * anchoMesaConCartas / width() - margen;
        double posY = (height() - event->y()) * altoMesaConCartas / height() - margen;
        int cx = coordenadaAPosicionCuantizada(posX, anchoMesaConCartas);
        int cy = coordenadaAPosicionCuantizada(posY, altoMesaConCartas);
        if (cx>=0 && cy>=0
                && !mesaConCartas(unsigned(cy),unsigned(cx))->getEstaEmparejada()
                && !mesaConCartas(unsigned(cy),unsigned(cx))->getVisible())
        {
            if (cartasSeleccionadas[0] == nullptr) {
                cartasSeleccionadas[0] = mesaConCartas(unsigned(cy),unsigned(cx));
            } else {
                cartasSeleccionadas[1] = mesaConCartas(unsigned(cy),unsigned(cx));
                // Verificar si son iguales
                if (cartasSeleccionadas[0]->getId() == cartasSeleccionadas[1]->getId()) {
                    // Marcamos que las encontramos
                    cartasSeleccionadas[0]->setEstaEmparejada(true);
                    cartasSeleccionadas[1]->setEstaEmparejada(true);
                    // Ya no estan seleccionadas
                    cartasSeleccionadas[0] = nullptr;
                    cartasSeleccionadas[1] = nullptr;
                } else {
                    // Activar timer
                    temporizador.start(miliSegundosAlFallar);
                }
            }
            mesaConCartas(unsigned(cy),unsigned(cx))->setVisible(true);
            update();
        }
        if(mesaConCartas.TodasLasCartasEmparejadas())
        {
            tiempoNivelSuperado=cronometro.ObtenerTiempo();
            nivelSuperado=nivel;
            std::cout<<"Tiempo transcurrido en el nivel "<<ObtenerNivelSuperado()<<": "<<tiempoNivelSuperado
                <<" segundos"<<std::endl;
            if(nivel<8)
            {
                nivel++;
                seleccionaMazo();
                repartirCartas();
                cronometro.ObtenerTiempoYReinicar();
                cronometro.PararCronometro();
            }
        }
    }
}

float JuegoDeMemoria::ObtenerTiempoNivelSuperado()
{
    return tiempoNivelSuperado;
}

void JuegoDeMemoria::Reiniciar()
{
    srand(time(0));
    nivel=nivelInicial;
    nivelSuperado=0;
    tiempoNivelSuperado=0;
    cronometro.ObtenerTiempoYReinicar();
    cronometro.PararCronometro();
    cartasSeleccionadas[0] = nullptr;
    cartasSeleccionadas[1] = nullptr;
}

void JuegoDeMemoria::SetPuntero(QApplication *pPtrApp)
{
    ptrApp=pPtrApp;
}

int JuegoDeMemoria::ObtenerNivelSuperado()
{
    return nivelSuperado;
}

void JuegoDeMemoria::ElegirNivel(int value)
{
    nivelInicial = value;
    try {
        if(nivelInicial<1 or nivelInicial>8)
            throw "Nivel invalido";
    } catch (char const* error) {
      std::cout<<error<<". Cerrando aplicacion"<<std::endl;
      std::terminate();
    }
    Reiniciar();
}

void JuegoDeMemoria::ElegirTiempoAlFallar(float tiempo)
{
    miliSegundosAlFallar=(tiempo*1000.000);
}

void JuegoDeMemoria::ElegirColorFondo(float pRojo, float pVerde, float pAzul)
{
    rojo=pRojo;
    verde=pVerde;
    azul=pAzul;
    glClearColor(rojo,verde,azul,0.0f);
}

void JuegoDeMemoria::MostrarAlInicio(bool parametro)
{
    mostrarAlIniciar=parametro;
}

void JuegoDeMemoria::TiempoMostrarAlInicio(int tiempo)
{
    tiempoMostrar=tiempo*1000.000;
}

int JuegoDeMemoria::coordenadaAPosicionCuantizada(double pCoord, double limite)
{
    int posicion = -1;
    if (pCoord > 0 && pCoord < limite - margen){
        int c = static_cast<int>(pCoord / 1.1);
        double d = pCoord - c * 1.1;
        if (d < 1) posicion = c;
    }
    return posicion;
}

void JuegoDeMemoria::voltearCartas()
{
    temporizador.stop();
    // Se dan vuelta las cartas
    cartasSeleccionadas[0]->setVisible(false);
    cartasSeleccionadas[1]->setVisible(false);
    // Ya no estan seleccionadas
    cartasSeleccionadas[0] = nullptr;
    cartasSeleccionadas[1] = nullptr;
    update();
}

void JuegoDeMemoria::EsconderCartas()
{
    temporizadorMostrar.stop();
    mesaConCartas.EsconderCartas();
    update();
}
