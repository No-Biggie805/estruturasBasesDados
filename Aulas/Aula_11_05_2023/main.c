#include <stdlib.h>
#include "abp.h"

int main()
{ABP abp=NULL; // Árvore binária de procura vazia

 abp = inserir(abp,10,"maria");
 abp = inserir(abp,5,"maria");
 abp = inserir(abp,20,"maria");
 abp = inserir(abp,1,"maria");
 abp = inserir(abp,15,"maria");
 abp = inserir(abp,11,"maria");
 abp = inserir(abp,8,"maria");

 abp = altura(abp);

 
 return(0);
}
