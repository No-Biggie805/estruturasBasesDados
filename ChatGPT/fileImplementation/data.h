#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <string.h>
// typedef struct node Node;
typedef struct node
{
    char name[50];
    char address[100];
    int age;
    struct node *next;
} Node;

void insertNew(Node **head);
void viewData(Node *head);
void Free(Node **head);
void saveToFile(Node *head, const char *filename);
void loadFromFile(Node **head, const char *filename);

#endif // HEADER_H_INCLUDED
