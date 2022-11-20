#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "..\JuegoSaltoCaballo\juegosaltocaballo.h"
#include "..\JuegoDeMemoria\juegodememoria.h"
#include "..\Funcionalidades\desempenio.h"
#include "..\Funcionalidades\manejoDatos.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QApplication *PptrApp);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_SeleccionarNivelCaballo_currentIndexChanged(int index);

    void on_EjecutarCaballo_clicked();

    void on_EjecutarMemoria_clicked();

    void on_SeleccionarNivelMemoria_currentIndexChanged(int index);

    void on_SeleccionadorColor_currentIndexChanged(int index);

    void on_CartasBocaArriba_toggled(bool checked);

    void on_TiempoMostrar2Distintas_valueChanged(int arg1);

    void on_ColorRojo_valueChanged(int arg1);

    void on_ColorVerde_valueChanged(int arg1);

    void on_ColorAzul_valueChanged(int arg1);

    void on_TiempoMostrarCartasInicio_valueChanged(int arg1);

    void on_SeleccionarNivelMemoria_activated(int index);

    void on_CargarPacientes_clicked();

    void on_AgregarPaciente_clicked();

    void on_ObtenerNivelMaximoMemoria_clicked();

    void on_ObtenerTiempoMaximoMemoria_clicked();

    void on_ObtenerNivelMaximoCaballo_clicked();

    void on_ObtenerTiempoMaximoCaballo_clicked();

    void on_ModificarPaciente_clicked();

    void on_CargarDatosPaciente_clicked();

    void on_SeleccionarPaciente_clicked();

    void on_GraficaLineal_toggled(bool checked);

    void on_GraficaInterpolada_toggled(bool checked);

    void on_DibujarGrafica_clicked();

    void on_ValorNivelVentana_currentIndexChanged(int index);

    void on_ValorNivelVentana_activated(int index);

    void on_ValorTipoVentana_currentIndexChanged(int index);

    void on_ValorTipoVentana_activated(int index);

    void on_GuardarMemoria_clicked();

    void on_GuardarCaballo_clicked();

    void on_VentanaDNI_textChanged();

    void on_VentanaDatos_textChanged();

private:
    //Gestion
    char tipoVentana;
    char nivelVentana;
    string datosVentana;
    int DNIVentana;
    bool datosCargados;
    bool pacienteSeleccionado;

    QString mostrar,aux;
    float rojo=0.0;
    float verde=0.0;
    float azul=0.0;
    Ui::MainWindow *ui;
    JuegoDeMemoria memoria;
    JuegoSaltoCaballo caballo;
    ManejoDatos datos;
    Desempenio funciones;
    Graficador2D graficador;
};
#endif // MAINWINDOW_H
