#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct LNode
{
    int data;
    struct LNode * next;
}LNode,*LinkList;

bool InitList(LinkList l)
{
    l=(LNode *)malloc(sizeof(LNode));
    l->next=NULL;
    return true;
}
