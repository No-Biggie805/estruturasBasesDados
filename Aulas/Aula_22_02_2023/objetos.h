#define TAM 100

typedef struct registo
{
	int codigo;
	float distancia;
} objeto;

typedef struct reg
{
	float media;
	float maior;
} dados;

// Protótipos das operações

// Inserção de um novo objeto
// Devolve 1 em caso de sucesso ou 0 caso contrário
int inserirNovoObjeto(objeto objetos[],
					  int codigo,
					  float distancia,
					  int quantidade);

// Determinar a existência de um determinado código
// Devolve 1 se existir ou 0 caso contrário
int existe(objeto objetos[], int codigo, int quantidade);

// Alínea b)
float media(objeto objetos[], int quantidade);

// Alínea c)
float maisDistante(objeto objetos[], int quantidade);

// Alínea d)
dados calculos(objeto objetos[], int quantidade);
int guardarTxt(objeto Objetos[], int quantidade);
int lerTxt(objeto Objetos[]);
