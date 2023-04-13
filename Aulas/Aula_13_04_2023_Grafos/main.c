#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"

int main()
{Grafo g = NULL;

 criarVertice(&g,"abc.def.ghi");
 criarVertice(&g,"bc.def.ghi");
 criarVertice(&g,"bc.def.hi");
 criarAresta(g,"abc.def.ghi","bc.def.ghi",11);
 criarAresta(g,"abc.def.ghi","bc.def.hi",1);

 inserirMeio(g,"abc.def.ghi",1);
 inserirMeio(g,"abc.def.ghi",2);
 inserirMeio(g,"bc.def.ghi",3);

 printf("Vertices adjacentes a abc.def.ghi\n");
 listarAdjacentes(g,"abc.def.ghi");

 printf("Meios de transporte existentes na localizacao abc.def.ghi\n");
 listarMeios(g,"abc.def.ghi");
}
