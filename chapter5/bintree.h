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
bool reverseLevel(biTree t)
{
    if (t == NULL)
        return false;
    SqQueue q;
    initQueue(&q);
    SqStack s;
    initStack(&s);
    biTNode *p = t;
    enQueue(&q, p);
    while (!queueEmpty(q))
    {
        deQueue(&q, &p);
        push(&s, p);
        if (p->lchild)
            enQueue(&q, p->lchild);
        if (p->rchild)
            enQueue(&q, p->rchild);
    }
    while (!stackEmpty(s))
    {
        pop(&s, &p);
        visit(p);
    }
    return true;
}
int high(biTree t)
{
    int high = 0, maxhigh = 1;
    biTNode *p = t, *r = NULL;
    SqStack s;
    initStack(&s);
    while (p || !stackEmpty(s))
    {
        if (p)
        {
            push(&s, p);
            p = p->lchild;
            ++high;
        }
        else
        {
            getTop(&s, &p);
            if (p->rchild && p->rchild != r)
                p = p->rchild;
            else
            {
                pop(&s, &p);
                r = p;
                p = NULL;
                --high;
            }
        }
        if (high > maxhigh)
            maxhigh = high;
    }
    return maxhigh;
}
bool isComplete(biTree t)
{
    if (t == NULL)
        return false;
    biTNode *p = t;
    SqQueue q;
    initQueue(&q);
    enQueue(&q, p);
    while (!queueEmpty(q))
    {
        deQueue(&q, &p);
        if (p)
        {
            enQueue(&q, p->lchild);
            enQueue(&q, p->rchild);
        }
        else
        {
            while (!queueEmpty(q))
            {
                deQueue(&q, &p);
                if (p)
                    return false;
            }
        }
    }
    return true;
}
int dsonNodes(biTree t)
{
    if (t == NULL)
        return 0;
    else if (t->lchild != NULL && t->rchild != NULL)
        return dsonNodes(t->lchild) + dsonNodes(t->rchild) + 1;
    else
        return dsonNodes(t->lchild) + dsonNodes(t->rchild);
}
void changeChild(biTree b)
{
    if (b->lchild != NULL)
        changeChild(b->lchild);
    if (b->rchild != NULL)
        changeChild(b->rchild);
    biTNode *text = b->lchild;
    b->lchild = b->rchild;
    b->rchild = text;
}
bool preNode(biTree b, int k)
{
    SqStack s;
    initStack(&s);
    biTNode *p = b;
    int i = 0;
    while (p || !stackEmpty(s))
    {
        if (p)
        {
            ++i;
            if (i == k)
            {
                visit(p);
                return true;
            }
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
void deleteTree(biTree t)
{
    if (t)
    {
        deleteTree(t->lchild);
        deleteTree(t->rchild);
        free(t);
    }
}
void deleX(biTree t, elemtpt x)
{
    SqQueue q;
    initQueue(&q);
    biTNode *p = t;
    enQueue(&q, p);
    if (t->data == x)
    {
        deleteTree(t);
        t = NULL;
        return;
    }
    while (!queueEmpty(q))
    {
        deQueue(&q, &p);
        if (p->lchild)
        {
            if (p->lchild->data == x)
            {
                deleteTree(p->lchild);
                p->lchild = NULL;
            }
            else
                enQueue(&q, p->lchild);
        }
        if (p->rchild)
        {
            if (p->rchild->data == x)
            {
                deleteTree(p->rchild);
                p->rchild = NULL;
            }
            else
                enQueue(&q, p->rchild);
        }
    }
}
void findParent(biTree t, elemtpt x)
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
            if (p->data == x)
                break;
            if (p->rchild && p->rchild != r)
                p = p->rchild;
            else
            {
                pop(&s, &p);
                r = p;
                p = NULL; // r是p的上一个访问的就知道有没有访问过右孩子了
            }
        }
    }
    while (!stackEmpty(s))
    {
        pop(&s, &p);
        visit(p);
    }
}
void copyStack(SqStack *source,SqStack *destination)
{
    int top=source->top;
    while (top!=-1)
    {
        destination->data[++destination->top]=source->data[top--];
    }
}
void findMutualParent(biTree t,biTNode *p1,biTNode *q1,biTNode *r)
{
    SqStack s;SqStack s1;
    initStack(&s);initStack(&s1);
    biTNode *p = t, *r = NULL;int lavel=0;
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
            if(p==p1 || p==q1)
            {
                if(lavel==1)
                    break;
                lavel++;
                copyStack(&s,&s1);
            }
            if (p->rchild && p->rchild != r)
                p = p->rchild;
            else
            {
                pop(&s, &p);
                r = p;
                p = NULL; // r是p的上一个访问的就知道有没有访问过右孩子了
            }
        }
    }
    while(!stackEmpty(s) && !stackEmpty(s1))
    {
        pop(&s,&p1);
        pop(&s1,&q1);
        if(p1==q1)
        {
            r=p1;
            break;
        }
    }
}
