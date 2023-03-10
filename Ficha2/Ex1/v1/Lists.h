#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node
{
    int val;
    struct node *next;
} node_t;

void printList(node_t *head);

node_t *createNode(int value);

void addFirst(node_t **head, int value);

void addLast(node_t **head, int value);

//returning the size of the list
int getCurrSize(node_t *head);

//rules:
/*
1->If head is not NULL and position is not 0. Then exit it.
2->if head is null and position is 0. Then we are gonna insert new node to the head and exit it
3->If head is not null and pos. is 0. Then set head ref. to the new node. Finally set new node to head and exit it
4->if not, iterate until finding the nth position and end it. 
*/
void add_by_index(node_t **head, int value, int n);

//adding by index using the recursive method (no loop can be used)
node_t *add_by_index_recursive(node_t *head, int pos, int value);

//add by index pt2  (experimental)
node_t *add_by_index_recursive_pt2(node_t **head, int pos, int value);

//return the average of the integers inside list
float CalcMedia(node_t **head);

//remove by index funtions
int Pop(node_t **head);//

int remove_by_index(node_t **head, int n);
