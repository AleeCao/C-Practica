/****************************************/
/*      SARASEANDO SIN VARIABLES        */
/****************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct numero {
    int * valor;
}Numero;

typedef struct nodo{
    Numero * numero;
    struct nodo * psig;
}Nodo;

int sumarLista(Nodo * p);
int sumarPunteros(int * p1, int * p2);
int sumarPunterosYEliminarlos(int ** refp1, int ** refp2);

int main(){

    system("clear");
    
    int * p_tengaGanas = malloc(sizeof(int));
    (*p_tengaGanas) = 1;

    Nodo * pinicial = NULL;
    Nodo * p_numero = NULL;
    while((*p_tengaGanas) == 1) {
        p_numero = malloc(sizeof(Nodo));
        p_numero->numero = malloc(sizeof(Numero));
        p_numero->numero->valor = malloc(sizeof(int));

        printf("Ingrese el 1er numero:");
        scanf("%d", p_numero->numero->valor);
        system("clear");
        printf("Guarde %d en la direccion de memoria %p\n", *p_numero->numero->valor, p_numero->numero->valor);
        //Inserto al principio.
        p_numero->psig = pinicial;
        pinicial = p_numero;
        printf("Seguis cargando? (0: NO, 1: SI)");
        scanf("%d", p_tengaGanas);
        system("clear");
    }


    printf("Suma de los números es:\n");
    printf("%d\n", sumarLista(pinicial));

    return 0;
}

int sumarLista(Nodo * p) {
    int * acum = malloc(sizeof(int));
    (*acum) = 0;
    while( p!=NULL ){
        (*acum) = (*acum) + (*p->numero->valor); // acum += p->valor; 
        p = p->psig;
    }
    return (*acum);
}

int sumarPunteros(int * p1, int * p2) {
    return ((*p1) + (*p2));
}

int sumarPunterosYEliminarlos(int ** refp1, int ** refp2) {
    int * suma = malloc(sizeof(int));
    (*suma) = (*(*refp1)) + (*(*refp2));
    free((*refp1));
    free((*refp2));
    return (*suma);
}