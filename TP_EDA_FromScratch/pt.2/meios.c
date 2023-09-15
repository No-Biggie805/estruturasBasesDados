
#include "meios.h"

int existeMeios(meios_t *head, int ID)
{
    // meios_t *temp = head;
    while (head != NULL)
    {
        if (head->ID == ID)
            return 1;
        head = head->next;
    }
    return 0;
}

meios_t *criarMeios(meios_t **head, char tipo[], int ID, float bateria, float autonomia, int RegistoMeio)
{
    meios_t *newNode = (meios_t *)malloc(sizeof(meios_t));
    if (!existeMeios(*head, ID))
    {
        strcpy(newNode->tipo, tipo);
        newNode->ID = ID;
        newNode->bateria = bateria;
        newNode->autonomia = autonomia;
        newNode->RegistoMeio = RegistoMeio;
        newNode->next = NULL; // iMPORTANTE CONSIDERAR NULL AQUI PARA DEPOIS FAZER O NEXT->HEAD
        if (&(*head) == NULL)
            *head = newNode;
        else // o processo seguinte acontecer de criar novo nodo dentro la link list
        {
            newNode->next = *head;
            *head = newNode;
        }
        printf("meio n existe, a retornar novo.\n");
        return newNode;
    }
    else
    {
        printf("meio existe, a retornar o mesmo.\n");
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
            printf("Bateria:%f\n", head->bateria);
            printf("Autonomia:%f\n", head->autonomia);
            printf("Registo do veiculo:%d\n", head->RegistoMeio);
            head = head->next;
        }
    }
}

void serialize_Data(meios_t *head)
{
    FILE *fp = fopen("list.txt", "w");
    meios_t *temp;
    if (fp == NULL)
    {
        fprintf(stderr, "\nCouldn't open any file");
        return;
    }
    if (head == NULL)
        return;
    else
    {

        // writing nodes of the link list to the file.
        for (temp = head; temp != NULL; temp = temp->next)
        {
            fprintf(fp, "%s|%d|%f|%f|%d\n", temp->tipo, temp->ID, temp->bateria, temp->autonomia, temp->RegistoMeio);
        }
    }
    fclose(fp);
}

meios_t *deserialize_Data(meios_t **head)
{
    FILE *fp = fopen("list.txt", "r");
    char tipo[15];
    int ID, RegistoMeio;
    float bateria, autonomia;

    if (fp == NULL)
    {
        printf("error opening the file");
        return NULL;
    }
    else
    {
        while (fscanf(fp, "%[^|]|%d|%f|%f|%d\n", tipo, &ID, &bateria, &autonomia, &RegistoMeio) != EOF)
        {
            if (head == NULL)
            {
                printf("list is empty");
            }
            else
            {
                // adicionar ID
                *head = criarMeios(&(*head), tipo, ID, bateria, autonomia, RegistoMeio);
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

void muda_meios(meios_t **head, char tipo[], int ID, float bateria, float autonomia)
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

void RegistroAluguerMeio(meios_t *head, int ID)
{
    meios_t *temp = head;
    if (head == NULL)
    {
        printf("N achou nenhum meio com o ID, insira novo meio para poder registar");
        return;
    }
    if (existeMeios(temp, ID))
    {
        if (temp->ID == ID)
        {
            temp->RegistoMeio = 1;
            return;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->RegistoMeio = 1;
            printf("meio achado, registo feito");
        }
    }
    else
        printf("inseriu codigo do meio correto?");
}
// // Organizar por ordem[decrescente]
// meios_t *ListaOrdem(meios_t **head)
// {
//     meios_t *current = *head;
//     meios_t *index = NULL;

//     if (head == NULL)
//     {
//         printf("Lista Vazia\n");
//         return;
//     }
//     else
//     {
//         while (current != NULL)
//         {
//             index = current->next;
//             while (current->autonomia < index->autonomia) // while former < latter
//             {
//                 // begin swap process
//                 meios_t *temp = current->next;
//                 current->next = temp->next;
//                 temp->next = current;
//                 if (current == head)
//                 {
//                     head = temp;
//                 }
//                 else
//                 {
//                     meios_t *prev = head;
//                     while (prev->next != current)
//                         prev = prev->next;
//                     prev->next = temp;
//                 }
//             }
//             current = temp;
//         }
//         current = current->next;
//     }
// }

// getting count of linked lists:
int getCount(meios_t **head)
{
    meios_t *temp = *head;
    int count = 0;
    if (head == NULL)
        return 0;
    else
    {
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
    }
    return count;
}

/*Function to swap the nodes */
meios_t *swap(meios_t *ptr1, meios_t *ptr2)
{
    meios_t *tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

/* Function to sort the list */
int bubbleSort(meios_t **head)
{
    meios_t *h;
    int i, j, swapped;
    int count = getCount(head);
    for (i = 0; i <= count; i++)
    {

        h = *head;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++)
        {

            meios_t *p1 = h;
            meios_t *p2 = p1->next;

            if (p1->autonomia < p2->autonomia)
            {

                /* update the link after swapping */
                h = swap(p1, p2); // return ptr2 in place of ptr1
                swapped = 1;
            }

            h = h->next;
        }

        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
    return 0;
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