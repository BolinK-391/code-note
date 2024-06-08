#pragma once
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>


typedef int LTDataType;
typedef struct ListNode
{
    struct ListNode* next;
    struct ListNode* prev;
    int data;
}ListNode;

//void ListInit(ListNode** pphead);
ListNode *ListInit();

void ListClear(ListNode* phead);
void ListDestroy(ListNode** pphead);

//注意：这里的phead是一个头指针，里面不会存储有效数据，只是找一个起点位置。
//所以打印的时候是从phead->next开始的，头插也是从phead->next开始的

ListNode* BuyListNode(LTDataType x);
void ListPrint(ListNode* phead);

void ListPushBack(ListNode* phead,LTDataType x);
void ListPopBack(ListNode* phead);
void ListPushFront(ListNode* phead,LTDataType x);
void ListPopFront(ListNode* phead);

ListNode *ListFind(ListNode* phead,LTDataType x);
//在pos前面插入x
void ListInsert(ListNode* pos,LTDataType x);
void ListErase(ListNode* pos);