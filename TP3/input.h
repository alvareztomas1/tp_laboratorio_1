/**
 * \brief Solicita un número al usuario y lo valida
 * \param input Se carga el numero ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \return Si obtuvo el numero [0] si no [-1]
 *
 */
int input_getInt (int* input, char *message, char *eMessage, int lowLimit, int hiLimit);

/**
 * \brief Solicita un número al usuario y lo valida
 * \param input Se carga el numero ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \return Si obtuvo el numero [0] si no [-1]
 *
 */
int input_getFloat (float* input, char *message, char *eMessage, int lowLimit, int hiLimit);

/**
 * \brief Solicita un caracter al usuario y lo valida
 * \param input Se carga el caracter ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \return Si obtuvo el caracter [0] si no [-1]
 *
 */
int input_getChar (char* input, char *message, char *eMessage, char lowLimit, char hiLimit);

/**
 * \brief Solicita una cadena de caracteres al usuario y la valida
 * \param input Se carga el string ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Longitud mínima de la cadena
 * \param hiLimit Longitud máxima de la cadena
 * \return Si obtuvo la cadena [0] si no [-1]
 *
 */
int input_getString (char* input, char* message, char *eMessage, int lowLimit, int hiLimit);

/** \brief Solicita al usuario el ingreso de dos caracteres y los valida
 *
 * \param  input Los dos caracteres a ingresar
 * \param  message Es el mensaje a ser mostrado
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Longitud mínima de la cadena
 * \param hiLimit Longitud máxima de la cadena
 * \return Void
 *
 */
void input_validarDosChar(char* input, char message[], char eMessage[], char lowLimit, char hiLimit);


