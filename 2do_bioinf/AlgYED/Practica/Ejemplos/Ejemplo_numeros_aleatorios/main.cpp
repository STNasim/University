/*!
 *  \brief      Código de ejemplo para generación de números pseudoaleatorios.
 *  \details    Código de ejemplo para generación de números pseudoaleatorios.
 *              Se muestran estrategias para generar números reales y enteros con
 *              diferentes distribuciones así como sus referencias.
 *  \author     Jordán F. Insfrán.
 *  \version    1.0.0
 *  \date       Fecha de creación: 2020-08-12
 *  \date       Fecha de última modificación: ver repositorio.
 *  \pre        -
 *  \bug        -
 *  \warning    Los números generados son pseudoaleatorios y no estrictamente aleatorios
 *  \copyright  Ver documento en repositorio.
 */

#include <QCoreApplication>

#include <iostream> // flujos de entrada y salida
#include <random>   // generador de números pseudoaleatorios y distribuciones
#include <string>   // cadenas de caracteres
#include <ctime>    // valor temporal para generar semilla de números pseudoaleatorios

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // ***** variables auxiliares para usos múltiples *****
    int i;
    // ****************************************************

    // ****************************************************************************
    // Semilla para el generador. (Permite generar diferentes secuencias numéricas
    // ****************************************************************************
    unsigned semilla = time(0);

    cout << "Semilla: " << semilla << endl << endl;

    // *********************************************************
    // Generador
    // *********************************************************
    default_random_engine generador(semilla);
    // knuth_b generador(semilla);
    //      Fuente: http://www.cplusplus.com/reference/random/default_random_engine/

    cout << "Generador produciendo valores entre "
         << generador.min() << " y " << generador.max() << endl;
    for(i=1; i<=10; ++i)
        cout << "Lanzamiento " << i << ":\t" << generador() << endl;
    cout << endl << endl;

    // *********************************************************
    // Parámetros para experimentos
    // *********************************************************
    const int n_lanzamientos = 200000;  // número de lanzamientos (o experimentos)
    const int n_estrellas = 300;        // número de estrellas
    const int n_intervalos = 15;        // número de intervalos

    // *********************************************************
    // Distribución normal de números reales
    //      Fuente: http://www.cplusplus.com/reference/random/normal_distribution/
    // *********************************************************
    normal_distribution<double> dist_norm(5.0,2.0); // (media, desvío estándar)
    int p[n_intervalos] = {}; // valor inicial 0 en todas las posiciones
    double num;
    for (i=0; i<n_lanzamientos; ++i) {
        num = dist_norm(generador);
        if ( num >= 0.0 && num < n_intervalos)
            ++p[int(num)];
    }
    cout << "Distribución normal (o gaussiana) de reales con media 5.0 y desvío 2.0:" << endl;
    string cad;
    for (i=0; i<n_intervalos; ++i) {
        cad = to_string(i) + '-' + to_string(i+1) + ": ";
        cad.resize(7, ' ');
        cout << cad;
        cout << string(p[i]*n_estrellas/n_lanzamientos,'*') << endl;
    }
    cout << endl;

    // *********************************************************
    // Distribución uniforme de números enteros
    //      Fuente: http://www.cplusplus.com/reference/random/uniform_int_distribution/
    // *********************************************************
    uniform_int_distribution<int> dist_unif(0, n_intervalos-1); // rango cerrado: [0, n_intervalos - 1]
    int q[n_intervalos] = {};
    int ent;
    for (i=0; i<n_lanzamientos; ++i) {
        ent = dist_unif(generador);
        ++q[ent];
    }
    cout << "Distribución uniforme de enteros [0, " << n_intervalos-1 << "]:" << endl;
    for (i=0; i<n_intervalos; ++i)
        cout << i << ": " << string(q[i]*n_estrellas/n_lanzamientos,'*') << endl;
    cout << endl;

    // *********************************************************
    // Distribución uniforme de reales
    //      Fuente: http://www.cplusplus.com/reference/random/uniform_real_distribution/
    // *********************************************************
    uniform_real_distribution<long double> dist_unif_real(0.0, 1.0); // rango cerrado: [0, 9]
    int r[n_intervalos] = {};
    long double real;
    for (i=0; i<n_lanzamientos; ++i) {
        real = dist_unif_real(generador);
        ++r[int(n_intervalos * real)];
    }
    cout << "Distribución uniforme de reales (long double) [0.0, 1.0]:" << endl;
    cout << fixed; cout.precision(2);
    for (int i=0; i<n_intervalos; ++i){
        cout << float(i)/n_intervalos << "-" << float(i+1)/n_intervalos
             << ": " << string(r[i]*n_estrellas/n_lanzamientos,'*') << endl;
    }
    cout << endl;

    // *********************************************************
    // Distribución discreta
    //      Fuente: http://www.cplusplus.com/reference/random/discrete_distribution/
    // *********************************************************
    vector<int> prob(n_intervalos); // probabilidades discretas
    for(i=0; i<n_intervalos; ++i) prob[i]= i%5; // probabilidad escalonada
    discrete_distribution<int> dist_disc(prob.begin(), prob.end());
    int s[n_intervalos] = {};
    for (i=0; i<n_lanzamientos; ++i) {
        ent = dist_disc(generador);
        ++s[ent];
    }
    cout << "Distribución discreta de enteros [0, " << n_intervalos-1 << "]:" << endl;
    for (i=0; i<n_intervalos; ++i)
        cout << i << ": " << string(s[i]*n_estrellas/n_lanzamientos,'*') << endl;
    cout << endl;

    // Otras distribuciones:
    //    Fuente: http://www.cplusplus.com/reference/random/

    return a.exec();
}
