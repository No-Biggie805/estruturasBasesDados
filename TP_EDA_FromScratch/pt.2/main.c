// Base do projecto, sera o que ira guardar o menu da lista ao total.

#include "meios.h"
int menu();

int main()
{

    meios_t *head = NULL;

    char tipo[15];
    int ID, bateria, autonomia, op;

    while (1)
    {
        // printf("insira opcao"); scanf("%d", op);
        op = menu();
        switch (op)
        {
        case 1:
            printf("insira o tipo do meio:");
            scanf("%s", tipo);
            printf("insira o ID do meio");
            scanf("%d", &ID);
            printf("insira a percentagem da bateria do meio:");
            scanf("%d", &bateria);
            printf("insira a autonomia do meio:");
            scanf("%d", &autonomia);
            // char registo = 'n';
            head = criarMeios(&head, tipo, ID, bateria, autonomia);
            // Escrever dados pos ter guardado na memoria
            serialize_Data(head);
            // if (check == 1)
            //     printf("dados escritos");
            // else if (check == 0) /* condition */
            //     printf("dados nao escritos");
            break;
        case 2:
            system("clear");
            printf("printing out the link-list information\n");
            ListarMeios(head);
            break;
        case 3:
            system("clear");
            printf("select which ID you want deleted");
            scanf("%d", &ID);
            Remove_meios(&head, ID);
            break;
        case 4: // serializing data
            system("clear");
            printf("Iniciar escrita de dados");
            serialize_Data(head);
            break;
        case 5:
            system("clear");
            printf("Inicializar a leitura de dados");
            deserialize_Data(&head);
            break;
        case 6:
            system("clear");
            printf("Função altera dados\n");
            printf("insira o tipo de meio:");
            scanf("%s", tipo);
            printf("\n");
            printf("insira o ID do meio:");
            scanf("%d", &ID);
            printf("\n");
            printf("insira a bateria do meio:");
            scanf("%d", &bateria);
            printf("\n");
            printf("insira a autonomia do meio:");
            scanf("%d", &autonomia);
            printf("\n");
            muda_meios(&head, tipo, ID, bateria, autonomia);
            break;
        // case 7:
        //     system("clear");
        //     printf("Função registo\n");
        //     printf("insira o ID do meio:");
        //     scanf("%d", &ID);
        //     head = RegistroAluguerMeio(head, ID);
        //     break;
        case 8:
            system("clear");
            bubbleSort(&head);
            break;
        case 0:
            system("clear");
            printf("\n");
            printf("A libertar memoria..");
            FreeMem(&head);
            return 0;
            break;

        default: // wrong option
            break;
        }
    }

    return 0;
}

int menu()
{
    int op;
    printf("M E N U\n");
    printf("1 Inserir meio\n");
    printf("2 Listar meios\n");
    printf("3 Remover meios\n");
    printf("4 Guardar meios\n");
    printf("5 Ler meios\n");
    printf("6 alterar dados meios\n");
    printf("7 Registar Meio\n");
    printf("8 Ordenar a lista dos meios\n");
    printf("0 Sair\n");
    printf("Opcao:\n");
    scanf("%d", &op);
    return (op);
}
