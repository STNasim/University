import os
from distutils.version import StrictVersion

def set_r() -> None:
    """
    Setea el directorio de R y el directorio de los dll de R.
    """
    direcciones_r = os.listdir(r"C:\Program Files\R")
    # Filtrar las direcciones que no empiecen con 'R-' y quitarles el 'R-'
    direcciones_r = [d.replace('R-', '') for d in direcciones_r if os.path.isdir(os.path.join(r"C:\Program Files\R", d))]
    
    # Ordenar las direcciones de mayor a menor versión
    direcciones_r.sort(key=StrictVersion, reverse=True)

    direccion_ultimo_r = 'R-' + direcciones_r[0]  # Agregar el 'R-' al principio

    # Setear el directorio de los dll de R
    os.add_dll_directory(r"C:\Program Files\R\{}\bin\x64".format(direccion_ultimo_r))

    # Setear el directorio de R
    os.environ["R_HOME"] = r"C:\Program Files\R\{}".format(direccion_ultimo_r)