/*En una ferretería se quiere simular la venta, generando el ticket y actualizando el stock. 
Se cuenta con 50 productos, cada uno con su nombre, stock y precio unitario.
Por cada venta se solicita el nombre y cantidad a vender.
Si el stock no es suficiente se deberá mostrar un mensaje, caso contrario, actualizar stock y generar el ticket de venta 
imprimiendo: nombre, Cantidad Vendida, Precio total.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//Defino funciones
void cargarProducto(int *cantMax);
void venta(int cantMax);

//Defino estructura del producto
typedef struct producto 
{
	char nombre[20];
	int stock;
	float precio;
}prod;

prod vecProducto[50];

int main() {
	int op = 0, cant = 0;
	bool salida = false;
	while (!salida)
	{
		system("cls");
		printf("~~~~MENU~~~~");
		printf("\nSeleccione una opcion:");
		printf("\n1)Cargar producto.");
		printf("\n2)Venta.");
		printf("\n\n0)Salida.\n");
		scanf("%i", &op);
		switch (op)
		{
		case 0:
			salida = true;
			break;
		case 1:
			cargarProducto(&cant);
			break;
		case 2:
			venta(cant);
			break;
		default:
			printf("Selecciono  una opcion incorrecta");
			break;
		}
	}
	return 0;
}

//Implemento las funciones
void cargarProducto(int *cantMax) 
{
	int x = *cantMax;
	system("cls");
	if (x > 50)
	{
		printf("Espacio lleno");
	}
	else
	{
		printf("Ingrese el nombre del producto: ");
		scanf("%s", vecProducto[x].nombre);
		printf("Ingrese el precio del producto: $");
		scanf("%f", &vecProducto[x].precio);
		printf("Ingrese el stock del producto: ");
		scanf("%i", &vecProducto[x].stock);
	}
	cantMax++;
}

void venta(int cantMax) 
{
	char prod[20];
	int ctd = 0;
	system("cls");
	printf("Ingrese el nombre del producto: ");
	scanf("%s", prod);
	for (int i = 0; i <= cantMax; i++)
	{
		if (strcmp(prod, vecProducto[i].nombre) == 0)
		{
			printf("\nIndique la cantidad: ");
			scanf("%i", &ctd);
			if (ctd <= vecProducto[i].stock)
			{
				system("cls");
				printf("~~~~TICKE~~~~\n\n");
				printf("Producto: %s", vecProducto[i].nombre);
				printf("\nCantidad: %i", ctd);
				printf("\n\nTOTAL: $%.2f", vecProducto[i].precio * ctd);
				_getch();
				vecProducto[i].stock = vecProducto[i].stock - ctd;
				break;
			}
			else
			{
				printf("Stock de producto insuficiente.");
				_getch();
			}
		}
		if (i == cantMax)
		{
			printf("Nombre incorrecto");
			_getch();
		}
	}
}