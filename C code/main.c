#include "stdio.h"
int main(){
    FILE* pf = fopen("test.txt","r");
    if(pf == NULL){
        perror("fopen");//同strerror但是这个可以自动打印
    }
    fclose(pf);
    pf = NULL;
    return 0;
}