#include <bits/stdc++.h>
using namespace std;

void selection_sort(int *arr, int n)
{
    int min_idx;
    for (int i = 0; i < n; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_idx] >= arr[j])
            {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

void insertion_sort(int *arr, int n) 
{
    int key, j;

    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[10] = {13, 5, 11, 7, 8}, size = 5;

    selection_sort(arr, size);

    insertion_sort(arr, size);

    bubble_sort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << " " << arr[i];
    }
}