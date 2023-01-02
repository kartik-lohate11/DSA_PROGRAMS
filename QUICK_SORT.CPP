#include <iostream>
#include <algorithm>
using namespace std;

int povit(int *arr, int l, int h)
{
    int key = arr[l];
    int count = 0;

    for (int i = l + 1; i <= h; i++)
    {
        if (key >= arr[i])
        {
            count++;
        }
    }

    int countidx = l + count;

    swap(arr[countidx], arr[l]);
    cout << " the count = " << arr[countidx] << endl;

    int i = l, j = h;

    while (i < countidx && h > countidx)
    {
        while(arr[i] <= key)
        {
            i++;
        }
        while(arr[j] > key)
        {
            j--;
        }

        if (i < countidx && j > countidx)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return countidx;
}

void quick_sort(int *arr, int l, int h)
{
    if (l >= h)
    {
        return;
    }

    int mid = povit(arr, l, h);

    cout << " mid = " << mid << endl;

    quick_sort(arr, l, mid - 1);

    quick_sort(arr, mid + 1, h);

}

int main()
{
    int arr[10] = {15, 1, 11, 7, 8, 9}, a, b, tem;
    int size = 6;
    int h = size - 1, l = 0;

    quick_sort(arr, l, h);

    for (int i = 0; i < size; i++)
    {
        cout << " " << arr[i];
    }

    return 0;
}