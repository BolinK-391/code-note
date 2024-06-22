#include "Sort.h"
#include "Stack.h"

// 排序实现的接口


// 插入排序
//时间复杂度：O(N^2) < 1+2+...+n-1  (首项+末项)*项数/2 >
//空间复杂度：O(1)
void InsertSort(int* a, int n)
{
    assert(a);

    for(int i = 0; i < n-1; ++i) {

        //单趟排序

        //[0,end]有序
        //把 end + 1 往 [0,end] 区间插入保持它有序
        int end = i;
        int tmp = a[end + 1];
        while (end >= 0)
        {
            if (tmp < a[end])
            {
                a[end + 1] = a[end];
                end--;
            }
            else
            {
                break;
            }
        }
        a[end + 1] = tmp;
    }
}


// 希尔排序
//1、预排序
//2、直接插入排序
//时间复杂度：O(N^1.3 ~ N ^2)
void ShellSort(int* a, int n)
{
    //1、gap > 1相当于预排序，让数组接近有序
    //2、gap == 1就相当于直接插入排序，保证有序

    int gap = n;
    while(gap > 1)
    {
        gap = gap / 3 + 1;//+1保证了最后一次gap一定是1
        //gap == 1最后一次就相当于直接插入排序

        //gap越大，前面大的数据可以越快到后面，后面小的数，可以越快到前面。
        //gap越大，越不接近有序。gap越小越接近有序。如果 gap == 1其实就相当于直接插入排序，就有序了。

        //多组并排
        for (int i = 0; i < n - gap; ++i)
        {
            int end = i;
            int tmp = a[end + gap];
            while (end >= 0)
            {
                if (tmp < a[end])
                {
                    a[end + gap] = a[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
            a[end + gap] = tmp;
        }
        //PrintArray(a,n);
    }
}


// 选择排序
void SelectSort(int* a, int n)
{
    assert(a);

    int begin = 0 , end = n - 1;
    while(begin < end)
    {
        //在[begin,end]之间找出最小的数和最大的数的下标
        int mini,maxi;
        mini = maxi = begin;
        for(int i = begin+1; i <= end; ++i)
        {
            if(a[i] > a[maxi])
                maxi = i;
            if(a[i] < a[mini])
                mini = i;

        }

        //注意：这种写法下：maxi和mini、end和begin位置有重叠，交换就会出问题。
        //Swap(&a[begin],&a[mini]);
        //Swap(&a[end],&a[maxi]);

        Swap(&a[begin],&a[mini]);

        //如果max和begin位置重叠，则maxi的位置需要修正
        if(begin == maxi)
            maxi = mini;

        Swap(&a[end],&a[maxi]);

        begin++;
        end--;
    }
}

// 堆排序
void AdjustDwon(int* a, int n, int root)
{
    //向下调整算法
    int parent = root;
    int child = parent * 2 + 1;
    while(child < n)
    {
        if(child+1 < n && a[child+1] > a[child])
            child++;
        if(a[child] > a[parent])
        {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }

}
void HeapSort(int* a, int n)
{
    //排升序，建大堆还是小堆？大堆。（建大堆后将根和第n个数交换后，再对前n-1个数再次建大堆）
    for(int i = (n-1-1)/2; i >= 0; i--)
    {
        AdjustDwon(a,n,i);
    }
    int end = n - 1;
    while (end > 0)
    {
        Swap(&a[0],&a[end]);
        AdjustDwon(a,end,0);
        end--;
    }
}

// 冒泡排序
//时间复杂度：O(N^2)
//空间复杂度：O(1)
void BubbleSort(int* a, int n)
{
    int end = n;
    while (end > 0)
    {
        int exchange = 0;
        for (int i = 1; i < n; ++i)
        {
            if (a[i - 1] > a[i])
            {
                Swap(&a[i - 1], &a[i]);
                exchange = 1;
            }
        }

        //如果一趟冒泡的过程中没有发生交换，则前部分已经有序，不需要再冒泡
        if(exchange == 0)
        {
            break;
        }
    }
}

// 快速排序递归实现

// 快速排序hoare版本 (左右指针法)
int PartSort1(int* a, int begin, int end)//[begin,end]
{
    //升序

    //单趟
    //1、左边比key小，右边比key大
    //2、key放到他正确的位置（最终要放的位置）

    //实际中无法保证选key是中位数
    //三数取中 保证不要选到最小或者最大，让有序时变成最优
    //最坏的情况不再会出现
    //综合而言时间复杂度为O(N*logN)  <不是O(N^2)>
    int midInex = GetMidIndex(a,begin,end);
    Swap(&a[midInex],&a[end]);

    int keyindex = end;
    while(begin < end)
    {
        //begin找大

        //选最右边的值做key
        //那么一定要让左边begin先走
        //这样能保证他们相遇的位置
        //是一个比key大的位置

        //选最左边的值做key
        //同理要让右边end先走
        //...

        while(begin < end && a[begin] <= a[keyindex])
        {
            begin++;
        }

        while(begin < end && a[end] >= a[keyindex])
        {
            end--;
        }

        Swap(&a[begin],&a[end]);
    }
    Swap(&a[begin],&a[keyindex]);
    return begin;
}

// 快速排序挖坑法
int PartSort2(int* a, int begin, int end)
{

    //三数取中
    int midInex = GetMidIndex(a,begin,end);
    Swap(&a[midInex],&a[end]);

    int hole = a[end];//坑
    while(begin < end)
    {
        while(begin < end && a[begin] <= hole)
            begin++;

        //左边找到比hole大的数填进右边的坑里，begin处的位置形成新的坑
        a[end] = a[begin];

        while(begin < end && a[end] >= hole)
            end--;

        //右边找到比hole大的数填进左边的坑里，end处的位置形成新的坑
        a[begin] = a[end];
    }

    a[begin] = hole;

    return begin;

}

// 快速排序前后指针法
int PartSort3(int* a, int begin, int end)
{
    //cur找到比key小的就停下来
    //然后prev++，然后cur和prev位置的值交换

    //这个过程像，cur找小跟prev++位置的值交换，把小的翻到左边，把大的往后推

    //注意一开始的prev指针没有指向begin，还没有进场

    int cur = begin;
    int prev = begin - 1;

//    //三数取中
//    int midInex = GetMidIndex(a,begin,end);
//    //Swap(&a[midInex],&a[end]);
//    int key = a[midInex];

    int keyindex = end;
    while(cur < end)
    {
        if(a[cur] < a[keyindex] && ++prev != cur)
            Swap(&a[prev],&a[cur]);
        cur++;
    }

    Swap(&a[++prev],&a[keyindex]);//当cur走到end的时候表面，prev和prev之前的值都比key<end>要小了，所以把key<end>值直接排在prev后面


    return prev;
}

//时间复杂度O(N*logN)
//空间复杂度O(logN)  深度

void QuickSort(int* a, int left, int right)
{
    assert(a);
    if(left >= right)
        return;

    //优化
    //小区间使用插入排序去排
    //不再使用快速排序的递归排
    //减少整体的递归次数
    if((right - left + 1) > 10)
    {
        int div = PartSort3(a,left,right);

        //[left,div-1] div [div+1,right]
        QuickSort(a,left,div-1);
        QuickSort(a,div + 1,right);
    }
    else
    {
        //小于等于10个以内的区间，不再递归排序

        //插入排序
        InsertSort(a + left, right - left + 1);
    }

}

// 快速排序 非递归实现 —— 1、改循环(斐波那契数列求解) 一些简单递归才能改循环 2、栈模拟存储数据非递归
//递归调用压栈也是后进先出，数据结构的栈也是后进先出，能达到一样的效果是因为二者的性质相同，所以所有的递归都可以改成非递归

//非递归：
//1、提高效率
//2、递归的最大缺陷：若栈帧的深度太深，可能会导致栈溢出。因为系统栈空间一般不大，在M级别
//   数据结构栈模拟非递归，数据是存储在堆上的，堆是G级别的空间

void QuickSortNonR(int* a, int left, int right)
{
    //栈模拟实现 (借助栈保存区间)
    Stack st;
    StackInit(&st);

    StackPush(&st,right);
    StackPush(&st,left);

    while(!StackEmpty(&st))
    {
        int begin = StackTop(&st);
        StackPop(&st);
        int end = StackTop(&st);
        StackPop(&st);

        //[begin,end]
        //单趟排
        int div = PartSort3(a,begin,end);
        //[begin,div-1] div [div+1,end]

        //入栈
        if(div+1 < end)//至少有两个值
        {
            StackPush(&st,end);
            StackPush(&st,div + 1);
        }
        //后进先出
        if(begin < div-1)
        {
            StackPush(&st,div-1);
            StackPush(&st,begin);
        }
        //先处理左区间，左区间都处理完了再处理右区间
    }
    StackDestroy(&st);
}

// 归并排序递归实现
//时间复杂度：O(N*logN)
//空间复杂度：O(logN)
void _MergeSort(int* a,int left,int right,int* tmp)
{
    if(left >= right)
        return;

    int mid = (left + right) / 2;
    //[left,mid] [mid+1,right] 有序，则可以合并，现在他们没有序，子问题解决
    _MergeSort(a,left,mid,tmp);
    _MergeSort(a,mid+1,right,tmp);
    //先分到不可分割后再归并

    //归并[left,mid] [mid+1,right] 有序
    MergeArr(a,left,mid,mid+1,right,tmp);
}

void MergeSort(int* a, int n)
{
    assert(a);
    int *tmp = malloc(sizeof (int)*n);

    _MergeSort(a,0,n-1,tmp);

    free(tmp);
}

// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
    assert(a);
    int* tmp = malloc(sizeof (int)*n);
    int gap = 1;

    while(gap < n)
    {
        for (int i = 0; i < n; i += 2 * gap) {
            //[i,i+gap) [i+2*gap)
            //[i,i+gap-1] [i+2*gap-1]

            int begin_1 = i,end_1 = i + gap -1;
            int begin_2 = i + gap,end_2 = i + 2*gap -1;

            //1、合并时只有第一组，就不需要合并
            if(begin_2 >= n)
                break;
            //2、合并时只有第二组只有部分数据，需要修正end_2边界
            if(end_2 >= n)
                end_2 = n - 1;

            MergeArr(a, begin_1, end_1, begin_2, end_2, tmp);
        }
        gap *= 2;
    }
    free(tmp);
}

// 计数排序
//时间复杂度：O(MAX(N,范围))
//空间复杂度：O(范围)
//只适用于整形，如果浮点数或者字符串排序，还得用比较排序
void CountSort(int* a,int n)
{
    assert(a);

    int min = a[0];
    int max = a[0];
    for(int i = 1; i < n; ++i)
    {
        if(a[i] > max)
            max = a[i];
        if(a[i] < min)
            min = a[i];
    }

    int range = max - min + 1;
    int *countArr = malloc(sizeof(int)*range);
    memset(countArr,0,sizeof (int)*range);

    //统计次数
    for(int i = 0; i < n; ++i)
    {
        countArr[a[i] -min]++;
    }

    //排序
    int index = 0;
    for(int j = 0;j < range; ++j)
    {
        while(countArr[j]--)
            a[index++] = j + min;
    }

    free(countArr);
}


void PrintArray(int* a,int n)
{
    for(int i = 0; i < n; i ++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void Swap(int *p1,int *p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int GetMidIndex(int *a,int begin,int end)
{
    int mid = (begin + end) / 2;
    if(a[begin] < a[mid])
    {
        if(a[mid] < a[end])
            return mid;
        else if(a[begin] > a[end])
            return begin;
        else
            return end;
    }
    else//a[begin] > a[mid]
    {
        if(a[mid] > a[end])
            return mid;
        else if(a[begin] < a[end])
            return begin;
        else
            return end;

    }
}

void MergeArr(int* a, int begin_1, int end_1, int begin_2, int end_2, int* tmp)
{
    //归并[left,mid] [mid+1,right] 有序
    int left = begin_1 , right = end_2;
    int index = begin_1;
    while (begin_1 <= end_1 && begin_2 <= end_2)
    {
        if(a[begin_1] < a[begin_2])
            tmp[index++] = a[begin_1++];  //若 i=3 ，a[++i](先自增后读取) = a[4] ; a[i++](先读取后自增) = a[3] i=4
        else
            tmp[index++] = a[begin_2++];
    }

    while (begin_1 <= end_1)
        tmp[index++] = a[begin_1++];

    while (begin_2 <= end_2)
        tmp[index++] = a[begin_2++];

    //把归并好的在tmp的数据再拷贝回到原数组
    for(int i = left;i <= right;i++)
    {
        a[i] = tmp[i];
    }
}

void _MergeFile(const char* file_1,const char* file_2,const char* mergeFile)
{
    FILE *fout1 = fopen(file_1,"r");
    if(fout1 == NULL)
    {
        printf("打开文件失败\n");
        exit(-1);
    }

    FILE *fout2 = fopen(file_1,"r");
    if(fout2 == NULL)
    {
        printf("打开文件失败\n");
        exit(-1);
    }

    FILE *fin = fopen(mergeFile,"w");
    if(fin == NULL)
    {
        printf("打开文件失败\n");
        exit(-1);
    }

    int num1,num2;
    int ret1 = fscanf(fout1,"%d\n",&num1);
    int ret2 = fscanf(fout2,"%d\n",&num2);
    while (ret1 != EOF && ret2 != EOF)
    {
        if(num1 < num2)
        {
            fprintf(fin, "%d\n", num1);
            ret1 = fscanf(fout1,"%d\n",&num1);
        }
        else
        {
            fprintf(fin, "%d\n", num2);
            ret2 = fscanf(fout1, "%d\n", &num1);
        }
    }
    while(ret1 != EOF)
    {
        fprintf(fin, "%d\n", num1);
        ret1 = fscanf(fout1,"%d\n",&num1);
    }
    while(ret2 != EOF)
    {
        fprintf(fin, "%d\n", num2);
        ret2 = fscanf(fout1, "%d\n", &num1);
    }

    fclose(fout1);
    fclose(fout2);
    fclose(fin);
}

const char* MergeSortFile(const char* file)
{
    FILE *fout = fopen(file,"r");
    if(fout == NULL)
    {
        printf("打开文件失败\n");
        exit(-1);
    }

//分割成一段一段数据，内存排序后写到小文件
    int n = 10;
    int a[10];
    int i = 0;
    int num = 0;
    const char subfile[20];
    int filei = 0;
    while(fscanf(fout,"%d\n",&num) !=EOF)
    {
        if(i < n-1)
            a[i++] = num;
        else
        {
            a[i] = num;
            QuickSort(a, 0, n - 1);
            sprintf(subfile,"%d",filei++);
            FILE *fin = fopen(subfile,"w");
            for(int i = 0;i < n; i++)
                fprintf(fin,"%d\n",a[i]);
            fclose(fin);
            i = 0;
            memset(a,0,sizeof (int)*n);
        }
    }

    //利用互相归并到文件，实现整体有序
    char mergeFile[100] = "12";
    char file_1[100] = "1";
    char file_2[100] = "2";
    for(int i = 2; i < n; ++i)
    {
        //读取file_1和file_2,进行归并出mergeFile
        _MergeFile(file_1,file_2,mergeFile);

        strcpy(file_1,mergeFile);
        sprintf(file_2,"%d",i + 1);
        sprintf(mergeFile,"%s%d",mergeFile,i + 1);
    }
    fclose(fout);
}