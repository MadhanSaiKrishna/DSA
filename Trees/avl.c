#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int Element;

struct stAvl
{
    Element e;
    int height;
    struct stAvl *left;
    struct stAvl *right;
};

typedef struct stAvl *AVL;

