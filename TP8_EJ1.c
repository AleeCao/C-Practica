#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct numero {
    int numr;
    struct numero *sig;
}num;

num *raiz = NULL;

void insertarNumero (int numer);
void eliminarNoRepetidos();
void repetido(int referencia);
void imprimir();

int main () {
    int numeros = 1;
    printf("Ingrese el numero: ");
    printf("\n\n\"0\" para salir.\n");
    while (numeros != 0)
    {
        scanf("%d", &numeros);
        insertarNumero(numeros);
    }
    imprimir();
    printf("ingrese el numero: ");
    scanf("%d", &numeros);
    repetido(numeros);
    eliminarNoRepetidos();
    system("cls");
    imprimir();
    while (getchar() != '\n'){
    }
    return 0;
}

void insertarNumero(int numer)
{
    num *nodo = raiz;
    nodo = malloc(sizeof(num));
    nodo->numr = numer;
    if (nodo == NULL)
    {
        raiz = nodo;
        nodo->sig = NULL;
    }
    else
    {
        nodo->sig = raiz;
        raiz = nodo;
    }
    
}

void imprimir()
{
    //puntero que toma la misma direccion que raiz
    num *reco = raiz;
    printf("Lista completa:\n");
    while (reco != NULL)
    {
        printf("%d", reco->numr);
        printf("\n");
        //paso el puntero a la direccion del siguiente nodo
        reco=reco->sig;
    }
    //libero reco
    free(reco);
}

void eliminarNoRepetidos()
{
    //puntero que toma la misma direccion que raiz
    num *reco = raiz;
    num *borrador = raiz;
    while (reco != NULL)
    {
        num *reco2 = reco->sig;
        while (reco2 != NULL)
        {
            if (reco2->numr == reco->numr)
            {
                break;
            }
            reco2=reco2->sig;
        }
        if (reco2 == NULL)
        {
            if (reco == raiz)
            {
                borrador->sig = reco->sig;
                borrador = reco;
                reco = reco->sig;
                raiz = reco;
                free(borrador);
            }
            else
            {
                borrador->sig = reco->sig;
                borrador = reco;
                reco = reco->sig;
                free(borrador);
            }
        }
        
        borrador = reco;
        reco=reco->sig;
    }
}

void repetido(int referencia)
{
    int contador = 0;
    num *reco = raiz;
    while (reco != NULL)
    {
        if (reco->numr == referencia)
        {
            contador++;
        }
        reco=reco->sig;
    }
    printf("El numero se repite %d veces.", contador);
    while (getchar() != '\n'){}
}