#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int Element;

struct node
{
    Element data;
    struct Node *next;
};

typedef struct node* Node;

struct stQueue{
    int Capacity;
    Node Front;
    Node Rear;
    int size;
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

int isFull(Queue q){
    int fulled;
    if (q->size==q->Capacity)
    {
        fulled = 1;
    }
    return fulled;
}

int isEmpty(Queue q){
    return (q->size==0);
}

Element Deque(Queue q){
    Element e;
    if (q->size==0)
    {
        printf("No Elements to Deque\n");
        exit(0);
    }
    else
    {
        Node temp = q->Front;
        q->Front = q->Front->next;
        e = temp->data  ;
        free(temp);
        q->size--;
    }
    
    return e;
}
void printQueue(Queue q){
    
}