#include <stdio.h>

int main(){
   int arr[] = {1,2,(3,4),5};
    printf("%d\n",sizeof(arr));
    return 0;
}

//逗号表达式
//逗号表达式，就是用逗号隔开的多个表达式。
//逗号表达式，从左向右依次执行。整个表达式的结果是最后一个表达式的结果。
//所以arr[2] = (3,4) = 4