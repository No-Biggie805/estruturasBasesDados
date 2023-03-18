
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Temp
{
    int matricula;
    char nome[50];
    char curso[50];
    char datnasc[30];
    struct Temp *prox;
} lista;

// cria o inicio da lista, em vazio
// lista *inicio;
//--------------------------------------------------------

// void criaLista(lista *inicio); // criar nova lista

lista *cadastro(lista **inicio); // adicionar a lista

// void imprimePonterio(lista **inicio);//procedimento imprimir

// lista *pesquisamatricula(lista *inicio);//funccao pesquisar matricula de retorno do nodo dos dados da pesquisa

// lista *pesquisanome(lista *inicio);//funcao pesquisar por nome de retorno do nodo dos dados da pesquisa

// int removedado(lista *inicio, int dado); // funçao int para retornar os numeros.

void imprime(lista *inicio); // imprimir lista

void libera(lista **inicio); // liberar o apontador ao sair do programa

