#include <stdio.h>
//交换两个int变量的值,不能使用第三个变量.
//即 a = 3, b = 5,交换之后 a = 5, b = 3;

int main() {
    int a = 3;
    int b = 5;
    printf("a = %d b = %d\n",a,b);

    //方法一
//    void First(int *a,int *b);
//    First(&a,&b);

    //方法二
//位操作符  ^异或(二进制位相异为1，相同为0)
    void Second(int *a,int *b);
    Second(&a,&b);

   int c = 3;
   c ^ c;
   //011
   //011
   //000
//任何两个相同的数字异或一定是0
   0 ^ c;
    //000
    //011
    //011
//0和任何的数字异或一定是数字本身


    return 0;
}


void First(int *a,int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    printf("a = %d b = %d\n",*a,*b);
}
//缺陷:数值太大会溢出
//第二种方法就不会溢出，因为没有进位
void Second(int *a,int *b){
    *a = *a ^ *b;
    // = a ^ b ^ b = a ^ 0 = a
    *b = *a ^ *b;
    // = a ^ b ^ a = b ^ 0 = b
    *a = *a ^ *b;
    printf("a = %d b = %d\n",*a,*b);
}

//关于位操作符：
    // & >>按位与
    // | >>按位或
    // ^ >>按位异或
    //注：他们的操作数必须是整数。