#include <stdio.h>

void my_1(char* a,char* b){
    while(*b != '\0'){
        *a = *b;
        a++;
        b++;
    }
    *a = *b;
}

void my_2(char* a,char* b){
    while(*b != '\0'){
        *a++ = *b++;
    }
    *a = *b;
}

//最优解
void my_3(char* a,char* b){
    while(*a++ = *b++){
        //当*b = '\0'时,'\0'表示字符串结束，它在ASCII中的值为0（数值0，非字符'0'）
        //代表条件式 *a++ = *b++ 为假(=0);所以不执行循环
        //但是在*b != '\0'时,条件式都为真
        ;
    }
}

int main(){
    char a[10] = "xxxxxxxxx";
    char b[] = "lake";
   // my(a,b);
    printf("%s",a);
}