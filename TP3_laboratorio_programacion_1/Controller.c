#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno=-1;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
		pFile=fopen(path,"r");
		if(pFile!=NULL)
		{
			parser_EmployeeFromText(pFile,pArrayListEmployee);
			retorno=0;
		}
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
    int retorno=-1;
    Employee emp;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
		pFile=fopen(path,"r");
		if(pFile!=NULL)
		{
			while(!feof(pFile))
			{
				fread(&emp,sizeof(Employee),1,pFile);
				if(!employee_newByStruct(pArrayListEmployee,emp))
				{
					retorno=0;
				}
			}
		}
    }
    fclose(pFile);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char bufferName[128];
    char bufferHoras[128];
    char bufferSueldo[128];
    char bufferId[128];
    int retorno=-1;
    int id;
    Employee* pAux;

    if(pArrayListEmployee!=NULL)
    {
		if(	!utn_getName("\nIngrese nombre: ","ERROR",1,128,2,bufferName) &&
			!utn_getIntStr("\nIngrese horas trabajadas: ","ERROR",1,6,1,100000,2,bufferHoras) &&
			!utn_getIntStr("\nIngrese sueldo: ","ERROR",1,7,1,1000000,2,bufferSueldo))
		{
			id=employee_getIdMax(pArrayListEmployee);
			sprintf(bufferId,"%d",id+1);
			pAux=employee_newParametros(bufferId,bufferName,bufferHoras,bufferSueldo);
			ll_add(pArrayListEmployee,pAux);
			retorno=0;
		}

    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    char bufferNombre[128];
    char bufferHorasTrabajadas[128];
    char bufferSueldo[128];
	int idMod;
	int indice;
	int llSize=ll_len(pArrayListEmployee);
	Employee* pAux;
	int retorno=-1;

	if(	!utn_getInt("\nIngrese id del empleado:","ERROR",1,llSize,2,&idMod) &&
		!employee_getEmpById(pArrayListEmployee,idMod,&indice) &&
        indice<=llSize)
	{
        pAux=ll_get(pArrayListEmployee,indice);
        if(	!utn_getName("\nIngrese nombre: ","ERROR",1,128,2,bufferNombre) &&
            !utn_getIntStr("\nIngrese horas trabajadas: ","ERROR",1,6,1,100000,2,bufferHorasTrabajadas) &&
            !utn_getIntStr("\nIngrese sueldo: ","ERROR",1,7,1,1000000,2,bufferSueldo))
		{
			if(	!employee_setNombre(pAux,bufferNombre) &&
				!employee_setHorasTrabajadasStr(pAux,bufferHorasTrabajadas) &&
				!employee_setSueldoStr(pAux,bufferSueldo))
			{
				retorno=0;
			}
		}
	}
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* pEmpDel;
    int indice;
    int id;
    int llSize=ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL)
    {
        if(	!utn_getInt("\nIngrese id del empleado:","ERROR",1,llSize,2,&id) &&
            !employee_getEmpById(pArrayListEmployee,id,&indice))
        {
            pEmpDel=ll_pop(pArrayListEmployee,indice);
            employee_delete(pEmpDel);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int bufferId;
    char bufferNombre[4096];
    int bufferHoras;
    int bufferSueldo;

    int i;
    int len;
    int retorno=-1;
    Employee* pAux;
    len=ll_len(pArrayListEmployee);
    printf("len ll:%d",len);
    for(i=0;i<len;i++)
    {
        if(pArrayListEmployee!=NULL)
		{
			pAux=ll_get(pArrayListEmployee,i);
		}
		if(	!employee_getId(pAux,&bufferId) &&
			!employee_getNombre(pAux,bufferNombre) &&
			!employee_getHorasTrabajadas(pAux,&bufferHoras) &&
			!employee_getSueldo(pAux,&bufferSueldo))
		{
			printf("\nID:%d\nNombre:%s\nHoras:%d\nSueldo:%d\n", bufferId,
                                                                bufferNombre,
                                                                bufferHoras,
                                                                bufferSueldo);
			retorno=0;
		}
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(pArrayListEmployee!=NULL)
    {
        ll_sort(pArrayListEmployee,employee_compararPorNombre,1);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    char bufferId[128];
    char bufferNombre[128];
    char bufferHoras[128];
    char bufferSueldo[128];
    int retorno=-1;
    int i;

	Employee* pAux=NULL;
	FILE* pFile=NULL;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
		pFile=fopen(path,"w");
		if(pFile!=NULL)
		{
			for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                pAux=ll_get(pArrayListEmployee,i);
                if(	pAux !=NULL &&
                    !employee_getIdStr(pAux,bufferId) &&
                    !employee_getNombre(pAux,bufferNombre) &&
                    !employee_getHorasStr(pAux,bufferHoras) &&
                    !employee_getSueldoStr(pAux,bufferSueldo))
                {
                    fprintf(pFile,"%s,%s,%s,%s\n",  bufferId,
                                                    bufferNombre,
                                                    bufferHoras,
                                                    bufferSueldo);
                    retorno=0;
                }
            }
		}
    }
    fclose(pFile);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int i;
	Employee* pEmp=NULL;
	FILE* pFile=NULL;
    int retorno=-1;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
		pFile=fopen(path,"w");
		if(pFile!=NULL)
		{
			for(i=0;i<ll_len(pArrayListEmployee);i++)
			{
				pEmp=ll_get(pArrayListEmployee,i);
				fwrite(pEmp,sizeof(Employee),1,pFile);
				retorno=0;
			}
		}
    }
    fclose(pFile);
    return retorno;
}

