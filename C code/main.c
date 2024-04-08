#include "stdio.h"
int main(){
    char str1[] = "hello bit.";
    char str2[] = "hello bit.";

    char* str3 = "hello bit.";//常量字符串(无法更改 )
    char* str4 = "hello bit.";
    //由于str3和str4都是常量字符串并且内容相同，
    //所以"hello bit."在内存中只有一份，
    //str3和str4都是指向同一个地址

    if(str1 == str2)//取两个的地址
        printf("str1 and str2 are same\n");
    else
        printf("str1 and str2 are not same\n");

    if(str3 == str4)//取两个的地址
        printf("str3 and str4 are same\n");
    else
        printf("str3 and str4 are not same\n");
}

//这里str3和str4指向的是一个同一个常量字符串。C/C++会把常量字符串存储到单独的一个内存区域，
//当几个指针指向同一个字符串的时候，他们实际会指向同一块内存。
//但是用相同的常量字符串去初始化不同的数组的时候就会开辟出不同的内存块。
//所以str1和str2不同，str3和str4不同。