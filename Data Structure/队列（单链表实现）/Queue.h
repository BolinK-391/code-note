#pragma once
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>


typedef int QDataType;


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
QDataType QueueEmpty(Queue* pq);

QDataType QueueSize(Queue* pq);