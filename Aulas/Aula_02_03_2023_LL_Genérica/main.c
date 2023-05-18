#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll.h"

void main();

// Implementações


// Procedimento principal
void main()
{
    ListElem *lista = NULL; // definição de uma lista ligada vazia
    Jogador *j;

    j = (Jogador*)malloc(sizeof(struct dados));
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
    // lista = addItemHead(lista,j);
    lista = addItemOrderedIterative(lista, j, &compararNomes);

    j = (Jogador*)malloc(sizeof(struct dados));
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
    // lista = addItemHead(lista,j);
    lista = addItemOrderedIterative(lista, j, &compararNomes);

    j = (Jogador*)malloc(sizeof(struct dados));
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
    // lista = addItemHead(lista,j);
    lista = addItemOrderedIterative(lista, j, &compararNomes);

    // Escrita na consola do conteúdo da lista ligada
    showListIterative(lista, &show);

    // printf("-----------------------------------------------------------\n");
    int numero = 2;
    // Remoção da primeiro ocorrência do registo com número de jogador 2
    lista = removeItemIterative(lista, &numero, &igual);

    // Escrita na consola do conteúdo da lista ligada
    showListIterative(lista, &show);
}
