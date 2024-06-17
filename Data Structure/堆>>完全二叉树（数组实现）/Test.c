#include "Stack.h"


int main()
{
    int array[] = {27,15,19,18,28,34,65,49,25,37};
    Heap hp;
    HeapInit(&hp,array,sizeof(array)/sizeof (HPDataType));
    HeapPush(&hp,13);

    for(int i = 0 ; i < 10 ; i++)
    {
        printf("%d ", hp._a[i]);
    }

    printf("\n");
    int k = 5;
    int *retArr = getLeastNumbers(hp._a,hp._size,k);
    for(int i = 0 ; i < 5 ; i++)
    {
        printf("%d ", retArr[i]);
    }
    HeapDestroy(&hp);

    return 0;
}

//TopK问题
//100个数，选出最小的前10个数
//N个数，选出最小的前K个数

//1、堆排序  时间复杂度O(N*logN)
//2、建堆 >> 100个数的小堆 , HeapPop 9次 , 就选出来了  O(N+K*logN)   N+(K-1)*logN

//再优化 >> 假设N是10个亿，假设内存中存不下这些值，这些值在文件中。K是10

//3、建K个数一个大堆，然后10亿数跟堆顶比较，比堆顶小就替换堆顶的数，再向下调整。
//最后，K个的大堆中值就是最小的前K个  时间复杂度O(N*logK)
