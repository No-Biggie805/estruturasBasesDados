
#include "meios.h"

int existeMeios(meios_t *head, int ID)
{
    meios_t *temp = head;
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

// meios_t *criarGestor(meios_t *head, char nomeCompleto[], char password[], int ID)
// {

//     if (!existeGestor(head, ID))
//     {
//         // create dynamic allocation instance.
//         meios_t *newNode = (meios_t *)malloc(sizeof(meios_t));
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

meios_t *criarMeios(meios_t **head, char tipo[], int ID, int bateria, int autonomia, char registo)
{
    meios_t *newNode = (meios_t *)malloc(sizeof(meios_t));
    if (!existeMeios(*head, ID))
    {
        strcpy(newNode->tipo, tipo);
        newNode->ID = ID;
        newNode->bateria = bateria;
        newNode->autonomia = autonomia;
        newNode->registo = registo;
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

void ListarMeios(meios_t *head)
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
            printf("ID:%d\n", head->ID);
            printf("Tipo:%s\n", head->tipo);
            printf("Bateria:%d\n", head->bateria);
            printf("Autonomia:%d\n", head->autonomia);
            printf("registo:%c\n", head->registo);
            head = head->next;
        }
    }
}

int serialize_Data(meios_t *head)
{
    FILE *fp = fopen("list.txt", "w");
    meios_t *temp = head;
    if (fp == NULL)
    {
        fprintf(stderr, "\nCouldn't open any file");
        return 0;
    }
    // writing nodes of the link list to the file.
    while (temp != NULL)
    {
        fprintf(fp, "%s|%d|%d|%d|%c\n", temp->tipo, temp->ID, temp->bateria, temp->autonomia, temp->registo);
        temp = temp->next;
    }

    fclose(fp);
    return 1;
}

meios_t *deserialize_Data(meios_t **head)
{
    FILE *fp = fopen("list.txt", "r");
    char tipo[15], registo;
    int ID, bateria, autonomia;

    if (fp == NULL)
    {
        printf("error opening the file");
        return NULL;
    }
    else
    {
        while (fscanf(fp, "%[^|]|%d|%d|%d|%c\n", tipo, &ID, &bateria, &autonomia, &registo) != EOF)
        {
            if (head == NULL)
            {
                printf("list is empty");
            }
            else
            {
                // adicionar ID
                *head = criarMeios(&(*head), tipo, ID, bateria, autonomia, registo);
            }
        }
        fclose(fp);
    }
    printf("-->Data loaded from file sucessfully\n");
    return *head;
}

void Remove_meios(meios_t **head, int ID)
{
    meios_t *temp;
    if ((*head)->ID == ID) // warning: comparison between pointer "(&(*head)->ID == ID)" and integer, indeed bad
    {
        temp = *head;          // store current
        *head = (*head)->next; // pass on to the next node
        free(temp);            // release the current
    }
    else
    {
        meios_t *current = *head;

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

void muda_meios(meios_t **head, char tipo[], int ID, int bateria, int autonomia)
{
    int pos = 0;

    if ((*head) == NULL)
    {
        printf("Linked list seems to be empty");
        return;
    }
    meios_t *current = NULL;
    current = *head;
    if (current->ID == ID)
    {
        current->ID = ID;
        strcpy(current->tipo, tipo);
        current->bateria = bateria;
        current->autonomia = autonomia;
        return;
    }
    else
    {
        while (current->next != NULL)
        {
            if (current->ID == ID)
            {
                current->ID = ID;
                strcpy(current->tipo, tipo);
                current->bateria = bateria;
                current->autonomia = autonomia;
                return;
            }
            current = current->next;
            pos++;
        }
    }
    printf("Meio de ID '%d' does not exist in the list\n", ID);
}

meios_t *RegistroAluguerMeio(meios_t *head, int ID)
{
    char registo = 'y';
    meios_t *temp = head;
    if (head == NULL)
    {
        return NULL;
    }
    if (existeMeios(temp, ID))
    {
        printf("a registar..");
        temp->registo = registo;
        printf("resgisto :%c", temp->registo);
    }

    while (temp->next != NULL)
    {
        if (existeMeios(temp, ID))
        {
            printf("a registar..");
            temp->registo = registo;
            printf("resgisto :%c", temp->registo);
        }
        temp = temp->next;
    }
    return head;
}

// Only funtion that works currectly for me??
void FreeMem(meios_t **head)
{
    meios_t *newNode = *head;
    meios_t *temp;
    while (newNode != NULL)
    {
        /* code */
        temp = newNode->next;
        newNode = temp;
        free(temp);
    }
}