#include "main.h"

/* Function to partition the array */
int partition(int *arr, int low, int high)
{
    int pivot = low;
    int p = low + 1;
    int q = high;
    while(p <= q)
    {
        while(arr[p] <= arr[pivot])
        p++;
        while(arr[q] > arr[pivot])
        q--;
        if(p < q)
        {
            int temp = arr[p];
            arr[p] = arr[q];
            arr[q] = temp;
        }
    }
    int temp = arr[q];
    arr[q] = arr[pivot];
    arr[pivot] = temp;
    return q;
}
