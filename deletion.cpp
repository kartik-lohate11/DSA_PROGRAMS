#include <iostream>
using namespace std;

// deletion at array index by using function

void display(int *arr, int size)
{
    int a;
    for (a = 0; a < size - 1; a++)
    {
        cout << " " << arr[a];
    }
}

int des(int *arr, int idx, int size)
{
    int a;
    if (idx <= -1 && idx >= size)
    {
        cout << " the has less sapce -1 " << endl;
        return 0;
    }
    else
    {
        for (a = idx; a <= size; a++)
        {
            arr[a] = arr[a + 1];
        }
        display(arr, size);
    }
    return 0;
}

int main()
{
    int arr[10], size, idx, a;

    cout << "enter the size of array " << endl;
    cin >> size;

    cout << "enter the elements of array " << endl;
    for (a = 0; a < size; a++)
    {
        cin >> arr[a];
    }

    cout << "enter the index of array for removing " << endl;
    cin >> idx;

    des(arr, idx, size);

    return 0;
}