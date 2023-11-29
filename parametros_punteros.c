#include <stdio.h>
#include <stdlib.h>
// PRUEBA DE PUNTEROS Y PARAMETROS

void cargarValorV1(int ** p, int valor);
void cargarValorV2(int * p, int valor);
int * cargarValorV3(int * p, int valor);

int main() {

    //Puntero por Referencia
    int * p1 = NULL;
    cargarValorV1(&p1, 2); //Paso la Dirección de memoria del puntero
    // La siguiente instrucción funciona correctamente porque el puntero apunta a un nuevo valor "int"
    printf("Variable: p1, Direccion de memoria = %p, Valor = %p, Apunta a %d\n", &p1, p1, *p1);

    //Puntero por Valor (copia)
    int * p2 = NULL;
    cargarValorV2(p2, 3); //Paso el valor del puntero "NULL"
    // La siguiente instrucción (si se descomenta) da SEGMENTATION FAULT, porque queremos mostrar valores de un puntero NULL.
    //  printf("Variable: p2, Direccion de memoria = %p, Valor = %p, Apunta a %d\n", &p2, p2, *p2);

    // Sin embargo... en la función anterior, se creó un espacio de memoria con su dirección y se le
    //  asignó el valor!

    // Por lo tanto, para seguir utilizando el parámetro puntero por valor y asignarle una nueva dirección
    //  una opción sería:
    int * p3 = NULL;
    p3 = cargarValorV3(p2, 3); //Paso el valor del puntero "NULL"
    printf("Variable: p3, Direccion de memoria = %p, Valor = %p, Apunta a %d\n", &p3, p3, *p3);
    return 0;
}

void cargarValorV1(int ** p, int valor) {
    *p = malloc(sizeof(int));
    **p = valor;
}

void cargarValorV2(int * p, int valor) {
    p = malloc(sizeof(int));
    *p = valor;
    printf("----------------------------------------------------------\n");
    printf("-------cargarValorV2 - Datos locales de la funcion--------\n");
    printf("    Variable: p2, Direccion de memoria = %p\n", &p);
    printf("    Variable: p2, Valor = %p\n", p);
    printf("    Variable: p2, Valor Apuntado = %d\n", *p);
    printf("----------------------------------------------------------\n");
}

int * cargarValorV3(int * p, int valor) {
    p = malloc(sizeof(int));
    *p = valor;
}