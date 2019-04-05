#include <stdio.h>
#include <stdlib.h>
/**
* \brief suma dos float y devuelve el resultado
* \param primer operando
* \param segundo operando
* \param devuelvo el resultado al usuario por referencia
* \return 0 salio todo bien
*
*/
int sumarDosFloat(float primerOperando,float segundoOperando,float *resultado)
{
    *resultado=primerOperando+segundoOperando;
    return 0;
}
/**
* \brief resta dos float y devuelve el resultado
* \param primer operando
* \param segundo operando
* \param devuelvo el resultado al usuario por referencia
* \return 0 salio todo bien
*
*/
int restarDosFloat(float primerOperando,float segundoOperando,float *resultado)
{
    *resultado=primerOperando-segundoOperando;
    return 0;
}
/**
* \brief divide el primer numero por el segundo y devuelve el resultado
* \param primer operando
* \param segundo operando
* \param devuelvo el resultado al usuario por referencia
* \return 0 salio todo bien
* \return -1 error, el usuario ingreso uno o dos ceros
*
*/
int dividir(float primerOperando,float segundoOperando,float *resultado)
{
    if(primerOperando!=0 && segundoOperando!=0)
    {
        *resultado=primerOperando/segundoOperando;
        return 0;
    }
    else
    {
        printf("Error\n");
        return -1;
    }
}
/**
* \brief multiplica dos float y devuelve el resultado
* \param primer operando
* \param segundo operando
* \param devuelvo el resultado al usuario por referencia
* \return 0 salio todo bien
*
*/
int multiplicarDosFloat(float primerOperando,float segundoOperando,float *resultado)
{
    *resultado=primerOperando*segundoOperando;
    return 0;
}
/**
* \brief calcula factorial y devuelve el resultado
* \param operando
* \param devuelvo el resultado al usuario por referencia
* \return 0 salio todo bien
* \return -1 error el usuario ingreso cero
*
*/
int factorial(float operando,float *resultado)
{
    int i;
    float fact=1;
    if(operando!=0)
    {
        for(i=1;i<=operando;i++)
        {
            fact=fact*i;
        }
        *resultado=fact;
        return 0;
    }
    else
    {
        printf("Error\n");
        return -1;
    }
}

