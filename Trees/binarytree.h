#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

typedef int Element;

struct stTreeNode
{
    Element e;
    struct stTreeNode *left;
    struct stTreeNode *right;
};

typedef struct stTreeNode *BST;
typedef BST BinTree;
typedef BinTree Position;

#endif