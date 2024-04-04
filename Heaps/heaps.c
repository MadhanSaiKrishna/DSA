#include "heaps.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <inttypes.h>
#include <math.h>
#include <string.h>

#define INVALID -55555;

void swap(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

Heap createHeap(int capacity)
{
	Heap H;
	assert(capacity>0);
	H = (Heap)malloc(sizeof(Heap));
	assert(H!=NULL);
	H->size = 0;
	H->capacity = capacity;
	H->arr = (int*)malloc(H->capacity*sizeof(int));
	assert(H->arr!=NULL);
	return H;
}

bool isFull(Heap H)
{
	return (H->size>=H->capacity);
}

bool isEmpty(Heap H)
{
	return (H->size==0);
}

void insert(Heap H, Element val)
{
	if(!isFull(H))
	{
		H->arr[H->size++] = val;
		int i = H->size - 1;
		
		while(i>0 && H->arr[i]<H->arr[(i-1)/2])
		{
				if(H->arr[i]< H->arr[(i-1)/2])
				{
					swap(&H->arr[i], &H->arr[(i-1)/2]);
					i = (i-1)/2;
				}
				else 
				{
					return;
				}		
		}
	}
}

void heapify(Heap H, int parent)
{
	if(isEmpty(H))
	{
		return;
	}
	int smallest = parent;
	int left = 2*parent + 1;
	int right = 2*parent +2;
	if(left<H->size && H->arr[left]<H->arr[smallest])
	{
		swap(&H->arr[left], &H->arr[smallest]);
		smallest = left;
	}
	else if(right < H->size && H->arr[right] < H->arr[smallest])
	{
		swap(&H->arr[right], &H->arr[smallest]);
		smallest = right;
	}
	if(smallest!=parent)
	{
		heapify(H, smallest);
	}
	
}
//In heaps we can only delete the root element
void delete(Heap H)
{
	Element temp = H->arr[0];
	H->arr[0] = H->arr[H->size-1];
	H->arr[H->size-1] = temp; //Swapping the root element with the last element
	// => Deleting the root element and storing at the end 
	H->size--;
	// heapify(H,0);
	int i = 0;
	int left = 2*i + 1;
	int right = 2*i + 2;
	int small = i;
	while(true)
	{
		left = 2*i +1;
		right = 2*i+2;
		if(left > H->size || right > H->size)
		{
			break;
		}	
		// printf("Hello\n");	
		if(left < H->size && H->arr[small]>H->arr[left])
		{
			swap(&H->arr[small], &H->arr[left]);
			small = left;
			
		}
		else if(right < H->size && H->arr[small] > H->arr[right])
		{
			swap(&H->arr[small], &H->arr[right]);
			small = right;
		}

		if (small == i)
		{
			break;
		}
		i = small;
	}
	return;
}

Element extractMin(Heap H)
{
	Element val = H->arr[0];
	delete(H);
	return val;
}

void printHeap(Heap H)
{
	for (int i = 0; i < H->size; ++i)
	{
		printf("%d ",H->arr[i]);
	}
}

// Heap buildHeap(Element* arr)
// {
	
// }

int main()
{
	Heap myHeap = createHeap(10);
	insert(myHeap, 81);
	insert(myHeap, 11);
	
	insert(myHeap, 8);
	insert(myHeap, 2);
	 insert(myHeap, 1);
	 insert(myHeap, 10);
	printf("%d\n" , extractMin(myHeap));
	printf("%d\n" , extractMin(myHeap));
	// printHeap(myHeap);
	return 0;
}