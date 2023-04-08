#include <stdio.h>
#include "meio.h"

int menu()
{int op;
 printf("M E N U\n");
 printf("1 Inserir Meio\n");
 printf("2 Listar Meios\n");
 printf("3 Remover Meio\n");
 printf("4 Guardar Meios\n");
 printf("5 Ler Meios\n");
 printf("0 Sair\n");
 printf("Opcao:\n");
 scanf("%d",&op);
 return(op);
}

int main()
{Meio* meios = NULL; // Lista ligada vazia 
 int op, cod;
 float bat, aut;
 char tipo[50];
 do
 {
  op = menu();
  switch(op)
  {case 1: printf("Codigo?\n");
	   scanf("%d",&cod);
	   scanf("%*c"); 
	   printf("Tipo\n");
	   scanf("%[^\n]s",tipo);
	   printf("Nivel da bateria?\n");
	   scanf("%f",&bat);
	   printf("Autonomia\n");
	   scanf("%f",&aut);
           meios = inserirMeio(meios,cod,tipo,bat,aut);
	   break;
   case 2: listarMeios(meios); break;
   case 3: printf("Codigo do meio de mobilidade a remover?\n");
	   scanf("%d",&cod);
	   meios = removerMeio(meios, cod);
	   break;
   case 4: guardarMeios(meios); break;
   case 5: meios = lerMeios(); break;
  }
 } while (op!=0);


 return(0);
}
