#include <stdio.h>
#include "objetos.h"

int main()
{
    objeto Objetos[TAM];
    int qt = 0; // quantidade de objetos
    float resultado;

    qt = lerTxt(Objetos);

    qt += inserirNovoObjeto(Objetos,1,10,qt);
    qt += inserirNovoObjeto(Objetos,2,12,qt);

    resultado = media(Objetos, qt);
    if (resultado != -1)
        printf("Media %.2f\n", resultado);
    else
        printf("Array não contem nenhum objeto!\n");

    guardarTxt(Objetos, qt);
    return (0);
}
