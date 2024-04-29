#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define MaxSize 100
typedef struct{
    int data[MaxSize];
    int top;
}SqStack;
void initStack(SqStack *s)
{
    s->top=-1;
}
bool stackEmpty(SqStack s)
{
    if(s.top==-1)
        return true;
    return false;
}
bool push(SqStack *s,int x)
{
    if(s->top==MaxSize-1)
        return false;
    s->data[++s->top]=x;
    return true;
}
bool pop(SqStack *s,int *x)
{
    if(s->top==-1)
        return false;
    *x=s->data[s->top--];
    return true;
}
bool getTop(SqStack *s,int *x)
{
    if(s->top==-1)
        return false;
    *x=s->data[s->top];
    return true;
}