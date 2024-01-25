#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int Element;

struct stQueue{
    int Capacity;
    int Front;
    int Rear;
    int size;
    Element* QArray;
};

typedef struct stQueue* Queue;

Queue createQueue(int);
void Enque(Element, Queue);
int isFull(Queue);
int isEmpty(Queue);
Element Deque(Queue);
void printQueue(Queue);
void deleteQueue(Queue);
void clearQueue(Queue);


Queue createQueue(int Maxelements){
    Queue Q;
    Q = (Queue)malloc(sizeof(Queue));
    return Q;
}


int main()
{
    return 0;
}