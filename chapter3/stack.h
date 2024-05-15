#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define MaxSize 100
typedef char elemtp;
typedef struct{
    elemtp data[MaxSize];
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
bool push(SqStack *s,elemtp x)
{
    if(s->top==MaxSize-1)
        return false;
    s->data[++s->top]=x;
    return true;
}
bool pop(SqStack *s,elemtp *x)
{
    if(s->top==-1)
        return false;
    *x=s->data[s->top--];
    return true;
}
bool getTop(SqStack *s,elemtp *x)
{
    if(s->top==-1)
        return false;
    *x=s->data[s->top];
    return true;
}

typedef struct stack
{
    elemtp data[MaxSize];
    int top[2];
}ShareStack;

void initShareStack(ShareStack *s)
{
    s->top[0]=-1;
    s->top[1]=MaxSize;
}
bool sharePush(ShareStack *s,int i,elemtp x)
{
    if(s->top[1]-s->top[0]==1 || i<0 || i>1)
        return false;
    switch (i)
    {
    case 0:
        s->data[++s->top[0]]=x;
        break;
    case 1:
        s->data[--s->top[1]]=x;
        break;
    }   
    return true;
}
bool sharePop(ShareStack *s,int i,elemtp *x)
{
    if(i<0 || i>1)
        return false;
    switch (i)
    {
    case 0:
        if(s->top[0]==-1)
            return false;
        *x=s->data[s->top[0]--];
        break;
        case 1:
        if(s->top[1]==MaxSize)
            return false;
        *x=s->data[s->top[1]++];
        break;
    }
    return true;
}
typedef struct 
{
    elemtp data[MaxSize];
    int front,rear;
}SqQueue;
void initQueue(SqQueue *q)
{
    q->front=q->rear=0;
}
bool queueEmpty(SqQueue q)
{
    if(q.front==q.rear)
        return true;
    return false;
}
bool enQueue(SqQueue *q,elemtp x)
{
    if((q->rear+1)%MaxSize==q->front)
        return false;
    q->data[q->rear]=x;
    q->rear=(q->rear+1)%MaxSize;
    return true;
}
bool deQueue(SqQueue *q,elemtp *x)
{
    if(q->front==q->rear)
        return false;
    *x=q->data[q->front];
    q->front=(q->front+1)%MaxSize;
    return true;
}
typedef struct{
    elemtp data[MaxSize];
    int front,rear;
    int tag;
}SqQueue2;
void initTQueue(SqQueue2 *q)
{
    q->front=q->rear=0;
    q->tag=0;
}
bool queueTEmpty(SqQueue2 q)
{
    if(q.front==q.rear && q.tag==0)
        return true;
    return false;
}
bool enTQueue(SqQueue2 *q,elemtp x)
{
    if(q->rear==q->front && q->tag==1)
        return false;
    q->data[q->rear]=x;q->tag=1;
    q->rear=(q->rear+1)%MaxSize;
    return true;
}
bool deTQueue(SqQueue2 *q,elemtp *x)
{
    if(q->front==q->rear && q->tag==0)
        return false;
    *x=q->data[q->front];q->tag=0;
    q->front=(q->front+1)%MaxSize;
    return true;
}