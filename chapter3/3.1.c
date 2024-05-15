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
bool dc(LinkList l, int length)
{
    const int size = length / 2;char stack[size];int top=-1;
    LNode *p=l->next;int i=0;
    while (p!=NULL && i<size)
    {
        stack[++top]=p->data;
        p=p->next;++i;
    }
    if(length%2!=0)
        p=p->next;
    while (p!=NULL)
    {
        if(p->data!=stack[top--])
            return false;
        p=p->next;
    }
    return true;
}
bool reverse(SqQueue *q,SqStack *s)
{
    if(q->front==q->rear)
        return false;
    while(q->front!=q->rear)
    {
        s->data[++s->top]=q->data[q->front];
        q->front=(q->front+1)%MaxSize;
    }
    while (s->top!=-1)
    {
        q->data[q->rear]=s->data[s->top--];
        q->rear=(q->rear+1)%MaxSize;
    }
    return true;
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

