#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main()
{
    Node *head = NULL;
    int choice;
    char filename[100];

    while (1)
    {
        printf("\n1. Insert New Data\n2. View Data\n3. Save Data to File\n4. Load Data from File\n5. Free Memory and Exit\nEnter your choice: ");
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
            printf("Enter filename to save data: ");
            scanf("%s", filename);
            saveToFile(head, filename);
            break;
        case 4:
            printf("Enter filename to load data: ");
            scanf("%s", filename);
            loadFromFile(&head, filename);
            break;
        case 5:
            Free(&head);
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
