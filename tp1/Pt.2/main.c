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

#include "DBmeios.h"

/**
 * @brief main function, contains the following functions
 * @return int
 */
int main()
{
    Meios_t *head = NULL;
    Grafo_t *headGraph = NULL;

    char tipo[50];
    int CodeID;
    float bateria, autonomia;

    int opcao; //, tipo_user;

    while (1)
    {

        // system("clear");
        printf("selecione a sua opção: [0->inserir_meio/1->VerListaPMeio/2->ViewFromFile/3->SaveToFile/4->RemoveMeio/5->ModifyMeioData/6->RegistarAluguerMeio/7->ListarMeiosAlugados/8->PrintOrdemDecrescente/9->AddVertice/10->sair]\n");
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
            printf("enter vehicle ID:");
            scanf("%d", &CodeID);
            printf("enter vehicle type:");
            scanf("%s", tipo);
            printf("enter the amount of batery resting: ");
            scanf("%f", &bateria);
            printf("enter what autonomy will it have: ");
            scanf("%f", &autonomia);

            /**
             * @brief Construct a new insertMeio object and store to link list
             *
             */
            head = insertMeio(&head, tipo, CodeID, bateria, autonomia);
            // newUser = EnterUser(name, password); //to enter new user
            // newUser->next = head;
            // head = newUser;

            // /**
            //  * @brief Construct a new Confirm Log I N object
            //  *
            //  */
            // ConfirmLogIN(head, name, codename); // passing procedure to confirm if user logged in
            // /**
            //  * @brief Construct a new serialize object
            //  *
            //  */
            // serialize(head); // call for serialize funtion
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
            printf("remover o meio:\n");
            printf("insira o codigo do veiculo:");
            scanf("%d", &CodeID);
            /**
             * @brief call the delete funtion and store to linked list
             *
             */
            head = deleteMeio(head, CodeID);
            break;
        }

        case 5:
        {
            system("clear");
            printf("funcao modificar data do Meio:\n");
            printf("insira o codigo/ID do meio: ");
            scanf("%d", &CodeID);
            printf("\ninsira tipo: ");
            scanf("%s", tipo);
            printf("\ninsira nova bateria: ");
            scanf("%f", &bateria);
            printf("\ninsira nova autonomia: ");
            scanf("%f", &autonomia);
            ModMeio(&head, tipo, CodeID, bateria, autonomia);
            break;
        }

        case 6: // Registering meios
        {
            system("clear");
            // head->RegistoAlugado = RegistoAluguelMeio(head, CodeID); // updating registo aqui!!
            printf("insira um codigo/ID para fazer o registo :");
            scanf("%d", &CodeID);
            RegistoAluguelMeio(head, CodeID);
            printf("\n");
            printf("\n");
            break;
        }

        case 7: // Ver Alugados
        {
            system("clear");
            PrintListaMeiosAlugados(head);
            printf("\n");
            printf("\n");
            break;
        }

        case 8:
        {
            system("clear");
            head = PrintOrdemDecrescente(head);
            // PrintOrdemDecrescente(head);
            printf("\n");
            printf("\n");
            break;
        }

        // Funcao temporaria criar vertice, nao funciona by default..
        case 9:
        {
            system("clear");
            int valor = criarVertice(&headGraph, "abc.def.ghi");
            printf("retorno vertice: %d", valor);
            valor = criarVertice(&headGraph, "abc.def.ghi");
            printf("retorno vertice: %d", valor);
            printf("\n");
            printf("\n");
            break;
        }

        case 10:
        {
            system("clear");
            printf("\n"); //
            /**
             * @brief Construct a new Free Mem object
             *
             */
            FreeMem(&head); // funcção liberar apontadores à memoria
            printf("-->saiu do programa\n");
            return 0;
            break;
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
