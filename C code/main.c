#include "stdio.h"
int main(){
    FILE* pf = fopen("test.txt","r");
    if(pf == NULL){
        perror("fopen");//ͬstrerror������������Զ���ӡ
    }
    fclose(pf);
    pf = NULL;
    return 0;
}