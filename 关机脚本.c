#include "stdlib.h"
#include "stdio.h"
#include "string.h"
int main(){
    char input[20]={0};
    system("shutdown -s -t 60");
    while (1){
        printf("��ע�⣬��ĵ��Խ���1�����ڹػ��������룺YXX����һ���޴�ĵ�������ȡ���ػ�\n");
        scanf("%s",input);
        if(strcmp(input,"YXX����һ���޴�ĵ�")==0){
            system("shutdown -a");
            break;
        }
    }
    return 0;
}
//windows����ϵͳ���й���½���ı�����GBK��ע��Ĺ�����Ȼ�����룡��