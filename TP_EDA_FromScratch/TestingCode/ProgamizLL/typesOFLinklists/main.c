#include <stdio.h>
#include <stdlib.h>

/*Singly link list implementation*/
// typedef struct node
// {

//     int data;
//     struct node *next;
// } node_t;

// int main()
// {
//     /*Initialize nodes*/
//     node_t *head;
//     node_t *One = NULL;
//     node_t *Two = NULL;
//     node_t *Three = NULL;

//     /*Allocating to memory*/
//     One = (node_t *)malloc(sizeof(node_t));
//     Two = (node_t *)malloc(sizeof(node_t));
//     Three = (node_t *)malloc(sizeof(node_t));

//     /*Assign data Values*/
//     One->data = 1;
//     Two->data = 2;
//     Three->data = 3;

//     /*Connecting the nodes*/
//     One->next = Two;
//     Two->next = Three;
//     Three->next = NULL;

//     /*save the address of the first node to the head of LL*/
//     head = One;

//     printf("%d\n", One->data);
//     printf("%d\n", Two->data);
//     printf("%d\n", Three->data);

//     return 0;

// }

// // ----------------------------x----------------------------------
// /*Doubly linked list implementation*/
// // Adding an aditional by the term of previous pointer to the link list.
// typedef struct node
// {
//     int data;
//     struct node *next;
//     struct node *prev;
// } node_t;

// int main()
// {
//     /*Initializing linked list*/
//     node_t *head;
//     node_t *One = NULL;
//     node_t *Two = NULL;
//     node_t *Three = NULL;

//     One = (node_t *)malloc(sizeof(node_t));
//     Two = (node_t *)malloc(sizeof(node_t));
//     Three = (node_t *)malloc(sizeof(node_t));

//     /*Assign data value*/
//     One->data = 1;
//     Two->data = 2;
//     Three->data = 3;

//     /*connect the nodes*/
//     One->next = Two;
//     One->prev = NULL;

//     Two->next = Three;
//     Two->prev = One;

//     Three->next = NULL;
//     Three->prev = Two;

//     head = One;
//     return 0;
// }

// ----------------------------x----------------------------------
/*Circular linked list implementation*/
// Adding an aditional by the term of previous pointer to the link list.
typedef struct node
{
    int data;
    struct node *next;
} node_t;

int main()
{
    /*Initializing linked list*/
    node_t *head;
    node_t *One = NULL;
    node_t *Two = NULL;
    node_t *Three = NULL;

    One = (node_t *)malloc(sizeof(node_t));
    Two = (node_t *)malloc(sizeof(node_t));
    Three = (node_t *)malloc(sizeof(node_t));

    /*Assign data value*/
    One->data = 1;
    Two->data = 2;
    Three->data = 3;

    /*connect the nodes*/
    One->next = Two;

    Two->next = Three;

    Three->next = head;

    head = One;
    return 0;
}