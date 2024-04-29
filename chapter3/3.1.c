#include "stack.h"
#include "../chapter2/linklist.h"
SqStack s;
bool legal(char A[])
{
    int x;
    for (int i = 0; A[i] != '\0'; ++i)
    {
        if (A[i] == 'I')
            push(&s, 1);
        if (A[i] == 'O')
            pop(&s, &x);
    }
    if (stackEmpty(s))
        return true;
    return false;
}
int dc(LinkList l,int length)
{
    
}
int main(int argc, char const *argv[])
{
    initStack(&s);
    for (int i = 0; i < 10; ++i)
    {
        push(&s, i);
    }
    for (int i = 0; i < 10; ++i)
    {
        int x;
        pop(&s, &x);
        printf("%d\n", x);
    }

    return 0;
}
