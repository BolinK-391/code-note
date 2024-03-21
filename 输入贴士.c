#include<stdio.h>
int main(){
   int a ;
    scanf("%d",&a);//不要带上{\n、\t、空格}，不然要输入两次
   if(a)//a为不等于0的真，!a为等于0的假
       printf("yes");
   else
       printf("no");
   return 0;
}
//如果在格式字符串（出现了空白字符（空格、\n、\t之类），那么
//scanf() 会吃掉输入中所有接下来的空白字符。也就是说，
//在这段代码中 scanf 会等到输入中出现非空白字符才会返回。