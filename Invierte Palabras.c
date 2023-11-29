#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int InvertirPalabra (char *palabra, int tamanio);

int main () {
    int tamanioFrase = 0;
    char palabra[100] = "prueba de como seria un programa que develve la cantidad de palabras.";
    int tamanio;
    tamanio = sizeof(palabra);
    printf("%s\n", palabra);
    tamanioFrase = InvertirPalabra(palabra, tamanio);
    printf ("%d", tamanioFrase);
    return 0;

}

int InvertirPalabra (char *palabra, int tamanio) 
{
    int contador = 0;
    for (int i = 0; i < tamanio; i++)
    {
        if (palabra[i] == ' ')
        {
            contador++;
        }
        if (palabra[i] == '.')
        {
            contador++;
            return contador;
        }
    }
}