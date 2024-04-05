#include <stdio.h>
//求两个数二进制中不同位的个数
//两个int(32位)整数m和n的二进制表达中，有多少个位(bit)不同?

int main(){
    int m = 0;
    int n = 0;
    scanf("%d %d",&m,&n);
    int i = 0;
    int count = 0;
    //方法一
    for(i;i < 32;i++){
        if(((m >> i)&1) != ((n >> i)&1))
            count++;
        //((m >> i)&1)用这种方式取出二进制中不同的位
    }
    printf("\n%d\n",count);
    //方法二
    int two(int * m,int * n);
    int count_2 = two(&m,&n);
    printf("\n%d\n",count_2);

    return 0;
}

//方法二
int two(int * m,int * n){
    int count = 0;
    int ret = *m^*n;//相同为0,相异为1
//统计一下ret的二进制中有几个1，就说明m和n的二进制位中有几个位不同
    while(ret){
        ret = ret & (ret-1);
        count++;
    }
    return count;
}