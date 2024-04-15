#include "stdio.h"
#include "string.h"

int main(){
    char arr[] = "rusty lake paradox";
    char* p = " ";
    char tmp[20] = {0};
    strcpy(tmp,arr);
    //rusty\0lake\0
    char* ret = NULL;
    for(ret = strtok(tmp,p);ret != NULL;ret = strtok(NULL,p))  //每当strtok找到一个分割点时，会返回第一个的地址并记录分割点后将分割点变为'\0'
    {                                                                             //第二次传入空指针时，会根据之前的记忆点开始找下一个分割点，ret返回的值是起始点的地址
        printf("%s\n",ret);                                                 //strtok函数本身有记忆能力
    }
}

//ret = strtok(tmp,p);
//printf("%s\n",ret);

//ret = strtok(NULL,p);
//printf("%s\n",ret);

//ret = strtok(NULL,p);
//printf("%s\n",ret);