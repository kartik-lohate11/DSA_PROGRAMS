#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    struct node *next;
    int data;
};

struct node *linked_front(struct node *head, int a)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        cout << "list is full ";
    }
    else
    {
        if (head == NULL)
        {
            ptr->data = a;
            head = ptr;
            ptr->next = NULL;
        }
        else
        {
            ptr->data = a;
            ptr->next = head;
            head = ptr;
        }
    }

    return head;
}

struct node *linked_end(struct node *head, int a)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = a;
    struct node *q = head;
    if (head == NULL)
    {
        head = ptr;
        ptr->next = NULL;
    }
    else
    {
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = ptr;
        ptr->next = NULL;
    }
    return head;
}

void display(struct node *head)
{
    while (head != NULL)
    {
        cout << " " << head->data;
        head = head->next;
    }
}

struct node *linked_p(struct node *head, int elm, int p)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = elm;
    ptr->next = NULL;
    struct node *q = head;
    struct node *pxt;
    int a = 1;
    if (p == 1)
    {
        if (head == NULL)
        {
            head = ptr;
        }
        else
        {
            ptr->next = head;
            head = ptr;
        }
    }
    else
    {
        while (a < p - 1 && q->next != NULL)
        {
            q = q->next;
            a++;
        }
        pxt = q->next;

        q->next = ptr;
        ptr->next = pxt;
    }
    return head;
}

struct node *linked_del_front(struct node *head)
{
    struct node *ptr = head;
    if (head == NULL)
    {
        cout << "list is empty ";
    }
    else
    {
        head = head->next;
        delete (ptr);
    }
    return head;
}

struct node *linked_del_end(struct node *head)
{
    struct node *ptr = head;
    if (head == NULL)
    {
        cout << "list is empty ";
    }
    else
    {
        if (head->next == NULL)
        {
            head = NULL;
            delete (head);
        }
        else
        {
            while (ptr->next->next != NULL)
            {
                ptr = ptr->next;
            }
            struct node *q = ptr->next;
            ptr->next = NULL;
            delete (q);
        }
    }
    return head;
}

struct node *linked_del_p(struct node *head, int p)
{
    int a = 1;
    struct node *ptr = head;
    if (head == NULL)
    {
        cout << "list is empty ";
    }
    else
    {
        if (p == 1)
        {
            if (head->next == NULL)
            {
                head = NULL;
                delete (head);
            }
            else
            {
                head = head->next;
                delete (ptr);
            }
        }
        else
        {
            while (a < p - 1 && ptr->next != NULL)
            {
                ptr = ptr->next;
                a++;
            }
            struct node *q = ptr->next;
            ptr->next = q->next;
            delete (q);
        }
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    int ch, a = 10, elm, p;

    while (a != 0)
    {
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "enter the element " << endl;
            cin >> elm;
            head = linked_front(head, elm);
        }
        break;

        case 2:
        {
            cout << "enter the element " << endl;
            cin >> elm;
            head = linked_end(head, elm);
        }
        break;

        case 3:
        {
            display(head);
        }
        break;

        case 4:
        {

            cout << "enter the element at position ";
            cin >> elm >> p;
            head = linked_p(head, elm, p);
        }
        break;

        case 5:
        {
            head = linked_del_front(head);
        }
        break;

        case 6:
        {
            head = linked_del_end(head);
        }
        break;

        case 7:
        {
            cout << "enter the position ";
            cin >> p;
            head = linked_del_p(head, p);
        }
        break;

        default:
        {
            cout << "exit ";
            a = 0;
        }
        }
    }
    return 0;
}