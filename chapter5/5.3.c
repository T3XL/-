#include "bintree.h"

int main(int argc, char const *argv[])
{
    biTNode *t = creatNode(1);
    t->lchild = creatNode(2);t->rchild = creatNode(3);
    biTNode *lc = t->lchild, *rc = t->rchild;
    lc->lchild = creatNode(4);lc->rchild = creatNode(5);
    rc->lchild = creatNode(6);rc->rchild = creatNode(7);
    lc->lchild->lchild=creatNode(8);
    levelOrder(t);
    changeChild(t);
    levelOrder(t);
    return 0;
}
