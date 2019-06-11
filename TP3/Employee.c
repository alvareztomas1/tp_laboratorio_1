#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee* nuevoEmpleado = (Employee*)malloc(sizeof(Employee));

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id = 0;
        strcpy(nuevoEmpleado->nombre, "");
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->sueldo = 0;
    }

    return nuevoEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* nuevoEmpleado = (Employee*)malloc(sizeof(Employee));
    int todoOk = 0;

    if(nuevoEmpleado != NULL)
    {
        if( employee_setId(nuevoEmpleado, atoi(idStr) == 1) )
        {
            if ( employee_setNombre(nuevoEmpleado, nombreStr) == 1 )
            {
                if ( employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr)) == 1 )
                {
                    if ( employee_setSueldo(nuevoEmpleado, atoi(sueldoStr)) == 1 )
                    {
                        todoOk = 1;
                    }
                }
            }

            if( todoOk == 0 )
            {
                free(nuevoEmpleado);
                nuevoEmpleado = NULL;
            }
        }



        nuevoEmpleado->id = atoi(idStr);
        strcpy(nuevoEmpleado->nombre, nombreStr);
        nuevoEmpleado->horasTrabajadas = atoi(horasTrabajadasStr);
        nuevoEmpleado->sueldo = atof(sueldoStr);
    }

    return nuevoEmpleado;
}

int employee_setId(Employee* this,int id) // TODO LO QUE SEA SET ES ESCRIBIR
{
    int todoOk = 0;

    if( this != NULL && id >0 )
    {
        this->id= id;
        todoOk = 1;
    }

    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo) // TODO LO QUE SEA SET ES ESCRIBIR
{
    int todoOk = 0;

    if( this != NULL && sueldo >0 && sueldo <100000 )
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if( this != NULL && strlen(nombre) < 128 && strlen(nombre) > 0 )
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;

    if( this != NULL && horasTrabajadas >0 && horasTrabajadas <=350 )
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}

int employee_findLastId(LinkedList* pArrayListEmployee)
{
    int id = -1;
    Employee* employee = employee_new();

    if ( employee != NULL )
    {
        for (int i = 0; i<ll_len(pArrayListEmployee); i++)
        {
            employee = ll_get(pArrayListEmployee, i);

            id = employee->id;
        }
    }

    return id;
}

int employee_findEmployee(LinkedList* pArrayListEmpoloyee, int id)
{
    int error = -1;

    Employee* employee = employee_new();

    if ( employee != NULL )
    {

        for (int i = 0; i<ll_len(pArrayListEmpoloyee); i++)
        {
            printf("funciona\n");
            employee = ll_get(pArrayListEmpoloyee, i);

            if (employee->id == id)
            {
                error = i;
            }
        }
    }

    return error;
}
