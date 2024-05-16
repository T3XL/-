#include "5.3lib.h"
#include "threadBTree.h"

int main(int argc, char const *argv[])
{
    // biTNode *t = creatNode(1);
    // t->lchild = creatNode(2);t->rchild = creatNode(3);
    // biTNode *lc = t->lchild, *rc = t->rchild;
    // lc->lchild = creatNode(4);lc->rchild = creatNode(5);
    // rc->lchild = creatNode(6);rc->rchild = creatNode(7);
    // lc->lchild->lchild=creatNode(8);
    // int w=width(t);
    // printf("%d\n",w);
    threadNode *t=createThreadNode(1);
    t->lchild=createThreadNode(2);t->rchild=createThreadNode(3);
    createInThread(t);
    return 0;
}
