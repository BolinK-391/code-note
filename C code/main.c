#include <stdio.h>
#include "string.h"
//输入：I like beijing.
//返回：beijing. like I

//不能使用scanf函数
//scanf()函数接收输入数据时，遇以下情况结束一个数据的输入：
//(1)遇空格、“回车”、“跳格”键；
//(2)遇宽度结束；
//(3)遇非法输入。
void reverse(char *a,char *b);

int main(){
    char arr[100]={0};
    gets( arr );
    printf("%s\n",arr);

    //三步翻转法

    //1.字符串整体反转
    //gnijieb. ekil I
    int len = strlen(arr);
    reverse(arr,arr+len-1);
    printf("%s\n",arr);

    //2.每个单词逆序
    //beijing. like I
    char *start = arr;
    while(*start)//*start != '\0'
    {
        char*end = start;
        while(*end != ' ' && *end != '\0'){
            end++;
        }
        //逆序一个单词
        reverse(start,end-1);
        if(*end == ' ')
            start = end + 1;
        else//最后一个单词的时候如果+1了的话就跳过了'\0',就不会暂停了
            start = end;
    }
    printf("%s",arr);
    return 0;

}


void reverse(char *left,char *right){
    while(left<right)
    {
        char tmp = 0;
        tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}