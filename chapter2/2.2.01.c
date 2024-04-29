#include "list.h"

bool Del_Min(SeqList *l, ElemType *e)
{
    if (l->length == 0)
        return false;
    *e = l->data[0];
    int pos = 0;
    for (int i = 0; i < l->length; i++)
    {
        if (l->data[i] < *e)
        {
            *e = l->data[i];
            pos = i;
        }
    }
    l->data[pos] = l->data[l->length - 1];
    l->length--;
    return true;
}

void Del_x(SeqList *l, ElemType x)
{
    int k = 0;
    for (int i = 0; i < l->length; i++)
    {
        if (l->data[i] != x)
        {
            l->data[k] = l->data[i];
            k++;
        }
    }
    l->length = k;
}
bool Del_s_t(SeqList *l, ElemType s, ElemType t)
{
    int k = 0;
    if (s >= t || l->length == 0)
        return false;
    for (int i = 0; i < l->length; ++i)
    {
        if (l->data[i] < s || l->data[i] > t)
        {
            l->data[k] = l->data[i];
            ++k;
        }
    }
    l->length = k;
    return true;
}
bool Del_same(SeqList *l)
{
    if (l->length == 0)
        return false;
    int k = 0;
    for (int i = 1; i < l->length; ++i)
    {
        if (l->data[k] != l->data[i])
        {
            l->data[++k] = l->data[i];
        }
    }
    l->length = k + 1;
    return true;
}
bool merges(SeqList *q, SeqList *s, SeqList *merge)
{
    if (q->length + s->length > merge->MaxSize)
        return false;
    int i, j, k = 0;
    for (i = 0, j = 0; i < s->length && j < q->length;)
    {
        if (s->data[i] <= q->data[j])
            merge->data[k++] = s->data[i++];
        else
            merge->data[k++] = s->data[j++];
    }
    while (j < q->length)
    {
        merge->data[k++] = q->data[j++];
    }
    while (i < s->length)
    {
        merge->data[k++] = s->data[i++];
    }
    merge->length = k;
    return true;
}
bool Reverse(SeqList *l, int left, int right)
{
    if (left >= right || right > l->length)
        return false;
    ElemType temp;
    for (int i = 0; i < (right - left + 1) / 2; i++)
    {
        temp = l->data[i + left - 1];
        l->data[i + left - 1] = l->data[right - i - 1];
        l->data[right - i - 1] = temp;
    }
    return true;
}
void Exchange(SeqList *l, int m, int n)
{
    Reverse(l, 1, l->length);
    Reverse(l, 1, n);
    Reverse(l, n + 1, n + m);
}
/*
 * @Description: 折半查找
 * @Param:
 * @Return:
 * @date 2024-04-23
 * @Editors: T3XL
 */
bool Serch_x(SeqList *l, ElemType x)
{
    if (l->length == 0)
        return false;
    int low = 0, hight = l->length - 1;
    int mid = 0;
    while (low <= hight)
    {
        mid = (low + hight) / 2;
        if (l->data[mid] == x)
            break;
        else if (l->data[mid] < x)
            low = mid + 1;
        else
            hight = mid - 1;
    }
    if(l->data[mid]==x && mid != l->length-1)
    {
        ElemType temp= l->data[mid];
        l->data[mid]=l->data[mid+1];
        l->data[mid+1]=temp;
    }
    if(low>hight)
    {
        if(l->length+1>l->MaxSize)
            return false;
        int i=0;
        for(i=l->length-1;i>hight;--i)
        {
            l->data[i+1]=l->data[i];
        }
        l->data[i+1]=x;
        l->length+=1;
    }
    return true;
}
void SameKey(int A[],int B[],int C[],int n)
{
    int i=0,j=0,k=0;
    while(i<n && j<n && k<n)
    {
        if(A[i] == B[j] && B[j] == C[k])
        {
            printf("%d\n",A[i]);
            ++i;
            ++j;
            ++k;
        }
        else
        {
            if(A[i] > B[j] || A[i] > C[k])
            {
                if(B[j] >= C[k])
                    ++k;
                if(B[j] <= C[k])
                    ++j;
            }
            else if(B[j] > C[k] || B[j] > A[i])
            {
                if(A[i] >= C[k])
                    ++k;
                if(A[i] <= C[k])
                    ++i;
            }
            else if(C[k] > A[i] || C[k] > B[j])
            {
                if(A[i] >= B[j])
                    ++j;
                if(A[i] <= B[j])
                    ++i;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    SeqList l;
    InitList(&l);
    for (int i = 1; i < 11; i++)
    {
        ListInsert(&l, i, i);
    }
    for (int i = 1; i < 5; ++i)
    {
        ListInsert(&l, 10 + i, i + 20);
    }
    Listshow(&l);
    puts("-------------------");
    Exchange(&l, 10, 4);
    Listshow(&l);
    return 0;
}
