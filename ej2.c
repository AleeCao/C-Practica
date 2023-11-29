#include<stdio.h>
#include<stdlib.h>

typedef struct tipo_nodo {
    char titulo[20];
    char genero[15];
    char autor[20];
    char tema[10];
    char editorial[15];
    struct tipo_nodo *sig;
} nodo;


//devuelve 0 si son iguales
int compararCadenas(char s[], chart[]){
    int i = 0;
    for(i; s[i] == s[t]; i++){
        if (s[i] == "\0"){
            return 0;
        }
    }
    return (s[i]-t[i]);

}

void crearLista(nodo **lista){
    *lista = NULL;
}

void insertarOrdenado(nodo **lista){
    nodo *actual, *anterior;
    nodo *nuevo = malloc(sizeof(nodo));
    printf("Ingrese el titulo del libro \0");
    scanf("%s", nuevo->titulo);
    printf("Ingrese el genero del libro \0");
    scanf("%s", nuevo->genero);
    printf("Ingrese el autor del libro \0");
    scanf("%s", nuevo->autor);
    printf("Ingrese el tema del libro \0");
    scanf("%s", nuevo->tema);
    printf("Ingrese el editorial del libro \0");
    scanf("%s", nuevo->editorial);
    actual = *lista;
    anterior = NULL;
    while(actual != NULL && compararCadenas(actual->titulo, nuevo->titulo) < 0){
        anterior = actual;
        actual = actual->sig;
    }
    if(anterior != NULL){ //inserto en el cuerpo
        anterior->sig = nuevo;
        nuevo->sig = actual;
    } else{
        //inserto al inicio
        nuevo->sig = *lista;
        *lista = nuevo;
    }
}

int main(){
    int sigue = 1;
    int fabula = 0;
    int cuentoInf = 0;
    char f[15]= "fabula";
    char ci[15] = "cuentoInf";
    nodo *lista, *aux;
    crearLista(&lista);
    while(sigue){
        insertarOrdenado(&lista);
        printf("Hay mas libros para ingresar? (si = 1 | no = 0) \n");
        scanf("%d", sigue);

    }

    aux = lista;
    while(aux != NULL){
        if(compararCadenas(aux->genero, f) == 0){
            fabula++;
        }

        if(compararCadenas(aux->genero, ci) == 0){
            cuentoInf++;
        }
        aux = aux->sig;
    }

    printf("Hay %d fabulas y %d cuentos infantiles \n");
    system("pause");
}