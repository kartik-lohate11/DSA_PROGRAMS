#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

// Deletion a node by it's value.
struct node *deletion_val(struct node *ptr, int value)
{
    struct node *head = ptr;
    struct node *q = ptr->next;
    while (q->data != value && q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    if (q->data == value)
    {
        ptr->next = q->next;
        free(q);
    }

    return head;
}

// Deletion a node at between the given linked list.
struct node *deletion_bit(struct node *ptr, int idx)
{
    int i = 1;
    struct node *head = ptr;
    struct node *ptr1 = ptr->next;
    while (i < idx)
    {
        ptr = ptr->next;
        ptr1 = ptr1->next;
        i++;
    }
    ptr->next = ptr1->next;
    free(ptr1);
    return head;
}

// deletion a node by pertuclar node
struct node *deletion_node(struct node *ptr, struct node *nptr)
{
    struct node *head = ptr;
    struct node *q = ptr->next;

    while (ptr->next != nptr)
    {
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = q->next;
    free(q);

    return head;
}

// Deletion a front node
struct node *deletion_at_front(struct node *ptr)
{
    struct node *head = ptr;
    head = head->next;
    free(ptr);
    ptr = NULL;
    return head;
}

// deletion a last node
struct node *deletion_at_end(struct node *ptr)
{
    struct node *head = ptr;
    while ((ptr->next)->next != NULL)
    {
        ptr = ptr->next;
    }
    struct node *q = (ptr->next)->next;
    ptr->next = NULL;
    free(q);

    return head;
}

// TRAVERSAL.
void linked_list(struct node *ptr)
{
    int a;
    for (a = 0; ptr != NULL; a++)
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
    struct node *f5; // it is a new node

    f1 = (struct node *)malloc(sizeof(struct node));
    f2 = (struct node *)malloc(sizeof(struct node));
    f3 = (struct node *)malloc(sizeof(struct node));
    f4 = (struct node *)malloc(sizeof(struct node));
    f5 = (struct node *)malloc(sizeof(struct node));

    f1->data = 11;
    f1->next = f2;

    f2->data = 12;
    f2->next = f3;

    f3->data = 13;
    f3->next = f4;

    f4->data = 14;
    f4->next = NULL;

    linked_list(f1);

    cout << " after the deletion " << endl;
    f1 = deletion_at_front(f1);
    linked_list(f1);

    cout << "deletion at end " << endl;
    f1 = deletion_at_end(f1);
    linked_list(f1);

    cout << "deletion at between node " << endl;
    f1 = deletion_bit(f1, 1);
    linked_list(f1);

    cout << "delection after the node " << endl;
    f1 = deletion_node(f1, f2);
    linked_list(f1);

    cout << " deletion the node by it's value" << endl;
    f1 = deletion_val(f1, 13);
    linked_list(f1);

    return 0;
}