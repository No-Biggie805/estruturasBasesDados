#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"

int main()
{
    Grafo *g = NULL;

    //--------------------------------------x---------------------------------------------------------------------------------
    // inserir coordenadas
    criarVertice(&g, "abc.def.ghi");                 // cria v1
    criarVertice(&g, "bc.def.ghi");                  // cria v2
    criarVertice(&g, "bc.def.hi");                   // cria v3
    criarAresta(g, "abc.def.ghi", "bc.def.ghi", 11); // cria a1(needs criarVertice Params to continue)
                                                     // Parametros:
                                                     // g-> head
                                                     //"abc.def.ghi"-> vOrigem
                                                     //"bc.def.ghi"-> vDestino
                                                     // 11-> peso
    criarAresta(g, "abc.def.ghi", "bc.def.hi", 1); // cria a2, muda destino
    criarAresta(g, "abc.def.ghi", "abc.def.ghi", 3);

    //--------------------------------------x---------------------------------------------------------------------------------
    // inserir meios
    inserirMeio(g, "abc.def.ghi", 1); // inserir meio 1, o que sim estas funcoes sao separadas do q esta em cima
    inserirMeio(g, "abc.def.ghi", 2);
    inserirMeio(g, "bc.def.ghi", 3);

    // //--------------------------------------x---------------------------------------------------------------------------------
    // escrever dados
    printf("Vertices adjacentes a abc.def.ghi\n");
    listarAdjacentes(g, "abc.def.ghi"); // listar as coordenadas

    printf("Meios de transporte existentes na localizacao abc.def.ghi\n");
    listarMeios(g, "abc.def.ghi");
}
