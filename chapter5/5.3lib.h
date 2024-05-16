#include "bintree.h"
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
void preNode(biTree b, int k)
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
                return ;
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
void findMutualParent(biTree t,biTNode *p1,biTNode *q1,biTNode *r1)
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
            r1=p1;
            break;
        }
    }
}
/* 
 * @Description: 第五题和第十三题思路类似，利用层次遍历并确定好每一层的边界
 * @Param: 
 * @Return: 
 * @date 2024-05-15 
 * 1.设置变量last指向当前层的最右边结点
 * 2.每次层次遍历出队时与last比较，相等则意味着到了这一层的末尾
 * @Editors: T3XL
 */
int width(biTree t)
{
    SqQueue q;initQueue(&q);
    biTNode *p=t;enQueue(&q,p);
    int width=1,turn=0;int last=1;
    while(!queueEmpty(q))
    {
        deQueue(&q,&p);
        ++turn;
        if(p->lchild)
            enQueue(&q,p->lchild);
        if(p->rchild)
            enQueue(&q,p->rchild);
        if(last==q.front)
        {
            if(turn>width)
                width=turn;
            turn=0;
            last=q.rear;
        }
    }
    return width;
}
/* 
 * @Description: 
 * @Param: 
 * @Return: 
 * @date 2024-05-15 
 * 1.满二叉树：任意结点的左右子树的均含有相等的结点数
 * 2.先序序列的第一个结点时后序序列的最后一个结点
 * @Editors: T3XL
 */
void preTopost(elemtpt pre[],int start1,int teminate1,elemtpt post[],int start2,int teminate2)
{
    int half;
    if(teminate1>=start1)
    {
        post[teminate2]=pre[start1];
        half=(teminate1-start1)/2;
        preTopost(pre,start1+1,start1+half,post,start2,start2+half-1);
        preTopost(pre,start1+half+1,teminate1,post,start2+half,teminate2-1);
    }
}