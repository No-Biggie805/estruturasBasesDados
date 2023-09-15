#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct meios
{
    /* data */
    char tipo[15];
    int ID, RegistoMeio;
    float bateria, autonomia;
    struct meios *next;
} meios_t;

meios_t *criarMeios(meios_t **head, char tipo[], int ID, float bateria, float autonomia, int RegistoMeio);
// meios_t *criarGestor(meios_t *head, char nomeCompleto[], char password[], int ID);
void ListarMeios(meios_t *head);
int existeMeios(meios_t *head, int ID);
void FreeMem(meios_t **head);
void serialize_Data(meios_t *head);
meios_t *deserialize_Data(meios_t **head);
void Remove_meios(meios_t **head, int ID);
void muda_meios(meios_t **head, char tipo[], int ID, float bateria, float autonomia);
void RegistroAluguerMeio(meios_t *head, int ID);
/*experimental*/
meios_t *swap(meios_t *ptr1, meios_t *ptr2);
int getCount(meios_t **head);
int bubbleSort(meios_t **head);
