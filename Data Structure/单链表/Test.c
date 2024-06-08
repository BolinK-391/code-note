#include "SList.h"

void TestSList1()
{
    SListNode* pList = NULL;
    SListPushBack(&pList,1);
    SListPushBack(&pList,2);
    SListPushBack(&pList,3);
    SListPrint(pList);
    SListPopBack(&pList);
    SListPrint(pList);
    SListPushFront(&pList,3);
    SListPrint(pList);
    SListPrint(pList);

    //查找充当修改
    SListNode* pos = SListFind(pList,2);
    if(pos)
    {
        pos->data = 30;
    }
    SListPrint(pList);


    SListNode* pos_1 = SListFind(pList,1);
    if(pos_1)
    {
        SListInsertAfter(pos_1, 233);
    }
    SListPrint(pList);

    pList = reverseList(pList);
    SListPrint(pList);
    SListPushBack(&pList,1);
    SListPushBack(&pList,2);
    SListPushBack(&pList,3);
    SListPrint(pList);
    SListNode* pos_2 = removeElements(pList,3);
    SListPrint(pos_2);

    SListNode* middle = middleNode(pList);
    printf("%d\n",middle->data);
    SListNode* num = FindKthToTail(pList,5);
    printf("%d\n",num->data);

    SListPushBack(&pList,1);
    SListPushBack(&pList,2);
    SListPushBack(&pList,3);
    SListPrint(pList);
    SListNode *a = Partition(pList,2);
    SListPrint(a);



}

int main()
{

    TestSList1();

    return 0;
}
