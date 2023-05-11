#include <stdio.h> 
#include <string.h> 
#include "grafo.h"

int main()
{
Dados D[MAX]; // Dados das localizações, meios de mobilidade elétrica e clientes
int G[MAX][MAX],i,j,n,u;

strcpy(D[0].geocodigo,"cotton.raspberry.scrabbled");
D[0].codigoMeio1 = 100;
D[0].codigoMeio2 = 105;
D[0].codigoMeio3 = 208;
D[0].codigoCliente1 = 123456789;
D[0].codigoCliente2 = 0;

strcpy(D[1].geocodigo,"notated.griddles.graver");
D[1].codigoMeio1 = 101;
D[1].codigoMeio2 = 201;
D[1].codigoMeio3 = 0;

strcpy(D[2].geocodigo,"thanks.pined.clogs");
D[2].codigoMeio1 = 110;
D[2].codigoMeio2 = 0;
D[2].codigoMeio3 = 0;

strcpy(D[3].geocodigo,"crewcut.condense.perceive");
D[3].codigoMeio1 = 111;
D[3].codigoMeio2 = 222;
D[3].codigoMeio3 = 333;

printf("Enter no. of vertices:");
scanf("%d",&n);

// example: 4

printf("\nEnter the adjacency matrix:\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&G[i][j]);

// example:
// 10 0 5 10
// 4 0 0 3
// 5 2 0 1
// 3 0 1 3

printf("\nEnter the starting node:");
scanf("%d",&u);
dijkstra(G,n,u);
return 0;
}
