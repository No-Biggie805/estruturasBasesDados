#include <stdio.h>

// 0! = 1
// n! = n * (n-1) * (n-2) * .... * 2 * 1
//
// n! = n*(n-1)!
//
// 3! = 3*2*1 = 6

// Implementação recursiva da função factorial
int factorial3(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
        res *= i;
    return (res);
}

// Implementação recursiva da função factorial
int factorial(int n)
{
    if (n == 0)
        return (1);
    else
        return (n * factorial(n - 1));
}

// Implementação da função factorial
void factorial2(int n, int *r)
{
    *r = 1;
    for (int i = 1; i <= n; i++)
        *r *= i; // *r = *r * i;
}

// Função (int) permitindo calcular a soma de dois inteiros a partir dos
// seus endereços de memória
// Devolver 1 em caso de sucesso
// ou 0 em caso de insucesso
int soma(int *end1, int *end2, int *end3)
{
    if ((end1 != NULL) && (end2 != NULL))
    {
        *end3 = *end1 + *end2;
        return (1);
    }
    else
        return (0);
}

// Procedimento (void) permitindo calcular a soma de dois inteiros a partir dos
// seus endereços de memória
void soma2(int *end1, int *end2, int *end3, int *end4)
{
    if ((end1 != NULL) && (end2 != NULL))
    {
        *end3 = *end1 + *end2;
        *end4 = 1;
    }
    else
        *end4 = 0;
}

int main()
{
    int a = 10, b = 11, f, sucesso;
    int *ptr1; // c poderá conter um endereço (para inteiro)
               // em cada instante de tempo
    int **ptr2;

    printf("3!=%d\n", factorial(3)); // faz 3*2*1=6
    factorial2(3, &f);
    printf("3!=%d\n", f);

    soma2(&a, &b, &f, &sucesso);
    if (sucesso == 1)
        printf("%d+%d=%d\n", a, b, f); // escrever? f = 10 + 11
    else
        printf("Dados invalidos!\n");

    int res = soma(NULL, &b, &f); // não imprime nada por causa do NULL
    if (res == 1)
        printf("%d+%d=%d\n", a, b, f);
    else
        printf("Dados invalidos!\n");
    //----------------------x----------------------
    printf("a=%d b=%d\n", a, b);

    printf("endereco de a = %p\n", &a);//imprimir o endereço da variavel a
    printf("endereco de b = %p\n", &b);//imprimir o endereço da variavel b

    ptr1 = NULL; // endereço nulo

    ptr1 = &a; // atribuição do endereço da variável a

    printf("conteúdo de ptr1 = %p\n", ptr1);
    printf("endereco de ptr1 = %p\n", &ptr1);

    printf("Conteudo de a = %d\n", *ptr1); // acesso ao dado associado ao endereço presente na variável c

    printf("Conteúdo de a = %d\n", *(&a));

    *ptr1 = 12; // acesso ao conteúdo da variável a
                // e atribuição do valor inteiro 12
    printf("Conteúdo de a = %d\n", a);

    ptr2 = &ptr1; //    ptr2 ---->  ptr1 ----> a = 12
                  //                     b = 11
                  //
    // Escrita do conteúdo de a sabendo o conteúdo de d?
    printf("Conteúdo de a = %d\n", **ptr2); // consulta da variável a
    **ptr2 = 13;                            // alteração do estado da variável a
    printf("Conteúdo de a = %d\n", a);      // consulta da variável a

    return (0);
}


