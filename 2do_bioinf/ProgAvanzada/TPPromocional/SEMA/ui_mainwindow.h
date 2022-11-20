/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QComboBox *SeleccionarNivelMemoria;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *SeleccionadorColor;
    QLabel *label_5;
    QCheckBox *CartasBocaArriba;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *EjecutarMemoria;
    QComboBox *SeleccionarNivelCaballo;
    QLabel *label_8;
    QPushButton *ObtenerNivelMaximoMemoria;
    QLCDNumber *MostrarNivelMemoria;
    QLCDNumber *MostrarTiempoMemoria;
    QPushButton *ObtenerTiempoMaximoMemoria;
    QLCDNumber *MostrarNivelCaballo;
    QLCDNumber *MostrarTiempoCaballo;
    QPushButton *ObtenerTiempoMaximoCaballo;
    QPushButton *ObtenerNivelMaximoCaballo;
    QPushButton *EjecutarCaballo;
    QPushButton *CargarPacientes;
    QLabel *label_9;
    QPushButton *AgregarPaciente;
    QPushButton *ModificarPaciente;
    QPushButton *SeleccionarPaciente;
    QPushButton *CargarDatosPaciente;
    QLabel *label_10;
    QCheckBox *GraficaLineal;
    QCheckBox *GraficaInterpolada;
    QPushButton *DibujarGrafica;
    QSpinBox *TiempoMostrar2Distintas;
    QSpinBox *ColorRojo;
    QSpinBox *ColorVerde;
    QSpinBox *ColorAzul;
    QLabel *label_4;
    QLabel *label_11;
    QLabel *label_12;
    QSpinBox *TiempoMostrarCartasInicio;
    QPlainTextEdit *VentanaDatos;
    QLabel *label_14;
    QPlainTextEdit *VentanaDNI;
    QLabel *label_15;
    QComboBox *ValorTipoVentana;
    QComboBox *ValorNivelVentana;
    QPushButton *GuardarMemoria;
    QPushButton *GuardarCaballo;
    QLabel *Consola;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(350, 10, 101, 21));
        SeleccionarNivelMemoria = new QComboBox(centralwidget);
        SeleccionarNivelMemoria->addItem(QString());
        SeleccionarNivelMemoria->addItem(QString());
        SeleccionarNivelMemoria->addItem(QString());
        SeleccionarNivelMemoria->addItem(QString());
        SeleccionarNivelMemoria->addItem(QString());
        SeleccionarNivelMemoria->addItem(QString());
        SeleccionarNivelMemoria->addItem(QString());
        SeleccionarNivelMemoria->addItem(QString());
        SeleccionarNivelMemoria->setObjectName(QString::fromUtf8("SeleccionarNivelMemoria"));
        SeleccionarNivelMemoria->setGeometry(QRect(340, 50, 31, 22));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(380, 50, 61, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(370, 80, 101, 31));
        SeleccionadorColor = new QComboBox(centralwidget);
        SeleccionadorColor->addItem(QString());
        SeleccionadorColor->addItem(QString());
        SeleccionadorColor->addItem(QString());
        SeleccionadorColor->addItem(QString());
        SeleccionadorColor->addItem(QString());
        SeleccionadorColor->addItem(QString());
        SeleccionadorColor->addItem(QString());
        SeleccionadorColor->addItem(QString());
        SeleccionadorColor->addItem(QString());
        SeleccionadorColor->setObjectName(QString::fromUtf8("SeleccionadorColor"));
        SeleccionadorColor->setGeometry(QRect(310, 130, 61, 22));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(380, 130, 81, 16));
        CartasBocaArriba = new QCheckBox(centralwidget);
        CartasBocaArriba->setObjectName(QString::fromUtf8("CartasBocaArriba"));
        CartasBocaArriba->setGeometry(QRect(330, 210, 111, 31));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(350, 240, 121, 51));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(560, 10, 121, 21));
        EjecutarMemoria = new QPushButton(centralwidget);
        EjecutarMemoria->setObjectName(QString::fromUtf8("EjecutarMemoria"));
        EjecutarMemoria->setGeometry(QRect(290, 410, 75, 23));
        SeleccionarNivelCaballo = new QComboBox(centralwidget);
        SeleccionarNivelCaballo->addItem(QString());
        SeleccionarNivelCaballo->addItem(QString());
        SeleccionarNivelCaballo->addItem(QString());
        SeleccionarNivelCaballo->addItem(QString());
        SeleccionarNivelCaballo->addItem(QString());
        SeleccionarNivelCaballo->addItem(QString());
        SeleccionarNivelCaballo->addItem(QString());
        SeleccionarNivelCaballo->addItem(QString());
        SeleccionarNivelCaballo->setObjectName(QString::fromUtf8("SeleccionarNivelCaballo"));
        SeleccionarNivelCaballo->setGeometry(QRect(570, 50, 31, 22));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(610, 50, 61, 20));
        ObtenerNivelMaximoMemoria = new QPushButton(centralwidget);
        ObtenerNivelMaximoMemoria->setObjectName(QString::fromUtf8("ObtenerNivelMaximoMemoria"));
        ObtenerNivelMaximoMemoria->setGeometry(QRect(280, 300, 101, 41));
        MostrarNivelMemoria = new QLCDNumber(centralwidget);
        MostrarNivelMemoria->setObjectName(QString::fromUtf8("MostrarNivelMemoria"));
        MostrarNivelMemoria->setGeometry(QRect(390, 310, 64, 23));
        MostrarTiempoMemoria = new QLCDNumber(centralwidget);
        MostrarTiempoMemoria->setObjectName(QString::fromUtf8("MostrarTiempoMemoria"));
        MostrarTiempoMemoria->setGeometry(QRect(390, 360, 64, 23));
        ObtenerTiempoMaximoMemoria = new QPushButton(centralwidget);
        ObtenerTiempoMaximoMemoria->setObjectName(QString::fromUtf8("ObtenerTiempoMaximoMemoria"));
        ObtenerTiempoMaximoMemoria->setGeometry(QRect(280, 350, 101, 41));
        MostrarNivelCaballo = new QLCDNumber(centralwidget);
        MostrarNivelCaballo->setObjectName(QString::fromUtf8("MostrarNivelCaballo"));
        MostrarNivelCaballo->setGeometry(QRect(650, 100, 64, 23));
        MostrarTiempoCaballo = new QLCDNumber(centralwidget);
        MostrarTiempoCaballo->setObjectName(QString::fromUtf8("MostrarTiempoCaballo"));
        MostrarTiempoCaballo->setGeometry(QRect(650, 150, 64, 23));
        ObtenerTiempoMaximoCaballo = new QPushButton(centralwidget);
        ObtenerTiempoMaximoCaballo->setObjectName(QString::fromUtf8("ObtenerTiempoMaximoCaballo"));
        ObtenerTiempoMaximoCaballo->setGeometry(QRect(540, 140, 101, 41));
        ObtenerNivelMaximoCaballo = new QPushButton(centralwidget);
        ObtenerNivelMaximoCaballo->setObjectName(QString::fromUtf8("ObtenerNivelMaximoCaballo"));
        ObtenerNivelMaximoCaballo->setGeometry(QRect(540, 90, 101, 41));
        EjecutarCaballo = new QPushButton(centralwidget);
        EjecutarCaballo->setObjectName(QString::fromUtf8("EjecutarCaballo"));
        EjecutarCaballo->setGeometry(QRect(540, 200, 75, 23));
        CargarPacientes = new QPushButton(centralwidget);
        CargarPacientes->setObjectName(QString::fromUtf8("CargarPacientes"));
        CargarPacientes->setGeometry(QRect(70, 50, 121, 21));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(110, 10, 41, 20));
        AgregarPaciente = new QPushButton(centralwidget);
        AgregarPaciente->setObjectName(QString::fromUtf8("AgregarPaciente"));
        AgregarPaciente->setGeometry(QRect(30, 90, 91, 23));
        ModificarPaciente = new QPushButton(centralwidget);
        ModificarPaciente->setObjectName(QString::fromUtf8("ModificarPaciente"));
        ModificarPaciente->setGeometry(QRect(130, 90, 141, 23));
        SeleccionarPaciente = new QPushButton(centralwidget);
        SeleccionarPaciente->setObjectName(QString::fromUtf8("SeleccionarPaciente"));
        SeleccionarPaciente->setGeometry(QRect(90, 240, 121, 23));
        CargarDatosPaciente = new QPushButton(centralwidget);
        CargarDatosPaciente->setObjectName(QString::fromUtf8("CargarDatosPaciente"));
        CargarDatosPaciente->setGeometry(QRect(70, 280, 161, 23));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(120, 350, 47, 16));
        GraficaLineal = new QCheckBox(centralwidget);
        GraficaLineal->setObjectName(QString::fromUtf8("GraficaLineal"));
        GraficaLineal->setGeometry(QRect(70, 380, 51, 21));
        GraficaInterpolada = new QCheckBox(centralwidget);
        GraficaInterpolada->setObjectName(QString::fromUtf8("GraficaInterpolada"));
        GraficaInterpolada->setGeometry(QRect(150, 380, 81, 21));
        DibujarGrafica = new QPushButton(centralwidget);
        DibujarGrafica->setObjectName(QString::fromUtf8("DibujarGrafica"));
        DibujarGrafica->setGeometry(QRect(110, 450, 75, 23));
        TiempoMostrar2Distintas = new QSpinBox(centralwidget);
        TiempoMostrar2Distintas->setObjectName(QString::fromUtf8("TiempoMostrar2Distintas"));
        TiempoMostrar2Distintas->setGeometry(QRect(320, 90, 41, 21));
        TiempoMostrar2Distintas->setMaximum(100);
        TiempoMostrar2Distintas->setValue(1);
        ColorRojo = new QSpinBox(centralwidget);
        ColorRojo->setObjectName(QString::fromUtf8("ColorRojo"));
        ColorRojo->setGeometry(QRect(310, 160, 42, 22));
        ColorRojo->setMaximum(100);
        ColorVerde = new QSpinBox(centralwidget);
        ColorVerde->setObjectName(QString::fromUtf8("ColorVerde"));
        ColorVerde->setGeometry(QRect(370, 160, 42, 22));
        ColorVerde->setMaximum(100);
        ColorAzul = new QSpinBox(centralwidget);
        ColorAzul->setObjectName(QString::fromUtf8("ColorAzul"));
        ColorAzul->setGeometry(QRect(430, 160, 42, 22));
        ColorAzul->setMaximum(100);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(290, 190, 61, 20));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(430, 190, 61, 16));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(360, 190, 71, 16));
        TiempoMostrarCartasInicio = new QSpinBox(centralwidget);
        TiempoMostrarCartasInicio->setObjectName(QString::fromUtf8("TiempoMostrarCartasInicio"));
        TiempoMostrarCartasInicio->setGeometry(QRect(300, 260, 42, 22));
        TiempoMostrarCartasInicio->setValue(3);
        VentanaDatos = new QPlainTextEdit(centralwidget);
        VentanaDatos->setObjectName(QString::fromUtf8("VentanaDatos"));
        VentanaDatos->setGeometry(QRect(60, 180, 201, 51));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(20, 190, 31, 20));
        VentanaDNI = new QPlainTextEdit(centralwidget);
        VentanaDNI->setObjectName(QString::fromUtf8("VentanaDNI"));
        VentanaDNI->setGeometry(QRect(60, 130, 131, 31));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(30, 140, 21, 16));
        ValorTipoVentana = new QComboBox(centralwidget);
        ValorTipoVentana->addItem(QString());
        ValorTipoVentana->addItem(QString());
        ValorTipoVentana->setObjectName(QString::fromUtf8("ValorTipoVentana"));
        ValorTipoVentana->setGeometry(QRect(60, 420, 69, 22));
        ValorNivelVentana = new QComboBox(centralwidget);
        ValorNivelVentana->addItem(QString());
        ValorNivelVentana->addItem(QString());
        ValorNivelVentana->addItem(QString());
        ValorNivelVentana->addItem(QString());
        ValorNivelVentana->addItem(QString());
        ValorNivelVentana->addItem(QString());
        ValorNivelVentana->addItem(QString());
        ValorNivelVentana->addItem(QString());
        ValorNivelVentana->setObjectName(QString::fromUtf8("ValorNivelVentana"));
        ValorNivelVentana->setGeometry(QRect(140, 420, 69, 22));
        GuardarMemoria = new QPushButton(centralwidget);
        GuardarMemoria->setObjectName(QString::fromUtf8("GuardarMemoria"));
        GuardarMemoria->setGeometry(QRect(380, 410, 75, 23));
        GuardarCaballo = new QPushButton(centralwidget);
        GuardarCaballo->setObjectName(QString::fromUtf8("GuardarCaballo"));
        GuardarCaballo->setGeometry(QRect(630, 200, 75, 23));
        Consola = new QLabel(centralwidget);
        Consola->setObjectName(QString::fromUtf8("Consola"));
        Consola->setGeometry(QRect(240, 440, 491, 141));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Juego de la memoria", nullptr));
        SeleccionarNivelMemoria->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        SeleccionarNivelMemoria->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        SeleccionarNivelMemoria->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        SeleccionarNivelMemoria->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        SeleccionarNivelMemoria->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));
        SeleccionarNivelMemoria->setItemText(5, QCoreApplication::translate("MainWindow", "6", nullptr));
        SeleccionarNivelMemoria->setItemText(6, QCoreApplication::translate("MainWindow", "7", nullptr));
        SeleccionarNivelMemoria->setItemText(7, QCoreApplication::translate("MainWindow", "8", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Nivel Inicial", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Tiempo al dar vuelta\n"
"dos tarjetas distintas", nullptr));
        SeleccionadorColor->setItemText(0, QCoreApplication::translate("MainWindow", "Defecto", nullptr));
        SeleccionadorColor->setItemText(1, QCoreApplication::translate("MainWindow", "Blanco", nullptr));
        SeleccionadorColor->setItemText(2, QCoreApplication::translate("MainWindow", "Rojo", nullptr));
        SeleccionadorColor->setItemText(3, QCoreApplication::translate("MainWindow", "Verde", nullptr));
        SeleccionadorColor->setItemText(4, QCoreApplication::translate("MainWindow", "Azul", nullptr));
        SeleccionadorColor->setItemText(5, QCoreApplication::translate("MainWindow", "Amarillo", nullptr));
        SeleccionadorColor->setItemText(6, QCoreApplication::translate("MainWindow", "Magenta", nullptr));
        SeleccionadorColor->setItemText(7, QCoreApplication::translate("MainWindow", "Cian", nullptr));
        SeleccionadorColor->setItemText(8, QCoreApplication::translate("MainWindow", "Manual", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "Color de fondo", nullptr));
        CartasBocaArriba->setText(QCoreApplication::translate("MainWindow", "Empezar con las\n"
"cartas boca arriba", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Tiempo que las cartas\n"
"permanecen boca arriba", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Juego camino del caballo", nullptr));
        EjecutarMemoria->setText(QCoreApplication::translate("MainWindow", "Ejecutar", nullptr));
        SeleccionarNivelCaballo->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        SeleccionarNivelCaballo->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        SeleccionarNivelCaballo->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        SeleccionarNivelCaballo->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        SeleccionarNivelCaballo->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));
        SeleccionarNivelCaballo->setItemText(5, QCoreApplication::translate("MainWindow", "6", nullptr));
        SeleccionarNivelCaballo->setItemText(6, QCoreApplication::translate("MainWindow", "7", nullptr));
        SeleccionarNivelCaballo->setItemText(7, QCoreApplication::translate("MainWindow", "8", nullptr));

        label_8->setText(QCoreApplication::translate("MainWindow", "Nivel Inicial", nullptr));
        ObtenerNivelMaximoMemoria->setText(QCoreApplication::translate("MainWindow", "Mostrar m\303\241ximo\n"
"nivel superado", nullptr));
        ObtenerTiempoMaximoMemoria->setText(QCoreApplication::translate("MainWindow", "Mostrar tiempo del\n"
"nivel superado", nullptr));
        ObtenerTiempoMaximoCaballo->setText(QCoreApplication::translate("MainWindow", "Mostrar tiempo del\n"
"nivel superado", nullptr));
        ObtenerNivelMaximoCaballo->setText(QCoreApplication::translate("MainWindow", "Mostrar m\303\241ximo\n"
"nivel superado", nullptr));
        EjecutarCaballo->setText(QCoreApplication::translate("MainWindow", "Ejecutar", nullptr));
        CargarPacientes->setText(QCoreApplication::translate("MainWindow", "Cargar Pacientes", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Gesti\303\263n", nullptr));
        AgregarPaciente->setText(QCoreApplication::translate("MainWindow", "Agregar paciente", nullptr));
        ModificarPaciente->setText(QCoreApplication::translate("MainWindow", "Modificar datos paciente", nullptr));
        SeleccionarPaciente->setText(QCoreApplication::translate("MainWindow", "Seleccionar paciente", nullptr));
        CargarDatosPaciente->setText(QCoreApplication::translate("MainWindow", "Cargar datos test del paciente", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Gr\303\241ficas", nullptr));
        GraficaLineal->setText(QCoreApplication::translate("MainWindow", "Lineal", nullptr));
        GraficaInterpolada->setText(QCoreApplication::translate("MainWindow", "Interpolada", nullptr));
        DibujarGrafica->setText(QCoreApplication::translate("MainWindow", "Graficar", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Rojo (0-100)", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Azul(0-100)", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Verde(0-100)", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Datos", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "DNI", nullptr));
        ValorTipoVentana->setItemText(0, QCoreApplication::translate("MainWindow", "M", nullptr));
        ValorTipoVentana->setItemText(1, QCoreApplication::translate("MainWindow", "S", nullptr));

        ValorTipoVentana->setCurrentText(QCoreApplication::translate("MainWindow", "M", nullptr));
        ValorNivelVentana->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        ValorNivelVentana->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        ValorNivelVentana->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        ValorNivelVentana->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        ValorNivelVentana->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));
        ValorNivelVentana->setItemText(5, QCoreApplication::translate("MainWindow", "6", nullptr));
        ValorNivelVentana->setItemText(6, QCoreApplication::translate("MainWindow", "7", nullptr));
        ValorNivelVentana->setItemText(7, QCoreApplication::translate("MainWindow", "8", nullptr));

        GuardarMemoria->setText(QCoreApplication::translate("MainWindow", "Guardar test", nullptr));
        GuardarCaballo->setText(QCoreApplication::translate("MainWindow", "Guardar test", nullptr));
        Consola->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
