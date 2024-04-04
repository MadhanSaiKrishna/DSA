#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

void swap(int *a, int *b)
{
	int *temp = b;
	*b = *a;
	*a = *temp;
}

void heapify(int arr[], int N; int i )
{

}

void heapSort(int arr[], int N)
{

}

void printArray(int arr[], int N)
{
	for(int i = 0; i<N;i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int arr[10] = {5,8,14,2,0,-5,-23,49,-11,13};
	heapSort(arr,10);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}