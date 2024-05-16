#include "stdio.h"
#include <memory.h>
#include "string.h"
#include "malloc.h"

#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX 1000
#define DEFAULT_SZ 3
#define INC_SZ 2
//类型的定义
typedef struct PeoInfo{
    char name[MAX_NAME];
    char sex[MAX_SEX];
    int age;
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
}PeoInfo;

//通讯录(动态版本和静态版本主要更改的地方)
typedef struct Contact{
    PeoInfo * data;//指向动态申请的空间，用来存放联系人的信息
    int sz;//记录的是当前通讯录中有效信息的个数
    int capacity;//记录当前通讯录的最大容量
}Contact;

//初始化通讯录(动态版本和静态版本主要更改的地方)
void InitContact(Contact* pc);

//增加人的信息
void AddContact(Contact* pc);

//打印联系人信息
void PrintContact(const Contact* pc);//传地址效率高

//删除人的信息
void DelContact(Contact* pc);

//查找人的信息
void SearchContact(Contact* pc);

//修改人的信息
void ModifyContact(Contact* pc);

//对通讯录进行排序
void BubbleSort(Contact* pc);

//保存通讯录信息到本地文件
void SaveContact(Contact* pc);

//销毁通讯录
void DestoryContact(Contact* pc);

//加载通讯录本地文件
void LoadContact(Contact* pc);

//考虑增容
void CheckCapacity(Contact* pc);