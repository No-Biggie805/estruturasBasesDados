/*abordagem: este excerto de codigo vem a explicar a diferença entre usar *head ou **head
ao implementar em link-lists, em resumo, usa-se mais *head se numa funcao void por exemplo
quiser apenas usar para executar o procedimento, como se fosse so em read-mode e
para **head, se quiser usar fora ja, contudo se quiser usar so *head tera de ser considerado fazer entao
"struct node *funcao(struct node *head);"
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int one;
    int two;
    struct node *next;
    // char location[100];
};
void changeHead(struct node **head)
{
}
void sort(struct node *head)
{
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));

    // now head pointing to a node stucture ( if you dereferance head you get teh first value)

    struct node *tmp = head;

    struct node **newHead = (struct node **)malloc(sizeof(struct node *));

    // New head points to a 'struct node*', which hold an addtess of another struct node

    head->one = 12; //*head->one =12; //head.one = 12 is wrong cos it is holding an address.
    // you can do it but it doesnt make sence since you dont know whats on address #12

    // now if you want head to point to old head which is on tmp at the moment
    *newHead = head;

    // now if you working with 2 linked list and you want to change the heads use below
    changeHead(newHead);

    // if you want to just sort its better and easy to use
    sort(head);

    // chack whats on head and newhead
    printf("double derefence newHead:%d\n", **newHead);
    printf("derefence newHead(its and address same ad address of head):%d\n", *newHead);
    printf("Head(its and address):%d\n", head);
    printf("derefence Head:%d\n", *head); // head->one works too
}
