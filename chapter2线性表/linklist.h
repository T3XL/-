#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct LNode
{
    int data; // 如果是头节点则代表长度
    struct LNode *next;
} LNode, *LinkList;
/*
 * @Description: 带头节点单链表初始化
 * @Param:
 * @Return:
 * @date 2024-04-26
 * @Editors: T3XL
 */
bool InitList(LinkList l)
{
    l = (LNode *)malloc(sizeof(LNode));
    l->next = NULL;
    return true;
}
LNode *makeLNode(int e)
{
    LNode *l = (LNode *)malloc(sizeof(LNode));
    l->data = e;
    return l;
}
/*
 * @Description: 带头节点单链表求表长
 * @Param:
 * @Return:
 * @date 2024-04-26
 * @Editors: T3XL
 */
int length(LinkList l)
{
    int len = 0;
    LNode *p = l;
    while (p != NULL)
    {
        p = p->next;
        ++len;
    }
    return len - 1;
}
LNode *getElem(LinkList l, int i)
{
    LNode *p = l;
    int j = 0;
    while (p != NULL && j < i)
    {
        p = p->next;
        ++j;
    }
    return p;
}
bool ListInsert(LinkList l, int i, int e)
{
    LNode *p = l;
    int j = 0;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (p == NULL)
        return false;
    LNode *s = makeLNode(e);
    p->next = s;
    s->next = NULL;
    return true;
}
bool ListDelete(LinkList l, int i)
{
    if (i < 1)
        return false;
    int j = 0;
    LNode *p = l;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if(p==NULL)
        return false;
    LNode *s = p->next;
    p->next = s->next ? s->next : NULL;
    free(s);
    return true;
}
LinkList listHeaderInsert(LinkList l)
{
    LNode *s;int x;
    l=(LNode*)malloc(sizeof(LNode));
    l->next=NULL;
    scanf("%d",&x);
    while(x!=9999)
    {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=l->next;
        l->next=s;
        scanf("%d",&x);
    }
    return l;
}
LinkList listTailInsert(LinkList l)
{
    LNode *s, *rear;int x;
    l=(LNode*)malloc(sizeof(LNode));
    l->next=NULL;
    rear=l;
    scanf("%d",&x);
    while(x!=9999)
    {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=NULL;
        rear->next=s;
        rear=s;
        scanf("%d",&x);
    }
    return l;
}
typedef struct DNode
{
    int data;
    struct DNode *prior,*next;
} DNode,*DLinkList;

bool InitDBList(DLinkList l)
{

}

