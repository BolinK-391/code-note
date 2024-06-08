#include "Stack.h"

//栈的作用：
//1.如果有后进先出需求的地方，比如迷宫问题
//2.递归改成非递归


void TestStack()
{
    Stack st;

    //后进先出是相对入的时候在栈里面的数据
    StackInit(&st);
    StackPush(&st,1);
    StackPush(&st,2);
    StackPush(&st,3);
    printf("%d ", StackTop(&st));
    StackPop(&st);
    StackPush(&st,4);
    StackPush(&st,5);

    while (!StackEmpty(&st))//栈不等于空
    {
        printf("%d ", StackTop(&st));
        StackPop(&st);
    }
    printf("\n");
    StackDestroy(&st);
}

int main()
{
    TestStack();
    return 0;
}