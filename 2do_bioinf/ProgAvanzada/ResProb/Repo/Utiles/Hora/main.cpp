#include <QCoreApplication>
#include "hora.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Hora Ho;
    char HoraUsuario[8];
    Ho.IngresoHora(HoraUsuario);
    Ho.HoraMayorActual(HoraUsuario);
    Ho.DifHoraActual(HoraUsuario);

    return a.exec();
}
