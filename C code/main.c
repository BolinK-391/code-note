#include <stdio.h>
#define SWAP(N) ((N & 0xaaaaaaaa)>>1) + ((N & 0x55555555)<<1)
//写一个宏，可以将一个整数的二进制位的奇数位和偶数位交换。
int main(){
    //10
    //00000000000000000000000000001010 'a'
    int num = 6;
    int ret = SWAP(num);
    //int ret = ((num & 0xaaaaaaaa)>>1) + ((num & 0x55555555)<<1);
    printf("%d\n",ret);
}