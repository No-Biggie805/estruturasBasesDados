#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct gestor
{
    /* data */
    char nomeCompleto[15];
    char password[15];
    int ID;
    struct gestor *next;
} gestor_t;

gestor_t *criarGestor(gestor_t **head, char nomeCompleto[], char password[], int ID);
// gestor_t *criarGestor(gestor_t *head, char nomeCompleto[], char password[], int ID);
void printList(gestor_t *head);
int existeGestor(gestor_t *head, int ID);
void FreeMem(gestor_t **head);
int serialize_Data(gestor_t *head);
gestor_t *deserialize_Data(gestor_t **head);
void Remove_gestor(gestor_t **head, int ID);

