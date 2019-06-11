#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int input_getInt (int* input, char *message, char *eMessage, int lowLimit, int hiLimit)
{
    int todoOk = -1;
    int valor;

    printf("%s", message);
    scanf("%d", &valor);

    while(valor<lowLimit || valor> hiLimit)
    {
        printf(eMessage);
        scanf("%d", &valor);
    }

    *input=valor;
    todoOk=0;

    return todoOk;
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int input_getFloat (float* input, char *message, char *eMessage, int lowLimit, int hiLimit)
{
    int todoOk = -1;
    float valor;

    printf("%s", message);
    scanf("%f", &valor);

    while(valor<lowLimit || valor>hiLimit)
    {
        printf(eMessage);
        scanf("%f", &valor);
    }

    *input=valor;
    todoOk=0;



    return todoOk;
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int input_getChar (char* input, char *message, char *eMessage, char lowLimit, char hiLimit)
{
     int todoOk = -1;

    printf ("%s", message);
    fflush(stdin);
    scanf ("%c", input);

    while(*input>hiLimit || *input<lowLimit)
    {
       printf ("%s", eMessage);
       fflush(stdin);
       scanf  ("%c", input);
    }

    todoOk=0;

    return todoOk;
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int input_getString(char* input, char *message, char *eMessage, int lowLimit, int hiLimit)
{
    int todoOk=-1;

    system("cls");
    printf ("%s",message);
    fflush(stdin);
    scanf("%s", input);

    while(strlen(input)>hiLimit || strlen(input)<lowLimit)
    {
        printf("%s", eMessage);
        fflush(stdin);
        scanf("%s", input);


    }
        todoOk=0;


     return todoOk;

}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void input_validarDosChar(char* input, char message[], char eMessage[], char lowLimit, char hiLimit)
{
    printf("%s", message);
    fflush(stdin);
    *input=getche();
    printf("\n");
    system("pause");


    *input = tolower(*input);

    while (*input != lowLimit && *input != hiLimit)
    {
        printf("\n");
        printf(eMessage);
        printf("\n\n");
        printf(message);

        scanf("%c", input);
        fflush(stdin);
        *input = tolower(*input);
    }
}




