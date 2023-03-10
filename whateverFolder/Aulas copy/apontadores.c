#include <stdio.h>

void soma(int *a, int *b, int *c)
{
    *c = *a + *b;
}

typedef struct registo
{
    int codigo;
    char tipo[20];
    float bateria;
    float autonomia;
} mobilidade;

int main()
{
    int a = 10, b = 11, f;
    int *c; // c poderá conter um endereço (para inteiro)
            // em cada instante de tempo
            // int** d;
            // void* e;

    // mobilidade* m1;

    // soma(&a, &b , &f);
    // printf("Conteudo de f = %d\n", f);

    printf("a=%d b=%d\n", a, b);

    printf("endereco de a = %p\n", &a);
    printf("endereco de b = %p\n", &b);

    c = NULL; // endereço nulo

    c = &a; // atribuição do endereço da variável a

    printf("conteúdo de c = %p\n", c);
    printf("endereco de c = %p\n", &c);

    printf("Conteudo de a = %d\n", *c); // acesso ao dado associado ao endereço presente na variável c

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
