#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
     int error = 1;
    char buffer[4][20];
    int cant;



    if( pFile != NULL )
    {
        ll_clear(pArrayListEmployee);

        while ( !feof(pFile) )
        {
            Employee* newEmploye = employee_new();

            if ( newEmploye != NULL )
            {
                cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

                if( cant < 4 )
                {
                    break;
                }

                employee_setId(newEmploye, atoi(buffer[0]));
                employee_setNombre(newEmploye, buffer[1]);
                employee_setHorasTrabajadas(newEmploye, atoi(buffer[2]));
                employee_setSueldo(newEmploye, atoi(buffer[3]));

                ll_add(pArrayListEmployee, newEmploye);

                error = 0;
            }

        }

        fclose(pFile);
    }


    return error;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int error = 1;
    int cant;

    if( pFile != NULL )
    {
        ll_clear(pArrayListEmployee);

        while ( !feof(pFile) )
        {
            Employee* newEmploye = employee_new();

            if ( newEmploye != NULL )
            {
                cant = fread(newEmploye, sizeof (Employee), 1, pFile);

                if( cant < 1 )
                {
                    break;
                }

                ll_add(pArrayListEmployee, newEmploye);

                error = 0;
            }
        }

        fclose(pFile);
    }

    return error;
}
