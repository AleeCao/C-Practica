/*Una empresa comercializa dos tipos de productos. Por día se tiene dos turnos en los cuales se realizan las ventas, como
máximo 100 diarias.

Al comenzar el día se conoce el stock de cada producto. Por cada venta se debe saber el tipo de producto y la cantidad
a vender.

El proceso de venta termina cuando se llega a las 100 ventas o no queda stock en ninguno de los dos productos.

Se desea realizar un programa que simule la venta del día y obtenga la siguiente información:
1)	Indicar la cantidad vendida de cada producto por turno.
2)	Al final del día, mostrar el porcentaje de cantidad vendida de cada producto respecto del total de cantidad vendida.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>
#include<string.h>

#define MAX 100

//Defino funciones
void ventas(int turn, int *cantVent);
void cerrarDia(int *cantidadVendidas);

int main() 
{
	int turno = 0, op = 0, vent[5] = { 0, 0, 0, 0, 0 };
	bool salida = false;
	while (!salida)
	{
		system("cls");
		printf("====MENU====");
		printf("\nSeleccione una opcion:");
		printf("\n1)Ventas.");
		printf("\n2)Cerrar dia.");
		printf("\n\n0)Salida.\n");
		scanf("%i", &op);
		switch (op)
		{
		case 0:
			salida = true;
			break;
		case 1:
			system("cls");
			printf("Ingrese el turno: ");
			scanf("%i", &turno);
			ventas(turno, &vent);
			break;
		case 2:
			cerrarDia(&vent);
			_getch();
			salida = true;
			break;
		default:
			printf("Ingreso una opccion incorecta");
			break;
		}
	}
	return 0;
}

//Implemento las funciones
void ventas(int turn, int *cantVent)
{
	int prod = 0;
	int cant = 0;
	system("cls");
	if (turn==1)
	{
		printf("Bienvenido turno %i \n", turn);
		printf("Indique el producto a vender: \n1) Papa \n2) Cebolla \n");
		scanf("%i", &prod);
		printf("Indique la cantidad: ");
		scanf("%i", &cant);
		cantVent[prod - 1] = cantVent[prod - 1] + cant;
	}
	if (turn==2)
	{
		printf("Bienvenido turno %i \n", turn);
		printf("Indique el producto a vender: \n1) Papa \n2) Cebolla \n");
		scanf("%i", &prod);
		printf("Indique la cantidad: ");
		scanf("%i", &cant);
		cantVent[prod + 1] = cantVent[prod + 1] + cant;
	}
		
}

void cerrarDia(int *cantidadVendidas)
{
	cantidadVendidas[4] = cantidadVendidas[0] + cantidadVendidas[1] + cantidadVendidas[2] + cantidadVendidas[3];
	int porcent1 = 0, porcent2 = 0;
	porcent1 = ((cantidadVendidas[0] + cantidadVendidas[2]) / cantidadVendidas[4]) * 100;
	porcent2 = ((cantidadVendidas[1] + cantidadVendidas[3]) / cantidadVendidas[4]) * 100;
	system("cls");
	printf("Cantidad vendida del producto 1: \nTurno 1: %i unidades\nTurno 2: %i unidades", cantidadVendidas[0], cantidadVendidas[2]);
	printf("\nCantidad vendida del producto 2: \nTurno 1: %i unidades\nTurno 2: %i unidades", cantidadVendidas[1], cantidadVendidas[3]);
	printf("\nCantidad vendida Total: %i unidades", cantidadVendidas[4]);
	printf("\nPorcentaje de ventas del producto 1: %i", porcent1);
	printf("\nPorcentaje de ventas del producto 2: %i", porcent2);

}