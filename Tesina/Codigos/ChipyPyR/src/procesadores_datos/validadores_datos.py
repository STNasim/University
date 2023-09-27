

class ValidadorDatosGrupos():
    """
    Clase que se encarga de validar los datos de los grupos.
    """
    @staticmethod
    def validar_datos(datos : list) -> bool:
        """
        Valida los datos de los grupos.

        :param datos: Lista con los nombres de los grupos.
        :type datos: list
        :return: True si los datos son validos, False en caso contrario.
        :rtype: bool
        """
        return ValidadorDatosGrupos.__validar_cantidad_grupos(datos) and \
        ValidadorDatosGrupos.__validar_elementos_vacios(datos) and \
        ValidadorDatosGrupos.__validar_nombres(datos)
    
    @staticmethod
    def __validar_cantidad_grupos(datos : list) -> bool:
        """
        Valida que haya al menos 2 grupos diferentes.

        :param datos: Lista con los nombres de los grupos.
        :type datos: list
        :return: True si los datos son validos, False en caso contrario.
        :rtype: bool
        """
        #Se revisa que haya al menos 2 grupos diferentes
        if len(set(datos)) < 2:
            raise ValueError("Debe haber al menos 2 grupos diferentes")
        return True

    @staticmethod
    def __validar_elementos_vacios(datos : list) -> bool:
        """
        Valida que no haya elementos vacios en la lista de grupos.

        :param datos: Lista con los nombres de los grupos.
        :type datos: list
        :return: True si los datos son validos, False en caso contrario.
        :rtype: bool
        """
        #Se revisa si en la lista de grupos hay algun elemento vacío
        if '' in datos or None in datos:
            raise ValueError("Hay elementos sin asignar a un grupo")
        return True
    
    @staticmethod
    def __validar_nombres(datos : list) -> bool:
        """
        Valida que los nombres de los grupos no contengan caracteres especiales (distintos a una letra o número)

        :param datos: Lista con los nombres de los grupos.
        :type datos: list
        :return: True si los datos son validos, False en caso contrario.
        :rtype: bool
        """
        for nombre in datos:
            if not nombre.isalnum():
                raise ValueError(f"El nombre {nombre} contiene caracteres especiales")
        return True
    
class ValidadorDatosMuestras():
    """
    Clase que se encarga de validar los datos de las muestras.
    """
    @staticmethod
    def validar_datos(datos : list) -> bool:
        """
        Valida los datos de las muestras.

        :param datos: Lista con los nombres de las muestras.
        :type datos: list
        :return: True si los datos son validos, False en caso contrario.
        :rtype: bool
        """
        return ValidadorDatosMuestras.__validar_datos_unicos(datos) and \
        ValidadorDatosMuestras.__validar_elementos_vacios(datos)
    
    @staticmethod
    def __validar_datos_unicos(datos : list) -> bool:
        """
        Valida que los nombres de las muestras sean únicos.

        :param datos: Lista con los nombres de las muestras.
        :type datos: list
        :return: True si los datos son validos, False en caso contrario.
        :rtype: bool
        """
        #Se revisa que los nombres de las muestras sean únicos
        if len(set(datos)) < len(datos):
            raise ValueError("Los nombres de las muestras deben ser únicos")
        return True

    @staticmethod
    def __validar_elementos_vacios(datos : list) -> bool:
        """
        Valida que no haya elementos vacios en la lista de muestras.

        :param datos: Lista con los nombres de las muestras.
        :type datos: list
        :return: True si los datos son validos, False en caso contrario.
        :rtype: bool
        """
        #se revisa si en la lista de muestras hay alguno vacío
        if '' in datos or None in datos:
            raise ValueError("Hay nombres de muestras vacios, borrelas o coloque un nombre")
        return True

class ValidadorDatos:
    """
    Clase que se encarga de llamar al validador correspondiente para los datos.
    """
    @staticmethod
    def validar_datos(tipo_de_validador : str, datos : list) -> bool:
        """
        Valida los datos.

        :param tipo_de_validador: Tipo de validador a usar.
        :type tipo_de_validador: str
        :param datos: Lista con los datos a validar.
        :type datos: list
        :return: True si los datos son validos, False en caso contrario.
        :rtype: bool
        """
        tipo_de_validador = tipo_de_validador.lower()
        if tipo_de_validador == 'muestras':
            return ValidadorDatosMuestras.validar_datos(datos)
        elif tipo_de_validador == 'grupos':
            return ValidadorDatosGrupos.validar_datos(datos)
        else:
            raise ValueError(f"Tipo de validador no soportado: {tipo_de_validador}")
