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

int menu();

int subMenu();

int inicializarEmpleados (eEmpleado emp[], int tam);

void altaEmpleado (eEmpleado emp[], int tam, int contador);

void modificarEmpleado (eEmpleado emp[], int tam);

void bajaEmpleado (eEmpleado emp[], int tam);

int mostrarEmpleados (eEmpleado emp[], int tam);

void ordenarEmpleados (eEmpleado emp[], int tam);

void informeSalarios (eEmpleado emp[], int tam);
