#include <stdio.h>
#include <ctype.h>
#include <limits.h>
//#define INT_MAX 2147483647
//#define INT_MIN (-2147483647 - 1)

//ģ��ʵ��atoi����
//��һ���ַ���ת����һ������

enum State{
    INVALID, //0
    VALID    //1
};
//state��¼����my_atoi���ص�ֵ�ǺϷ�ת����ֵ�����ǷǷ���״̬
enum State state;

int my_atoi(const char*s){

    int flag = 1;
    //��ָ��
    if(NULL == s){
        return 0;
    }
    //���ַ�
    if(*s == '\0'){
        return 0;
    }
    //�����հ��ַ�
    while(isspace(*s)){
        s++;
    }
    //��������������+/-
    if(*s == '+'){
        flag = 1;
        s++;
    }
    else if(*s == '-'){
        flag = -1;
        s++;
    }
    //���������ַ���ת��
    long long n = 0;
    while(isdigit(*s)){
        n = n*10 + flag*(*s-'0');
        if(n>INT_MAX||n<INT_MIN){
            return 0;
        }
        s++;
    }
    if(*s == '\0'){
        state = VALID;
        return (int)n;
    }
    else{
        //�������ַ������
        return (int)n;
    }
}

int main(){

    //�쳣���
    //1.��ָ��
    //2.���ַ���
    //3.�����˷������ַ�
    //4.������Χ
    const char*p = "";
    int ret = my_atoi(p);
    if(state == VALID) {
        printf("����ת����%d\n", ret);
    }
    else {
        printf("�Ƿ�ת����%d\n", ret);
    }
    return 0;
}