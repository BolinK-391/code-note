#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//动态顺序表设计(大小可变)
typedef int SLDataType;

//vector
typedef struct SeqList{
    SLDataType* a; //指向动态开辟的数组
    int size;      //有效数据的个数
    int capacity;  //容量空间的大小
}SL,SeqList;

//初始化
void SeqListInit(SL* s);

//打印
void SeqListPrint(SL*ps);

//检查扩容
void SeqListCheckCapacity(SL*ps);

//销毁
void SeqListDestory(SL*ps);

//尾插尾删  头插头删
void SeqListPushBack(SL* ps,SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps,SLDataType x);
void SeqListPopFront(SL* ps);

//任意位置的插入和删除
void SeqListInsert(SL* ps,int pos,SLDataType x);
void SeqListErase(SL* ps,int pos);

//顺序表查找
int SeqListFind(SL*ps,SLDataType x);