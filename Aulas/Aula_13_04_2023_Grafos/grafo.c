#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "grafo.h"

// Criar um novo vértice
// Devolve 1 em caso de sucesso ou 0 caso contrário
int criarVertice(Grafo **g, char novoId[]) // criar novo nodo de vertice
{
  Grafo *novo = malloc(sizeof(struct registo1));
  if (novo != NULL)
  {
    strcpy(novo->vertice, novoId);
    novo->meios = NULL;
    novo->seguinte = *g;
    *g = novo;
    return (1);
  }
  else
    return (0);
}

// Devolve 1 se o vertice existe no grafo ou 0 caso contrário
int existeVertice(Grafo *g, char vertice[]) // verificar se existe ou nao nodo
{
  while (g != NULL)
  {
    if (strcmp(g->vertice, vertice) == 0)
      return (1);
    else
      g = g->seguinte;
  }
  return (0);
}

// Criar uma nova aresta
// Devolve 1 em caso de sucesso ou 0 caso contrário
int criarAresta(Grafo *g, char vOrigem[], char vDestino[], float peso) // criar novo nodo de aresta
{
  Adjacente *novo;
  if (existeVertice(g, vOrigem) && existeVertice(g, vDestino)) // if vOrigem and vDestino exist inside Llist
  {                                                            // execute the following
    while (strcmp(g->vertice, vOrigem) != 0)                   // while compared strings are different
      g = g->seguinte;                                         // transverse linked list
    novo = (Adjacente *)malloc(sizeof(Adjacente));
    if (novo != NULL)
    {
      strcpy(novo->vertice, vDestino);
      novo->peso = peso;
      novo->seguinte = g->adjacentes;
      g->adjacentes = novo;
      return (1); // return true
    }
    else
      return (0); // Nao vejo utilidade nisto.. mas ok
  }
  else
    return (0);
}

// Listar os vértices adjacentes
void listarAdjacentes(Grafo *g, char vertice[])
{
  Adjacente *aux;
  if (existeVertice(g, vertice))
  {
    while (strcmp(g->vertice, vertice) != 0) // while remote vertice != local vertice
      g = g->seguinte;                       // tranverse L-list
    //g->adjacentes constains data such as peso  
    while (aux != NULL)
    {
      printf("Adjacente:%s Peso:%.2f\n", aux->vertice, aux->peso);
      aux = aux->seguinte;
    }
  }
}

// Inserir meio de transporte na localização com geocódigo passado por parâmetro
// Devolve 1 em caso de sucesso ou 0 caso contrário
int inserirMeio(Grafo *g, char geocodigo[], int codigoMeio)
{
  while ((g != NULL) && (strcmp(g->vertice, geocodigo) != 0)) // While head is not NULL
                                                              // and is different from geocodigo
    g = g->seguinte;
  if (g == NULL)
    return (0);
  else
  {
    Meios *novo = malloc(sizeof(struct registo3));
    novo->codigo = codigoMeio;
    novo->seguinte = g->meios;
    g->meios = novo;
    return (1);
  }
}

// Listar os códigos dos meios de transporte presente numa determinada localização passada por parâmetro
void listarMeios(Grafo *g, char geocodigo[])
{
  while ((g != NULL) && (strcmp(g->vertice, geocodigo) != 0))
    g = g->seguinte;
  if (g != NULL)
  {
    Meios *aux = g->meios;
    if (aux == NULL)
      printf("sem meios de transporte\n");
    else
      while (aux != NULL)
      {
        printf("Codigo meio: %d\n", aux->codigo);
        aux = aux->seguinte;
      }
  }
  else
    printf("geocodigo inexistente\n");
}
