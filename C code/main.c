#include <stdio.h>

#define OFFSETOF(struct_name,mem_name) (int)&(((struct_name*)0)->mem_name)//假设起始位置的地址是0x0
//写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明

struct A
{
    int a;
    short b;
    int c;
    char d;
};

int main(){
    printf("%d\n",OFFSETOF(struct A,d));
    return 0;
}
