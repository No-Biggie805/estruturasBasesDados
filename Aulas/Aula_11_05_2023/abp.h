/*                        |                  |                   
                         10                  20
		       /    \               /  \
		      5      15            15
		     / \     / \          /  \
		    3   9   12  20       14
		       /    /\          /  \
		      8    11 14       12
                                       / \
                                      11
                                     / \
				    10
				   /  \
				  9
				 / \
				8
			       / \
			      5
			     / \
			    3
	->10->5->3->9->15->12->20->11->14

*/

#define MAX 50

typedef struct registo
{int numero;
 char nome[MAX];
 struct registo* esquerda;
 struct registo* direita;
}* ABP;

// Inserção de um novo registo numa árvore binária de procura
// Devolver o endereço do registo raíz
ABP inserir(ABP abp, int numero, char nome[]);
ABP inserirRec(ABP abp, int numero, char nome[]);

// Consulta da informação de um registo contendo um número
// passado por parâmetro
// Devolver o endereço de memória do registo se existir
// Devolver NULL se não existir
ABP consultar(ABP abp, int numero);

// Quantidade de registos (versão recursiva)
int quantidadeRec(ABP abp);

// Quantidade de registos (versão iterativa)
int quantidadeIt(ABP abp);

int altura(ABP abp);