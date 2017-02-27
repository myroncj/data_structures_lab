#include <stdio.h>
#include <stdlib.h>
 
struct node {
   struct node *prev;
   int data;
   struct node *next;
};
 
struct node *first = NULL;
void insert_at_begin(int);
void insert_after(int,int);
void insert_before(int, int);
void insert_at_end(int);
void traverse();
void delete_from_begin();
void delete_after(int);
void delete_from_end();
int count = 0;
 
int main () {
   int input, data, mid;
 
   for (;;) {
      printf("\n\n1. Insert an node at beginning of linked list.\n");
      printf("2. Insert an node after a certain element of the linked list.\n");
      printf("3. Insert an node before a certain node of the linked list.\n");
      printf("4. Insert an node at end of linked list.\n");
      printf("5. Traverse linked list.\n");
      printf("6. Delete node from beginning.\n");
      printf("7. Delete node in between.\n");
      printf("8. Delete node from end.\n");
      printf("9. Exit\n");
 
      scanf("%d", &input);
 
      if (input == 1) {
         printf("Enter value of element\n");
         scanf("%d", &data);
         insert_at_begin(data);
      }
            else if (input == 2)
      {
         printf("\nEnter value of element\n");
         scanf("%d", &data);
         printf("\nAfter which value should it be inserted?\n");
         scanf("%d", &mid);
         insert_after(data,mid);
      }
               else if (input == 3)
      {
         printf("\nEnter value of element\n");
         scanf("%d", &data);
         printf("\nBefore which value should it be inserted?\n");
         scanf("%d", &mid);
         insert_before(data,mid);
      }

      else if (input == 4) {
         printf("Enter value of element\n");
         scanf("%d", &data);
         insert_at_end(data);
      }
      else if (input == 5)
         traverse();
      else if (input == 6)
         delete_from_begin();  
      else if (input == 7)
      {
         printf("Enter the element to delete:");
         scanf("%d",&data);
         delete_after(data);
      } 
      else if (input == 8)
         delete_from_end();
      else if (input == 9)
         break;
      
      else
         printf("Please enter valid input.\n");      
   }
 
   return 0;
}
 
void insert_at_begin(int x) {
   struct node *t;
 
   t = (struct node*)malloc(sizeof(struct node));

   count++;
 
   if (first == NULL) {
      first = t;
      first->prev = NULL;
      first->data = x;
      first->next = NULL;
      return;
   }
 
   t->prev = NULL;
   t->data = x;
   t->next = first;
   first = t;
}
 
void insert_at_end(int x) {
   struct node *t, *temp;
 
   t = (struct node*)malloc(sizeof(struct node));
   count++;
 
   if (first == NULL) {
      first = t;
      first->prev = NULL;
      first->data = x;
      first->next = NULL;
      return;
   }
 
   temp = first;
 
   while (temp->next != NULL)
      temp = temp->next;   
 
   temp->next = t;
   t->prev = temp;
   t->data    = x;
   t->next    = NULL;
}

void insert_after(int x,int y)
{
   struct node *t, *q;

   q = first;

   t=(struct node*)malloc(sizeof(struct node));

   count++;

   if (first == NULL) {
      first = t;
      first->prev = NULL;
      first->data = x;
      first->next = NULL;
      return;
   }

   while(q->next != NULL && q->data != y)
   {
      q=q->next;
   }

   t->next=q->next;
   t->prev=q;
   t->data=x;
   q->next=t;

} 

void insert_before(int x,int y)
{
   struct node *t, *q;

   q=first;

   t=(struct node*)malloc(sizeof(struct node));
   count++;

   if (first == NULL) {
      first = t;
      first->prev = NULL;
      first->data = x;
      first->next = NULL;
      return;
   }

   while(q->next->next != NULL && q->next->data != y)
   {
      q=q->next;
   }

   t->next=q->next;
   t->prev=q;
   t->data=x;
   q->next=t;

} 

void traverse() {
   struct node *t;
 
   t = first;
 
   if (t == NULL) {
      printf("Linked list is empty.\n");
      return;
   }
 
   printf("There are %d elements in linked list.\n", count);
 
   while (t->next != NULL) {
      printf("%d\n", t->data);
      t = t->next;
   }
   printf("%d\n", t->data);
}
 
void delete_from_begin() {
   struct node *t;
   int n;
 
   if (first == NULL) {
      printf("Linked list is already empty.\n");
      return;
   }
 
   n = first->data;
   t = first->next;
   free(first);
   first = t;
   count--;
 
   printf("%d deleted from beginning successfully.\n", n);
}
 
void delete_from_end() {
   struct node *t, *u;
   int n;
 
   if (first == NULL) {
      printf("Linked list is already empty.\n");
      return;
   }
 
   count--;
 
   if (first->next == NULL) {
      n = first->data;
      free(first);
      first = NULL;
      printf("%d deleted from end successfully.\n", n);
      return;
   }
 
   t = first;
 
   while (t->next != NULL) {
      u = t;
      t = t->next;
   }
 
   n = t->data;
   u->next = NULL;
   free(t);
 
   printf("\n%d deleted from end successfully.\n", n);
}

void delete_after(int x)
{
   struct node *t,*u;
   int n;

   if(first == NULL)
   {
      printf("\nLinked list is empty!");
      return;
   }

   count--;

   if(first->next == NULL)
   {
      n = first->data;
      free(first);
       first = NULL;
      printf("\n%d deleted successfully!",n);
      return;
   }

   t = (struct node *)malloc(sizeof(struct node));

   t = first;

   while(t->next != NULL && t->data != x)
   {
      u = t;
      t= t->next;
   }

   if(t->link == NULL)
   {
      printf("\nNode %d not found!",x);
      return;
   }

   n=t->data;

   u->next=t->next;
   free(t);

   printf("\n%d successfully deleted!",n);

}
