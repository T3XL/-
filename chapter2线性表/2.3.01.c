#include "linklist.h"

bool deleteX(LinkList l, int x)
{
    if (!l->next)
        return false;
    LNode *p = l->next, *pre = l, *q;
    while (p != NULL)
    {
        if (p->data == x)
        {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
    return true;
}
bool deleteMin(LinkList l)
{
    if (!l->next)
        return false;
    LNode *pre = l, *p = pre->next;
    LNode *minpre = pre, *minp = p;
    while (p != NULL)
    {
        if (p->data < minp->data)
        {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    minpre->next = minp->next;
    free(minp);
    return true;
}
LinkList reverseList(LinkList l)
{
    LNode *p = l->next;
    l->next = NULL;
    while (p != NULL)
    {
        LNode *s = p;
        p = p->next;
        s->next = l->next;
        l->next = s;
    }
    return l;
}
bool delN2M(LinkList l, int n, int m)
{
    LNode *pre = l, *mid = l->next;
    while (mid != NULL)
    {
        if (mid->data < m && mid->data > n)
        {
            LNode *q = mid;
            mid = mid->next;
            pre->next = mid;
            free(q);
        }
        else
        {
            pre = mid;
            mid = mid->next;
        }
    }
    return true;
}
LNode *getIntersectionNode(struct LNode *headA, struct LNode *headB) {
        struct LNode *p, *q;

        for (p = headA, q = headB; p != q; ){
            if (p != NULL)
                p = p->next;
            else p = headB;
            if (q != NULL)
                q = q->next;
            else q = headA;
        }

        return p;
}
LinkList *disCreat(LinkList l)
{
    LNode *A=(LNode *)malloc(sizeof(LNode));
    A->next=NULL;
    LNode *p=l->next,*pre=l;
    int i=1;
    while(p!=NULL)
    {
        if(i%2==0)
        {
            LNode *s=p;
            p=p->next;
            pre->next=p;
            s->next=A->next;
            A->next=s;
            ++i;
        }
        else
        {
            pre=p;
            p=p->next;
            ++i;
        }
    }
    LinkList *R=(LinkList*)malloc(sizeof(LinkList)*2);
    R[0]=l;R[1]=A;
    return R;
}
void delSame(LinkList l)
{
    if(l->next==NULL && l->next->next==NULL)
        return;
    LNode *p=l->next->next,*pre=l->next;
    while(p!=NULL)
    {
        if(pre->data==p->data)
        {
            LNode *s=p;
            p=p->next;
            pre->next=p;
            free(s);
        }
        else
        {
            p=p->next;
            pre=p;
        }
    }
}
LinkList genC(LinkList A,LinkList B)
{
    LNode *p=A->next,*q=B->next;
    LinkList C=(LinkList)malloc(sizeof(LNode));
    C->next=NULL;
    while(p!=NULL && q!=NULL)
    {
        if(p->data==q->data)
        {
            LNode *s=(LNode*)malloc(sizeof(LNode));
            s->data=p->data;
            p=p->next;q=q->next;
            s->next=C->next;
            C->next=s;
        }
        else if(p->data < q->data)
        {
            p=p->next;
        }
        else
        {
            q=q->next;
        }
    }
    return C;
}
bool pattern(LinkList A,LinkList B)
{
    LNode *p=A->next,*q=B->next;
    while(p!=NULL)
    {
        if(p->data==q->data)
        {
            LNode *s=q;
            p=p->next;
            s=s->next;
            while(p->data==s->data && s!=NULL && p!=NULL)
            {
                p=p->next;
                s=s->next;
            }
            if(s==NULL)
            {
                return true;
            }
        }
        else
            p=p->next;
    }
    return false;
}
bool Symmetry(DLinkList l)
{
    if(l->next==NULL || l->prior==NULL)
        return false;
    DNode *p=l->next,*q=l->prior;
    while(p!=q && p->next != q)
    {
        if(p->data != q->data)
            return false;
        p=p->next;
        q=q->prior;
    }
    return true;
}
LinkList link(LinkList h1,LinkList h2)
{
    LNode *p=h1,*q=h2;
    while(p->next!=h1)
        p=p->next;
    while (q->next!=h2)
        q=q->next;
    p->next=h2;
    q->next=h1;
    return h1;
}
typedef struct FreqDNode{
    int data,freq;
    struct FreqDNode *prior;
    struct FreqDNode *next;
}FreqDNode,* FreqDList;
FreqDNode *Locate(FreqDList l,int x)
{
    FreqDNode *p=l->next,*pre;
    while(p!=NULL && p->data!=x)
        p=p->next;
    if(p==NULL)
        exit(0);
    p->freq++;
    pre=p->prior;
    if(pre==l && pre->freq > p->freq)
        return p;
    if(p->next!=NULL)
        p->next->prior=p->prior;
    p->prior->next=p->next;
    while(pre!=l && pre->freq <= p->freq)
    {
        pre=pre->prior;
    }
    p->next=pre->next;
    if(pre->next!=NULL) 
        p->next->prior=p;
    p->prior=pre;
    pre->next=p;
    return p;
}
LinkList rightMov(LinkList l,int k)
{
    if(l->next==NULL)
        return l;
    LNode *p=l;
    int length=0;
    while (p!=NULL)
    {
        p=p->next;
        ++length;
    }
    if(length==k)
        return l;
    p->next=l;
    p=l;
    for(int i=0;i<length-k;i++)
        p=p->next;
    l=p->next;
    p->next=NULL;
    return l;
}
bool findLoopStart(LinkList l)
{
    LNode *slow=l,*fast=l;
    while (slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
        if(fast->next==NULL)
            return false;
        fast=fast->next;
    }
    return true;
}
int pairSum(LinkList l)
{
    LNode *slow=l,*fast=l->next,*r;int max=INT32_MIN;
    while(fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    r=slow;slow=slow->next;r->next=NULL;
    while (slow!=fast)
    {
        LNode *s=slow;
        slow=slow->next;
        s->next=r->next;
        r->next=s;
    }
    fast->next=r->next;
    r->next=fast;
    r=r->next;LNode *p=l,*q=r;
    while(p!=r)
    {
        if(p->data+q->data > max)
            max=p->data+q->data;
        p=p->next;q=q->next;
    }
    return max;
}
LNode *findK(LinkList l,int k)
{
    LNode *p=l->next,*q=l->next;int i=0;
    while (p->next!=NULL)
    {
        if(++i>=k)
            q=q->next;
        p=p->next;
    }
    return q;
}
int main(int argc, char const *argv[])
{
    LNode *l;
    l=listTailInsert(l);
    showList(l);
    puts("----");
    LinkList *R;
    R=disCreat(l);
    showList(R[0]);
    puts("----");
    showList(R[1]);
    return 0;
}
