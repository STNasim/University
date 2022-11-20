#include "interfaz.h"

Interfaz::Interfaz(QApplication *ptrApp)
{
    pacienteSeleccionado=false;
    datosCargados=false;
    graficador.setPtr_app(ptrApp);
    memoria.SetPuntero(ptrApp);
    caballo.SetPuntero(ptrApp);
}

void Interfaz::InterfazInicio()
{
    int aux=0;
    system("CLS");
    std::cout<<"Bienvenido. seleccione una opción: "<<std::endl
       <<"1. Datos y gráficas"<<std::endl
      <<"2. Juego de memoria"<<std::endl
     <<"3. Juego del salto del caballo"<<std::endl
    <<"4. Salir"<<std::endl;
    std::cin>>aux;
    while(aux<=0 or aux>=5)
        std::cin>>aux;
    system("CLS");
    if(aux==1)
        InterfazDatosYGraficas();
    if(aux==2)
        InterfazMemoria();
    if(aux==3)
        InterfazCaballo();
    if(aux==4)
        exit(0);
}

void Interfaz::InterfazDatosYGraficas()
{
    int opcion=0;
    int DNI;
    std::string datosIngresados;
    std::cout<<"Interfaz de datos y gráficas: "<<std::endl
       <<"1. Cargar pacientes a memoria"<<std::endl
      <<"2. Agregar un paciente"<<std::endl
     <<"3. Modificar datos de un paciente"<<std::endl
    <<"4. Seleccionar un paciente"<<std::endl
    <<"5. Cargar los datos del paciente seleccionado"<<std::endl
    <<"6. Graficar segun los datos de test cargados"<<std::endl
    <<"7. Volver"<<std::endl;
    std::cin>>opcion;
    while(opcion<=0 or opcion>=8)
        std::cin>>opcion;
    system("CLS");
    if(opcion==1)
    {
        if(datos.CargarPacientes())
        {
            std::cout<<"Pacientes cargados con éxito"<<std::endl;
            datosCargados=true;
        }
        else
            std::cout<<"No se pudieron cargar los pacientes"<<std::endl;
    }
    if(opcion==2)
    {
        std::cout<<"Ingrese el DNI del paciente a agregar"<<std::endl;
        std::cin>>DNI;
        std::cout<<"Ingrese los datos a agregar, finalizados por un punto(.)"<<std::endl;
        getline(std::cin,datosIngresados,'.');
        datosIngresados.erase(datosIngresados.begin());
        if(datos.AgregarPaciente(DNI,datosIngresados))
            std::cout<<"Paciente agregado con éxito"<<std::endl;
        else
            std::cout<<"No se pudo agregar al paciente"<<std::endl;
    }
    if(opcion==3)
    {
        std::cout<<"Ingrese el DNI del paciente a modificar"<<std::endl;
        std::cin>>DNI;
        std::cout<<"Ingrese los datos a establecer, finalizados por un punto(.)"<<std::endl;
        getline(std::cin,datosIngresados,'.');
        datosIngresados.erase(datosIngresados.begin());
        if(datos.ModificarPaciente(DNI,datosIngresados))
            std::cout<<"Paciente modificiado con éxito"<<std::endl;
        else
            std::cout<<"No se pudo modificar al paciente"<<std::endl;
    }
    if(opcion==4)
    {
        if(datosCargados)
        {
            std::cout<<"Ingrese el DNI del paciente a seleccionar"<<std::endl;
            std::cin>>DNI;
            if(datos.SeleccionarPaciente(DNI))
            {
                std::cout<<"Paciente seleccionado"<<std::endl;
                pacienteSeleccionado=true;
            }
            else
            {
                std::cout<<"No se pudo seleccionar al paciente"<<std::endl;
                pacienteSeleccionado=false;
            }
        }
        else
            std::cout<<"No se han cargado datos aún"<<std::endl;
    }
    if(opcion==5)
    {
        if(pacienteSeleccionado)
        {
            std::string aux=datos.CargarDatosPaciente();
            if(aux.empty())
                std::cout<<"No hay datos para este paciente"<<std::endl;
        }
        else
            std::cout<<"No se ha seleccionado paciente"<<std::endl;

    }
    if(opcion==6)
    {
        if(pacienteSeleccionado)
        {
            char tipo;
            char nivel;
            int opcion2;
            std::cout<<"Ingrese el caracter del test (M o S)"<<std::endl;
            std::cin>>tipo;
            while(tipo!='M' and tipo!='S')
            {
                std::cout<<"Caracter inválido"<<std::endl;
                std::cin>>tipo;
            }
            std::cout<<"Ingrese el nivel del test (1 a 8)"<<std::endl;
            std::cin>>nivel;
            while(nivel!='1' and nivel!='2' and nivel!='3' and nivel!='4'
                  and nivel!='5' and nivel!='6' and nivel!='7' and nivel!='8')
            {
                std::cout<<"Caracter inválido"<<std::endl;
                std::cin>>nivel;
            }
            if(datos.ObtenerDatosPaciente(tipo,nivel).size()==0)
            {
                std::cout<<"No hay datos relacionados"<<std::endl;
                InterfazDatosYGraficas();
            }
            funciones.CargarDatos(datos.ObtenerDatosPaciente(tipo,nivel));
            std::cout<<"1. Gráfica lineal"<<std::endl
               <<"2. Gráfica Interpolada"<<std::endl
              <<"3. Ambas"<<std::endl;
            std::cin>>opcion2;
            while(opcion2>=4 or opcion2<=0)
            {
                std::cout<<"Opción inválida"<<std::endl;
                std::cin>>opcion2;
            }
            if(opcion2==1)
                funciones.MostrarLineal(true);
            if(opcion2==2)
                funciones.MostrarInterpolada(true);
            if(opcion2==3)
            {
                funciones.MostrarLineal(true);
                funciones.MostrarInterpolada(true);
            }
            graficador.limpiarDibujos();
            graficador.cargarDibujo(&funciones);
            graficador.mostrar(500,500);
            funciones.MostrarLineal(false);
            funciones.MostrarInterpolada(false);
        }
        else
            std::cout<<"No se ha seleccionado paciente"<<std::endl;
    }
    if(opcion==7)
        InterfazInicio();
    else
        InterfazDatosYGraficas();
}

void Interfaz::InterfazMemoria()
{
    int opcion=0;
    float opcion2=0;
    std::cout<<"Interfaz de juego de memoria: "<<std::endl
       <<"1. Seleccionar nivel inicial"<<std::endl
      <<"2. Establecer tiempo al girar dos cartas diferentes"<<std::endl
     <<"3. Establecer color de fondo"<<std::endl
    <<"4. Elegir si comenzar o no con cartas boca arriba"<<std::endl
    <<"5. Establecer tiempo que las cartas comienzan boca arriba"<<std::endl
    <<"6. Mostrar tiempo del ultimo nivel superado"<<std::endl
    <<"7. Mostar nivel maximo superado en el ultimo test"<<std::endl
    <<"8. Ejecutar juego"<<std::endl
    <<"9. Guardar test"<<std::endl
    <<"10. Volver"<<std::endl;
    std::cin>>opcion;
    while(opcion<=0 or opcion>=11)
        std::cin>>opcion;
    system("CLS");
    if(opcion==1)
    {
        std::cout<<"Ingrese el nivel (1 a 8)"<<std::endl;
        std::cin>>opcion2;
        while(opcion2<=0 or opcion2>=9)
            std::cin>>opcion2;
        memoria.ElegirNivel((int)opcion2);
    }
    if(opcion==2)
    {
        std::cout<<"Ingrese el tiempo que quiere establecer"<<std::endl;
        std::cin>>opcion2;
        memoria.ElegirTiempoAlFallar(opcion2);
    }
    if(opcion==3)
    {
        float rojo,verde,azul;
        std::cout<<"Ingrese la intensidad del color rojo(0.0 a 1.0)"<<std::endl;
        std::cin>>rojo;
        if(rojo>1.0)
            rojo=1.0;
        std::cout<<"Ingrese la intensidad del color verde(0.0 a 1.0)"<<std::endl;
        std::cin>>verde;
        if(verde>1.0)
            verde=1.0;
        std::cout<<"Ingrese la intensidad del color azul(0.0 a 1.0)"<<std::endl;
        std::cin>>azul;
        if(azul>1.0)
            azul=1.0;
        memoria.ElegirColorFondo(rojo,verde,azul);
    }
    if(opcion==4)
    {
        std::cout<<"Ingrese 1 para iniciar con cartas boca arriba o 2 para no hacerlo"<<std::endl;
        std::cin>>opcion2;
        while(opcion2!=1 and opcion2!=2)
        {
            std::cout<<"Opción inválida"<<std::endl;
            std::cin>>opcion2;
        }
        if(opcion2==1)
            memoria.MostrarAlInicio(true);
        else
            memoria.MostrarAlInicio(false);
    }
    if(opcion==5)
    {
        std::cout<<"Ingrese el tiempo que quiere establecer"<<std::endl;
        std::cin>>opcion2;
        memoria.TiempoMostrarAlInicio((int)opcion2);
    }
    if(opcion==6)
        std::cout<<"Ultimo nivel superado: "<<memoria.ObtenerNivelSuperado()<<std::endl;
    if(opcion==7)
        std::cout<<"Tiempo de ultimo nivel superado: "<<memoria.ObtenerTiempoNivelSuperado()<<" segundos"<<std::endl;
    if(opcion==8)
        memoria.IniciarJuego();
    if(opcion==9)
    {
        if(pacienteSeleccionado)
        {
            if(memoria.ObtenerNivelSuperado()!=0 and memoria.ObtenerTiempoNivelSuperado()!=0)
                datos.GuardarTest('M','0'+memoria.ObtenerNivelSuperado(),(int)memoria.ObtenerTiempoNivelSuperado());
            else
                std::cout<<"No se ha hecho ningún test"<<std::endl;
        }
        else
            std::cout<<"No se puede guardar, no se ha seleccionado un paciente, vuelva y seleccionelo"<<std::endl;
    }
    if(opcion==10)
        InterfazInicio();
    else
        InterfazMemoria();
}

void Interfaz::InterfazCaballo()
{
    int opcion=0;
    float opcion2=0;
    std::cout<<"Interfaz de juego del salto del caballo: "<<std::endl
       <<"1. Seleccionar nivel inicial"<<std::endl
      <<"2. Mostrar tiempo del ultimo nivel superado"<<std::endl
     <<"3. Mostrar nivel maximo superado en el ultimo test"<<std::endl
    <<"4. Ejecutar juego"<<std::endl
    <<"5. Guardar test"<<std::endl
    <<"6. Volver"<<std::endl;
    std::cin>>opcion;
    while(opcion<=0 or opcion>=7)
        std::cin>>opcion;
    system("CLS");
    if(opcion==1)
    {
        std::cout<<"Ingrese el nivel (1 a 8)"<<std::endl;
        std::cin>>opcion2;
        while(opcion2<=0 or opcion2>=9)
            std::cin>>opcion2;
        caballo.SeleccionarNivel((int)opcion2);
    }
    if(opcion==2)
        std::cout<<"Tiempo de ultimo nivel superado: "<<caballo.ObtenerTiempoSuperado()<<" segundos"<<std::endl;
    if(opcion==3)
        std::cout<<"Ultimo nivel superado: "<<caballo.ObtenerNivelSuperado()<<std::endl;
    if(opcion==4)
    {
        std::cout<<"Presione S para indicar que la solución es correcta y N para incorrecta"<<std::endl;
        caballo.IniciarJuego();
    }
    if(opcion==5)
    {
        if(pacienteSeleccionado)
        {
            if(caballo.ObtenerNivelSuperado()!=0 and caballo.ObtenerTiempoSuperado()!=0)
                datos.GuardarTest('S','0'+caballo.ObtenerNivelSuperado(),(int)caballo.ObtenerTiempoSuperado());
            else
                std::cout<<"No se ha hecho ningún test"<<std::endl;
        }
        else
            std::cout<<"No se puede guardar, no se ha seleccionado un paciente, vuelva y seleccionelo"<<std::endl;
    }
    if(opcion==6)
        InterfazInicio();
    else
        InterfazCaballo();
}
