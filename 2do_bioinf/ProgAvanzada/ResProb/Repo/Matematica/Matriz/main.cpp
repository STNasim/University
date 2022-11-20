#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <matriz.h>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << "Código de test para clase Matriz: " << endl << endl;

    Matriz A, B, C, D, R;

    ifstream archi("datos_matrices.txt");

    if( archi.is_open() )
        cout << "El archivo está abierto...";
    else
        cout << "El archivo NO está abierto...";
    cout << endl << endl;


    // Carga desde un flujo de datos de entrada.
    archi >> A;
    archi >> B >> C; // Carga concatenada.
    //operator>>(operator>>(archi,B),C);

    archi.close(); // Se cierra el archivo.

//    // Carga a partir de cadena de caracteres.
        // A.operator=("[ 3 4 6; 8 9 7; 1 2 3; 5 6 7 ]");
// //        B = "[ 2 4 5 3; 2 4 6 6; 1 2 3 5 ]";
// //        C = "[ 10 10 10; 10 10 10; 10 10 10; 10 10 10 ]";
//    D = "[ 19 20 21; 22 23 24 ]";

    cout << "La matriz A es: " << endl
         << A << endl << endl;
//    cout << "La matriz B es: " << endl
//         << B << endl << endl;
//    cout << "La matriz C es: " << endl
//         << C << endl << endl;
//    cout << "La matriz D es: " << endl
//         << D << endl << endl;

//    D(0,0) = 1;
//    cout << "Se modifica el elemento (0,0) de D para que valga 1."
//         << endl << "La matriz D es ahora: " << endl
//         << D << endl << endl;

//    R = A + C;
//    cout << "La suma A + C es: " << endl
//         << R << endl << endl;

//    R = A - C;
//    cout << "La resta A - C es: " << endl
//         << R << endl << endl;

//    R = 4*C*2; // También funciona 2*C
//    cout << "El producto de 4*C*2 es: " << endl
//         << R << endl << endl;

//    ++C; // Suma 1 a todos los elementos de la matriz.
//    cout << "El resultado de ++C es: " << endl
//         << C << endl << endl;

//    C++; // Suma 1 a todos los elementos de la matriz.
//    cout << "El resultado de C++ es: " << endl
//         << C << endl << endl;

//    R = ++C; // Suma 1 a todos los elementos de la matriz.
//    cout << "El resultado R de R = ++C es: " << endl
//         << R << endl << endl;

//    R = C++; // Suma 1 a todos los elementos de la matriz.
//    cout << "El resultado R de R = C++ es: " << endl
//         << R << endl << endl;
//    cout << "La matriz C es: " << endl
//         << C << endl << endl;

//    R = A*B;
//    cout << "El producto A*B es: " << endl
//         << R << endl << endl;

//    R = !A;
//    cout << "La traspuesta de A es: " << endl
//         << R << endl << endl;

//    cout << "Las matrices A y C son "
//         << ( A == C ? "Iguales" : "Distintas")
//         << endl << endl;

//    Matriz E = A;
//    cout << "Las matrices A y E son "
//         << ( A != E ? "Distintas" : "Iguales")
//         << endl << endl;
    return a.exec();
}
