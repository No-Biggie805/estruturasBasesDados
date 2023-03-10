#include <stdio.h>
int soma(int *end1, int *end2, int *end3)
{
    int resultado;
    int valor1, valor2;

    if ((end1 != NULL) && (end2 != NULL))
    {

        valor1 = *end1;
        valor2 = *end2;
        resultado = valor1 + valor2;
        *end3 = resultado;

        return (1);
    }

    else
        return (0);
}

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

// implementação recursiva da funçao factorial
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
        return (n * factorial(n--));
}

// implementação da procedimento do factorial
void factorial2(int n, int *r)
{
    *r = 1;
    for (int i = 1; i <= n; i++) //
    {
        *r *= i; //*r = *r * i, não será apontador no i
    }
}

int factorial3(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }
    return (res);
}

// void soma(int *a, int *b, int *c)
// {
//     *c = *a + *b;
// }

int main()
{
    int a = 10, b = 11, f;
    int *ptr1; // c poderá conter um endereço (para inteiro)
               // em cada instante de tempo
               // int** d;
               // void* e;
    int **ptr2;
    int res;

    res = soma(NULL, &b, &f);
    if (res == 1)
        printf("%d+%d=%d\n", a, b, f);
    else
        printf("Dados invalidos!\n");

    // mobilidade* m1;

    // soma(&a, &b , &f);
    // printf("Conteudo de f = %d\n", f);

    printf("a=%d b=%d\n", a, b);

    printf("endereco de a = %p\n", &a);
    printf("endereco de b = %p\n", &b);

    ptr1 = NULL; // endereço nulo

    ptr1 = &a; // atribuição do endereço da variável a

    printf("conteúdo de ptr1 = %p\n", ptr1);
    printf("endereco de ptr1 = %p\n", &ptr1);

    printf("Conteudo de a = %d\n", *ptr1); // acesso ao dado associado ao endereço presente na variável c
    printf("Conteudo de a = %d\n", *(&a));

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

        /*
    printf("Conteúdo de a = %d\n", *(&a) );

    *c = 12;
    printf("Conteúdo de a = %d\n", a );

    d = &c;   //    d ---->  c ----> a = 12
          //                     b = 11
          //
    // Escrita do conteúdo de a sabendo o conteúdo de d?
    printf("Conteúdo de a = %d\n", **d);
   */
    return (0);
}
