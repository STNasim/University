QT += core
QT -= gui
QT += openglwidgets
LIBS += -lOpenGL32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JuegoDeLaMemoria
TEMPLATE = app

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
        ../Caso1/carta.cpp \
        ../Caso1/circulo.cpp \
        ../Caso1/cuadrado.cpp \
        ../Caso1/espiral.cpp \
        ../Caso1/estrella.cpp \
        ../Caso1/figura.cpp \
        ../Caso1/mesa.cpp \
        ../Caso1/triangulo.cpp \
        Segundero.cpp \
        juegodelamemoria.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../Caso1/carta.h \
    ../Caso1/circulo.h \
    ../Caso1/cuadrado.h \
    ../Caso1/espiral.h \
    ../Caso1/estrella.h \
    ../Caso1/figura.h \
    ../Caso1/mesa.h \
    ../Caso1/pixel.h \
    ../Caso1/triangulo.h \
    Segundero.h \
    juegodelamemoria.h
