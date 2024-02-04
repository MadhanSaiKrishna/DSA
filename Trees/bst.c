#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "binarytree.h"

// Creating a Binary Search Tree without the case of repeated , twin elements

BinTree MakeNode(Element x)
{
    BinTree newNode;
    newNode = (BinTree)malloc(sizeof(struct stTreeNode));
    assert(newNode != NULL);
    newNode->e = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BST Insert(BST T, Element x)
{
    if (T == NULL)
    {
        T = MakeNode(x);
    }
    else if (x < T->e)
    {
        T->left = Insert(T->left, x);//Updating the Left node
    }
    else if (x > T->e)
    {
        T->right = Insert(T->right, x);//Updating the right node
    }
    return T;
}

Position Find(BST T, Element x)
{
    Position posNode;
    if (T == NULL)
    {
        posNode = NULL;
    }
    else if (x == T->e)
    {
        posNode = T;
    }
    else if (x < T->e)
    {
        posNode = Find(T->left, x);
    }
    else if (x > T->e)
    {

        posNode = Find(T->right, x);
    }
    return posNode;
}

void printTree(BinTree T)
{
    if (T == NULL)
    {
        return;
    }
    printf("%d\n", T->e);
    printTree(T->left);
    printTree(T->right);
}

int main()
{
    BST tree = MakeNode(10);
    tree = Insert(tree, 11);
    // printTree(tree);
    tree = Insert(tree, 9);
    // printTree(temp);
    tree = Insert(tree,8);
    tree = Insert(tree,12);
    tree = Insert(tree,7);
    tree = Insert(tree,13);
    tree = Insert(tree,6);
    tree = Insert(tree,14);
    printTree(tree);
    return 0;
}