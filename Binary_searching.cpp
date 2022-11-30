#include <iostream>
using namespace std;

// Performs the BINARY SEARCHING at given array

int binary_search(int *arr, int size, int elm)
{
    int high, low, mid, a, c = 1, m;

    low = 0;
    high = size - 1;

    for (a = 0; high >= low; a++)
    {
        mid = (high + low) / 2;

        if (arr[mid] == elm)
        {
            cout << "the found element " << elm << " at index " << mid << endl;
            break;
        }
        else if (arr[mid] > elm)
        {
            high = mid - 1;
        }
        else if (arr[mid] < elm)
        {
            low = mid + 1;
        }
        c++; // the count number of looping .
    }
    // if (size / 2 <= c)            // if the given element is not found.
    // {
    //     cout << " the element " << elm << " is not hear at array " << endl;
    // }

    cout << " taken times = " << c << " times";
    return 0;
}

int main()
{
    int arr[30], size, elm, a, b, tem;

    cout << "enter the size of array " << endl;
    cin >> size;

    cout << "enter the elements of array " << endl;
    for (a = 0; a < size; a++)
    {
        cin >> arr[a];
    }

    cout << "enter the element which you want to find :- " << endl;
    cin >> elm;

    binary_search(arr, size, elm);

    return 0;
}
/*
OUTPUT:-
  enter the elements of array
  8
  4
  9
  3
  1
  enter the element which you want to find :-
  9
  the found element 9 at index 3
   taken times = 3 times
   */
