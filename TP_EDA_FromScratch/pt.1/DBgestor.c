
#include "DBgestor.h"

int existeGestor(gestor_t *head, int ID)
{
    gestor_t *temp = head;
    while (head != NULL)
    {
        if (temp->ID == ID)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// gestor_t *criarGestor(gestor_t *head, char nomeCompleto[], char password[], int ID)
// {

//     if (!existeGestor(head, ID))
//     {
//         // create dynamic allocation instance.
//         gestor_t *newNode = (gestor_t *)malloc(sizeof(gestor_t));
//         if (newNode != NULL)
//         {
//             strcpy(newNode->nomeCompleto, nomeCompleto);
//             strcpy(newNode->password, password);
//             newNode->ID = ID;
//             newNode->next = head;
//             return (newNode);
//         }
//     }
//     else
//         return (head);
// }

gestor_t *criarGestor(gestor_t **head, char nomeCompleto[], char password[], int ID)
{
    gestor_t *newNode = (gestor_t *)malloc(sizeof(gestor_t));
    if (!existeGestor(*head, ID))
    {
        strcpy(newNode->nomeCompleto, nomeCompleto);
        strcpy(newNode->password, password);
        newNode->ID = ID;
        newNode->next = NULL; // iMPORTANTE CONSIDERAR NULL AQUI PARA DEPOIS FAZER O NEXT->HEAD
        if (&(*head) == NULL)
            *head = newNode;
        else // o processo seguinte acontecer de criar novo nodo dentro la link list
        {
            newNode->next = *head;
            *head = newNode;
        }
        printf("gestor n existe, a retornar novo.\n");
        return newNode;
    }
    else
    {
        printf("gestor existe, a retornar o mesmo.\n");
        return *head;
    }
}

void printList(gestor_t *head)
{

    // If we use the head pointer instead of the temp while printing the link list, we will miss track of the starting node,
    // having a print of null instead of the first node.

    // to avoid that we create temp and use it to process the link list data

    if (head == NULL)
    {
        printf("\nNao achou!!");
        return;
    }
    else
    {
        while (head != NULL)
        {
            /* code */
            printf("Nome:%s\n", head->nomeCompleto);
            printf("ID:%d\n", head->ID);
            head = head->next;
        }
    }
}

int serialize_Data(gestor_t *head)
{
    FILE *fp = fopen("list.txt", "w");
    gestor_t *temp = head;
    if (fp == NULL)
    {
        fprintf(stderr, "\nCouldn't open any file");
        return 0;
    }
    // writing nodes of the link list to the file.
    while (temp != NULL)
    {
        fprintf(fp, "%s|%s|%d\n", temp->nomeCompleto, temp->password, temp->ID);
        temp = temp->next;
    }

    fclose(fp);
    return 1;
}

gestor_t *deserialize_Data(gestor_t **head)
{
    FILE *fp = fopen("list.txt", "r");
    char nomeCompleto[15], password[15];
    int ID;

    if (fp == NULL)
    {
        printf("error opening the file");
        return NULL;
    }
    else
    {
        while (fscanf(fp, "%[^|]|%[^|]|%d\n", nomeCompleto, password, &ID) != EOF)
        {
            if (head == NULL)
            {
                printf("list is empty");
            }
            else
            {
                // adicionar ID
                *head = criarGestor(&(*head), nomeCompleto, password, ID);
            }
        }
        fclose(fp);
    }
    printf("-->Data loaded from file sucessfully\n");
    return *head;
}

void Remove_gestor(gestor_t **head, int ID)
{
    gestor_t *temp;
    if ((*head)->ID == ID)// warning: comparison between pointer and integer, indeed bad
    {
        temp = *head;          // store current
        *head = (*head)->next; // pass on to the next node
        free(temp);            // release the current
    }
    else
    {
        gestor_t *current = *head;

        while (current->next != NULL)
        {
            if (current->next->ID == ID)
            {
                temp = current;
                current->next->ID = current->next->next->ID;
                free(temp);
            }
            else
            {
                current = current->next;
            }
        }
    }
}

// Only funtion that works currectly for me??
void FreeMem(gestor_t **head)
{
    gestor_t *newNode = *head;
    gestor_t *temp;
    while (newNode != NULL)
    {
        /* code */
        temp = newNode->next;
        newNode = temp;
        free(temp);
    }
}