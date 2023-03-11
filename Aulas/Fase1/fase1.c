#include <stdio.h>
#include "meio.h"

int main()
{
    Meio *inicio = NULL; // Lista ligada vazia

    inicio = inserirMeio(inicio, 1, "bicicleta", 55, 30);
    inicio = inserirMeio(inicio, 2, "bicicleta", 85, 50);
    inicio = inserirMeio(inicio, 3, "trotinete", 85, 50);

    listarMeios(inicio);

    if (existeMeio(inicio, 1))
        printf("inicio 1 existe\n");
    else
        printf("inicio 1 nao existe\n");

    if (existeMeio(inicio, 4))
        printf("inicio 4 existe\n");
    else
        printf("inicio 4 nao existe\n");

    inicio = removerMeio(inicio, 1);
    inicio = removerMeio(inicio, 2);
    inicio = removerMeio(inicio, 3);
    listarMeios(inicio);
    freeMem(inicio);

    return (0);
}
