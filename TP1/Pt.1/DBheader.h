#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <stdbool.h>

typedef struct AdminUser // lista de usuário a manter o programa, irá talvez ser melhorado
                         // conforme o que o professor preferir
{
    char name[15], password[12];
    // char *name, *password;
    struct AdminUser *next;
} AdminUser_t;

// AdminUser_t *head;
// void generateNewList();

AdminUser_t *EnterUser(char name[], char password[]);

// void ConfirmLogIN(AdminUser_t *head, char name[], char password[]);
void printList(AdminUser_t *head);
void FreeMem(AdminUser_t **head);
// void deleteNode(AdminUser_t **head, int pos);