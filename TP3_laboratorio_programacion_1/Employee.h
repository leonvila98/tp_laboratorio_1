#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int estado;//0.INACTIVO-1.ACTIVO
}Employee;

Employee* employee_new(void);
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
int employee_newByStruct(LinkedList* lista,Employee emp);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setIdStr(Employee* this, char* id);
int employee_getIdStr(Employee* this, char* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setHorasTrabajadasStr(Employee* this, char* horasTrabajadas);
int employee_getHorasStr(Employee* this, char* horas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_setSueldoStr(Employee* this, char* sueldo);
int employee_getSueldoStr(Employee* this, char* sueldo);

int employee_setEstado(Employee* this,int estado);
int employee_getEstado(Employee* this,int* estado);

int employee_getIdMax(LinkedList* pArray);

int employee_getEmpById(LinkedList* pArray,int id,int* indice);

int employee_compararPorNombre(void* this1,void* this2);


#endif // employee_H_INCLUDED
