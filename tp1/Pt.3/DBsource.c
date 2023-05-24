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
int existMeio(Meios_t *head, int CodeID)
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

    if (!existMeio(*head, CodeID))
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

// Funcao criar vertice: o vertice neste significa um ponto na rua.
int criarVertice(Grafo_t **head, char V[])
{
    Grafo_t *newNode = (Grafo_t *)malloc(sizeof(Grafo_t));
    if (!existeVertice(*head, V))
    {
        if (newNode != NULL)
        {
            strcpy(newNode->vertice, V);
            newNode->meios = NULL;
            newNode->next = *head;
            *head = newNode;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        printf("Vertice Existe");
        return -1;
    }
}

// funcao verificar se vertice existe, parecido com exiteMeio.
int existeVertice(Grafo_t *head, char V[])
{
    // Grafo_t *temp ;
    while (head != NULL)
    {
        if (strcmp(head->vertice, V) == 0)
        {
            return 1; // vertice exists
        }
        head = head->next;
    }
    return 0; // vertice does not exist
}

// WIP
// int criarEdge(Grafo_t *head, char vOrigem[], char vDestino[], float peso)
// {
//     Adjacentes_t *newNode = (Adjacentes_t *)malloc(sizeof(Adjacentes_t));
//     if (existeVertice(head, vOrigem) && existeVertice(head, vDestino))
//     {
//         while (strcmp(head->vertice, vOrigem) != 0) // enquanto origem for diferente do vertice
//             head = head->next;
//         if (newNode != NULL) // se novo for !=Null
//         {                    // criar novo edge/adjacente
//             strcpy(newNode->vertice, vDestino);
//             newNode->peso = peso;
//             newNode->next = head->adjacents;
//             head->adjacents = newNode;
//             return 1;
//         }
//         else
//             return 0;
//     }
//     else
//         return 0;
// }
// WIP

// Experimental implementation, adding function as procedure:
void criarEdge(Grafo_t **head, char vOrigem[], char vDestino[], float peso)
{
    Adjacentes_t *newNode = (Adjacentes_t *)malloc(sizeof(Adjacentes_t));
    if (existeVertice(*head, vOrigem) && existeVertice(*head, vDestino))
    {
        Grafo_t *temp = *head;
        while (strcmp(temp->vertice, vOrigem) != 0)
            temp = temp->next;
        if (newNode != NULL)
        {
            // Grafo_t *temp = *head;
            strcpy(newNode->vertice, vDestino);
            newNode->peso = peso;
            newNode->next = temp->adjacents;
            temp->adjacents = newNode;
        }
        else
            return;
    }
    else
    {
        printf("vertices ñ existem..");
        return;
    }
}
// Experimental------------------------------------------

// // função listar adjacentes, coordernadas do grafo.
// void listarEdges(Grafo_t *head, char vertice[])
// {
//     Adjacentes_t *aux;
//     if (existeVertice(head, vertice) != 0)
//     {
//         while (strcmp(head->vertice, vertice))
//             head = head->next;
//         aux = head->adjacents;
//         while (aux != NULL)
//         {
//             printf("Adjacente:%s Peso:%.2f\n", aux->vertice, aux->peso);
//             aux = aux->next;
//         }
//     }
// }

void listarEdges(Grafo_t *head, char vertice[])
{
    Adjacentes_t *aux;
    while (head != NULL)
    {
        aux = head->adjacents;
        while (aux != NULL)
        {
            printf("Adjacente:%s Peso:%.2f\n", aux->vertice, aux->peso);
            aux = aux->next;
        }
        return;
    }
    head = head->next;
}
/*
void inserirMeio_GeoCode(Grafo_t *head, char geocodigo[], int CodeID)
{
    while ((head != NULL) && (strcmp(head->vertice, geocodigo)) != 0)
        head = head->next;
    if (head == NULL)
        return;
    // return 0;
    else
    {
        // problema, estamos a mexer na linked list principal, contudo apenas no id do veiculo dentro desta funcao,
        // podemos aplicar alteracao, se nao considerarmos nada relevante dos valores principais contudo.. ns..
        Meios_t *newNode = (Meios_t *)malloc(sizeof(Meios_t));
        newNode->CodeID = CodeID;
        newNode->next = head->meios;
        head->meios = newNode;
        // return 1;
    }
}
*/
void inserirMeio_GeoCode(Grafo_t *head, char geocodigo[], int CodeID)
{
    //  *temp = head;
    while ((head != NULL) && (strcmp(head->vertice, geocodigo)) != 0) // {
        head = head->next;
    if (head == NULL)
        return;
    // return 0;
    else
    {
        // problema, estamos a mexer na linked list principal, contudo apenas no id do veiculo dentro desta funcao,
        // podemos aplicar alteracao, se nao considerarmos nada relevante dos valores principais contudo.. ns..
        Meios_t *newNode = (Meios_t *)malloc(sizeof(Meios_t));
        if (newNode == NULL)
        {
            printf("Error: Failed to allocate memory for Meios_t node.\n");
            return;
        }

        newNode->CodeID = CodeID;
        newNode->next = head->meios;
        head->meios = newNode;

        printf("codigos inseridos: %d\n", newNode->CodeID);
        // return 1;
    }
    // }
}

void listMeios_Geocode(Grafo_t *head, char geocodigo[])
{
    while ((head != NULL) && strcmp(head->vertice, geocodigo) != 0)
        head = head->next;
    if (head != NULL)
    {
        Meios_t *aux = head->meios;
        if (aux == NULL)
            printf("sem meios de transporte\n");
        else
            while (aux != NULL)
            {
                printf("Codigo meio: %d\n", aux->CodeID);
                aux = aux->next;
            }
    }
    else
        printf("geocodigo inesistente");
}


// void listMeios_Geocode(Grafo_t *head, char geocodigo[])
// {
//     Meios_t *aux = head->meios;
//     if (aux == NULL)
//     {
//         printf("sem meios de transporte");
//         return;
//     }
//     else
//         while (head != NULL)
//         {

//             head = head->next;
//         }
// }

// /*
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

// funcao registar por aluguer
void RegistoAluguelMeio(Meios_t *head, int CodeID)
{
    Meios_t *temp = head;
    if ((existMeio(head, CodeID)))
    {

        if (temp == NULL)
        {
            printf("N achou nenhum meio com o ID, insira novo meio para poder registar");
            return;
        }
        else if (temp->CodeID == CodeID)
        {
            temp->RegistoAlugado = 1;
            return; // Lock out the function, do nothing else!!
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
    else
        printf("inseriu codigo do meio correto?");
}

// Escrever os meios alugados na consola
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
            printf("\n");
        }
        temp = temp->next;
    }
}

// Listagem dos meios em ordem decrescente de autonomia
// void PrintOrdemDecrescente(Meios_t *head)
// {
//     Meios_t *current = head, *index = NULL;
//     float tempSortData;
//     if (current == NULL)
//     {
//         printf("Lista encontra-se vazia");
//         return;
//     }
//     else
//     {
//         // for (size_t i < temp->autonomia[i]; i >= 0; i--)
//         // {

//         // }
//         while (current != NULL)
//         {
//             index = current->next;
//             while (index != NULL)
//             {
//                 if (current->autonomia > index->autonomia)
//                 {
//                     // primeiro fazer o update dos dados
//                     tempSortData = current->autonomia;
//                     current->autonomia = index->autonomia;
//                     index->autonomia = tempSortData;

//                     // seguinte será mover dentro da linked list
//                     // strncpy(temp)
//                 }
//             }
//         }
//     }
// }

/**
 * @brief Printar em ordem descrescente na lista
 *
 * @param head, inicio da lista
 * @param swapped, variavel flag que ira confirmar a troca
 * @param lptr, apontador de estado da lista, apenas ira ficar NULL e por fim guardar o valor de current
 * que seria o ultimo no trocado
 * @param current, manter controlo do nodo atual
 * @param temp, nodo temporario/auxiliar para ajudar na troca de nos
 * @return head
 */
Meios_t *PrintOrdemDecrescente(Meios_t *head)
{
    int swapped;
    Meios_t *current = head;
    Meios_t *lptr = NULL;

    if (head == NULL)
        return head; // List is empty
    // return;

    /**
     * @brief begin while loop process
     *
     */
    do
    {
        swapped = 0;
        current = head;

        /**
         * @brief start transversing the linked list
         *
         */
        while (current->next != lptr) // while list is != NULL
        {
            /**
             * @brief begin the swap process
             *
             */
            if (current->autonomia < current->next->autonomia) // autonomia is great than next->value
            {
                /**
                 * @brief exanching node data
                 *
                 */
                Meios_t *temp = current->next; // creates temp pointer and stores current->next, data
                current->next = temp->next;    // stores temp->next to current->next
                temp->next = current;          // now storing current data to temp->next
                //----------------x-----------------
                /**
                 * @brief Construct a new if object, we will use this to update the linked list,
                 *
                 */
                if (current == head)
                    head = temp;
                else
                {
                    Meios_t *prev = head;
                    while (prev->next != current)
                        prev = prev->next;
                    prev->next = temp;
                }
                current = temp;
                swapped = 1;
            }
            current = current->next;
        }
        lptr = current;
    } while (swapped);
    return head;
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