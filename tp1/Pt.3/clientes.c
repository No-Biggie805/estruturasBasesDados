/**
 * @file clientes.c
 * @author Jose Santos (a18605@alunos.ipca.pt)
 * @brief Ficheiro contem funcoes dos clientes para poder gerir os mesmos. Funcionalidade do cliente nao foi possivel ser adiciona.
 * @version 0.1
 * @date 2023-03-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "DB.h"

/**
 * @brief Checks if "gestor" exists.
 *
 * @param head
 * @param ID
 * @return int
 */
int existCliente(Clientes_t *head, int ID)
{
    while (head != NULL)
    {
        if (head->ID == ID)
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
 * @param ID
 * @return AdminUser_t* //returning as newNode pointing to linked list
 */
Clientes_t *EnterCliente(Clientes_t **head, char name[], char password[], int ID) // adicionar ID
{
    // setting up dynamic allocation
    Clientes_t *newNode = (Clientes_t *)malloc(sizeof(Clientes_t));

    if (!existCliente(*head, ID))
    {
        strcpy(newNode->name, name); // alloc the data dinamically here..
        strcpy(newNode->password, password);
        newNode->ID = ID;

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
 * @param ID
 */
void ConfirmLoginCliente(Clientes_t *head, char name[], int ID)
{
    // dinamic allocation:experimental
    // AdminUser_t *temp = (AdminUser_t *)malloc(sizeof(AdminUser_t)); // setting up the allocation member pointer which will contain the data of the struct

    Clientes_t *temp = head;

    if (strcmp(temp->name, name) == 0) // checking our respectfull user
    {
        if (temp->ID == ID) // checking our respectfull password
        {                               // trocar talvez para ID
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
void printList_Clientes(Clientes_t *head) // Nao precisa mexer
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
            printf("\tprinting the ID: %d", head->ID);
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
void serialize_Clientes(Clientes_t *head) // no need to create as **head since we are not changing
                                          // data from linked list, and we only need to serialize data to a file
{
    FILE *fp = fopen("AdminList.txt", "w");
    if (fp == NULL)
    {
        printf("error opening file");
        // exit(1);
        return;
    }
    Clientes_t *temp = head;
    for (temp = head; temp != NULL; temp = temp->next)
    {
        fprintf(fp, "%s|%s|%d\n", temp->name, temp->password, temp->ID); // adicionar ID
    }
    fclose(fp);
}

/**
 * @brief deserialize function will take the data from file, and write to the linked list
 *
 * @param head
 * @return AdminUser_t*
 */
Clientes_t *deserialize_Cliente(Clientes_t **head)
{
    FILE *fp = fopen("AdminList.txt", "r");
    char name[15], password[15];
    int ID;
    if (fp == NULL) // yes, this works
    {
        return NULL; // or return if void ??
    }
    else if (fp != NULL)
    {
        while (fscanf(fp, "%[^|]|%[^|]|%d\n", name, password, &ID) != EOF) // scanning while it has not reached the E.O.F.
        {
            if (head == NULL)
            {
                printf("making empty list are we?");
            }
            else
            {
                *head = EnterCliente(&(*head), name, password, ID); // experimental, its werks yay
            }
        }
        fclose(fp);
    }

    printf("-->Data loaded from file sucessfully\n");
    return *head;
}

Clientes_t *deleteClientes(Clientes_t *head, int ID)
{
    Clientes_t *current = head, *prev = head, *temp;
    if (current == NULL)
    {
        printf("list is empty, insert an user first");
        return NULL;
    }
    else

        if (current->ID == ID) // remove first instance found
    {
        temp = current->next;
        free(current);
        printf("removeu o 1º da lista");
        return temp;
    }
    else
    {
        // Find the instance we want deleted and delete it
        while (current != NULL && current->ID != ID)
        {
            prev = current;
            current = current->next;
        }
        // remove the node
        if (current == NULL)
        {
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
 * @param ID
 * @param name
 * @param password
 */
void ModCliente(Clientes_t **head, int ID, char *name, char *password)
{
    // setting up dynamic memory allocation pointer.
    // AdminUser_t *newNode = (AdminUser_t *)malloc(sizeof(AdminUser_t));
    Clientes_t *temp = *head;

    if (temp == NULL)
    {
        printf("Lista esta vazia!!\n");
        return;
    }
    else if (temp->ID == ID) // if current find that our modifiable node is head
    {                                    // start modifying head
        strcpy(temp->name, name);        // copy name
        strcpy(temp->password, password);
        temp->ID = ID;

        return;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->ID == ID)
            {
                strcpy(temp->name, name); // copy name
                strcpy(temp->password, password);
                temp->ID = ID;
                return;
            }
            temp = temp->next;
        }

        printf("Error: could not find node with ID %d\n", ID);
    }
}

/**
 * @brief free the linked list pointer from memory in order to avoid leaks
 *
 * @param head
 */
void FreeMem_Clientes(Clientes_t **head)
{
    printf("\nFunção Liberar, a executar..");
    Clientes_t *newNode = *head;
    Clientes_t *temp;
    while (newNode != NULL)
    {
        // temp = newNode;
        temp = newNode->next;
        newNode = temp;
        free(newNode);
    }
}