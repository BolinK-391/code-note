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

//���Ž�
void my_3(char* a,char* b){
    while(*a++ = *b++){
        //��*b = '\0'ʱ,'\0'��ʾ�ַ�������������ASCII�е�ֵΪ0����ֵ0�����ַ�'0'��
        //��������ʽ *a++ = *b++ Ϊ��(=0);���Բ�ִ��ѭ��
        //������*b != '\0'ʱ,����ʽ��Ϊ��
        ;
    }
}

int main(){
    char a[10] = "xxxxxxxxx";
    char b[] = "lake";
   // my(a,b);
    printf("%s",a);
}