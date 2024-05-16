#include "bintree.h"    

typedef struct Thread
{
    elemtpt data;
    struct Thread *lchild;
    struct Thread *rchild;
    int ltag,rtag;
}threadNode, *threadTree;

threadTree createThreadNode(elemtpt data)
{
    threadNode *t=(threadNode*)malloc(sizeof(threadNode));
    t->data=data;
    return t;
}
void inThread(threadTree p,threadTree *pre)
{
    if(p!=NULL)
    {
        inThread(p->lchild,pre);
        if(p->lchild==NULL)
        {
            p->lchild=*pre;
            p->ltag=1;
        }
        if((*pre)!=NULL && (*pre)->rchild==NULL)
        {
            (*pre)->rchild=p;
            (*pre)->rtag=1;
        }
        *pre=p;
        inThread(p->rchild,pre);
    }
}
void createInThread(threadTree t)
{
    threadNode *pre=NULL;
    if(t!=NULL)
    {
        inThread(t,&pre);
        pre->rchild=NULL;        // 处理最后一个结点
        pre->rtag=1;
    }
}
threadNode *firstNode(threadTree p)
{
    while(p->ltag==0)
        p=p->lchild;
    return p;
}
threadNode *nextNode(threadNode *p)
{
    if(p->rtag==1) 
        return p->rchild;
    else
        return firstNode(p->rchild);
}
void inOrder(threadNode *t)
{
    for(threadNode *p=firstNode(t);p!=NULL;p=nextNode(p))
        visit(p);
}
