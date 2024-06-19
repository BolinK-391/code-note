#pragma once
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>


//声明一下
extern struct BinaryTreeNode;
typedef struct BinaryTreeNode* QDataType;

typedef int BTDataType;
typedef struct BinaryTreeNode
{
    BTDataType _data;
    struct BinaryTreeNode* _left;
    struct BinaryTreeNode* _right;
}BTNode;

int TreeSize_2(BTNode* root);

//typedef int QDataType;


typedef struct QueueNode
{
    struct QueueNode* _next;
    QDataType _data;
}QueueNode;

typedef struct Queue
{
    QueueNode *_head;
    QueueNode *_tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);


void QueuePush(Queue* pq,QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

//返回1是空，返回0是非空
int QueueEmpty(Queue* pq);

int QueueSize(Queue* pq);