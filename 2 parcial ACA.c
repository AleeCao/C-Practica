/*En el ACA (Automovil Club Argentino) se realizan services a vehículos de clientes. Al comenzar el día se tiene un 
archivo c:\turnos.dat con los turnos de los clientes a ser atendidos, con la siguiente información:
--Patente y Tipo de service (1- Service general, 2- Cambio de aceite, 3- Reparación mecánica).

El ACA cuenta con la siguiente información de cada cliente en un archivo c:\clientes.dat:
--Patente, Marca, Modelo, DNI, Nombre, Apellido.

Al comenzar el día se va atendiendo a los clientes según la cola de turnos. Luego de ser atendido cada cliente, 
se deja registrado un listado final en forma ordenada por DNI con la siguiente información para la facturación:
--Patente, DNI, Nombre, Apellido, Tipo de Service, Importe a pagar

1. Desarrollar toda la operatoria del día
2. Al finalizar el día se desea obtener de la lista final, en forma recursiva, el monto recaudado del día.
3. Generar un archivo c:\final.dat con todos los datos de la lista final
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct turnos {
    char patente [8];
    int tipo_service;
}turno;

typedef struct datosClientes {
    char patente [8];
    int dni;
    char nombre [20];
    char apellido [10];
    int tipoService;
    float importe;
}cliente;

typedef struct nodo {
    turno dato;
    struct nodo *sig;
}turnos;

typedef struct clientes {
    cliente datos;
    struct clientes *sig;
}clientes;

void cargarTurno(turnos **lista, turno dato);
void atenderCliente(clientes **lista, turnos **listaTurnos);
float montoGenerado(clientes **listaClientes);

int main() {
    cliente datoCliente;
    turno datoTurno;
    int op = 0;
    float monto = 0;
    turnos *listaTurnos = NULL;
    clientes *listaClientes = NULL;
    while (op != 4)
    {
        printf("===MENU===\n");
        printf("1. Cargar turno\n");
        printf("2. Atender cliente\n");
        printf("3. Monto recaudado\n");
        printf("4. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                cargarTurno(&listaTurnos, datoTurno);
                break;
            case 2:
                atenderCliente(&listaClientes, &listaTurnos);
                break;
            case 3:
                monto = montoGenerado(&listaClientes);
                printf("El monto total generado es: $%.2f", monto);
                fflush(stdin);
                _getch();
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion incorrecta\n");
                break;
        }
    }

    return 0;
}

void cargarTurno(turnos **lista, turno dato){
    system("cls");
    printf("Ingrese la patente: ");
    scanf("%s", &dato.patente);
    printf("Ingrese el tipo de service: \n");
    printf("1) Service general \n2) Cambio de aceite \n3) Reparación mecánica\n");
    scanf("%d", &dato.tipo_service);
    turnos *nuevo = malloc(sizeof(turnos));
    nuevo->dato = dato;
    if (*lista == NULL)
    {
        nuevo->sig = NULL;
        *lista = nuevo;
    }else{
        turnos *aux = *lista;
        aux->sig = nuevo;
        nuevo->sig = NULL;
    }
}


void atenderCliente(clientes **lista, turnos **listaTurnos){
    turnos *aux = *listaTurnos;
    if (aux == NULL)
    {
        printf("No hay mas clientes en la cola\n");
    }else{
        clientes *nuevo = malloc(sizeof(clientes));
        strcpy(aux->dato.patente, nuevo->datos.patente);
        printf("Ingrese el DNI: ");
        scanf("%d", &nuevo->datos.dni);
        printf("Ingrese el nombre: ");
        scanf("%s", &nuevo->datos.nombre);
        printf("Ingrese el apelido: ");
        scanf("%s", &nuevo->datos.apellido);
        nuevo->datos.tipoService = aux->dato.tipo_service;
        switch (aux->dato.tipo_service)
        {
        case 1:
            nuevo->datos.importe = 60000;
            break;
        case 2:
            nuevo->datos.importe = 20000;
            break;
        case 3:
            nuevo->datos.importe = 40000;
            break;
        default:
            break;
        }
        if (*lista == NULL)
        {
            nuevo->sig = NULL;
            *lista = nuevo;
        }else{
            nuevo->sig = *lista;
            *lista = nuevo;
        }
        *listaTurnos = aux->sig;

        system("cls");
    printf("Datos cargados: \n");
    printf("Nombre: %s\n", nuevo->datos.nombre);
    printf("Apellido: %s\n", nuevo->datos.apellido);
    printf("DNI: %d\n", nuevo->datos.dni);
    printf("Tipo de servicio: %d\n", nuevo->datos.tipoService);
    printf("Importe: $%.2f\n", nuevo->datos.importe);
    fflush(stdin);
    _getch();
    }
    
}


float montoGenerado(clientes **listaClientes){
    clientes *aux = *listaClientes;
    float total = 0;
    if (aux == NULL)
    {
        total = aux->datos.importe;
        return total;
    }else{
        total = aux->datos.importe + montoGenerado(&aux->sig);
        return total;
    }
}


