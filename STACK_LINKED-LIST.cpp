#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *push(struct node *head, int a)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        cout << " stack is full ";
    }
    else
    {
        if (head == NULL)
        {
            head = ptr;
            ptr->next = NULL;
            ptr->data = a;
        }
        else
        {
            ptr->next = head;
            head = ptr;
            ptr->data = a;
        }
    }
    return head;
}

struct node *pop(struct node *head)
{
    struct node *ptr = head;
    if (ptr == NULL)
    {
        cout << " stack is empty ";
    }
    else
    {
        head = head->next;
        delete (ptr);
    }
    return head;
}

void display(struct node *head)
{
    cout << " display ";
    while (head != NULL)
    {
        cout << " the element = " << head->data << endl;
        head = head->next;
    }
}

int main()
{
    int a = 11, ch, elm;
    struct node *head = NULL;

    while (a != 0)
    {
        cout << "enter the chooes " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            cout << "enter the element " << endl;
            cin >> elm;
            head = push(head, elm);
        }
        break;

        case 2:
        {
            head = pop(head);
        }
        break;

        case 3:
        {
            display(head);
        }
        break;

        case 4:
        {
            cout << "exit ";
            a = 0;
        }
        }
    }
    return 0;
}