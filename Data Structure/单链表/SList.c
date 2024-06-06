#include "SList.h"

SListNode* BuySListNode(SListDataType x){
    SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
    if(newNode == NULL){
        printf("申请失败\n");
        exit(-1);
    }
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void SListPushBack(SListNode** pphead,SListDataType x)
{
    SListNode* newNode = BuySListNode(x);
    if(*pphead == NULL){
        *pphead = newNode;
    }
    else{
        //找到尾
        SListNode* tail = *pphead;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}
void SListPopBack(SListNode** pphead)
{
    //1.空
    //2.一个结点
    //3.一个以上结点/
    if(*pphead == NULL)
    {
        return;
    }
    else if((*pphead)->next == NULL)
    {
        free(*pphead);
        *pphead = NULL;
    }
    else
    {
        SListNode* prev = NULL;
        SListNode* tail = *pphead;
        while(tail->next != NULL)
        {
            prev = tail;
            tail = tail->next;
        }
        free(tail);
        prev->next = NULL;
    }
}

void SListPushFront(SListNode** pphead,SListDataType x)
{
    SListNode* newnode = BuySListNode(x);
    newnode->next = *pphead;
    *pphead = newnode;
}
void SListPopFront(SListNode** pphead)
{
    //1.空
    //2.一个结点 + 3.一个以上的节点

    if(*pphead == NULL)
    {
        return;
    }
    else
    {
        SListNode* next = (*pphead)->next;
        free(*pphead);

        *pphead = next;
    }
}


void SListPrint(SListNode* phead)
{
    SListNode* cur = phead;
    while(cur != NULL)
    {
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void SListSize(SListNode* phead);

//单链表查找
SListNode* SListFind(SListNode* phead,SListDataType x)
{
    SListNode* cur = phead;
    while (cur)
    {
        if(cur->data == x)
        {
            return cur;
        }

        cur = cur->next;
    }
    return NULL;
}

// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SListDataType x)
{
    assert(pos);

    SListNode* newnode = BuySListNode(x);
    newnode->next = pos->next;
    pos->next = newnode;
}

// 单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos)
{
    assert(pos);
    if(pos->next)
    {
        SListNode* next = pos->next;
        SListNode* nextnext = next->next;
        pos->next = nextnext;
        free(next);
    }
}

SListNode* reverseList(SListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    SListNode* n1 = NULL,*n2 = head,*n3 = head->next;
    while(n2)
    {
        //反转
        n2->next = n1;

        //迭代
        n1 = n2;
        n2 = n3;
        if(n3)
            n3 = n3->next;
    }
    return n1;
}

//移除链表元素
SListNode* removeElements(SListNode* head, int val)
{
    SListNode* prev = NULL,*cur = head;
    while(cur)
    {
        if(cur->data == val)
        {
            //if(cur == NULL)
            if(cur == head)
            {
                head = cur->next;
                free(cur);
                cur = head;
            }
            else
            {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}

//链表的中间结点
SListNode* middleNode(SListNode* head)
{
    SListNode* slow = head;
    SListNode* fast = head->next;

    while (fast && fast->next)//继续的条件<不是结束的条件>
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//输出该链表中倒数第k个结点
SListNode* FindKthToTail(SListNode* head, int k)
{
    SListNode* fast = head,*slow = head;
    while(k--)
    {
        if(fast)
            fast = fast->next;
        else
            return NULL;
    }

    while(fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

SListNode* Partition(SListNode* head,int x)
{
    SListNode* lessHead,*lessTail;
    SListNode* greaterHead,*greaterTail;
    lessHead = lessTail = (SListNode*)malloc(sizeof(SListNode));
    greaterHead = greaterTail = (SListNode*)malloc(sizeof(SListNode));
    lessHead->next = greaterHead->next = NULL;

    SListNode *cur = head;
    while(cur)
    {
        if(cur->data < x)
        {
            lessTail->next = cur;
            lessTail = lessTail->next;
        }

        else
        {
            greaterTail->next = cur;
            greaterTail = greaterTail->next;
        }
        cur = cur->next;
    }

    lessTail->next = greaterHead->next;
    greaterTail->next = NULL;
    SListNode *list = lessHead->next;
    free(lessHead);
    free(greaterHead);

    return list;
}