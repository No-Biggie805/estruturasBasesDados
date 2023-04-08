#include <stdlib.h>
#include <string.h>
#include "meio.h"


int tamanho(Meio* inicio) //Tamanho da lista ligada
{Meio* aux = inicio;
 int contador = 0;
 while (aux != NULL)
 {contador++;
  aux = aux->seguinte; // transitar para o registo seguinte
 }
 return(contador);
}

// Inserção de um novo registo no fim
// Devolve como resultado o endereço inicial da lista ligada após a inserção
Meio* inserirFim(Meio* inicio, int cod, char tipo[], float bat, float aut)
{Meio* novo = malloc(sizeof(struct registo));
 Meio* aux = inicio;
 if (novo!=NULL)
 {novo->codigo = cod;
  strcpy(novo->tipo,tipo);
  novo->bateria = bat;
  novo->autonomia = aut;
  novo->seguinte = NULL;
  if (aux==NULL) return(novo);
  else {while (aux->seguinte!=NULL) aux = aux->seguinte;
        aux->seguinte = novo; 
	  // inserção do novo registo na última posição da lista
        return(inicio);
       }
 }
 else return(inicio);
}


// Função recursiva para a inserção de um novo registo no fim da lista ligada
// Devolve como resultado o endereço inicial da lista ligada após a inserção
Meio* inserirFimRec(Meio* inicio, int cod, char tipo[], float bat, float aut)
{if (inicio==NULL) 
	return(inserirMeio(NULL,cod,tipo,bat,aut)); // inserção no início
 else {inicio->seguinte=inserirFimRec(inicio->seguinte,cod,tipo,bat,aut);
       return(inicio);
      }
}


int removerTodos(Meio* inicio) // remover todos os registos da lista ligada
{Meio* aux;
 while (inicio!=NULL)
 {aux = inicio->seguinte;
  free(inicio);
  inicio = aux;
 }
}

Meio* consultar(Meio* inicio, int cod) // consultar registo a partir do código
{
 while(inicio!=NULL)
 {if (inicio->codigo==cod) return(inicio);
  inicio=inicio->seguinte;
 }
 return(NULL);
}

float mediaAutonomia(Meio* inicio) // cálculo da autonomia média
{int soma=0, quantidade=0;
 while(inicio!=NULL)
 {soma += inicio->autonomia;
  quantidade++;
  inicio = inicio->seguinte;
 }
 if (quantidade!=0) return(soma/quantidade);
 else return(-1);
}

Meio* copiaListaLigada(Meio* inicio) // Criar uma cópia da lista ligada
{Meio* copia=NULL;
 while(inicio!=NULL)
 {copia = inserirFim(copia, inicio->codigo, 
		     inicio->tipo, inicio->bateria, inicio->autonomia);
  inicio = inicio->seguinte;
 }
 return(copia);
}


int guardarMeiosBin(Meio* inicio)
{FILE* fp;
 fp = fopen("meios.bin","wb");
 if (fp!=NULL)
 {
 Meio* aux= inicio;
 while (aux != NULL)
 {
  fwrite(aux, sizeof(struct registo), 1, fp); 
  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}

Meio* lerMeiosBin()
{FILE* fp;
 Meio* aux=NULL;
 Meio aux2;
 fp = fopen("meios.bin","rb");
 if (fp!=NULL)
 {while (!feof(fp))
  { fread(&aux2,sizeof(struct registo), 1, fp);
    aux = inserirMeio(aux, aux2.codigo, aux2.tipo, 
		           aux2.bateria, aux2.autonomia);
  }
  fclose(fp);
 }
 return(aux);
}

int guardarMeios(Meio* inicio)
{FILE* fp;
 fp = fopen("meios.txt","w");
 if (fp!=NULL)
 {
 Meio* aux= inicio;
 while (aux != NULL)
 {
  fprintf(fp,"%d;%f;%f;%s\n", aux->codigo, aux->bateria, 
	                      aux->autonomia, aux->tipo);
  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}

Meio* lerMeios()
{FILE* fp;
 int cod;
 float bat, aut;
 char tipo[50];
 Meio* aux=NULL;
 fp = fopen("meios.txt","r");
 if (fp!=NULL)
 {while (!feof(fp))
  { fscanf(fp,"%d;%f;%f;%[^\n]s\n", &cod, &bat, &aut, tipo);
    aux = inserirMeio(aux, cod, tipo, bat, aut);
  }
  fclose(fp);
 }
 return(aux);
}

// Inserção de um novo registo
Meio* inserirMeio(Meio * inicio, int cod, char tipo[], float bat, float aut)
{
 if (!existeMeio(inicio, cod))
 {Meio * novo = malloc(sizeof(struct registo));
  if (novo != NULL)
  {novo->codigo = cod;
   strcpy(novo->tipo,tipo);
   novo->bateria = bat;
   novo->autonomia = aut;
   novo->seguinte = inicio;
   return(novo);
  }
 } else return(inicio);
}

// listar na consola o conteúdo da lista ligada
void listarMeios(Meio * inicio)
{while (inicio != NULL)
 {printf("%d %s %.2f %.2f\n",inicio->codigo,inicio->tipo, 
		             inicio->bateria, inicio->autonomia);
  inicio = inicio->seguinte;
 }
}


// Determinar existência do 'codigo' na lista ligada 'inicio'
// devolve 1 se existir ou 0 caso contrário
int existeMeio(Meio* inicio, int cod)
{while(inicio!=NULL)
  {if (inicio->codigo == cod) return(1);
   inicio = inicio->seguinte;
  }
 return(0);
}

/*
Meio* removerMeio(Meio* inicio, int cod) // Remover um meio a partir do seu código
{while (inicio!=NULL)
 {if (inicio->codigo==cod) 
	 {aux = inicio->seguinte;
          free(inicio);
	  return(aux);
	 }
  else {inicio = removerMeio(inicio->seguinte,cod);
	return(inicio);
       }
 }
}
*/

// Remover um meio a partir do seu código{
Meio* removerMeio(Meio* inicio, int cod) 
{
 Meio *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL);
 else if (atual->codigo == cod) // remoção do 1º registo
 {aux = atual->seguinte;
  free(atual);
  return(aux);
 }
 else
 {while ((atual!=NULL)&&(atual->codigo!=cod)) 
  {anterior = atual;
   atual = atual->seguinte;
  }
  if (atual==NULL) return(inicio);
  else
  {anterior->seguinte = atual->seguinte;
   free(atual);
   return(inicio);
  }
 }
}





