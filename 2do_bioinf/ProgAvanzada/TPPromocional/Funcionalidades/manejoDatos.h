/*!
 *  \class     ManejoDatos.
 *  \brief     La clase se encarga de gestionar datos de pacientes
 *  \details   La clase carga los datos mediante un archivo de texto y puede modificar dicho archivo junto con los
 *              pacientes una vez cargados en memoria. Tambien puede guardar en un archivo binario test hechos por
 *              un paciente, y leerlos y filtrarlos segun lo que se necesite. Finalmente puede devolver el tiempo
 *              de dichos tests que pueden usados en otras clases.
 *  \author    Salim Nasim.
 *  \version   1.1.
 *  \date      Fecha de creación: 30/05/2020.
 *  \date      Fecha de última modificación: 31/05/2020.
 *  \pre       La clase puede ser utilizada cuando se necesite gestionar y filtrar ciertos datos en forma de tests.
 *  \bug       -
 *  \warning   No pueden borrarse los datos ya sea en el archivo de texto o binario. Puede resultar dificil si se quiere
 *              borrar datos especificos especialmente en el archivo binario.
 *  \copyright GNU Public License.
*/
#ifndef MANEJOARCHIVOS_H
#define MANEJOARCHIVOS_H

#include <fstream>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>

//using namespace std;
class ManejoDatos
{
struct test
{
      int DNI;
      int anio;
      int mes;
      int dia;
      int horas;
      int minutos;
      char tipo;
      char nivel;
      int tiempo;
};

public:

    /*!
     * \brief ManejoDatos Constructor vacio
     */
    ManejoDatos();

    /*!
     * \brief CargarPacientes Carga los pacientes a partir de un archivo de texto
     * \return booleano verdadero o falso dependiendo si la operación tuvo éxito
     */
    bool CargarPacientes();

    /*!
     * \brief AgregarPaciente Agrega un paciente a los registros de memoria y al archivo de texto
     * \param DNI DNI del paciente a agregar
     * \param datos Datos que quieran añadirse al paciente, nombre, edad, etc.
     * \return booleano verdadero o falso dependiendo si la operación tuvo éxito
     */
    bool AgregarPaciente(int DNI, std::string datos);

    /*!
     * \brief ModificarPaciente Permite modificar los datos de un paciente insertando su DNI
     * \param DNI
     * \param datos
     * \return booleano verdadero o falso dependiendo si la operación tuvo éxito
     */
    bool ModificarPaciente(int DNI, std::string datos);

    /*!
     * \brief SeleccionarPaciente Selecciona un paciente por su DNI para distintas operaciones
     * \param DNI DNI del paciente a seleccionar
     * \return booleano que será verdadero si se encontró el paciente en memoria. De lo contrario, falso.
     */
    bool SeleccionarPaciente(int DNI);

    /*!
     * \brief CargarDatosPaciente Permite cargar en memoria los datos de los tests realizados
     *                              al paciente y los muestra por consola.
     * \return Devuelve un string con los datos del paciente
     */
    std::string CargarDatosPaciente();

    /*!
     * \brief ObtenerDatosPaciente Devuelve los tiempos tardados por el paciente seleccionado para el tipo y nivel
     * \param tipo Establece que tipo de tests filtrar
     * \param nivel Establece que niveles se desea filtrar
     * \return Un vector de numeros enteros con los tiempos en segundos.
     */
    std::vector <int> ObtenerDatosPaciente(char tipo, char nivel);

    /*!
     * \brief GuardarTest Permite guardar un test en el archivo binario para el paciente seleccionado
     * \param tipo Tipo de test
     * \param nivel Nivel del test
     * \param tiempoTest Tiempo tardado en el test
     */
    bool GuardarTest(char tipo, char nivel, int tiempoTest);

private:
    std::map<int,std::string> datosMemoria;
    std::map<int,std::string>::iterator pacienteSeleccionado;
    std::vector <test> datosPaciente;
};

#endif // MANEJOARCHIVOS_H
