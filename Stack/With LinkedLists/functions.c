#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "functions.h"

Stack createStack()
{
    Stack S;
    S = (Stack)malloc(sizeof(struct stStack));
    assert(S != NULL);
    S->L = (Node)malloc(sizeof(struct stNode));;
    assert(S->L != NULL);
    S->size = 0;
    return S;
}

void push(Stack S, Element x)
{
    Node newNode = (Node)malloc(sizeof(struct stNode));
    assert(newNode != NULL);
    newNode->data = x;
    newNode->next = S->L;
    S->L = newNode;
    S->size++;
}

Element pop(Stack S)
{
    if (S->size == 0)
    {
        printf("No Elements to POP\n");
        exit(0);
    }
    else
    {
        Element e;
        Node temp = S->L->next;
        e = S->L->data;
        free(S->L);
        S->L = temp;
        S->size--;
        return e;
    }
}

void viewTop(Stack S)
{
    if (S->size>0)
    {
        printf("%d\n", S->L->data);
    }
    else
    {
        printf("NO elements in the Stack\n");
        exit(0);
    }
    
    
}