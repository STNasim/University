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
        ../Caso2/Segundero.cpp \
        ../Graficador2D/dibujo.cpp \
        ../Graficador2D/graficador2d.cpp \
        caballo.cpp \
        main.cpp \
        solversaltocaballo.cpp \
        tablero.cpp \
        texto.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../Caso2/Segundero.h \
    ../Graficador2D/dibujo.h \
    ../Graficador2D/graficador2d.h \
    caballo.h \
    solversaltocaballo.h \
    tablero.h \
    texto.h
