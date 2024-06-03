#include "SeqList.h"

//初始化
void SeqListInit(SL* s)
{
//    s.size = 0;
//    s.a = NULL;
//    s.capacity = 0;
    s->a = (SLDataType*)malloc(sizeof(SLDataType)*4);

    if(s->a == NULL)
    {
        printf("申请内存失败\n");
        exit(-1);
    }

    s->size = 0;
    s->capacity = 4;

}

//销毁
void SeqListDestory(SL*ps)
{
    free(ps->a);
    ps->a = NULL;
    ps->size = ps->capacity = 0;
}

//检查扩容
void SeqListCheckCapacity(SL*ps)
{

    //如果满了需要增容
    if(ps->size >= ps->capacity){
        ps->capacity *= 2;
        ps->a = (SLDataType*)realloc(ps->a,sizeof(SLDataType)*ps->capacity);
        if(ps->a == NULL){
            printf("失败");
            exit(-1);
        }
    }
}

//尾插尾删  头插头删
void SeqListPushBack(SL* ps,SLDataType x)
{
    assert(ps);
    SeqListCheckCapacity(ps);

    if(ps->a != NULL){
    ps->a[ps->size] = x;
    ps->size++;
    }
    else {
        printf("失败");
        exit(-1);
    }
}

//打印
void SeqListPrint(SL*ps)
{
    assert(ps);
    SeqListCheckCapacity(ps);
    for(int i = 0 ; i < ps->size ; ++i)
    {
        printf("%d ",ps->a[i]);
    }
    printf("\n");
}

void SeqListPopBack(SL* ps)
{
    assert(ps);

    ps->a[ps->size-1] = 0;
    ps->size--;
}

void SeqListPushFront(SL* ps,SLDataType x)
{
    assert(ps);
    int end = ps->size - 1;
    while (end>=0){
        ps->a[end+1] = ps->a[end];
        end--;
    }

    ps->a[0] = x;
    ps->size++;

}

void SeqListPopFront(SL* ps)
{
    assert(ps);
    int start = 0;
    while (start < ps->size-1){
        ps->a[start] = ps->a[start+1];
        start++;
    }

    ps->size--;
}

//任意位置的插入和删除
void SeqListInsert(SL* ps,int pos,SLDataType x)
{
    assert(ps);
    assert(pos<=ps->size && pos >= 0);
    SeqListCheckCapacity(ps);
    int end = ps->size-1;
    while(end>=pos){
        ps->a[end+1] = ps->a[end];
        end--;
    }
    ps->a[pos]  = x;
    ps->size++;
}

void SeqListErase(SL* ps,int pos)
{
    assert(ps);
    assert(pos<ps->size && pos >= 0);
    int start = pos;
    while(start<ps->size-1)
    {
       ps->a[start] = ps->a[start+1];
       start++;
    }
    ps->size--;
}

//顺序表查找
int SeqListFind(SL*ps,SLDataType x)
{
    assert(ps);
    int i = 0;
    while(i<ps->size)
    {
        if(ps->a[i] == x)
        {
            return i;
        }
        i++;
    }
    return -1;
}