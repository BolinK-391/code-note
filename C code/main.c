#include "stdio.h"
int main(){
    char str1[] = "hello bit.";
    char str2[] = "hello bit.";

    char* str3 = "hello bit.";//�����ַ���(�޷����� )
    char* str4 = "hello bit.";
    //����str3��str4���ǳ����ַ�������������ͬ��
    //����"hello bit."���ڴ���ֻ��һ�ݣ�
    //str3��str4����ָ��ͬһ����ַ

    if(str1 == str2)//ȡ�����ĵ�ַ
        printf("str1 and str2 are same\n");
    else
        printf("str1 and str2 are not same\n");

    if(str3 == str4)//ȡ�����ĵ�ַ
        printf("str3 and str4 are same\n");
    else
        printf("str3 and str4 are not same\n");
}

//����str3��str4ָ�����һ��ͬһ�������ַ�����C/C++��ѳ����ַ����洢��������һ���ڴ�����
//������ָ��ָ��ͬһ���ַ�����ʱ������ʵ�ʻ�ָ��ͬһ���ڴ档
//��������ͬ�ĳ����ַ���ȥ��ʼ����ͬ�������ʱ��ͻῪ�ٳ���ͬ���ڴ�顣
//����str1��str2��ͬ��str3��str4��ͬ��