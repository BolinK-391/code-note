#include <stdio.h>
#include <string.h>
void change(int *pa,int *pb){
    int t = *pa;
    *pa = *pb;
    *pb = t;
}

int main ()
{
    int a = 10;
    int b = 20;
    printf("%d%d",a,b);
    change(&a,&b);//���ﲻ��ָ��Ļ�������a��b���뺯��change��ַ�ᷢ���ı䣬����ԭ����&a��&b��
    printf("\n%d%d",a,b);
    return 0;
}
