#if !defined(MACRO)
#define MACRO

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MaxSize 100
typedef int elemtpt;
typedef struct BiTNode
{
    elemtpt data;
    struct BiTNode *lchild, *rchild;
} biTNode, *biTree;

biTNode *creatNode(elemtpt x)
{
    biTNode *t = (biTNode *)malloc(sizeof(biTNode));
    t->lchild = t->rchild = NULL;
    t->data = x;
    return t;
}
void visit(biTNode *t)
{
    printf("%d\n", t->data);
}
typedef biTree elemtp;
typedef struct
{
    elemtp data[MaxSize];
    int front, rear;
} SqQueue;
void initQueue(SqQueue *q)
{
    q->front = q->rear = 0;
}
bool queueEmpty(SqQueue q)
{
    if (q.front == q.rear)
        return true;
    return false;
}
bool enQueue(SqQueue *q, elemtp x)
{
    if ((q->rear + 1) % MaxSize == q->front)
        return false;
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % MaxSize;
    return true;
}
bool deQueue(SqQueue *q, elemtp *x)
{
    if (q->front == q->rear)
        return false;
    *x = q->data[q->front];
    q->front = (q->front + 1) % MaxSize;
    return true;
}
typedef struct
{
    elemtp data[MaxSize];
    int top;
} SqStack;
void initStack(SqStack *s)
{
    s->top = -1;
}
bool stackEmpty(SqStack s)
{
    if (s.top == -1)
        return true;
    return false;
}
bool push(SqStack *s, elemtp x)
{
    if (s->top == MaxSize - 1)
        return false;
    s->data[++s->top] = x;
    return true;
}
bool pop(SqStack *s, elemtp *x)
{
    if (s->top == -1)
        return false;
    *x = s->data[s->top--];
    return true;
}
bool getTop(SqStack *s, elemtp *x)
{
    if (s->top == -1)
        return false;
    *x = s->data[s->top];
    return true;
}
void copyStack(SqStack *source,SqStack *destination)
{
    int top=source->top;
    while (top!=-1)
    {
        destination->data[++destination->top]=source->data[top--];
    }
}
void deleteTree(biTree t)
{
    if (t)
    {
        deleteTree(t->lchild);
        deleteTree(t->rchild);
        free(t);
    }
}
void preOrder(biTree t)
{
    if (t != NULL)
    {
        visit(t);
        preOrder(t->lchild);
        preOrder(t->rchild);
    }
}
void inOrder(biTree t)
{
    if (t != NULL)
    {
        inOrder(t->lchild);
        visit(t);
        inOrder(t->rchild);
    }
}
void postOrder(biTree t)
{
    if (t != NULL)
    {
        postOrder(t->lchild);
        postOrder(t->rchild);
        visit(t);
    }
}
/*
 * @Description: 中序遍历二叉树的非递归算法
 * @Param:
 * @Return:
 * @date 2024-05-12
 * @Editors: T3XL
 * 1.沿着根的左孩子，依次入栈，直到左孩子为空。
 * 2.栈顶元素出栈并访问：若其右孩子为空，继续执行2；若其右孩子不空，将右子树转执行1
 */
void inOrder2(biTree t)
{
    SqStack s;
    biTNode *p = t;
    initStack(&s);
    while (p || !stackEmpty(s))
    {
        if (p)
        {
            push(&s, p);
            p = p->lchild;
        }
        else
        {
            pop(&s, &p);
            visit(p);
            p = p->rchild;
        }
    }
}
void preOrder2(biTree t)
{
    SqStack s;
    biTNode *p = t;
    initStack(&s);
    while (p || !stackEmpty(s))
    {
        if (p)
        {
            visit(p);
            push(&s, p);
            p = p->lchild;
        }
        else
        {
            pop(&s, &p);
            p = p->rchild;
        }
    }
}
/*
 * @Description: 后序遍历二叉树非递归算法
 * @Param:
 * @Return:
 * @date 2024-05-13
 * @Editors: T3XL
 * 1.沿着根的左孩子，依次入栈，知道左孩子为空
 * 2.读栈顶元素：若其右孩子非空未被访问过，将右子树转执行1；否则，栈顶元素出栈并访问
 */
void postOrder2(biTree t)
{
    SqStack s;
    initStack(&s);
    biTNode *p = t, *r = NULL;
    while (p || !stackEmpty(s))
    {
        if (p)
        {
            push(&s, p);
            p = p->lchild;
        }
        else
        {
            getTop(&s, &p);
            if (p->rchild && p->rchild != r)
                p = p->rchild;
            else
            {
                pop(&s, &p);
                visit(p);
                r = p;
                p = NULL; // r是p的上一个访问的就知道有没有访问过右孩子了
            }
        }
    }
}
void levelOrder(biTree t)
{
    SqQueue q;
    initQueue(&q);
    biTNode *p = t;
    enQueue(&q, p);
    while (!queueEmpty(q))
    {
        deQueue(&q, &p);
        visit(p);
        if (p->lchild)
            enQueue(&q, p->lchild);
        if (p->rchild)
            enQueue(&q, p->rchild);
    }
}



#endif // MACRO
