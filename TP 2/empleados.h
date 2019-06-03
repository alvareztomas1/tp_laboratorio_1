//   ESTRUCTURAS   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int itsEmpty;

}eEmpleado;

//   PROTOTIPOS   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Menu de opciones del programa
 *
 * \return Opcion elegida por el usuario
 *
 */
int menu();

/** \brief Submenu utilizado en los informes
 *
 * \return Opcion elegida por el usuario
 *
 */
int subMenuInformes();

/** \brief Inicializa el campo itsEmpty en 1 del array de empleados
 *
 * \param emp estructura a modificar
 * \param tam tamaño de la estructura
 * \return [1] si no lo consiguio, [0] si pudo
 *
 */
int inicializarEmpleados (eEmpleado* emp, int tam);

/** \brief Busca en la estructura que el campo itsEmpty sea 1
 *
 * \param emp estructura a recorrer
 * \param tam tamaño de la estructura
 * \return [-2] si no pudo [indice de la estructura donde encontro el campo igual a 1]
 *
 */
int buscarLibre (eEmpleado* emp, int tam);

/** \brief Recibe un legajo ingresado por el usuario y busca que este dado de alta
 *
 * \param emp estructura a recorrer
 * \param  tam tamaño de la estructura
 * \param id ingresado por el usuario
 * \return [-1] si no lo enconto [indice de la estructura donde encontro el legajo del empleado]
 *
 */
int buscarEmpleado (eEmpleado* emp, int tam, int id);

/** \brief Funcion para dar de alta a un empleado
 *
 * \param emp estructura del empleado a llenar
 * \param tam tamaño de la estructura
 * \param contador permite hacer autoincremental el campo legajo de la estructura
 * \return [1] si no lo consiguio, [0] si pudo hacerlo
 *
 */
int altaEmpleado (eEmpleado* emp, int tam, int contador);

/** \brief Permite al usuario modificar campos de la estructura empleado
 *
 * \param emp estructura a modificar
 * \param tam tamaño de la estructura
 * \return [1] si no se consiguio [0] si pudo hacerlo
 *
 */
int modificarEmpleado (eEmpleado* emp, int tam);

/** \brief Permite dar de baja algun empleado cambiado su campo itsEmpty por -1
 *
 * \param emp estructura a recorrer para dar de baja al empleado indicado por el usuario
 * \param tam tamaño de la estructura
 * \return [1] si no se consiguio [0] si se pudo hacer
 *
 */
int bajaEmpleado (eEmpleado* emp, int tam);


/** \brief Muestra en pantalla todos los empleados dados de alta
 *
 * \param emp estructura de empleados a recorrer
 * \param tam tamaño de la estructura
 * \return [1] si no se consiguio [0] si se pudo hacer
 *
 */
int mostrarEmpleados (eEmpleado* emp, int tam);


/** \brief Ordena a los empleados alfabeticamente por apellido y sector
 *
 * \param emp estructura de empleados a recorrer
 * \param tam tamaño de la estructura
 * \return [1] si no se consiguio [0] si pudo hacerlo
 *
 */
int ordenarEmpleados (eEmpleado* emp, int tam);

/** \brief Informe de total de salarios, con su promedio y cuantos empleados lo superan
 *
 * \param emp estructura de empleados a recorrer
 * \param tam tamaño de la estructura
 * \return [1] si no se consiguio [0] si se pudo hacer
 *
 */
int informeSalarios (eEmpleado* emp, int tam);
