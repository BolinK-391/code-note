#include "Queue.h"

//队列的作用：
//1.如果有先进先出需求的地方，比如要保持序列公平，排队抽号机
//2.广度优先遍历


void TestQueue()
{
    Queue q;
    QueueInit(&q);
    QueuePush(&q,1);
    QueuePush(&q,2);
    QueuePush(&q,3);
    QueuePush(&q,4);
    QueuePush(&q,5);

    while (!QueueEmpty(&q))
    {
        printf("%d ", QueueFront(&q));
        QueuePop(&q);
    }
    printf("\n");

    QueueDestroy(&q);



}

int main()
{
    TestQueue();
    return 0;
}