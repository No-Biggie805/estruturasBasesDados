#include <stdio.h>
#define INFINITY 9999
#define MAX 4 

typedef struct registo
{char geocodigo[50];
 int codigoMeio1;
 int codigoMeio2;
 int codigoMeio3;
 int codigoCliente1;
 int codigoCliente2;
} Dados;


// Protótipos
int lerRede();
int lerMeiosClientes();
int guardarRede();
int guardarMeiosClientes();
void dijkstra(int G[MAX][MAX],int n,int startnode);

 
