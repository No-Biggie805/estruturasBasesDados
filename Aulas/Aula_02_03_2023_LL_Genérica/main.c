#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll.h"

// Estruturas de Dados
//
// Representar os dados de um conjunto de jogadores recorrendo ao
// módulo de listas genéricas
// Considerar para cada jogador: número, nome, 5 preferências de armas

typedef struct
{
    char arma[50]; // arma de combate
    int pontuacao; // 0 a 100
} Preferencias;

typedef struct dados
{
    int numero;
    char nome[50];
    Preferencias preferencias[5]; // ordem de preferências (máximo de 5)
} *Jogador;
// Protótipos

void show(void *data);
int igual(void *data1, void *data2);
void main();

// Implementações

// Escrita na consola do dados de um jogador
void show(void *data)
{
    Jogador j = (Jogador)data;
    if (j != NULL)
        printf("%d %s ", j->numero, j->nome);
    for (int i = 0; i < 5; i++)//looping of 5 players
        printf("%s %d ", j->preferencias[i].arma, j->preferencias[i].pontuacao);
    printf("\n");
}

// Se iguais devolve 0
// se número do jogador referenciado por data1 for inferior devolve -1
// caso contrário 1
int comparar(void *data1, void *data2)//função de comparação(usado em funções/procedimentos como um bloco)
                                    //será enviado como um parâmetro
{
    Jogador d1 = (Jogador)data1;
    Jogador d2 = (Jogador)data2;
    if (d1->numero < d2->numero)//se numero de d1 < numero de d2..
        return (1);//retornar "seguinte"
    else if (d1->numero > d2->numero)//senão.. se for o inverso
        return (-1);// retorna "anterior"
    else
        return (0);//senão retorna "igual"
}

int compararNomes(void *data1, void *data2)
{
    Jogador d1 = (Jogador)data1;
    Jogador d2 = (Jogador)data2;
    return (-strcmp(d1->nome, d2->nome));
}

// Se iguais devolve 1 senão devolve 0
// 1º parâmetro: endereço de memória de um jogador
// 2º parâmetro: número do jogador a remover
// Devolve 1 se os códigos são iguais
// Devolve 0 caso contrário
int igual(void *data1, void *data2)
{
    Jogador d1 = (Jogador)data1;
    int *d2 = (int *)data2;
    if ((d1 != NULL) && (d2 != NULL))
        return (d1->numero == *d2);
    else
        return (0);
}

// Procedimento principal
void main()
{
    ListElem lista = NULL; // definição de uma lista ligada vazia
    Jogador j;

    j = (Jogador)malloc(sizeof(struct dados));
    j->numero = 1;
    strcpy(j->nome, "Sara");
    strcpy(j->preferencias[0].arma, "sniper");
    j->preferencias[0].pontuacao = 87;
    strcpy(j->preferencias[1].arma, "pistola");
    j->preferencias[1].pontuacao = 67;
    strcpy(j->preferencias[2].arma, "metralhadora");
    j->preferencias[2].pontuacao = 57;
    strcpy(j->preferencias[3].arma, "-");
    j->preferencias[3].pontuacao = 0;
    strcpy(j->preferencias[4].arma, "-");
    j->preferencias[4].pontuacao = 0;
    lista = addItemHead(lista,j);
    // lista = addItemOrderedIterative(lista, j, &compararNomes);

    j = (Jogador)malloc(sizeof(struct dados));
    j->numero = 3;
    strcpy(j->nome, "Bruno");
    strcpy(j->preferencias[0].arma, "metralhadora");
    j->preferencias[0].pontuacao = 77;
    strcpy(j->preferencias[1].arma, "sniper");
    j->preferencias[1].pontuacao = 79;
    strcpy(j->preferencias[2].arma, "-");
    j->preferencias[2].pontuacao = 0;
    strcpy(j->preferencias[3].arma, "-");
    j->preferencias[3].pontuacao = 0;
    strcpy(j->preferencias[4].arma, "-");
    j->preferencias[4].pontuacao = 0;
    lista = addItemHead(lista,j);
    // lista = addItemOrderedIterative(lista, j, &compararNomes);

    j = (Jogador)malloc(sizeof(struct dados));
    j->numero = 2;
    strcpy(j->nome, "Jose");
    strcpy(j->preferencias[0].arma, "sniper");
    j->preferencias[0].pontuacao = 87;
    strcpy(j->preferencias[1].arma, "pistola");
    j->preferencias[1].pontuacao = 67;
    strcpy(j->preferencias[2].arma, "metralhadora");
    j->preferencias[2].pontuacao = 57;
    strcpy(j->preferencias[3].arma, "-");
    j->preferencias[3].pontuacao = 0;
    strcpy(j->preferencias[4].arma, "-");
    j->preferencias[4].pontuacao = 0;
    lista = addItemHead(lista,j);
    // lista = addItemOrderedIterative(lista, j, &compararNomes);

    // Escrita na consola do conteúdo da lista ligada
    showListIterative(lista, &show);

    // printf("-----------------------------------------------------------\n");
    int numero = 2;
    // Remoção da primeiro ocorrência do registo com número de jogador 2
    lista = removeItemIterative(lista, &numero, &igual);

    // Escrita na consola do conteúdo da lista ligada
    showListIterative(lista, &show);
}
