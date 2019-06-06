#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"
#define MINIMO -9999
#define MAXIMO 9999

int main()
{
    char seguir='s';
    int opcion=0;
    float primerOperando;
    float segundoOperando;
    float resultado;

    do
    {
        printf("1- Calcular suma (A+B)\n");
        printf("2- Calcular resta (A-B)\n");
        printf("3- Calcular division (A/B)\n");
        printf("4- Calcular multiplicacion (A*B)\n");
        printf("5- Calcular el factorial (A!)\n");
        printf("6- Calcular todas las operaciones\n");
        printf("7- Salir\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                getFloat("Ingrese primer operando:\n","Error\n",MINIMO,MAXIMO,10,&primerOperando);
                getFloat("Ingrese segundo operando:\n","Error\n",MINIMO,MAXIMO,10,&segundoOperando);
                sumarDosFloat(primerOperando,segundoOperando,&resultado);
                printf("%.2f + %.2f = %.2f\n",primerOperando,segundoOperando,resultado);
                break;
            case 2:
                getFloat("Ingrese primer operando:\n","Error\n",MINIMO,MAXIMO,10,&primerOperando);
                getFloat("Ingrese segundo operando:\n","Error\n",MINIMO,MAXIMO,10,&segundoOperando);
                restarDosFloat(primerOperando,segundoOperando,&resultado);
                printf("%.2f - %.2f = %.2f\n",primerOperando,segundoOperando,resultado);
                break;
            case 3:
                getFloat("Ingrese primer operando:\n","Error\n",MINIMO,MAXIMO,10,&primerOperando);
                getFloat("Ingrese segundo operando:\n","Error\n",MINIMO,MAXIMO,10,&segundoOperando);
                if(dividir(primerOperando,segundoOperando,&resultado)==0)
                {
                    printf("%.2f / %.2f = %.2f\n",primerOperando,segundoOperando,resultado);
                    return 1;
                }
                else
                {
                    printf("Intentelo nuevamente\n");
                    break;
                }
                break;
            case 4:
                getFloat("Ingrese primer operando:\n","Error",MINIMO,MAXIMO,10,&primerOperando);
                getFloat("Ingrese segundo operando:\n","Error",MINIMO,MAXIMO,10,&segundoOperando);
                multiplicarDosFloat(primerOperando,segundoOperando,&resultado);
                printf("%.2f * %.2f = %.2f\n",primerOperando,segundoOperando,resultado);
                break;
            case 5:
                getFloat("Ingrese operando:\n","Error",MINIMO,MAXIMO,10,&primerOperando);
                factorial(primerOperando,&resultado);
                printf("%.2f! = %.2f\n",primerOperando,resultado);
                break;
            case 6:
                getFloat("Ingrese primer operando:\n","Error\n",MINIMO,MAXIMO,10,&primerOperando);
                getFloat("Ingrese segundo operando:\n","Error\n",MINIMO,MAXIMO,10,&segundoOperando);
                sumarDosFloat(primerOperando,segundoOperando,&resultado);
                printf("%.2f + %.2f = %.2f\n",primerOperando,segundoOperando,resultado);
                restarDosFloat(primerOperando,segundoOperando,&resultado);
                printf("%.2f - %.2f = %.2f\n",primerOperando,segundoOperando,resultado);
                dividir(primerOperando,segundoOperando,&resultado);
                printf("%.2f / %.2f = %.2f\n",primerOperando,segundoOperando,resultado);
                multiplicarDosFloat(primerOperando,segundoOperando,&resultado);
                printf("%.2f * %.2f = %.2f\n",primerOperando,segundoOperando,resultado);
                factorial(primerOperando,&resultado);
                printf("%.2f! = %.2f\n",primerOperando,resultado);
                factorial(segundoOperando,&resultado);
                printf("%.2f! = %.2f\n",segundoOperando,resultado);
                break;
            case 7:
                seguir = 'n';
                break;
        }
    }while(seguir=='s');
    return 0;
}
