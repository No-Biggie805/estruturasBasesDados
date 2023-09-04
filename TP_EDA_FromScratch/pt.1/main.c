// Base do projecto, sera o que ira guardar o menu da lista ao total.

#include "DBgestor.h"
int menu();

int main()
{

    gestor_t *head = NULL;

    char nomeCompleto[15], password[15];
    int ID, op;

    while (1)
    {
        // printf("insira opcao"); scanf("%d", op);
        op = menu();
        switch (op)
        {
        case 1:
            printf("insira o nome do gestor");
            scanf("%s", nomeCompleto);
            printf("insira a password");
            scanf("%s", password);
            printf("insira o ID");
            scanf("%d", &ID);
            head = criarGestor(&head, nomeCompleto, password, ID);
            // //Experimental
            // head = criarGestor(head, nomeCompleto, password, ID);

            // Escrever dados pos ter guardado na memoria
            int check = serialize_Data(head);
            if (check == 1)
                printf("dados escritos");
            else if (check == 0) /* condition */
                printf("dados nao escritos");
            break;
        case 2:
            system("clear");
            printf("printing out the link-list information\n");
            printList(head);
            break;
        case 3:
            system("clear");
            printf("select which ID you want deleted");
            scanf("%d", &ID);
            Remove_gestor(&head, ID);
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
            printf("insira o nome do gestor");
            scanf("%s", nomeCompleto);
            printf("\n");
            printf("insira a password do gestor");
            scanf("%s", password);
            printf("\n");
            printf("insira a identificação do gestor");
            scanf("%d", &ID);
            printf("\n");
            muda_gestor(&head, ID, nomeCompleto, password);
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
    printf("1 Inserir gestor\n");
    printf("2 Listar gestores\n");
    printf("3 Remover gestores\n");
    printf("4 Guardar gestores\n");
    printf("5 Ler gestores\n");
    printf("6 alterar dados gestor\n");
    printf("0 Sair\n");
    printf("Opcao:\n");
    scanf("%d", &op);
    return (op);
}
