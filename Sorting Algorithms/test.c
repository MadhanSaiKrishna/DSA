#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "sort.h"

int main()
{
    int arr[5] = {1,8,6,4,9};
    InsertionSort(arr,5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}