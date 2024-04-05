#include <stdio.h>
//编写代码实现：求一个整数存储在内存中的二进制中1的个数。
//就是求补码的二进制中的1的个数

//使用 按位与操作符 & 和 右移操作符 >>
//就是把该整数与1进行按位与操作比较
//如果返回1就代表最低位为1，返回0就代表最低位为0
//然后右移整数的补码再与1进行按位与操作


//问题代码
int fuction_1(int n){
     int count = 0;
     while(n){
         if(n%2==1){
             count++;
         }
         n /= 2;
     }
     return count;
}
//这个函数仅对n为整数时有效，如果是负数不会计算其补码里的二进制1个数
//可以把 int 类型改为 unsigned(无符号整型)就可以计算负数

//优解
int fuction_2(int n){
    int count = 0;
    int i = 0;
    for(i;i<32;i++){
         if(((n>>i)&1) == 1)
             count++;

    }
    return count;
}

int fuction_3(int n){
    int count = 0;
    int i = 0;
   while(n){
       n = n & (n-1);//会去掉n的二进制序列里的最后一个1 [ 重点表达式 ]
       count++;
   }
    return count;
}

//写一个代码判断一个数字是不是2的n次方
//2的n次方的数字，其中只有一个1
//k & (k-1) == 0 //如果k里面只有一个1，那一次就去掉了

int main(){
    int n = -10;

    int ret = fuction_3(n);
    printf("num = %d",ret);

    return 0;
}