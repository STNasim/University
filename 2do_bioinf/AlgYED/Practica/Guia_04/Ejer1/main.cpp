#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try
    {
        stack<string> pila;
        string expresion;
        ifstream lectura;
        lectura.open("../Expresion.txt",ios::in);
        if(lectura.is_open())
            getline(lectura,expresion,'\n');
        else
        {
            cout<<"Escriba la expresion: "<<endl;
            getline(cin,expresion,'\n');
        }
        cout<<expresion<<" = ";

        for(unsigned int i=0;i<expresion.size();i++)
        {
            string caracter;
            caracter.push_back(expresion[i]);
            if(caracter!=" ")
            {
                if(caracter=="+" || caracter=="-" || caracter=="*" || caracter=="/")
                {
                    double numero2= stod(pila.top());
                    pila.pop();
                    double numero1= stod(pila.top());
                    pila.pop();
                    if(caracter=="+")
                        pila.push(to_string(numero1+numero2));
                    if(caracter=="-")
                        pila.push(to_string(numero1-numero2));
                    if(caracter=="*")
                        pila.push(to_string(numero1*numero2));
                    if(caracter=="/")
                        pila.push(to_string(numero1/numero2));
                }
                else
                {
                    while(expresion[i+1]!=' ')
                    {
                        caracter.push_back(expresion[i+1]);
                        i++;
                    }
                    pila.push(caracter);
                }
            }
            caracter.clear();
        }
        cout<<pila.top()<<endl;

        lectura.close();
    }
    catch (string mje)
    {
        cout << "Error: " << mje << endl;
    }
    catch (...)
    {
        cout << "Error indeterminado..." << endl;
    }
    cout << "Fin de la prueba..." << endl;
    return a.exec();
}
