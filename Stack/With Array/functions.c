#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "functions.h"

Stack createStack(const int max_num_elements){
    assert(max_num_elements>0);
    Stack S = (Stack)malloc(sizeof(struct ststack));
    assert(S!=NULL);
    S->iMaxElements=max_num_elements;
    S->pstart = (Element)malloc(max_num_elements*sizeof(Element));
    return S;
}

void push(Stack S, Element E){
    //Stack indexing starts with 1
    if (S->iTop<S->iMaxElements-1){//Checking if there is memory for the new element in the stack
        S->pstart[++S->iTop]=E;
    }
    else
    {
        printf("\nStack is Full\n");
        exit(0);
    }
    return;    
}

void pop(Stack S){
    if (!isStackEmpty(S))
    {
        S->iTop--;
        S->iMaxElements--;
    }
    
    return;
}

int isStackEmpty(Stack S){
    return (S->iTop==-1);
}

void deleteStack(Stack S){
    if (S!=NULL)
    {
        free(S->pstart);
        free(S);
    }
        
}

int getSizeofStack(const Stack S){
    int size;
    size =  S->iTop;
    return size;
}

void printStack(const Stack S){
    for (int i = 0; i < S->iTop; i++)
    {
        printf("%c", S->pstart[i]);
    }
    
}

Element getTop(Stack S){
    Element e;
    e=S->pstart[S->iTop-1];
    return e;
}