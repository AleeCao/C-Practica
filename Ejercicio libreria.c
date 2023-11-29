#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Libros
{
    char nombre[20];
    int codigo; 
    char autor[20];
    char editorial[20];
    float precio;
    int stock;
}Libro;


typedef struct nodo
{
    //Variable que contiene la informacion
    Libro datos;
    //variable que apunta al siguiente nodo
    struct nodo *sig;
}nodo;

//variable global que apunta al primer nodo de la lista
nodo *raiz = NULL;

//Procedimiento para agregar un nuevo nodo
void insertar(Libro lib);
//Procedimiento para mostrar la informacion de un nodo
void listarLibro();
//Procedimiento para mostrar la informacion de un nodo especifico
void listarLibroSinStock();
//Procedimiento para actualizar la informacion de libro
void actualizarLibro();
//Procedimiento para cargar la informacion de libro
void cargarLibro(Libro *info);
//Procedimiento para liberar todos los nodos de la lista
void liberar();
void limpiarBarra();

int main()
{
    int rta=1;
    //Variable del dato
    Libro lib;
    while(rta != 0){
        system("cls");
        printf("MENU PRINCIPAL\n");
		printf("---------------------\n");
		printf("1) Ingresar Libro\n");
		printf("2) Cargar Libro\n");
		printf("3) Listar Libros\n");
        printf("4) Listar Libros sin stock\n");
        printf("5) Actualizar Libro\n");
		printf("0) Salir\n");
		printf("Ingrese una opcion: ");
		scanf("%d", &rta);
		switch(rta)
        {
            case 0:
                void liberar();
                rta = 0;
                break;

			case 1:
                //llama al procedimiento que carga los datos del libro
                cargarLibro(&lib);
                break;

            case 2:
                //Inserta el libro en la lista
                insertar(lib);
                break;

            case 3:
                //Muestra todos los libros de la lista
                listarLibro();
                break;

            case 4:
                //Muestra los libros sin stock de la lista
                listarLibroSinStock();
                break;

            case 5:
                //Actualiza un libro de la lista
                actualizarLibro();
                break;
        }
    }
    return 0;  
}


void limpiarBarra()
{
    while (getchar() != '\n');
}

void insertar(Libro info)
{
    //Declaro un nuevo nodo
    nodo *nuevo;
    nuevo = malloc(sizeof(nodo));
    nuevo->datos = info;
    if (raiz == NULL)
    {
        raiz = nuevo;
        nuevo->sig = NULL;
    }
    else
    {
        nuevo->sig = raiz;
        raiz = nuevo;
    }

}

void listarLibro()
{
    system("cls");
    nodo *reco = raiz;
    printf("Lista completa:\n");
    while (reco != NULL)
    {
        printf("-------------------\n");
        printf("Nombre: %s\n", reco->datos.nombre);
	    printf("Codigo: %d\n", reco->datos.codigo);
	    printf("Autor: %s\n", reco->datos.autor);
        printf("Editorial: %s\n", reco->datos.editorial);
        printf("Precio: %2.f\n", reco->datos.precio);
        printf("Stock: %d\n", reco->datos.stock);
	    printf("-------------------\n");
        reco=reco->sig;
    }
    free(reco);
    limpiarBarra();
	_getch();
}

void listarLibroSinStock()
{
    system("cls");
    nodo *reco = raiz;
    printf("Lista completa:\n");
    while (reco != NULL)
    {
        if (reco->datos.stock == 0)
        {
            printf("-------------------\n");
            printf("Nombre: %s\n", reco->datos.nombre);
            printf("Codigo: %d\n", reco->datos.codigo);
            printf("Autor: %s\n", reco->datos.autor);
            printf("Editorial: %s\n", reco->datos.editorial);
            printf("Precio: %2.f\n", reco->datos.precio);
            printf("Stock: %d\n", reco->datos.stock);
            printf("-------------------\n");
        }
        reco=reco->sig;
    }
    free(reco);
    limpiarBarra();
	_getch();
}

void cargarLibro(Libro *info)
{
    system("cls");
	printf("Ingrese nombre: ");
	scanf(" %[^\n]", info->nombre); //String, sin ampersand
    limpiarBarra();
	printf("Ingrese Codigo: ");
	scanf("%d", &info->codigo); 
	printf("Ingrese autor: ");
	scanf(" %[^\n]", info->autor);
    limpiarBarra();
    printf("Ingrese editorial: ");
	scanf(" %[^\n]", info->editorial);
    limpiarBarra();
    printf("Ingrese precio: $");
	scanf("%f", &info->precio);
    printf("Ingrese stock: ");
	scanf("%d", &info->stock);
}

void actualizarLibro()
{
    int cod = 0;
    Libro lib2;
    nodo *reco = raiz;
    system("cls");
	printf("Ingrese el codigo del libro: ");
    scanf("%d", &cod);
    while (reco !=NULL)
    {
        if (reco->datos.codigo == cod)
        {
            cargarLibro(&lib2);
            reco->datos = lib2;
        }
        reco = reco->sig;
    }
    
}

void liberar()
{
    nodo *reco = raiz; // Puntero para recorrer la lista
    nodo *bor; // Puntero para eliminar los nodos
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        free(bor);
    }
    raiz = NULL;
}