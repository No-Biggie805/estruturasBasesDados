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

#include "DBheader.h"

// void generateNewList()
// {
//     head = NULL;
// }

/**
 * @brief Checks if "gestor" exists.
 *
 * @param head
 * @param codename
 * @return int
 */
int existAdmin(AdminUser_t *head, int codename)
{
    while (head != NULL)
    {
        if (head->codename == codename)
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
 * @param name
 * @param password
 * @param codename
 * @return AdminUser_t* //returning as newNode pointing to linked list
 */
AdminUser_t *EnterUser(AdminUser_t **head, char name[], char password[], int codename) // adicionar codename
{
    // setting up dynamic allocation
    AdminUser_t *newNode = (AdminUser_t *)malloc(sizeof(AdminUser_t));

    if (!existAdmin(*head, codename))
    {
        strcpy(newNode->name, name); // alloc the data dinamically here..
        strcpy(newNode->password, password);
        newNode->codename = codename;

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

/**
 * @brief procedure to do confirm the user login
 *
 * @param head
 * @param name
 * @param codename
 */
void ConfirmLogIN(AdminUser_t *head, char name[], int codename)
{
    // dinamic allocation:experimental
    // AdminUser_t *temp = (AdminUser_t *)malloc(sizeof(AdminUser_t)); // setting up the allocation member pointer which will contain the data of the struct

    AdminUser_t *temp = head;

    if (strcmp(temp->name, name) == 0) // checking our respectfull user
    {
        if (temp->codename == codename) // checking our respectfull password
        {                               // trocar talvez para codename
            printf("\nUser verification: 'experimental'\n");
            printf("\nWelcome dear User:as menber:%s,as local:%s", name, temp->name);
        }
        else
            printf("\nWrong Password");
    }
    else
        printf("\nWrong UserName"); // prints if the local user is not equal to the one we should have from linked list
}

/**
 * @brief procedure will print the linked list data.
 *
 * @param head
 */
void printList(AdminUser_t *head) // Nao precisa mexer
{

    // AdminUser_t *temporary = head;

    if (head == NULL) // se lista for vazio
    {
        printf("\nNão Achou!!");
        return;
    }
    else
    {
        while (head != NULL) // enquanto não terminar a nossa lista..
        {
            printf("printing name: %s", head->name); // excrever por nome na consola
            printf("\tprinting the codename: %d", head->codename);
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
void serialize(AdminUser_t *head) // no need to create as **head since we are not changing
                                  // data from linked list, and we only need to serialize data to a file
{
    FILE *fp = fopen("list.txt", "w");
    if (fp == NULL)
    {
        printf("error opening file");
        // exit(1);
        return;
    }
    AdminUser_t *temp = head;
    for (temp = head; temp != NULL; temp = temp->next)
    {
        fprintf(fp, "%s|%s|%d\n", temp->name, temp->password, temp->codename); // adicionar codename
    }
    fclose(fp);
}

/**
 * @brief deserialize function will take the data from file, and write to the linked list
 *
 * @param head
 * @return AdminUser_t*
 */
AdminUser_t *deserialize(AdminUser_t **head)
{
    FILE *fp = fopen("list.txt", "r");
    // AdminUser_t *temp = NULL;
    char name[15], password[15];
    int codename;
    // AdminUser_t *newNode = (AdminUser_t *)malloc(sizeof(AdminUser_t));
    if (fp == NULL) // yes, this works
    {
        return NULL; // or return if void ??
    }
    else if (fp != NULL)
    {
        while (fscanf(fp, "%[^|]|%[^|]|%d\n", name, password, &codename) != EOF) // scanning while it has not reached the E.O.F.
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
                *head = EnterUser(&(*head), name, password, codename); // experimental, its werks yay

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

AdminUser_t *deleteUser(AdminUser_t *head, int codename)
{
    AdminUser_t *current = head, *prev = head, *temp;
    if (current == NULL)
    {
        printf("list is empty, insert an user first");
        return NULL;
    }
    else

        if (current->codename == codename) // remove first instance found
    {
        temp = current->next;
        free(current);
        printf("removeu o 1º da lista");
        return temp;
    }
    else
    {
        // Find the instance we want deleted and delete it
        while (current != NULL && current->codename != codename)
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
void ModUser(AdminUser_t **head, int codename, char *name, char *password)
{
    // setting up dynamic memory allocation pointer.
    // AdminUser_t *newNode = (AdminUser_t *)malloc(sizeof(AdminUser_t));
    AdminUser_t *temp = *head;

    if (temp == NULL)
    {
        printf("Lista esta vazia!!\n");
        return;
    }
    else if (temp->codename == codename) // if current find that our modifiable node is head
    {                                    // start modifying head
        strcpy(temp->name, name);        // copy name
        strcpy(temp->password, password);
        temp->codename = codename;

        return;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->codename == codename)
            {
                strcpy(temp->name, name); // copy name
                strcpy(temp->password, password);
                temp->codename = codename;
                // temp = newNode;
                return;
            }
            temp = temp->next;
        }
        // }

        printf("Error: could not find node with codename %d\n", codename);
        // return NULL;
    }
}

/**
 * @brief free the linked list pointer from memory in order to avoid leaks
 *
 * @param head
 */
void FreeMem(AdminUser_t **head)
{
    printf("\nFunção Liberar, a executar..");
    AdminUser_t *newNode = *head;
    AdminUser_t *temp;
    while (newNode != NULL)
    {
        // temp = newNode;
        temp = newNode->next;
        newNode = temp;
        free(newNode);
    }
}