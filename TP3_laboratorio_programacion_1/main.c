#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int aux;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        printf("\n-----------------------------------------------");
        printf("\n1.Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
        printf("\n2.Cargar los datos de los empleados desde el archivo data.csv (modo binario)");
        printf("\n3.Alta de empleado");
        printf("\n4.Modificar datos de empleado");
        printf("\n5.Baja de empleado");
        printf("\n6.Listar empleados");
        printf("\n7.Ordenar empleados");
        printf("\n8.Guardar los datos de los empleados en el archivo data.csv (modo texto)");
        printf("\n9.Guardar los datos de los empleados en el archivo data.csv (modo binario)");
        printf("\n10.Salir");

        if(!utn_getInt("\nOpcion:","\nOpcion no valida",1,10,2,&option))
        {
			switch(option)
			{
				case 1:
				{
					controller_loadFromText("data.csv",listaEmpleados);
					break;
				}
				case 2:
				{

					break;
				}
				case 3:
				{

					break;
				}
				case 4:
				{

					break;
				}
				case 5:
				{

					break;
				}
				case 6:
				{
                    if(!controller_ListEmployee(listaEmpleados))
                    {
						break;
                    }
					else
					{
						printf("\nGG");
					}
				}
				case 7:
				{

					break;
				}
				case 8:
				{

					break;
				}
				case 9:
				{

					break;
				}
			}
        }
    }while(option != 10);
    return 0;
}
