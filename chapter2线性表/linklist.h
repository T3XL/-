#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
typedef struct LNode
{
    int data; // 如果是头节点则代表长度
    struct LNode *next;
} LNode, *LinkList;
void showList(LinkList l)
{
    LNode *p = l->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}
/*
 * @Description: 带头节点单链表初始化
 * @Param:
 * @Return:
 * @date 2024-04-26
 * @Editors: T3XL
 */
LinkList InitList()
{
    LinkList l = (LNode *)malloc(sizeof(LNode));
    l->next = NULL;
    return l;
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
    if (p == NULL)
        return false;
    LNode *s = p->next;
    p->next = s->next ? s->next : NULL;
    free(s);
    return true;
}
LinkList listHeaderInsert(LinkList l)
{
    LNode *s;
    int x;
    l = (LNode *)malloc(sizeof(LNode));
    l->next = NULL;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = l->next;
        l->next = s;
        scanf("%d", &x);
    }
    return l;
}
LinkList listTailInsert(LinkList l)
{
    LNode *s, *rear;
    int x;
    l = (LNode *)malloc(sizeof(LNode));
    l->next = NULL;
    rear = l;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = NULL;
        rear->next = s;
        rear = s;
        scanf("%d", &x);
    }
    return l;
}
typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;
DLinkList InitDBList()
{
    DLinkList l = (DNode *)malloc(sizeof(DNode));
    if (l == NULL)
        return false;
    l->prior = NULL;
    l->next = NULL;
    return l;
}
bool dListInsert(DLinkList l, int i)
{
    DNode *p;
    int j = 0;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (p == NULL)
        return false;
    DNode *s = (DNode *)malloc(sizeof(DNode));
    if (p->next)
    {
        s->next = p->next;
        p->next->prior = s;
    }
    else
        s->next = NULL;
    s->prior = p;
    p->next = s;
    return true;
}
bool dListDelete(DLinkList l, int i)
{
    DNode *p;
    int j = 0;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (p == NULL && p->next == NULL)
        return false;
    DNode *s = p->next;
    if (s->next)
    {
        s->next->prior = p;
    }
    p->next = s->next;
    free(s);
    return true;
}
DLinkList dListHeaderInsert(DLinkList l)
{
    int x;
    DNode *s;
    l = (DNode *)malloc(sizeof(DNode));
    l->next = NULL;
    l->prior = NULL;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (DNode *)malloc(sizeof(DNode));
        s->data = x;
        if (l->next)
        {
            s->next = l->next;
            s->next->prior = s;
        }
        else
            s->next = l->next;
        s->prior = l;
        l->next = s;
    }
    return l;
}
DLinkList dListTailInsert(DLinkList l)
{
    int x;
    DNode *s, *rear = l;
    l = (DNode *)malloc(sizeof(DNode));
    l->next = NULL;
    l->prior = NULL;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (DNode *)malloc(sizeof(DNode));
        s->data = x;
        s->next = rear->next;
        s->prior = rear;
        rear->next = s;
        rear = s;
    }
    return l;
}
