#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define InitSize 100
typedef int ElemType;
typedef struct
{
    ElemType *data;
    int length, MaxSize;
} SeqList;

/* 
 * @Description: 初始化顺序表
 * @Param: SeqList *l
 * @Return: 
 * @date 2024-04-21 
 * @Editors: T3XL
 */
void InitList(SeqList *l)
{
    l->data = (ElemType *)malloc(InitSize * sizeof(ElemType));
    l->length = 0;
    l->MaxSize = InitSize;
}
/* 
 * @Description: 删除顺序表
 * @Param: SeqList *l
 * @Return: 
 * @date 2024-04-21 
 * @Editors: T3XL
 */
void DestroyList(SeqList *l)
{
    free(l->data);
    l->data = NULL;
    l->length = 0;
    l->MaxSize = 0;
}
/* 
 * @Description: 
 * @Param: 
 * @Return: 
 * @date 2024-04-21 
 * @Editors: T3XL
 */
bool ListInsert(SeqList *l,int i,ElemType e)
{
    if(i<1 || i>l->length+1)                // 判断插入位置是否合法
        return false;
    if(l->length>=l->MaxSize)               // 当前存储空间已满，需要扩容
    {
        ElemType *newbase = (ElemType *)realloc(l->data, (l->MaxSize+InitSize)*sizeof(ElemType));
        if(!newbase)
            return false;
        l->data = newbase;
        l->MaxSize += InitSize;
    }
    for(int j=l->length;j>=i;j--)           // 将插入位置后面的元素后移
        l->data[j] = l->data[j-1];
    l->data[i-1] = e;
    l->length++;
    return true;
}
/* 
 * @Description: 删除顺序表第i个位置的元素，用引用变量e返回被删除的元素
 * @Param: 
 * @Return: 
 * @date 2024-04-21 
 * @Editors: T3XL
 */
bool ListDelete(SeqList *l,int i,ElemType *e)
{
    if(i<1 || i>l->length)
        return false;
    *e = l->data[i-1];
    for(int j=i;j<l->length;j++)
        l->data[j-1] = l->data[j];
    l->length--;
    return true;
}
/* 
 * @Description: 在顺序表中，查找第一个元素等于e的元素
 * @Param: 
 * @Return: 
 * @date 2024-04-21 
 * @Editors: T3XL
 */
int LocateElem(SeqList l,ElemType e)
{
    for(int i=0;i<l.length;i++)
        if(l.data[i]==e)
            return i+1;
    return 0;
}
/* 
 * @Description: 
 * @Param: 
 * @Return: 
 * @date 2024-04-22 
 * @Editors: T3XL
 */
bool Listshow(SeqList *l)
{
    if(l->length==0)
        return false;
    for(int i=0;i<l->length;i++)
    {
        printf("order%d : %d\n",i,l->data[i]);
    }
    return true;
}

