#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

int main()
{
    Stack s = createStack(10);
    push(s,'a');
    push(s, 'b');
    pop(s);
    push(s, 'c');
    //printStack(s);
    //printf("%c", getTop(s));
    return 0;
}