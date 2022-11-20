#include <QCoreApplication>
#include <OrdenamientosBasicos.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    ArregloDin arr;

//    arr.agregar(2);
//    arr.agregar(4);
//    arr.agregar(6);
//    arr.agregar(7);
//    arr.agregar(1);
//    arr.agregar(3);
//    arr.agregar(8);
//    arr.agregar(5);

//    mostrarArr(arr);
//    cout<<endl;

//    //ord_burbuja(arr);
//    ord_insercion(arr);

//    mostrarArr(arr);
//    cout<<endl;

    deque<int> mydeque(2,100);

    mydeque.push_front(200);
    mydeque.push_front(300);
    mydeque.push_back(99);

    for(unsigned int i=0;i<mydeque.size();i++)
    {
        cout<<mydeque[i]<<"  ";
    }
    cout<<endl;
    ord_insercion(mydeque);

    for(unsigned int i=0;i<mydeque.size();i++)
    {
        cout<<mydeque[i]<<"  ";
    }
    return a.exec();
}
