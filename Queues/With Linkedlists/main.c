#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int Element;

struct node
{
    int data;
    struct Node *next;
};

typedef struct node* Node;

struct stQueue{
    int Capacity;
    Node Front;
    Node Rear;
    int size;
    Element* QArray;
};

typedef struct stQueue* Queue;

Queue createQueue();
void Enque(Element, Queue);
int isFull(Queue);
int isEmpty(Queue);
Element Deque(Queue);
void printQueue(Queue);
void deleteQueue(Queue);
void clearQueue(Queue); 

Queue createQueue(){
    Queue q;
    q = (Queue)malloc(sizeof(struct stQueue));
    assert(q!=NULL);
    q->Front= NULL;
    q->Rear= NULL;
    q->size = 0;
    return q;
}

void Enque(Element x, Queue q){
    Node temp = (Node)malloc(sizeof(struct node));
    assert(temp!=NULL);
    temp->data= x;
    temp->next = NULL;
    if (q->size==0)
    {
        q->Front=q->Rear=temp;
    }
    else
    {
        q->Rear->next =temp;
        q->Rear = temp;
    }  
    q->size= q->size+1;  
}