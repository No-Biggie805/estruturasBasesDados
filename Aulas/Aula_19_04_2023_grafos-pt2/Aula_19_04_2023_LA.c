#include <stdio.h>
#include <stdlib.h>

// Representação de um grafo orientado e pesado (valores positivos)
// com 10 vértices {0,1,2,3,4.....9} no máximo
// via listas de adjacência

#define VERTICES 10

typedef struct reg
{
    int valor;
    struct reg *seguinte;
} *Pilha;

typedef struct registo
{
    int id;     // id de um vértice adjacente
    float peso; // peso da aresta permitindo transitar para o vértice
                // adjacente
    struct registo *seguinte;
} Lista, *Adjacentes;

// Inserção de uma aresta no grafo 'Grafo' com origem em v1 e
// destino em v2 e peso p
// Devolve 1 em caso de sucesso ou 0 caso caso contrário
int inserirAresta(Adjacentes Grafo[], int v1, int v2, float p)
{
    Adjacentes novo;
    if ((v1 >= 0) && (v1 < VERTICES) && (v2 >= 0) && (v2 < VERTICES) &&
        (p >= 0))
    {
        novo = (Adjacentes)malloc(sizeof(struct registo));
        novo->id = v2;
        novo->peso = p;
        novo->seguinte = Grafo[v1];
        Grafo[v1] = novo;
        return (1);
    }
    else
        return (0);
}

void listar(Adjacentes Grafo[])
{
    int i;
    Adjacentes aux;
    for (i = 0; i < VERTICES; i++)
    {
        printf("Vertice %d: ", i);
        aux = Grafo[i];
        while (aux != NULL)
        {
            printf("%d(%.2f) ", aux->id, aux->peso);
            aux = aux->seguinte;
        }
        printf("\n");
    }
}

void inicializarGrafo(Adjacentes Grafo[])
{
    int i;
    for (i = 0; i < VERTICES; i++)
        Grafo[i] = NULL;
}

// Adicionar no valor no topo da pilha 'pilha'
Pilha push(Pilha pilha, int valor)
{
    Pilha novo = (Pilha)malloc(sizeof(struct reg));
    if (novo != NULL)
    {
        novo->valor = valor;
        novo->seguinte = pilha;
        return (novo);
    }
    else
        return (pilha);
}

// Devolver o valor presente no topo da pilha 'pilha'
int top(Pilha pilha)
{
    if (pilha != NULL)
        return (pilha->valor);
    else
        return (0);
}

// Remover o valor presente no topo da pilha 'pilha'
Pilha pop(Pilha pilha)
{
    Pilha aux;
    if (pilha != NULL)
    {
        aux = pilha->seguinte;
        free(pilha);
        return (aux);
    }
    else
        return (pilha);
}

// Listagem pela ordem inversa do conteúdo da lista ligada referenciada
// pelo parâmtero 'pilha'
void listarPilha(Pilha pilha)
{
    if (pilha != NULL)
    {
        listarPilha(pilha->seguinte);
        printf("%d -> ", pilha->valor);
    }
}

// Determinar se a pilha 'pilha' está vazia
int vazia(Pilha pilha)
{
    return (pilha == NULL);
}

// Determinar a existência de um ciclo a partir do vértice 'nodo'
// Travessia em profundidade do grafo 'Grafo' a partir do vértice 'nodo'
// Devolve 1 se existir um ciclo a partir de 'nodo'
// devolve 0 caso contrário
int profundidade(Adjacentes Grafo[], int nodo)
{
    int visitados[VERTICES], i, v;
    Pilha s = NULL;
    Adjacentes aux;
    for (i = 0; i < VERTICES; i++)
        visitados[i] = 0; // 0 vértices não visitados
                          // 1 vértices visitados
    {
        if (visitados[nodo] == 0)
        {
            s = push(s, nodo);
            visitados[nodo] = 1;
            while (!vazia(s))
            {
                v = top(s);
                s = pop(s);
                // printf("%d ", v);
                aux = Grafo[v];
                while (aux != NULL)
                {
                    if (nodo == aux->id)
                        return (1);
                    if (visitados[aux->id] == 0)
                    {
                        s = push(s, aux->id);
                        visitados[aux->id] = 1;
                    }
                    aux = aux->seguinte;
                }
            }
        }
    }
    return (0);
}

// Existência de pelo menos um ciclo no grafo 'Grafo'
// Devolve 1 se existir pelo menos um ciclo
// devolve 0 caso contrário
int ciclos(Adjacentes Grafo[])
{
    int i;
    for (i = 0; i < VERTICES; i++)
        if (profundidade(Grafo, i))
            return (1);
    return (0);
}

void uniao(Adjacentes Grafo1[], Adjacentes Grafo2[], Adjacentes Grafoaux[])
{
    Adjacentes aux1;
    for (int i = 0; i < VERTICES; i++)
    {
        aux1 = Grafo1[i];
        while (aux1 != NULL)
        {
            inserirAresta(Grafoaux, i, aux1->id, aux1->peso);
            aux1 = aux1->seguinte;
        }
        aux1 = Grafo2[i];
        while (aux1 != NULL)
        {
            inserirAresta(Grafoaux, i, aux1->id, aux1->peso);
            aux1 = aux1->seguinte;
        }
    }
}

void composicao(Adjacentes Grafo1[], Adjacentes Grafo2[], Adjacentes Grafoaux[])
{
    Adjacentes aux1, aux2;
    for (int i = 0; i < VERTICES; i++)
    {
        aux1 = Grafo1[i]; // Lista dos vértices adjacentes
        while (aux1 != NULL)
        {
            aux2 = Grafo2[aux1->id];
            while (aux2 != NULL)
            {
                inserirAresta(Grafoaux, i, aux2->id, aux1->peso + aux2->peso);
                aux2 = aux2->seguinte;
            }
            aux1 = aux1->seguinte;
        }
    }
}

void converter(Adjacentes Grafo[], float Matriz[][VERTICES])
{
    int i, j;
    Adjacentes aux;
    for (i = 0; i < VERTICES; i++)
        for (j = 0; j < VERTICES; j++)
            Matriz[i][j] = 0;
    for (i = 0; i < VERTICES; i++)
    {
        aux = Grafo[i];
        while (aux != NULL)
        {
            Matriz[i][aux->id] = aux->peso;
            aux = aux->seguinte;
        }
    }
    for (i = 0; i < VERTICES; i++)
    {
        for (j = 0; j < VERTICES; j++)
            printf("%.2f ", Matriz[i][j]);
        printf("\n");
    }
}

int existeCaminhoAux(Adjacentes G[], int origem, int destino, int visitados[])
{
    int res = 0;
    Adjacentes aux;
    if (origem == destino)
        return (1);
    else
    {
        visitados[origem] = 1;
        aux = G[origem];
        while (aux != NULL)
        {
            if (visitados[aux->id] == 0)
                res = res || existeCaminhoAux(G, aux->id, destino, visitados);
            aux = aux->seguinte;
        }
        return (res);
    }
}

int existeCaminho(Adjacentes G[], int origem, int destino)
{
    int visitados[VERTICES], i;
    for (i = 0; i < VERTICES; i++)
        visitados[i] = 0;
    return (existeCaminhoAux(G, origem, destino, visitados));
}

// Determinar se vértice 'id' já foi visitado
int visitado(int sequencia[], int pos, int id)
{
    int i;
    for (i = 0; i < pos; i++)
        if (sequencia[i] == id)
            return (1);
    return (0);
}

// Listar os caminhos existentes entre dois vértices passados
// por parâmetro
void listarCaminhosAux(Adjacentes G[], int origem, int destino,
                       int sequencia[], int posicao, int pesoTotal)
{
    int i;
    Adjacentes aux;
    sequencia[posicao] = origem;
    if (origem == destino)
    {
        for (i = 0; i < posicao; i++)
            printf("%d->", sequencia[i]); // escrita de um caminho
        printf("%d (%d)\n", destino, pesoTotal);
    }
    else
    {
        aux = G[origem];
        while (aux != NULL)
        {
            if (!visitado(sequencia, posicao, aux->id))
                listarCaminhosAux(G, aux->id, destino, sequencia, posicao + 1,
                                  pesoTotal + aux->peso);
            aux = aux->seguinte;
        }
    }
}

void listarCaminhos(Adjacentes G[], int origem, int destino)
{
    int sequencia[VERTICES];
    listarCaminhosAux(G, origem, destino, sequencia, 0, 0);
}

// Obtenção do caminho com menor peso

void main()
{
    Pilha p = NULL;
    float Matriz[VERTICES][VERTICES];

    Adjacentes Grafo1[VERTICES]; // Lista de adjacência
    inicializarGrafo(Grafo1);
    Adjacentes Grafo2[VERTICES]; // Lista de adjacência
    inicializarGrafo(Grafo2);
    Adjacentes Grafo3[VERTICES]; // Lista de adjacência
    inicializarGrafo(Grafo3);
    Adjacentes Grafo4[VERTICES]; // Lista de adjacência
    inicializarGrafo(Grafo4);

    inserirAresta(Grafo1, 1, 3, 10); // Inserção da aresta com origem
                                     // no vértice 1 e destino no
                                     // vértice 3 e peso 10
    inserirAresta(Grafo1, 0, 1, 5);
    inserirAresta(Grafo1, 0, 2, 15);
    inserirAresta(Grafo1, 0, 3, 1);
    inserirAresta(Grafo1, 3, 0, 1);
    inserirAresta(Grafo1, 2, 3, 1);
    inserirAresta(Grafo1, 0, 4, 15);
    inserirAresta(Grafo1, 2, 4, 1);
    inserirAresta(Grafo1, 4, 8, 11);
    inserirAresta(Grafo1, 8, 3, 11);
    inserirAresta(Grafo1, 3, 2, 11);
    inserirAresta(Grafo1, 4, 5, 11);
    inserirAresta(Grafo1, 4, 6, 11);
    inserirAresta(Grafo1, 6, 8, 11);
    inserirAresta(Grafo1, 8, 7, 11);
    inserirAresta(Grafo1, 6, 2, 8);
    inserirAresta(Grafo1, 3, 4, 8);
    listar(Grafo1);

    listarCaminhos(Grafo1, 0, 2);
    // printf("Caminho: %d\n", existeCaminho(Grafo1,2,0));
    // converter(Grafo1, Matriz);
    /*
     inserirAresta(Grafo1,1,3,10); // Inserção da aresta com origem
                                  // no vértice 1 e destino no
                      // vértice 3 e peso 10
     inserirAresta(Grafo2,3,2,5);
     inserirAresta(Grafo2,0,2,15);
     inserirAresta(Grafo2,4,3,1);
     inserirAresta(Grafo2,7,5,11);
     inserirAresta(Grafo2,2,3,8);
     listar(Grafo2);
    */
    // uniao(Grafo1, Grafo2 , Grafo3);
    // listar(Grafo3);

    // composicao(Grafo1, Grafo2 , Grafo4);
    // listar(Grafo4);

    // printf("Existe ciclo: %d\n", ciclos(Grafo1));
    // caminhos(Grafo1,0,8);
}
