#include <stdio.h>
#include <stdlib.h>
using namespace std;

// ABSTRACT DATA TYPE.  by using STRACTURE

struct array
{
    int total_size;
    int used_size;
    int *ptr;
};

void inser(struct array *arr, int tsize, int usize)
{
    arr->total_size = tsize;
    arr->used_size = usize;

    arr->ptr = (int *)malloc(tsize * sizeof(int)); // Dynamic memory allocation.
}

void get(struct array *arr1)
{
    int a, n;
    for (a = 0; a < arr1->used_size; a++)
    {
        scanf("%d", &n);
        (arr1->ptr)[a] = n;
    }
}

void show(struct array *arr2)
{
    int a;
    for (a = 0; a < arr2->used_size; a++)
    {
        printf(" %d ", (arr2->ptr)[a]);
    }
}
int main()
{
    struct array arr;
    int size, usize;

    printf("enter the size of arry \n");
    scanf("%d", &size);

    printf("enter the used size \n");
    scanf("%d", &usize);

    inser(&arr, size, usize);

    printf("enter the elements of array \n");
    get(&arr);

    printf("the elements of array \n");
    show(&arr);

    return 0;
}