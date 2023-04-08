#include <stdio.h>

typedef struct registo
{int codigo; // código do meio de mobilidade elétrica
 char tipo[50];
 float bateria;
 float autonomia;
 struct registo* seguinte;
} Meio;


Meio* inserirMeio(Meio* inicio, int cod, char tipo[], float bat, float aut); // Inserção de um novo registo
void listarMeios(Meio* inicio); // listar na consola o conteúdo da lista ligada
int existeMeio(Meio* inicio, int codigo); // Determinar existência do 'codigo' na lista ligada 'inicio'
Meio* removerMeio(Meio* inicio, int cod); // Remover um meio a partir do seu código

int tamanho(Meio* inicio); //Tamanho da lista ligada
Meio* inserirFim(Meio* inicio, int cod, char tipo[], float bat, float aut); // Inserção de um novo registo no fim
int removerTodos(Meio* inicio); // remover lista ligada
Meio* consultar(Meio* inicio, int cod); // consultar registo a partir do código
float mediaAutonomia(Meio* inicio); // cálculo da autonomia média
Meio* copiaListaLigada(Meio* inicio); // Criar uma cópia da lista ligada
Meio* inserirPos(Meio* inicio, int pos, int cod, char tipo[], float bat, float aut); // Inserção de um novo registo numa determinada posição
Meio* alterarMeio(Meio* inicio, int pos, int cod, char tipo[], float bat, float aut); // Alterar dados

// Associar histórico de alugueres sob a forma de uma lista ligada

int guardarMeios(Meio* inicio);
Meio* lerMeios();
