#include <iostream>
using namespace std;

// insertation at array index by using functions

void display(int *arr, int size)
{
  int a;
  for (a = 0; a < size+1; a++)
  {
    cout << " " << arr[a];
  }
}
int inser(int *arr, int size, int elm, int idx)
{
  int a;
  if (size >= 100)
  {
    cout << " we don't have a Space " << endl;
    return -1 ;
  }
  else
  {
    for (a = size; a >= idx; a--)
    {
      arr[a + 1] = arr[a];
    }

    arr[idx] = elm;
    display(arr, size);
  }
  return 0 ;
}

int main()
{
  int arr[100], size, elm, a, idx;

  cout<<"enter the size of array "<<endl;
  cin>>size;

  cout << "enter the elements of array " << endl;
  for (a = 0; a < size; a++)
  {
    cin >> arr[a] ;
  }

  cout<<"enter the element of array "<<endl;
  cin>>elm;

  cout<<"enter the index of array "<<endl;
  cin>>idx;

  inser(arr, size, elm, idx);
  return 0;
}