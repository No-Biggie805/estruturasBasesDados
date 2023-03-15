#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

int createNewNode(node_t **head, int data);

void printList(node_t *head);

void FreeMem(node_t **head);

// int existHead(node_t *head, int data);