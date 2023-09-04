#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct meios
{
    /* data */
    char tipo[15];
    int ID, bateria, autonomia;
    char registo;
    struct meios *next;
} meios_t;

meios_t *criarMeios(meios_t **head, char tipo[], int ID, int bateria, int autonomia, char registo);
// meios_t *criarGestor(meios_t *head, char nomeCompleto[], char password[], int ID);
void ListarMeios(meios_t *head);
int existeMeios(meios_t *head, int ID);
void FreeMem(meios_t **head);
int serialize_Data(meios_t *head);
meios_t *deserialize_Data(meios_t **head);
void Remove_meios(meios_t **head, int ID);
void muda_meios(meios_t **head, char tipo[], int ID, int bateria, int autonomia);
meios_t *RegistroAluguerMeio(meios_t *head, int ID);
