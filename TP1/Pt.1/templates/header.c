#include "header.h"

node_t *createNewNode(node_t *head, int data)
{

    if (!existHead(head, data))
    {
        node_t *newNode = (node_t *)malloc(sizeof(node_t));

        if (newNode != NULL)
        {
            newNode->data = data;
            newNode->next = head;
            return newNode;
        }
    }
    return head;
}

void printList(node_t *head)
{

    while (head != NULL)
    {
        printf("%d-\t", head->data);
        head = head->next;
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
        newNode = temp;
        free(newNode);
    }
}

int existHead(node_t *head, int data)
{
    // node_t *temp = *head;
    while (head != NULL)
    {
        if (head->data == data)
        {
            return (1);
        }
        head = head->next;
    }
    return 0;
}