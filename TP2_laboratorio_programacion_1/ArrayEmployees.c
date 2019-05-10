#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"

/** \brief  To indicate that all position in the array are empty,
 *          this function put the flag (isEmpty) in TRUE in all
 *          position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
 int initEmployees(Employee *list,int len)
 {
     int i;
     int retorno=-1;
     if(list!=NULL)
     {
         for(i=0;i<len;i++)
         {
             list[i].isEmpty=1;
         }
         retorno=0;
     }
     return retorno;
 }
/** \brief  add in a existing list of employees the values received as parameters
 *          in the first empty position
 * \param list employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] -
 *          (0) if Ok
 *
 */
int addEmployee(Employee* list, int len)
{
    char bufferName[51];
    char bufferLastName[51];
    float bufferSalary;
    int bufferSector;
    int i;
    int retorno=-1;
    if(list!=NULL && emp_isEmpty(list,len,&i)==0)
    {
        getString("Ingrese el nombre: ","Error",1,51,2,bufferName);
        getString("Ingrese la apellido: ","Error",1,51,2,bufferLastName);
        getInt("Ingrese el sector: ","Error",0,200,2,&bufferSector);
        getFloat("Ingrese el salario: ","Error",1,100000,2,&bufferSalary);
        strncpy(list[i].name,bufferName,51);
        strncpy(list[i].lastName,bufferLastName,51);
        list[i].sector=bufferSector;
        list[i].salary=bufferSalary;
        list[i].isEmpty=0;
        retorno=0;
    }
    return retorno;
}
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
 *         pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id,int *indice)
{
    int retorno=-1;
    int i;
    for(i=0;i<len;i++)
    {
        if(list[i].id==id)
        {
            *indice=i;
            retorno=0;
        }
    }
    return retorno;
}
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
 *         find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
    int i;
    int retorno=-1;
    if(list!=NULL)
    {
        findEmployeeById(list,len,id,&i);
        list[i].isEmpty=1;
        retorno=0;
    }
    return retorno;
}
/** \brief Sort the elements in the array of employees,
 *          the argument order indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \param orderSame int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order,int orderSame)
{
    int retorno=-1;
    int i;
    Employee buffer;
    int flagSwap;

    if(list!=NULL && len>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < len; i++)
            {
                if( ((strcmp(list[i].lastName,list[i+1].lastName) < 0) && order) ||
                    ((strcmp(list[i].lastName,list[i+1].lastName) > 0) && !order) )
                {
                    flagSwap=1;
                    buffer = list[i];
                    list[i] = list[i+1];
                    list[i+1] = buffer;
                }
                else if(strcmp(list[i].lastName,list[i+1].lastName) == 0)
                {
                    if( ((list[i].sector< list[i+1].sector) && orderSame) ||
                        ((list[i].sector > list[i+1].sector) && !orderSame) )
                    {
                        flagSwap=1;
                        buffer = list[i];
                        list[i] = list[i+1];
                        list[i+1] = buffer;
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param len int
 * \return int
 *
 */
int printEmployees(Employee* list, int len)
{
    int i;
    int retorno=-1;
    for(i=0;i<len;i++)
    {
        if(list!=NULL && list[i].isEmpty==0)
        {
            printf("\nID: %d\nName: %s\nLast name: %s\nSalary: %.2f\nSector: %d\n",
                   list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
            retorno=0;
        }
    }
    return retorno;
}
/** \brief modifica, mediante un menu, los campos seleccionados de un empleado
 *
 * \param list Employee*
 * \param len int
 * \return int
 *
 */
int modifyEmployee(Employee *list,int len)
{
    int id;
    int opcionMod=0;
    int retorno=-1;
    int indiceEmployee;
    getInt("\nIngrese ID:","\nERROR,reingrese ID:",0,len*2,2,&id);
    if(findEmployeeById(list,len,id,&indiceEmployee)==0)
    {
        while(opcionMod!=5)
        {
            getInt("\nModificar:\n1-Nombre\n2-Apellido\n3-Salario\n4-Sector\n5-Salir\n","\nERROR,reingrese opcion",1,5,2,&opcionMod);
            switch(opcionMod)
            {
                case 1:
                {
                    if(getName("\nIngrese el nombre: ","Error",1,51,2,list[indiceEmployee].name)==0)
                    {
                        printf("\nNombre modificado con exito");
                    }
                    else
                    {
                        printf("\nERROR");
                    }
                    break;
                }
                case 2:
                {
                    if(getName("\nIngrese el nombre: ","Error",1,51,2,list[indiceEmployee].lastName)==0)
                    {
                        printf("\nApellido modificado con exito");
                    }
                    else
                    {
                        printf("\nERROR");
                    }
                    break;
                }
                case 3:
                {
                    if(getFloat("\nIngrese el salario: ","Error",0,100000,2,&list[indiceEmployee].salary)==0)
                    {
                        printf("\nSalario modificado con exito");
                    }
                    else
                    {
                        printf("\nERROR");
                    }
                    break;
                }
                case 4:
                {
                    if(getInt("\nIngrese el sector: ","Error",0,100000,2,&list[indiceEmployee].sector)==0)
                    {
                        printf("\nSector modificado con exito");
                    }
                    else
                    {
                        printf("\nERROR");
                    }
                    break;
                }
            }
            retorno=0;
        }
    }
    else
    {
        printf("\nEl ID no existe\n");
    }
    return retorno;
}

int secondReport(Employee *list,int len)
{
    int i;
    float promedio;
    float acumulador=0;
    int acumuladorEmp=0;
    for(i=0;i<len;i++)
    {
        acumulador=acumulador+list[i].salary;
    }
    promedio=acumulador/len;
    for(i=0;i<len;i++)
    {
        if(list[i].salary>promedio)
        {
            acumuladorEmp++;
        }
    }
    printf("\nTotal de salarios: %.2f\nPromedio de salarios: %.2f\nEmpleados que superan el promedio: %d\n",
           acumulador,promedio,acumuladorEmp);
    return 0;
}

int emp_isEmpty(Employee *list,int len,int *index)
{
    int i;
    int retorno=-1;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            *index=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}
