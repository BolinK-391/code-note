#include "stdio.h"

//���������ֽ����С���ֽ���ĸ�����һ��С�������жϵ�ǰ�������ֽ���

int check_sys(){
    int a = 1;
    char *p = (char*)&a;//��һ��char*(һ���ֽ�)���͵�ָ�����һ��int*(�ĸ��ֽ�)���͵ĵ�ַ�����Եõ���һ���ֽ�
    return *p;//����1��ʾС�ˣ�����0��ʾ���

}
int main(){
    //д�����жϵ�ǰ�������ֽ���
    int ret = check_sys();
    if(ret == 1)
        printf("С��");
    else
        printf("���");

    return 0;

}