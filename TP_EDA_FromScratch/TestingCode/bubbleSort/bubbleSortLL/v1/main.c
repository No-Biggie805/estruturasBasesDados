// Licence: https://bit.ly/2JK1psc
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node_t;
int main()
{
    node_t *temp1, *temp2, *t, *newNode, *startList;
    int n, k, i, j;
    startList = NULL;
    printf("Input number of elements in the linked list?");
    scanf("%d", &n);
    printf("Input the elements in the linked list:\n");
    for (i = 1; i <= n; i++)
    {
        if (startList == NULL)// list is empty
        {
            newNode = (node_t *)malloc(sizeof(node_t));
            scanf("%d", &newNode->data);// user will insert the node data
            newNode->next = NULL;
            startList = newNode;
            temp1 = startList;
        }
        else
        {
            newNode = (node_t *)malloc(sizeof(node_t));
            scanf("%d", &newNode->data);
            newNode->next = NULL;
            temp1->next = newNode;
            temp1 = newNode;
        }
    }
    for (i = n - 2; i >= 0; i--)
    {
        temp1 = startList;
        temp2 = temp1->next;
        for (j = 0; j <= i; j++)
        {
            if (temp1->data > temp2->data)
            {
                //begin swap process
                k = temp1->data;
                temp1->data = temp2->data;
                temp2->data = k;
            }
            temp1 = temp2;
            temp2 = temp2->next;
        }
    }
    printf("Sorted order is: \n");
    t = startList;
    while (t != NULL)
    {
        printf("%d\t", t->data);
        t = t->next;
    }
}