#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

node_t *createNewNode(node_t *head, int data);

void printList(node_t *head);

void FreeMem(node_t **head);

int existHead(node_t *head, int data);