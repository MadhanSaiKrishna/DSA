#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "binarytree.h"

// Creating a Binary Search Tree without the case of duplicate elements

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

BinTree Insert(BinTree T, Element x)
{
    if (T==NULL)
    {
        return MakeNode(x);
    }
    else if(x<T->e){
        T->left = Insert(T->left, x);
    }
    else if(x>T->e){
        T->right = Insert(T->right,x);
    }
    return T;
}

void preOrderTraversal_rec(BinTree T)
{
    if (T == NULL)
    {
        return;
    }
    printf("%d\n", T->e);
    preOrderTraversal_rec(T->left);
    preOrderTraversal_rec(T->right);
}

void inOrderTraversal_rec(BinTree T){
    if (T==NULL)
    {
        return;
    }
    inOrderTraversal_rec(T->left);
    printf("%d\n", T->e);
    inOrderTraversal_rec(T->right);    
}

void postOrderTraversal_rec(BinTree T){
    if (T==NULL)
    {
        return;
    }
    postOrderTraversal_rec(T->left);
    postOrderTraversal_rec(T->right);
    printf("%d\n", T->e);
    
}

BinTree search(BinTree T, int x){
    if (T==NULL || T->e == x)
    {
        return T;
    }
    else if (x<T->e)
    {
        return search(T->left,x);
    }
    else if (x>T->e)
    {
        return search(T->right,x);
    }
    
    
}




int main()
{
    BinTree tree = MakeNode(10);
    // tree = Insert(tree, 11);
    // printTree(tree);
    tree = Insert(tree, 9);
    // printTree(temp);
    // tree = Insert(tree,12);
    tree = Insert(tree,7);
    // tree = Insert(tree,6);
    // tree = Insert(tree,14);
    // tree = Insert(tree,5);
    // postOrderTraversal_rec(tree);    
    // BinTree s = search(tree, 10);
    // printf("%d", s->e);
    return 0;
}