#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

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


BST createNode(Element x)
{
    BST newNode = (BST)malloc(sizeof(struct stTreeNode));
    assert(newNode!=NULL);
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->e = x;
    return newNode;
}


BST insert(BST T, Element x)
{
    BST node = createNode(x);
    if (T==NULL)
    {
        return node;
    }
    if (x<T->e)
    {
        T->left = insert(T->left,x);
    }
    else if (x>T->e)
    {
        T->right = insert(T->right,x);
    }
    return T;
    
}

// Root node is given, check whether it is a BST or not.
bool isBST(BinTree T)
{
    static BinTree prev =NULL;
    if (T == NULL)
    {
        return true;
    }
    //following INORDER logic --> Left, Root, Right
    if (!isBST(T->left))
    {
        return 0;
    }
    if (prev!= NULL && T->e<=prev->e)
    {
        return false;
    }
    prev = T;
    return isBST(T->right);
}


//Finding the min value in a bst
BST min(BST root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left==NULL && root->right == NULL)
    {
        return root;
    }

    return min(root->left);    
}


//finding the max value in a bst
BST max(BST root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if(root->left == NULL && root->right==NULL)
    {
        return root;
    }
    
    return max(root->right);
}

BST delete(BST root, Element x)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left ==  NULL && root->right ==NULL && root->e == x)
    {
        free(root);
        return NULL;
    }
    
}

int main()
{
    BinTree T;
    T = createNode(10);
    T->left = createNode(5);
    T->right = createNode(15);
    T->left->left = createNode(3);
    T->left->right = createNode(6);
    T->left->left->left = createNode(1);
    // if (isBST(T))
    // {
    //     printf("Yes");
    // }
    printf("Max of the BST is : %d", max(T)->e);
    return 0;
}