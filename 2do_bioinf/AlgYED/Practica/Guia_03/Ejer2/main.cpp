#include <QCoreApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try
    {
        list<int> lista (5,20);
        for(auto iterator=lista.begin();iterator!=lista.end();iterator++)
        {
            cout<<*iterator<<", ";
        }
        cout<<endl;
        lista.push_front(2);
        lista.push_front(10);
        for(auto iterator=lista.begin();iterator!=lista.end();iterator++)
        {
            cout<<*iterator<<", ";
        }
        cout<<endl;
        lista.push_back(9);
        lista.push_back(7);
        for(auto iterator=lista.begin();iterator!=lista.end();iterator++)
        {
            cout<<*iterator<<", ";
        }
        cout<<endl;
        auto it=lista.begin();
        advance(it,lista.size()/2);
        lista.insert(it,7);
        lista.insert(it,23);
        lista.insert(it,86);
        lista.insert(it,34);
        lista.insert(it,76);
        for(auto iterator=lista.begin();iterator!=lista.end();iterator++)
        {
            cout<<*iterator<<", ";
        }
        cout<<endl;
        lista.sort();
        for(auto iterator=lista.begin();iterator!=lista.end();iterator++)
        {
            cout<<*iterator<<", ";
        }
        cout<<endl;
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
