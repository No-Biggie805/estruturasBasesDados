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

typedef struct Meios // lista de usuário a manter o programa, irá talvez ser melhorado
                         // conforme o que o professor preferir
{
    int CodeID, RegistoAlugado;
    char type[50];
    float batery, autonomia;
    struct Meios *next;
} Meios_t;

//  Meios_t *head;
// void generateNewList();

Meios_t *insertMeio(Meios_t **head, char type[], int CodeID, float batery, float autonomia);
void printList(Meios_t *head);
// void ConfirmLogIN(Meios_t *head, char name[], int codename);
void serialize(Meios_t *head); // write name data to file
Meios_t *deserialize(Meios_t **head); // Read data from file, in dev.
void FreeMem(Meios_t **head);
int existAdmin(Meios_t *head, int CodeID);
Meios_t *deleteMeio(Meios_t *head, int CodeID);
void ModMeio(Meios_t **head, char *type, int CodeID, float batery, float autonomia);
void RegistoAluguelMeio(Meios_t *head, int CodeID);
void PrintListaMeiosAlugados(Meios_t *head);

