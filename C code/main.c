#include <stdio.h>

int main() {
    int flag = 0;
    scanf("%d",&flag);

    //flag为真,打印haha
    if(flag)
    {
        printf("haha\n");
    }

    //flag为假,打印hehe
    if(!flag)
    {
        printf("hehe\n");
    }

    void function(int *a);

    function(&flag);

    return 0;
}

//单目操作符：逻辑反操作符 !
//若a = 0 则 !a = 1
//若a = 1 则 !a = 0

//单目操作符：对一个数的二进制按位取反 ~
//注意 ~ 是对保存在内存条里的补码取反，不是对原码

void function(int *a){

    //把a的二进制中的第5位置改为1
    *a = *a | (1 << 4); //按位或 | 相异取1，相同取0

    //把a的二进制中的第5位置改为0
    *a = *a & ~(1 << 4); //按位与 & 相同取1，相异取0
}
