#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//Create Linked List
void insert(int data) {
   // Allocate memory for new node;
   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->data = data;
   link->next = NULL;

   // If head is empty, create new list
   if(head==NULL) {
      head = link;
      return;
   }

   current = head;
   
   // move to the end of the list
   while(current->next!=NULL)
      current = current->next;
   
   // Insert link at the end of the list
   current->next = link; 
}

void display() {
   struct node *ptr = head;

   printf("\n[head] =>");
   //start from the beginning
   while(ptr != NULL) {
      printf(" %d =>",ptr->data);
      ptr = ptr->next;
   }

   printf(" [null]\n");
}

void update_data(int old, int new) {//inserting old node data and then the new one.
   int pos = 0;
   
   if(head==NULL) {
      printf("Linked List not initialized");
      return;
   } 

   current = head;//to prevent head from losing its index point we set current=head.
   while(current->next!=NULL) {//start to transverse LL
      if(current->data == old) {
         current->data = new;
         printf("\n%d found at position %d, replaced with %d\n", old, pos, new);
         return;
      }
      
      current = current->next;
      pos++;//count the position of the loop, just to point at what index it was found on.
   }
   
   printf("%d does not exist in the list\n", old);
}

int main() {
   insert(10);
   insert(20);
   insert(30);
   insert(1);
   insert(40);
   insert(56); 

   display();
   update_data(40, 44);
   display();
   
   return 0;
}