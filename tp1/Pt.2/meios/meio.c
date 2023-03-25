// #include <stdlib.h>
#include <string.h>
#include "meio.h"

// Inserção de um novo registo
// inserção realizada no início da lista ligada
Meio *inserirMeio(Meio *inicio, int cod, char tipo[], float bat, float aut)
{
  // cod: codigo, tipo: tipo do meio de mobilidade,
  if (!existeMeio(inicio, cod))
  {
    // Meio *novo = malloc(sizeof(struct registo));
    Meio *novo = (Meio *)malloc(sizeof(Meio)); // maneira preferivel aqui!!

    if (novo != NULL) // enquanto o nó não for nulo
    {
      novo->codigo = cod;       // atualizar no nó o dado "codigo"
      strcpy(novo->tipo, tipo); // atualizar no nó o dado "tipo"
      novo->bateria = bat;      // atualizar no nó o dado "bateria"
      novo->autonomia = aut;    // atualizar no nó o dado "autonomia"
      novo->seguinte = inicio;  // atualizar o seguinte para poder indexar a novo head
      return (novo);
    }
  }
  else               // senão
    return (inicio); // cria inicio novo de lista
}

// listar na consola o conteúdo da lista ligada
void listarMeios(Meio *inicio)
{
  while (inicio != NULL) // enquanto lista n
  {
    printf("-->%d %s %.2f %.2f\n", inicio->codigo, inicio->tipo,
           inicio->bateria, inicio->autonomia);
    inicio = inicio->seguinte;
  }
}

// Determinar existência do 'codigo' na lista ligada 'inicio'
// devolve 1 se existir ou 0 caso contrário
int existeMeio(Meio *inicio, int cod)
{
  while (inicio != NULL) // enquanto a lista não atingir ao fim
  {
    if (inicio->codigo == cod)
      return (1);              // return 1 quererá dizer verdadeiro
    inicio = inicio->seguinte; // senão continuará a ver até ao fim da lista
                               // o procedimento, por trás, atualiza o seguinte da struct(ou linked list)
  }                            // chegou a NULL, terminou a lista

  return (0); // função retorna 0 se e só se o bloco vir que deu falso
}

Meio *removerMeio(Meio *inicio, int cod) // Remover um meio a partir do seu código
{
  Meio *aux;
  
  while (inicio != NULL)
  {
    if (inicio->codigo == cod)
    {
      aux = inicio->seguinte;
      free(inicio);
      return (aux);
    }
    else
    {
      inicio = removerMeio(inicio->seguinte, cod);
      return (inicio);
    }
  }
}

/*
// Remover um meio a partir do seu código{
Meio *removerMeio(Meio *inicio, int cod)
{
  Meio *anterior = inicio, *atual = inicio, *aux;

  if (atual == NULL)
    return (NULL);               // lista ligada vazia
  else if (atual->codigo == cod) // remoção do 1º registo
  {
    aux = atual->seguinte;
    free(atual);
    return (aux);
  }
  else
  {
    while ((atual != NULL) && (atual->codigo != cod))//procurar na lista
    {
      anterior = atual;
      atual = atual->seguinte;
    }
    if (atual == NULL)
      return (inicio);
    else//se o atual ñ atingiu o fim da linked list ao longo do ciclo while
    {
      anterior->seguinte = atual->seguinte;
      free(atual);
      return (inicio);
    }
  }
}
*/
void freeMem(Meio *inicio)
{
  printf("\nFunção Liberar, a executar..");
  Meio *newNode = inicio;
  Meio *temp;
  while (newNode != NULL)
  {
    // temp = newNode;
    temp = newNode->seguinte;
    newNode = temp;
    free(newNode);
  }
}