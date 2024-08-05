/*
En un depósito se almacenan productos que están empaquetados en cajas con las 
mismas dimensiones, aunque pueden tener distinto peso (Kg), según el producto 
que contenga.

La empresa YA CUENTA con un catálogo de productos (LISTA) con el siguiente 
formato:
	* id_producto: int	* peso_kg: float

Para poder realizar la distribución, la empresa debe armar palets con una 
geometría de 4 cajas x 4 cajas y 6 niveles de altura (ancho, profundidad y altura). (máximo 96 cajas...)

Con el objetivo de ser eficientes a la hora de armar los palets, la empresa 
necesita un programa que asista al operario durante la tarea de “picking” 
(selección de cajas) y armado de cada palet; indicando al operario caja por 
caja el nivel de ubicación en el palet, de manera tal que aquellas cajas con 
mayor peso queden siempre debajo (para que no se aplasten).

Para ello, el programa deberá (simular el armado de 1 sólo palet):

1. Permitir ingresar en forma aleatoria los Códigos de Producto y sus respectivas 
Cantidades (CJ: cajas) en una lista (Insertar Ordenado por KG), controlando no 
exceder del máximo permitido.
2. Utilizar una PILA, para organizar los productos a incluir en el Palet.
3. Desapilar cada producto, indicando al Operario el Producto a seleccionar y 
agregar al Palet.
4. Realizar un informe para indicar el peso total del palet, de manera recursiva.
*/
#include <stdio.h>
#include <stdlib.h>

// 4x4x6
#define MAX_PRODUCTOS 96

typedef struct nodoCatProd{
    int id_producto;
    float peso_kg;
    struct nodoProducto * psig;
}CatProductos;

typedef struct nodoLista{
    int id_producto;
    struct nodoProducto * psig;
}NodoLista, NodoPila;

// Se encarga de ir agregando productos en nodos a lista
// controlando que no exceda los MAX_PRODUCTOS
// 1. Pedir Código de producto al usuario
// 2. Busdcar el peso en el catálogo (nueva función)
// 3. Según el peso INSERTAR ORDENADO
void cargarListaProductos(NodoLista ** lista, CatProductos * catalogo);

void cargarPila(NodoPila ** pila, NodoLista * lista);

void apilar(NodoPila ** pila, int idProducto);

int desapilar(NodoPila ** pila);

void armarPallet(NodoPila ** pila);

int main(){

    // Asumo que está cargada
    CatProductos * catProductos;
    // Creo la pila
    NodoPila * pila = NULL;
    // Creo lista de productos vacía
    NodoLista * lista = NULL;

    cargarListaProductos(&lista, catProductos);

    cargarPila(&pila, lista);

    // ACA EMPIEZA EL PROCESO DE ARMAR EL PALLET
    armarPallet(&pila);

    float totalKg = informeRecursivo(lista, catProductos);

    printf("KG Total = %0.2f", totalKg);
    
    return 0;
}

float informeRecursivo(NodoLista * lista, CatProductos * catalogo) {
    float peso = 0;
    // CASO BASE
    if (lista == NULL) {
        return 0;
    } else {
        peso = obtenerPeso(lista->id_producto, catalogo);
        return peso + informeRecursivo(lista->psig, catalogo);
    }
}

void armarPallet(NodoPila ** pila) {
    int codProd = 0;
    int contador = 0;
    int nivel = 0;
    while((*pila) != NULL) {
        codProd = desapilar(&pila);
        nivel = (contador -1) / 16;
        nivel ++;
        printf("Ponga una caja de código %d, en el nivel %d", codProd, nivel);
    }
    printf("FIN DE LA CARGA.");
}

void cargarPila(NodoPila ** pila, NodoLista * lista) {
    NodoLista * paux = lista;
    while(paux != NULL) {
        // APILO EL NODO DE LA LISTA
        apilar(&pila, paux->id_producto);
        paux = paux->psig;
    }
}

void apilar(NodoPila ** pila, int idProducto) {
    NodoPila * nuevo = malloc(sizeof(NodoPila));
    nuevo->id_producto = idProducto;
    nuevo->psig = NULL;
    nuevo->psig = (*pila);
    (*pila) = nuevo;
}

int desapilar(NodoPila ** pila) {
    if ((*pila) != NULL) {
        int valor = (*pila)->id_producto;
        NodoPila * aBorrar = (*pila);
        (*pila) = (*pila)->psig;
        free(aBorrar);
        return valor;
    } else {
        return NULL;
    }
}

void cargarListaProductos(NodoLista ** lista, CatProductos * catalogo){
    // 1. Pedir Código de producto al usuario
    // 2. Buscar el peso en el catálogo (nueva función)
    // 3. Según el peso INSERTAR ORDENADO
    int codProd =0;
    NodoLista * p_ant = NULL;
    NodoLista * p_act = NULL;
    float peso = 0;
    float peso_act = 0;
    int contador = 0;
    while (contador < 96)
    {
        printf("Ingrese código de producto (0 PARA FINALIZAR):");
        scanf("%d", &codProd);
        // VALIDO CANT MAX DE PROD EN EL PALLET
        if (codProd == 0) {
            contador = 96;
        } else {
            contador ++;
            NodoLista * nuevo = malloc(sizeof(NodoLista));
            nuevo->id_producto = codProd;
            peso = obtenerPeso(codProd, catalogo);
            // Ahora resuelvo el insertar ordenado
            p_ant = NULL;
            p_act = *lista;
            
            if (p_act == NULL) {
                (*lista) = nuevo;
            } else {
                peso_act = obtenerPeso(p_act->id_producto, catalogo);
                while((peso_act < peso) && (p_act->psig != NULL)) {
                    p_ant = p_act;
                    p_act = p_act->psig;
                    peso_act = obtenerPeso(p_act->id_producto, catalogo);
                }
                p_ant->psig = nuevo;
                nuevo->psig = p_act;
            }
        }
    }
    
    



}