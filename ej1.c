#include<stdio.h>
#include<stdlib.h>

typedef struct tipo_nodo {
    int valor;
    struct tipo_nodo *sig;
} nodo;

void crearLista(nodo **lista) {
    *lista = NULL;
}

void insertarOrdenado(nodo **lista, int dato){
    nodo *actual, *anterior;

    nodo *nuevo = malloc(sizeof(nodo));
    nuevo->valor = dato;
    actual = *lista;
    anterior = NULL;
    while(actual != NULL && actual->valor < dato){
        anterior = actual;
        actual = actual->sig;
    }

    //inserto en el cuerpo
    if (anterior != NULL){
        anterior->sig = nuevo;
        nuevo->sig = actual;
    } else {
        //inserto al inicio
        nuevo->sig = *lista;
        *lista = nuevo;
    }


}
int contar(nodo *lista, int num){
    int cuenta = 0;
    nodo *aux;
    aux = lista;
    while(aux != NULL){
        if(aux->valor == num){
            cuenta++;
        }
        aux = aux->sig;
    }
    return cuenta;
}



void eliminarNodo(nodo **lista, int dato){
    nodo *actual, *anterior;
    actual = *lista;
    anterior = NULL;
    while(actual != NULL && actual->valor != dato){
        anterior = actual;
        actual = actual->sig;
    }
        //encontre el dato
    if (actual != NULL) {
        if(anterior != NULL){
            anterior->sig = actual->sig;
        } else {
            *lista = actual->sig;
        }
        free(actual);
    } 
}



void imprimirLista(nodo *lista){
    nodo *aux;
    aux = lista;
    while(aux != NULL){
        printf("%d \n", aux->valor);
        aux = aux->sig;
    }
}

int main(){
    int num, veces, numero;
    nodo *lista;
    crearLista(&lista);
    printf("Ingrese un numero. Ingrese 0 para terminar \n");
    scanf("%d", &num);
    while(num != 0){
        insertarOrdenado(&lista, num);
        printf("Ingrese un numero. Ingrese 0 para terminar\n");
        scanf("%d", &num);
    }

    printf("Ingrese un numero para determinar si esta en la lista \n");
    scanf("%d", &numero);
    veces = contar(lista, numero);
    if (veces == 0){
        printf("El numero no esta en la lista \n");
    }

    if (veces == 1){
        eliminarNodo(&lista, numero);
        printf("El numero aparecia una sola vez por lo que fue eliminado \n");

    }

    if (veces > 1){
        printf("El numero aparece %d veces\n", veces);
        imprimirLista(lista);
        printf("\n");
        system("pause");

    return 0;

    }

}