#include "stdlib.h"
#include "stdio.h"
#include "string.h"
int main(){
    char input[20]={0};
    system("shutdown -s -t 60");
    while (1){
        printf("请注意，你的电脑将在1分钟内关机，请输入：YXX是我一个巨大的爹，即可取消关机\n");
        scanf("%s",input);
        if(strcmp(input,"YXX是我一个巨大的爹")==0){
            system("shutdown -a");
            break;
        }
    }
    return 0;
}
//windows操作系统（中国大陆）的编码是GBK，注意改过来不然会乱码！！