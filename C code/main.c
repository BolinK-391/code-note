#include "stdio.h"

char* my_strcat(char* dest,const char*src)
{
    char*ret = dest;
    //1.��Ŀ���ַ����е�\0
    while(*dest){
        dest++;
    }
    while(*dest++ = *src++){
        ;
        // '\0'ASCII��Ϊ0-->��
    }
    return ret;//���ص�Ŀ��ռ����ʼ��ַ
}
int main(){
    char arr1[20] = "hello ";
    char arr2[] = "world";
    //my_strcat(arr1,arr2);
    printf("%s\n",my_strcat(arr1,arr2));
}