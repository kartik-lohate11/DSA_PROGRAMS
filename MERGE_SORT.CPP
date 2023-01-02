#include <bits/stdc++.h>
using namespace std;

void Merge_Array(int *arr, int l, int h)
{
    int mid = (l + h) / 2;

    int l1 = mid - l + 1;
    int l2 = h - mid;

    int *arr1 = (int *)malloc(sizeof(l1));
    int *arr2 = (int *)malloc(sizeof(l2));

    int idx = l;
    for (int i = 0; i < l1; i++)
    {
        arr1[i] = arr[idx+i];
        
    }
    idx = mid + 1;
    for (int i = 0; i < l2; i++)
    {
        arr2[i] = arr[idx+i];
        
    }

    int idx1 = 0;
    int idx2 = 0;
    idx = l;

    while (idx1 < l1 && idx2 < l2)
    {
        if (arr1[idx1] < arr2[idx2])
        {
            arr[idx] = arr1[idx1];
            idx1++;
        }
        else
        {
            arr[idx] = arr2[idx2];
            idx2++;
        }
        idx++;
    }

    while (idx1 < l1)
    {
        arr[idx] = arr1[idx1];
        idx++;
        idx1++;
    }

    while (idx2 < l2)
    {
        arr[idx] = arr2[idx2];
        idx++;
        idx2++;
    }
}

void Merge_Sort(int *arr, int l, int h)
{
    if (l >= h)
    {
        return;
    }
    int mid = (l + h) / 2 ;

    Merge_Sort(arr, l, mid);

    Merge_Sort(arr, mid + 1, h);

    Merge_Array(arr, l, h);
}

int main()
{

    int arr[117] = {6334 ,4098 ,7968 ,4523 ,277 ,6956, 4560, 2062 ,5705 ,5743 ,879 ,5626 ,9961 ,
    491 ,2995 ,741 ,4827}, a, b, tem;
    int size = 17;

    Merge_Sort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << " " << arr[i];
    }

   // 277 491 741 879 2062 2995 4098 4523 4560 4827 5626 5705 5743 6334 6956 7968 9961



    return 0;
}