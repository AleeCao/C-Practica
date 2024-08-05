// En una planta industrial se fabrican 100 productos diferentes. Los productos que se fabrican en la planta son
// enviados al depósito central de comercialización, con la siguiente información: nroProducto (1 a 100), stock
// precioCosto. Se cuenta además con una lista de 150 Clientes con la siguiente información: 
// nroCliente (de 1 a 150), nombre, dirección, localidad y teléfono.
// Durante el dia se van realizando pedidos, informando nroCliente, nroPedido y cantidad. Generar una lista con
// pedidos que se pueden cumplir con la cantidad, almacenando la siguiente información:
// nroCliente
// nombre
// Teléfono
// localidad
// nroProducto
// Cantidad pedida
// ImportePedido (precioCosto * cantidad pedida) + 40%

// El Proceso termina cuando se llegan a los 100 pedidos cumplidos

//TEMA 1
//    1. Ingresando una localidad, saber cuantos pedidos se realizaron e importe recaudado de la misma.
//    2. Imprimir de los pedidos de la localidad de 'Jacinto Araoz", el porcentaje de pedidos con importe mayor a $10.000,
//    respecto del total de pedidos de dicha localidad. 

//TEMA 2
//    1. Ingresando una localidad, mostrar el porcentaje del importe recaudado, respecto del total recaudado.
//    2. Imprimir la cantidad y el importe de la localidad de 'Jacinto Araoz', que superen un importe mayor a $10000. 

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//Armo las estrcturas a utilizar
typedef struct productos 
{
	int nroProducto;
	int stock;
	float precioCosto;
}productos;
typedef struct clientes 
{
	int nroCliente;
	char nombre[20];
	char direccion[50];
	char localidad[20];
	int telefono;
}clientes;
typedef struct pedidos {
	int nroCliente;
	char nombre[20];
	int teléfono;
	char localidad[20];
	int nroProducto;
	int cantPedida;
	float importePedido;
}pedidos;

productos vecProductos[101];
clientes vecClientes[151];
pedidos vecPedidos[101];

//Defino funciones
void cargarProducto(int *indProd);
void cargarCliente(int *indCliente);
void cargarPedido(int *indPedido);
void listarPedidos(int indPedido);
void tema1a(int indice);
void tema1b();


int main() 
{
	int op = 0, indicePro = 1, indiceCli = 1, indicePed = 1;
	bool salida = false;
	while (!salida)
	{
		system("cls");
		printf("\tMENU\n");
		printf("\nSelecciones una opcion");
		printf("\n1)Cargar producto.");
		printf("\n2)Cargar cliente.");
		printf("\n3)Cargar pedido.");
		printf("\n4)Mostrar pedidos.");
		printf("\n5)Mostrar tema 1 a.");
		printf("\n6)Mostrar tema 1 b.");
		printf("\n\n0)Salida.\n");
		scanf("%i", &op);
		switch (op)
		{
		case 0:
			salida = true;
			break;
		case 1:
			cargarProducto(&indicePro);
			break;
		case 2:
			cargarCliente(&indiceCli);
			break;
		case 3:
			cargarPedido(&indicePed);
			break;
		case 4:
			listarPedidos(indicePed);
			break;
		case 5:
			tema1a(indicePed);
			break;
		case 6:
			tema1b();
			break;
		default:
			printf("Selecciono una opcion incorrecta");
			break;
		}
	}
	return 0;
}

//Implemento las funciones
void cargarProducto(int *indProd) 
{
	//información: nroProducto (1 a 100), stock y precioCosto
	int x = *indProd;
	if (x<101)
	{
		system("cls");
		vecProductos[x].nroProducto = x;
		printf("Producto N° %i", x);
		printf("\nIngrese el stock del producto: ");
		scanf("%i", &vecProductos[x].stock);
		printf("\nIngrese el precio del producto: $");
		scanf("%f", &vecProductos[x].precioCosto);
		indProd++;
	}
	else
	{
		system("cls");
		printf("Listado lleno");
	}
}



void cargarCliente(int* indCliente) 
{
	int x = *indCliente;
	if (x < 151)
	{
		//Informacion: nroCliente (de 1 a 150), nombre, dirección, localidad y teléfono.
		system("cls");
		vecClientes[x].nroCliente = x; 
		printf("Ingrese el nombre del cliente: ");
		scanf("%s", vecClientes[x].nombre); 
		printf("\nIngrese la direccion del cliente: ");
		scanf("%s", vecClientes[x].direccion);
		printf("\nIngrese la localidad del cliente: ");
		scanf("%s", vecClientes[x].localidad); 
		printf("\nIngrese el telefono del cliente: ");
		scanf("%i", &vecClientes[x].telefono);
		indCliente++;
	}
	else
	{
		system("cls");
		printf("Listado lleno");
	}
}



void cargarPedido(int *indPedido) 
{
	// se realizan pedidos informando: nroCliente, nroProducto y cantidad.
	int x = *indPedido, nroCliente = 0, cant = 0, nroProducto = 0;
	if (x < 101)
	{
		system("cls"),
		printf("Ingrese el numero de cliente: ");
		scanf("%i", &nroCliente);
		printf("\nIngrese el numero de producto: ");
		scanf("%i", &nroProducto);
		printf("\nIngrese la cantidad: ");
		scanf("%i", &cant);
		if (cant > vecProductos[nroProducto].stock) 
		{
			printf("Stock de producto insuficiente para realizar la transaccion.");
			_getch();
		}
		else 
		{
			//asignamos valores
			vecPedidos[x].nroCliente = nroCliente;
			strcpy(vecPedidos[x].nombre, vecClientes[nroCliente].nombre);
			strcpy(vecPedidos[x].localidad, vecClientes[nroCliente].localidad);
			vecPedidos[x].teléfono = vecClientes[nroCliente].telefono;
			vecPedidos[x].nroProducto = nroProducto;
			vecPedidos[x].cantPedida = cant;
			vecPedidos[x].importePedido = (vecProductos[nroCliente].precioCosto * cant);
		}
		indPedido++;
	}
	else 
	{
		printf("No se admiten mas pedidos");
	}
}



void listarPedidos(int indPedido) 
{
	system("cls");
	for (int x = 1; x <= indPedido; x++)
	{
		printf("N°Cliente: %i \nNombre: %s \nTeléfono: %i \nLocalidad: %s \nN°Producto: %i \nCantidad: %i \nImporte: $%.2f", vecPedidos[x].nroCliente, vecPedidos[x].nombre, vecPedidos[x].teléfono, vecPedidos[x].localidad, vecPedidos[x].nroProducto, vecPedidos[x].cantPedida, vecPedidos[x].importePedido);
		
	}
	_getch();
}

void tema1a(int indice) 
{
	//    1. Ingresando una localidad, saber cuantos pedidos se realizaron e importe recaudado de la misma.
	 
	char ciud[20];
	int cant = 0;
	float monto = 0;
	system("cls");
	printf("Ingrese el nombre de la ciudad: ");
	scanf("%s", ciud);
	for (int i = 0; i < indice; i++)
	{
		if (strcmp(ciud,vecPedidos[i].localidad)==0)
		{
			cant++;
			monto = monto + vecPedidos[i].importePedido;
		}
	}
	printf("En la localidad de %s se realizaron %i pedidos sumando asi un monto total de: $%.2f", ciud, cant, monto);
	_getch();
}

void tema1b()
{
	//    2. Imprimir de los pedidos de la localidad de 'Jacinto Araoz", el porcentaje de pedidos con importe mayor a $10.000,
	//    respecto del total de pedidos de dicha localidad.
}