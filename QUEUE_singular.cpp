#include <iostream>
#include <stdlib.h>
using namespace std;

struct queue
{
    int f, b;
    int *arr;
    int size;
};

int enqueue(int *arr, int &f, int &b, int size)
{
    int elm;
    if (b == size)
    {
        cout << " the queue is full " << endl;
    }
    else
    {
        cout << "enter the element " << endl;
        cin >> elm;
        b++;
        arr[b] = elm;
    }
    return 0;
}

void display(int *arr, int &f, int &b)
{
    int a;

    for (a = f + 1; a <= b; a++)
    {
        cout << a << " element = " << arr[a] << endl;
    }
}

void dequeue(int *arr, int &f, int &b)
{
    int a;
    if (f == b)
    {
        cout << " the queue is empty" << endl;
    }
    else
    {
        f++;
    }
}

int main()
{
    int a = 1;
    int ch;
    struct queue q;
    q.size = 10;
    q.f = -1;
    q.b = -1;
    q.arr = (int *)malloc(sizeof(int) * q.size);

    while (a != 0)
    {
        cout << "enter the following OPERTAIONS :" << endl;
        cout << " 1 . ENQUEUE at singular queue " << endl
             << " 2 . DEQUEUE at singular queue" << endl
             << " 3 . DISPLAY " << endl
             << " 4. exit at queue " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            enqueue(q.arr, q.f, q.b, q.size);
            break;
        case 2:
            dequeue(q.arr, q.f, q.b);
            break;

        case 3:
            display(q.arr, q.f, q.b);
            break;

        case 4:
            a = 0;
        }
    }

    return 0;
}