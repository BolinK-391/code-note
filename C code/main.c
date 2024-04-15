#include "stdio.h"

char* my_strcat(char* dest,const char*src)
{
    char*ret = dest;
    //1.找目标字符串中的\0
    while(*dest){
        dest++;
    }
    while(*dest++ = *src++){
        ;
        // '\0'ASCII码为0-->假
    }
    return ret;//返回的目标空间的起始地址
}
int main(){
    char arr1[20] = "hello ";
    char arr2[] = "world";
    //my_strcat(arr1,arr2);
    printf("%s\n",my_strcat(arr1,arr2));
}