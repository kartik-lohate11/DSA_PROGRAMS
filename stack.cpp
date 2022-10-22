#include <iostream>
using namespace std;

 /* make a stack and perform pop,push,display and exit
 operation with using perticular funchions */

void push(int *arr, int tem, int size, int &top)
{
    if (top == size - 1)
    {
        cout << "stack overflow" << endl;
    }
    else
    {
        cout << "enter" << endl;
        cin >> tem;
        top++;
        arr[top] = tem;
    }
}

void pop(int &top)
{
    if (top == -1)
        cout << "null stack" << endl;

    else
        top--;
}

void display(int *arr, int &top)
{
    int a;
    for (a = 0; a <= top; a++)
    {
        cout << " " << arr[a];
    }
}
int main()
{
    int arr[20], tem, top = -1, size, ch, a = 2;
    cout << " enter the size of array" << endl;
    cin >> size;

    while (a > 0)
    {
        cout << "enter the your choise " << endl
             << "1. push " << endl
             << "2. pop " << endl
             << "3. display " << endl
             << "4. exit " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            push(arr, tem, size, top);
        }
        break;

        case 2:
        {
            pop(top);
        }
        break;

        case 3:
        {
            display(arr, top);
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