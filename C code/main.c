#include <stdio.h>

#define OFFSETOF(struct_name,mem_name) (int)&(((struct_name*)0)->mem_name)//������ʼλ�õĵ�ַ��0x0
//дһ���꣬����ṹ����ĳ����������׵�ַ��ƫ�ƣ�������˵��

struct A
{
    int a;
    short b;
    int c;
    char d;
};

int main(){
    printf("%d\n",OFFSETOF(struct A,d));
    return 0;
}
