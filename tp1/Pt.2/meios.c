/**
 * @file user.c
 * @author Jose Santos (a18605@alunos.ipca.pt)
 * @brief this file takes care of the functions and procedures that we are gonna use to make our link list program
 * @version 0.1
 * @date 2023-03-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "DBmeios.h"

/**
 * @brief Checks if "vehicle" exists.
 *
 * @param head
 * @param CodeID
 * @return int
 */
int existAdmin(Meios_t *head, int CodeID)
{
    while (head != NULL)
    {
        if (head->CodeID == CodeID)
            return 1;
        head = head->next;
    }
    return 0;
}

/**
 * @brief This function will create a new instance to a linked list and return new pointer
 *
 * //Parameters used
 * @param head
 * @param type
 * @param CodeID
 * @param batery
 * @param autonomia
 * @return Meios_t* //returning as newNode pointing to linked list
 */
Meios_t *insertMeio(Meios_t **head, char type[], int CodeID, float batery, float autonomia)
{
    // setting up dynamic allocation
    Meios_t *newNode = (Meios_t *)malloc(sizeof(Meios_t));

    if (!existAdmin(*head, CodeID))
    {
        strcpy(newNode->type, type); // alloc the data dinamically here..
        newNode->CodeID = CodeID;
        newNode->batery = batery;
        newNode->autonomia = autonomia;
        newNode->RegistoAlugado = 0; // just a flag value, no need to bother with parametrizing

        newNode->next = NULL; // consider next as the last of the list

        if (&(*head) == NULL) // inicio sendo declarado nulo fica igual ao valor do
                              // ponteiro no incicio que e nulo
        {
            *head = newNode; // ponteiro e anulado para nao limpar a memoria
        }
        else // esta caso ira fazer com que a posiçao de proximo(prox) retorne a
             // 0. Importante para o apontador nao anular os valores guardados
        {
            newNode->next = *head; // considerar prox, do atual como nulo
            *head = newNode;       // inicio de lista nulo
        }
        printf("user nao existe, a retornar novo.\n");
        return newNode;
    }
    else
    {
        printf("user ja existe, a retornar o mesmo.\n");
        return *head;
    }

    // Missing to file implementation.

    // colocar função criar nova lista se for vazio??(ver codigo do trabalho do 1ºano, no replit)
}

// /**
//  * @brief procedure to do confirm the user login
//  *
//  * @param head
//  * @param name
//  * @param codename
//  */
// void ConfirmLogIN(Meios_t *head, char name[], int codename)
// {
//     // dinamic allocation:experimental
//     // Meios_t *temp = (Meios_t *)malloc(sizeof(Meios_t)); // setting up the allocation member pointer which will contain the data of the struct

//     Meios_t *temp = head;

//     if (strcmp(temp->name, name) == 0) // checking our respectfull user
//     {
//         if (temp->codename == codename) // checking our respectfull password
//         {                               // trocar talvez para codename
//             printf("\nUser verification: 'experimental'\n");
//             printf("\nWelcome dear User:as menber:%s,as local:%s", name, temp->name);
//         }
//         else
//             printf("\nWrong Password");
//     }
//     else
//         printf("\nWrong UserName"); // prints if the local user is not equal to the one we should have from linked list
// }

/**
 * @brief procedure will print the linked list data.
 *
 * @param head
 */
void printList(Meios_t *head) // Nao precisa mexer
{

    // Meios_t *temporary = head;

    if (head == NULL) // se lista for vazio
    {
        printf("\nNão Achou!!");
        return;
    }
    else
    {
        while (head != NULL) // enquanto não terminar a nossa lista..
        {
            printf("printing type: %s", head->type); // excrever por nome na consola
            printf("\tprinting the CodeID: %d", head->CodeID);
            printf("\tprinting batery: %.2f", head->batery);
            printf("\tprinting autonomia: %.2f", head->autonomia);
            printf("\n----------x------------\n");
            // getchar();
            head = head->next; // avança nodo seguinte
        }
    }
}

// implementation added thanks to: https://www.youtube.com/watch?v=dAZbGAhWQtw
// insert data from linked list to a file

/**
 * @brief serialize procedure will write linked list data to file
 *
 * @param head
 */
void serialize(Meios_t *head) // no need to create as **head since we are not changing
                                  // data from linked list, and we only need to serialize data to a file
{
    FILE *fp = fopen("list.txt", "w");
    if (fp == NULL)
    {
        printf("error opening file");
        // exit(1);
        return;
    }
    Meios_t *temp = head;
    for (temp = head; temp != NULL; temp = temp->next)
    {
        fprintf(fp, "%s|%d|%f|%f\n", temp->type, temp->CodeID, temp->batery, temp->autonomia); // adicionar codename
    }
    fclose(fp);
}

/**
 * @brief deserialize function will take the data from file, and write to the linked list
 *
 * @param head
 * @return Meios_t*
 */
Meios_t *deserialize(Meios_t **head)
{
    FILE *fp = fopen("list.txt", "r");
    // Meios_t *temp = NULL;
    // char name[15], password[15];
    // int codename;

    char type[50];
    int CodeID;
    float batery, autonomia;

    // Meios_t *newNode = (Meios_t *)malloc(sizeof(Meios_t));
    if (fp == NULL) // yes, this works
    {
        return NULL; // or return if void ??
    }
    else if (fp != NULL)
    {
        while (fscanf(fp, "%[^|]|%d|%f|%f\n", type, &CodeID, &batery, &autonomia) != EOF) // scanning while it has not reached the E.O.F.
        {
            if (head == NULL)
            {
                printf("making empty list are we?");
            }
            else
            {
                // fscanf(fp, "%[^|]|%[^|]|\n", name, password);
                // submiting to linked list inside of head

                // adicionar codename
                *head = insertMeio(&(*head), type, CodeID, batery, autonomia); // experimental, its werks yay

                // strcpy(newNode->name, name);
                // strcpy(newNode->password, password);
                // newNode->next = *head;
                // *head = newNode;}
            }
        }
        fclose(fp);
    }

    printf("-->Data loaded from file sucessfully\n");
    return *head;
}

Meios_t *deleteMeio(Meios_t *head, int CodeID)
{
    Meios_t *current = head, *prev = head, *temp;
    if (current == NULL)
    {
        printf("list is empty, insert an user first");
        return NULL;
    }
    else

        if (current->CodeID == CodeID) // remove first instance found
    {
        temp = current->next;
        free(current);
        printf("removeu o 1º da lista");
        return temp;
    }
    else
    {
        // Find the instance we want deleted and delete it
        while (current != NULL && current->CodeID != CodeID)
        {
            // if (temp->codename == codename)
            // {
            prev = current;
            current = current->next;
            // }
            // *head = &(*head)->next; // continua a percorrer dentro da lista
        }
        // remove the node
        if (current == NULL)
        {
            // temp = *head;
            return head;
        }
        else
        {
            prev->next = current->next;
            free(current);
            return (head);
            printf("removeu o ultimo da lista");
        }
        // reached the end of procedure, no need to add return.
    }
}

/**
 * @brief Modify User data in to the linked list
 *
 * @param head
 * @param codename
 * @param name
 * @param password
 */
void ModMeio(Meios_t **head, char *type, int CodeID, float batery, float autonomia)
{
    // setting up dynamic memory allocation pointer.
    // Meios_t *newNode = (Meios_t *)malloc(sizeof(Meios_t));
    Meios_t *temp = *head;

    if (temp == NULL)
    {
        printf("Lista esta vazia!!\n");
        return;
    }
    else if (temp->CodeID == CodeID) // if current find that our modifiable node is head
    {                                // start modifying head
        strcpy(temp->type, type);    // copy name
        temp->CodeID = CodeID;
        temp->batery = batery;
        temp->autonomia = autonomia;

        return;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->CodeID == CodeID)
            {
                strcpy(temp->type, type); // copy name
                temp->CodeID = CodeID;
                temp->batery = batery;
                temp->autonomia = autonomia;
                return;
            }
            temp = temp->next;
        }

        printf("Error: could not find node with CodeID %d\n", CodeID);
    }
}

void RegistoAluguelMeio(Meios_t *head, int CodeID)
{
    Meios_t *temp = head;
    if (temp == NULL)
    {
        printf("N achou nenhum meio com o ID, insira novo meio para poder registar");
        return;
    }
    else if (temp->CodeID == CodeID)
    {
        temp->RegistoAlugado = 1;
        return;//Lock out the function, do nothing else!!
    }
    else
    {

        while (temp != NULL)
        {
            if (temp->CodeID == CodeID)
            {
                temp->RegistoAlugado = 1; // Setting to true now
                // return 1;// experimental: same thing, but returning true here

                printf("meio achado, registo feito");
            }
            temp = temp->next;
        }
    }
}

void PrintListaMeiosAlugados(Meios_t *head)
{
    printf("printing the list of registered vehicles: ");
    Meios_t *temp = head;

    while (temp != NULL)
    {
        if (temp->RegistoAlugado == 1)
        {
            // printList(temp);
            printf("%s,%d,%.2f,%.2f", temp->type, temp->CodeID, temp->batery, temp->autonomia);
        }
        temp = temp->next;
    }
}

/**
 * @brief free the linked list pointer from memory in order to avoid leaks
 *
 * @param head
 */
void FreeMem(Meios_t **head)
{
    printf("\nFunção Liberar, a executar..");
    Meios_t *newNode = *head;
    Meios_t *temp;
    while (newNode != NULL)
    {
        // temp = newNode;
        temp = newNode->next;
        newNode = temp;
        free(newNode);
    }
}