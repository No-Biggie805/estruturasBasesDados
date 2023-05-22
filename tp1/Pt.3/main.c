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
        printf("selecione a sua opção: [0->inserir_meio/1->VerListaPMeio/2->ViewFromFile/3->SaveToFile/4->RemoveMeio");
        printf("/5->ModifyMeioData/6->RegistarAluguerMeio/7->ListarMeiosAlugados/8->PrintOrdemDecrescente/");
        printf("9->AddVertice/10->AddEdge/11->ListarEdges/12->AddMeios_Geocode/13->listarMeios_Geocode/20->sair]\n");
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
            // int valor = criarVertice(&headGraph, "abc.def.ghi");
            // printf("retorno vertice: %d", valor);
            // valor = criarVertice(&headGraph, "abc.def.ghi");
            // printf("retorno vertice: %d", valor);
            criarVertice(&headGraph, "abc.def.ghi"); // cria v1, em teoria passamos o apontador da lista(g)
                                                     // e o vertice que no caso sera um sitio na cidade
            criarVertice(&headGraph, "bc.def.ghi");  // cria v2
            criarVertice(&headGraph, "bc.def.hi");   // cria v3
            printf("\n");
            printf("\n");
            break;
        }
            // Experimental---------X-------------

        case 10:
        {
            system("clear");
            // criarEdge(headGraph, "abc.def.ghi", "jkl.mno.pqr", 11);
            criarEdge(&headGraph, "abc.def.ghi", "bc.def.ghi", 11); // cria a1(needs criarVertice Params to continue)
                                                                    // o que e?-Aresta e a coneccao de um vertice ao outro
                                                                    // Parametros:
                                                                    // g-> head
                                                                    //"abc.def.ghi"-> vOrigem
                                                                    //"bc.def.ghi"-> vDestino
                                                                    // 11-> peso, extra dado, julgo..
            criarEdge(&headGraph, "abc.def.ghi", "bc.def.hi", 1);   // cria a2, muda destino
            criarEdge(&headGraph, "abc.def.ghi", "abc.def.ghi", 3);
            printf("\n");
            printf("\n");
            break;
        }

        case 11:
        {
            system("clear");
            printf("Vertices adjacentes a abc.def.ghi\n");
            listarEdges(headGraph, "abc.def.ghi");
            printf("\n");
            printf("\n");

            break;
        }
            // Adicionar meios por geocodigo.
        case 12:
        {
            system("clear");
            printf("adicionar meios por geocodigo..");
            inserirMeio_GeoCode(headGraph, "abc.def.ghi", 1234);
            inserirMeio_GeoCode(headGraph, "abc.def.ghi", 123);
            inserirMeio_GeoCode(headGraph, "bc.def.ghi", 123445);
            printf("\nfeito");
            printf("\n");
            printf("\n");
            break;
        }
        // listar meios por geocodigo
        case 13:
        {
            system("clear");
            printf("funcao listar meios por geocodigo");
            printf("\n");
            printf("\n");
            listMeios_Geocode(headGraph, "abc.def.ghi");
            printf("\n");
            listMeios_Geocode(headGraph, "bc.def.ghi");
            printf("\n");
            break;
        }
        case 20:
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
