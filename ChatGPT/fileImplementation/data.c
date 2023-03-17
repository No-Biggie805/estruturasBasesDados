#include <stdio.h>
#include <stdlib.h>
#include "data.h"

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
            count++; // counts the index of person, just to keep track inside the list
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

void saveToFile(Node *head, const char *filename)
{
    FILE *fp = fopen(filename, "w"); // open file in write mode
    if (fp == NULL)
    {
        printf("Error opening file %s for writing.\n", filename);
        return;
    }

    Node *current = head;
    while (current != NULL)
    {
        fprintf(fp, "%s|%s|%d\n", current->name, current->address, current->age); // write data to file
        current = current->next;
    }

    fclose(fp); // close file
    printf("Data saved to file %s successfully!\n", filename);
}

void loadFromFile(Node **head, const char *filename)
{
    FILE *fp = fopen(filename, "r"); // open file in read mode
    if (fp == NULL)
    {
        printf("Error opening file %s for reading.\n", filename);
        return;
    }

    char name[50];
    char address[100];
    int age;

    Node *newNode = (Node *)malloc(sizeof(Node));

    while (fscanf(fp, "%[^|]|%[^|]|%d\n", name, address, &age) != EOF) // scaning while list has not ended
    {
        // Node *temp = NULL;

        if (newNode == NULL)
        {
            printf("Error allocating data to new node.\n");
            break;
        }
        // Adding data:
        // should parse data corretly still..

        strcpy(newNode->name, name);
        strcpy(newNode->address, address);
        newNode->age = age;

        newNode->next = *head;
        *head = newNode;

        // Adding to linked list as a funtion,(experimental)
        //  temp = insertNew(temp);//Does not work if its void lel
    }
    fclose(fp); // close file
    printf("Data loaded from file %s successfully!\n", filename);
}