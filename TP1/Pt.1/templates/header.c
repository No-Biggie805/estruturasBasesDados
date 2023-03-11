#include "header.h"

node_t *createNewNode(int data){

    node_t *newNode = (node_t*)malloc(sizeof(node_t));

    newNode->data = data;
    newNode->next = NULL;
}

void printList(node_t *head){

    while (head != NULL)
    {
        printf("%d-\t",head->data);
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

