#include "stdio.h"

int i;
//i是全局变量，不初始化，默认是0

int main(){
    i--;
    //-1
    if(i>sizeof(i)){
        //-1>4
        //sizeof这个操作符，算出的结果的类型是unsigned int
        //有符号整型和无符号整型比较大小的时候会把有符号先转换成无符号整型再进行比较

        printf(">\n");
    }
    else
    {
        printf("<\n");
    }
    return 0;
}