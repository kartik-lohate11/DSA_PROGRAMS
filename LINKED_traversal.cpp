#include <iostream>
#include <stdlib.h>
using namespace std;

// LINKED LIST TRAVERSAL.

struct node
{
    int data;
    struct node *next;
};

void linked_list(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout << "the element = " << ptr->data << endl;
        ptr = ptr->next;
    }
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
    f1->next = f2;

    f2->data = 12;
    f2->next = f3;

    f3->data = 13;
    f3->next = f4;

    f4->data = 14;
    f4->next = NULL;

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