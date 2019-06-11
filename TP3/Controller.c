#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "input.h"


int controller_menu()
{
    int rta;

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
    input_getInt(&rta, "Ingrese opcion: ", "Opcion invalida. Reingrese: ", 1, 10);


    return rta;
}

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int error = 1;
    FILE* f;
    char buffer[4][20];
    int cant;

    f = fopen(path, "r");

    if( f != NULL )
    {
        ll_clear(pArrayListEmployee);

        while ( !feof(f) )
        {
            Employee* newEmploye = employee_new();

            if ( newEmploye != NULL )
            {
                cant = fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

                if( cant < 4 )
                {
                    break;
                }

                employee_setId(newEmploye, atoi(buffer[0]));
                employee_setNombre(newEmploye, buffer[1]);
                employee_setHorasTrabajadas(newEmploye, atoi(buffer[2]));
                employee_setSueldo(newEmploye, atoi(buffer[3]));

                ll_add(pArrayListEmployee, newEmploye);
                printf(" %04d   %-10s   %3d   %6d\n\n", newEmploye->id, newEmploye->nombre, newEmploye->horasTrabajadas, newEmploye->sueldo);
                error = 0;
            }

        }

        fclose(f);
    }

    return error;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int error = 1;
    FILE* f;
    int cant;

    f = fopen(path, "rb");

    if( f != NULL )
    {
        ll_clear(pArrayListEmployee);

        while ( !feof(f) )
        {
            Employee* newEmploye = employee_new();

            if ( newEmploye != NULL )
            {
                cant = fread(newEmploye, sizeof (Employee), 1, f);

                if( cant < 1 )
                {

                    break;
                }

                ll_add(pArrayListEmployee, newEmploye);

                error = 0;
            }
        }

        fclose(f);
    }

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
                    /*ll_set(pArrayListEmployee, j, employeeI);
                    ll_set(pArrayListEmployee, i, aux);*/
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
             printf(" %04d   %-10s   %3d   %6d\n\n", employee->id, employee->nombre, employee->horasTrabajadas, employee->sueldo);
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

