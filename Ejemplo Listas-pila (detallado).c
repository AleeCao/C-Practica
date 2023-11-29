#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct nodo
{
    int info;
    //variable que apunta al siguiente nodo
    struct nodo *sig;
};

//variable global que apunta al primer nodo de la lista
struct nodo *raiz = NULL;

//Procedimiento para agregar un nuevo nodo
void insertar (int x);
//Procedimiento para mostrar la informacion de un nodo
void imprimir();
//Funcion que elimina un nodo y nos devuelve la informacion que contenia
int extraer();
//Procedimiento para liberar todos los nodos de la lista
void liberar();

int main()
{
    int salida = 1, prueba = 0;
    while (salida != 0)
    {
        system("cls");
        printf("Ingrese el numero para ingresar: ");
        scanf("%d", &prueba);
        insertar(prueba);
        insertar(prueba + 2);
        insertar(prueba + 5);
        imprimir();
        printf("Extraemos de la pila: %i\n",extraer());
        imprimir();
        liberar();
        getch();
        salida = prueba;
    }
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
    //si la lista esta vacia el puntero al siguiente nodo queda en NULL
    if (raiz == NULL)
    {
        raiz = nuevo;
        nuevo->sig = NULL;
    }
    //sino asigno la direccion del siguiente nodo
    else
    {
        nuevo->sig = raiz;
        raiz = nuevo;
    }

}

void imprimir()
{
    //Declaro un puntero que toma la misma direccion que raiz
    struct nodo *reco = raiz;
    printf("Lista completa:\n");
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

void liberar()
{
    struct nodo *reco = raiz; // Puntero para recorrer la lista
    struct nodo *bor; // Puntero para eliminar los nodos
    while (reco != NULL)
    {
        //tomo el valor del nodo a liberar
        bor = reco;
        //paso reco a la direccion del siguiente nodo
        reco = reco->sig;
        //libero a bor eliminando el nodo
        free(bor);
    }
    //asigno a raiz el valor de null ya que no quedan nodos
    raiz = NULL;
}