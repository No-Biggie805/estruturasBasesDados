#include "DBheader.h"

// void generateNewList()
// {
//     head = NULL;
// }

AdminUser_t *EnterUser(AdminUser_t **head, char name[], char password[])
{
    // setting up dynamic allocation
    AdminUser_t *newNode = (AdminUser_t *)malloc(sizeof(AdminUser_t));

    strcpy(newNode->name, name); // alloc the data dinamically here..
    strcpy(newNode->password, password);
    newNode->next = NULL; // consider next as the last of the list

    if (&(*head) == NULL) // inicio sendo declarado nulo fica igual ao valor do
                          // ponteiro no incicio que e nulo
    {
        *head = newNode; // ponteiro e anulado para nao limpar a memoria
    }
    else // esta caso ira fazer com que a posiçao de proximo(prox) retorne a
         // 0. Importante para o apontador nao anular os valores guardados
    {
        newNode->next = *head; // considerar prox, do atual como nulo
        *head = newNode;       // inicio de lista nulo
    }

    return newNode;

    // colocar função criar nova lista se for vazio??(ver codigo do trabalho do 1ºano, no replit)
}
/*
void ConfirmLogIN(AdminUser_t *head, char name[], char password[])
{
    // dinamic allocation:experimental
    // AdminUser_t *temp = (AdminUser_t *)malloc(sizeof(AdminUser_t)); // setting up the allocation member pointer which will contain the data of the struct

    AdminUser_t *temp = head;

    if (strcmp(temp->name, name) == 0) // checking our respectfull user
    {
        if (strcmp(temp->password, password) == 0) // checking our respectfull password
        {
            printf("\nWelcome dear User:%s,%s", name, temp->name);
        }
        else
            printf("\nWrong Password");
    }
    else
        printf("\nWrong UserName");
}
*/

void printList(AdminUser_t *head)
{
    AdminUser_t *temporary = head;
    if (head == NULL) // se lista for vazio
    {
        printf("\nNão Achou!!");
        return;
    }
    else
    {
        while (temporary != NULL) // enquanto não terminar a nossa lista..
        {
            printf("printing name: %s", temporary->name); // excrever por nome na consola
            printf("\n----------x------------\n");
            // getchar();
            temporary = temporary->next; // avança nodo seguinte
        }
    }
}
void FreeMem(AdminUser_t **head)
{
    printf("\nFunção Liberar, a executar..");
    AdminUser_t *newNode = *head;
    AdminUser_t *temp;
    while (newNode != NULL)
    {
        // temp = newNode;
        temp = newNode->next;
        newNode = temp;
        free(newNode);
    }
}