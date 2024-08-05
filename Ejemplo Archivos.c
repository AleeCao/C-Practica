//Crear un archivo binario y almacenar un caracter, un entero y un float.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
    FILE *arch; //puntero a archivo
    arch=fopen("archivo1.dat","wb");
    if (arch==NULL)
        exit(1);

    char letra='A';
    fwrite(&letra, sizeof(char), 1, arch);
    int valor1=12;
    fwrite(&valor1, sizeof(int), 1, arch);
    float valor2=5.25;
    fwrite(&valor2, sizeof(float), 1, arch);

    fclose(arch);

    printf("Se creo un archivo binario que almacena un char, un int y un float.");

    getch();
    return 0;
}


//Para abrir el archivo binario que se creó en el concepto anterior: "archivo1.dat" y leer sus datos.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
    FILE *arch;
    arch=fopen("archivo1.dat","rb");
    if (arch==NULL)
        exit(1);
    char c;
    fread(&c, sizeof(char), 1, arch);
    printf("caracter: %c\n",c);
    int v1;
    fread(&v1, sizeof(int), 1, arch);
    printf("entero: %i\n",v1);
    float v2;
    fread(&v2, sizeof(float), 1, arch);
    printf("float: %0.2f\n",v2);
    fclose(arch);
    getch();
    return 0;
}

