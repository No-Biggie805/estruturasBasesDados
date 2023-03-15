// #include <stdio.h>
#include "meio.h"

int main()
{
    Meio *inicio = NULL; // Lista ligada vazia
    Meio *newNode = NULL;
    int opcao, op = 1;
    int valor, i;
    char tipo[10];
    int bateria;
    float autonomia;
    int num = 3;

voltamenu:
    printf("Menu:\n0_novo\n1_Imprimi\n2_Remover\n3_Sair:\n--->");
    scanf("%d", &opcao);
    system("clear");

    switch (opcao)
    {
    case 0:
        // for (i = 1; i <= num; i++)

        for (;;)
        {
            printf("insira o tipo de meio:");
            scanf("%s", tipo);
            printf("insira o quanto sobra de bateria:");
            scanf("%d", &bateria);
            printf("insira a autonomia do veiculo: ");
            scanf("%f", &autonomia);
    
            newNode = inserirMeio(inicio, i, tipo, bateria, autonomia); // igualar novo nodo a funcao
            newNode->seguinte = inicio;                                 // tornar seguinte como inicio
            inicio = newNode;                                           // tornar inicio da lista como o valor do novo nodo
            
            
            
            /*inicio = inserirMeio(inicio, 1, "bicicleta", 55, 30);
            inicio = inserirMeio(inicio, 2, "bicicleta", 85, 50);
            inicio = inserirMeio(inicio, 3, "trotinete", 85, 50);*/

            printf("Menu Inserir:\n1->Novo Veiculo\t0->sair:");
            scanf("%d", &op);
            i = i + 1;
            if (op == 0)
                break;
        }
        break;
    case 1:

        listarMeios(inicio);

        // if (existeMeio(inicio, 1))
        //     printf("inicio 1 existe\n");
        // else
        //     printf("inicio 1 nao existe\n");

        // if (existeMeio(inicio, 4))
        //     printf("inicio 4 existe\n");
        // else
        //     printf("inicio 4 nao existe\n");
        break;

    case 2:

        inicio = removerMeio(inicio, 1);
        inicio = removerMeio(inicio, 2);
        inicio = removerMeio(inicio, 3);
        break;

    case 3:
        system("clear");
        freeMem(inicio);
        return 0;
        break;
    }

    // listarMeios(inicio);

    goto voltamenu;
    return (0);
}
