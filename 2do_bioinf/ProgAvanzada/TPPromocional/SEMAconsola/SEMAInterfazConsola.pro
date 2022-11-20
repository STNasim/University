QT -= gui

QT += widgets
QT += openglwidgets

LIBS += -lOpenGL32

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../CasosDePrueba/Caso1/carta.cpp \
        ../CasosDePrueba/Caso1/circulo.cpp \
        ../CasosDePrueba/Caso1/cuadrado.cpp \
        ../CasosDePrueba/Caso1/espiral.cpp \
        ../CasosDePrueba/Caso1/estrella.cpp \
        ../CasosDePrueba/Caso1/figura.cpp \
        ../CasosDePrueba/Caso1/mesa.cpp \
        ../CasosDePrueba/Caso1/triangulo.cpp \
        ../CasosDePrueba/Caso2/Segundero.cpp \
        ../CasosDePrueba/Caso4/caballo.cpp \
        ../CasosDePrueba/Caso4/solversaltocaballo.cpp \
        ../CasosDePrueba/Caso4/tablero.cpp \
        ../CasosDePrueba/Caso4/texto.cpp \
        ../CasosDePrueba/Graficador2D/dibujo.cpp \
        ../CasosDePrueba/Graficador2D/graficador2d.cpp \
        ../Funcionalidades/desempenio.cpp \
        ../Funcionalidades/manejoDatos.cpp \
        ../JuegoDeMemoria/juegodememoria.cpp \
        ../JuegoSaltoCaballo/juegosaltocaballo.cpp \
        interfaz.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../CasosDePrueba/Caso1/carta.h \
    ../CasosDePrueba/Caso1/circulo.h \
    ../CasosDePrueba/Caso1/cuadrado.h \
    ../CasosDePrueba/Caso1/espiral.h \
    ../CasosDePrueba/Caso1/estrella.h \
    ../CasosDePrueba/Caso1/figura.h \
    ../CasosDePrueba/Caso1/mesa.h \
    ../CasosDePrueba/Caso1/pixel.h \
    ../CasosDePrueba/Caso1/triangulo.h \
    ../CasosDePrueba/Caso2/Segundero.h \
    ../CasosDePrueba/Caso4/caballo.h \
    ../CasosDePrueba/Caso4/solversaltocaballo.h \
    ../CasosDePrueba/Caso4/tablero.h \
    ../CasosDePrueba/Caso4/texto.h \
    ../CasosDePrueba/Graficador2D/dibujo.h \
    ../CasosDePrueba/Graficador2D/graficador2d.h \
    ../Funcionalidades/desempenio.h \
    ../Funcionalidades/manejoDatos.h \
    ../JuegoDeMemoria/juegodememoria.h \
    ../JuegoSaltoCaballo/juegosaltocaballo.h \
    interfaz.h
