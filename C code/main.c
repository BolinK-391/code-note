#include "stdio.h"
#include "string.h"

int main(){
    char arr[] = "rusty lake paradox";
    char* p = " ";
    char tmp[20] = {0};
    strcpy(tmp,arr);
    //rusty\0lake\0
    char* ret = NULL;
    for(ret = strtok(tmp,p);ret != NULL;ret = strtok(NULL,p))  //ÿ��strtok�ҵ�һ���ָ��ʱ���᷵�ص�һ���ĵ�ַ����¼�ָ��󽫷ָ���Ϊ'\0'
    {                                                                             //�ڶ��δ����ָ��ʱ�������֮ǰ�ļ���㿪ʼ����һ���ָ�㣬ret���ص�ֵ����ʼ��ĵ�ַ
        printf("%s\n",ret);                                                 //strtok���������м�������
    }
}

//ret = strtok(tmp,p);
//printf("%s\n",ret);

//ret = strtok(NULL,p);
//printf("%s\n",ret);

//ret = strtok(NULL,p);
//printf("%s\n",ret);