#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int Element;
typedef Element Key;

#define INVALID -5555;

struct stNode
{
    Element val;
    struct stNode *next;
};

typedef struct stNode *Node;

struct stHt
{
    Key k;
    Node *pstart;
    int size;
};

typedef struct stHt *HashTable;

Key getHash(Element e, HashTable myHt)
{
    
}

HashTable createHashTable(int iTablesize)
{
    HashTable myHt;
    myHt = (HashTable)malloc(sizeof(struct stHt));
    assert(myHt != NULL);
    myHt->pstart = (Node)malloc(iTablesize * sizeof(Node));
    myHt->size = iTablesize;
    for (int i = 0; i < iTablesize; i++)
    {
        myHt->pstart[i] = (Node)malloc(sizeof(struct stNode));
        assert(myHt->pstart[i] != NULL);
        myHt->pstart[i]->val = INVALID;//Sentinel Node
        myHt->pstart[i]->next = NULL;
    }
    return myHt;
}

Node FindInTable(Element e, HashTable myHt)
{
    Key k = getHash(e,myHt);
    if (myHt->pstart[k]!=NULL)
    {
        Node curr = myHt->pstart[k]->next;
        if (curr==NULL)
        {
            return NULL;
        }
        else
        {
            while (curr!=NULL)
            {
                if (e == curr->val)
                {
                    return curr;
                }
                else
                {
                    curr = curr->next;
                }
            }
            
        }
    }
    return NULL;
    
}

void EmptyTable(HashTable myHt)
{
    if (myHt == NULL)
    {
        return;
    }
    Node curr;
    Node next;
    for (int i = 0; i < myHt->size; i++)
    {
        curr = myHt->pstart[i];
        while (curr!=NULL)
        {
            next = curr->next;
            free(curr);
            curr = next;
        }
        myHt->pstart[i]->next = NULL;
    }
    return;
}

void DeleteTable(HashTable myHt)
{
    if (myHt == NULL)
    {
        return;
    }
    Node curr;
    Node next;
    for (int i = 0; i < myHt->size; i++)
    {
        curr = myHt->pstart[i];
        while (curr!=NULL)
        {
            next = curr->next;
            free(curr);
            curr = next;
        }
        myHt->pstart[i] = NULL;
    }
    free(myHt->pstart);
    free(myHt);
    return;    
}

int main()
{
    return 0;
}