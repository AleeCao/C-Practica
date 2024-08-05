/*Una fabrica industrial desea digitalizar sus ventas, en la cual fabrica y vende bulones. La misma produce 10 tipos de bulones, 
y se tiene de cada uno el codigo, nombre, stock y precio unitario de venta. Al comenzar el dia se hace la carga inicial de 
stock de cada tipo de bulon, para luego realizar las ventas de stock disponible hasta concluir el dia.

Por cada venta imprimir el ticket con: nombre bulon, precio unitario, cantidad vendida, monto total de la venta.
Al finalizar el dia, informar total vendido y total recaudado por tipo de bulon*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<conio.h>

//Defino las funciones:
void cargaProducto(int *cont);
void venta(float *informe);

//Defino la estructura del producto
typedef struct Bulon
{
	int codigo;
	char nombre[20];
	int stock;
	float precio;
}bl;

bl  vecBl[10];

int main() {
	int op = 0;
	int cont = 0;
	bool salida = false;
	float listaFinal[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
	while (!salida)
	{
		system("cls");
		printf("=======MENU=======");
		printf("\n1) Actualizar catalogo.");
		printf("\n2) Venta.");
		printf("\n3) Cerrar dia.");
		printf("\n\n0) Salir.\n\n");
		scanf_s("%d", &op);
		switch (op)
		{
		case 1: 
			cargaProducto(&cont);
			break;
		case 2:
			venta( &listaFinal);
			break;
		case 3:
			system("cls");
			for (int i = 0; i < cont; i++)
			{
				printf("\nEl valor para el bulon %s es: $%.2f", vecBl[i].nombre, listaFinal[i+1]);
			}
			printf("\n\nEl monto total recudado es: $%.2f", listaFinal[0]);
			_getch();
			break;
		case 0:
			salida = true;
			break;
		default:
			printf("\nEligio una opcion incorrecta");
			break;
		}
	}
	
	return 0;
}

//Implemento las funciones
void cargaProducto(int *cont) 
{
	int x = *cont;
	if (x<10)
	{
		system("cls");
		printf("Ingrese el codigo del producto: ");
		scanf("%d", &vecBl[x].codigo);
		printf("Ingrese el nombre del producto: ");
		scanf("%s", vecBl[x].nombre);
		printf("Ingrese el precio del producto: ");
		scanf("%f", &vecBl[x].precio);
		printf("Ingrese el stock del producto: ");
		scanf("%d", &vecBl[x].stock);
		*cont = *cont + 1;
	}
	else
	{
		printf("Lista llena no se permiten mas productos.");
	}
}

void venta(float *informe)
{
	float cod = 0;
	int cant = 0;
	system("cls");
	printf("Ingrese el codigo del producto: ");
	scanf_s("%f", &cod);
	for (int i = 0; i < 10; i++)
	{
		if (vecBl[i].codigo==cod)
		{
			printf("Indique la cantidad: ");
			scanf_s("%d", &cant);
			cod = cant * vecBl[i].precio;
			system("cls");
			printf("======TICKET=====");
			printf("\nProducto: %s", vecBl[i].nombre),
			printf("\nPrecio unitario: $%.2f", vecBl[i].precio);
			printf("\nCantidad vendida: $%d", cant);
			printf("\n\nTOTAL: $%.2f", cod);
			_getch();
			informe[0] = informe[0] + cod;
			informe[i+1] = informe[i+1] + cod;
			break;
		}
		if (i == 9)
		{
			printf("El codigo ingresado no pertenece a un producto");
		}
	}
}