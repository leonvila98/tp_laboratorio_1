#include <stdio.h>
#include <stdlib.h>

int isValidInt(int numero,int max,int min)
{
    if(numero<=max && numero>=min)
    {
        return 1;
    }
    return 0;
}

int getInt(char *mensaje,char *mensajeError,int minimo,
            int maximo,int reintentos,int *resultado)
{
    int buffer;
    int retorno=-1;
    if(mensaje != NULL && mensajeError != NULL && maximo >= minimo && reintentos>=0)
    {
        do
        {
            printf("%s",mensaje);
            scanf("%d",&buffer);
            if(isValidInt(buffer,maximo,minimo))
            {
                *resultado=buffer;
                retorno=0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    else
    {
        printf("%s",mensajeError);
    }
    return retorno;
}
int isValidFloat(float numero,float max,float min)
{
    if(numero<=max && numero>=min)
    {
        return 1;
    }
    return 0;
}

int getFloat(char *mensaje,char *mensajeError,float minimo,float maximo,int reintentos,float *resultado)
{
    int retorno=-1;
    float buffer;
    if(mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
    {
        do
        {
            printf("%s",mensaje);
            scanf("%f",&buffer);
            if(isValidFloat(buffer,maximo,minimo))
            {
                *resultado=buffer;
                retorno=0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    return retorno;
}

int isValidChar(char caracter,char min,char max)
{
    if(caracter<=max && caracter>=min)
    {
        return 1;
    }
    return 0;
}
int getChar(char *mensaje,char *mensajeError,char minimo,char maximo,int reintentos,char *resultado)
{
    int retorno=-1;
    char buffer;
    if(mensaje!=NULL && mensajeError!=NULL && maximo>=minimo && reintentos>=0)
    {
        do
        {
            printf("%s",mensaje);
            //__fpurge(stdin);
            scanf("%c",&buffer);
            if(isValidChar(buffer,minimo,maximo))
            {
                *resultado=buffer;
                retorno=0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    return retorno;
}

