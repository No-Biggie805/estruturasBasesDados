#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include <stdbool.h>

typedef struct AdminUser // lista de usuário a manter o programa, irá talvez ser melhorado
                         // conforme o que o professor preferir
{
    char name[15], password[12];
    int codename;
    // char *name, *password;
    struct AdminUser *next;
} AdminUser_t;

// AdminUser_t *head;
// void generateNewList();

AdminUser_t *EnterUser(AdminUser_t **head, char name[], char password[], int codename);

void printList(AdminUser_t *head);
void ConfirmLogIN(AdminUser_t *head, char name[], int codename);
void serialize(AdminUser_t *head); // write name data to file
AdminUser_t *deserialize(AdminUser_t **head); // Read data from file, in dev.
void FreeMem(AdminUser_t **head);
int existAdmin(AdminUser_t *head, int codename);
// void deleteNode(AdminUser_t **head, int pos);