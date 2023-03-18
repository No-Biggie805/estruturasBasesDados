#include "header.h"

int createNewNode(node_t **head, int data) //
{

    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    int success = newNode != NULL;

    if (success)
    {
        newNode->data = data;
        newNode->next = *head;
        *head = newNode;
        return success;
    }
    else
        return 0;
}

void printList(node_t *head)
{

    if (head == NULL)
        printf("List is empty");
    else
    {

        while (head != NULL)
        {
            printf("%d-\t", head->data);
            head = head->next;
        }
    }
}

void FreeMem(node_t **head)
{
    printf("\nFunção Liberar, a executar..");
    node_t *newNode = *head;
    node_t *temp;
    while (newNode != NULL)
    {
        // temp = newNode;
        temp = newNode->next;
        free(newNode);
        newNode = temp;
        }
}

// int existHead(node_t *head, int data)
// {
//     // node_t *temp = *head;
//     while (head != NULL)
//     {
//         if (head->data == data)
//         {
//             return (1);
//         }
//         head = head->next;
//     }
//     return 0;
// }