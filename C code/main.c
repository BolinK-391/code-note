#include <stdio.h>

//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字。
//1 2 3 4 5 6 1 2 3 4

void Find(int arr[],int sz,int* pz,int*py){

    //1.要把所有数字异或
    int i = 0;
    int ret = 0;
    for(i=0;i<sz;i++){
        ret ^= arr[i];
    } 
    //2.计算ret的哪一位为1
    //ret = 3
    //011
    int pos = 0;
    for(i=0;i<32;i++){
        if(((ret >> i)&1)==1){//"&"只有两者对应位都为"1"，结果对应位才为1，否则为0
            pos = i;
            break;
        }
    }
    //把从低位向高的第pos位为1，为0的放在另外一个组。
    int num1 = 0;
    int num2 = 0;
    for(i=0;i<sz;i++){
        if(((arr[i] >> pos)&1)==1){
        num1 ^= arr[i];
        //"^"只有两者对应位不一样(即一个为1，一个为0)，则结果对应位才为1，否则为0
        //所以分组后如果一个组内出现一样的话异或结果为0，不一样就留下
        }

        else{
        num2 ^= arr[i];
    }
        *pz = num1;
        *py = num2;
    }

}


int main(){
    int arr[] = {1,2,3,4,5,6,1,2,3,4};
    //1.分组
    //2.分组的要点：5和6必须在不同的组
    //
    //找出这两个只出现一次的数字

    int sz = sizeof(arr)/sizeof(arr[0]);
    int x = 0;
    int y = 0;
    Find(arr,sz,&x,&y);
    printf("%d %d",x,y);
    return 0;
}