#include <stdio.h>
#include "string.h"
//���룺I like beijing.
//���أ�beijing. like I

//����ʹ��scanf����
//scanf()����������������ʱ���������������һ�����ݵ����룺
//(1)���ո񡢡��س����������񡱼���
//(2)����Ƚ�����
//(3)���Ƿ����롣
void reverse(char *a,char *b);

int main(){
    char arr[100]={0};
    gets( arr );
    printf("%s\n",arr);

    //������ת��

    //1.�ַ������巴ת
    //gnijieb. ekil I
    int len = strlen(arr);
    reverse(arr,arr+len-1);
    printf("%s\n",arr);

    //2.ÿ����������
    //beijing. like I
    char *start = arr;
    while(*start)//*start != '\0'
    {
        char*end = start;
        while(*end != ' ' && *end != '\0'){
            end++;
        }
        //����һ������
        reverse(start,end-1);
        if(*end == ' ')
            start = end + 1;
        else//���һ�����ʵ�ʱ�����+1�˵Ļ���������'\0',�Ͳ�����ͣ��
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