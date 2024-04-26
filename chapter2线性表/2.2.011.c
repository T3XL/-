#include "list.h"

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
double findMedianSortedArrays(SeqList *A, SeqList *B)
{
    int n = A->length;
    int m = B->length;
    if (n > m) // 保证数组A一定最短
        return findMedianSortedArrays(B, A);
    int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;
    while (lo <= hi)
    {
        c1 = (lo + hi) / 2;
        c2 = m + n - c1;

        LMax1 = (c1 == 0) ? INT32_MIN : A->data[(c1 - 1) / 2];
        RMin1 = (c1 == 2 * n) ? INT32_MAX : A->data[c1 / 2];
        LMax2 = (c2 == 0) ? INT32_MIN : B->data[(c2 - 1) / 2];
        RMin2 = (c2 == 2 * m) ? INT32_MAX : B->data[c2 / 2];

        if (LMax1 > RMin2)
            hi = c1 - 1;
        else if (LMax2 > RMin1)
            lo = c1 + 1;
        else
            break;
    }
    return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
}
int mooreVoting(SeqList *l)
{
    int count=0,candidate;
    for(int i=0;i<l->length;++i)
    {
        if(count==0)
            candidate=l->data[i];
        if(candidate == l->data[i])
            ++count;
        else
            --count;
    }
    if(count > 0)
    {
        for(int i=0,count=0;i<l->length;++i)
        {
            if(l->data[i] == candidate)
                ++count;
        }
    }
    if(count > l->length/2)
        return candidate;
    else
        return -1;
}
int findMissMin(int A[],int n)
{
    int *B=(int*)malloc(sizeof(int) * n);
    memset(B,0,sizeof(int) * n);
    for(int i=0;i<n;++i)
    {
        if(A[i] > 0 && A[i] < n)
            B[A[i]-1]=1;
    }
    int i;
    for(i=0;i<n;++i)
    {
        if(B[i] == 0)
            break;
    }
    return i+1;
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
