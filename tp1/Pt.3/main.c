/*Questões a fazer ao professor sobre o trabalho:
1->Qual  será a estrutura base do programa ao desenvolver sem inclusão dos dados da lista?
e.g:quesão do registo do utilizador
R:serão listas do Cliente, gestor e mobilidade

2->Como irá depois ser feito o funcionamento do antes e depois de implementar as linked lists?
e.g:questões da gestão de dados quais poderão ser numa
estrutura base e os que serão para linked list?

R: em principio serão todos linked lists
*/

/**
 * @file main.c
 * @author Jose Santos(a18605@alunos.ipca.pt)
 * @brief ficheiro main, contem o menu que ira conter as seguintes funcoes
 * @version 0.1
 * @date 2023-03-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "DB.h"

/**
 * @brief main function, contains the following functions
 * @return int
 */

void adminMenu()
{
    printf("\nAdmin Menu:\n");
    printf("1. Manage gestor list\n");
    printf("2. Manage meios list\n");
    printf("3. Exit to main menu\n");
    printf("Enter your choice: ");
}

int InvalidLogin(AdminUser_t *head, char *gestor, int codename)
{
    AdminUser_t *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->name, gestor) == 0 && codename == temp->codename)
        {
            // ConfirmLogIN(head, gestor, codename); // Confirmar qual o utilizdor.
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main()
{
    /*
    Gestor: tera acesso a alterar dados: veiculo, gestor e cliente.
    cliente: Podera em principio so poder mexer nos seus dados e consultar meios..
    */
    AdminUser_t *headAdmins = NULL;
    Clientes_t *headCliente = NULL;
    Meios_t *headMeios = NULL;
    Grafo_t *headGrafo = NULL;

    int tipo = 0;
    int codename;
    char gestor[15]; // TAM = 50, do DB.h

    // // redundante, mas menos confuso..
    // int ID;
    // char Cliente[15];

    int exitProgram = 0; // Flag to determine whether to exit the program
    int opcao;
    int continua = 1;
    // Pre-execution, data serialization:
    deserialize_Admins(&headAdmins);
    deserialize_Cliente(&headCliente);

    while (continua) // enquanto continua = 1
    {
        exitProgram = 0;
        // Summiting Admin blocks
        printf("Prompt User/Admin,");
        printf("Qual e o seu tipo de utilizador: ");
        scanf("%d", &tipo);
        if (tipo == 1) // Gestor
        {
            printf("Insira o nome do gestor:");
            scanf("%s", gestor);
            printf("insira id do gestor: ");
            scanf("%d", &codename);

            // WIP:insert login
            if (!InvalidLogin(headAdmins, gestor, codename))
            {
                printf("Invalid Login, Exiting to main menu.");
                exitProgram = 1;
            }

            while (!exitProgram)
            {
                printf("\nO que deseja fazer?\n");
                adminMenu();
                scanf("%d", &opcao);
                switch (opcao)
                {
                case 1: // Entering admin menu
                {
                    LoopAdminsProcedure(headAdmins); // gerir dados do gestor
                    break;
                }
                case 2: // Entering meios menu
                {
                    // WIP
                    LoopMeiosProcedure(headMeios, headGrafo);
                    break;
                }
                case 3:
                {
                    system("clear");
                    printf("Returning to the main menu\n");
                    exitProgram = 1;
                    break;
                }

                default:
                    system("clear");
                    printf("Error:Invalid Option");
                    break;
                }
            }
        }
        // else if (tipo == 2)
        // {
        //     printf("Insira o nome do gestor:");
        //     scanf("%s", Cliente);
        //     printf("insira id do gestor: ");
        //     scanf("%d", &ID);
        // }
        printf("deseja continuar?");
        scanf("%d", &continua);
        if (!continua)
            printf("a sair do main menu\n");
    }
    // LoopAdminsProcedure(head);

    // Summiting meios blocks
    // LoopMeiosProcedure();
    printf("a sair do programa..");
    return 0;
}
