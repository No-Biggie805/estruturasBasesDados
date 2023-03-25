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

#include "DBheader.h"

/**
 * @brief main function, contains the following functions
 * @return int
 */
int main()
{
    AdminUser_t *head = NULL;
    // AdminUser_t *newUser = NULL;
    char name[15], password[15];
    int codename;

    int opcao; //, tipo_user;

    while (1)
    {

        // system("clear");
        printf("selecione a sua opção: [0->inserir_user/1->VerListaPNome/2->ViewFromFile/3->SaveToFile/4->RemoveUser/5->ModifyUserData/10->sair]\n");
        printf("op:");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0: // adding and auto serialization
        {
            /**
             * @brief user input functions
             *
             */
            system("clear");
            printf("enter your username:");
            scanf("%s", name);
            printf("enter your password:");
            scanf("%s", password);
            printf("enter your code name: ");
            scanf("%d", &codename);

            /**
             * @brief Construct a new Enter User object and store to link list
             *
             */
            head = EnterUser(&head, name, password, codename);
            // newUser = EnterUser(name, password); //to enter new user
            // newUser->next = head;
            // head = newUser;

            /**
             * @brief Construct a new Confirm Log I N object
             *
             */
            ConfirmLogIN(head, name, codename); // passing procedure to confirm if user logged in
            /**
             * @brief Construct a new serialize object
             *
             */
            serialize(head); // call for serialize funtion
            printf("\n");
            break;
        }
        case 1:
        {
            system("clear");
            /**
             * @brief Construct a new print List object
             *
             */
            printList(head);
            break;
        }
        case 2: // Read files data
        {
            system("clear");
            /**
             * @brief Construct a new deserialize object
             *
             */
            deserialize(&head);
            break;
        }

        case 3:
        {
            system("clear");
            /**
             * @brief Construct a new serialize object
             *
             */
            serialize(head); // serialize at runtime whithout adding new user
            break;
        }

        case 4:
        {
            system("clear");
            printf("remover o user:\n");
            printf("insira o codigo do gestor:");
            scanf("%d", &codename);
            /**
             * @brief call the delete funtion and store to linked list
             *
             */
            head = deleteUser(head, codename);
            break;
        }

        case 5:
        {
            system("clear");
            printf("funcao modificar data do user:\n");
            printf("insira o codigo do gestor:");
            scanf("%d", &codename);
            printf("\ninsira name:");
            scanf("%s", name);
            printf("\ninsira password:");
            scanf("%s", password);

            ModUser(&head, codename, name, password);
            break;
        }

        case 10:
        {
            system("clear");
            printf("\n");
            /**
             * @brief Construct a new Free Mem object
             *
             */
            FreeMem(&head); // funcção liberar apontadores à memoria
            printf("-->saiu do programa\n");
            return 0;
            break;
            // falta adicionar função liberar(free)
        } // end of case 1

        /**
         * @brief default state, exiting the switch case going to while loop
         *
         */
        default:
            system("clear");
            printf("Error:Invalid Option");
        }
    }

    return 0;
}
