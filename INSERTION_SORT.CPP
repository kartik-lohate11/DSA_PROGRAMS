#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void insertion_sort(int *arr, int n)
{
    int tem, k, j;

    for (int i = 1; i < n; i++)
    {
        k = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > k)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = k;
    }
}

void selection_sort(int *arr,int size)
{
  int min;
  for(int i=0;i<size;i++)
  {
    min = i;
    for(int j=i+1;j<size;j++)
    {
        if(arr[j]<arr[min])
        {
            min = j;
        }
    }
    swap(arr[i],arr[min]);
  }
}
int main()
{
    int arr[10] = {4, 3, 1, 7, 8, 9}, a, b, tem;
    int size = 6;

   // insertion_sort(arr, size);

    selection_sort(arr,size);

    for (int i = 0; i < size; i++)
    {
        cout << " " << arr[i];
    }

    return 0;
}