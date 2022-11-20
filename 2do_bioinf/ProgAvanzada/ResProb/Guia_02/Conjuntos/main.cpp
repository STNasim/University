#include <QCoreApplication>
#include <conjunto.h>

/*
<< para unir dos conjuntos. Ejemplo, si A = {1, 2, 3} y B = {3, 4, 5}, entonces A << B hará que A se transforme en A = {1, 2, 3, 4, 5}
>> para restar un conjunto a otro. Ejemplo, si A = {1, 2, 3} y B = {3, 4, 5}, entonces A >> B hará que A se transforme en A = {1, 2}. Es decir, se eliminan los elementos de B que están en A.
+ para añadir un elemento al conjunto. Ejemplo, si A = {1, 2, 3}, entonces B = A + 7 dará por resultado el conjunto B = {1, 2, 3, 7}.
- para restar un elemento al conjunto. Ejemplo, si A = {1, 2, 3}, entonces B = A - 3 dará por resultado el conjunto B = {1, 2}. Si el elemento a restar no se encuentra en el conjunto, el conjunto resultante es igual al conjunto minuendo.
== para saber si dos conjuntos son iguales.
!= para saber si dos conjuntos son distintos.
< para saber si el cardinal de un conjunto es menor que el de otro conjunto. Cardinal: es la cantidad de elementos de un conjunto.
() para saber si un elemento está en el conjunto.
 */

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Conjunto a,b,c,r;

    a.setElementos({1, 2, 3});
    b.setElementos({3, 4, 5});
    c.setElementos({6, 5});
    std::cout<<"El conjunto a es: "<<a<<std::endl;
    std::cout<<"El conjunto b es: "<<b<<std::endl;
    std::cout<<"El conjunto c es: "<<c<<std::endl;

    c<<b;
    std::cout<<"El conjunto c+b es: "<<c<<std::endl;

    a>>b;
    std::cout<<"El conjunto a-b es: "<<a<<std::endl;

    return app.exec();
}
