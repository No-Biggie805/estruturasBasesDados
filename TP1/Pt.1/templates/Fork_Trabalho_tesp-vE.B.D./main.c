#include "list.h"

int main()
{
    // criaLista(inicio);//poderia ser so "lista *inicio=NULL";
    // voltamenu:

    lista *inicio = NULL, *newNode = NULL;
    int opcao;
    int op = 1;

    while (1)
    {

        // printf("Menu:\n0_novo\n1_Pesquisa por Matricula\n2_Pesquisa por Nome\n3_Remover\n4_Imprimi\n5_Sair:\n");
        printf("Menu: 0-add/1-see/2-out");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:

            // for (;;) // loop infinito ate condicao de parada 'break'
            // {
            cadastro(&inicio); // Modo de procedimento, nao funcional.
            /*
            if (inicio == NULL) // inicio sendo declarado nulo fica igual ao valor do
                              // ponteiro no incicio que e nulo
            {
                inicio = newNode; // ponteiro e anulado para nao limpar a memoria
            }
            else // esta caso ira fazer com que a posiçao de proximo(prox) retorne a
                 // 0. Importante para o apontador nao anular os valores guardados
            {
                newNode->prox = inicio; // considerar prox, do atual como nulo
                inicio = newNode;       // inicio de lista nulo
            }

            */

            // void EnterNewUser(lista *head, char )

            //     printf("Menu cadastro:\n1_Novo\t0_Sair:");
            //     scanf("%d", &op);
            //     if (op == 0) // caso 0 sair do loop
            //     {
            //         break;
            //     }
            // }
            printf(">>Dados cadastrados<<\n");

            break;

            // case 1:
            //     imprimePonterio(pesquisamatricula(inicio)); /// pesquisa a matricula e retorna para funcao
            //                                                 /// o ponterio para imprimir

            //     break;

            // case 2:
            //     imprimePonterio(pesquisanome(inicio));
            //     break;

            // case 3:
            //     imprime(inicio);                                          // EXECUÇAO OK
            //     removedado(inicio, pesquisamatricula(inicio)->matricula); // PROBLEMA A VOLTAR PARA O MENU
            //     printf("Removido... imprimindo lista \n");
            //     imprime(inicio);
            //     break;

        case 1:
            system("clear");
            imprime(inicio);
            break;

        case 2:
            libera(&inicio); // fechar o programa prevenindo leaks
            return 0;
            break;


        default:
        system("clear");
        printf("Error:Invalid option\n");
        }
    }

    // goto voltamenu;
    return 0;
}