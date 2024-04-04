#ifndef _HEAPS_H_
#define _HEAPS_H_

typedef int Element;

struct stHeap{
	int size;
	int capacity;
	Element *arr;
}stHeap;

typedef struct stHeap *Heap;

//Heap Operations
Heap createHeap(int capacity);
void insert(Heap H, Element val);
Element extractMin(Heap H);
void delete(Heap H);
void heapify(Heap H, int parent);
void printHeap(Heap H);
Heap buildHeap(Element* arr);

#endif