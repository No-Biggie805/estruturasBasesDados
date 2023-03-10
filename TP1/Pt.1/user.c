#include "DBheader.h"

// void generateNewList()
// {
//     head = NULL;
// }

AdminUser_t *EnterUser(char name[], char password[])
{
    // setting up dynamic allocation
    AdminUser_t *NewPtr = (AdminUser_t *)malloc(sizeof(AdminUser_t));
    // if (NewPtr == NULL)
    // {
    //     printf("\nerro na alocação!\n");
    //     exit(0);
    // }

    // int tipo_user = 0;
    // printf("Tipo de utilizador[Gestor(1)/Cliente(2)]:");
    // scanf("%d", &tipo_user);

    // if (tipo_user == 1) // 1->inserir gestor
    // {
    while (NewPtr != NULL)
    {

        strcpy(NewPtr->name, name); // alloc the data dinamically here..
        strcpy(NewPtr->password, password);
        NewPtr->next = NULL; // consider next as the last of the list
    }

    // if (head == NULL) // list is still empty
    // {
    //     head = NewPtr; // allocate data to new empty list
    // }
    // else // if head is not null, meaning "the list is not empty"
    // {
    //     NewPtr->next = head; // store next data to become current one
    //     head = NewPtr;       // allocate the data to top of the list
    // }

    // *head = NewPtr;//save as the head position

    // } // adicionar seguinte a adição do cliente, quando criar nova estrutura..

    // else if (tipo_user != 1)//else clause won't clear the data, needs a redo..
    // {
    //     printf("Opção invalida!!");

    //     // delete(NewPtr);//delete all node data
    //     return (NULL);
    // }

    return NewPtr;

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

    while (temporary != NULL) // enquanto não terminar a nossa lista..
    {
        printf("printing name: %s", temporary->name); // excrever por nome na consola
        printf("\n----------x------------\n");
        temporary = temporary->next; // avança nodo seguinte
        getchar();
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