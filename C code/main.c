#include <stdio.h>
#define SWAP(N) ((N & 0xaaaaaaaa)>>1) + ((N & 0x55555555)<<1)
//дһ���꣬���Խ�һ�������Ķ�����λ������λ��ż��λ������
int main(){
    //10
    //00000000000000000000000000001010 'a'
    int num = 6;
    int ret = SWAP(num);
    //int ret = ((num & 0xaaaaaaaa)>>1) + ((num & 0x55555555)<<1);
    printf("%d\n",ret);
}