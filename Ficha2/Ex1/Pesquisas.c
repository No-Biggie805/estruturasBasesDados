/* Exercicios resolvidos do site: https://www.learn-c.org */
#include <stdio.h>
#include <stdlib.h>

// // /*in the following example code for dynamic allocation example we take a number we want to delimit on and then allicate with the index value
// // which will then print delimited by the pointer*/

// // #include <stdio.h>
// // #include <stdlib.h>

// // int main()
// // {

// // 	// This pointer will hold the
// // 	// base address of the block created
// // 	int* ptr;
// // 	int n, i;

// // 	// Get the number of elements for the array
// // 	printf("Enter number of elements:");
// // 	scanf("%d",&n);//Writing 7
// // 	printf("Entered number of elements: %d\n", n);

// // 	// Dynamically allocate memory using malloc()
// // 	ptr = (int*)malloc(n * sizeof(int));

// // 	// Check if the memory has been successfully
// // 	// allocated by malloc or not
// // 	if (ptr == NULL) {
// // 		printf("Memory not allocated.\n");
// // 		exit(0);
// // 	}
// // 	else {

// // 		// Memory has been successfully allocated
// // 		printf("Memory successfully allocated using malloc.\n");

// // 		// Get the elements of the array
// // 		for (i = 0; i < n; ++i) {
// // 			ptr[i] = i + 1;//goes from 1 to 7
// // 		}

// // 		// Print the elements of the array
// // 		printf("The elements of the array are: ");
// // 		for (i = 0; i < n; ++i) {
// // 			printf("%d, ", ptr[i]);//prints from 1 to 7
// // 		}
// // 	}

// // 	return 0;
// // }

// // /*

// // Exercicio de alocação dinâmica

// // */
// // #include <stdio.h>
// // #include <stdlib.h>

// // typedef struct
// // {
// //   int x;
// //   int y;
// // } point;

// // int main()
// // {
// //   point *mypoint = (point*) malloc(sizeof(point));//Dynamic allocation happens here\
// //                                                   //We create pointer by holding the point struct to memory with
// //                                                   //the malloc function(requires <stdlib.h> btw)
// //   // mypoint = NULL; //Included in the exercice, its a trap

// //   /* Dynamically allocate a new point
// //      struct which mypoint points to here */

// //   mypoint->x = 10;//Dinamically allocatiocating values by equaling to the base struct values
// //   mypoint->y = 5;
// //   printf("mypoint coordinates: %d, %d\n", mypoint->x, mypoint->y);//using the dinamic memory allocation in here..

// //   free(mypoint);//Freeing the pointer from memory to prevent leaks, thus could be reused later or else just
// //                 //utilize it first and free at the end
// //   return 0;
// // }

/*LINKED LISTS EXERCICE*/

// typedef struct node
// {
//   // creating a linked list node here.
//   int val;
//   struct node *next;
// } node_t; // correct

// void print_list(node_t *head)
// {
//   //  printing list here
//   // we are doing this by iterating over the list pointer "current" will keep track
//   // of the node we are currently printing, after printing the value of the node,
//   // we set the current node to the next one until we reach the end which "current" will change to NULL
//   node_t *current = head;

//   while (current != NULL)
//   {
//     printf("%d\n", current->val);
//     current = current->next;
//   }
// } // correct

// int pop(node_t **head)
// {
//   // removing members from the list

//   int retval = -1;
//   node_t *next_node = NULL;

//   if (*head == NULL)
//   {
//     return -1;
//   }

//   next_node = (*head)->next;
//   retval = (*head)->val;
//   free(*head);
//   *head = next_node;

//   return retval;
// }
// int remove_by_value(node_t **head, int val)
// {
//   /* TODO: fill in your code here */

//   node_t *previous, *current;

//   if (*head == NULL)
//   {
//     return -1;
//   }

//   if ((*head)->val == val)
//   {
//     return pop(head);
//   }

//   previous = *head;
//   current = (*head)->next;

//   while (current)
//   {
//     if (current->val == val) // using the member value to the local one
//                              //
//     {
//       previous->next = current->next;
//       free(current);
//       return val;
//     }
//     previous = current;
//     current = current->next;
//   }
//   return -1;
// }

// void delete_list(node_t *head)
// {
//   node_t *current = head,
//          *next = head;

//   while (current)
//   {
//     next = current->next;
//     free(current);
//     current = next;
//   }
// }

// int main(void)
// {

//   node_t *test_list = (node_t *)malloc(sizeof(node_t));

//   test_list->val = 1;
//   test_list->next = (node_t *)malloc(sizeof(node_t));
//   test_list->next->val = 2;
//   test_list->next->next = (node_t *)malloc(sizeof(node_t));
//   test_list->next->next->val = 3;
//   test_list->next->next->next = (node_t *)malloc(sizeof(node_t));
//   test_list->next->next->next->val = 4;
//   test_list->next->next->next->next = NULL;

//   remove_by_value(&test_list, 3); //"test_list": pointer object
//                                   // sending adictional value of 3
//   delete_list(test_list);
//   print_list(test_list);

//   return EXIT_SUCCESS;
// }

/*stable version*/
// typedef struct node
// {
//   int val;
//   struct node *next;
// } node_t;

// void print_list(node_t *head)
// {
//   node_t *current = head;

//   while (current != NULL)
//   {
//     printf("%d\n", current->val);
//     current = current->next;
//   }
// }

// int pop(node_t **head)
// {
//   int retval = -1;
//   node_t *next_node = NULL;

//   if (*head == NULL)
//   {
//     return -1;
//   }

//   next_node = (*head)->next;
//   retval = (*head)->val;
//   free(*head);
//   *head = next_node;

//   return retval;
// }

// int remove_by_value(node_t **head, int val)
// {
//   node_t *previous, *current;

//   if (*head == NULL)
//   {
//     return -1;
//   }

//   if ((*head)->val == val)
//   {
//     return pop(head);
//   }

//   previous = *head;
//   current = (*head)->next;
//   while (current)
//   {
//     if (current->val == val)
//     {
//       previous->next = current->next;
//       free(current);
//       return val;
//     }

//     previous = current;
//     current = current->next;
//   }
//   return -1;
// }

// void delete_list(node_t *head)
// {
//   node_t *current = head,
//          *next = head;

//   while (current)
//   {
//     next = current->next;
//     free(current);
//     current = next;
//   }
// }

// int main(void)
// {
//   node_t *test_list = (node_t *)malloc(sizeof(node_t));

//   test_list->val = 1;
//   test_list->next = (node_t *)malloc(sizeof(node_t));
//   test_list->next->val = 2;
//   test_list->next->next = (node_t *)malloc(sizeof(node_t));
//   test_list->next->next->val = 3;
//   test_list->next->next->next = (node_t *)malloc(sizeof(node_t));
//   test_list->next->next->next->val = 4;
//   test_list->next->next->next->next = NULL;

//   remove_by_value(&test_list, 3);

//   print_list(test_list);
//   delete_list(test_list);

//   return EXIT_SUCCESS;
// }

/*Código do indiano*/

// typedef struct node
// {
//   int data;
//   struct node *next; // data menber pointer, which stores addresses of the same type
// } node;

// node *createLinkList(int n);
// void DisplayList(node *head);

// int main()

// {
//   int n = 0;
//   node *HEAD = NULL; // HEAD is being store the address of the first node
//                      // currently using NULL as we have not yet created a linkded list
//   printf("\nHow many nodes: ");
//   scanf("%d", &n);
//   HEAD = createLinkList(n);
//   DisplayList(HEAD);

//   return 0;
// }

// node *createLinkList(int n)
// {
//   int i;
//   node *head = NULL; // used to store the address of the first node and then used print at the end of the program
//   node *temp = NULL;
//   node *p = NULL;

//   for (i = 0; i < n; i++)
//   {
//     // creating an individual isolated node
//     temp = (node *)malloc(sizeof(node));
//     printf("\nEnter the data for the node number: ", i++);
//     scanf("%d", &(temp->data)); //& is being used for (temp->data)...

//     temp->next = NULL;

//     // if the list is empty, then make temp ass the first node
//     if (head == NULL)
//     {
//       head = temp;
//     }
//     else
//     {
//       p = head;
//       while (p->next != NULL)
//       {
//         p = p->next;
//       }
//       p->next = temp;
//     }
//   }
// }

// void DisplayList(node *head)
// {
//   node *p = head;
//   while (p->next != NULL)
//   {
//     printf("\t%d->", p->data);
//     p = p->next;
//   }
// }

/*From video : https://www.youtube.com/watch?v=VOpjAHCee7c */

typedef struct node
{
  int value;         // initializing node value
  struct node *next; // initializing a next pointer
} node_t;            // node_t is the defenition we are gonna use across the implementation

void printList(node_t *head)
{
  node_t *temporary = head; // firstly we create a temporary pointer that is going to start storing the head of the list

  while (temporary != NULL) // while list ain't over
  {
    printf("%d - ", temporary->value); // printing the value the temporary pointer points to..
    temporary = temporary->next;       // advancing to a new node
  }
}

node_t *createNewNode(int value)
{
  node_t *result = malloc(sizeof(node_t)); // dynamic allocating the struct data
  result->value = value;                   // adding to value member, the obtained value, and storing to result
  result->next = NULL;                     // deallocating next is set to NULL
  return result;                           // return our result so i can be printed to main()
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert)
{
  node_to_insert->next = *head;//point the node_to_insert->next to head
  *head = node_to_insert;//updating head inside the function, as its gonna return as parameter
  return node_to_insert;//return the updated node
}


node_t *find_node(node_t *head, int value)
{
  node_t *tmp = head;
  while (tmp != NULL)
  {
    if (tmp->value == value) // checking if tmp->value is equal to value
      return tmp;            // return tmp if yes
    tmp = tmp->next;         // advancing to the next one inside the link list
  }
  return NULL;
}

void insert_after_node(node_t *node_to_insert_after, node_t *newnode) // Creates a node after a node to the list
{

  newnode->next = node_to_insert_after->next; //
  node_to_insert_after->next = newnode;       // setting next node to point to the newnode
}
int main()
{
  // node_t n1, n2, n3;
  // node_t *head;

  // // for static allocation
  // node_t *n1, n2, n3;
  // node_t *head;

  // for dynamic allocation
  node_t *head = NULL;
  node_t *tmp; // the tmp pointer

  // n1.value = 5;
  // n2.value = 10;
  // n3.value = 13;

  // for uncomment this Old printing
  /*
  //link them up
  head = &n3;
  n3.next = &n2;
  n2.next = &n1;
  n1.next = NULL; //so we know when to stop
  */

  // Adding new node process
  //  //link them up
  //  head = &n1;
  //  n3.next = NULL;
  //  n2.next = &n3;
  //  n1.next = &n2; //so we know when to stop

  // //adding a new node
  // node_t n4;
  // n4.value = 13;
  // n4.next = &n3;
  // n2.next = &n4;

  // head = head->next;

  // n1 = malloc(sizeof(node_t));
  // n1->value = 45;
  // n2.value = 8;
  // n3.value = 32;
  // // static allocation

  // // link them up
  // head = n1;
  // n3.next = NULL;
  // n2.next = &n3;
  // n1->next = &n2; // so we know when to stop

  // tmp = createNewNode(32);
  // head = tmp;
  // tmp = createNewNode(23);
  // tmp->next = head;//jumping to the following node
  // head = tmp;
  // tmp = createNewNode(44);
  // tmp->next = head;
  // head = tmp;

  for (int i = 0; i < 25; i++)
  {
    tmp = createNewNode(i); // creating new node using the index value
    // tmp->next = head;//jumping to next node
    // head = tmp;//storing the head value to new node

    head = insert_at_head(&head, tmp);
  }
  // print the base list:
  printf("printing out the base list:\n");
  printList(head);
  printf("\n");

  // find a specific node inside the linked list
  tmp = find_node(head, 13);
  printf("found node with the value of: %d ", tmp->value);
  printf("\n");

  //insert after our found node a new node with its own value
  insert_after_node(tmp, createNewNode(75));

  printList(head);

  free(head);

  return 0;
}