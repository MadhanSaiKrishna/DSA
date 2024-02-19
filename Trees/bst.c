#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_QUEUE_SIZE 100

typedef int Element;

// Tree Data structure
struct stTreeNode
{
    Element e;
    struct stTreeNode *left;
    struct stTreeNode *right;
};

struct stQueue
{
    int front;
    int rear;
    struct stTreeNode **treearr;
    int size;
    int capacity;
};

typedef struct stQueue *Queue;
typedef struct stTreeNode *BST;
typedef BST BinTree;

// Queue functions

BST push(Queue, BST);
BST pop(Queue);
bool isEmpty(Queue);

BST push(Queue Q, BST root)
{
    Q->rear = (Q->rear + 1) % Q->capacity;
    Q->treearr[Q->rear] = root;
    if (Q->front == -1)
    {
        Q->front = 0;
    }
    Q->size++;
}

BST pop(Queue Q)
{
    BST temp = Q->treearr[Q->front];
    Q->front++;
    Q->size--;
    return temp;
}

bool isEmpty(Queue Q)
{
    return Q->size==0;
}

// Creating a Node
BST createNode(Element x)
{
    BST newNode = (BST)malloc(sizeof(struct stTreeNode));
    assert(newNode != NULL); // Handlin Memory Allocation failures
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->e = x;
    return newNode;
}

// Inserting elements into an BST
BST insert(BST T, Element x)
{
    BST node = createNode(x);
    if (T == NULL)
    {
        return node;
    }
    if (x < T->e)
    {
        T->left = insert(T->left, x);
    }
    else if (x > T->e)
    {
        T->right = insert(T->right, x);
    }
    return T;
}

// Root node is given, check whether it is a BST or not.
bool isBST(BinTree T)
{
    static BinTree prev = NULL;
    if (T == NULL)
    {
        return true;
    }
    // following INORDER logic --> Left, Root, Right
    if (!isBST(T->left))
    {
        return 0;
    }
    if (prev != NULL && T->e <= prev->e)
    {
        return false;
    }
    prev = T;
    return isBST(T->right);
}

// Finding the min value in a bst
BST min(BST root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root;
    }

    return min(root->left);
}

// finding the max value in a bst
BST max(BST root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root;
    }

    return max(root->right);
}

// Deleting a Node from the given BST
BST delete(BST root, Element x)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL && root->e == x)
    {
        free(root);
        return NULL;
    }
}

// Inorder Traversal Printing of the BST
void inorder(BST root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->e);
    inorder(root->right);
}

// Finding the Height of the BST
int height(BST root)
{
    if (root == NULL)
    {
        return 0;
    }
    return height(root->left) > height(root->right) ? height(root->left) + 1 : height(root->right) + 1;
}

// Level-order Traversal(Breadth- first Traversal)

void level_order(BST root)
{
    if (root == NULL)
    {
        return;
    }
    Queue Q = (Queue)malloc(sizeof(struct stQueue));
    Q->capacity = MAX_QUEUE_SIZE;
    Q->front = -1;
    Q->rear = -1;
    Q->size = 0;
    Q->treearr = (BinTree *)malloc(Q->capacity * sizeof(struct stTreeNode *));
    push(Q, root);
    while (!isEmpty(Q))
    {
        BinTree current = pop(Q);
        printf("%d ", current->e);
        if (current->left!=NULL)
        {
            push(Q, current->left);
        }
        if (current->right!=NULL)
        {
            push(Q, current->right);
        }
    }
}

//Checks if the the given root is balanced or not.
bool isBalanced(BST root)
{
    if (root == NULL)
    {
        return true;
    }

    if (abs(height(root->left)-height(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right))
    {
        return true;
    }
    else
    {
        return false;
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
    // T->left->left->left = createNode(1);
    // if (isBST(T))
    // {
    //     printf("Yes");
    // }
    // printf("Max of the BST is : %d", max(T)->e);
    // inorder(T);
    // printf("Height of the Tree is : %d", height(T));
    // level_order(T);
    if (isBalanced(T))
    {
        printf("Balanced");
    }
    
    return 0;
}