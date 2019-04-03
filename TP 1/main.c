#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    float operandoA;
    float operandoB;
    int flag;
    char rta;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    float factoreoA;
    float factoreoB;
    int casoTres;

    operandoA=0;
    operandoB=0;
    casoTres=0;
    flag=0;

    while (flag==0)
    {
        printf ("\nPresione 1 para ingresar un valor. <valor1 = %.2f>\n", operandoA);
        printf ("Presione 2 para ingresar otro valor. <valor2 = %.2f>\n", operandoB);
        printf ("Presione 3 para calcular las operaciones.\n");
        printf ("Presione 4 para mostrar los resultados.\n");
        printf ("Presione 5 para salir.\n");
        fflush (stdin);
        scanf("%c", &rta);

        switch (rta)
        {
        case '1':
            printf ("Ingrese un valor: ");
            scanf ("%f", &operandoA);
            break;
        case '2':
            printf ("Ingrese el segundo valor: ");
            scanf ("%f", &operandoB);
            break;
        case '3':
            casoTres=1;
            suma = sumar (operandoA, operandoB);
            resta = restar(operandoA, operandoB);
            division = dividir (operandoA,operandoB);
            multiplicacion = multiplicar (operandoA, operandoB);
            factoreoA = factorear(operandoA);
            factoreoB = factorear(operandoB);

            break;
        case '4':
            if (casoTres==1)
            {
                printf ("\n\nEl resultado de A+B es: %.2f\n\n", suma);
                printf ("El resultado de A-B es: %.2f\n\n", resta);
                if (operandoB==0)
                {
                    printf ("ERROR: No es posible dividir por cero\n\n");
                }
                else
                {
                    printf ("El resultado de A/B es: %.2f\n\n", division);
                }
                    printf("El resultado de A*B es: %.2f\n\n", multiplicacion);
                if (operandoA<0 && operandoB<0)
                {
                    printf ("ERROR: No hay factoriales negativos\n");
                }
                else if (operandoA>0 && operandoB<0)
                {
                    printf ("El factorial de A es: %0.f B es un valor negativo y no hay factorial\n\n", factoreoA);
                }
                else if (operandoA<0 && operandoB>0)
                {
                    printf ("El factorial de B es: %0.f A es un valor negativo y no hay factorial\n", factoreoB);
                }
                else
                {
                    printf ("El factorial de A es: %0.f y el factorial de B es: %0.f\n\n", factoreoA, factoreoB);
                }
            }
            else
            {
                printf ("\n\nNo se puede mostrar resultados si no se han calculado previamente.\n\n");
            }
            break;
        case '5':
            flag=1;
        break;
        }

    }
    return 0;
}

