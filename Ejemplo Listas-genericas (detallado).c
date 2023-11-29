#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Lista
{
    int info;
    struct Lista *sig;
}nodo;

nodo *raiz = NULL;

//Procedimiento para cargar un nuevo Nodo en la posicion dada como parametro
void insertar(int pos, int info);
int cantidad ();
void imprimir();

int main(){
    insertar(1,10);
    insertar(2,20);
    insertar(3,30);
    insertar(2,15);
    insertar(1,115);
    imprimir();
    _getch();
}

void insertar(int pos, int infor)
{
    if (pos <= cantidad() + 1)
    {
        nodo *nuevo;
        nuevo = malloc(sizeof(nodo));
        nuevo->info = infor;
        if (pos == 1)
        {
            nuevo->sig = raiz;
            raiz = nuevo;
        }
        else 
        {
            if (pos == cantidad() + 1)
            {
                nodo *reco = raiz;
                while (reco->sig != NULL)
                {
                    reco = reco->sig;
                }
                reco->sig = nuevo;
                nuevo->sig = NULL;
            }
            else
            {
                nodo *reco = raiz;
                int i = 0;
                while (i != pos - 1)
                {
                    reco = reco->sig;
                    i++;
                }
                nodo *siguiente = reco->sig;
                reco->sig = nuevo;
                nuevo->sig = siguiente;
            }
        }
    }
    else
    {
        fflush(stdin);
        printf("La posicion esta por fuera de la lista actual.");
        _getch();
    }
}

int cantidad ()
{
    int cant = 0;
    nodo *contador = raiz;
    while (contador != NULL)
    {
        cant++;
        contador = contador->sig;
    }
    return cant;
}

void imprimir()
{
    nodo *reco = raiz;
    printf("Lista completa.\n");
    while (reco!=NULL)
    {
        printf("%d ", reco->info);
        printf("\n");
        printf("-------------");
        printf("\n");
        reco = reco->sig;
    }
    fflush(stdin);
    getchar();
}

