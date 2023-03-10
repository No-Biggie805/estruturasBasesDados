#include <stdio.h>
#include <stdlib.h>

// int remove_by_index(node_t **head, int n)
// {
//     int i = 0;
//     int retval = -1;
//     node_t *current = *head;
//     node_t *temp_node = NULL;

//     if (n == 0)
//     {
//         return pop(head);
//     }

//     for (i = 0; i < n - 1; i++)
//     {

//         current = current->next;
        
//         if (current->next == NULL)
//         {
//             return -1;
//         }
//     }

//     if (current->next == NULL)
//     {
//         return -1;
//     }

//     temp_node = current->next;
//     retval = temp_node->val;
//     current->next = temp_node->next;
//     free(temp_node);

//     return retval;
// }

// // A complete working C program
// // to demonstrate deletion in
// // singly linked list
// #include <stdio.h>
// #include <stdlib.h>


// // A linked list node
// struct Node {
//     int data;
//     struct Node* next;
// };
 
// /* Given a reference (pointer to pointer) to the head of a
//    list and an int, inserts a new node on the front of the
//    list. */
// void push(struct Node** head_ref, int new_data)
// {
//     struct Node* new_node
//         = (struct Node*)malloc(sizeof(struct Node));
//     new_node->data = new_data;
//     new_node->next = (*head_ref);
//     (*head_ref) = new_node;
// }
 
// /* Given a reference (pointer to pointer) to the head of a
//    list and a key, deletes the first occurrence of key in
//    linked list */
// void deleteNode(struct Node** head_ref, int key)
// {
//     // Store head node
//     struct Node *temp = *head_ref, *prev;
 
//     // If head node itself holds the key to be deleted
//     if (temp != NULL && temp->data == key) {
//         *head_ref = temp->next; // Changed head
//         free(temp); // free old head
//         return;
//     }
 
//     // Search for the key to be deleted, keep track of the
//     // previous node as we need to change 'prev->next'
//     while (temp != NULL && temp->data != key) {
//         prev = temp;
//         temp = temp->next;
//     }
 
//     // If key was not present in linked list
//     if (temp == NULL)
//         return;
 
//     // Unlink the node from linked list
//     prev->next = temp->next;
 
//     free(temp); // Free memory
// }
 
// // This function prints contents of linked list starting
// // from the given node
// void printList(struct Node* node)
// {
//     while (node != NULL) {
//         printf(" %d ", node->data);
//         node = node->next;
//     }
// }
 
// // Driver code
// int main()
// {
//     /* Start with the empty list */
//     struct Node* head = NULL;
 
//     push(&head, 7);
//     push(&head, 1);
//     push(&head, 3);
//     push(&head, 2);
 
//     puts("Created Linked List: ");
//     printList(head);
//     deleteNode(&head, 1);
//     puts("\nLinked List after Deletion of 1: ");
//     printList(head);
//     return 0;
// }

 



