#include "Lists.h"


// // printing a simple connected list
// void printList(node_t *head)
// {
//   node_t *temporary = head;
//   while (temporary != NULL)
//   {
//     printf("%d-", temporary->val);
//     temporary = temporary->next;

//     //  printf("\n")
//   }
// }

// // creating new node_t node with the given value
// node_t *createNode(int value) // create as a funtion, since we it to return a value in this case being an integer
// {
//   node_t *newNode = (node_t *)malloc(sizeof(node_t)); // dynamic allocation value point
//   // dinamically allocating for a new node of type "node_t"
//   // the size of the memory block allocated is the size of "node_t"
//   // struct which is being determined with sizeof()

//   newNode->val = value; // updating the val member, (checked corretly)
//   newNode->next = NULL; // setting to NULL meaning
//                         // the new node is not yet connected to any other node
//   return newNode;       // return the node value
// }

// /*
// node_t *insert_at_head(node_t **head, node_t *node_to_insert)
// {
// node_to_insert->next = *head;
// *head = node_to_insert;
// return(node_to_insert);
// }
// */

// // node_t *insert_new_node_at_beginning(node_t *head)
// // {
// //   node_t *newNode = (node_t*)malloc(sizeof(node_t));
// //   newNode->val = 4;
// //   newNode->next = head;
// //   head = newNode;
// //   return newNode;
// // }

// // this funtion adds a node at the beggining of the linked list
// void addFirst(node_t **head, int value) // adding as funtion as we are not expecting any returns.. Only adding to the list
// {
//   // create a new node
//   node_t *newNode = (node_t *)malloc(sizeof(node_t));
//   newNode->val = value;
//   // make newNode pointing to the head node
//   newNode->next = *head;
//   // make newNode as the head node
//   *head = newNode;
// }

// // now adding a function were add new node to the end of the linked list
// void addLast(node_t **head, int value)
// {
//   // create a new node
//   node_t *newNode = (node_t *)malloc(sizeof(node_t));
//   newNode->val = value; // adding a value to our new node
//   // newNode->next = *head; //we now go to the end of the list, so:
//   newNode->next = NULL;
//   // *head = newNode;//wrong this means we are just inserting new Head to a new empty list..
//   if (*head == NULL) // if the *head is NULL then it means we have an empty list, which we do!
//     *head = newNode; // declaring new *head

//   // Otherwise it will be looking for the last node and then addicionally add new at the end.
//   else
//   {
//     node_t *lastnode = *head;

//     // last node next address will now be NULL
//     while (lastnode->next != NULL)
//     {
//       lastnode = lastnode->next;
//     }
//     // adding the last node at the end of the list
//     lastnode->next = newNode;
//   }
// }

// // // removing an integer using the given parameter
// // void Pop_int(node_t **head, int value)
// // {

// // }

// int Pop(node_t **headRef)
// {
//   node_t *head;
//   int result;

//   head = *headRef;
//   assert(head != NULL);
//   result = head->val;    // pulling out the data before the node is deleted
//   *headRef = head->next; //

//   free(head);
//   return (result);
// }

// int remove_by_index(node_t **head, int n)
// {
//   int i, result = -1;
//   node_t *current = *head;
//   node_t *tmp = NULL;

//   if (n == 0)
//     return Pop(head);

//   for (i = 0; i < n-1; i++)
//   {
//     if (current->next==NULL)
//     {
//       return -1;
//     }
//     current = current->next;
//   }
//   if (current->next==NULL)
//   {
//     return -1;
//   }
//   tmp = current->next;
//   result = tmp->val;
//   current->next=tmp->next;
//   free(tmp);
//   return(result);
// }

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
  printList(head); // same results just different printing
  printf("\n");

  // Now inserting at begging of the list:
  //  insert_new_node_at_beginning(head);
  addFirst(&head, 13);
  printList(head);
  printf("\n");

  // Now inserting at end to the list
  addLast(&head, 19);
  printList(head);
  printf("\n");

  //Experimental feature: Removing by index
  remove_by_index(&head, 5);
  printList(head);
  printf("\n");

  return 0;
}