/*Questões a fazer ao professor sobre o trabalho:
1->Qual  será a estrutura base do programa ao desenvolver sem inclusão dos dados da lista?
e.g:quesão do registo do utilizador
R:serão listas do Cliente, gestor e mobilidade

2->Como irá depois ser feito o funcionamento do antes e depois de implementar as linked lists?
e.g:questões da gestão de dados quais poderão ser numa
estrutura base e os que serão para linked list?

R: em principio serão todos linked lists
*/

#include "DBheader.h"

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
        printf("selecione a sua opção: [0->inserir_user/1->VerListaPNome/2->viewFromFile/10->sair]\n");
        printf("op:");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
        {
            system("clear");
            printf("enter your username:");
            scanf("%s", name);
            printf("enter your password:");
            scanf("%s", password);
            printf("enter your code name: ");
            scanf("%d", &codename);

            EnterUser(&head, name, password, codename);
            // newUser = EnterUser(name, password); //to enter new user
            // newUser->next = head;
            // head = newUser;

            ConfirmLogIN(head, name, codename); // passing procedure to confirm if user logged in
            serialize(head);                              // call for serialize funtion
            printf("\n");
            break;
        }
        case 1:
        {
            system("clear");
            printList(head);
            break;
        }
        case 2: // Read files data
        {
            system("clear");
            deserialize(&head);
            break;
        }

        case 10:
        {
            system("clear");
            printf("\n");
            FreeMem(&head); // funcção liberar apontadores à memoria
            printf("-->saiu do programa\n");
            return 0;
            break;
            // falta adicionar função liberar(free)
        } // end of case 1

        default:
            system("clear");
            printf("Error:Invalid Option");
        }
    }

    return 0;
}
