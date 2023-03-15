#include "list.h"

int main()
{
    criaLista();
voltamenu:
    printf("Menu:\n0_novo\n1_Pesquisa por Matricula\n2_Pesquisa por "
           "Nome\n3_Remover\n4_Imprimi\n5_Sair:\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 0:

        for (;;) // loop infinito ate condicao de parada 'break'
        {
            cadastro();
            // void EnterNewUser(lista *head, char )

            printf("Menu cadastro:\n1_Novo\t0_Sair:");
            scanf("%d", &op);
            if (op == 0) // caso 0 sair do loop
            {
                break;
            }
        }
        printf(">>Dados cadastrados<<\n");

        break;

    // case 1:
    //     imprimePonterio(pesquisamatricula()); /// pesquisa a matricula e retorna para funcao
    //                               /// o ponterio para imprimir

    //     break;

    // case 2:
    //     imprimeponterio(pesquisanome());
    //     break;

    // case 3:
    //     imprime(); // EXECUÇAO OK
    //     removedado(pesquisamatricula()->matricula); // PROBLEMA A VOLTAR PARA O MENU
    //     printf("Removido... imprimindo lista \n");
    //     imprime();
    //     break;

    case 4:
        imprime();
        break;

    case 5:
        libera(&inicio); // fechar o programa prevenindo leaks
        return 0;
        break;
    }

    goto voltamenu;
    return 0;
}