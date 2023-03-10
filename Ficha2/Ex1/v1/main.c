#include "Lists.h"

int main()
{
  node_t *head = NULL;
  node_t *newNode = NULL;

  for (int i = 0; i < 5; i++)
  {
    newNode = createNode(i);
    newNode->next = head;
    head = newNode;
  }
  printf("normal list");
  printList(head); // same results just different printing
  printf("\n");

  // Now inserting at begging of the list:
  //  insert_new_node_at_beginning(head);
  printf("Adding at the begging:");
  addFirst(&head, 13);
  printList(head);
  printf("\n");

  // Now inserting at end to the list
  printf("adding at the end:");
  addLast(&head, 19);
  printList(head);
  printf("\n");

  // Adding using index
  printf("adding by index:");
  add_by_index(&head, 20, 4);
  printList(head);
  printf("\n");

  // Adding by index the recursive way
  printf("adding by index recursively:");
  add_by_index_recursive(head, 2, 30);
  printList(head);
  printf("\n");

  // Adding by index recursively, (experimental: "head" passed as parameter)
  printf("adding by index recursively, passing head as parameter:");
  add_by_index_recursive_pt2(&head, 2, 50);
  printList(head);
  printf("\n");

  // calculating the average
  printf("Calulating the average:");
  float media = CalcMedia(&head);
  printf("%.2f", media);
  printf("\n");

  // Experimental feature: Removing by index
  printf("removing by index:");
  remove_by_index(&head, 5);
  printList(head);//removes node with the 2 value
  printf("\n");

  return 0;
}