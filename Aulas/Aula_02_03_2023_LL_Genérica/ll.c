#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ll.h" // header file
// Implementações
// Add userData, to void *data pointer instead of individual values
ListElem *addItemHead(ListElem *head, void *data)
{
	ListElem *aux = (ListElem *)malloc(sizeof(SListElem));

	if (aux == NULL)
		return head;

	aux->data = data;
	aux->next = head;

	return aux;
}

// Add userData, to void *data pointer instead of individual values
// adding data recursively
ListElem *addItemLastRecursive(ListElem *head, void *data)
{
	ListElem *aux = (ListElem *)malloc(sizeof(SListElem));

	if (head == NULL)
	{
		aux->data = data;
		aux->next = NULL;
		return aux;
	}

	head->next = addItemLastRecursive(head->next, data);

	return head;
}

// Add userData, to void *data pointer instead of individual values
// adding data iteratively, inside the for() loop
ListElem *addItemLastIterative(ListElem *head, void *data)
{
	ListElem *aux, *prev;
	aux = (ListElem *)malloc(sizeof(SListElem));

	// First we dinamically allocate data to aux pointer
	aux->data = data;
	aux->next = NULL; // we for now want aux node as an isolated node

	if (head == NULL) // if list is empty
	{
		return aux; // store to linked list right away
	}

	for (prev = head; prev->next != NULL; prev = prev->next) // tranverse link list iterativerly
		prev->next = aux;									 //	store aux node to the next node
	return head;											 // return the link updated list.
}

void showListIterative(ListElem *head, void (*show)(void *data))
{
	while (head != NULL)
	{
		show(head->data);//summon show function to output data 
		head = head->next;//transverse link list
	}
}

void showListRecursive(ListElem *head, void (*show)(void *data))
{
	if (head != NULL)
	{
		show(head->data);
		showListRecursive(head->next, show);
	}
}

ListElem *removeItemIterative(ListElem *head, void *data, int (*compare)(void *data1, void *data2))
{
	ListElem *aux, *prev;

	// List is empty
	if (head == NULL)
		return NULL;

	// Element to remove is on the head of the list
	if (compare(head->data, data) == 1)
	{
		aux = head->next;
		free(head);
		return aux;
	}

	// Element to remove is in the tail of the list
	for (prev = head; prev->next != NULL; prev = prev->next)
	{
		if (compare(prev->next->data, data) == 1)
		{
			aux = prev->next;
			prev->next = prev->next->next;
			free(aux);
			break;
		}
	}

	return head;
}

ListElem *removeItemRecursive(ListElem *head, void *data, int (*compare)(void *data1, void *data2))
{
	ListElem *aux;

	if (head == NULL)
		return NULL;

	if (compare(head->data, data) == 1)
	{
		aux = head->next;
		free(head);
		return aux;
	}
	else
	{
		head->next = removeItemRecursive(head->next, data, compare);
		return head;
	}
}

ListElem *addItemOrderedIterative(ListElem *head, void *data, int (*compare)(void *data1, void *data2))
{
	ListElem *n, *aux;

	n = (ListElem *)malloc(sizeof(SListElem));
	n->data = data;
	n->next = NULL;

	if (head == NULL || compare(data, head->data) < 0)
	{
		n->next = head;
		return n;
	}

	for (aux = head; aux->next != NULL; aux = aux->next)
	{
		if (compare(data, aux->next->data) < 0)
		{
			n->next = aux->next;
			aux->next = n;
			return head;
		}
	}

	aux->next = n;
	return head;
}

ListElem *addItemOrderedRecursive(ListElem *head, void *data, int (*compare)(void *data1, void *data2))
{
	ListElem *aux;

	if (head == NULL || compare(data, head->data) < 0)
	{
		aux = (ListElem *)malloc(sizeof(SListElem));
		aux->data = data;
		aux->next = head;
		return aux;
	}

	head->next = addItemOrderedRecursive(head->next, data, compare);
	return head;
}

// Escrita na consola do dados de um jogador
void show(void *data)
{
    Jogador *j = (Jogador *)data;
    if (j != NULL)
        printf("%d %s ", j->numero, j->nome);
    for (int i = 0; i < 5; i++)
        printf("%s %d ", j->preferencias[i].arma, j->preferencias[i].pontuacao);
    printf("\n");
}
// Se iguais devolve 0
// se número do jogador referenciado por data1 for inferior devolve -1
// caso contrário 1
int comparar(void *data1, void *data2)
{
    Jogador *d1 = (Jogador *)data1;
    Jogador *d2 = (Jogador *)data2;
    if (d1->numero < d2->numero)
        return (1);
    else if (d1->numero > d2->numero)
        return (-1);
    else
        return (0);
}

int compararNomes(void *data1, void *data2)
{
    Jogador *d1 = (Jogador *)data1;
    Jogador *d2 = (Jogador *)data2;
    return (-strcmp(d1->nome, d2->nome));
}

// Se iguais devolve 1 senão devolve 0
// 1º parâmetro: endereço de memória de um jogador
// 2º parâmetro: número do jogador a remover
// Devolve 1 se os códigos são iguais
// Devolve 0 caso contrário
int igual(void *data1, void *data2)
{
    Jogador *d1 = (Jogador*)data1;
    int *d2 = (int *)data2;
    if ((d1 != NULL) && (d2 != NULL))
        return (d1->numero == *d2);
    else
        return (0);
}
