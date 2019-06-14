#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "input.h"
#include "parser.h"
#include "controller.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    f = fopen(path, "r");
    int error;

    error = parser_EmployeeFromText(f, pArrayListEmployee);

    return error;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int error ;
    FILE* f;

    f = fopen(path, "rb");

    error = parser_EmployeeFromBinary(f, pArrayListEmployee);

    return error;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;
    int id;
    Employee* employee = employee_new();

    if ( employee != NULL )
    {
        input_getString(employee->nombre, "Ingrese nombre: ", "Superaste los caracteres. Reingresa: ", 0, 128);
        input_getInt(&employee->horasTrabajadas, "Ingrese horas trabajadas: ", "Rango entre 0-350. Reingresa: ", 40, 350);
        input_getInt(&employee->sueldo, "Ingrese sueldo: ", "Rango entre 9000 y 100000. Reingrese: ", 9000, 100000);
        id = employee_findLastId(pArrayListEmployee);

        employee->id = id+1;

        ll_add(pArrayListEmployee, employee);
        error = 0;
    }


    return error;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;
    Employee* employee = employee_new();
    int id;
    char salir;
    int opcion;

    if ( employee != NULL )
    {
        controller_ListEmployee(pArrayListEmployee);
        input_getInt(&id, "Ingrese id: ","No entra en el rango. Reingrese: ", 1, employee_findLastId(pArrayListEmployee));

        for ( int i = 0; i<ll_len(pArrayListEmployee); i++ )
        {
            employee = ll_get(pArrayListEmployee, i);

            if ( employee->id == id )
            {
                printf("%04d   %-10s   %3d   %6d\n\n", employee->id, employee->nombre, employee->horasTrabajadas, employee->sueldo);
                input_validarDosChar(&salir, "Desea continuar? s/n: ", "Solo s/n. Reingrese: ", 'n', 's');

                if ( salir == 's' )
                {
                    printf("1-Nombre\n");
                    printf("2-Horas trabajadas\n");
                    printf("3-Sueldo\n\n");
                    printf("4-Salir\n\n");
                    input_getInt(&opcion, "Ingrese opcion: ", "Superó el rango. Reingrese: ", 1, 3);

                    switch( opcion )
                    {
                        case 1:
                            input_getString(employee->nombre, "Ingrese nombre: ", "Superaste el rango. Reingresa: ", 1, 128);
                            error = 0;
                            break;

                        case 2:
                            input_getInt(&employee->horasTrabajadas, "Ingrese horas trabajadas: ", "Superaste el rango. Reingresa: ", 40, 350);
                            error = 0;
                            break;

                        case 3:
                            input_getInt(&employee->sueldo, "Ingrese sueldo: ", "Superaste el rango. Reingresa: ", 9000, 100000);
                            error = 0;
                            break;

                        case 4:
                            break;

                        default:
                            printf("\nOperacion invalida!!\n\n");
                        break;
                    }

                }

                else
                {
                    printf("Modificacion cancelada!!\n\n");
                    break;
                }
            }
        }
    }

    return error;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;
    int lastId;
    int id;
    //int findId;
    char salir;
    Employee* employee = employee_new();

    if ( employee != NULL )
    {
       // findId = employee_findEmployee(pArrayListEmployee, id);
        lastId = employee_findLastId(pArrayListEmployee);
        controller_ListEmployee(pArrayListEmployee);
        input_getInt(&id, "Ingrese id: ", "Legajo incompatible. Reingrese: ", 1, lastId);

        for (int i = 0; i<ll_len(pArrayListEmployee); i++)
        {
            employee = ll_get(pArrayListEmployee, i);

            if (id == employee->id)
            {
                printf("%04d   %-10s   %3d   %6d\n\n", employee->id, employee->nombre, employee->horasTrabajadas, employee->sueldo);

                input_validarDosChar(&salir, "Desea continuar? s/n: ", "Solo s/n. Reingrese: ", 'n', 's');

                if ( salir == 's' )
                {
                    ll_remove(pArrayListEmployee, i);
                    error = 0;
                    break;
                }

                else
                {
                    printf("Baja cancelada!!\n\n");
                    break;
                }

            }
        }
    }

    return error;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;
    Employee* employee = employee_new();

    if ( employee != NULL )
    {
        printf("LEGAJO  NOMBRE      HORAS   SUELDO\n\n");

        for ( int i = 0; i<ll_len(pArrayListEmployee); i++ )
        {
            employee = ll_get(pArrayListEmployee , i);

            printf(" %04d   %-10s   %3d   %6d\n\n", employee->id, employee->nombre, employee->horasTrabajadas, employee->sueldo);
            error = 0;
        }
    }


    return error;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;
    Employee* employeeI = employee_new();
    Employee* employeeJ = employee_new();
    Employee* aux = employee_new();


    if ( employeeI != NULL   && aux != NULL )
    {
         for ( int i = 0; i < ll_len(pArrayListEmployee); i++ )
        {
            for ( int j = i+1; j < ll_len(pArrayListEmployee); j++ )
            {
                employeeI = ll_get(pArrayListEmployee, i);

                employeeJ = ll_get(pArrayListEmployee, j);

                if ( strcmp (employeeI->nombre, employeeJ->nombre) > 0 )
                {
                    *aux = *employeeI;
                    *employeeI = *employeeJ;
                    *employeeJ = *aux;

                    error = 0;
                }
            }
        }
    }

    return error;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int error = 1;
    FILE* f;
    Employee* employee = employee_new();

    f = fopen( path, "w" );

    if ( f != NULL && employee != NULL )
    {
        fprintf(f, "LISTA DE EMPLEADOS\n\n");
        fprintf(f, "LEGAJO   NOMBRE   HORAS   SUELDO\n");

        for ( int i = 0; i<ll_len(pArrayListEmployee); i++ )
        {
            employee = ll_get(pArrayListEmployee, i);

            fprintf(f, "%d,%s,%d,%d\n", employee->id, employee->nombre, employee->horasTrabajadas, employee->sueldo);

            error = 0;
        }
    }

    fclose(f);

    return error;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int error = 1;
    FILE* f;
    Employee* employee = employee_new();

    f = fopen( path, "wb" );

    if ( f != NULL && employee != NULL)
    {
        for ( int i = 0; i<ll_len(pArrayListEmployee); i++ )
        {
            employee = ll_get(pArrayListEmployee, i);

            fwrite( employee, sizeof(Employee), 1, f );

            error = 0;
        }
    }

    fclose(f);

    return error;
}

