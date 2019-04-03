float sumar (float x,float y)
{
    float suma;

    suma=x+y;

    return suma;
}
float restar (float x, float y)
{
    float resta;

    resta=x-y;

    return resta;
}
 float dividir (float x, float y)
{
    float division;

    division=x/y;

    return division;
}
float multiplicar (float x, float y)
{
    float multiplicacion;

    multiplicacion=x*y;

    return multiplicacion;
}
float factorear (float x)
{
    float factoreo;
    int i;
    factoreo=1;

    for (i=1;i<=x;i++)
    {
        factoreo = factoreo*i;
    }

    return factoreo;
}
