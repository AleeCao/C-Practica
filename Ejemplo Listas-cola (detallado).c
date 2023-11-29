//ES BASICAMENTE UNA PILA PERO CONSTRUIDA DE ADELANTE PARA ATRAS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct nodo
{
    int info;
    //variable que apunta al siguiente nodo
    struct nodo *sig;
};

//variable global que apunta al nodo al frente de la lista
struct nodo *raiz = NULL;
//variable global que apunta al nodo al final de la lista
struct nodo *fondo = NULL;

//Procedimiento para agregar un nuevo nodo
void insertar (int x);
//Funcion que elimina un nodo y nos devuelve su contenido
int extraer();
//Procedimiento que imprime el contenido de la lista
void imprimir();
//Procedimiento que elimina todos los nodos de la lista y asi libera la memoria
void liberar();

int main()
{
    insertar(5);
    insertar(10);
    insertar(50);
    imprimir();
    printf("Extraemos uno de la cola: %i\n", extraer());
    imprimir();
    liberar();
    getch();
    return 0;
}

void insertar (int x)
{
    //Declaro un nuevo nodo
    struct nodo *nuevo;
    //con esto le asigno la cantiad de memoria necesaria
    nuevo = malloc(sizeof(struct nodo));
    //asigno el valor a info (en este caso el valor que pasamos como parametro)
    nuevo->info = x;
    nuevo->sig = NULL;
    //si la lista estaba vacia los punteros apuntan ahora al primer nodo 
    if (raiz == NULL)
    {
        //como se construye al reves estos apuntan al nodo
        raiz = nuevo;
        fondo = nuevo;
    }
    //sino asigno la direccion del siguiente nodo
    else
    {
        //como se construye al reves ahora el nodo anterior apunta al nodo nuevo
        fondo->sig = nuevo;
        fondo = nuevo;
    }
}

int extraer()
{
    if (raiz != NULL)
    {
        //le asigno la infomacion que contiene el nodo a una variable para devolverla
        int informacion = raiz->info;
        //declaro un nodo que apunta a la direccion del nodo a eliminar
        struct nodo *bor = raiz;
        //paso raiz al siguiente nodo
        raiz = raiz->sig;
        //libero bor, eliminando de esta manera el nodo al que apuntaba
        //si no libero este puntero la direccion queda guardada y no se la puedo asignara un nuevo puntero
        free(bor);
        return informacion;
    }
    else
    {
        return -1;
    }
}

void imprimir()
{
    //Declaro un puntero que toma la misma direccion que raiz
    struct nodo *reco = raiz;
    printf("Lista completa.\n");
    while (reco != NULL)
    {
        printf("%d", reco->info);
        printf("\n");
        //paso el puntero a la direccion del siguiente nodo
        reco=reco->sig;
    }
    //libero reco
    free(reco);
}

void liberar()
{
    struct nodo *bor; // Puntero para eliminar los nodos
    while (raiz != NULL)
    {
        //tomo el valor del nodo a liberar
        bor = raiz;
        //paso raiz a la direccion del siguiente nodo
        raiz = raiz->sig;
        //libero a bor eliminando el nodo
        free(bor);
    }
    //asigno a raiz el valor de null ya que no quedan nodos
    fondo = raiz;
}