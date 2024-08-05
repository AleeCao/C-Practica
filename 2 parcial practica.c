#include <stdio.h>
#include <stdlib.h>

//estructura de la caja
typedef struct caja
{
    int id_producto;
    float peso_kg;
} t_caja;

//estructura de la pila
typedef struct pila
{
    t_caja *datos;
    struct pila *sig;
} t_pila;



//apila las cajas en una pila
void crearLista(t_pila **nodo, t_caja *dato);
//desapila las cajas y arma el pallet
void armarPallet(t_pila **pila);
//calcula el peso de forma recursiva
float calcularPeso(t_pila *pila);

int main(){
t_pila *pila = NULL;
t_caja dato;
int cajas = 0, op = 0;
while (op != 4)
{
    system("cls");
    printf ("Menu\n");
    printf ("1) Cargar cajas\n");
    printf ("2) Armar pallet\n");
    printf ("3) Calcular peso\n");
    printf ("4) Salir\n");
    printf ("Ingrese una opcion: ");
    scanf ("%d", &op);
    switch (op)
    {
    case 1:
        if (cajas == 96)
        {
            armarPallet(&pila);
            printf("El peso total del pallet es: %.2f", calcularPeso(pila));
            break;
        }
        crearLista(&pila, &dato);
        cajas++;
        break;
    case 2:
        armarPallet(&pila);
        break;
    case 3:
        printf("El peso total del pallet es: %.2f", calcularPeso(pila));
        break;
    default:
        break;
    }
}

return 0;
}



void crearLista(t_pila **nodo, t_caja *dato){
    system("cls");
    t_pila * nodoAux = malloc(sizeof(t_pila));
    printf("Ingrese el id del producto: ");
    scanf("%d", &dato->id_producto);
    printf("Ingrese el peso del producto: ");
    scanf("%f", &dato->peso_kg);
    nodoAux->datos = dato;
    if (*nodo == NULL)
    {
        nodoAux->sig = NULL;
        *nodo = nodoAux;
    }
    else
    {
        nodoAux->sig = *nodo;
        *nodo = nodoAux;
    }
}

void armarPallet(t_pila **nodo){
t_pila *aux = *nodo;
    while (aux != NULL)
    {
        if (aux == *nodo)
        {
            aux = aux->sig;
            (*nodo)->sig = NULL;
        }
        else
        {
            t_pila *aux2 = aux;
            aux2 = aux->sig;
            aux = aux2->sig;
            aux2->sig = *nodo;
            *nodo = aux2;
        }
        aux = aux->sig;
    }
}

float calcularPeso(t_pila *pila){
    float peso = 0;
    if (pila == NULL)
    {
        return 0;
    }
    else
    {
        peso = pila->datos->peso_kg + calcularPeso(pila->sig);
    }
    return peso;
}

/*t_pila *aux = *nodo;
        while (nodo != nodoAux || aux->sig != nodoAux)
        {
            if (nodoAux->datos->peso_kg >= aux->datos->peso_kg)
            {
                nodoAux->sig = *nodo;
                *nodo = nodoAux;
            }
            t_pila *aux2 = aux;
            aux = aux->sig;
            if (aux->datos->peso_kg <= nodoAux->datos->peso_kg)
            {
                nodoAux->sig = aux;
                aux2->sig = nodoAux;
            }
            else if (aux->sig == NULL)
            {
                nodoAux->sig = NULL;
                aux->sig = nodoAux;
            }
        }*/