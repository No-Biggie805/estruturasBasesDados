// /*in the following example code for dynamic allocation example we take a number we want to delimit on and then allicate with the index value
// which will then print delimited by the pointer*/

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {

// 	// This pointer will hold the
// 	// base address of the block created
// 	int* ptr;
// 	int n, i;

// 	// Get the number of elements for the array
// 	printf("Enter number of elements:");
// 	scanf("%d",&n);//Writing 7
// 	printf("Entered number of elements: %d\n", n);

// 	// Dynamically allocate memory using malloc()
// 	ptr = (int*)malloc(n * sizeof(int));

// 	// Check if the memory has been successfully
// 	// allocated by malloc or not
// 	if (ptr == NULL) {
// 		printf("Memory not allocated.\n");
// 		exit(0);
// 	}
// 	else {

// 		// Memory has been successfully allocated
// 		printf("Memory successfully allocated using malloc.\n");

// 		// Get the elements of the array
// 		for (i = 0; i < n; ++i) {
// 			ptr[i] = i + 1;//goes from 1 to 7
// 		}

// 		// Print the elements of the array
// 		printf("The elements of the array are: ");
// 		for (i = 0; i < n; ++i) {
// 			printf("%d, ", ptr[i]);//prints from 1 to 7
// 		}
// 	}

// 	return 0;
// }

// /*

// Exercicio de alocação dinâmica

// */
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct
// {
//   int x;
//   int y;
// } point;

// int main()
// {
//   point *mypoint = (point*) malloc(sizeof(point));//Dynamic allocation happens here\
//                                                   //We create pointer by holding the point struct to memory with
//                                                   //the malloc function(requires <stdlib.h> btw)
//   // mypoint = NULL; //Included in the exercice, its a trap

//   /* Dynamically allocate a new point
//      struct which mypoint points to here */

//   mypoint->x = 10;//Dinamically allocatiocating values by equaling to the base struct values
//   mypoint->y = 5;
//   printf("mypoint coordinates: %d, %d\n", mypoint->x, mypoint->y);//using the dinamic memory allocation in here..

//   free(mypoint);//Freeing the pointer from memory to prevent leaks, thus could be reused later or else just
//                 //utilize it first and free at the end
//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  // creating a linked list node here.
  int val;
  struct node *next;
} node_t;

void print_list(node_t *head)
{
  //  printing list here
  // we are doing this by iterating over the list pointer "current" will keep track
  // of the node we are currently printing, after printing the value of the node,
  // we set the current node to the next one until we reach the end which "current" will change to NULL
  node_t *current = head;

  while (current != NULL)
  {
    printf("%d\n", current->val);
    current = current->next;
  }
}

int pop(node_t **head)
{
  //removing members from the list 


  int retval = -1;
  node_t *next_node = NULL;

  if (*head == NULL)
  {
    return -1;
  }

  next_node = (*head)->next;
  retval = (*head)->val;
  free(*head);
  *head = next_node;

  return retval;
}

int remove_by_value(node_t **head, int val)
{
  /* TODO: fill in your code here */

  

}

int main()
{

  node_t *test_list = (node_t *)malloc(sizeof(node_t));
  test_list->val = 1;
  test_list->next = (node_t *)malloc(sizeof(node_t));
  test_list->next->val = 2;
  test_list->next->next = (node_t *)malloc(sizeof(node_t));
  test_list->next->next->val = 3;
  test_list->next->next->next = (node_t *)malloc(sizeof(node_t));
  test_list->next->next->next->val = 4;
  test_list->next->next->next->next = NULL;

  remove_by_value(&test_list, 3);

  print_list(test_list);
}