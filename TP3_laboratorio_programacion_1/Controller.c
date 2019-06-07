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
    ll_sort(pArrayListEmployee,employee_compararPorNombre,0);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
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
    Employee* pEmp;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
		pFile=fopen(path,"r");
		if(pFile!=NULL)
		{
			while(!feof(pFile)) //desde aca funcion constructor que reciba empleado
			{
				fread(&emp,sizeof(Employee),1,pFile);
				//printf("%s\n",emp.nombre);
				pEmp=employee_new();
				if(	!employee_setNombre(pEmp,emp.nombre)&&
					!employee_setId(pEmp,emp.id)&&
					!employee_setHorasTrabajadas(pEmp,emp.horasTrabajadas)&&
					!employee_setSueldo(pEmp,emp.sueldo))
				{
					ll_add(pArrayListEmployee,pEmp);
				}
				else
				{
					//employee_delete(pEmp);
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
		}

    }
    return 1;
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
	Employee* pAux=NULL;
	int retorno=-1;
	if(	!utn_getInt("\nIngrese id del empleado:","ERROR",1,ll_len(pArrayListEmployee),2,&idMod) &&
		!employee_getEmpById(pArrayListEmployee,idMod,pAux))
	{
		employee_getNombre(pAux,bufferNombre);
		employee_getHorasTrabajadas(pAux,bufferHorasTrabajadas);

		printf("\nNOMBRE:%s",bufferNombre);
		printf("\nHoras:%s",bufferHorasTrabajadas);
/*		if(	!utn_getName("\nIngrese nombre: ","ERROR",1,128,2,bufferNombre) &&
			!utn_getIntStr("\nIngrese horas trabajadas: ","ERROR",1,6,1,100000,2,bufferHorasTrabajadas) &&
			!utn_getIntStr("\nIngrese sueldo: ","ERROR",1,7,1,1000000,2,bufferSueldo))
		{
			if(	!employee_setNombre(pAux,bufferNombre) &&
				!employee_setHorasTrabajadasStr(pAux,bufferHorasTrabajadas) &&
				!employee_setSueldoStr(pAux,bufferSueldo))
			{
				printf("\nENTRO");
				retorno=0;
			}
		}*/
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
    return 1;
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
    return 1;
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
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
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
				//printf("%s\n",pEmp->nombre);
				fwrite(pEmp,sizeof(Employee),1,pFile);
			}
		}
    }
    fclose(pFile);
    return retorno;
}

