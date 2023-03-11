#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

node_t *createNewNode(int data);

void printList(node_t *head);

void FreeMem(node_t **head);
