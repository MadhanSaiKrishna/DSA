#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

typedef int Element;

// Defining the Node
struct stNode
{
    Element data;
    struct Node *next;
};

typedef struct stNode* Node;

void insertAtBeginning(Node *head, Element x);
void insertAtEnd(Node *head, Element x);

#endif