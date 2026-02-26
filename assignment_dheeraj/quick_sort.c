#include "main.h"

/* Function to sort the array in quick sort method */
int quick_sort( int *arr, int low, int high )
{
    if(low < high)
    {
       int  index = partition(arr,low,high);
        quick_sort( arr, low, index - 1);
        quick_sort( arr, index + 1, high);
    }
}
