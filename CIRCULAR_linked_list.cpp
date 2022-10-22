#include <iostream>
#include <stdlib.h>
using namespace std;

// CIRCULAR LINKED LIST TRAVERSAL.

struct node
{
   int data;
   struct node *next;
};

void linked_list(struct node *ptr)
{
   struct node *head = ptr;
   do
   {
      cout << "the element = " << ptr->data << endl;
      ptr = ptr->next;
   } while (ptr != head);
}

struct node *inser_at_front(struct node *ptr)
{ struct node * head = ptr;
struct node * head1 = ptr;
   struct node * new_ptr = (struct node *)malloc(sizeof(struct node));
   new_ptr->data = 100;
   while(ptr->next!=head)
   {
      ptr=ptr->next;
   }
   ptr->next = new_ptr;
   new_ptr->next = head;
   head = new_ptr;
       return head;
}

int main()
{
   struct node *f1;
   struct node *f2;
   struct node *f3;
   struct node *f4;
   int a;

   f1 = (struct node *)malloc(sizeof(struct node));
   f2 = (struct node *)malloc(sizeof(struct node));
   f3 = (struct node *)malloc(sizeof(struct node));
   f4 = (struct node *)malloc(sizeof(struct node));

   f1->data = 11;
   f1->next = f2;

   f2->data = 12;
   f2->next = f3;

   f3->data = 13;
   f3->next = f4;

   f4->data = 14;
   f4->next = f1;

   linked_list(f1);
  f1 =  inser_at_front(f1);
      linked_list(f1);


   return 0;
}
