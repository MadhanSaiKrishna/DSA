#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "sort.h"

void InsertionSort(ElementTypePtr A, int numElements)
{
    int i, j;
    ElementType curr;

    for (int i = 0; i < numElements; i++)
    {
        curr = A[i];
        for (int j = i; j>=-1 && curr<A[j-1]; j--)
        {
            A[j] = A[j-1];
        }
        A[j] = curr;        
    }
    
}