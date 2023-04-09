/**
 * @file DBheader.h
 * @author Jose Santos (a18605@alunos.ipca.pt)
 * @brief header file to manage core data of the link list program
 * @version 0.1
 * @date 2023-03-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include <stdbool.h>

typedef struct AdminUser // lista de usuário a manter o programa, irá talvez ser melhorado
                         // conforme o que o professor preferir
{
    int CodeID;
    char type[50];
    float batery, autonomia;
    struct AdminUser *next;
} AdminUser_t;

//  AdminUser_t *head;
// void generateNewList();

AdminUser_t *insertMeio(AdminUser_t **head, char type[], int CodeID, float batery, float autonomia);
void printList(AdminUser_t *head);
// void ConfirmLogIN(AdminUser_t *head, char name[], int codename);
void serialize(AdminUser_t *head); // write name data to file
AdminUser_t *deserialize(AdminUser_t **head); // Read data from file, in dev.
void FreeMem(AdminUser_t **head);
int existAdmin(AdminUser_t *head, int CodeID);
AdminUser_t *deleteMeio(AdminUser_t *head, int CodeID);
void ModMeio(AdminUser_t **head, char *type, int CodeID, float batery, float autonomia);