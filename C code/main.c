#include "stdio.h"
int main(){
    int a[5] = {1,2,3,4,5};
    int* ptr = (int*)(&a + 1);
    printf("%d,%d",*(a + 1),*(ptr - 1));
    return 0;
}


//ԭ���� (&a + 1) ������ int(*)[5] <����ָ������>
//ǿ������ת���� int* �Ժ�ͱ��a[5]+1�ĵ�ַ
//ptr-1�Ժ����a[5]�ĵ�ַ