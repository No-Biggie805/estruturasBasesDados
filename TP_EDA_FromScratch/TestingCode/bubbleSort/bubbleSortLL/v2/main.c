// // C program to implement Bubble Sort on singly linked list
#include<stdio.h>
#include<stdlib.h>

// /* structure for a node */
// struct Node
// {
// 	int data;
// 	struct Node *next;
// };

// /* Function to insert a node at the beginning of a linked list */
// void insertAtTheBegin(struct Node **start_ref, int data);

// /* Function to bubble sort the given linked list */
// void bubbleSort(struct Node *start);

// /* Function to swap data of two nodes a and b*/
// void swap(struct Node *a, struct Node *b);

// /* Function to print nodes in a given linked list */
// void printList(struct Node *start);

// int main()
// {
// 	int arr[] = {12, 56, 2, 11, 1, 90};
// 	int list_size, i;

// 	/* start with empty linked list */
// 	struct Node *start = NULL;

// 	/* Create linked list from the array arr[].
// 	Created linked list will be 1->11->2->56->12 */
// 	for (i = 0; i< 6; i++)
// 		insertAtTheBegin(&start, arr[i]);

// 	/* print list before sorting */
// 	printf("\n Linked list before sorting ");
// 	printList(start);

// 	/* sort the linked list */
// 	bubbleSort(start);

// 	/* print list after sorting */
// 	printf("\n Linked list after sorting ");
// 	printList(start);

// 	getchar();
// 	return 0;
// }


// /* Function to insert a node at the beginning of a linked list */
// void insertAtTheBegin(struct Node **start_ref, int data)
// {
// 	struct Node *ptr1 = (struct Node*)malloc(sizeof(struct Node));
// 	ptr1->data = data;
// 	ptr1->next = *start_ref;
// 	*start_ref = ptr1;
// }

// /* Function to print nodes in a given linked list */
// void printList(struct Node *start)
// {
// 	struct Node *temp = start;
// 	printf("\n");
// 	while (temp!=NULL)
// 	{
// 		printf("%d ", temp->data);
// 		temp = temp->next;
// 	}
// }

// /* Bubble sort the given linked list */
// void bubbleSort(struct Node *start)
// {
// 	int swapped, i;
// 	struct Node *ptr1;
// 	struct Node *lptr = NULL;

// 	/* Checking for empty list */
// 	if (start == NULL)
// 		return;

// 	do
// 	{
// 		swapped = 0;
// 		ptr1 = start;

// 		while (ptr1->next != lptr)
// 		{
// 			if (ptr1->data > ptr1->next->data)
// 			{
// 				swap(ptr1, ptr1->next);
// 				swapped = 1;
// 			}
// 			ptr1 = ptr1->next;
// 		}
// 		lptr = ptr1;
// 	}
// 	while (swapped);
// }

// /* function to swap data of two nodes a and b*/
// void swap(struct Node *a, struct Node *b)
// {
// 	int temp = a->data;
// 	a->data = b->data;
// 	b->data = temp;
// }

// C program to sort Linked List
// using Bubble Sort
// by swapping nodes

/* structure for a node */
struct Node {
	int data;
	struct Node* next;
} Node;

/*Function to swap the nodes */
struct Node* swap(struct Node* ptr1, struct Node* ptr2)
{
	struct Node* tmp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = tmp;
	return ptr2;
}

/* Function to sort the list */
int bubbleSort(struct Node** head, int count)
{
	struct Node** h;
	int i, j, swapped;

	for (i = 0; i <= count; i++) {

		*h = *head;
		swapped = 0;

		for (j = 0; j < count - i - 1; j++) {

			struct Node* p1 = *h;
			struct Node* p2 = p1->next;

			if (p1->data > p2->data) {

				/* update the link after swapping */
				*h = swap(p1, p2);
				swapped = 1;
			}

			*h = &(*h)->next;
		}

		/* break if the loop ended without any swap */
		if (swapped == 0)
			break;
	}
}

/* Function to print the list */
void printList(struct Node* n)
{
	while (n != NULL) {
		printf("%d -> ", n->data);
		n = n->next;
	}
	printf("\n");
}

/* Function to insert a struct Node
at the beginning of a linked list */
void insertAtTheBegin(struct Node** start_ref, int data)
{
	struct Node* ptr1
		= (struct Node*)malloc(sizeof(struct Node));

	ptr1->data = data;
	ptr1->next = *start_ref;
	*start_ref = ptr1;
}

// Driver Code
int main()
{
	int arr[] = { 78, 20, 10, 32, 1, 5 };
	int list_size, i;

	/* start with empty linked list */
	struct Node* start = NULL;
	list_size = sizeof(arr) / sizeof(arr[0]);

	/* Create linked list from the array arr[] */
	for (i = 0; i < list_size; i++)
		insertAtTheBegin(&start, arr[i]);

	/* print list before sorting */
	printf("Linked list before sorting\n");
	printList(start);

	/* sort the linked list */
	bubbleSort(&start, list_size);

	/* print list after sorting */
	printf("Linked list after sorting\n");
	printList(start);

	return 0;
}
