#include "list.h"

// void criaLista(lista **inicio)
// {
//     inicio = NULL; // lista vazia
// }

lista *cadastro(lista **inicio)
{
    // lista *temp = *inicio;
    lista *newNode = (lista *)malloc(sizeof(lista)); // inicializar apontador de alocacao dinamica

    if (newNode == NULL) // caso seja nulo..
    {
        printf("Erro de alocacao\n"); // dá Erro
        // return 0;
        exit(0);
    }

    printf("Digite a matricula:");
    scanf("%d", &newNode->matricula); // declaraçao do ponteiro ao valor matricula
    printf("Digite o nome:");
    scanf(" %[^\n]", newNode->nome);
    printf("Digite o curso:");
    scanf(" %[^\n]", newNode->curso);
    printf("Digite a data de nascimento:");
    scanf(" %[^\n]", newNode->datnasc);

    newNode->prox = NULL; // apos todos os dados inseridos, o apontador vai
                          // para o "menu cadastro"

    if (&(*inicio) == NULL) // inicio sendo declarado nulo fica igual ao valor do
                            // ponteiro no incicio que e nulo
    {
        *inicio = newNode; // ponteiro e anulado para nao limpar a memoria
    }
    else // esta caso ira fazer com que a posiçao de proximo(prox) retorne a
         // 0. Importante para o apontador nao anular os valores guardados
    {
        newNode->prox = *inicio; // considerar prox, do atual como nulo
        *inicio = newNode;       // inicio de lista nulo
    }
    // newNode->prox = *inicio; // poderia assinar  = *inicio, contudo sera mais melhor ser assim,
    //                          // que ira assinar direto ao adereco e nao apontador.
    // *inicio = newNode;

    return newNode;
}

// void imprimePonterio(lista **inicio) /// para imprimir resultado da função busca
// {
//     lista *temp = *inicio;
//     if (temp == NULL) // Caso a função busca restorne null
//     {
//         printf("Não achou!!");
//         return;
//     }
//     while (temp != NULL)
//     {
//         printf("funcao-impressao--ponteiro ---\n\n");
//         printf("Matricula = %d\n", temp->matricula);
//         printf("Nome = %s\n", temp->nome);
//         printf("Curso = %s\n", temp->curso);
//         printf("Data de Nascimento = %s\n", temp->datnasc);
//         temp = temp->prox;

//         getchar(); // pressionar enter por cada nodo da lista
//         getchar(); // pressionar 2º vez e avançar para nodo seguinte até ser
//                    // null
//     }
// }

// // ///-------------------------------------------------pesquisa
// // ///pesquisa por matricula
// lista *pesquisamatricula(lista *inicio)
// {
//     int dado;
//     printf("Digite a matricula:");
//     scanf("%d", &dado);
//     lista *temp;
//     if (inicio == NULL)
//     {
//         return NULL; // Lista Vazia
//     }
//     // Caso a lista nao esteja vazia
//     temp = inicio;
//     while (temp != NULL)
//     {                                                         // inicio da procura
//         printf("procurando %d==%d\n", dado, temp->matricula); // ponteiro ve a referencia e imprime o dado
//                                                               // que foi buscar da variavel matricula dentro
//                                                               // da funçao cadastro, isto apenas significa
//                                                               // que o ponteiro sucecedeu na procura.
//         getchar();                                            // comentar remove o enter
//         if (temp->matricula == dado)                          // depois de encontrado havendo um dado
//                                                               // que bate na referencia.
//         {
//             printf("\nACHOU %d==%d!!!\n", temp->matricula, dado); // o ponteiro vai e imprime esse dado igualando à
//                                                                   // referencia.

//             return (temp); // retorna um ponteiro para função imprimir ponteiro
//         }
//         else // se o ponteiro não achar o dado, avança para comunicar que nao
//              // tem dados e inicia o processo do termino da funçao
//         {
//             temp = temp->prox; // volta ao inicio??? (ponteiro->prox =
//                                // inicio;), avança para o termino da funçao
//         }
//     }
//     return NULL; // quando termina de tentar achar um ponteiro, automaticamente
//                  // volta ao menu
// }

// lista *pesquisanome(lista *inicio)
// {
//     char pesq[50];
//     printf("Digite o nome:");
//     scanf(" %[^\n]", pesq);
//     lista *temp;
//     if (inicio == NULL)
//     {
//         return NULL; // Lista Vazia
//     }
//     // Caso a lista nao esteja vazia
//     temp = inicio;
//     while (temp != NULL)
//     {
//         printf("procurando %s==%s\n", pesq, temp->nome); /// comentar parar para de mostra lixo na tela
//         getchar();                                       /// comentar ai ñ pede enter
//         if (strcmp(temp->nome, pesq) == 0)               // achou !!
//         {
//             printf("\nACHOU %s==%s!!!\n", temp->nome, pesq);
//             return (temp); // retorna um ponteiro para função imprimr
//         }
//         else
//         {
//             temp = temp->prox;
//         }
//     }
//     return NULL;
// }

// int removedado(lista *inicio, int dado) // funçao int para retornar os numeros.
// {
//     lista *ptr, *antes;
//     if (inicio == NULL)
//     {
//         return 0; // Lista vazia !!!
//                   // return NULL;
//     }             // caso seja vazio termina a funçao.

//     else

//     { // Caso a lista nao esteja vazia
//         ptr = inicio;
//         antes = inicio;
//         while (ptr != NULL)
//         {
//             if (ptr->matricula == dado) // achou !!
//             {
//                 if (ptr == inicio) // se esta removendo o primeiro da lista
//                 {
//                     inicio = inicio->prox;
//                     free(ptr); // ptr libera a informação dentro da matricula
//                     return 1;  // removeu !!
//                 }
//                 else // continua procurando
//                 {
//                     antes->prox = ptr->prox; //
//                     free(ptr);               // Libera a area do nodo
//                     return 1;                // removeu !!
//                 }
//             }
//             else // continua procurando no prox. nodo
//             {
//                 antes = ptr;
//                 ptr = ptr->prox;
//             }
//         }
//         return 0; // Nao achou !!!
//     }
// }

void imprime(lista *inicio)
{
    lista *ponteirolista;
    lista *temp = inicio;
    // if (ponteirolista == NULL) // Caso a função busca restorne null
    // {
    //     printf("Não achou!!");
    //     return;
    // }
    // else
    if (inicio == NULL) // Caso a lista esteja vazia
    {
        printf("funcao-impressao>>lista-null--\n\n");
        return;
    }
    else if (inicio != NULL)
    {

        ponteirolista = temp;
        while (ponteirolista != NULL)
        {
            printf("Matricula = %d\n", ponteirolista->matricula);

            printf("Nome = %s\n", ponteirolista->nome);
            printf("Curso = %s\n", ponteirolista->curso);
            printf("Data de Nascimento = %s\n", ponteirolista->datnasc);
            ponteirolista = ponteirolista->prox;
            getchar();
            getchar();
        }
    }

    printf("funcao-impressao>>fim-da-lista ---\n\n");
}

void libera(lista **head)
{
    printf("\nFuncao liberar\n");
    lista *NovoPonteiro = *head;

    while (NovoPonteiro != NULL)
    {
        lista *temp = NovoPonteiro->prox;
        free(NovoPonteiro);
        NovoPonteiro = temp;
    }
}
