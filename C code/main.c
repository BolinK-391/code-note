#include "stdio.h"

int i;
//i��ȫ�ֱ���������ʼ����Ĭ����0

int main(){
    i--;
    //-1
    if(i>sizeof(i)){
        //-1>4
        //sizeof���������������Ľ����������unsigned int
        //�з������ͺ��޷������ͱȽϴ�С��ʱ�����з�����ת�����޷��������ٽ��бȽ�

        printf(">\n");
    }
    else
    {
        printf("<\n");
    }
    return 0;
}