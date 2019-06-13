#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        printf("\n-----------------------------------------------");
        printf("\n1.Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
        printf("\n2.Cargar los datos de los empleados desde el archivo data.bin (modo binario)");
        printf("\n3.Alta de empleado");
        printf("\n4.Modificar datos de empleado");
        printf("\n5.Baja de empleado");
        printf("\n6.Listar empleados");
        printf("\n7.Ordenar empleados");
        printf("\n8.Guardar los datos de los empleados en el archivo data.csv (modo texto)");
        printf("\n9.Guardar los datos de los empleados en el archivo data.bin (modo binario)");
        printf("\n10.Salir");
        __fpurge(stdin);
        if(!utn_getInt("\nOpcion:","\nOpcion no valida",1,10,2,&option))
        {
			switch(option)
			{
				case 1:
				{
					printf("\nCargar datos de texto");
					controller_loadFromText("data.csv",listaEmpleados);
					break;
				}
				case 2:
				{
					printf("\nCargar datos de binario");
					if(!controller_loadFromBinary("data.bin",listaEmpleados))
                    {
                        printf("\nCargado con exito");
                        printf("\nLEN:%d",ll_len(listaEmpleados));
                    }
                    else
                    {
                        printf("\nError al cargar");
                    }
					break;
				}
				case 3:
				{
                    printf("\nAlta de empleado");
                    if(!controller_addEmployee(listaEmpleados))
					{
						printf("\nEmpleado agregado con exito");
					}
					else
					{
						printf("\nError al agregar empleado");
					}
					break;
				}
				case 4:
				{
					printf("\nModificar empleado");
					if(!controller_editEmployee(listaEmpleados))
					{
						printf("\nEmpleado modificado con exito");
					}
					else
					{
						printf("\nError al modificar");
					}
					break;
				}
				case 5:
				{
                    printf("\nBaja de empleado");
                    if(!controller_removeEmployee(listaEmpleados))
                    {
                        printf("\nEmpleado eliminado con exito");
                    }
                    else
                    {
                        printf("\nError al eliminar");
                    }
					break;
					break;
				}
				case 6:
				{
                    printf("\nListar empleados");
                    if(!controller_ListEmployee(listaEmpleados))
                    {
						printf("\nLista completa");
                    }
					else
					{
						printf("\nError");
					}
					break;
				}
				case 7:
				{
                    printf("\nListar empleados");
                    if(!controller_sortEmployee(listaEmpleados))
                    {
						printf("\nOrdenados con exito");
                    }
					else
					{
						printf("\nError al ordenar");
					}
					break;
				}
				case 8:
				{
                    printf("\nGuardar como texto");
                    if(!controller_saveAsText("data.csv",listaEmpleados))
                    {
						printf("\nGuardado con exito");
                    }
					else
					{
						printf("\nError al guardar");
					}
					break;
					break;
				}
				case 9:
				{
                    printf("\nGuardar en binario");
                    if(!controller_saveAsBinary("data.bin",listaEmpleados))
                    {
                        printf("\nGuardado con exito");
                    }
                    else
                    {
                        printf("\nError al guardar");
                    }
					break;
				}
			}
        }
    }while(option != 10);
    return 0;
}
