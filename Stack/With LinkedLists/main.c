#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "functions.h"

int main(){
    Stack S = createStack();
    push(S,10);
    push(S,20);
    push(S,9);
    pop(S);
    pop(S);
    pop(S);
    viewTop(S);
    return 0;
}