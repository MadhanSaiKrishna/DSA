#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "functions.h"

void insertAtBeginning(Node *head, Element x)
{
    Node newhead;
    newhead=(Node)malloc(sizeof(Node));
    assert(newhead!=NULL);
    newhead->data=x;
    newhead->next = *head;
    *head= newhead;
}

void insertAtEnd(Node *head, Element x){
    Node newNode = (Node)malloc(sizeof(Node));
    assert(newNode!=NULL);
    newNode->data = x;
    newNode->next = NULL;
    Node temp = *head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

