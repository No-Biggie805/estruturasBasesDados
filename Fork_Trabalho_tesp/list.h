
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int opcao;
int op = 1;
typedef struct Temp
{
    int matricula;
    char nome[50];
    char curso[50];
    char datnasc[30];
    struct Temp *prox;
} lista;
// cria o inicio da lista, em vazio
lista *inicio;
//--------------------------------------------------------

void criaLista();//criar nova lista

void cadastro();//adicionar a lista

void imprimePonterio(lista *ponteirolista);//procedimento imprimir 

lista *pesquisamatricula();//funccao pesquisar matricula de retorno do nodo dos dados da pesquisa

lista *pesquisanome();//funcao pesquisar por nome de retorno do nodo dos dados da pesquisa

int removedado(int dado); // funçao int para retornar os numeros.

void libera(lista **head);//liberar o apontador ao sair do programa

void imprime();//imprimir lista