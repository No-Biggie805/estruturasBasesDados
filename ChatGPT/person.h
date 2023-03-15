#ifndef PERSON_H
#define PERSON_H

// define struct for a node in the linked list
typedef struct node
{
    char name[50];
    char address[100];
    int age;
    struct node* next;
} Node;

// function prototypes
void insertNew(Node** head);
void viewData(Node* head);
void Free(Node** head);

#endif
