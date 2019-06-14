#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();
    char seguir = 's';
    char rta;
    int error;
    int opcionMenu;



    do{
        printf("-------TRABAJO PRACTICO NUMERO 3-------\n\n");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.bin\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv\n");
        printf("9. Guardar los datos de los empleados en el archivo data.bin\n");
        printf("10. Salir\n\n");
        input_getInt(&opcionMenu, "Ingrese opcion: ", "Opcion invalida. Reingrese: ", 1, 10);

        switch( opcionMenu )
        {
            case 1:
                system("cls");
                error = controller_loadFromText("data.csv",listaEmpleados);

                if ( error )
                {
                    printf("\nNo se pudieron cargar los datos!!\n\n");
                }
                else
                {
                    printf("\nLos datos se cargaron correctamente!!\n\n");
                }
                system("pause");
                break;

            case 2:
                system("cls");
                error = controller_loadFromBinary("empleados.bin", listaEmpleados);

                if( error )
                {
                    printf("\nNo se pudieron cargar los datos!!\n\n");
                }
                else
                {
                    printf("\nLos datos se cargaron correctamente!!\n\n");
                }
                system("pause");
                break;

            case 3:
                system("cls");
                error = controller_addEmployee(listaEmpleados);

                if ( error )
                {
                    printf("\nNo se pudo realizar el alta!!\n\n");
                }
                else
                {
                    printf("\nAlta empleado exitosa!!\n\n");
                }
                system("pause");
                break;

            case 4:
                system("cls");
                error = controller_editEmployee(listaEmpleados);

                if ( error )
                {
                    printf("\nLa modificacion no pudo hacerse correctamente!!\n\n");
                }
                else
                {
                    printf("\nModificacion exitosa!!\n\n");
                }
                system("pause");
                break;

            case 5:
                system("cls");
                error = controller_removeEmployee(listaEmpleados);

                if ( error )
                {
                    printf("No se pudo realizar la baja!!\n\n");
                }
                else
                {
                    printf("\nBaja empleado exitosa!!\n\n");
                }

                system("pause");
                system("cls");
                break;

            case 6:
                system("cls");
                error = controller_ListEmployee(listaEmpleados);

                if ( error )
                {
                    printf("No se cargaron los datos!!\n\n");

                }
                system("pause");
                system("cls");
                break;

            case 7:
                system("cls");
                error = controller_sortEmployee(listaEmpleados);

                if ( error )
                {
                    printf("\nNo se pudo ordenar!!\n\n");
                }
                else
                {
                    printf("\nOrdenamiento exitoso!!\n\n");
                }
                system("pause");
                break;

            case 8:
                system("cls");
                error = controller_saveAsText("data.csv", listaEmpleados);

                if ( error )
                {
                    printf("\nLos datos no pudieron guardarse en el archivo csv!!\n\n");
                }
                else
                {
                    printf("\nLos datos fueron guardados con exito!!\n\n");
                }

                system("pause");
                break;

            case 9:

                system("cls");
                error = controller_saveAsBinary("empleados.bin", listaEmpleados);

                if ( error )
                {
                    printf("\nLos datos no pudieron guardarse en el archivo binario!!\n\n");
                }
                else
                {
                    printf("\nLos datos fueron guardados con exito!!\n\n");
                }

                system("pause");
                break;

            case 10:
                system("cls");
                input_validarDosChar(&rta, "Desea salir? Ingrese s/n: ", "Solo s/n. Reingrese: ", 'n', 's');


                if ( rta == 's' )
                {
                    ll_deleteLinkedList(listaEmpleados);
                    seguir = 'n';
                }

                break;

            default:
                system("cls");
                printf("\nOpcion invalida!!\n\n");
                system("pause");
                break;
        }
    fflush(stdin);
    }while(seguir == 's');



    return 0;
}
