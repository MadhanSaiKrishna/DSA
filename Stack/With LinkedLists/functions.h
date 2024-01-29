#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

typedef int Element;

struct stNode{
    Element data;
    struct stNode* next;
};

typedef struct stNode* Node;

struct stStack
{
    Node L;
    int size;
};


typedef struct stStack* Stack;

Stack createStack();
void push(Stack, Element);
Element pop(Stack);
void viewTop(Stack);

#endif