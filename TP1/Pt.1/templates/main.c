#include "header.h"

int main()
{
    node_t *head = NULL; // creating new empty list
    node_t *newNode = NULL;
    int option = 0;
    int valor;
    int retorna_valor;

    // voltamenu:
    while (1)//While loop is better than pervious implementation to avoid seg fault and other such things.
    {
        printf("selecione a sua opção: [0->inserir_user/1->VerListaPNome/10->sair]");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            system("clear");
            printf("enter a number to your list");
            scanf("%d", &valor);

            retorna_valor = createNewNode(&head, valor); // execute the funtion to add new node.
            printf("o valor returnado sera: %d", retorna_valor);
            /*
            // newNode = createNewNode(head, valor); // Enters new user

            // if ()
            // {
            //
            // }

            // newNode->next = head;
            // head = newNode;
            */

            printf("\n");

            break;
        case 1:
            system("clear");
            printList(head);
            break;

        case 10:
            system("clear");
            printf("\n");
            FreeMem(&head); // funcção liberar apontadores à memoria
            printf("-->saiu do programa\n");
            return 0;
            break;
        }
    }
    // goto voltamenu;
    return 0;
}