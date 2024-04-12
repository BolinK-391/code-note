#include "stdio.h"
//指针类型决定了指针的运算！

//由于还没学习结构体，这里告知结构体的大小是20个字节

struct Test
{
    int Num;
    char *pcName;
    short sDate;
    char cha[2];
    short sBa[4];
}*p;//这是一个指向结构体Test的指针

//假设p 的值为0x100000。 如下表表达式的值分别为多少？
//已知，结构体Test类型的变量大小是20个字节

int main() {
    printf("%p\n", p + 0x1);//+1 --> +20
                                  //0x100000 + 20 --> 0x100014 (十六进制)

    printf("%p\n", (unsigned long) p + 0x1);//强制转化为 无符号整型类型 [注意不是整型类型的指针！]
                                                  //+1就是加一个整型1
                                                  //0x100001

    printf("%p\n", (unsigned int *) p + 0x1);//强制转化为指向无符号整型类型的指针
                                                   //+1 --> +4
                                                   //0x100004
    return 0;
}