#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    system("chcp 65001");
    ui->setupUi(this);
    tipoVentana='M';
    nivelVentana='1';
    ui->DibujarGrafica->hide();
    ui->CargarDatosPaciente->hide();
    datosCargados=false;
    pacienteSeleccionado=false;
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SeleccionarNivelCaballo_currentIndexChanged(int index)
{
    index++;
    caballo.SeleccionarNivel(index);
}

void MainWindow::on_EjecutarCaballo_clicked()
{
    caballo.IniciarJuego();
    ui->GuardarCaballo->show();
}

void MainWindow::on_EjecutarMemoria_clicked()
{
    memoria.IniciarJuego();
    ui->GuardarMemoria->show();
}

void MainWindow::on_SeleccionarNivelMemoria_currentIndexChanged(int index)
{
    index++;
    memoria.ElegirNivel(index);
}

void MainWindow::on_SeleccionadorColor_currentIndexChanged(int index)
{
    if(index==0)
        memoria.ElegirColorFondo();
    if(index==1)
        memoria.ElegirColorFondo(1.0f,1.0f,1.0f);
    if(index==2)
        memoria.ElegirColorFondo(1.0f,0.0f,0.0f);
    if(index==3)
        memoria.ElegirColorFondo(0.0f,1.0f,0.0f);
    if(index==4)
        memoria.ElegirColorFondo(0.0f,0.0f,1.0f);
    if(index==5)
        memoria.ElegirColorFondo(1.0f,1.0f,0.0f);
    if(index==6)
        memoria.ElegirColorFondo(1.0f,0.0f,1.0f);
    if(index==7)
        memoria.ElegirColorFondo(0.0f,1.0f,1.0f);
    if(index==8)
        memoria.ElegirColorFondo(rojo,verde,azul);
}

void MainWindow::on_CartasBocaArriba_toggled(bool checked)
{
    memoria.MostrarAlInicio(checked);
}

void MainWindow::on_TiempoMostrar2Distintas_valueChanged(int arg1)
{
    memoria.ElegirTiempoAlFallar(arg1);
}

void MainWindow::on_ColorRojo_valueChanged(int arg1)
{
    if(arg1>100)
        arg1=100;
    rojo=arg1/100.00;
    if(ui->SeleccionadorColor->currentIndex()==8)
        memoria.ElegirColorFondo(rojo,verde,azul);
}

void MainWindow::on_ColorVerde_valueChanged(int arg1)
{
    if(arg1>100)
        arg1=100;
    verde=arg1/100.00;
    if(ui->SeleccionadorColor->currentIndex()==8)
        memoria.ElegirColorFondo(rojo,verde,azul);
}

void MainWindow::on_ColorAzul_valueChanged(int arg1)
{
    if(arg1>100)
        arg1=100;
    azul=arg1/100.00;
    if(ui->SeleccionadorColor->currentIndex()==8)
        memoria.ElegirColorFondo(rojo,verde,azul);
}

void MainWindow::on_TiempoMostrarCartasInicio_valueChanged(int arg1)
{
    memoria.TiempoMostrarAlInicio(arg1);
}

void MainWindow::on_SeleccionarNivelMemoria_activated(int index)
{
    index++;
    memoria.ElegirNivel(index);
}

void MainWindow::on_CargarPacientes_clicked()
{
    if(datos.CargarPacientes())
    {
        mostrar="Pacientes cargados";
        ui->Consola->setText(mostrar);
    }
}

void MainWindow::on_AgregarPaciente_clicked()
{
    if(datos.AgregarPaciente(DNIVentana,datosVentana))
    {
        mostrar="Paciente agregado";
        ui->Consola->setText(mostrar);
    }
}

void MainWindow::on_ObtenerNivelMaximoMemoria_clicked()
{
    ui->MostrarNivelMemoria->display(memoria.ObtenerNivelSuperado());
}

void MainWindow::on_ObtenerTiempoMaximoMemoria_clicked()
{
    ui->MostrarTiempoMemoria->display(memoria.ObtenerTiempoNivelSuperado());
}

void MainWindow::on_ObtenerNivelMaximoCaballo_clicked()
{
    ui->MostrarNivelCaballo->display(caballo.ObtenerNivelSuperado());
}

void MainWindow::on_ObtenerTiempoMaximoCaballo_clicked()
{
    ui->MostrarTiempoCaballo->display(caballo.ObtenerTiempoSuperado());
}

void MainWindow::on_ModificarPaciente_clicked()
{
    if(datos.ModificarPaciente(DNIVentana,datosVentana))
        mostrar="Paciente modificado";
    ui->Consola->setText(mostrar);
}

void MainWindow::on_CargarDatosPaciente_clicked()
{  
    ui->Consola->setText(QString::fromStdString(datos.CargarDatosPaciente()));
    datosCargados=true;
}

void MainWindow::on_SeleccionarPaciente_clicked()
{
    if(datos.SeleccionarPaciente(DNIVentana))
    {
        mostrar="Paciente seleccionado";
        ui->CargarDatosPaciente->show();
        pacienteSeleccionado=true;
    }
    ui->Consola->setText(mostrar);
}

void MainWindow::on_GraficaLineal_toggled(bool checked)
{
    funciones.MostrarLineal(checked);
    if(checked)
        ui->DibujarGrafica->show();
    else if(!ui->GraficaInterpolada->checkState())
        ui->DibujarGrafica->hide();

}

void MainWindow::on_GraficaInterpolada_toggled(bool checked)
{
    funciones.MostrarInterpolada(checked);
    if(checked)
        ui->DibujarGrafica->show();
    else if(!ui->GraficaLineal->checkState())
        ui->DibujarGrafica->hide();
}

void MainWindow::on_DibujarGrafica_clicked()
{
    if((datosCargados) and (datos.ObtenerDatosPaciente(tipoVentana,nivelVentana).size()!=0))
    {
        funciones.CargarDatos(datos.ObtenerDatosPaciente(tipoVentana,nivelVentana));
        graficador.limpiarDibujos();
        graficador.cargarDibujo(&funciones);
        graficador.mostrar(500,500);
    }
    else
    {
        mostrar="No hay datos";
        ui->Consola->setText(mostrar);
    }
}

void MainWindow::on_ValorNivelVentana_currentIndexChanged(int index)
{
    index++;
    nivelVentana= '0' + index;

}

void MainWindow::on_ValorNivelVentana_activated(int index)
{
    index++;
    nivelVentana= '0' + index;
}

void MainWindow::on_ValorTipoVentana_currentIndexChanged(int index)
{
    if(index==0)
        tipoVentana='M';
    else
        tipoVentana='S';
}

void MainWindow::on_ValorTipoVentana_activated(int index)
{
    if(index==0)
        tipoVentana='M';
    else
        tipoVentana='S';
}

void MainWindow::on_GuardarMemoria_clicked()
{
    if(memoria.ObtenerNivelSuperado()!=0 and memoria.ObtenerTiempoNivelSuperado() and pacienteSeleccionado)
    {
        if(datos.GuardarTest('M','0' + (memoria.ObtenerNivelSuperado()),(int)memoria.ObtenerTiempoNivelSuperado()))
        {
            mostrar="Datos guardados";
        }
    }
    else
        mostrar="No se pueden guardar los datos";
    ui->Consola->setText(mostrar);

}

void MainWindow::on_GuardarCaballo_clicked()
{
    datos.GuardarTest('S','0' + (caballo.ObtenerNivelSuperado()),(int)caballo.ObtenerTiempoSuperado());
}

void MainWindow::on_VentanaDNI_textChanged()
{
    aux=ui->VentanaDNI->toPlainText();
    DNIVentana=aux.toInt();
}

void MainWindow::on_VentanaDatos_textChanged()
{
    aux=ui->VentanaDatos->toPlainText();
    datosVentana=aux.toStdString();
}
