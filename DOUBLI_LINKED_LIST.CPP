#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *pvr;
};

struct node *inser_at_front(struct node *head, int elm)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        cout << " list is full";
    }
    else
    {
        ptr->data = elm;
        ptr->pvr = NULL;
        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
        }
        else
        {
            ptr->next = head;
            head->pvr = ptr;
            head = ptr;
        }
    }
    return ptr;
}

struct node *inser_at_end(struct node *head, int elm)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *q = head;
    if (ptr == NULL)
    {
        cout << " list is full";
    }
    else if (head == NULL)
    {
        ptr->data = elm;
        ptr->next = ptr->pvr = NULL;
        head = ptr;
    }
    else
    {
        ptr->data = elm;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = ptr;
        ptr->pvr = q;
        ptr->next = NULL;
    }

    return head;
}

struct node *inser_at_position(struct node *head, int elm, int p)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    int a = 1;
    struct node *q = head;
    if (ptr == NULL)
    {
        cout << " list is full";
    }
    else if (p == 1)
    {
        ptr->data = elm;
        ptr->pvr = NULL;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = NULL;
        }
        else
        {
            ptr->next = head;
            head->pvr = ptr;
            head = ptr;
        }
    }

    else
    {
        ptr->data = elm;
        while (p > a + 1 && q->next != NULL)
        {
            q = q->next;
            a++;
        }
        if (q->next == NULL)
        {
            cout << " invalid choise ";
        }
        else
        {

            struct node *pre = q->next;
            q->next = ptr;
            ptr->pvr = q;
            ptr->next = pre;
            pre->pvr = ptr;
        }
    }

    return head;
}

void display(struct node *head)
{
    while (head != NULL)
    {
        cout << " the element = " << head->data << " ";
        head = head->next;
    }
}

int main()
{
    struct node *head = NULL;
    int a = 11, ch, elm, p;

    cout << "enter the operation " << endl;
    cout << "1. insertion at front " << endl
         << " 2. insertion at end " << endl
         << " 3. insertion at specifice position " << endl
         << " 4. display " << endl
         << " 5. exit ";
    while (a != 0)
    {
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "enter the element ";
            cin >> elm;
            head = inser_at_front(head, elm);
        }
        break;

        case 2:
        {
            cout << "enter the element ";
            cin >> elm;
            head = inser_at_end(head, elm);
        }
        break;

        case 3:
        {
            cout << "enter the element & position ";
            cin >> elm >> p;
            head = inser_at_position(head, elm, p);
        }
        break;

        case 4:
        {
            display(head);
        }
        break;

        case 5:
        {
            cout << " exit ";
            a = 0;
        }
        }
    }

    return 0;
}