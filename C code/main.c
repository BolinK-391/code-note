#include <stdio.h>
#include <string.h>
int change(int n){
   int j = 0;
   for(j=2;j<n;j++){
       if(n%j==0)
           return 0;
       //return��break��࣬������ֹ������ִ�У����º����������أ�����ִ�к������롣
       //breakֻ����ѭ�����ں�switch�������ʹ�ã�����������塣
       //�������ﲻ��Ҫ�ټ�һ��break��

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
