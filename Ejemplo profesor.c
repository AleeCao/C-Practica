#include <stdio.h>
#include <stdlib.h>

typedef struct Registro {
    char letra;
    struct Registro * caja_sig;
}Reg;

Reg * p_inicial = NULL;
Reg * p_aux = NULL;

char * palabra = "HOLA";

int main() {
    system("clear");
    printf("%p\n", p_inicial);
    // Creo una primera caja
    p_inicial = malloc(sizeof(Reg));
    // Imprimo la dir de memoria de la nueva cajita
    printf("%p\n", p_inicial);

    p_inicial->letra = 'H';
    printf("%c\n",p_inicial->letra);
    p_inicial->caja_sig = malloc(sizeof(Reg));

    // Agrego otra caja mas
    p_aux = p_inicial;

    for (int i = 0; i < 4; i++)
    {
        p_aux->letra = palabra[i];
        p_aux->caja_sig = malloc(sizeof(Reg));
        printf("%c\n",p_aux->letra );
        p_aux = p_aux->caja_sig;
    }
    
    return 0;
}