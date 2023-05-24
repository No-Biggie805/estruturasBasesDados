#include <stdlib.h>
#include <string.h>
#include "abp.h"

// Inserção de um novo registo numa árvore binária de procura
// Devolver o endereço do registo raíz
ABP inserir(ABP abp, int numero, char nome[])
{
      ABP novo = (ABP)malloc(sizeof(struct registo));
      if (novo == NULL)
            return (abp);
      else
      {
            novo->numero = numero;
            strcpy(novo->nome, nome);
            novo->esquerda = NULL;
            novo->direita = NULL;
            if (abp == NULL)
                  return (novo);
            else
            {
                  ABP aux = abp, *ant;
                  while (aux != NULL)
                  {
                        if (aux->numero > numero)
                        {
                              ant = &(aux->esquerda);
                              aux = aux->esquerda;
                        }
                        else
                        {
                              ant = &(aux->direita);
                              aux = aux->direita;
                        }
                  }
                  *ant = novo; // *ant referencia o campo esquerda ou direita de
                               // uma folha da árvore binária de procura.
                               // *ant = novo permite atribuir o endereço
                               // ao campo definido por *ant.
                  return (abp);
            }
      }
}

// Inserção recursiva de um novo registo numa árvore binária de procura
// Devolver o endereço do registo raíz
ABP inserirRec(ABP abp, int numero, char nome[])
{
      if (abp == NULL)
      {
            ABP novo = (ABP)malloc(sizeof(struct registo));
            if (novo == NULL)
                  return (abp);
            else
            {
                  novo->numero = numero;
                  strcpy(novo->nome, nome);
                  novo->esquerda = NULL;
                  novo->direita = NULL;
                  return (novo);
            }
      }
      else if (abp->numero > numero)
            abp->esquerda = inserirRec(abp->esquerda, numero, nome);
      else
            abp->direita = inserirRec(abp->direita, numero, nome);
      return (abp);
}

// Consulta da informação de um registo contendo um número
// passado por parâmetro
// Devolver o endereço de memória do registo se existir
// Devolver NULL se não existir
ABP consultar(ABP abp, int numero)
{
      while (abp != NULL)
      {
            if (abp->numero == numero)
                  return (abp);
            else if (abp->numero > numero)
                  abp = abp->esquerda;
            else
                  abp = abp->direita;
      }
      return (NULL);
}

// Versão recursiva
ABP consultarRec(ABP abp, int numero)
{
      if (abp == NULL)
            return (NULL);
      else if (abp->numero == numero)
            return (abp);
      else if (abp->numero > numero)
            return (consultarRec(abp->esquerda, numero));
      else
            return (consultarRec(abp->direita, numero));
}

// Quantidade de registos (versão recursiva)
int quantidadeRec(ABP abp)
{
      if (abp == NULL)
            return (0);
      else
            return (1 + quantidadeRec(abp->esquerda) + quantidadeRec(abp->direita));
}

// Quantidade de registos (versão iterativa)
int quantidadeIt(ABP abp)
{
      int contador = 0;
      return (0);
}

int altura(ABP abp)
{
      int altEsq, altDir;
      if (abp == NULL)
            return 0;
      else
      {
            altEsq = altura(abp->esquerda);
            altDir = altura(abp->direita);
            if (altEsq > altDir)
                  return (altEsq + 1);
      }
}