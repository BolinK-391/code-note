#include <stdio.h>
#include <ctype.h>
#include <limits.h>
//#define INT_MAX 2147483647
//#define INT_MIN (-2147483647 - 1)

//模拟实现atoi函数
//把一个字符串转换成一个整数

enum State{
    INVALID, //0
    VALID    //1
};
//state记录的是my_atoi返回的值是合法转化的值，还是非法的状态
enum State state;

int my_atoi(const char*s){

    int flag = 1;
    //空指针
    if(NULL == s){
        return 0;
    }
    //空字符
    if(*s == '\0'){
        return 0;
    }
    //跳过空白字符
    while(isspace(*s)){
        s++;
    }
    //处理正负号问题+/-
    if(*s == '+'){
        flag = 1;
        s++;
    }
    else if(*s == '-'){
        flag = -1;
        s++;
    }
    //处理数字字符的转换
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
        //非数字字符的情况
        return (int)n;
    }
}

int main(){

    //异常情况
    //1.空指针
    //2.空字符串
    //3.遇到了非数字字符
    //4.超出范围
    const char*p = "";
    int ret = my_atoi(p);
    if(state == VALID) {
        printf("正常转换：%d\n", ret);
    }
    else {
        printf("非法转换：%d\n", ret);
    }
    return 0;
}