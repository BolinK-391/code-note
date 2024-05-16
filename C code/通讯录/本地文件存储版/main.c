#include "test.h"

//通讯录-静态版本
 //1.通讯录中能够存放1000个人的信息
 //每个人的信息：
 //名字+年龄+性别+电话+地址
 //2.增加人的信息
 //3.删除指定人的信息
 //4.修改指定人的信息
 //5.查找指定人的信息
 //6.排序通讯录的信息

 //动态增长版本
 //Ⅰ通讯录初始化后，能存放3个人的信息
 //Ⅱ空间存放满了的时候，我们增加2个信息
 // 3 + 2 + 2 + 2 + 2 ...

 //本地文件存储版本
 //当通讯录退出的时候，把信息写到文件
 //当通讯录初始化的时候，加载文件的信息到通讯录中



void menu(){
    printf("****************************\n");
    printf("***  1.add     2.del     ***\n");
    printf("***  3.search  4.modify  ***\n");
    printf("***  5.sort    6.print   ***\n");
    printf("*******    0.exit    *******\n");
    printf("****************************\n");
}
enum Option{
    EXIT,
    ADD,
    DEL,
    SEARCH,
    MODIFY,
    SORT,
    PRINT,};

int main(){
    int input = 0;
    //创建通讯录(动态版本和静态版本主要更改的地方)
    Contact con;//通讯录
    //初始化通讯录(动态版本和静态版本主要更改的地方)
    //给data申请一块连续的空间在堆区上
    //sz = 0
    //capacity初始化为当前的最大的容量
    InitContact(&con);
    do{
        menu();
        printf("请选择：>");
        scanf("%d",&input);
        switch(input){
            case ADD:
                //增加人的信息(动态版本和静态版本主要更改的地方)
                AddContact(&con);
                break;
            case DEL:
                //删除人的信息
                DelContact(&con);
                break;
            case SEARCH:
                //查找人的信息
                SearchContact(&con);
                break;
            case MODIFY:
                //修改人的信息
                ModifyContact(&con);
                break;
            case SORT:
                //对通讯录进行排序
                BubbleSort(&con);
                break;
            case PRINT:
                PrintContact(&con);
                break;
            case EXIT:
                //保存信息到本地文件
                SaveContact(&con);
                //(动态版本和静态版本主要更改的地方)
                //销毁通讯录
                DestoryContact(&con);
                break;
            default:
                printf("error\n");
                break;
        }

    }while(input);
    return 0;
}