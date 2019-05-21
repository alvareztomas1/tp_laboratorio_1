#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "empleados.h"

#define TAM_EMPLEADOS 5

int main()
{
    eEmpleado lista[TAM_EMPLEADOS]
    =
    {
        {1, "Tomas", "Alvarez", 50000, 1,0 },
        {2, "Florencia", "Cortes", 30000, 4, 0},
        {3, "Julieta", "Cortes", 35000, 3, 0},
        {4, "Bonavena", "Julio", 60000, 2, 0},
        {5, "Ramon", "Abila", 30000, 1, 0},
    };

    char seguir='s';
    char salir;
    int contadorLegajo=1;



    //inicializarEmpleados(lista, TAM_EMPLEADOS);

    do
    {

        switch (menu())
        {

            case 1:
                altaEmpleado(lista, TAM_EMPLEADOS, contadorLegajo);
                contadorLegajo++;

                system("pause");
                system("cls");
                break;

            case 2:
                modificarEmpleado(lista, TAM_EMPLEADOS);
                system("pause");
                system("cls");
                break;

           case 3:
                bajaEmpleado(lista, TAM_EMPLEADOS);
                system("pause");
                system("cls");
                break;

            case 4:
                switch (subMenu())
                {

                    case 1:
                        ordenarEmpleados(lista, TAM_EMPLEADOS);
                        mostrarEmpleados(lista, TAM_EMPLEADOS);
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        informeSalarios (lista, TAM_EMPLEADOS);
                        system("pause");
                        system("cls");
                        break;
                    case 3:
                        break;
                    default:
                        printf("\nOpcion invalida!!\n\n");
                        break;
                }
                break;

            case 5:
                system("cls");
                validarDosChar(&salir, "Desea salir? Ingrese s/n: ", "Solo s/n: ", 's', 'n');

                if (tolower(salir)=='s')
                {
                    seguir='n';
                }
                break;

            default:
                system("cls");
                printf("\nOpecion invalida!!\n\n");
                break;
        }

    }while (seguir=='s');
    fflush(stdin);
    return 0;
}
