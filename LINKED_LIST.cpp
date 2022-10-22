#include <iostream>
#include <stdlib.h>
using namespace std;

//     linked_list insertions :-

struct node
{
    int data;
    struct node *next;
};

//    LINKED LIST INSERTION :::

// 1. INSERTION After the node
struct node *inser_node(struct node *ptr, struct node *ptr_set, int elm)
{
    struct node *head = ptr;
    struct node *new_ptr = (struct node *)malloc(sizeof(struct node));
    while (ptr != ptr_set)
    {
        ptr = ptr->next;
    }
    new_ptr->data = 500;

    new_ptr->next = ptr->next;
    ptr->next = new_ptr;
    return head;
}

// 2. INSERTION at end node
struct node *inser_end(struct node *ptr, int elm)
{
    struct node *ptr1 = (struct node *)malloc(sizeof(struct node));
    struct node *head = ptr;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr1->data = elm;
    ptr->next = ptr1;
    ptr1->next = NULL;

    return head;
}

// 3. INSERTION at between linked list
struct node *inser_bet(struct node *ptr, int elm, int idx)
{
    struct node *new_ptr = (struct node *)malloc(sizeof(struct node));
    struct node *head = ptr;
    idx--;
    while (idx > 1)
    {
        ptr = ptr->next;
        idx--;
    }
    new_ptr->data = elm;

    new_ptr->next = ptr->next;
    ptr->next = new_ptr;

    return head;
}

// 4. INSERTION at front node of linked list
struct node *inser(struct node *ptr, int elm)
{
    struct node *ptr1 = (struct node *)malloc(sizeof(struct node));

    ptr1->data = elm;
    ptr1->next = ptr;

    return ptr1;
}

// 5. TRAVERSAL
void linked_list(struct node *ptr)
{
    int a;
    for (a = 0; ptr != NULL; a++)
    {
        cout << "the element = " << ptr->data << endl;
        ptr = ptr->next;
    }
}

// LINKED LIST DELETION :::
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

struct node *deletion_at_front(struct node *ptr)
{
    struct node *head = ptr;
    head = head->next;
    free(ptr);
    ptr = NULL;
    return head;
}

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

// SEARCHING at given linked list
struct node *search(struct node *ptr, int elm)
{
    while (ptr->data != elm && ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr->data == elm)
    {
        cout << "the element is here at linked list " << endl;
    }
    else
        cout << elm << " is not at linked list ";
    return 0;
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

    cout << "-::   PERFORM THE FOLLOWING OPERACTION AT THE GIVEN LINKED LIST  ::- " << endl;

    linked_list(f1);

    // INSERTION

    cout << "after the inesertion at first node " << endl;
    f1 = inser(f1, 10);
    linked_list(f1);

    cout << " inside the insertion " << endl;
    f1 = inser_bet(f1, 100, 6);
    linked_list(f1);

    cout << "insertion at end " << endl;
    f1 = inser_end(f1, 200);
    linked_list(f1);

    cout << " insertion after a  node" << endl;
    f1 = inser_node(f1, f3, 400);
    linked_list(f1);

    // DELETION

    cout << " the DELETION OPERATIONs " << endl;
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
    int elm;
    cout << "To find the element at the given linked list " << endl;
    cin >> elm;
    search(f1, elm);
    return 0;
} /*
 OUTPUT :-
 the element = 11
 the element = 12
 the element = 13
 the element = 14

 after the inesertion at first node
 the element = 10
 the element = 11
 the element = 12
 the element = 13
 the element = 14

  inside the insertion
 the element = 10
 the element = 11
 the element = 12
 the element = 13
 the element = 14
 the element = 100

 insertion at end
 the element = 10
 the element = 11
 the element = 12
 the element = 13
 the element = 14
 the element = 100
 the element = 200

  insertion after a  node
 the element = 10
 the element = 11
 the element = 12
 the element = 13
 the element = 500
 the element = 14
 the element = 100
 the element = 200 */