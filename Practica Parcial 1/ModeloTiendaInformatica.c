/*El comercio InformáticaLaPlata tiene un local de venta de insumos informáticos.
Lleva un registro de todos los productos que tiene en stock en un catálogo de 100 elementos distintos 
con la siguiente información: código de producto, stock, precio, cantidad de ventas y tipo de producto.
Todos campos de números enteros.

Los tipos de producto son numéricos de 1 a 5 y tienen los siguientes valores para stock mínimo y máximo:
1) Tipo 1: 50 y 500
2) Tipo 2: 35 y 200
3) Tipo 3: 40 y 400
4) Tipo 4: 75 y 800
5) Tipo 5: 100 y 800

Al comenzar el día pone las ventas en 0 y recibe al proveedor que trae productos para reposición en una lista con la siguiente
información: código de producto y cantidad a reponer.El proveedor siempre trae una lista de 20 elementos a reponer.
Luego de actualizar los valores de stock comienza el día de ventas (siempre tiene stock para vender y cada cliente
lleva 2 productos distintos).En cada venta debe indicar código de cada uno de los dos productos, cantidad de cada uno
y precio total de venta.

Al finalizar el día hace un pedido al proveedor (en una lista con el mismo formato en que el proveedor trae los productos de
reposición) de aquellos productos cuyo stock está por debajo del stock mínimo (la cantidad pedida por producto es stock 
máximo menos stock actual).Puede ocurrir que tenga que pedir reposición de los 100 productos, aunque el proveedor solo 
traiga 20.

Implemente un algoritmo que simule la operatoria completa, modelizando el catálogo con una matriz que indexe por número de 
filas a los códigos de productos (el código es igual al número de fila).
Al final debe indicar cual fue el producto más vendido y la cantidad total recaudada*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<stdbool.h>
#define MAX 100

//Defino matrices globales
int matCatalogo[100][5];
int matTipo[5][3];
int matStockPedido[100][2];

//Defino funciones
void cargarProducto(int *indice);
void venta();
void actualizarPedido();

int main() 
{
	matTipo[0][0] = 1; matTipo[0][1] = 50; matTipo[0][2] = 500; matTipo[1][0] = 2; matTipo[1][1] = 1; matTipo[1][2] = 1; matTipo[2][0] = 1;
	int op = 0, ind = 0;
	bool salida = false;
	while (!salida)
	{
		printf("====MENU====");
		printf("\nSeleccione una opcion:");
		printf("\n1)Cargar producto.");
		printf("\n2)Venta.");
		printf("\n3)Pedido a proveedor");
		printf("\n\n0)Salida.\n");
		scanf("%i", &op);
		switch (op)
		{
		case 0:
			salida = true;
			break;

		case 1:
			cargarProducto(&ind);
			break;

		case 2:
			venta();
			break;

		case 3:
			actualizarPedido();
			break;
		default:
			printf("Selecciono una opcion incorrecta.");
			break;
		}

	}
	return 0;
}

//Implemento funciones
void cargarProducto(int *indice) 
{
	int x = *indice;
	if (x < MAX)
	{
		//información: código de producto, stock, precio, cantidad de ventas y tipo de producto
		matCatalogo[x][0] = x;
		printf("Ingrese el stock del producto: ");
		scanf("%i", &matCatalogo[x][1]);
		printf("Ingrese el precio del producto: ");
		scanf("%i", &matCatalogo[x][2]);
		printf("Ingrese el cantidad de ventas del producto: ");
		scanf("%i", &matCatalogo[x][3]);
		printf("Ingrese el tipo del producto: ");
		scanf("%i", &matCatalogo[x][4]);
		indice++;
	}
	if (x >= MAX)
	{
		printf("Catalogo lleno");
	}
}

void venta() 
{
	//En cada venta debe indicar código de cada uno de los dos productos, cantidad de cada uno y precio total de venta.
	int cod[2] = { 0,0 }, cant[2] = { 0,0 };
	for (int i = 0; i < 2; i++)
	{
		system("cls");
		printf("Ingrese el codigo del %i° producto: ", i + 1);
		scanf("%i", &cod[i]);
		printf("Indique la cantidad: ");
		scanf("%i", &cant[i]);
		if (cant[i]>matCatalogo[cod[i]][1])
		{
			printf("Stock de producto insuficiente.");
			_getch();
			i--;
		}
	}
	printf("===TICKET===");
	printf("\nCodigo\tCantidad\tPrecio");
	printf("\n%i \t%i \t%i ", cod[0], cant[0], cant[0] * matCatalogo[cod[0]][2]);
	printf("\n%i \t%i \t%i ", cod[1], cant[1], cant[1] * matCatalogo[cod[1]][2]);
	for (int i = 0; i < 2; i++)
	{
		matCatalogo[cod[i]][1] = matCatalogo[cod[i]][1] - cant[i];
	}
}

void actualizarPedido() {
	printf("nanana");
}