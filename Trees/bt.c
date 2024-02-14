#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

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
    if (T == NULL)
    {
        return MakeNode(x);
    }
    else if (x < T->e)
    {
        T->left = Insert(T->left, x);
    }
    else if (x > T->e)
    {
        T->right = Insert(T->right, x);
    }
    return T;
}

BinTree Insert_iterative(BinTree T, int x)
{
    if (T==NULL)
    {
        return MakeNode(x);
    }
    while (T!=NULL)
    {
        if (x<T->left->e)
        {
            T =  T->left;
        }
        else if (x>T->right->e)
        {
            T = T->right;
        }        
    }
    T = MakeNode(x);
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

void inOrderTraversal_rec(BinTree T)
{
    if (T == NULL)
    {
        return;
    }
    inOrderTraversal_rec(T->left);
    printf("%d\n", T->e);
    inOrderTraversal_rec(T->right);
}

void postOrderTraversal_rec(BinTree T)
{
    if (T == NULL)
    {
        return;
    }
    postOrderTraversal_rec(T->left);
    postOrderTraversal_rec(T->right);
    printf("%d\n", T->e);
}

BinTree search(BinTree T, int x)
{
    if (T == NULL || T->e == x)
    {
        return T;
    }
    else if (x < T->e)
    {
        return search(T->left, x);
    }
    else if (x > T->e)
    {
        return search(T->right, x);
    }
}

BinTree search_iterative(BinTree T, int x)
{
    if (T == NULL)
    {
        return NULL;
    }
    else
    {
        while (T != NULL)
        {
            if (x < T->left->e)
            {
                T = T->left;
            }
            else if (x > T->right->e)
            {
                T = T->right;
            }
            else if (x == T->e)
            {
                return T;
            }
        }
    }
}

BinTree minOfTree(BinTree T)
{
    BinTree min;
    if (T == NULL)
    {
        return NULL;
    }
    min = T;
    BinTree left_min = minOfTree(T->left);

    if (left_min != NULL && left_min->e < min->e)
    {
        min = left_min;
    }
    BinTree right_min = minOfTree(T->right);
    if (right_min != NULL && right_min->e < min->e)
    {
        min = right_min;
    }
    return min;
}

BinTree maxOfTree(BinTree T)
{
    BinTree max;
    if (T == NULL)
    {
        return NULL;
    }
    max = T;
    BinTree left_max = maxOfTree(T->left);
    if (left_max != NULL && left_max->e > max->e)
    {
        max = left_max;
    }
    BinTree right_max = maxOfTree(T->right);
    if (right_max != NULL && right_max->e > max->e)
    {
        max = right_max;
    }
    return max;
}

int height(BinTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    int left_ht = height(T->left);
    int right_ht = height(T->right);
    return (left_ht > right_ht) ? (left_ht + 1) : (right_ht + 1);
}

int totNumOfNodes(BinTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    return 1 + totNumOfNodes(T->left) + totNumOfNodes(T->right);
}

int NumOfLeaves(BinTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    if (T->left == NULL && T->right == NULL)
    {
        return 1;
    }

    return NumOfLeaves(T->left) + NumOfLeaves(T->right);
}

int NumOfInternalNodes(BinTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    if (T->left == NULL && T->right == NULL)
    {
        return 0;
    }
    return 1 + NumOfInternalNodes(T->left) + NumOfInternalNodes(T->right);
}

BinTree delete(BinTree T, int x)
{
    if (T == NULL)
    {
        return NULL;
    }
}

bool isIdentical(BinTree T1, BinTree T2)
{
    if (T1==NULL && T2 == NULL)
    {
        return true;
    }
    if((T1==NULL && T2!=NULL) || (T2==NULL && T1!=NULL))
    {
        return false;
    }
    
    //Data should be same in the current Node and the left and right subtrees should be identical
    return (T1->e==T2->e) && (isIdentical(T1->left, T2->left)) && ((isIdentical(T1->right, T2->right)));
}

int main()
{
    BinTree tree = MakeNode(10);
    tree = Insert(tree, 11);
    // printTree(tree);
    // tree = Insert(tree, 9);
    // printTree(temp);
    // tree = Insert(tree,12);
    tree = Insert(tree, 7);
    // tree = Insert(tree,6);
    // tree = Insert(tree,14);
    tree = Insert(tree,5);
    // postOrderTraversal_rec(tree);
    // BinTree s = search_iterative(tree, 10);
    // printf("%d", s->e);
    // printf("%d", height(tree));
    return 0;
}