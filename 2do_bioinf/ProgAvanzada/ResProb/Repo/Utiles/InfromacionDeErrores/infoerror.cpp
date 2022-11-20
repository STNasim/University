#include "infoerror.h"

InfoError::InfoError()
{
    if(Error==0){
        std::cout<<Mensaje;
        Error=1;
    }
}
