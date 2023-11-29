/*En una escuela primaria se ha pedido a los alumnos que donen un libro para
armar una biblioteca. Se desea:
a. Incorporar los datos de los libros a una lista, en forma ordenada. La
información correspondiente a cada libro es: título, género, autor, tema,
editorial.
b. Informar la cantidad de fábulas y cuentos infantiles donados.*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct registro
{
    char titulo [20];
    char genero [20];
    char autor [20];
    char tema [20];
    char editorial [20];
}libro;

typedef struct lista
{
    libro data;
    struct lista *sig;
}nodo;

//Declaro procedimientos y funciones
//Cargar los libros
void cargarLibros(libro *info);
void insertarLibro(nodo **origen, libro info);
void listarFyC(nodo **origen);
void limpiarBarra();
void liberar(nodo **origen);

int main(){
    //puntero al nodo mas reciente
    nodo *raiz = NULL;
    //variable donde cargo los datos de los libros
    libro datos;
    int rta = 0;
    while (rta != 4)
    {
        system("cls");
        printf("----MENU----");
        printf("\n1)Cargar libro.");
        printf("\n2)Listar cantidad de fabulas y cuentos.");
        printf("\n3)Borrar datos.");
        printf("\n4)Salir.");
        printf("\n\nSeleccone una opcion: ");
        scanf("%d", &rta);
        switch (rta)
        {
        case 1:
            cargarLibros(&datos);
            insertarLibro(&raiz,datos);
            break;
        case 2:
            listarFyC(&raiz);
            break;

        case 4:
            liberar(&raiz);
            break;
        default:
            break;
        }
    }
    return 0;
}

void limpiarBarra()
{
    while (getchar() != '\n');
}

void cargarLibros(libro *info)
{
    system("cls");
    printf("Ingrese el titulo: ");
    scanf(" %[^\n]", info->titulo);
    printf("Ingrese el genero: ");
    scanf(" %[^\n]", info->genero);
    printf("Ingrese el autor: ");
    scanf(" %[^\n]", info->autor);
    printf("Ingrese el tema: ");
    scanf(" %[^\n]", info->tema);
    printf("Ingrese el editorial: ");
    scanf(" %[^\n]", info->editorial); 
}



void insertarLibro(nodo **origen, libro info)
{
    nodo *nuevo = *origen;
    nuevo = malloc(sizeof(nodo));
    nuevo->data = info;
    if (*origen == NULL)
    {
        *origen = nuevo;
        nuevo->sig = NULL;
    }
    else
    {
        nuevo->sig = *origen;
        *origen = nuevo;
    }
}



void listarFyC(nodo **origen)
{
    limpiarBarra();
    nodo *dinamico = *origen;
    int fabulas = 0, cuentos = 0;
    while (dinamico != NULL)
    {
        if ((strcmp(dinamico->data.genero,"fabula")) == 0)
        {
            fabulas++;
            dinamico = dinamico->sig;
        }
        if ((strcmp(dinamico->data.genero,"cuento")) == 0)
        {
            cuentos++;
            dinamico = dinamico->sig;
        }
        else
        {
            dinamico = dinamico->sig;
        }
    }
    system("cls");
    printf("La cantidad de fabulas es: %d", fabulas);
    printf("\nLa cantidad de cuentos es: %d", cuentos);
    _getch();
}

void liberar(nodo **origen)
{
    nodo *reco = *origen; // Puntero para recorrer la lista
    nodo *bor; // Puntero para eliminar los nodos
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        free(bor);
    }
    *origen = NULL;
}