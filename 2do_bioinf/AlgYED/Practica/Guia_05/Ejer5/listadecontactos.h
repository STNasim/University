#ifndef LISTADECONTACTOS_H
#define LISTADECONTACTOS_H
#include <fstream>
#include <iostream>
#include "../../Repo/EstructurasDeDatos/ABB_AVL_template/abb_avl_template.h"
using namespace std;
using namespace abb_avl_template;

class ListaDeContactos
{
public:
    class Contacto
    {
    public:
        string correo="";
        int clave=0;
        string extra="";
        bool operator>(Contacto aux) const
        {
            bool retorno=false;
            if(clave>aux.clave)
                retorno=true;
            return retorno;
        }
        bool operator<(Contacto aux) const
        {
            bool retorno=false;
            if(clave<aux.clave)
                retorno=true;
            return retorno;
        }
        bool operator==(Contacto aux)
        {
            bool retorno=false;
            if(clave==aux.clave)
                retorno=true;
            return retorno;
        }
    };
    class RegistroCorreo
    {
    public:
        Contacto* contacto;
        string correo;
        bool operator>(RegistroCorreo aux) const
        {
            bool retorno=false;
            if(correo>aux.correo)
                retorno=true;
            return retorno;
        }
        bool operator<(RegistroCorreo aux) const
        {
            bool retorno=false;
            if(correo<aux.correo)
                retorno=true;
            return retorno;
        }
        bool operator==(RegistroCorreo aux)
        {
            bool retorno=false;
            if(correo==aux.correo)
                retorno=true;
            return retorno;
        }

    };
    ABB_AVL<Contacto> agendaClave;
    ABB_AVL<RegistroCorreo> agendaCorreo;
public:
    ListaDeContactos();
    void mostrar();
    void agregar(int clave, string correo, string extra);
    void agregar(Contacto contacto);
    void buscar(string correo);
    void buscar(int clave);
    bool borrar(string correo);
    bool borrar(int clave);
    void modificar(string correoViejo, string correoNuevo);
    void modificar(int claveVieja, int claveNueva);
};

#endif // LISTADECONTACTOS_H

//std::string to_string(ListaDeContactos::RegistroCorreo reg)
//{
//    string retorno="";
//    retorno+=std::to_string(reg.contacto->clave)+="/n";
//    retorno+=reg.contacto->correo+="\n";
//    retorno+=reg.contacto->extra;
//    return retorno;
//}
//std::string to_string(ListaDeContactos::Contacto contacto)
//{
//    string retorno="";
//    retorno+=std::to_string(contacto.clave)+="/n";
//    retorno+=contacto.correo+="\n";
//    retorno+=contacto.extra;
//    return retorno;
//}
ostream& operator<<(ostream& pOut, ListaDeContactos::Contacto contacto) {
    pOut<<"Clave: "<<contacto.clave<<endl;
    pOut<<"Correo: "<<contacto.correo<<endl;
    pOut<<"Extra: "<<contacto.extra;
    return pOut;
}

ostream& operator<<(ostream& pOut, ListaDeContactos::RegistroCorreo reg) {
    pOut<<"Clave: "<<reg.contacto->clave<<endl;
    pOut<<"Correo: "<<reg.contacto->correo<<endl;
    pOut<<"Extra: "<<reg.contacto->extra;
    return pOut;
}

ListaDeContactos::ListaDeContactos()
{
    ifstream lectura;
    lectura.open("../Ejer5/Contactos.txt",ios::in);

    while(!lectura.eof())
    {
        Contacto aux;
        lectura>>aux.clave;
        lectura.ignore(1);
        getline(lectura,aux.correo,' ');
        lectura.ignore(1);
        getline(lectura,aux.extra,'\n');
        agregar(aux);
    }
}

void ListaDeContactos::mostrar()
{
    cout<<agendaClave;
}

void ListaDeContactos::agregar(int clave, string correo, string extra)
{
    Contacto contacto;
    contacto.clave=clave;
    contacto.correo=correo;
    contacto.extra=extra;
    RegistroCorreo aux;
    aux.contacto=&contacto;
    aux.correo=contacto.correo;
    agendaClave.agregar(contacto);
    agendaCorreo.agregar(aux);
}

void ListaDeContactos::agregar(ListaDeContactos::Contacto contacto)
{
    RegistroCorreo aux;
    aux.contacto=&contacto;
    aux.correo=contacto.correo;
    agendaClave.agregar(contacto);
    agendaCorreo.agregar(aux);
}

void ListaDeContactos::buscar(string correo)
{
    RegistroCorreo reg;
    reg.correo=correo;
    if(agendaCorreo.completarDato(reg))
        cout<<reg;
    else
        cout<<"No encontrado";
}

void ListaDeContactos::buscar(int clave)
{
    Contacto aux;
    aux.clave=clave;
    if(agendaClave.completarDato(aux))
        cout<<aux<<endl;
    else
        cout<<"No encontrado";
}

bool ListaDeContactos::borrar(string correo)
{
    bool retorno=false;
    RegistroCorreo aux;
    aux.correo=correo;
    if(agendaCorreo.completarDato(aux))
    {
        agendaClave.borrar(aux.contacto[0]);
        agendaCorreo.borrar(aux);
        retorno=true;
    }
    return retorno;
}

bool ListaDeContactos::borrar(int clave)
{
    bool retorno=false;
    Contacto aux;
    aux.clave=clave;
    if(agendaClave.completarDato(aux))
    {
        RegistroCorreo borrado;
        borrado.correo=aux.correo;
        agendaCorreo.borrar(borrado);
        agendaClave.borrar(aux);
        retorno=true;
    }
    return retorno;
}

void ListaDeContactos::modificar(string correoViejo, string correoNuevo)
{
    Contacto contactoNuevo;
    RegistroCorreo registroViejo,registroNuevo;
    registroNuevo.correo=contactoNuevo.correo=correoNuevo;
    registroViejo.correo=correoViejo;
    agendaCorreo.completarDato(registroViejo);
    contactoNuevo.clave=registroViejo.contacto->clave;
    contactoNuevo.extra=registroViejo.contacto->extra;
    agendaClave.borrar(registroViejo.contacto[0]);
    agendaCorreo.borrar(registroViejo);
    agendaClave.agregar(contactoNuevo);
    registroNuevo.contacto=&contactoNuevo;
    agendaCorreo.agregar(registroNuevo);
}

void ListaDeContactos::modificar(int claveVieja, int claveNueva)
{
    Contacto contactoNuevo, contactoViejo;
    RegistroCorreo registroViejo, registroNuevo;
    contactoViejo.clave=contactoNuevo.clave=claveVieja;
    agendaClave.completarDato(contactoNuevo);
    contactoNuevo.clave=claveNueva;
    registroNuevo.correo=registroViejo.correo=contactoNuevo.correo;
    agendaClave.borrar(contactoViejo);
    agendaCorreo.borrar(registroViejo);
    agendaClave.agregar(contactoNuevo);
    registroNuevo.contacto=&contactoNuevo;
    agendaCorreo.agregar(registroNuevo);
}
