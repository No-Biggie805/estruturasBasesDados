#include "Lists.h"

// printList and createnode were made possible thanks to: https://www.youtube.com/watch?v=VOpjAHCee7c
// printing a simple connected list
void printList(node_t *head)
{
  node_t *temporary = head;
  while (temporary != NULL)
  {
    printf("%d-", temporary->val);
    temporary = temporary->next;

    //  printf("\n")
  }
}

// creating new node_t node with the given value
node_t *createNode(int value) // create as a funtion, since we it to return a value in this case being an integer
{
  node_t *newNode = (node_t *)malloc(sizeof(node_t)); // dynamic allocation value point
  // dinamically allocating for a new node of type "node_t"
  // the size of the memory block allocated is the size of "node_t"
  // struct which is being determined with sizeof()

  newNode->val = value; // updating the val member, (checked corretly)
  newNode->next = NULL; // setting to NULL meaning
                        // the new node is not yet connected to any other node
  return newNode;       // return the node value
}

/*
node_t *insert_at_head(node_t **head, node_t *node_to_insert)
{
node_to_insert->next = *head;
*head = node_to_insert;
return(node_to_insert);
}
*/

// node_t *insert_new_node_at_beginning(node_t *head)
// {
//   node_t *newNode = (node_t*)malloc(sizeof(node_t));
//   newNode->val = 4;
//   newNode->next = head;
//   head = newNode;
//   return newNode;
// }

// credit: https://www.log2base2.com/data-structures/linked-list/inserting-a-node-at-the-beginning-of-a-linked-list.html
//  this funtion adds a node at the beggining of the linked list
void addFirst(node_t **head, int value) // adding as funtion as we are not expecting any returns.. Only adding to the list
{
  // create a new node
  node_t *newNode = (node_t *)malloc(sizeof(node_t));
  newNode->val = value;
  // make newNode pointing to the head node
  newNode->next = *head;
  // make newNode as the head node
  *head = newNode;
}

// credit: https://www.log2base2.com/data-structures/linked-list/inserting-a-node-at-the-end-of-a-linked-list.html
// now adding a function were add new node to the end of the linked list
void addLast(node_t **head, int value)
{
  // create a new node
  node_t *newNode = (node_t *)malloc(sizeof(node_t));
  newNode->val = value; // adding a value to our new node
  // newNode->next = *head; //we now go to the end of the list, so:
  newNode->next = NULL;
  // *head = newNode;//wrong this means we are just inserting new Head to a new empty list..
  if (*head == NULL) // if the *head is NULL then it means we have an empty list, which we do!
    *head = newNode; // declaring new *head

  // Otherwise it will be looking for the last node and then addicionally add new at the end.
  else
  {
    node_t *lastnode = *head;

    // last node next address will now be NULL
    while (lastnode->next != NULL)
    {
      lastnode = lastnode->next;
    }
    // adding the last node at the end of the list
    lastnode->next = newNode;
  }
  // free(newNode);
  
}

// // removing an integer using the given parameter
// void Pop_int(node_t **head, int value)
// {

// }

// source found on: https://prepinsta.com/c-program/for-insertion-at-the-nth-node-of-the-singly-linked-list/

// need to add by index so we can currectly measure its index to avoid issues
int getCurrSize(node_t *head) // node_t **head does not work since
{
  int size = 0;
  while (head != NULL) // while it won't reach to the end of the list..
  {
    head = head->next; // keep advancing node till the end of it

    // diffent ("!=") implementation:

    // head->next = head;//incorrect as we don't want to update our next head to be the current one

    size++; // and increment the size data
  }
  return (size); // return the size data
}

// add by index, iterative implementation
void add_by_index(node_t **head, int value, int n)
{
  int size = getCurrSize(*head); // getting the current size of list and storing locally to a value
  // int i;
  // setting dynamic allocation pointer, to store the updated node data
  node_t *newNode = (node_t *)malloc(sizeof(node_t));

  // node_t *current = *head, *tmp = NULL; // current, for current head position
  // tmp, as a temporary node
  node_t *temp = NULL;

  // allocating the data to new pointer prematurely as a new node.
  newNode->val = value;
  // setting the next of the current node to NULL as we currently consider it to be in its own standalone list
  newNode->next = NULL;

  if (n < 0 || n > size)
  {
    printf("Invalid position to insert\n");
  }
  else if (n == 0)
  {                        // if the n pos is 0 than we create new list
    newNode->next = *head; // creating new head of the list
    *head = newNode;       // setting newNode to become the new head
  }
  else
  {

    // temp used to traverse(back n forth) the Linked List
    temp = *head; // temp is what we can also consider a temporary node.

    // transverse till the nth node
    while (--n)          // goes backwards inside the list
      temp = temp->next; // advancing to the next node

    // assign newNode's next to nth node's next
    newNode->next = temp->next;

    // assign nth node's next to this new node
    temp->next = newNode;
    // newNode inserted b/w nth node
  }
  // free(newNode);
  // free(temp);
}

node_t *add_by_index_recursive(node_t *head, int pos, int value)
{
  int size = getCurrSize(head); // getting the current size of list and storing locally to a value

  // setting up dynamic allocation pointer
  node_t *newNode = (node_t *)malloc(sizeof(node_t));

  if (pos < 0 || pos > size)
    printf("invalid position to insert\n");

  else if (head == NULL || pos == 0) // if given position is 0
  {
    newNode->val = value; // dinamically allocate the data to the list
    newNode->next = head; // set node position to the beginning of the list
    head = newNode;       // store the node inside the list
  }
  else
  {
    head->next = add_by_index_recursive(head->next, pos - 1, value);
  }
  return head;
  // free(newNode);
}

node_t *add_by_index_recursive_pt2(node_t **head, int pos, int value)
{
  // could always just use node_t **head casting away the temp use but for learning porpouse
  // but i decided to use node_t **head, and then the node_t *temp pointer

  node_t *temp = NULL; // setting temporary node to become a new temporary list
  temp = *head;

  int size = getCurrSize(*head); // getting the current size of list and storing locally to a value

  // setting up dynamic allocation
  node_t *newNode = (node_t *)malloc(sizeof(node_t));

  // // allocating already the given data to the new node
  // newNode->val = value;
  // newNode->next = NULL;
  // head = newNode;
  // temp = newNode;

  if (pos < 0 || pos > size)
    printf("Invalid position to insert\n");
  else if (temp == NULL || pos == 0) // if given position is 0
  {
    newNode->val = value; // dinamically allocate the data to the list
    newNode->next = temp; // set node position to the beginning of the list
    temp = newNode;       // store the node inside the list
  }
  else
  {
    temp->next = add_by_index_recursive_pt2(&(temp->next), pos - 1, value);
    // now as we can see function takes the argument currently since we are passing as parameter
  }
  return *head = temp;
  // free(temp);
}

// calcular a media dos inteiros da lista ligada
float CalcMedia(node_t **head)
{
  // Aspectos a considerar:
  // Não interessa alocação dinâmica, retornar a lista ou alterar alguma coisa dentro da lista
  // Calcular a média de inteiros lista e retornar o valor da média da lista

  // starting ptr with the head
  node_t *temp = *head; // declare a new temporary node, and store the head inside in order to access from it
  float sum = 0.0, count = 0.0;

  while (temp != NULL) // while list is has not ended..
  {
    sum += temp->val;  // summarize all data allocated inside of the list
    temp = temp->next; // advance to the next node
    count++;           // count alongside to store the number of members we have inside the list
  }
  float media = (float)sum / count; // make an average operation

  return media; // successfully return as float
  // free(temp);
}

int Pop(node_t **head)
{
  node_t *temp;
  int result;

  temp = *head;
  // assert(temp != NULL);
  while (temp != NULL)
  {
    result = temp->val; // pulling out the data before the node is deleted
    *head = temp->next; // jump into the next node
  }
  // result = temp->val;    // pulling out the data before the node is deleted
  // *head = temp->next; //
  free(head);
  return (result);
}

// remover um inteiro presente numa determinada posição passada
// por um parâmetro(int pos)

// criar em procedimento apenas será perciso remover por index
int remove_by_index(node_t **head, int n)
{
  int i, result = -1;
  node_t *current = *head;
  node_t *tmp = NULL;

  if (n == 0)
    return Pop(head);

  for (i = 0; i < n - 1; i++)
  {
    if (current->next == NULL)
    {
      return -1;
    }
    current = current->next;
  }
  if (current->next == NULL)
  {
    return -1;
  }
  tmp = current->next;
  result = tmp->val;
  current->next = tmp->next;
  free(tmp);
  return (result);
}
