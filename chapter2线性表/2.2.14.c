#include "list.h"

#define INT_MAX 0x7fffffff
int abs(int a)
{
    if(a<0) return -a;
    else    return a;
}
bool xlsMin(int a,int b,int c)
{
    if(a <= b && a <= c) return true;
    else return false;
}
int findMinofTrip(SeqList *A,SeqList *B,SeqList *C)
{
    int i=0,j=0,k=0,dMin=INT_MAX;
    while (i<A->length && j<B->length && k<C->length && dMin >0)
    {
        int D=abs(A->data[i]-B->data[j])+abs(B->data[j]-C->data[k])+abs(C->data[k]-A->data[i]);
        if(D < dMin)
            dMin=D;
        if(xlsMin(A->data[i],B->data[j],C->data[k])) ++i;
        else if(xlsMin(B->data[j],C->data[k],A->data[i])) ++j;
        else ++k;
    }
    return dMin;
}