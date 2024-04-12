#include "stdio.h"
int main(){
    int a[5] = {1,2,3,4,5};
    int* ptr = (int*)(&a + 1);
    printf("%d,%d",*(a + 1),*(ptr - 1));
    return 0;
}


//原本的 (&a + 1) 类型是 int(*)[5] <数组指针类型>
//强制类型转换成 int* 以后就变成a[5]+1的地址
//ptr-1以后就是a[5]的地址