#pragma once
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>

typedef int SListDataType;
//结点
typedef struct SListNode
{
    SListDataType data;
    struct SListNode* next;
}SListNode;


SListNode* BuySListNode(SListDataType x);

void SListPushBack(SListNode** pphead,SListDataType x);
void SListPopBack(SListNode** pphead);

void SListPushFront(SListNode** pphead,SListDataType x);
void SListPopFront(SListNode** pphead);

void SListPrint(SListNode* phead);

//单链表查找
SListNode* SListFind(SListNode* phead,SListDataType x);

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SListDataType x);


// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos);

//反转单链表
//输入：head = [1,2,3,4,5]
//输出：[5,4,3,2,1]
SListNode* reverseList(SListNode* head);


//移除链表元素
//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

//输入：head = [1,2,6,3,4,5,6], val = 6
//输出：[1,2,3,4,5]
SListNode* removeElements(SListNode* head, int val);


//链表的中间结点
//给你单链表的头结点 head ，请你找出并返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点。
SListNode* middleNode(SListNode* head);

//输出该链表中倒数第k个结点
SListNode* FindKthToTail(SListNode* head, int k);

//现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，
//且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
SListNode* Partition(SListNode* head,int x);
//哨兵位的头结点(不存储有效数据 仅提供接口  不需要二级指针)
