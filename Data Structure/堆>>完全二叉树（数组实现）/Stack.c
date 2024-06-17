#include "Stack.h"

void Swap(HPDataType* p1,HPDataType* p2)
{
    HPDataType tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

//前提：左右子树的都是小堆
void AdjustDown(HPDataType * a,int n,int root)
{
    //找出左右孩子中小的那一个
    int parent = root;
    int child = parent*2 + 1;//左孩子

    while(child < n)
    {
        if (child+1 < n && a[child + 1] < a[child])//选出最小的孩子
        {
            ++child;//右孩子
        }

        if (a[child] < a[parent]) {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = parent*2 + 1;
        }
        else
        {
            break;
        }
    }
}

void AdjustUp(HPDataType * a,int n,int child)
{
    int parent = (child-1)/2;
    while (child > 0)
    {
        if(a[child] < a[parent])
        {
            Swap(&a[child],&a[parent]);
            child = parent;
            parent = (child-1)/2;
        }
        else
        {
            break;
        }
    }
}

void HeapInit(Heap* php,HPDataType* a,int n)
{
    php->_a = (HPDataType*)malloc(sizeof (HPDataType)*n);
    //...
    memcpy(php->_a,a,sizeof (HPDataType)*n);
    php->_size = n;
    php->_capacity = n;

    //构建堆
    for(int i = (n-1-1)/2;i >= 0;i--)
    {
        AdjustDown(php->_a,php->_size,i);
    }
    //时间复杂度
    //假设树有N个节点，树高度：logN
    //要注意这里时间复杂度不是N*logN，是O(N)

    int end = n - 1;
//    printf("%d\n",*(php->_a + end));
    while (end > 0)//降序小堆  升序大堆
    {
        Swap(php->_a, php->_a + end);

        //再继续选次小的
        AdjustDown(php->_a,end,0);
        end--;
    }

}

void HeapDestroy(Heap* php)
{
    assert(php);
    free(php->_a);
    php->_a = NULL;
    php->_capacity = php->_size = 0;
}

void HeapPush(Heap* php,HPDataType x)
{
    assert(php);
    if(php->_size == php->_capacity)
    {
        php->_capacity *= 2;
        HPDataType *tmp = (HPDataType*)realloc(php->_a,sizeof(HPDataType)*php->_capacity);
        //
        php->_a = tmp;
    }
    php->_a[php->_size++] = x;

    AdjustUp(php->_a,php->_size,php->_size-1);
}

void HeapPop (Heap* php)//原理同堆排序，只不过这里是真的删除最后一个数，而排序并没有删除（假删）
{
    assert(php);
    assert(php->_size > 0);

    Swap(&php->_a[0],&php->_a[php->_size - 1]);
    php->_size--;

    AdjustDown(php->_a,php->_size,0);
}

HPDataType HeapTop(Heap* php)
{
    assert(php);
    assert(php->_size > 0);

    return php->_a[0];
}

int* getLeastNumbers(int* arr,int arrSize,int k)
{
    if(k == 0)
        return NULL;

    int* retArr = (int*) malloc(sizeof (int)*k);

    //建k个的大堆
    for(int i = 0; i < k; ++i)
    {
        retArr[i] = arr[i];
    }
    for(int i = (k-1-1)/2; i >= 0; --i)
    {
        AdjustDown(retArr,k,i);
    }

    for(int j = k; j < arrSize; ++j)
    {
        if(arr[j] < retArr[0])
        {
            retArr[0] = arr[j];
            AdjustDown(retArr,k, 0);
        }
    }

    return retArr;
}