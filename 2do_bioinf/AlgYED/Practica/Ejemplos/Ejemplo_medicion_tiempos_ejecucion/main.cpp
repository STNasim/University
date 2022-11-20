/*!
 *  \brief      Código de ejemplo para medición de tiempos de ejecución.
 *  \details    Código de ejemplo para medición de tiempos de ejecución.
 *  \author     Jordán F. Insfrán.
 *  \version    1.0.0
 *  \date       Fecha de creación: 2020-08-14
 *  \date       Fecha de última modificación: ver repositorio.
 *  \pre        Disponer de biblioteca chrono instalada. La misma corresponde al estándar C++11.
 *  \bug        -
 *  \warning    La resolución no necesariamente representa la precisión y/o
 *              exactitud de las mediciones. Se debe sostener esta afirmación con
 *              documentación respaldatoria antes de aplicar este código a una apliación
 *              real.
 *  \copyright  Ver documento en repositorio.
 */

#include <QCoreApplication>

#include <iostream>

#include "cronometro.h"

// Función global cuyo tiempo de ejecución se medirá
long long fun(long m){
    long long a = 0LL;
    for(long k=0;k<m;++k) a += k;
    return a;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // ************************************************************
    // ******* Ejemplo de uso de cronómetro con una función *******
    // ************************************************************
    Cronometro cron;

    long m = 200*1000*1000;

    cron.iniciarCronometro();       // Se inicia cronometro.
    long long resultado = fun(m);   // Se lleva a cabo una acción cuya
                                    //  duración se desea medir.
    cron.pararCronometro();         // Se detiene cronómetro.

    double delta_t = cron.getDuracionEnSegundos();

    std::cout << "Resolución del cronómetro en segundos: "
              << cron.getResolucionEnSegundos() << std::endl;
    std::cout << "Tiempo transcurrido en segundos: "
              << delta_t << std::endl;
    std::cout << "Resultado que se obtuvo: "
              << resultado << std::endl;

    return a.exec();
}
