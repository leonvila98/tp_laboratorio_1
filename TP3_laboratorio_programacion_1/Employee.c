#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

/** \brief Crea un espacio de memoria con espacio para un Employee.
 *
 * \param void
 * \return Employee* Puntero a la primera posicion del espacio de memoria creado.
 *
 */
Employee* employee_new(void)
{
	return (Employee*) malloc(sizeof(Employee));
}

/** \brief Crea un espacio de memoria con espacio para un Employee y lo crea mediante
 *         los parametros pasados.
 *
 * \param char* id (del Employee a crear).
 * \param char* nombre (del Employee a crear).
 * \param char* horas trabajadas (del Employee a crear).
 * \param char* sueldo (del Employee a crear).
 * \return Employee* Puntero a la primera posicion del espacio de memoria creado.
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* retorno=NULL;
	Employee* pAuxEmployee;

	if(idStr!=NULL &&
	   nombreStr!=NULL &&
	   horasTrabajadasStr!=NULL &&
	   sueldoStr!=NULL)
	{
		pAuxEmployee=employee_new();
		if(pAuxEmployee!=NULL)
		{
			if(	!employee_setIdStr(pAuxEmployee,idStr) &&
				!employee_setNombre(pAuxEmployee,nombreStr) &&
				!employee_setHorasTrabajadasStr(pAuxEmployee,horasTrabajadasStr) &&
				!employee_setSueldoStr(pAuxEmployee,sueldoStr) &&
				!employee_setEstado(pAuxEmployee,0))
			{
				retorno=pAuxEmployee;
			}
			else
			{
				employee_delete(pAuxEmployee);
			}
		}
	}
	return retorno;
}

/** \brief Crea un espacio de memoria con espacio para un Employee, lo crea
 *         mediante la estructrura pasada y lo guarda en una LinkedList.
 *
 * \param LinkedList* lista (LinkedList a guardar el Employee creado).
 * \param Employee emp (Employee a guardar en la LinkedList).
 * \return Int retorno (0-Pudo crear y guardar el Employee)((-1)-No pudo crear o guardar el Employee).
 *
 */
int employee_newByStruct(LinkedList* lista,Employee emp)
{
    Employee* pEmp;
    int retorno=-1;

    pEmp=employee_new();
    if(	!employee_setNombre(pEmp,emp.nombre)&&
        !employee_setId(pEmp,emp.id)&&
        !employee_setHorasTrabajadas(pEmp,emp.horasTrabajadas)&&
        !employee_setSueldo(pEmp,emp.sueldo))
    {
        ll_add(lista,pEmp);
        retorno=0;
    }
    else
    {
        employee_delete(pEmp);
    }
    return retorno;
}

/** \brief Libera el espacio en memoria ocupado por un Employee(Delete).
 *
 * \param void
 * \return Employee* Puntero a la primera posicion del espacio de memoria creado.
 *
 */
void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

/** \brief Set del id en un Employee.
 *
 * \param Employee* Puntero del Employee
 * \param int id del Employee
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int employee_setId(Employee* this,int id)
{
	int retorno = -1;
    if(this != NULL && !isValidInt(id,10000,0))
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el id de un Employee.
 *
 * \param Employee* Puntero del Employee
 * \param int* id del Employee
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Set del nombre en un Employee.
 *
 * \param Employee* Puntero del Employee
 * \param char* nombre del Employee
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
    if(this != NULL && !isValidName(nombre))
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el nombre de un Employee.
 *
 * \param Employee* Puntero del Employee
 * \param char* nombre del Employee
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

/** \brief Set de horas trabajadas en un Employee.
 *
 * \param Employee* Puntero del Employee
 * \param int horas trabajadas del Employee
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
    if(this != NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene horas trabajadas de un Employee.
 *
 * \param Employee* Puntero del Employee
 * \param int* horasTrabajadas del Employee
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

/** \brief Set del sueldo en un Employee.
 *
 * \param Employee* Puntero del Employee
 * \param int sueldo del Employee
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
    if(this != NULL)
    {
        this->sueldo=sueldo;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el sueldo de un Employee.
 *
 * \param Employee* Puntero del Employee
 * \param int* sueldo del Employee
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

/** \brief Set del estado en un Employee.
 *
 * \param Employee* Puntero del Employee
 * \param int estado del Employee
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int employee_setEstado(Employee* this,int estado)
{
	int retorno = -1;
    if(this != NULL && !isValidInt(estado,1,0))
    {
        this->estado = estado;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el estado de un Employee.
 *
 * \param Employee* Puntero del Employee
 * \param int* estado del Employee
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int employee_getEstado(Employee* this,int* estado)
{
	int retorno = -1;
    if(this != NULL && estado != NULL)
    {
        *estado = this->estado;
        retorno = 0;
    }
    return retorno;
}

/** \brief Set del id en string en un Employee.
 *
 * \param Employee* Puntero del Employee
 * \param char* id del Employee
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int employee_setIdStr(Employee* this, char* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = employee_setId(this,atoi(id));
    }
    return retorno;
}

/** \brief Obtiene el id en string de un Employee.
 *
 * \param Employee* Puntero del Employee
 * \param char* id del Employee
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int employee_getIdStr(Employee* this, char* id)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && id != NULL)
    {
        employee_getId(this,&bufferInt);
        sprintf(id,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

/** \brief Set de horas trabajadas en string en un Employee.
 *
 * \param Employee* Puntero del Employee
 * \param char* horasTrabajadas del Employee
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int employee_setHorasTrabajadasStr(Employee* this, char* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = employee_setHorasTrabajadas(this,atoi(horasTrabajadas));
    }
    return retorno;
}

/** \brief Obtiene horas trabajadas en string de un Employee.
 *
 * \param Employee* Puntero del Employee
 * \param char* horas del Employee
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int employee_getHorasStr(Employee* this, char* horas)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && horas != NULL)
    {
        employee_getHorasTrabajadas(this,&bufferInt);
        sprintf(horas,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

/** \brief Set del sueldo en string en un Employee.
 *
 * \param Employee* Puntero del Employee
 * \param char* sueldo del Employee
 * \return int retorno (0-Pudo hacer el set)((-1)-No pudo hacer el set).
 *
 */
int employee_setSueldoStr(Employee* this, char* sueldo)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = employee_setSueldo(this,atoi(sueldo));
    }
    return retorno;
}

/** \brief Obtiene el sueldo en string de un Employee.
 *
 * \param Employee* Puntero del Employee
 * \param char* sueldo del Employee
 * \return int retorno (0-Pudo obtener)((-1)-No pudo obtener).
 *
 */
int employee_getSueldoStr(Employee* this, char* sueldo)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && sueldo != NULL)
    {
        employee_getSueldo(this,&bufferInt);
        sprintf(sueldo,"%d",bufferInt);
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el id maximo de un Employee en una LinkedList.
 *
 * \param LinkedList* pArray .
 * \return int max retorna el id mas grande.
 *
 */
int employee_getIdMax(LinkedList* pArray)
{
	int i;
	int id;
	int max;
	int flag=0;
	Employee* pAux;
	if(pArray!=NULL)
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			pAux=ll_get(pArray,i);
			employee_getId(pAux,&id);
			if(flag==0 || id>max)
			{
				max=id;
				flag=1;
			}
		}
	}
	return max;
}

/** \brief Obtiene el indice de un Empleado mediante su id.
 *
 * \param LinkedList* pArray.
 * \param int id del Employee
 * \param int* indice del Employee buscado.
 * \return int retorno (0-Si lo encontro)((-1)-No lo encontro).
 *
 */
int employee_getEmpById(LinkedList* pArray,int id,int* indice)
{
	int i;
	Employee* pAuxEmp;
	int bufferId;
	int retorno=-1;

	if(pArray!=NULL)
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			pAuxEmp=ll_get(pArray,i);
			if(!employee_getId(pAuxEmp,&bufferId))
            {
                if(id==bufferId)
                {
                    *indice=i;
                    retorno=0;
                    break;
                }
            }
		}
	}
	return retorno;
}

/** \brief Compara por nombre dos Employee.
 *
 * \param void* this1.
 * \param void* this2.
 * \return int retorno (0-Si son iguales)(1-si this1 es mas grande que this2)
 *                      ((-1)-si this1 es mas chico que this2).
 *
 */
int employee_compararPorNombre(void* this1,void* this2)//recibe dos void
{
	char bufferA[4096];
	char bufferB[4096];

	employee_getNombre((Employee*)this1,bufferA);
	employee_getNombre((Employee*)this2,bufferB);
	if(strcmp(bufferA,bufferB)>0)
		return 1;
	else if(strcmp(bufferA,bufferB)<0)
		return -1;
	return 0;
}

//int fun(int indice,int (*pFun) (void*,void*),float peso)
