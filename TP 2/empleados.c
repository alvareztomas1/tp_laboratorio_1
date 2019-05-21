#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "empleados.h"
#include "input.h"
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int menu()
{
    int opcion;

    printf("---------ABM EMPLEADOS----------\n\n");
    printf("1-Alta empleado\n");
    printf("2-Modificar empleado\n");
    printf("3-Baja empleado\n");
    printf("4-Informes\n");
    printf("5-Salir\n");
    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int subMenu()
{
    int respuesta;

    printf("----------INFORMES----------\n\n");
    printf("1-Listado empleados\n");
    printf("2-Total y promedio salarios\n");
    printf("3-Salir\n");
    printf("\nIngrese opcion: ");
    scanf("%d", &respuesta);

    return respuesta;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int inicializarEmpleados (eEmpleado emp[], int tam)
{
    int todoOk=-1;

    if (tam !=0)
    {
        for (int i=0;i<tam;i++)
        {
            emp[i].itsEmpty=1;
            todoOk=0;
        }
    }

    return todoOk;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int buscarLibre (eEmpleado emp[], int tam)
{
    int espacioLibre=-2;

    if (tam !=0)
    {
         for (int i=0;i<tam;i++)
        {
            if (emp[i].itsEmpty==1)
            {
                espacioLibre=i;
                break;
            }
        }
    }

    return espacioLibre;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int buscarEmpleado (eEmpleado emp[], int tam, int id)
{
    int indice=-1;

    if (tam!=0)
    {
        for (int i=0;i<tam;i++)
        {
            if (emp[i].id==id && emp[i].itsEmpty==0)
            {
                indice=i;

                break;
            }
        }
    }


    return indice;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void altaEmpleado (eEmpleado emp[], int tam, int contador)
{

    int espacioLibre=-2;

    if (tam !=0)
    {
         for (int i=0;i<tam;i++)
        {
            if (emp[i].itsEmpty==1)
            {
                espacioLibre=i;
                break;
            }
        }
    }

    if (espacioLibre==-2)
    {
        printf("\nNo hay espacio libre en el sistema!!\n\n");
    }
    else
    {
        getString(emp[espacioLibre].lastName, "Ingrese apellido: ","No entra en el rango. Reingrese: ", 0, 51);
        getString(emp[espacioLibre].name, "Ingrese nombre: ", "No entra en el rango. Reingrese: ", 0, 51);
        getFloat(&emp[espacioLibre].salary, "Ingrese sueldo: ", "No entar en el rango. Reingrese: ", 0, 1000000);
        getInt(&emp[espacioLibre].sector, "Ingrese sector: ", "No entra en el rango. Reingrese: ", 1,5);

        emp[espacioLibre].id=0;
        emp[espacioLibre].id+=contador;
        emp[espacioLibre].itsEmpty=0;




    }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void bajaEmpleado (eEmpleado emp[], int tam)
{
    int id;
    int busquedaId;
    char salir;

    int sinEmpleados=0;

    for (int i=0;i<tam;i++)
    {
        if (emp[i].itsEmpty==0)
        {
            mostrarEmpleados(emp, tam);
            printf("\nIngrese id: ");
            scanf("%d", &id);

            busquedaId=buscarEmpleado(emp, tam, id);

            if (busquedaId==-1)
            {
                printf("Legajo inexistente en el sistema!!\n");
            }
            else
            {
                printf("Legajo %d-%s, %s\n\n", emp[busquedaId].id, emp[busquedaId].lastName, emp[busquedaId].lastName);
                validarDosChar(&salir, "Desea continuar? Ingrese s/n: ", "Solo s/n: ", 's', 'n');

                if (tolower(salir)=='s')
                {
                    emp[busquedaId].itsEmpty=1;
                    printf("\nOperacion exitosa!!\n\n");
                    sinEmpleados++;
                }
                else
                {
                    printf("\nOperacion cancelada!!\n\n");
                    return;
                }

            }
        }
    }
    if (sinEmpleados==0)
    {
        printf("\nNo hay empleados que dar de baja!!\n\n");
    }


}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int mostrarEmpleados (eEmpleado emp[], int tam)
{
    int todoOk=-1;
    int contador=0;

    printf("\nID   APELLIDO   NOMBRE  SUELDO   SECTOR\n");
    for (int i=0;i<5;i++)
    {
        if (emp[i].itsEmpty==0)
        {

            printf("%d   %-s    %-s   %.2f    %3d\n", emp[i].id, emp[i].lastName, emp[i].name, emp[i].salary, emp[i].sector);
            todoOk=0;
            contador++;
        }

    }
    if (contador==0)
    {
        printf("\nNo hay empleados que listar!!\n\n");
    }

    return todoOk;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ordenarEmpleados (eEmpleado emp[], int tam)
{

    eEmpleado aux;

    for (int i=0;i<tam-1;i++)
    {
        for (int j=i+1;j<tam;j++)
        {
            if(stricmp(emp[i].name, emp[j].name)<0)
            {
                aux=emp[i];
                emp[i]=emp[j];
                emp[j]=aux;
            }
            else if ((stricmp(emp[i].name, emp[j].name)>0) && emp[i].id>emp[j].id)
            {
                aux=emp[i];
                emp[i]=emp[j];
                emp[j]=aux;
            }
        }
    }
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void modificarEmpleado (eEmpleado emp[], int tam)
{
    int id;
    int busquedaId=0;
    char salir;
    int opcion;
    int sinEmpleados=0;

    for (int i=0;i<tam;i++)
    {
        if (emp[i].itsEmpty==0)
        {
            sinEmpleados++;
            mostrarEmpleados(emp, tam);
            getInt(&id, "Ingrese id: ", "No entra en el rango. Reingrese: ", 1, 10000);

            busquedaId=buscarEmpleado(emp, tam, id);

            if (busquedaId==-1)
            {
                printf("\nLegajo inexistente en el sistema!!\n\n");

            }
            else
            {
                printf("\nId nro %d-%s, %s\n\n", emp[busquedaId].id, emp[busquedaId].lastName, emp[busquedaId].name);

                validarDosChar(&salir, "Desea continuar? Ingrese s/n: ", "Solo s/n: ", 's', 'n');

                if (salir=='s')
                {
                    printf("1-Apellido\n");
                    printf("2-Nombre\n");
                    printf("3-Salario\n");
                    printf("4-Sector\n");
                    getInt(&opcion, "Ingrese opcion: ", "No entro en el rango, reingrese: ", 1, 5);

                    switch (opcion)
                    {
                        case 1:
                            getString(emp[busquedaId].lastName, "Ingrese apellido: ", "No entra en el rango. Reingrese: ", 0, 51);
                            break;
                        case 2:
                            getString(emp[busquedaId].name, "Ingrese nombre: ", "No entra en el rango. Reingrese: ", 0, 51);
                            break;
                        case 3:
                            getFloat(&emp[busquedaId].salary, "Ingrese salario: ", "No entra en el rango. Reingrese: ", 0, 1000000);
                            break;
                        case 4:
                            getInt(&emp[busquedaId].sector, "Ingrese sector: ", "No entra en el rango. Reingrese: ", 1, 5);
                            break;
                    }
                        printf("\nOperacion exitosa!!\n\n");

                }
                else
                {
                    printf("\nOperacion cancelada!!\n\n");
                }


            }
        }
    }
    if (sinEmpleados==0)
    {
        printf("\nNo hay empleados que modificar!!\n\n");
    }



}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void informeSalarios (eEmpleado emp[], int tam)
{
    int total=0;
    int contadorSalario=0;
    int contadorEmpleados=0;
    int promedio;

    for (int i=0;i<tam;i++)
    {
        if (emp[i].itsEmpty==0)
        {
            total=emp[i].salary+total;
            contadorEmpleados++;
        }

    }
    if (contadorEmpleados==0)
    {
        printf("\nNo hay emleados dados de alta!!\n\n");
        return;
    }

    promedio=total/contadorEmpleados;

    for (int i=0;i<tam;i++)
    {
        if (emp[i].salary>promedio)
        {
            contadorSalario++;
        }
    }


    printf("El total de salarios es: %d. Con un promedio de %d y %d personas superandolo\n",total,  promedio, contadorSalario);

}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
