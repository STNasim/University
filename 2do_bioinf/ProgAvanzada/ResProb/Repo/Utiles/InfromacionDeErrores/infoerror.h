#ifndef INFOERROR_H
#define INFOERROR_H
#include <iostream>

class InfoError
{
public:
    InfoError();
private:
    bool Error=0;
    std::string Mensaje="Error en el programa";
};


#endif // INFOERROR_H
