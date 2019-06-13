#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "empleados.h"
#include "input.h"

#define TAM_EMPLEADOS 5

int main()
{
    eEmpleado lista[TAM_EMPLEADOS];

    char seguir='s';
    char salir;
    int contadorLegajo=1;
    int error;

    inicializarEmpleados(lista, TAM_EMPLEADOS);

    do
    {
        switch (menu())
        {
            case 1:
                error=altaEmpleado(lista, TAM_EMPLEADOS, contadorLegajo);

                if (error==1)
                {
                    printf("\nNo hay espacio en el sistema!!\n\n");
                }
                else
                {
                    contadorLegajo++;
                }

                system("pause");
                system("cls");
                break;

            case 2:
                system("cls");
                error=modificarEmpleado(lista, TAM_EMPLEADOS);

                if (error==1)
                {
                    printf("\nNo hay empleados dados de alta!!\n\n");
                }

                system("pause");
                system("cls");
                break;

           case 3:
                error=bajaEmpleado(lista, TAM_EMPLEADOS);

                if (error==1)
                {
                    printf("\nNo hay empleados dados de alta!!\n\n");
                }

                system("pause");
                system("cls");
                break;

            case 4:
                switch (subMenuInformes())
                {

                    case 1:
                        system("cls");
                        ordenarEmpleados(lista, TAM_EMPLEADOS);
                        error=mostrarEmpleados(lista, TAM_EMPLEADOS);

                        if (error==1)
                        {
                            printf("\nNo hay empleados que listar!!\n\n");
                        }
                        system("pause");
                        system("cls");
                        break;

                    case 2:
                        system("cls");
                        error=informeSalarios (lista, TAM_EMPLEADOS);

                        if (error==1)
                        {
                            printf("\nNo hay empleados dados de alta!!\n\n");
                        }
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

        fflush(stdin);
    }while (seguir=='s');


    return 0;
}
