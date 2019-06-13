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
int subMenuInformes()
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
int inicializarEmpleados (eEmpleado* emp, int tam)
{
    int todoOk=1;

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
int buscarLibre (eEmpleado* emp, int tam)
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
int buscarEmpleado (eEmpleado* emp, int tam, int id)
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
int altaEmpleado (eEmpleado* emp, int tam, int contador)
{
    int todoOk=1;
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

        if (espacioLibre==-2)
        {
            return 1;
        }

        else
        {
            getString(emp[espacioLibre].lastName, "Ingrese apellido: ","No entra en el rango. Reingrese: ", 0, 51);
            getString(emp[espacioLibre].name, "Ingrese nombre: ", "No entra en el rango. Reingrese: ", 0, 51);

            emp[espacioLibre].lastName[0]=toupper(emp[espacioLibre].lastName[0]);
            emp[espacioLibre].name[0]=toupper(emp[espacioLibre].name[0]);

            getFloat(&emp[espacioLibre].salary, "Ingrese sueldo: ", "No entar en el rango. Reingrese: ", 0, 1000000);
            getInt(&emp[espacioLibre].sector, "Ingrese sector: ", "No entra en el rango. Reingrese: ", 1,5);

            emp[espacioLibre].id=0;
            emp[espacioLibre].id+=contador;
            emp[espacioLibre].itsEmpty=0;

            printf("\nAlta empleado exitosa!!\n\n");
            todoOk=0;
        }
    }

    return todoOk;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int bajaEmpleado (eEmpleado* emp, int tam)
{
    int todoOk=1;
    int id;
    int busquedaId;
    char salir;
    int contador=0;

    if (tam!=0)
    {
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
                        emp[busquedaId].itsEmpty=-1;
                        printf("\nOperacion exitosa!!\n\n");
                        contador++;
                        break;
                    }
                    else
                    {
                        printf("\nOperacion cancelada!!\n\n");
                        contador++;
                        break;

                    }

                }
            }
        }
    }

    if (contador>0)
    {
        todoOk=0;
    }

    return todoOk;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int mostrarEmpleados (eEmpleado* emp, int tam)
{
    int todoOk=1;
    int contador=0;


    if (tam!=0)
    {
        printf("\nID   APELLIDO   NOMBRE  SUELDO   SECTOR\n");

        for (int i=0;i<5;i++)
        {
            if (emp[i].itsEmpty==0)
            {
                printf("%d   %-s    %-s   %.2f    %3d\n", emp[i].id, emp[i].lastName, emp[i].name, emp[i].salary, emp[i].sector);
                contador++;
            }
        }
    }

    if (contador>0)
    {
        todoOk=0;
    }

    return todoOk;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int ordenarEmpleados (eEmpleado* emp, int tam)
{
    int todoOk=1;
    eEmpleado aux;
    int contador=0;

    if (tam!=0)
    {
        for (int i=0;i<tam-1;i++)
        {
            for (int j=i+1;j<tam;j++)
            {
                if(strcmp(emp[i].lastName, emp[j].lastName)>0)
                {
                    aux=emp[i];
                    emp[i]=emp[j];
                    emp[j]=aux;
                }
                if (emp[i].sector>emp[j].sector)
                {
                    aux=emp[i];
                    emp[i]=emp[j];
                    emp[j]=aux;
                    contador=1;
                }

            }
        }

        if (contador==1)
        {
            todoOk=0;
        }

    }


    return todoOk;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int modificarEmpleado (eEmpleado* emp, int tam)
{
    int todoOk=1;
    int id;
    int busquedaId=0;
    char salir;
    int opcion;

    if (tam!=0)
    {
        for (int i=0;i<tam;i++)
        {
            if (emp[i].itsEmpty==0)
            {
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
                                emp[busquedaId].lastName[0]=toupper(emp[busquedaId].lastName[0]);

                                break;
                            case 2:
                                getString(emp[busquedaId].name, "Ingrese nombre: ", "No entra en el rango. Reingrese: ", 0, 51);
                                emp[busquedaId].name[0]=toupper(emp[busquedaId].name[0]);
                                break;
                            case 3:
                                getFloat(&emp[busquedaId].salary, "Ingrese salario: ", "No entra en el rango. Reingrese: ", 0, 1000000);
                                break;
                            case 4:
                                getInt(&emp[busquedaId].sector, "Ingrese sector: ", "No entra en el rango. Reingrese: ", 1, 5);
                                break;
                        }
                            printf("\nOperacion exitosa!!\n\n");
                            todoOk=0;
                            break;

                    }
                    else
                    {
                        printf("\nOperacion cancelada!!\n\n");
                        todoOk=0;
                        break;
                    }
                }
            }
        }
    }

    return todoOk;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int informeSalarios (eEmpleado* emp, int tam)
{
    int todoOk=1;
    int total=0;
    int contadorSalario=0;
    int contadorEmpleados=0;
    int promedio;

    if (tam!=0)
    {
        for (int i=0;i<tam;i++)
        {
            if (emp[i].itsEmpty==0)
            {
                total=emp[i].salary+total;
                contadorEmpleados++;
            }
        }

        if (contadorEmpleados>0)
        {
            promedio=total/contadorEmpleados;

            for (int i=0;i<tam;i++)
            {
                if (emp[i].salary>promedio)
                {
                    contadorSalario++;
                }
            }

            if (contadorSalario>0)
            {
                printf("El total de salarios es: %d. Con un promedio de %d y %d personas superandolo\n",total,  promedio, contadorSalario);
                todoOk=0;
            }

        }

    }


    return todoOk;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
