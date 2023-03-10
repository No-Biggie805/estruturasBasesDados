#include <stdio.h>
#include "objetos.h"

// Alínea b)
// Devolve a média das distância
// ou devolve -1 caso a quantidade de objetos seja 0
float media(objeto objetos[], int quantidade)
{
  int soma = 0;
  if (quantidade > 0)
  {
    for (int i = 0; i < quantidade; i++)
      soma += objetos[i].distancia;
    return (soma / quantidade);
  }
  else
    return (-1);
}

// Alínea c)
// Devolve a distância do objeto mais longe
// ou devolve -1 caso a quantidade de objetos seja 0
float maisDistante(objeto objetos[], int quantidade)
{
  int i;
  float maior = 0;
  if (quantidade > 0)
  {
    for (i = 0; i < quantidade; i++)
      if (objetos[i].distancia > maior)
        maior = objetos[i].distancia;
    return (maior);
  }
  else
    return (-1);
}

// Determinar a existência de um determinado código
// Devolve 1 se existir ou 0 caso contrário
int existe(objeto objetos[], int codigo, int quantidade)
{
  int i = 0;
  while (i < quantidade)
  {
    if (objetos[i].codigo == codigo)
      return (1);
    i++;
  }
  return (0);
}

// Inserção de um novo objeto
// Devolve 1 em caso de sucesso ou 0 caso contrário
int inserirNovoObjeto(objeto objetos[],
                      int codigo,
                      float distancia,
                      int quantidade)
{
  if (!existe(objetos, codigo, quantidade) && (quantidade < TAM))
  {
    objetos[quantidade].codigo = codigo;
    objetos[quantidade].distancia = distancia;
    return (1);
  }
  else
    return (0);
}

dados calculos(objeto objetos[], int quantidade)
{
  dados d;
  d.media = media(objetos, quantidade);
  d.maior = maisDistante(objetos, quantidade);
  return (d);
}

// Guardar os objetos em ficheiro de texto
// Devolve 1 em caso de sucesso ou 0 caso contrário
int guardarTxt(objeto Objetos[], int quantidade)
{
  FILE *fp;

  fp = fopen("dados.txt", "wt");
  if (fp != NULL)
  {
    for (int i = 0; i < quantidade; i++)
      fprintf(fp, "%d;%.2f\n", Objetos[i].codigo, Objetos[i].distancia);
    fclose(fp);
    return (1);
  }
  else
    return (0);
}

// Leitura do conteúdo do ficheiro 'dados.txt'
// Devolve como resultado a quantidade de objetos lidos
int lerTxt(objeto Objetos[])
{
  FILE *fp;
  int qt = 0;
  fp = fopen("dados.txt", "rt");
  if (fp != NULL)
  {
    while (!feof(fp))
    {
      fscanf(fp, "%d;%f\n", &Objetos[qt].codigo, &Objetos[qt].distancia);
      qt++;
    }
    fclose(fp);
    return (qt);
  }
  else
    return (0);
}
