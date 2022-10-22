#include <iostream>
#include <stdlib.h>
using namespace std;

// DOUBLY LINKED LIST TRAVERSAL.

struct node
{
   int data;
   struct node *next;
   struct node *pri;
};

struct node *deletion(struct node *ptr)
{
   struct node *head = ptr;
   struct node *q = ptr->next;
   ptr = ptr->next;
 q->pri=NULL;
   free(head);
   return ptr; }

struct node * inser(struct node * ptr)
{
   struct node * nptr = (struct node *)malloc(sizeof(struct node));
   nptr->data = 100;
   ptr->pri = nptr;
   nptr->next = ptr;
   nptr->pri=NULL;
   
   return nptr;
}

void linked_list(struct node *ptr)
{
   do
   {
      cout << "the element = " << ptr->data << endl;
      ptr = ptr->next;
   } while (ptr != NULL);
}

int main()
{
   struct node *f1;
   struct node *f2;
   struct node *f3;
   struct node *f4;

   f1 = (struct node *)malloc(sizeof(struct node));
   f2 = (struct node *)malloc(sizeof(struct node));
   f3 = (struct node *)malloc(sizeof(struct node));
   f4 = (struct node *)malloc(sizeof(struct node));

   f1->data = 11;
   f1->pri = NULL;
   f1->next = f2;

   f2->data = 12;
   f2->pri = f1;
   f2->next = f3;

   f3->data = 13;
   f3->next = f4;
   f3->pri = f2;

   f4->data = 14;
   f4->next = NULL;
   f4->pri = f3;

   linked_list(f1);
   cout<<"new node "<<endl;
   f1 = inser(f1);
   linked_list(f1);

    cout << "deletion at front " << endl;
   f1 = deletion(f1);
   linked_list(f1);

   return 0;
}
/*
OUTPUT :-
the element = 11
the element = 12
the element = 13
the element = 14
*/