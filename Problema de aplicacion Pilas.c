#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


 
typedef struct controlBalanceado
{
    char caracter;
    struct controlBalanceado *sig;
}ctrl;

ctrl *p_incial = NULL;

//Funcion que analiza la ecuacion
void cargar (char *ecuacion);
int analizar ();

int main()
{
    //variable que aloja la formula
    char formula[20];
    int resultado = 0;
    printf("Ingrese la formula a analizar: ");
    scanf("%s", formula);
    cargar(formula);
    resultado = analizar();
    if (resultado == 1)
    {
        printf("La funcion estaba bien escrita");
    }
    else
    {
        printf("La funcion esta mal escrita idiota");
    }
    return 0;
}

void cargar (char *ecuacion)
{
    //puntero para crear el nodo
    ctrl *p_aux = NULL;
    for (int i = 0; i < 20; i++)
    {
        p_aux = malloc(sizeof(ctrl));
        if (ecuacion[i] == '('|| ecuacion[i] == ')' || ecuacion[i] == '[' || ecuacion[i] == ']' || ecuacion[i] == '{' || ecuacion[i] == '}')
        {
            p_aux->caracter = ecuacion[i];
            if (p_incial == NULL)
            {
                p_incial = p_aux;
                p_aux->sig = NULL;
            }
            else
            {
                p_aux->sig = p_incial;
                p_incial = p_aux;
            }
        }
    }
}

int analizar ()
{
    //TO DO
    
    ctrl *p_aux = p_incial;
    p_aux = p_aux->sig;
    while (p_aux != NULL)
    {
        if (p_aux->caracter == p_incial->caracter)
        {
            p_aux = p_aux->sig;
            p_incial = p_aux;
            p_aux = p_incial->sig;
        }
        else
        {
            break;
        }
    }
    if (p_aux == NULL)
    {
        return 1;
    }
    else
    {
        return -1;
    }
    
}

