#include "Queue.h"

void QueueInit(Queue* pq)
{
    assert(pq);
    pq->_head = pq->_tail = NULL;
}

void QueueDestroy(Queue* pq)
{
    QueueNode *cur = pq->_head;
    while(cur)
    {
        QueueNode *next = cur->_next;
        free(cur);
        cur = next;
    }
    pq->_head = pq->_tail = NULL;
}


void QueuePush(Queue* pq,QDataType x)
{
    assert(pq);
    QueueNode *newnode = (QueueNode*)malloc(sizeof (QueueNode));
    if(newnode == NULL)
    {
        printf("内存不足\n");
        exit(-1);
    }
    newnode->_data = x;
    newnode->_next = NULL;
    if(pq->_head == NULL)
    {
        pq->_head = pq->_tail = newnode;
    }
    else
    {
        pq->_tail->_next = newnode;
        pq->_tail = newnode;
    }
}

void QueuePop(Queue* pq)
{
    assert(pq);
    assert(pq->_head);

    QueueNode *next = pq->_head->_next;
    free(pq->_head);
    pq->_head = next;

    if(pq->_head == NULL)
    {
        pq->_tail = NULL;
    }
}

QDataType QueueFront(Queue* pq)
{
    assert(pq);
    assert(pq->_head);

    return pq->_head->_data;
}
QDataType QueueBack(Queue* pq)
{
    assert(pq);
    assert(pq->_tail);

    return pq->_tail->_data;
}

//返回1是空，返回0是非空
int QueueEmpty(Queue* pq)
{
    assert(pq);
    return pq->_head == NULL ? 1 : 0;
}

int QueueSize(Queue* pq)
{
    assert(pq);

    QueueNode *cur = pq->_head;
    int size = 0;
    while (cur)
    {
        size++;
        cur = cur->_next;
    }
    return size;
}

