typedef char Element;

struct ststack
{
    int iTop;
    int iMaxElements;
    Element* pstart;
}ststack;

typedef struct ststack* Stack;

Stack createStack(const int);
void push(Stack, Element);
void pop(Stack);
Element getTop(Stack);
int isStackEmpty(Stack);
void deleteStack(Stack);
int getSizeofStack(const Stack );
void printStack(const Stack);