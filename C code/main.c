#include <stdio.h>

int main() {
    int flag = 0;
    scanf("%d",&flag);

    //flagΪ��,��ӡhaha
    if(flag)
    {
        printf("haha\n");
    }

    //flagΪ��,��ӡhehe
    if(!flag)
    {
        printf("hehe\n");
    }

    void function(int *a);

    function(&flag);

    return 0;
}

//��Ŀ���������߼��������� !
//��a = 0 �� !a = 1
//��a = 1 �� !a = 0

//��Ŀ����������һ�����Ķ����ư�λȡ�� ~
//ע�� ~ �ǶԱ������ڴ�����Ĳ���ȡ�������Ƕ�ԭ��

void function(int *a){

    //��a�Ķ������еĵ�5λ�ø�Ϊ1
    *a = *a | (1 << 4); //��λ�� | ����ȡ1����ͬȡ0

    //��a�Ķ������еĵ�5λ�ø�Ϊ0
    *a = *a & ~(1 << 4); //��λ�� & ��ͬȡ1������ȡ0
}
