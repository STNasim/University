#include "manejoDatos.h"

ManejoDatos::ManejoDatos()
{

}

bool ManejoDatos::CargarPacientes()
{
    bool retorno=false;
    std::ifstream archi;
    archi.open("DatosDePacientes.txt");
    if(archi.is_open())
    {
        retorno=true;
        int DNI;
        std::string datos;
        while(!archi.eof())
        {
            archi>>DNI;
            archi.ignore(1);
            getline(archi,datos);
            datosMemoria.insert(std::pair<int,std::string>(DNI,datos));
        }
    }
    archi.close();
    return retorno;
}

bool ManejoDatos::AgregarPaciente(int DNI, std::string datos)
{
    bool ok=false;
    std::ofstream archi;
    archi.open("DatosDePacientes.txt", std::ios::app);
    if(archi.is_open())
    {
        archi<<'\n'<<DNI<<" "<<datos;
        datosMemoria.insert(std::pair<int,std::string>(DNI,datos));
        ok=true;
    }
    archi.close();
    return ok;
}

bool ManejoDatos::ModificarPaciente(int DNI, std::string datos)
{
    bool ok=false;
    if(datosMemoria.erase(DNI)==1)
        datosMemoria.insert(std::pair<int,std::string>(DNI,datos));
    std::fstream archi;
    std::string extraccion, aux;
    archi.open("DatosDePacientes.txt",std::ios::in);
    if(archi.is_open())
    {
        while(!archi.eof())
        {
            getline(archi,aux,'\n');
            extraccion+=aux;
            extraccion+='\n';
        }
        extraccion.pop_back();
        aux= std::to_string(DNI);
        int inicio=extraccion.find(aux);
        if(inicio!=-1)
        {
            int fin=extraccion.find('\n',inicio);
            std::string linea=aux;
            linea+=" ";
            linea+=datos;
            extraccion.replace(inicio,fin-inicio,linea);
            ok=true;
        }
    }
    archi.close();
    if(ok)
    {
        archi.open("DatosDePacientes.txt",std::ios::out);
        if(archi.is_open())
            archi<<extraccion;
        archi.close();
    }
    return ok;
}

bool ManejoDatos::SeleccionarPaciente(int DNI)
{
    pacienteSeleccionado=datosMemoria.find(DNI);
    return (pacienteSeleccionado!=datosMemoria.end());
}

std::string ManejoDatos::CargarDatosPaciente()
{
    datosPaciente.clear();
    datosPaciente.resize(0);
    test extraccion;
    std::fstream archi;
    std::string retorno;
    retorno.clear();
    archi.open("EstudiosDePacientes_SEMA.dat",std::ios::binary | std::ios::in | std::ios::ate );
    if(archi.is_open())
    {
        int aux=archi.tellg();
        aux/=sizeof (test);
        archi.seekg(0);
        for(int n=0;n<aux;n++)
        {
            archi.read((char*)&extraccion,sizeof (test));
            if(extraccion.DNI==pacienteSeleccionado->first)
                datosPaciente.push_back(extraccion);
        }
        if(datosPaciente.size()>0)
        {
            retorno+=(std::to_string(pacienteSeleccionado->first));
            retorno+='\n';
            retorno+=pacienteSeleccionado->second;
            retorno+='\n';
            for(int i=0;i<(int)datosPaciente.size();i++)
            {
                retorno+="Test: ";
                retorno+=datosPaciente[i].tipo;
                retorno+=+"  - ";
                retorno+="Fecha: ";
                retorno+=(std::to_string(datosPaciente[i].anio));
                retorno+='/';
                if(datosPaciente[i].mes<10)
                    retorno+='0';
                retorno+=(std::to_string(datosPaciente[i].mes));
                retorno+='/';
                if(datosPaciente[i].dia<10)
                    retorno+='0';
                retorno+=(std::to_string(datosPaciente[i].dia));
                retorno+=" - ";
                retorno+="Hora: ";
                retorno+=(std::to_string(datosPaciente[i].horas));
                retorno+=":";
                if(datosPaciente[i].minutos<10)
                    retorno+='0';
                retorno+=(std::to_string(datosPaciente[i].minutos));
                retorno+=" hs - ";
                retorno+="Nivel: ";
                retorno+=(datosPaciente[i].nivel);
                retorno+=" - ";
                retorno+="Tiempo: ";
                retorno+=(std::to_string(datosPaciente[i].tiempo));
                retorno+=" segundos.";
                retorno+='\n';
            }
        }
    }
    archi.close();
    std::cout<<retorno;
    return retorno;
}

std::vector<int> ManejoDatos::ObtenerDatosPaciente(char tipo, char nivel)
{
    std::vector <int> retorno;

    for(int n=0;n<(int)datosPaciente.size();n++)
    {
        if((datosPaciente[n].tipo==tipo) and (datosPaciente[n].nivel==nivel))
        {
            retorno.push_back(datosPaciente[n].tiempo);
        }
    }

    return retorno;
}

bool ManejoDatos::GuardarTest(char tipo, char nivel, int tiempoTest)
{
    bool ok=false;
    std::fstream archi;
    archi.open("EstudiosDePacientes_SEMA.dat",std::ios::binary | std::ios::out | std::ios::app );
    if(archi.is_open())
    {
        time_t aux;
        time(&aux);
        struct tm *tiempo;
        tiempo= localtime(&aux);
        test guardado;

        guardado.DNI=pacienteSeleccionado->first;
        guardado.anio=(tiempo->tm_year+1900);
        guardado.mes=(tiempo->tm_mon+1);
        guardado.dia=(tiempo->tm_mday);
        guardado.horas=(tiempo->tm_hour);
        guardado.minutos=(tiempo->tm_min);
        guardado.tipo=tipo;
        guardado.nivel=nivel;
        guardado.tiempo=tiempoTest;
        archi.write((char*)&guardado,sizeof (test));
        ok=true;
    }
    archi.close();
    return ok;
}
