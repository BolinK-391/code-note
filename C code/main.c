#include "stdio.h"

//126.ָ������3
int main()
{
    char *c[] = {"ENTER","NEW","POINT","FIRST"};

    char**cp[] = {c+3,c+2,c+1,c};

    char***cpp = cp;//cpp ++ �� -- ��ı�cpp�����ֵ

    printf("%s\n", **++cpp);//point   //*cpp = c+2

    printf("%s\n", *--*++cpp+3);//++cpp --> c+1 --> �����ú� --> c     //ER

    printf("%s\n", *cpp[-2]+3);           //ST

    printf("%s\n", cpp[-1][-1]+1);// --> *(*(cpp-1)-1)+1 //EW

    return 0;
}