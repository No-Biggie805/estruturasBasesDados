#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

void insertNew(Node **head)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    printf("Enter name: ");
    scanf("%s", new_node->name);

    printf("Enter address: ");
    scanf("%s", new_node->address);

    printf("Enter age: ");
    scanf("%d", &new_node->age);

    new_node->next = *head;
    *head = new_node;
}

void viewData(Node *head)
{
    Node *current = head;
    int count = 1;

    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        printf("Data in the list:\n");
        while (current != NULL)
        {
            printf("%d. Name: %s, Address: %s, Age: %d\n", count, current->name, current->address, current->age);
            current = current->next;
            count++;
        }
    }
}

void Free(Node **head)
{
    Node *current = *head;
    Node *temp;

    while (current != NULL)
    {
        temp = current->next;
        free(current);
        current = temp;
    }

    *head = NULL;
}
