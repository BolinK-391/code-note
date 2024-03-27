#include <stdio.h>
#include "string.h"
//º¯ÊýµÝ¹é
void change(char* a){
    char null = *a;
    int len = strlen(a);
    printf("%d",len);
    *a=*(a+len-1);
    *(a+len-1)='\0';
    if(strlen(a+1)>=2){
        change(a+1);
    }
    *(a+len-1)=null;
}

int main(){
    char arr[] = "abcdefg";
    change(arr);
    printf("%s",arr);


}