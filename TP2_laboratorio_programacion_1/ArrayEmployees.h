typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

int initEmployees(Employee *list,int len);
int addEmployee(Employee* list, int len);
int emp_isEmpty(Employee *list,int len,int *index);
int findEmployeeById(Employee* list, int len,int id,int *indice);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order,int orderSame);
int printEmployees(Employee* list, int len);
int modifyEmployee(Employee *list,int len);
int secondReport(Employee *list,int len);
