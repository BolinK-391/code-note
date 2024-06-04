//整数的 数组形式  num 是按照从左到右的顺序表示其数字的数组。

//例如，对于 num = 1321 ，数组形式是 [1,3,2,1] 。
//给定 num ，整数的 数组形式 ，和整数 k ，返回 整数 num + k 的 数组形式 。

//输入：num = [1,2,0,0], k = 34
//输出：[1,2,3,4]
//解释：1200 + 34 = 1234

//输入：num = [2,7,4], k = 181
//输出：[4,5,5]
//解释：274 + 181 = 455

//输入：num = [2,1,5], k = 806
//输出：[1,0,2,1]
//解释：215 + 806 = 1021

#include <stdio.h>
#include <malloc.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* num, int numSize, int k, int* returnSize)
{
    int KSize = 0;
    int kNum = k;
    while(kNum)
    {
        KSize++;
        kNum /= 10;
    }

    int len = numSize>KSize?numSize+1:KSize+1;
    int* retArr = (int*)malloc(sizeof(int)*(len+1));

    //A[]
    //k[]
    int i = numSize-1;
    int reti = 0;
    int nextNum = 0;//进位
    while(len--)
    {
        int a = 0;
        if(i>=0){
            a = num[i];
            i--;
        }

        int ret = a + k%10 + nextNum;
        k /= 10;
        if(ret > 9)
        {
            ret -= 10;
            nextNum = 1;

        }
        else
        {
            nextNum = 0;
        }

        retArr[reti] = ret;
        reti++;
    }

    if(nextNum == 1)
    {
        retArr[reti] = 1;
        reti ++;
    }

    //逆置数组
    int left = 0,right = reti-1;
    while(left < right)
    {
        int tmp = retArr[left];
        retArr[left] = retArr[right];
        retArr[right] = tmp;
        left++;
        right--;
    }
    *returnSize = reti;
    return retArr;
}

int main()
{
    int num[2] = {9,9};
    int k = 3129;
    int a = 0;
    int* arr = addToArrayForm(num,2,k,&a);

    for(int i = 1 ; i < a ; i++)
    {
        printf("%d ",arr[i]);
    }

}