#include <stdio.h>
#include <string.h>
int change(int n){
   int j = 0;
   for(j=2;j<n;j++){
       if(n%j==0)
           return 0;
       //return和break差不多，都是终止函数的执行，导致函数立即返回，不再执行后续代码。
       //break只能在循环体内和switch语句体内使用，跳出该语句体。
       //所以这里不需要再加一个break；

   }
    return 1;
}

int main ()
{
    int i = 0;
    for(i=100;i<=200;i++){
        if(change(i)==1)
            printf("%d\n",i);
    }
    return 0;
}
