#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define QTY_EMP 4

int main()
{
    Employee arrayEmp[QTY_EMP];
    int i;
    int id;
    int opcion;
    int opcionInfo;
    for(i=0;i<QTY_EMP;i++)
    {
        arrayEmp[i].id=i*2;
    }
    initEmployees(arrayEmp,QTY_EMP);
    printEmployees(arrayEmp,QTY_EMP);

    getInt("\n1-Alta empleado\n2-Modificar empleado\n3-Baja empleado\n4-Informes\n","Error",1,4,2,&opcion);
    switch(opcion)
    {
        case 1:
        {
            if(addEmployee(arrayEmp,QTY_EMP)==0)
            {
                printEmployees(arrayEmp,QTY_EMP);
                return 0;
            }
            else
            {
                printf("\nNo hay espacio");
                return 1;
            }
            break;
        }
        case 2:
        {
            modifyEmployee(arrayEmp,QTY_EMP);
            break;
        }
        case 3:
        {
            printEmployees(arrayEmp,QTY_EMP);
            if(getInt("\nIngrese id a remover:","ERROR",0,QTY_EMP*2,2,&id)==0)
            {
                if(removeEmployee(arrayEmp,QTY_EMP,id)==0)
                {
                    printEmployees(arrayEmp,QTY_EMP);
                    printf("Se removio con exito");
                    return 0;
                }
            }
            else
            {
                printf("\nError");
                return 1;
            }
            break;
        }
        case 4:
        {
            getInt("\n1-Empleados ordenados alfabeticamente\n2-Total y promedio de los salarios,empleados que lo superan\n",
                   "ERROR",1,2,2,&opcionInfo);
            if(opcionInfo==1)
            {
                sortEmployees(arrayEmp,QTY_EMP,1,1);
                printEmployees(arrayEmp,QTY_EMP);
                break;
            }
            else if(opcionInfo==2)
            {
                secondReport(arrayEmp,QTY_EMP);
                break;
            }
            break;
        }
    }
    return 0;
}
