#include <stdio.h>
#include <string.h>
void change(int *pa,int *pb){
    int t = *pa;
    *pa = *pb;
    *pb = t;
}

int main ()
{
    int a = 10;
    int b = 20;
    printf("%d%d",a,b);
    change(&a,&b);//这里不用指针的话，变量a、b进入函数change地址会发生改变，不是原来的&a、&b。
    printf("\n%d%d",a,b);
    return 0;
}
