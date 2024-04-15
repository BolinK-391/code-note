#include "stdio.h"

//126.指针类型3
int main()
{
    char *c[] = {"ENTER","NEW","POINT","FIRST"};

    char**cp[] = {c+3,c+2,c+1,c};

    char***cpp = cp;//cpp ++ 和 -- 会改变cpp本身的值

    printf("%s\n", **++cpp);//point   //*cpp = c+2

    printf("%s\n", *--*++cpp+3);//++cpp --> c+1 --> 解引用后 --> c     //ER

    printf("%s\n", *cpp[-2]+3);           //ST

    printf("%s\n", cpp[-1][-1]+1);// --> *(*(cpp-1)-1)+1 //EW

    return 0;
}