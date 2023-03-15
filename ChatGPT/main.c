#include <stdio.h>
#include <stdlib.h>
#include "person.h"

int main()
{
    Node* head = NULL;
    int choice;

    while (1)
    {
        printf("\nMenu\n");
        printf("1. Insert new data\n");
        printf("2. View data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertNew(&head);
                break;
            case 2:
                viewData(head);
                break;
            case 3:
                Free(&head);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
