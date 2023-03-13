#include <stdio.h>
#include <stdlib.h>
// Remover um meio a partir do seu código
// ------------------------------              ------------------------------
// |              |             |            \ |              |             |
// |     DATA     |     NEXT    |--------------|     DATA     |     NEXT    |
// |              |             |            / |              |             |
// ------------------------------              ------------------------------

typedef struct registo
{
    int codigo;               // código do meio de mobilidade elétrica
    char tipo[50];            // tipo do meio de mobilidade
    float bateria;            // carga da bateria
    float autonomia;          // autonomia
    struct registo *seguinte; // endereço de memória para uma struct registo
} Meio;

// Inserção de um novo registo
Meio *inserirMeio(Meio *inicio, int cod, char tipo[], float bat, float aut);

// listar na consola o conteúdo da lista ligada
void listarMeios(Meio *inicio);

// Determinar existência do 'codigo' na lista ligada 'inicio'
int existeMeio(Meio *inicio, int codigo);

// Remover um meio a partir do seu código
Meio *removerMeio(Meio *inicio, int cod);

void freeMem(Meio *inicio);